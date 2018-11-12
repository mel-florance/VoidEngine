#include "TransformWidget.h"

TransformWidget::TransformWidget(QWidget* parent, const QString& name) : QWidget(parent)
{
	this->name = name;
	this->transform = QVector3D();
	this->group = std::make_unique<QWidget>();
	QLabel* label = new QLabel(name);

	QDoubleSpinBox* xInput = new QDoubleSpinBox();
	xInput->setAlignment(Qt::AlignCenter);
	QLocale lang(QLocale::English, QLocale::UnitedKingdom);
	xInput->setLocale(lang);

	xInput->valueFromText(lang.toString(this->transform.x()));
	QDoubleSpinBox* yInput = new QDoubleSpinBox();
	yInput->setAlignment(Qt::AlignCenter);
	yInput->setLocale(lang);
	yInput->valueFromText(lang.toString(this->transform.y()));
	QDoubleSpinBox* zInput = new QDoubleSpinBox();
	zInput->setLocale(lang);
	zInput->setAlignment(Qt::AlignCenter);
	zInput->valueFromText(lang.toString(this->transform.z()));

	QGridLayout* layout = new QGridLayout();
	label->setFixedWidth(56);
	layout->addWidget(label,  0, 0, 0, 1);
	layout->addWidget(xInput, 0, 1, 0, 1);
	layout->addWidget(yInput, 0, 2, 0, 1);
	layout->addWidget(zInput, 0, 3, 0, 1);

	layout->setAlignment(Qt::AlignTop);
	layout->setSpacing(1);
	layout->setMargin(0);

	this->getGroup()->setLayout(layout);
}


TransformWidget::~TransformWidget()
{
}
