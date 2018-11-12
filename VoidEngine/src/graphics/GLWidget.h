#pragma once

#include <iostream>
#include <vector>

#include <QtWidgets>
#include <QtOpenGL>
#include <QVector3D>
#include <QMatrix4x4>

#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>

#include "../core/Transform.h"


class GLWidget : public QOpenGLWidget, protected QOpenGLExtraFunctions
{
	Q_OBJECT

public:
	GLWidget(QWidget *parent);

	void initializeGL();
	void paintGL();
	void draw();
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void resizeGL(int width, int height);
	void getInfos();

	void GLWidget::renderText(double x, double y, const QString& str, const QFont& font = QFont());
	QWidget* mParent;

	~GLWidget();

private:
	QRegion m_cachedRegion;

	QPoint lastMousePos;
	QOpenGLBuffer m_vbo;
	QOpenGLBuffer m_ibo;
	QOpenGLVertexArrayObject m_vao;
	QOpenGLShaderProgram* m_shader;
	QTabWidget* tab;
	int alpha;
	int u_modelToWorld;
	int u_worldToView;
	QMatrix4x4 m_projection;
	Transform m_transform;

	QTime frameTime;
	unsigned int frameCount;
};
