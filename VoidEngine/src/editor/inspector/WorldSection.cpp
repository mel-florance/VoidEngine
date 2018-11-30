#include "WorldSection.h"

WorldSection::WorldSection(QWidget* parent) : QWidget(parent)
{
	this->group = std::make_unique<QWidget>();

	this->colorSection();
	this->fogSection();
	this->aoSection();

	QGridLayout* mainLayout = new QGridLayout();
	mainLayout->setAlignment(Qt::AlignTop);
	mainLayout->addWidget(this->getColor());
	mainLayout->addWidget(this->getFog());
	mainLayout->addWidget(this->getAo());

	this->group->setLayout(mainLayout);
}

void WorldSection::colorSection()
{
	this->color = std::make_unique<QGroupBox>("Color");

	this->colorBtn = new QPushButton();
	this->colorBtn->setStyleSheet("background-color: #ffffff");
	this->colorDialog = new QColorDialog();

	QObject::connect(this->colorBtn, &QPushButton::clicked, this, &WorldSection::onColorBtnClicked);
	QObject::connect(this->colorDialog, &QColorDialog::currentColorChanged, this, &WorldSection::onColorChanged);
	QGridLayout* colorLayout = new QGridLayout();
	colorLayout->addWidget(this->colorBtn);

	this->getColor()->setLayout(colorLayout);
}

void WorldSection::onColorBtnClicked()
{
	this->colorDialog->show();
}

void WorldSection::onColorChanged(const QColor& color)
{
	this->colorBtn->setStyleSheet("background-color: " + color.name());
}

void WorldSection::aoSection()
{
	this->ao = std::make_unique<QGroupBox>("Ambient Occlusion");

	QGridLayout* aoLayout = new QGridLayout();
	QCheckBox* ck_enable = new QCheckBox("Activate", this);
	aoLayout->addWidget(ck_enable);

	this->getAo()->setLayout(aoLayout);
}

void WorldSection::fogSection()
{
	this->fog = std::make_unique<QGroupBox>("Fog");
	QLocale lang(QLocale::English, QLocale::UnitedKingdom);

	QLabel* labelStart = new QLabel(" Start");
	QDoubleSpinBox* startInput = new QDoubleSpinBox();
	startInput->setValue(0.1);
	startInput->setLocale(lang);
	startInput->setAlignment(Qt::AlignCenter);

	QLabel* labelEnd = new QLabel(" End");
	QDoubleSpinBox* endInput = new QDoubleSpinBox();
	endInput->setValue(0.5);
	endInput->setLocale(lang);
	endInput->setAlignment(Qt::AlignCenter);

	QLabel* labelDensity = new QLabel(" Density");
	QDoubleSpinBox* densityInput = new QDoubleSpinBox();
	densityInput->setValue(1.0);
	densityInput->setLocale(lang);
	densityInput->setAlignment(Qt::AlignCenter);

	QLabel* labelHeight = new QLabel(" Height");
	QDoubleSpinBox* heightInput = new QDoubleSpinBox();
	heightInput->setValue(1.0);
	heightInput->setLocale(lang);
	heightInput->setAlignment(Qt::AlignCenter);

	QGridLayout* layout = new QGridLayout();
	layout->setAlignment(Qt::AlignTop);
	layout->addWidget(labelStart, 0, 0);
	layout->addWidget(startInput, 0, 1);
	layout->addWidget(labelEnd, 0, 2);
	layout->addWidget(endInput, 0, 3);
	layout->addWidget(labelDensity, 1, 0);
	layout->addWidget(densityInput, 1, 1);
	layout->addWidget(labelHeight, 1, 2);
	layout->addWidget(heightInput, 1, 3);

	this->getFog()->setLayout(layout);
}

WorldSection::~WorldSection()
{

}
