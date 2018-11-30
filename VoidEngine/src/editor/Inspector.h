#pragma once

#include <memory>
#include <QMap>
#include <QtWidgets>
#include <QString>

#include "inspector/WorldSection.h"
#include "inspector/SceneSection.h"
#include "inspector/CameraSection.h"
#include "inspector/MaterialSection.h"
#include "inspector/TextureSection.h"
#include "inspector/LightsSection.h"
#include "inspector/ObjectSection.h"
#include "inspector/ParticlesSection.h"
#include "inspector/PhysicsSection.h"

class Inspector
{
public:
	Inspector(QWidget* parent = Q_NULLPTR);
	~Inspector();

	inline QTabWidget* getTabs() { return this->tabs.get(); }
	void addSection(unsigned int column, QWidget* section, QIcon& icon);

	inline WorldSection* getWorld() { return this->world.get();  }
	inline SceneSection* getScene() { return this->scene.get();  }
	inline CameraSection* getCamera() { return this->camera.get();  }
	inline MaterialSection* getMaterial() { return this->material.get();  }
	inline TextureSection* getTexture() { return this->texture.get();  }
	inline LightsSection* getLights() { return this->lights.get();  }
	inline ObjectSection* getObject() { return this->object.get();  }
	inline ParticlesSection* getParticles() { return this->particles.get();  }
	inline PhysicsSection* getPhysics() { return this->physics.get();  }

private:
	std::unique_ptr<QTabWidget> tabs;

	std::unique_ptr<WorldSection> world;
	std::unique_ptr<SceneSection> scene;
	std::unique_ptr<CameraSection> camera;
	std::unique_ptr<MaterialSection> material;
	std::unique_ptr<TextureSection> texture;
	std::unique_ptr<LightsSection> lights;
	std::unique_ptr<ObjectSection> object;
	std::unique_ptr<ParticlesSection> particles;
	std::unique_ptr<PhysicsSection> physics;
};
