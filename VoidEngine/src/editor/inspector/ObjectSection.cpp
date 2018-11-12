#include "ObjectSection.h"

ObjectSection::ObjectSection(QWidget* parent) : QWidget(parent)
{
	this->group = std::make_unique<QWidget>();
	this->transform = std::make_unique<QGroupBox>("Transform");
	this->properties = std::make_unique<QGroupBox>("Properties");

	TransformWidget* position = new TransformWidget(this, "Position");
	TransformWidget* rotation = new TransformWidget(this, "Rotation");
	TransformWidget* scale    = new TransformWidget(this, "Scale");

	QGridLayout* transformLayout = new QGridLayout();
	transformLayout->addWidget(position->getGroup(), 0, 0);
	transformLayout->addWidget(rotation->getGroup(), 1, 0);
	transformLayout->addWidget(scale->getGroup(),    2, 0);

	transformLayout->setAlignment(Qt::AlignTop);
	transformLayout->setSpacing(1);
	this->getTransform()->setLayout(transformLayout);

	QLabel* nameLabel = new QLabel("Name");
	nameLabel->setFixedWidth(50);
	QLineEdit* input = new QLineEdit();
	QLabel* parentingLabel = new QLabel("Parent");
	parentingLabel->setFixedWidth(50);
	QComboBox* parenting = new QComboBox();
	parenting->addItem("test");
	parenting->addItem("test2");

	QGridLayout* propertiesLayout = new QGridLayout();
	propertiesLayout->setAlignment(Qt::AlignTop);
	propertiesLayout->addWidget(nameLabel, 0, 0);
	propertiesLayout->addWidget(input, 0, 1);
	propertiesLayout->addWidget(parentingLabel, 1, 0);
	propertiesLayout->addWidget(parenting, 1, 1);
	this->getProperties()->setLayout(propertiesLayout);

	QGridLayout* mainLayout = new QGridLayout();
	mainLayout->setAlignment(Qt::AlignTop);
	mainLayout->addWidget(this->getProperties());
	mainLayout->addWidget(this->getTransform());
	this->group->setLayout(mainLayout);
}

ObjectSection::~ObjectSection()
{

}
