#include "VoidEngine.h"

VoidEngine::VoidEngine() : QMainWindow(Q_NULLPTR)
{
	ui.setupUi(this);
	this->projectDialog = std::make_unique<ProjectDialog>();

	QAction* newProject = this->findChild<QAction*>("actionNew_project");
	QAction* exit = this->findChild<QAction*>("actionExit");

	QObject::connect(newProject, &QAction::triggered, this, &VoidEngine::projectCreate);
	QObject::connect(exit, &QAction::triggered, this, &VoidEngine::exit);

	this->outliner = std::make_unique<Outliner>();
	this->inspector = std::make_unique<Inspector>();
	this->assetsManager = std::make_unique<AssetsManager>(this);
	this->console = std::make_unique<Console>();
	this->viewport = std::make_unique<Viewport>(this);
	this->statusBarLabel = std::make_unique<StatusBar>(this);

	QWidget* central = this->findChild<QWidget*>("centralWidget");

	this->assetsManager->getTabs()->addTab(this->console->getTextarea(), "Console");

	QSplitter* split1 = new QSplitter();
	QSplitter* split2 = new QSplitter();
	QSplitter* split3 = new QSplitter();

	split3->setOrientation(Qt::Vertical);

	for (int i = 0; i < 10; ++i) {
		this->outliner->addItem(i, "test");
	}

	split3->addWidget(this->outliner->getTabs());
	split3->addWidget(this->inspector->getTabs());
	split3->setStretchFactor(1, 2); 

	QVBoxLayout* layout = new QVBoxLayout;
	QWidget* container = new QWidget;
	QVBoxLayout* container_layout = new QVBoxLayout;

	split1->addWidget(this->viewport->getTabs());
	QList<int> list = { 50, 50 };
	split1->setSizes(list);

	container_layout->setContentsMargins(QMargins(0, 0, 0, 0));
	layout->setContentsMargins(QMargins(5, 0, 5, 0));

	split1->addWidget(this->assetsManager->getTabs());

	container_layout->addWidget(split1);
	container->setLayout(container_layout);

	split1->setOrientation(Qt::Vertical);
	split2->addWidget(container);
	split2->addWidget(split3);
	QList<int> l = { 900, 250 };
	split2->setSizes(l);
	layout->addWidget(split2);

	this->statusBar()->addPermanentWidget(this->statusBarLabel->getLabel());

	central->setLayout(layout);
	this->viewport->getGLWidget()->getInfos();
}

void VoidEngine::projectCreate()
{
	if(projectDialog != Q_NULLPTR)
		projectDialog->show();
}

void VoidEngine::exit()
{
	this->close();
}

VoidEngine::~VoidEngine()
{

}
