#pragma once

#include <QtWidgets>
#include <memory>

#include "../../mesh/Mesh.h"
#include "../../scene/Node.h"
#include "../widgets/TransformWidget.h"

class ObjectSection : public QWidget
{
public:
	ObjectSection(QWidget* parent = 0);
	~ObjectSection();

	inline QGroupBox* getTransform() { return this->transform.get(); }
	inline QWidget* getGroup() { return this->group.get(); }
	inline QWidget* getProperties() { return this->properties.get(); }
	inline QWidget* getDisplay() { return this->display.get(); }

	inline void setNode(Node* node)
	{ 
		this->node = node;
		this->nameInput->setText(node->name);
		this->position->setNode(this->node);
		this->rotation->setNode(this->node);
		this->scale->setNode(this->node);
	}

private:
	QLineEdit* nameInput;
	Node* node;
	std::unique_ptr<QWidget> group;
	std::unique_ptr<QGroupBox> transform;
	std::unique_ptr<QWidget> properties;
	std::unique_ptr<QWidget> display;

	TransformWidget* position;
	TransformWidget* rotation;
	TransformWidget* scale;
};
