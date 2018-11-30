#include "ObjectSection.h"

ObjectSection::ObjectSection(QWidget* parent) : QWidget(parent)
{
	this->group = std::make_unique<QWidget>();
	this->transform = std::make_unique<QGroupBox>("Transform");
	this->properties = std::make_unique<QGroupBox>("Properties");
	this->display = std::make_unique<QGroupBox>("Display");

	this->position = new TransformWidget(parent, TransformWidget::POSITION, "Position");
	this->rotation = new TransformWidget(parent, TransformWidget::ROTATION, "Rotation");
	this->scale    = new TransformWidget(parent, TransformWidget::SCALE, "Scale");

	QGridLayout* transformLayout = new QGridLayout();
	transformLayout->addWidget(this->position->getGroup(), 0, 0);
	transformLayout->addWidget(this->rotation->getGroup(), 1, 0);
	transformLayout->addWidget(this->scale->getGroup(),    2, 0);
	transformLayout->setAlignment(Qt::AlignTop);
	transformLayout->setSpacing(1);
	this->getTransform()->setLayout(transformLayout);

	QGridLayout* displayLayout = new QGridLayout();
	QCheckBox* ck_name = new QCheckBox("Name", this);
	QCheckBox* ck_wire = new QCheckBox("Wire", this);
	QCheckBox* ck_bounds = new QCheckBox("Bounds", this);
	QCheckBox* ck_axis = new QCheckBox("Axis", this);
	displayLayout->addWidget(ck_name, 0, 0);
	displayLayout->addWidget(ck_wire, 0, 1);
	displayLayout->addWidget(ck_bounds, 1, 0);
	displayLayout->addWidget(ck_axis, 1, 1);
	displayLayout->setAlignment(Qt::AlignTop);
	displayLayout->setSpacing(1);

	this->getDisplay()->setLayout(displayLayout);

	QLabel* nameLabel = new QLabel("Name");
	nameLabel->setFixedWidth(50);
	this->nameInput = new QLineEdit();
	QLabel* parentingLabel = new QLabel("Parent");
	parentingLabel->setFixedWidth(50);
	QComboBox* parenting = new QComboBox();

	QGridLayout* propertiesLayout = new QGridLayout();
	propertiesLayout->setAlignment(Qt::AlignTop);
	propertiesLayout->addWidget(nameLabel, 0, 0);
	propertiesLayout->addWidget(nameInput, 0, 1);
	propertiesLayout->addWidget(parentingLabel, 1, 0);
	propertiesLayout->addWidget(parenting, 1, 1);
	this->getProperties()->setLayout(propertiesLayout);

	QGridLayout* mainLayout = new QGridLayout();
	mainLayout->setAlignment(Qt::AlignTop);
	mainLayout->addWidget(this->getProperties());
	mainLayout->addWidget(this->getTransform());
	mainLayout->addWidget(this->getDisplay());
	this->group->setLayout(mainLayout);
}

ObjectSection::~ObjectSection()
{

}
