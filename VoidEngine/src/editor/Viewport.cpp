#include "Viewport.h"

Viewport::Viewport(QWidget* parent) : QWidget(parent)
{
	this->parent = parent;
	this->tabs = std::make_unique<QTabWidget>();
	this->tabs->setObjectName("tabViewport");

	QSurfaceFormat qglFormat;
	qglFormat.setVersion(4, 2);
	qglFormat.setProfile(QSurfaceFormat::CoreProfile);
	qglFormat.setSwapInterval(0);
	qglFormat.setSwapBehavior(QSurfaceFormat::SingleBuffer);

	this->glWidget = std::make_unique<GLWidget>(parent);
	this->glWidget->setObjectName("glWidget");
	this->glWidget->setFormat(qglFormat);

	QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	this->glWidget->setSizePolicy(sizePolicy);

	this->getTabs()->addTab(this->glWidget.get(), "Viewport");
}

Viewport::~Viewport()
{

}
