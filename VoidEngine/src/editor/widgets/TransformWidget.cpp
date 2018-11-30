#include "TransformWidget.h"
#include "../../core/VoidEngine.h"

TransformWidget::TransformWidget(QWidget* parent, TransformType type, const QString& name) : QWidget(parent)
{
	this->parent = parent;
	this->type = type;
	this->name = name;
	this->node = nullptr;
	this->group = std::make_unique<QWidget>();
	QLocale lang(QLocale::English, QLocale::UnitedKingdom);

	QLabel* label = new QLabel(name);
	label->setFixedWidth(56);

	this->xInput = new QDoubleSpinBox();
	this->xInput->setRange(-100000.0, 100000.0);
	this->xInput->setAlignment(Qt::AlignCenter);
	this->xInput->setLocale(lang);
	this->xInput->setValue(0.0);
	this->xInput->setSingleStep(0.01);
	QObject::connect(this->xInput, SIGNAL(valueChanged(double)), this, SLOT(onXInputChanged(double)));

	this->yInput = new QDoubleSpinBox();
	this->yInput->setRange(-100000.0, 100000.0);
	this->yInput->setAlignment(Qt::AlignCenter);
	this->yInput->setLocale(lang);
	this->yInput->setValue(0.0);
	this->yInput->setSingleStep(0.01);
	QObject::connect(this->yInput, SIGNAL(valueChanged(double)), this, SLOT(onYInputChanged(double)));

	this->zInput = new QDoubleSpinBox();
	this->zInput->setRange(-100000.0, 100000.0);
	this->zInput->setLocale(lang);
	this->zInput->setAlignment(Qt::AlignCenter);
	this->zInput->setValue(0.0);
	this->zInput->setSingleStep(0.01);
	QObject::connect(this->zInput, SIGNAL(valueChanged(double)), this, SLOT(onZInputChanged(double)));

	QGridLayout* layout = new QGridLayout();

	layout->addWidget(label,  0, 0, 0, 1);
	layout->addWidget(this->xInput, 0, 1, 0, 1);
	layout->addWidget(this->yInput, 0, 2, 0, 1);
	layout->addWidget(this->zInput, 0, 3, 0, 1);

	layout->setAlignment(Qt::AlignTop);
	layout->setSpacing(1);
	layout->setMargin(0);

	this->getGroup()->setLayout(layout);
}

void TransformWidget::setNode(Node* n)
{
	this->node = n;

	if (this->node != nullptr)
	{
		float yaw = 0.f;
		float pitch = 0.f;
		float roll = 0.f;

		this->node->transform->rotation().getEulerAngles(&yaw, &pitch, &roll);

		switch (this->type) {
		case POSITION:
			this->xInput->setValue((double)this->node->transform->translation().x());
			this->yInput->setValue((double)this->node->transform->translation().y());
			this->zInput->setValue((double)this->node->transform->translation().z());
			break;
		case ROTATION:
			this->xInput->setValue((double)yaw);
			this->yInput->setValue((double)roll);
			this->zInput->setValue((double)pitch);
			break;
		case SCALE:
			this->xInput->setValue((double)this->node->transform->scale().x());
			this->yInput->setValue((double)this->node->transform->scale().y());
			this->zInput->setValue((double)this->node->transform->scale().z());
			break;
		}
	}
}

void TransformWidget::onXInputChanged(double value)
{
	if (this->node != nullptr)
	{
		switch (this->type) {
		case POSITION:
			this->node->transform->setTranslationX((float)value);
			break;
		case ROTATION:
			this->node->transform->setRotationX((float)value);
			break;
		case SCALE:
			this->node->transform->setScaleX((float)value);
			break;
		}
	}
}

void TransformWidget::onYInputChanged(double value)
{
	if (this->node != nullptr)
	{
		switch (this->type) {
		case POSITION:
			this->node->transform->setTranslationY((float)value);
			break;
		case ROTATION:
			this->node->transform->setRotationY((float)value);
			break;
		case SCALE:
			this->node->transform->setScaleY((float)value);
			break;
		}
	}
}

void TransformWidget::onZInputChanged(double value)
{
	if (this->node != nullptr)
	{
		switch (this->type) {
		case POSITION:
			this->node->transform->setTranslationZ((float)value);
			break;
		case ROTATION:
			this->node->transform->setRotationZ((float)value);
			break;
		case SCALE:
			this->node->transform->setScaleZ((float)value);
			break;
		}
	}
}

TransformWidget::~TransformWidget()
{

}
