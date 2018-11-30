#include "Scene.h"

Scene::Scene()
{

}

void Scene::update(float delta)
{
	if(this->active_camera != nullptr)
		this->active_camera->update(delta);
}

Scene::~Scene()
{

}
