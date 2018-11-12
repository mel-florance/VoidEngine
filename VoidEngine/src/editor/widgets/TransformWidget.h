#pragma once

#include <QtWidgets>
#include <QVector3D>
#include <memory>

class TransformWidget : public QWidget
{
public:
	TransformWidget(QWidget* parent, const QString& name);
	~TransformWidget();

	QWidget* getGroup() { return this->group.get(); }
	QVector3D& getTransform() { return this->transform; }

private:
	QString name;
	QVector3D transform;
	std::unique_ptr<QWidget> group;
};

