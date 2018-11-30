#include "MaterialSection.h"

MaterialSection::MaterialSection(QWidget* parent) : QWidget(parent)
{
	this->group = std::make_unique<QWidget>();
}

MaterialSection::~MaterialSection()
{

}
