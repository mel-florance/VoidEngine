#include "InputsManager.h"

QPoint InputsManager::mouseCurrPos = QPoint();
QPoint InputsManager::mousePrevPos = QPoint();
QPoint InputsManager::mouseDelta = QPoint();

InputsManager::InputsManager(QObject* parent) : QObject(parent)
{
	qApp->installEventFilter(this);
}

bool InputsManager::eventFilter(QObject* obj, QEvent* event)
{
	this->mousePrevPos = this->mouseCurrPos;
	this->mouseCurrPos = QCursor::pos();
	this->mouseDelta = this->mouseCurrPos - this->mousePrevPos;

	for (auto listener : this->listeners) 
	{
		switch (event->type()) 
		{
			case QEvent::KeyPress:
				emit keyPressed(static_cast<QKeyEvent*>(event));
				break;
			case QEvent::KeyRelease:
				emit keyReleased(static_cast<QKeyEvent*>(event));
				break;
			case QEvent::MouseMove:
				emit mouseMoved(static_cast<QMouseEvent*>(event));
				break;
			case QEvent::MouseButtonPress:
				emit mousePressed(static_cast<QMouseEvent*>(event));
				break;
			case QEvent::MouseButtonRelease:
				emit mouseReleased(static_cast<QMouseEvent*>(event));
				break;
			case QEvent::Wheel:
				emit mouseWheeled(static_cast<QWheelEvent*>(event));
				break;
		}
	}

	return QObject::eventFilter(obj, event);
}


InputsManager::~InputsManager()
{

}
