#include "LightsSection.h"

LightsSection::LightsSection(QWidget* parent) : QWidget(parent)
{
	this->parent = parent;
	this->group = std::make_unique<QWidget>();

	this->typeSection();
	this->colorSection();
	this->energySection();
	this->transformSection();
	this->shadowSection();

	QGridLayout* mainLayout = new QGridLayout();
	mainLayout->setAlignment(Qt::AlignTop);
	mainLayout->addWidget(this->getType());
	mainLayout->addWidget(this->getColor());
	mainLayout->addWidget(this->getEnergy());
	mainLayout->addWidget(this->getTransform());
	mainLayout->addWidget(this->getShadows());

	this->group->setLayout(mainLayout);
}

void LightsSection::colorSection()
{
	this->color = std::make_unique<QGroupBox>("Color");

	this->colorBtn = new QPushButton();
	this->colorBtn->setStyleSheet("background-color: #ffffff");
	this->colorDialog = new QColorDialog();

	QObject::connect(this->colorBtn, &QPushButton::clicked, this, &LightsSection::onColorBtnClicked);
	QObject::connect(this->colorDialog, &QColorDialog::currentColorChanged, this, &LightsSection::onColorChanged);
	QGridLayout* colorLayout = new QGridLayout();
	colorLayout->addWidget(this->colorBtn);

	this->getColor()->setLayout(colorLayout);
}

void LightsSection::onColorBtnClicked()
{
	this->colorDialog->show();
}

void LightsSection::onColorChanged(const QColor& color)
{
	this->colorBtn->setStyleSheet("background-color: " + color.name());
}

void LightsSection::transformSection()
{
	this->transform = std::make_unique<QGroupBox>("Transform");
	TransformWidget* position = new TransformWidget(this->parent, TransformWidget::POSITION, "Position");
	TransformWidget* rotation = new TransformWidget(this->parent, TransformWidget::ROTATION, "Rotation");
	TransformWidget* scale = new TransformWidget(this->parent, TransformWidget::SCALE, "Scale");

	QGridLayout* transformLayout = new QGridLayout();
	transformLayout->addWidget(position->getGroup(), 0, 0);
	transformLayout->addWidget(rotation->getGroup(), 1, 0);
	transformLayout->addWidget(scale->getGroup(), 2, 0);
	transformLayout->setAlignment(Qt::AlignTop);
	transformLayout->setSpacing(1);

	this->getTransform()->setLayout(transformLayout);
}

void LightsSection::typeSection()
{
	this->type = std::make_unique<QWidget>();

	QPushButton* pointBtn = new QPushButton("Point");
	pointBtn->setCheckable(true);
	pointBtn->setChecked(true);
	QPushButton* directionnalBtn = new QPushButton("Directionnal");
	directionnalBtn->setCheckable(true);
	QPushButton* spotBtn = new QPushButton("Spot");
	spotBtn->setCheckable(true);

	QGridLayout* typeLayout = new QGridLayout();
	typeLayout->setAlignment(Qt::AlignTop);
	typeLayout->addWidget(pointBtn, 0, 0);
	typeLayout->addWidget(directionnalBtn, 0, 1);
	typeLayout->addWidget(spotBtn, 0, 2);
	typeLayout->setSpacing(0);

	this->getType()->setLayout(typeLayout);
}

void LightsSection::shadowSection()
{
	this->shadows = std::make_unique<QGroupBox>("Shadows");

	QGridLayout* shadowLayout = new QGridLayout();
	QCheckBox* ck_enable = new QCheckBox("Activate", this);
	shadowLayout->addWidget(ck_enable);

	this->getShadows()->setLayout(shadowLayout);
}

void LightsSection::energySection()
{
	this->energy = std::make_unique<QGroupBox>("Energy");
	QLocale lang(QLocale::English, QLocale::UnitedKingdom);

	this->energySlider = new QSlider(Qt::Horizontal, this);
	this->energySlider->setRange(0, 100);

	this->energyInput = new QDoubleSpinBox();
	energyInput->setLocale(lang);
	this->energyInput->setValue(0.0);
	this->energyInput->setFixedWidth(50);
	this->energyInput->setAlignment(Qt::AlignCenter);

	QGridLayout* energyLayout = new QGridLayout();
	energyLayout->addWidget(this->energySlider, 0, 0, 0, 1);
	energyLayout->addWidget(this->energyInput, 0, 3, 1, 1);

	connect(this->energySlider, SIGNAL(valueChanged(int)), this, SLOT(energySliderChanged(int)));
	connect(this->energyInput, SIGNAL(valueChanged(double)), this, SLOT(energyBtnChanged(double)));

	this->getEnergy()->setLayout(energyLayout);
}

void LightsSection::energyBtnChanged(double value)
{
	this->energySlider->setValue(value);
}

void LightsSection::energySliderChanged(int value) 
{
	this->energyInput->setValue((double)value);
}

LightsSection::~LightsSection()
{

}
