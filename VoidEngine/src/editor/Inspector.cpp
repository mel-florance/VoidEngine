#include "Inspector.h"

Inspector::Inspector()
{
	this->sections = std::make_unique<QTabWidget>();

	this->world = std::make_unique<WorldSection>();
	this->lights = std::make_unique<LightsSection>();
	this->object = std::make_unique<ObjectSection>();
	this->particles = std::make_unique<ParticlesSection>();
	this->physics = std::make_unique<PhysicsSection>();

	this->addSection(this->getObject()->getGroup(), "Object");
	this->addSection(this->getWorld()->getGroup(), "World");
	this->addSection(this->getLights()->getGroup(), "Lights");
	this->addSection(this->getParticles()->getGroup(), "Particles");
	this->addSection(this->getPhysics()->getGroup(), "Physics");
}

void Inspector::addSection(QWidget* section, const QString& name) {
	this->sections->addTab(section, name);
}

Inspector::~Inspector()
{
}
