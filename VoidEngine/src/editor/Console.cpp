#include "Console.h"

Console::Console()
{
	this->textarea = std::make_unique<QTextEdit>();
	this->textarea->setObjectName("consoleWidget");
	this->textarea->setFont(QFont("Consolas", 11));
	this->textarea->setReadOnly(true);
	this->textarea->setText("Engine started!");
}

Console::~Console()
{

}
