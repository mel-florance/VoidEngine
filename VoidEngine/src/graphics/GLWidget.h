#pragma once

#include <iostream>
#include <vector>
#include <sstream>

#include <QTextStream>
#include <QtWidgets>
#include <QtOpenGL>
#include <QVector3D>
#include <QMatrix4x4>

#include <QOpenGLBuffer>
#include <QSharedPointer>
#include <QOpenGLVertexArrayObject>

#include "../core/Transform.h"
#include "../scene/Scene.h"
#include "../scene/Node.h"
#include "../core/GameLoop.h"

#include "../rendering/ForwardRenderer.h"
#include "../materials/DefaultMaterial.h"

class GLWidget : public QOpenGLWidget, protected QOpenGLExtraFunctions
{
	Q_OBJECT

public:
	GLWidget(QWidget* parent = Q_NULLPTR);

	void initializeGL();
	void paintGL();
	void draw();
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void resizeGL(int width, int height);
	void getInfos();

	void drawNode(Node* node);
	inline QSharedPointer<ForwardRenderer> getRenderer() { return this->renderer; }
	inline QSharedPointer<Shader> getShader() { return this->shader; }
	void GLWidget::renderText(double x, double y, const QString& str, const QFont& font = QFont());
	QWidget* mParent;

	inline QSharedPointer<Scene> getDefaultScene() { return this->default_scene; }
	std::string toDecimal(float counts, unsigned int precision = 1);
	~GLWidget();

public slots:
	void updated(float delta, float fps);
	void rendered();

private:
	QRegion m_cachedRegion;
	QPoint lastMousePos;
	QSharedPointer<Shader> shader;
	QTabWidget* tab;
	QSharedPointer<Scene> default_scene;
	int alpha;
	float delta;
	float angle;
	float fps;
	DefaultMaterial* defaultMat;

	GameLoop* gameLoop;
	Transform m_transform;
	QTime frameTime;
	QSharedPointer<ForwardRenderer> renderer;
	unsigned int frameCount;
};
