#pragma once

#include <QtWidgets>
#include <memory>

class ParticlesSection : public QWidget
{
public:
	ParticlesSection(QWidget* parent = 0);
	~ParticlesSection();

	QGroupBox* getGroup() { return this->group.get(); }

private:
	std::unique_ptr<QGroupBox> group;
};
