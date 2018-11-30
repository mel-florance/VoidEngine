#pragma once

#include <QtOpenGL>
#include <QSharedPointer>

class Shader
{
public:
	Shader();
	~Shader();

	inline void setProgram(QSharedPointer<QOpenGLShaderProgram> p) { this->program = p; }
	inline QSharedPointer<QOpenGLShaderProgram> getProgram() { return this->program; }

private:
	QSharedPointer<QOpenGLShaderProgram> program;
};

