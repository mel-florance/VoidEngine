#include "AssetsManager.h"

AssetsManager::AssetsManager(QObject* parent) : QObject(parent)
{
	this->parent = parent;
	this->tabs = std::make_unique<QTabWidget>();
	this->tree = std::make_unique<QTreeView>();
	this->splitter = std::make_unique<QSplitter>();
	this->root = "C:/Users/overk/VoidEngineProjects";

	QObject::connect(this->tree.get(), &QTreeView::clicked, this, &AssetsManager::onTreeViewClicked);

	this->dirModel = std::make_unique<QFileSystemModel>();
	this->dirModel->setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);
	this->dirModel->setRootPath(this->root);

	this->fileModel = std::make_unique<QFileSystemModel>();
	this->fileModel->setFilter(QDir::Files | QDir::NoDotAndDotDot);
	this->fileModel->setRootPath(this->root);

	QModelIndex idx = this->dirModel->index(this->root);
	this->tree->setModel(this->dirModel.get());
	this->tree->setRootIndex(idx);
	this->tree->hideColumn(1);
	this->tree->hideColumn(2);
	this->tree->hideColumn(3);
	this->tree->setHeaderHidden(true);

	this->splitter->addWidget(this->tree.get());

	this->fileList = std::make_unique<QTreeView>();
	this->fileList->setModel(this->fileModel.get());
	this->fileList->hideColumn(1);
	this->fileList->hideColumn(2);
	this->fileList->hideColumn(3);
	this->fileList->setHeaderHidden(true);
	QModelIndex id = this->fileModel->index(this->root);
	this->fileList->setRootIndex(id);
	this->fileList->setObjectName("treeViewList");

	this->splitter->addWidget(this->fileList.get());
	this->getTabs()->addTab(this->splitter.get(), "Assets Manager");
}

void AssetsManager::onTreeViewClicked(QModelIndex index)
{
	QString path = this->dirModel->fileInfo(index).absoluteFilePath();
	QTreeView* list = this->parent->findChild<QTreeView*>("treeViewList");
	QModelIndex idx = this->fileModel->setRootPath(path);
	list->setRootIndex(idx);
}

AssetsManager::~AssetsManager()
{

}
