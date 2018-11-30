#pragma once


#include <QSharedPointer>
#include <QVariant>
#include <QtWidgets>
#include <QFile>

#include "../core/MeshLoader.h"

class AssetsManager : public QWidget
{
	Q_OBJECT

public slots:
	void modelLoaded(Node* root);
	void modelProgress(float value);
	void loadingFinished();

public:
	AssetsManager(QWidget* parent);
	~AssetsManager();

	QTabWidget* getTabs() { return this->tabs.get(); }
	QTreeView* getTree() { return this->tree.get(); }
	QString& getRoot() { return this->root; }
	inline MeshLoader* getMeshLoader() { return this->meshLoader; }

	void addChild(QTreeWidgetItem* parent, Node* child);
	inline bool moveFile(const QString& source, const QString& dest) { return QFile::copy(source, dest); }

public slots:
	void onTreeViewClicked(QModelIndex index);
	void fileListClicked(QModelIndex index);

private:
	QString root;
	QWidget* parent;
	QTreeWidgetItem* sceneTree;
	QThread* thread;

	MeshLoader* meshLoader;
	QProgressDialog* progressDialog;

	std::unique_ptr<QTabWidget> tabs;
	std::unique_ptr<QTreeView> tree;
	std::unique_ptr<QSplitter> splitter;

	std::unique_ptr<QFileSystemModel> dirModel;
	QSharedPointer<QFileSystemModel> fileModel;
	QSharedPointer<QTreeView> fileList;
};
