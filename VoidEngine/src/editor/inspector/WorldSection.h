#pragma once

#include <QtWidgets>
#include <memory>

class WorldSection : public QWidget
{
public:
	WorldSection(QWidget* parent = 0);
	~WorldSection();

	QWidget* getGroup() { return this->group.get(); }
	QGroupBox* getColor() { return this->color.get(); }
	QGroupBox* getFog() { return this->fog.get(); }
	QGroupBox* getAo() { return this->ao.get(); }

	void fogSection();
	void colorSection();
	void onColorBtnClicked();
	void onColorChanged(const QColor &color);
	void aoSection();

private:
	std::unique_ptr<QWidget> group;
	std::unique_ptr<QGroupBox> color;
	std::unique_ptr<QGroupBox> fog;
	std::unique_ptr<QGroupBox> ao;
	QPushButton* colorBtn;
	QColorDialog* colorDialog;
};

