#pragma once

#include <QtWidgets>

class Console
{
public:
	Console();
	~Console();

	inline QTextEdit* getTextarea() { return this->textarea.get(); }

private:
	std::unique_ptr<QTextEdit> textarea;
};
