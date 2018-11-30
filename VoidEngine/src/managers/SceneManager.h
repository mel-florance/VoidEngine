#pragma once

#include <QtWidgets>
#include <QSharedPointer>
#include "../scene/Scene.h"

class SceneManager
{
public:
	SceneManager(QWidget* parent = Q_NULLPTR);
	~SceneManager();

	inline QVector<QSharedPointer<Scene>>& getScenes() { return this->scenes; }
	inline void addScene(QSharedPointer<Scene> scene) { this->scenes.push_back(scene); }
	inline QSharedPointer<Scene> getActiveScene() { return this->activeScene; }
	inline void setActiveScene(QSharedPointer<Scene> scene) { this->activeScene = scene; }

private:
	QWidget* parent;
	QSharedPointer<Scene> activeScene;
	QVector<QSharedPointer<Scene>> scenes;
};

