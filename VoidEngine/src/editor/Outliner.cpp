#include "Outliner.h"

Outliner::Outliner()
{
	this->tabs = std::make_unique<QTabWidget>();
	this->tree = std::make_unique<QTreeWidget>();
	this->tree->setColumnCount(1);
	this->getTabs()->addTab(this->tree.get(), "Outliner");
}

void Outliner::addItem(int column, const QString& name)
{
	QTreeWidgetItem* item =  new QTreeWidgetItem();
	QTreeWidgetItem* child = new QTreeWidgetItem();
	child->setText(0, name);
	item->setText(0, name);
	item->addChild(child);
	this->getTree()->addTopLevelItem(item);
}

Outliner::~Outliner()
{

}
