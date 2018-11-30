#include "FPSCamera.h"
#include "../editor/Viewport.h"

#include <QDebug>

const QVector3D FPSCamera::local_forward(0.0f, 0.0f, -1.0f);
const QVector3D FPSCamera::local_up(0.0f, 1.0f, 0.0f);
const QVector3D FPSCamera::local_right(1.0f, 0.0f, 0.0f);

FPSCamera::FPSCamera(QWidget* parent) : Camera(parent)
{
	this->moveSpeed = 0.5f;
	this->maxSpeed = 0.5f;
	this->rotSpeed = 150.0f;
	this->sensitivity = 0.1f;
	this->setActive(false);

	this->keys["FORWARD"] = Qt::Key_Z;
	this->keys["BACKWARD"] = Qt::Key_S;
	this->keys["LEFT"] = Qt::Key_Q;
	this->keys["RIGHT"] = Qt::Key_D;
	this->keys["UP"] = Qt::Key_E;
	this->keys["DOWN"] = Qt::Key_A;

	this->keys_states["FORWARD"] = false;
	this->keys_states["BACKWARD"] = false;
	this->keys_states["LEFT"] = false;
	this->keys_states["RIGHT"] = false;
	this->keys_states["UP"] = false;
	this->keys_states["DOWN"] = false;
}

void FPSCamera::move(Direction dir)
{
	if (this->getMode() == PERSPECTIVE)
	{
		float speed = this->moveSpeed * this->delta;

		switch (dir)
		{
		case UP:
			this->translationDelta -= this->up() * speed;
			break;
		case DOWN:
			this->translationDelta += this->up() * speed;
			break;
		case LEFT:
			this->translationDelta += this->right() * speed;
			break;
		case RIGHT:
			this->translationDelta -= this->right() * speed;
			break;
		case FORWARD:
			this->translationDelta -= this->forward() * speed;
			break;
		case BACKWARD:
			this->translationDelta += this->forward() * speed;
			break;
		}
	}
}

void FPSCamera::lockCursor(bool value)
{

}

void FPSCamera::update(float dt)
{
	this->delta = dt;

	if (this->isActive())
	{
		if (this->keys_states["FORWARD"])
			this->move(FORWARD);
		if (this->keys_states["BACKWARD"])
			this->move(BACKWARD);
		if (this->keys_states["LEFT"])
			this->move(LEFT);
		if (this->keys_states["RIGHT"])
			this->move(RIGHT);
		if (this->keys_states["UP"])
			this->move(UP);
		if (this->keys_states["DOWN"])
			this->move(DOWN);
	}

	this->translate(this->translationDelta);
	this->translationDelta *= 0.85f;
}

void FPSCamera::onKeyPressed(QKeyEvent* event)
{
	this->setKeyState(event, true);
}

void FPSCamera::onKeyReleased(QKeyEvent* event)
{
	this->setKeyState(event, false);
}

void FPSCamera::setKeyState(QKeyEvent* event, bool state)
{
	for (const auto& key : this->keys.toStdMap())
		if (event->key() == key.second)
			this->keys_states[key.first] = state;
}

void FPSCamera::onMouseMoved(QMouseEvent* event)
{
	if (this->isActive()) 
	{
		this->rotate(-this->rotSpeed * this->delta * InputsManager::mouseDelta.x(), FPSCamera::local_up);
		this->rotate(-this->rotSpeed * this->delta * InputsManager::mouseDelta.y(), this->right());
	}
}

void FPSCamera::onMousePressed(QMouseEvent* event)
{
	if (event->button() == Qt::RightButton)
		this->setActive(true);
}

void FPSCamera::onMouseReleased(QMouseEvent* event)
{
	this->setActive(false);
}

void FPSCamera::onMouseDown(QMouseEvent* event)
{

}

void FPSCamera::onMouseUp(QMouseEvent* event)
{

}

void FPSCamera::onMouseWheeled(QWheelEvent* event)
{
	this->moveSpeed += ((float)event->angleDelta().y()) * 0.001f;

	if (this->moveSpeed < 0.0f)
		this->moveSpeed = 0.0f;
}

void FPSCamera::rotate(const QQuaternion& amount)
{
	this->dirty = true;
	this->rotation = amount * this->rotation;
}

void FPSCamera::translate(const QVector3D amount)
{
	this->dirty = true;
	this->translation += amount;
}

void FPSCamera::setTranslation(const QVector3D& value)
{
	this->dirty = true;
	this->translation = value;
}

void FPSCamera::setRotation(const QQuaternion& value)
{
	this->dirty = true;
	this->rotation = value;
}

void FPSCamera::translate(float x, float y, float z) 
{ 
	this->translate(QVector3D(x, y, z));
}

void FPSCamera::rotate(float angle, const QVector3D& axis) 
{ 
	this->rotate(QQuaternion::fromAxisAndAngle(axis, angle));
}

void FPSCamera::rotate(float angle, float x, float y, float z) 
{ 
	this->rotate(QQuaternion::fromAxisAndAngle(x, y, z, angle));
}

void FPSCamera::setTranslation(float x, float y, float z) 
{ 
	this->setTranslation(QVector3D(x, y, z));
}

void FPSCamera::setRotation(float angle, const QVector3D& axis)
{ 
	this->setRotation(QQuaternion::fromAxisAndAngle(axis, angle));
}

void FPSCamera::setRotation(float angle, float x, float y, float z) 
{ 
	this->setRotation(QQuaternion::fromAxisAndAngle(x, y, z, angle));
}

QVector3D FPSCamera::forward() const
{
	return this->rotation.rotatedVector(local_forward);
}

QVector3D FPSCamera::up() const
{
	return this->rotation.rotatedVector(local_up);
}

QVector3D FPSCamera::right() const
{
	return this->rotation.rotatedVector(local_right);
}

const QMatrix4x4& FPSCamera::toMatrix()
{
	if(this->dirty)
	{
		this->dirty = false;
		this->world.setToIdentity();
		this->world.rotate(this->rotation.conjugate());
		this->world.translate(this->translation);
	}

	return this->world;
}

FPSCamera::~FPSCamera()
{

}
