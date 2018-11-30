#pragma once

#include "Camera.h"
#include "../managers/InputsManager.h"

class FPSCamera : public Camera
{
	Q_OBJECT
public:
	FPSCamera(QWidget* parent = Q_NULLPTR);
	~FPSCamera();

	static const QVector3D local_forward;
	static const QVector3D local_up;
	static const QVector3D local_right;

	void translate(const QVector3D amount);
	void translate(float x, float y, float z);
	void setTranslation(const QVector3D& value);
	void setTranslation(float x, float y, float z);
	inline QVector3D& getTranslation() { return this->translation; }

	void rotate(const QQuaternion& amount);
	void rotate(float angle, const QVector3D& axis);
	void rotate(float angle, float x, float y, float z);
	void setRotation(const QQuaternion& value);
	void setRotation(float angle, const QVector3D& axis);
	void setRotation(float angle, float x, float y, float z);
	inline QQuaternion& getRotation() { return this->rotation; }

	const QMatrix4x4& toMatrix();
	void setKeyState(QKeyEvent* event, bool state);

	QVector3D up() const;
	QVector3D right() const;
	QVector3D forward() const;

	void move(Direction dir);
	void lockCursor(bool value);
	void update(float delta) override;

public slots:
	void onMouseUp(QMouseEvent* event);
	void onKeyPressed(QKeyEvent* event);
	void onKeyReleased(QKeyEvent* event);
	void onMouseMoved(QMouseEvent* event);
	void onMouseDown(QMouseEvent* event);
	void onMousePressed(QMouseEvent* event);
	void onMouseReleased(QMouseEvent* event);
	void onMouseWheeled(QWheelEvent* event);

private:

	bool dirty;
	float delta;
	float maxSpeed;
	float moveSpeed;
	float rotSpeed;
	float sensitivity;
	bool cursorLocked;

	QMatrix4x4 world;
	QQuaternion rotation;
	QVector3D translation;
	QVector3D translationDelta;

	QMap<QString, int> keys;
	QMap<QString, bool> keys_states;
};

