#include "ForwardRenderer.h"

ForwardRenderer::ForwardRenderer(QMainWindow* w, QSharedPointer<Shader> shader) : window(w)
{
	this->shader = shader;
	this->projection = QMatrix4x4();
	this->transform = QSharedPointer<Transform>::create();
	this->ibo = new QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
	this->vbo = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
}

void ForwardRenderer::prepare()
{
	this->shader->getProgram()->link();
	this->shader->getProgram()->bind();
	this->u_modelToWorld = this->shader->getProgram()->uniformLocation("modelToWorld");
	this->u_worldToView = this->shader->getProgram()->uniformLocation("worldToView");

	glViewport(0, 0, window->width(), window->height());
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	this->projection.setToIdentity();
	this->projection.perspective(60.0f, window->width() / float(window->height()), 0.01f, 1000.0f);

	this->shader->getProgram()->bind();
	this->shader->getProgram()->setUniformValue(u_modelToWorld, this->transform->toMatrix());
	this->shader->getProgram()->setUniformValue(u_worldToView, this->projection);

	//this->vao->bind();
	this->ibo->bind();

	qDebug() << "ForwardRenderer ready";
}

void ForwardRenderer::render()
{
	this->prepare();

	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);

	this->triggers();
}

void ForwardRenderer::triggers()
{
	this->vao->release();
	this->ibo->release();
	this->shader->getProgram()->release();
}

ForwardRenderer::~ForwardRenderer()
{

}
