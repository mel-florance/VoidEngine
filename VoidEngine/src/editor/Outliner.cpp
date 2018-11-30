#include "Outliner.h"
#include "../core/VoidEngine.h"

Outliner::Outliner(QWidget* parent) : QWidget(parent)
{
	this->parent = parent;
	this->tabs = std::make_unique<QTabWidget>();
	this->tree = std::make_unique<QTreeWidget>();
	this->tree->setObjectName("outliner");
	this->tree->setColumnCount(1);
	this->tree->setHeaderHidden(true);

	QObject::connect(this->tree.get(), &QTreeView::clicked, this, &Outliner::itemClicked);
	this->getTabs()->addTab(this->tree.get(), "Outliner");
}

void Outliner::itemClicked(QModelIndex index)
{
	VoidEngine* engine = (VoidEngine*)this->parent;
	QTreeWidgetItem* item = this->tree->currentItem();

	if (engine->getInspector() != Q_NULLPTR)
	{
		QVariant v = item->data(0, Qt::UserRole);

		if (!v.isNull())
		{
			Node* node = v.value<Node*>();

			if (node != nullptr) {
				engine->getInspector()->getObject()->setNode(node);
			}
		}
	}
}

void Outliner::addItem(int column, const QString& name)
{
	QTreeWidgetItem* item =  new QTreeWidgetItem();
	QTreeWidgetItem* child = new QTreeWidgetItem();

	item->setExpanded(true);
	child->setExpanded(true);
	child->setText(0, name);
	item->setText(0, name);
	item->addChild(child);

	this->getTree()->addTopLevelItem(item);
}

Outliner::~Outliner()
{

}
