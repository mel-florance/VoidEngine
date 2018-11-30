#include "Camera.h"

Camera::Camera(QWidget* parent) : QWidget(parent),
	fov(60.0f),
	aspect_ratio(16.0f / 9.0f),
	near_plane(0.1f),
	far_plane(1000.0f),
	active(true),
	mode(PERSPECTIVE)
{
	this->parent = parent;
	this->projection.perspective(this->fov, this->aspect_ratio, this->near_plane, this->far_plane);
}

Camera::~Camera()
{

}
