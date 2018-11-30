#pragma once

#include <QtWidgets>
#include <memory>

class PhysicsSection : public QWidget
{
public:
	PhysicsSection(QWidget* parent = 0);
	~PhysicsSection();

	QGroupBox* getGroup() { return this->group.get(); }

private:
	std::unique_ptr<QGroupBox> group;
};
