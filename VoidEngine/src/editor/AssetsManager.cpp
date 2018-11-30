#include "AssetsManager.h"
#include "../core/VoidEngine.h"

AssetsManager::AssetsManager(QWidget* parent) : QWidget(parent)
{
	this->parent = parent;
	this->tabs = std::make_unique<QTabWidget>();
	this->tree = std::make_unique<QTreeView>();
	this->splitter = std::make_unique<QSplitter>();
	this->root = "C:/Users/overk/VoidEngineProjects/Survival";

	this->dirModel = std::make_unique<QFileSystemModel>();
	this->dirModel->setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);
	this->dirModel->setRootPath(this->root);

	this->fileModel = QSharedPointer<QFileSystemModel>::create();
	this->fileModel->setFilter(QDir::Files | QDir::NoDotAndDotDot);
	this->fileModel->setRootPath(this->root);

	QModelIndex idx = this->dirModel->index(this->root);
	this->tree->setModel(this->dirModel.get());
	this->tree->setRootIndex(idx);
	this->tree->hideColumn(1);
	this->tree->hideColumn(2);
	this->tree->hideColumn(3);

	this->splitter->addWidget(this->tree.get());

	this->fileList = QSharedPointer<QTreeView>::create();
	this->fileList->setModel(this->fileModel.get());

	QModelIndex id = this->fileModel->index(this->root);
	this->fileList->setRootIndex(id);
	this->fileList->setObjectName("treeViewList");

	this->splitter->addWidget(this->fileList.get());

	QObject::connect(this->tree.get(), &QTreeView::clicked, this, &AssetsManager::onTreeViewClicked);
	QObject::connect(this->fileList.get(), &QTreeView::doubleClicked, this, &AssetsManager::fileListClicked);



	this->sceneTree = new QTreeWidgetItem();
	this->sceneTree->setText(0, "Scene");
	this->sceneTree->setIcon(0, QIcon(":/res/icons/scene.png"));

	VoidEngine* engine = (VoidEngine*)this->parent;
	engine->getOutliner()->getTree()->addTopLevelItem(this->sceneTree);
	engine->getOutliner()->getTree()->expandToDepth(3);

	this->getTabs()->addTab(this->splitter.get(), "Assets Manager");
}

void AssetsManager::fileListClicked(QModelIndex index)
{
	QString path = this->dirModel->fileInfo(index).absoluteFilePath();
	QStringList ext = path.split(".");

	if (ext[1].toLower() == "obj"
	||  ext[1].toLower() == "fbx" 
	||  ext[1].toLower() == "dae" 
	||  ext[1].toLower() == "3ds" 
	||  ext[1].toLower() == "gltf" 
	||  ext[1].toLower() == "bin" 
	||  ext[1].toLower() == "blend")
	{
		this->meshLoader = new MeshLoader();
		//QObject::connect(this->meshLoader, SIGNAL(finished(Node*)), this, SLOT(modelLoaded(Node*)));
		this->thread = new QThread();
		this->meshLoader->setPath(path);
		//this->meshLoader->process();
		/*this->modelLoaded(this->meshLoader->getRoot());*/

		qRegisterMetaType<Node*>();

		this->progressDialog = new QProgressDialog("Importing data...", "Cancel", 0, 100);
		this->progressDialog->setWindowFlags(progressDialog->windowFlags() | Qt::WindowStaysOnTopHint);
		this->progressDialog->hide();

		QObject::connect(this->progressDialog, &QProgressDialog::canceled, this->thread, &QThread::quit);
		QObject::connect(this->thread, &QThread::started, this->meshLoader, &MeshLoader::process);
		QObject::connect(this->thread, &QThread::finished, this, &AssetsManager::loadingFinished);
		QObject::connect(this->meshLoader, SIGNAL(progress(float)), this, SLOT(modelProgress(float)));
		QObject::connect(this->meshLoader, SIGNAL(finished(Node*)), this, SLOT(modelLoaded(Node*)));

		this->meshLoader->moveToThread(this->thread);
		this->progressDialog->show();
		this->thread->start();
	}
}

void AssetsManager::loadingFinished()
{
	qDebug() << "thread ended";
}

void AssetsManager::modelLoaded(Node* root)
{
	this->thread->quit();
	this->progressDialog->hide();
	//root->transform->setTranslationX(20.f);

	qDebug() << root->name;

	VoidEngine* engine = (VoidEngine*)this->parent;

	if (engine->getOutliner() != Q_NULLPTR)
	{
		this->addChild(this->sceneTree, root);
		engine->getViewport()->getGLWidget()->getDefaultScene()->addNode(root);
		engine->getConsole()->getTextarea()->append("Loaded mesh: " + root->name);
	}
}

void AssetsManager::modelProgress(float value)
{
	this->progressDialog->setValue((int)floor(value * 100.0f));
}

void AssetsManager::onTreeViewClicked(QModelIndex index)
{
	QString path = this->dirModel->fileInfo(index).absoluteFilePath();
	QTreeView* list = this->parent->findChild<QTreeView*>("treeViewList");
	QModelIndex idx = this->fileModel->setRootPath(path);
	list->setRootIndex(idx);
}

void AssetsManager::addChild(QTreeWidgetItem* parent, Node* child)
{
	QTreeWidgetItem* item = new QTreeWidgetItem();
	item->setText(0, child->name);
	item->setIcon(0, QIcon(":/res/icons/object.png"));
	QVariant v;
	v.setValue(child);
	item->setData(0, Qt::UserRole, v);
	QVariant p = parent->data(0, Qt::UserRole);
	child->parent = p.value<Node*>();
	parent->addChild(item);

	if (child->nodes.size() > 0)
		for (auto node : child->nodes)
			this->addChild(item, node);
}

AssetsManager::~AssetsManager()
{

}
