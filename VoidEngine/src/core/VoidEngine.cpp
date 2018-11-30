#include "VoidEngine.h"

VoidEngine::VoidEngine() : QMainWindow(Q_NULLPTR)
{
	ui.setupUi(this);

	this->setAcceptDrops(true);
	this->projectDialog = std::make_unique<ProjectDialog>();

	QAction* newProject = this->findChild<QAction*>("actionNew_project");
	QAction* exit = this->findChild<QAction*>("actionExit");
	QObject::connect(newProject, &QAction::triggered, this, &VoidEngine::projectCreate);
	QObject::connect(exit, &QAction::triggered, this, &VoidEngine::exit);

	this->sceneManager = std::make_unique<SceneManager>(this);

	this->outliner       = std::make_unique<Outliner>(this);
	this->inspector      = std::make_unique<Inspector>(this);
	this->console        = std::make_unique<Console>();
	this->assetsManager  = std::make_unique<AssetsManager>(this);
	this->viewport       = std::make_unique<Viewport>(this);
	this->statusBarLabel = std::make_unique<StatusBar>(this);

	this->inputsManager = new InputsManager(this);
	this->inputsManager->addListener("tabViewport");
	this->viewport->getGLWidget()->getDefaultScene()->setActiveCamera(this->viewport->getCamera());

	QObject::connect(this->inputsManager, SIGNAL(keyPressed(QKeyEvent*)), this->viewport->getCamera(), SLOT(onKeyPressed(QKeyEvent*)));
	QObject::connect(this->inputsManager, SIGNAL(keyReleased(QKeyEvent*)), this->viewport->getCamera(), SLOT(onKeyReleased(QKeyEvent*)));
	QObject::connect(this->inputsManager, SIGNAL(mouseMoved(QMouseEvent*)), this->viewport->getCamera(), SLOT(onMouseMoved(QMouseEvent*)));
	QObject::connect(this->inputsManager, SIGNAL(mousePressed(QMouseEvent*)), this->viewport->getCamera(), SLOT(onMousePressed(QMouseEvent*)));
	QObject::connect(this->inputsManager, SIGNAL(mouseReleased(QMouseEvent*)), this->viewport->getCamera(), SLOT(onMouseReleased(QMouseEvent*)));
	QObject::connect(this->inputsManager, SIGNAL(mouseWheeled(QWheelEvent*)), this->viewport->getCamera(), SLOT(onMouseWheeled(QWheelEvent*)));

	this->setupLayout();
}

void VoidEngine::setupLayout()
{
	QWidget* central = this->findChild<QWidget*>("centralWidget");

	this->assetsManager->getTabs()->addTab(this->console->getTextarea(), "Console");

	QSplitter* split1 = new QSplitter();
	QSplitter* split2 = new QSplitter();
	QSplitter* split3 = new QSplitter();

	split3->setOrientation(Qt::Vertical);
	split3->addWidget(this->outliner->getTabs());
	split3->addWidget(this->inspector->getTabs());
	split3->setStretchFactor(1, 2);

	QVBoxLayout* layout = new QVBoxLayout;
	QWidget* container = new QWidget;
	QVBoxLayout* container_layout = new QVBoxLayout;

	container_layout->setContentsMargins(QMargins(0, 0, 0, 0));
	layout->setContentsMargins(QMargins(5, 0, 5, 0));

	split1->setOrientation(Qt::Vertical);
	split1->addWidget(this->viewport->getTabs());
	split1->setSizes(QList<int>({ 50, 50 }));
	split1->setStretchFactor(0, 1);
	split1->addWidget(this->assetsManager->getTabs());

	container_layout->addWidget(split1);
	container->setLayout(container_layout);

	split2->addWidget(container);
	split2->addWidget(split3);
	split2->setSizes(QList<int>({ 900, 250 }));

	layout->addWidget(split2);
	this->statusBar()->addPermanentWidget(this->statusBarLabel->getLabel());
	central->setLayout(layout);

	this->viewport->getGLWidget()->getInfos();


}

void VoidEngine::projectCreate()
{
	if (this->projectDialog != Q_NULLPTR)
		this->projectDialog->show();
}

void VoidEngine::dragEnterEvent(QDragEnterEvent* e)
{
	if (e->mimeData()->hasUrls())
	{
		e->acceptProposedAction();
		qDebug() << "entered";
	}
}

void VoidEngine::showEvent(QShowEvent* event)
{
	//QMainWindow::showEvent(event);
}

void VoidEngine::dropEvent(QDropEvent * e)
{
	const QMimeData* mimeData = e->mimeData();

	if (mimeData->hasUrls())
	{
		QStringList pathList;
		QList<QUrl> urlList = mimeData->urls();

		for (int i = 0; i < urlList.size() && i < 32; ++i)
			pathList.append(urlList.at(i).toLocalFile());

		qDebug() << pathList;

		for (auto path : pathList)
		{
			QFileInfo file(path);
			this->assetsManager->moveFile(path, this->assetsManager->getRoot() + "/resources/" + file.fileName());
		}
	}
}

void VoidEngine::exit()
{
	this->close();
}

VoidEngine::~VoidEngine()
{

}
