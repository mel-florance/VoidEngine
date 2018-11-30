#pragma once

#include <QtWidgets>
#include <QVector3D>



class Light : public QWidget
{
	Q_OBJECT
public:
	Light(QWidget* parent = Q_NULLPTR);
	virtual ~Light();

	inline QVector3D& getPosition() { return this->position; }
	inline void setPosition(const QVector3D& pos) { this->position = pos; }
	inline QVector3D& getColor() { return this->color; }
	inline void setColor(const QVector3D& col) { this->color = col; }

private:
	QVector3D position;
	QVector3D color;
};

