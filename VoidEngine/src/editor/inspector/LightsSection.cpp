#include "LightsSection.h"

LightsSection::LightsSection(QWidget* parent) : QWidget(parent)
{
	this->group = std::make_unique<QGroupBox>("Lights");
}

LightsSection::~LightsSection()
{

}
