#pragma once

#include <QtWidgets>
#include <QVector3D>
#include <memory>

#include "../../core/Transform.h"
#include "../../scene/Node.h"

class TransformWidget : public QWidget
{
	Q_OBJECT
public:

	enum TransformType {
		POSITION,
		ROTATION,
		SCALE
	};

	TransformWidget(QWidget* parent, TransformType type, const QString& name);
	~TransformWidget();

	QWidget* getGroup() { return this->group.get(); }

	Transform* getTransform() { return this->transform; }
	inline void setTransform(Transform* transform) { this->transform = transform; }

	inline void setX(float x) { this->xInput->setValue(x); }
	inline void setY(float y) { this->yInput->setValue(y); }
	inline void setZ(float z) { this->zInput->setValue(z); }

	void setNode(Node* node);

public slots:
	void onXInputChanged(double value);
	void onYInputChanged(double value);
	void onZInputChanged(double value);

private:
	QWidget* parent;
	TransformType type;
	QString name;
	Node* node;
	Transform* transform;
	std::unique_ptr<QWidget> group;

	QDoubleSpinBox* xInput;
	QDoubleSpinBox* yInput;
	QDoubleSpinBox* zInput;
};

