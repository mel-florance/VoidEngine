#pragma once

#include <QtWidgets>

class StatusBar : public QWidget
{
	Q_OBJECT

public:
	StatusBar(QWidget* parent = Q_NULLPTR);
	~StatusBar();

	inline QLabel* getLabel() { return this->label.get(); }

private:
	QWidget* parent;
	std::unique_ptr<QLabel> label;
};

