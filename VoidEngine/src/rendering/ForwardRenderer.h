#pragma once

#include <QSharedPointer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLFunctions>
#include <QtOpenGL>

#include <QtWidgets>

#include <QMatrix4x4>
#include "Shader.h"
#include "../mesh/Mesh.h"
#include "../core/Transform.h"

class ForwardRenderer
{

public:
	ForwardRenderer(QMainWindow* window = Q_NULLPTR, QSharedPointer<Shader> shader = Q_NULLPTR);

	void prepare();
	void render();
	void triggers();

	inline QSharedPointer<Shader> getShader() { return this->shader; }

	~ForwardRenderer();

private:
	QOpenGLBuffer* vbo;
	QOpenGLBuffer* ibo;
	QOpenGLVertexArrayObject* vao;
	QSharedPointer<Shader> shader;
	QMainWindow* window;
	int u_modelToWorld;
	int u_worldToView;
	QMatrix4x4 projection;
	QSharedPointer<Transform> transform;
};
