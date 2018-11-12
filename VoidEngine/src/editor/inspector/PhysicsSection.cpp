#include "PhysicsSection.h"



PhysicsSection::PhysicsSection(QWidget* parent) : QWidget(parent)
{
	this->group = std::make_unique<QGroupBox>("Physics");
}


PhysicsSection::~PhysicsSection()
{
}
