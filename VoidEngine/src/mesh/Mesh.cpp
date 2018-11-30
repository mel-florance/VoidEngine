#include "Mesh.h"

Mesh::Mesh(const QString& name) : name(name)
{

}

void Mesh::setupBuffers(QSharedPointer<QOpenGLShaderProgram> shader)
{
	if (this->vao.isCreated())
		return;

	shader->bind();
	this->vao.create();
	this->vao.bind();

	QOpenGLBuffer vbo = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
	vbo.create();
	vbo.bind();
	vbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
	vbo.allocate(&this->vertices[0], this->vertices.size() * sizeof(this->vertices[0]));
	shader->enableAttributeArray(0);
	shader->setAttributeBuffer(0, GL_FLOAT, 0, 3);
	vbo.release();

	QOpenGLBuffer ubo = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
	ubo.create();
	ubo.bind();
	ubo.setUsagePattern(QOpenGLBuffer::StaticDraw);
	ubo.allocate(&this->uvs[0], this->uvs.size() * sizeof(this->uvs[0]));
	shader->enableAttributeArray(1);
	shader->setAttributeBuffer(1, GL_FLOAT, 0, 2);
	ubo.release();

	QOpenGLBuffer nbo = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
	nbo.create();
	nbo.bind();
	nbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
	nbo.allocate(&this->normals[0], this->normals.size() * sizeof(this->normals[0]));
	shader->enableAttributeArray(2);
	shader->setAttributeBuffer(2, GL_FLOAT, 0, 3);
	nbo.release();

	QOpenGLBuffer tbo = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
	tbo.create();
	tbo.bind();
	tbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
	tbo.allocate(&this->tangents[0], this->tangents.size() * sizeof(this->tangents[0]));
	shader->enableAttributeArray(3);
	shader->setAttributeBuffer(3, GL_FLOAT, 0, 3);
	tbo.release();

	this->ibo = QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
	this->ibo.create();
	this->ibo.bind();
	this->ibo.setUsagePattern(QOpenGLBuffer::StaticDraw);
	this->ibo.allocate(&this->indices[0], this->indices.size() * sizeof(this->indices[0]));
	this->ibo.release();

	qDebug() << "Loaded buffers for mesh: " <<  this->name;;

	this->vao.release();
}

void Mesh::draw()
{
	this->vao.bind();
	this->ibo.bind();

	glDrawElements(GL_TRIANGLES,this->indices.size(), GL_UNSIGNED_INT, 0);

	this->ibo.release();
	this->vao.release();
}

Mesh::~Mesh()
{

}