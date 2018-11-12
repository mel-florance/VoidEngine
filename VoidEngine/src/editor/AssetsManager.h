#pragma once

#include <QtWidgets>

class AssetsManager : public QObject
{
	Q_OBJECT

public:
	AssetsManager(QObject* parent);
	~AssetsManager();

	void onTreeViewClicked(QModelIndex index);
	QTabWidget* getTabs() { return this->tabs.get(); }
	QTreeView* getTree() { return this->tree.get(); }

private:
	QString root;
	QObject* parent;
	std::unique_ptr<QTabWidget> tabs;
	std::unique_ptr<QTreeView> tree;
	std::unique_ptr<QSplitter> splitter;

	std::unique_ptr<QFileSystemModel> dirModel;
	std::unique_ptr<QFileSystemModel> fileModel;
	std::unique_ptr<QTreeView> fileList;
};
