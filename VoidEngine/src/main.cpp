#include "core/VoidEngine.h"
#include <QtWidgets/QApplication>
#include <QGLFormat>

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_UseDesktopOpenGL, true);
	QApplication* app = new QApplication(argc, argv);
	app->setStyle(QStyleFactory::create("Fusion"));

	QPalette darkPalette;
	darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
	darkPalette.setColor(QPalette::WindowText, Qt::white);
	darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
	darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
	darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
	darkPalette.setColor(QPalette::ToolTipText, Qt::white);
	darkPalette.setColor(QPalette::Text, Qt::white);
	darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
	darkPalette.setColor(QPalette::ButtonText, Qt::white);
	darkPalette.setColor(QPalette::BrightText, Qt::red);
	darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
	darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
	darkPalette.setColor(QPalette::HighlightedText, Qt::black);

	app->setPalette(darkPalette);
	app->setStyleSheet(
		"QToolTip {"
			"color: #ffffff;"
			"background-color: #2a82da;"
			"border: 1px solid white;"
		"}"
	);

	VoidEngine* e = new VoidEngine();
	e->show();

	return app->exec();
}
