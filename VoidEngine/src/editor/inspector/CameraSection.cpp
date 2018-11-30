#include "CameraSection.h"

CameraSection::CameraSection(QWidget* parent) : QWidget(parent)
{
	this->group = std::make_unique<QWidget>();
}

CameraSection::~CameraSection()
{

}
