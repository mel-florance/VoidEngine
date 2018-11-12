#include "StatusBar.h"

StatusBar::StatusBar(QWidget* parent) : QWidget(parent)
{
	this->parent = parent;
	this->label = std::make_unique<QLabel>(parent);
	this->label->setText("Ready !");
	this->label->setObjectName("statusLabel");
}

StatusBar::~StatusBar()
{

}
