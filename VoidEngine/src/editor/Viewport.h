#pragma once

#include <QtWidgets>
#include "../graphics/GLWidget.h"
#include "../cameras/FPSCamera.h"

class Viewport : public QWidget
{
	Q_OBJECT

public:
	Viewport(QWidget* parent);
	~Viewport();

	QTabWidget* getTabs() { return this->tabs.get(); }
	GLWidget* getGLWidget() { return this->glWidget.get();  }
	QWidget* getParent() { return this->parent; }
	FPSCamera* getCamera() { return this->camera; }

private:
	std::unique_ptr<QTabWidget> tabs;
	QWidget* parent;
	std::shared_ptr<GLWidget> glWidget;
	FPSCamera* camera;
};
