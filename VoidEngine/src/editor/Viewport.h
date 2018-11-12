#pragma once

#include <QtWidgets>
#include "../graphics/GLWidget.h"

class Viewport : public QWidget
{
	Q_OBJECT

public:
	Viewport(QWidget* parent);
	~Viewport();

	QTabWidget* getTabs() { return this->tabs.get(); }
	GLWidget* getGLWidget() { return this->glWidget.get();  }

private:
	std::unique_ptr<QTabWidget> tabs;
	QWidget* parent;
	std::unique_ptr<GLWidget> glWidget;
};
