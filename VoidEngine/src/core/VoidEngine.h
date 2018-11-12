#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include <QTextEdit>
#include <QSplitter>
#include <QList>
#include <QtWidgets>
#include <memory>

#include "ui_VoidEngine.h"
#include "../projects/ProjectDialog.h"

#include "../editor/Outliner.h"
#include "../editor/Inspector.h"
#include "../editor/AssetsManager.h"
#include "../editor/Console.h"
#include "../editor/Viewport.h"
#include "../editor/StatusBar.h"

class VoidEngine : public QMainWindow
{
public:
	VoidEngine();
	~VoidEngine();

	void projectCreate();
	void exit();

private:
	Ui::VoidEngineClass ui;
	std::unique_ptr<ProjectDialog> projectDialog;

	std::unique_ptr<Outliner> outliner;
	std::unique_ptr<Inspector> inspector;
	std::unique_ptr<AssetsManager> assetsManager;
	std::unique_ptr<Console> console;
	std::unique_ptr<Viewport> viewport;
	std::unique_ptr<StatusBar> statusBarLabel;
};
