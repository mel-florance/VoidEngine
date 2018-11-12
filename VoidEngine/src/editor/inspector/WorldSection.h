#pragma once

#include <QtWidgets>
#include <memory>

class WorldSection : public QWidget
{
public:
	WorldSection(QWidget* parent = 0);
	~WorldSection();

	QWidget* getGroup() { return this->group.get(); }

private:
	std::unique_ptr<QWidget> group;
};

