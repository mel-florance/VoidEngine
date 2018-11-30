#include "Inspector.h"

Inspector::Inspector(QWidget* parent)
{
	this->tabs = std::make_unique<QTabWidget>();
	this->tabs->setStyleSheet("QTabBar::tab {width: 40px;}");

	this->world     = std::make_unique<WorldSection>();
	this->scene     = std::make_unique<SceneSection>();
	this->camera    = std::make_unique<CameraSection>();
	this->material  = std::make_unique<MaterialSection>();
	this->texture   = std::make_unique<TextureSection>();
	this->lights    = std::make_unique<LightsSection>(parent);
	this->object    = std::make_unique<ObjectSection>(parent);
	this->particles = std::make_unique<ParticlesSection>();
	this->physics   = std::make_unique<PhysicsSection>();

	this->addSection(0, this->getObject()->getGroup(),    QIcon(":/res/icons/object.png"));
	this->addSection(1, this->getWorld()->getGroup(),     QIcon(":/res/icons/world.png"));
	this->addSection(2, this->getScene()->getGroup(),     QIcon(":/res/icons/scene.png"));
	this->addSection(3, this->getCamera()->getGroup(),    QIcon(":/res/icons/camera.png"));
	this->addSection(4, this->getMaterial()->getGroup(),  QIcon(":/res/icons/material.png"));
	this->addSection(5, this->getTexture()->getGroup(),   QIcon(":/res/icons/texture.png"));
	this->addSection(6, this->getLights()->getGroup(),    QIcon(":/res/icons/lights.png"));
	this->addSection(7, this->getParticles()->getGroup(), QIcon(":/res/icons/particles.png"));
	this->addSection(8, this->getPhysics()->getGroup(),   QIcon(":/res/icons/physics.png"));
}

void Inspector::addSection(unsigned int column, QWidget* section, QIcon& icon) {

	this->tabs->addTab(section, "");
	this->tabs->setTabIcon(column, icon);
}

Inspector::~Inspector()
{
}
