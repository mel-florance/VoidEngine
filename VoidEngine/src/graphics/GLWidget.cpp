#include "GLWidget.h"
#include <QDebug>
#include <QGLContext>
#include <QString>
#include <QOpenGLShaderProgram>
#include "../mesh/Vertex.h"
#include "../core/Util.h"
#include <QOpenGLFunctions>

static const Vertex sg_vertexes[3] = {
	Vertex(QVector3D(-0.5f,  -0.5f, 0.0f), QVector3D(0.0f, 0.0f, 1.0f)),
	Vertex(QVector3D(0.5f, -0.5f, 0.0f), QVector3D(0.0f, 1.0f, 0.0f)),
	Vertex(QVector3D(0.0f, 0.5f, 0.0f), QVector3D(1.0f, 0.0f, 0.0f))
};

static const GLushort sg_indices[3] = { 0, 1, 2 };

GLWidget::GLWidget(QWidget* parent) : QOpenGLWidget(parent)
{
	this->mParent = parent;
	m_ibo = QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
	m_vbo = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
	m_transform.translate(0.0f, 0.0f, -5.0f);
	//QObject::connect(this, &QOpenGLWidget::frameSwapped, this, &GLWidget::paintGL);

	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(update()));
	//timer->setInterval(0);
	timer->start(16);
}

void GLWidget::initializeGL()
{
	initializeOpenGLFunctions();

	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	m_shader = new QOpenGLShaderProgram();
	m_shader->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/res/shaders/basic.vert");
	m_shader->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/res/shaders/basic.frag");
	m_shader->link();
	m_shader->bind();

	u_modelToWorld = m_shader->uniformLocation("modelToWorld");
	u_worldToView = m_shader->uniformLocation("worldToView");

	m_vbo.create();
	m_vbo.bind();
	m_vbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
	m_vbo.allocate(sg_vertexes, sizeof(sg_vertexes));

	m_ibo.create();
	m_ibo.bind();
	m_ibo.setUsagePattern(QOpenGLBuffer::StaticDraw);
	m_ibo.allocate(sg_indices, 3 * sizeof(GLushort));
	m_ibo.release();

	m_vao.create();
	m_vao.bind();

	m_shader->enableAttributeArray(0);
	m_shader->enableAttributeArray(1);
	m_shader->setAttributeBuffer(0, GL_FLOAT, Vertex::positionOffset(), Vertex::PositionTupleSize, Vertex::stride());
	m_shader->setAttributeBuffer(1, GL_FLOAT, Vertex::colorOffset(), Vertex::ColorTupleSize, Vertex::stride());


	m_vao.release();

	m_vbo.release();
	m_shader->release();

	tab = this->mParent->findChild<QTabWidget*>("tabViewport");
	glViewport(0, 0, tab->width(), tab->height());
	frameTime.start();
}

void GLWidget::paintGL()
{
	glViewport(0, 0, tab->width(), tab->height());
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	++frameCount;

	if (this->frameTime.elapsed() >= 1000)
	{
		QFont font("Consolas", 10);
		double fps = this->frameCount / ((double)this->frameTime.elapsed() / 1000.0);
		this->renderText(10.0, 10.0, "FPS: " + QString::number(fps), font);
	}

	m_projection.setToIdentity();
	m_projection.perspective(60.0f, tab->width() / float(tab->height()), 0.01f, 1000.0f);

	m_transform.rotate(1, QVector3D(0.4f, 0.3f, 0.3f));

	draw();
}

void GLWidget::renderText(double x, double y, const QString& str, const QFont& font) 
{
	QPainter painter(this);
	painter.setPen(Qt::white);
	painter.setFont(font);
	painter.drawText(x, y, width(), height(), Qt::AlignLeft, str);
}

void GLWidget::draw()
{
	m_shader->bind();
	m_shader->setUniformValue(u_worldToView, m_projection);
	m_shader->setUniformValue(u_modelToWorld, m_transform.toMatrix());
	m_vao.bind();
	m_ibo.bind();	

	//glDrawArrays(GL_TRIANGLES, 0, sizeof(sg_vertexes) / sizeof(sg_vertexes[0]));
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);

	m_vao.release();
	m_ibo.release();
	m_shader->release();
}

void GLWidget::resizeGL(int width, int height)
{


}

void GLWidget::mousePressEvent(QMouseEvent* event)
{
	lastMousePos = event->pos();
}

void GLWidget::mouseMoveEvent(QMouseEvent* event)
{
	lastMousePos = event->pos();
}


void GLWidget::getInfos()
{
	QOffscreenSurface surf;
	surf.create();

	QOpenGLContext ctx;
	ctx.create();
	ctx.makeCurrent(&surf);

	QTextEdit* console = this->mParent->findChild<QTextEdit*>("consoleWidget");
	const GLubyte* version = ctx.functions()->glGetString(GL_VERSION);
	const GLubyte* vendor = ctx.functions()->glGetString(GL_VENDOR);
	const GLubyte* renderer = ctx.functions()->glGetString(GL_RENDERER);
	const GLubyte* glsl_version = ctx.functions()->glGetString(GL_SHADING_LANGUAGE_VERSION);
	const GLubyte* gl_extensions = ctx.functions()->glGetString(GL_EXTENSIONS);

	QStringList list = QString((char*)version).split(QRegExp("\\s+"), QString::SkipEmptyParts);
	
	console->append(QString("==============================================="));
	console->append(QString("Vendor         : ") + QString((char*)vendor));
	console->append(QString("Device         : ") + QString((char*)renderer));
	console->append(QString("OpenGL version : ") + list[0]);
	console->append(QString("Driver version : ") + list[2]);
	console->append(QString("GLSL version   : ") + QString((char*)glsl_version));
	console->append(QString("==============================================="));
}

GLWidget::~GLWidget()
{

}
