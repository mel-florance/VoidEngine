#pragma once

#include <QtWidgets>
#include <memory>

class MaterialSection : public QWidget
{
public:
	MaterialSection(QWidget* parent = 0);

	QWidget* getGroup() { return this->group.get(); }

	~MaterialSection();

private:
	std::unique_ptr<QWidget> group;
};
