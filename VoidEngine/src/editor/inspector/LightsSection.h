#pragma once

#include <QtWidgets>
#include <memory>

class LightsSection : public QWidget
{
public:
	LightsSection(QWidget* parent = 0);
	~LightsSection();

	QGroupBox* getGroup() { return this->group.get(); }

private:
	std::unique_ptr<QGroupBox> group;
};

