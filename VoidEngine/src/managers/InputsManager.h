#pragma once

#include <QtWidgets>
#include <QMap>
#include <QString>


class InputsManager : public QObject
{
	Q_OBJECT
public:
	
	InputsManager(QObject* parent = Q_NULLPTR);
	~InputsManager();

	void addListener(const QString& name) {
		this->listeners.append(name);
	}

	static QPoint mouseCurrPos;
	static QPoint mousePrevPos;
	static QPoint mouseDelta;

signals:
	void keyPressed(QKeyEvent* event);
	void keyReleased(QKeyEvent* event);
	void mouseMoved(QMouseEvent* event);
	void mousePressed(QMouseEvent* event);
	void mouseReleased(QMouseEvent* event);
	void mouseWheeled(QWheelEvent* event);

protected:
	bool eventFilter(QObject* obj, QEvent* event);

private:
	QStringList listeners;
};
