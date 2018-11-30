#pragma once

#include <QtWidgets>
#include <memory>

#include "../widgets/TransformWidget.h"

class LightsSection : public QWidget
{
	Q_OBJECT

public:
	LightsSection(QWidget* parent = Q_NULLPTR);
	~LightsSection();

	QWidget* getGroup() { return this->group.get(); }
	QWidget* getType() { return this->type.get(); }
	QGroupBox* getTransform() { return this->transform.get(); }
	QGroupBox* getEnergy() { return this->energy.get(); }
	QGroupBox* getColor() { return this->color.get(); }
	QGroupBox* getShadows() { return this->shadows.get(); }

	void colorSection();
	void shadowSection();
	void transformSection();
	void typeSection();
	void energySection();
	void onColorBtnClicked();
	void onColorChanged(const QColor &color);

public slots:
	void energyBtnChanged(double value);
	void energySliderChanged(int value);

private:
	QWidget* parent;
	std::unique_ptr<QWidget> group;
	std::unique_ptr<QWidget> type;
	std::unique_ptr<QGroupBox> energy;
	std::unique_ptr<QGroupBox> transform;
	std::unique_ptr<QGroupBox> color;
	std::unique_ptr<QGroupBox> shadows;

	QPushButton* colorBtn;
	QColorDialog* colorDialog;
	QDoubleSpinBox* energyInput;
	QSlider* energySlider;
};
