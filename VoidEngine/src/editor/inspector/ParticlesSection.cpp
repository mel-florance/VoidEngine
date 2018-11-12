#include "ParticlesSection.h"



ParticlesSection::ParticlesSection(QWidget* parent) : QWidget(parent)
{
	this->group = std::make_unique<QGroupBox>("Particles");
}


ParticlesSection::~ParticlesSection()
{
}
