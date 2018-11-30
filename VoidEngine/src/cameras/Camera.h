#pragma once

#include <QQuaternion>
#include <QMatrix4x4>
#include <QtWidgets>
#include <QtGui>
#include <QVector3D>

class Camera : public QWidget
{
	Q_OBJECT
public:
	Camera(QWidget* parent = Q_NULLPTR);

	enum Mode { ORTHOGRAPHIC, PERSPECTIVE };
	enum Direction { UP, DOWN, LEFT, RIGHT, FORWARD, BACKWARD };

	inline bool isActive() { return this->active; }
	inline void setActive(bool value) { this->active = value; }

	inline QVector3D& getPosition() { return this->position; }
	inline void setPosition(const QVector3D& position) { this->position = position; };

	virtual QVector3D& getTranslation() = 0;
	virtual const QMatrix4x4& toMatrix() = 0;

	inline Mode getMode() { return this->mode; }
	inline void setMode(Mode mode) { this->mode = mode; }

	inline float getFov() { return this->fov; }
	inline void setFov(float angle) { this->fov = angle; }

	inline float getAspectRatio() { return this->aspect_ratio; }
	inline void setAspectRatio(float ratio) { this->aspect_ratio = ratio; }

	inline float getNearPlane() { return this->near_plane; }
	inline void setNearPlane(float value) { this->near_plane = value; }

	inline float getFarPlane() { return this->far_plane; }
	inline void setFarPlane(float value) { this->far_plane = value; }

	inline const QMatrix4x4 getView() { return this->view; };
	inline void setView(const QMatrix4x4& view) { this->view = view; }

	inline const QMatrix4x4& getProjection() { return this->projection; }
	inline void setProjection(const QMatrix4x4& projection) { this->projection = projection; }

	virtual void update(float delta) = 0;
	inline QWidget* getParent() { return this->parent; }

	~Camera();

public slots:
	virtual void onKeyPressed(QKeyEvent* event) = 0;
	virtual void onKeyReleased(QKeyEvent* event) = 0;
	virtual void onMouseMoved(QMouseEvent* event) = 0;
	virtual void onMouseDown(QMouseEvent* event) = 0;
	virtual void onMouseUp(QMouseEvent* event) = 0;
	virtual void onMousePressed(QMouseEvent* event) = 0;
	virtual void onMouseReleased(QMouseEvent* event) = 0;
	virtual void onMouseWheeled(QWheelEvent* event) = 0;

private:
	QWidget* parent;

	bool active;
	QVector3D position;
	Mode mode;

	float fov;
	float aspect_ratio;
	float near_plane;
	float far_plane;

	QMatrix4x4 projection;
	QMatrix4x4 view;
};
