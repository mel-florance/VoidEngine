#pragma once

#include <QtWidgets>
#include <memory>

class TextureSection : public QWidget
{
public:
	TextureSection(QWidget* parent = 0);

	QWidget* getGroup() { return this->group.get(); }

	~TextureSection();

private:
	std::unique_ptr<QWidget> group;
};
