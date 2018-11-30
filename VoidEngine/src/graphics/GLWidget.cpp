#include "GLWidget.h"
#include <QDebug>
#include <QGLContext>
#include <QString>
#include <QImage>
#include <QOpenGLShaderProgram>
#include "../mesh/Vertex.h"
#include "../core/Util.h"
#include "../editor/Outliner.h"
#include "../core/VoidEngine.h"
#include "../texturing/Texture.h"
#include "../core/VoidEngine.h"
#include <QOpenGLFunctions>


GLWidget::GLWidget(QWidget* parent) : QOpenGLWidget(parent)
{
	this->angle = 0.f;
	this->fps = 0.f;
	this->alpha = 0;
	this->mParent = parent;
	this->tab = Q_NULLPTR;
	this->frameCount = 0;
	this->default_scene = QSharedPointer<Scene>::create();
	this->gameLoop = new GameLoop();
	QThread* gameLoopThread = new QThread();

	QObject::connect(gameLoopThread, &QThread::started, this->gameLoop, &GameLoop::start);
	QObject::connect(this->gameLoop, SIGNAL(updated(float, float)), this, SLOT(updated(float, float)));
	QObject::connect(this->gameLoop, SIGNAL(rendered()), this, SLOT(rendered()));

	this->gameLoop->moveToThread(gameLoopThread);
	gameLoopThread->start();

	QSharedPointer<Light> light = QSharedPointer<Light>::create();
	float power = 2000.0f;
	light->setColor(QVector3D(80.0f * power, 80.0f * power, 80.0f * power));
	light->setPosition(QVector3D(200.0f, -50.0f, 0.0f));

	/*QSharedPointer<Light> light2 = QSharedPointer<Light>::create();
	light2->setColor(QVector3D(100000.0f, 200000.0f, 200000.0f));
	light2->setPosition(QVector3D(0.0f, -300.0f, -0.0f));
*/
	this->default_scene->addLight(light);
	//this->default_scene->addLight(light2);

	VoidEngine* ngine = (VoidEngine*)this->mParent;
	ngine->getSceneManager()->addScene(this->default_scene);
	ngine->getSceneManager()->setActiveScene(this->default_scene);

	//this->gameLoop->start();
}

void GLWidget::rendered()
{
	this->update();
}

void GLWidget::updated(float dt, float fps)
{
	this->angle -= 90.0f * dt;
	this->default_scene->update(dt);
	this->delta = dt;
	this->fps = fps;
}

void GLWidget::initializeGL()
{
	initializeOpenGLFunctions();

	this->shader = QSharedPointer<Shader>::create();
	this->shader->getProgram()->link();

	QString texDir = "C:/Users/overk/VoidEngineProjects/Survival/resources/textures/";
	QImage albedo = QImage(texDir + "pickup_low_Material_BaseColor.png");
	QImage normal = QImage(texDir + "pickup_low_Material_Normal.png");
	QImage mra = QImage(texDir + "pickup_low_Material_OcclusionRoughnessMetallic.png");
	//QImage roughness = QImage(texDir + "Can_roughness.jpg");
	//QImage metallic = QImage(texDir + "Can_metallic.jpg");
	QSharedPointer<Texture> a_texture = QSharedPointer<Texture>::create(albedo.mirrored());
	QSharedPointer<Texture> n_texture = QSharedPointer<Texture>::create(normal.mirrored());
	QSharedPointer<Texture> m_texture = QSharedPointer<Texture>::create(mra.mirrored());
	//QSharedPointer<Texture> r_texture = QSharedPointer<Texture>::create(roughness);
	//QSharedPointer<Texture> ao_texture = QSharedPointer<Texture>::create(ao);

	this->defaultMat = new DefaultMaterial("default", this->shader);
	this->defaultMat->setTexture(DefaultMaterial::ALBEDO, a_texture);
	this->defaultMat->setTexture(DefaultMaterial::NORMAL, n_texture);
	this->defaultMat->setTexture(DefaultMaterial::MRA, m_texture);
	//this->defaultMat->setTexture(DefaultMaterial::METALLIC, m_texture);
	//this->defaultMat->setTexture(DefaultMaterial::ROUGHNESS, r_texture);
	//this->defaultMat->setTexture(DefaultMaterial::AO, ao_texture);

	//this->defaultMat->setAlbedo(QVector3D(0.8f, 0.8f, 0.8f));
	//this->defaultMat->setMetallic(0.1f);
	//this->defaultMat->setRoughness(0.4f);
	//this->defaultMat->setAo(1.0f);

	VoidEngine* ngine = (VoidEngine*)this->mParent;
	MeshLoader::setShader(this->shader);

	this->renderer = QSharedPointer<ForwardRenderer>::create((QMainWindow*)this->mParent, this->shader);
	//this->renderer->prepare();

	tab = this->mParent->findChild<QTabWidget*>("tabViewport");
	glViewport(0, 0, tab->width(), tab->height());
}

void GLWidget::paintGL()
{
	glViewport(0, 0, tab->width(), tab->height());
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);

	++frameCount;
	draw();
}

void GLWidget::drawNode(Node* node)
{
	//node->transform->scale(QVector3D(10.0f, 10.0f, 10.0f));
	//node->transform->rotate(this->angle, QVector3D(0.0f, 1.0f, 0.0f));
	//qDebug() << node->transform->translation().x();
	this->shader->getProgram()->setUniformValue("mTransform", node->transform->toMatrix());

	for (auto mesh : node->meshes)
	{
		if (mesh != nullptr)
		{
			mesh->setupBuffers(this->shader->getProgram());
			mesh->draw();
		}
	}

	for (int i = 0; i < node->nodes.size(); i++)
		this->drawNode(node->nodes[i]);
}

void GLWidget::draw()
{
	VoidEngine* ngine = (VoidEngine*)this->mParent;

	this->shader->getProgram()->bind();
	this->defaultMat->bindUniforms(ngine->getViewport()->getCamera(), this->default_scene->getLights());

	for (auto node : this->default_scene->getNodes())
		this->drawNode(node);

	this->shader->getProgram()->release();
	this->renderText(10.0, 10.0, "FPS: " + QString::fromStdString(this->toDecimal(this->fps, 2)), QFont("consolas", 11));
}

std::string GLWidget::toDecimal(float counts, unsigned int precision)
{
	std::ostringstream ss;
	ss.precision(precision);
	ss << std::fixed << counts;
	return ss.str();
}

void GLWidget::renderText(double x, double y, const QString& str, const QFont& font)
{
	QPainter painter(this);
	painter.setPen(Qt::white);
	painter.setFont(font);
	painter.drawText(x, y, width(), height(), Qt::AlignLeft, str);
}

void GLWidget::resizeGL(int width, int height)
{
	VoidEngine* ngine = (VoidEngine*)this->mParent;
	Camera* cam = ngine->getViewport()->getCamera();
	QMatrix4x4 proj;
	proj.perspective(cam->getFov(), (float)width / height, cam->getNearPlane(), cam->getFarPlane());
	cam->setProjection(proj);
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
