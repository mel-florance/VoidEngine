#include "SceneSection.h"

SceneSection::SceneSection(QWidget* parent) : QWidget(parent)
{
	this->group = std::make_unique<QWidget>();
}

SceneSection::~SceneSection()
{

}
