#pragma once

#include <QtWidgets>
#include <memory>

class CameraSection : public QWidget
{
public:
	CameraSection(QWidget* parent = 0);

	QWidget* getGroup() { return this->group.get(); }

	~CameraSection();

private:
	std::unique_ptr<QWidget> group;
};
