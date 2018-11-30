#include "Shader.h"

Shader::Shader()
{
	this->program = QSharedPointer<QOpenGLShaderProgram>::create();
	this->program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/res/shaders/pbr.vs");
	this->program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/res/shaders/pbr.fs");
	this->program->link();
	this->program->bind();
}

Shader::~Shader()
{

}
