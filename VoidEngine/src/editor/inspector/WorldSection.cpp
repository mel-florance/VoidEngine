#include "WorldSection.h"

WorldSection::WorldSection(QWidget* parent) : QWidget(parent)
{
	this->group = std::make_unique<QWidget>();

}

WorldSection::~WorldSection()
{

}
