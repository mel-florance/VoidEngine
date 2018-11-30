#pragma once

#include <QtWidgets>
#include <memory>

class SceneSection : public QWidget
{
public:
	SceneSection(QWidget* parent = 0);

	QWidget* getGroup() { return this->group.get(); }

	~SceneSection();

private:
	std::unique_ptr<QWidget> group;
};
