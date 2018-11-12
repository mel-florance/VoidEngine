#pragma once

#include <QtWidgets>
#include <memory>

#include "../widgets/TransformWidget.h"

class ObjectSection : public QWidget
{
public:
	ObjectSection(QWidget* parent = 0);
	~ObjectSection();

	inline QGroupBox* getTransform() { return this->transform.get(); }
	inline QWidget* getGroup() { return this->group.get(); }
	inline QWidget* getProperties() { return this->properties.get(); }

private:
	std::unique_ptr<QWidget> group;
	std::unique_ptr<QGroupBox> transform;
	std::unique_ptr<QWidget> properties;
};

