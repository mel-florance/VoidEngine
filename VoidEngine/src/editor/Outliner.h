#pragma once

#include <QtWidgets>
#include <QSharedPointer>
#include "../editor/widgets/SelectionWidget.h"
#include "../mesh/Mesh.h"
#include "../scene/Node.h"

class Outliner : public QWidget
{
public:
	Outliner(QWidget* parent = Q_NULLPTR);
	~Outliner();

	void itemClicked(QModelIndex index);
	void addItem(int column, const QString& name);

	inline QTabWidget* getTabs() { return this->tabs.get(); }
	inline QTreeWidget* getTree() { return this->tree.get(); }
	inline QSharedPointer<SelectionWidget> getSelection() { return this->selection; }
	inline void setSelection(QSharedPointer<SelectionWidget> sel) { this->selection = sel; }
	inline void addToSelection(Node* node) { this->selection->addNode(node); }

private:
	QWidget* parent;
	QSharedPointer<SelectionWidget> selection;
	std::unique_ptr<QTabWidget> tabs;
	std::unique_ptr<QTreeWidget> tree;
};