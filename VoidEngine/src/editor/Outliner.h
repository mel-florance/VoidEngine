#pragma once

#include <QtWidgets>

class Outliner
{
public:
	Outliner();
	~Outliner();

	QTabWidget* getTabs() { return this->tabs.get(); }
	QTreeWidget* getTree() { return this->tree.get(); }
	void addItem(int column, const QString& name);

private:
	std::unique_ptr<QTabWidget> tabs;
	std::unique_ptr<QTreeWidget> tree;
};