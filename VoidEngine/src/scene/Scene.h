#pragma once

#include <QVector>
#include <QSharedPointer>

#include "Node.h"
#include "../mesh/Mesh.h"
#include "../cameras/Camera.h"
#include "../lighting/Light.h"

class Scene
{
public:
	Scene();
	~Scene();

	typedef QSharedPointer<Light> LightPtr;

	inline void setActiveCamera(Camera* camera) { this->active_camera = camera; }
	inline Camera* getActiveCamera() { return this->active_camera; }
	inline QVector<Node*> getNodes() { return this->nodes; }
	inline void addNode(Node* node) { this->nodes.push_back(node); }

	inline QVector<LightPtr> getLights() { return this->lights; }
	inline void addLight(LightPtr light) { this->lights.push_back(light); }

	inline Node* findNodeById(Node* node, unsigned int id)
	{
		if (node->id == id)
			return node;

		if (node->nodes.size() == 0)
			return nullptr;

		for (auto n : node->nodes)
		{
			if (n->id == id)
				return n;
			else
				return this->findNodeById(n, id);
		}
	}

	inline Node* getNodeById(unsigned int id)
	{
		for (auto node : this->nodes) 
		{
			if (node->id == id)
				return node;
			else
				return this->findNodeById(node, id);
		}
	}

	void update(float delta);

private:
	QVector<Node*> nodes;
	Camera* active_camera;
	QVector<LightPtr> lights;
};
