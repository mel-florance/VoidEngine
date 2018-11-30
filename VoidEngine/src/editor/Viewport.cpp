#include "Viewport.h"

Viewport::Viewport(QWidget* parent) : QWidget(parent)
{
	this->parent = parent;
	this->tabs = std::make_unique<QTabWidget>();
	this->tabs->setObjectName("tabViewport");
	this->tabs->setFocusPolicy(Qt::FocusPolicy::ClickFocus);

	QSurfaceFormat qglFormat;
	qglFormat.setVersion(4, 6);
	qglFormat.setDepthBufferSize(24);
	qglFormat.setStencilBufferSize(8);
	qglFormat.setProfile(QSurfaceFormat::CoreProfile);
	qglFormat.setSwapInterval(0);
	qglFormat.setSwapBehavior(QSurfaceFormat::SingleBuffer);

	this->glWidget = std::make_shared<GLWidget>(parent);
	this->glWidget->setObjectName("glWidget");
	this->glWidget->setFormat(qglFormat);

	QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	this->glWidget->setSizePolicy(sizePolicy);

	this->camera = new FPSCamera(this);

	this->getTabs()->addTab(this->glWidget.get(), "Viewport");
}

Viewport::~Viewport()
{
	delete this->camera;
}
