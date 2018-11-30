#pragma once

#include <memory>
#include <cmath>
#include <windows.h>

#include <QtWidgets>
#include <QDropEvent>
#include <QMimeData>
#include <QFileInfo>

#include "ui_VoidEngine.h"
#include "../projects/ProjectDialog.h"

#include "../editor/Outliner.h"
#include "../editor/Inspector.h"
#include "../editor/AssetsManager.h"
#include "../editor/Console.h"
#include "../editor/Viewport.h"
#include "../editor/StatusBar.h"

#include "MeshLoader.h"
#include "../editor/widgets/SelectionWidget.h"
#include "../managers/InputsManager.h"
#include "../managers/SceneManager.h"
#include "../cameras/FPSCamera.h"

class VoidEngine : public QMainWindow
{
	Q_OBJECT

protected:
	void dragEnterEvent(QDragEnterEvent* e) override;
	void dropEvent(QDropEvent* e) override;

public:
	VoidEngine();
	~VoidEngine();

	void setupLayout();
	void projectCreate();

	inline Outliner* getOutliner() { return this->outliner.get(); }
	inline Console* getConsole() { return this->console.get(); }
	inline Inspector* getInspector() { return this->inspector.get(); }
	inline Viewport* getViewport() { return this->viewport.get(); }
	inline AssetsManager* getAssetsManager() { return this->assetsManager.get(); }
	inline SceneManager* getSceneManager() { return this->sceneManager.get(); }

	void exit();

protected:
	void showEvent(QShowEvent* e);

private:
	Ui::VoidEngineClass ui;
	std::unique_ptr<ProjectDialog> projectDialog;
	MeshLoader* meshLoader;
	SelectionWidget* selection;
	InputsManager* inputsManager;
	std::unique_ptr<SceneManager> sceneManager;
	std::unique_ptr<Outliner> outliner;
	std::unique_ptr<Inspector> inspector;
	std::unique_ptr<AssetsManager> assetsManager;
	std::unique_ptr<Console> console;
	std::unique_ptr<Viewport> viewport;
	std::unique_ptr<StatusBar> statusBarLabel;
};
