#pragma once

#include <memory>
#include <QtWidgets>
#include "inspector/WorldSection.h"
#include "inspector/LightsSection.h"
#include "inspector/ObjectSection.h"
#include "inspector/ParticlesSection.h"
#include "inspector/PhysicsSection.h"

class Inspector
{
public:
	Inspector();
	~Inspector();

	inline QTabWidget* getTabs() { return this->sections.get(); }
	void addSection(QWidget* section, const QString& name);

	inline WorldSection* getWorld() { return this->world.get();  }
	inline LightsSection* getLights() { return this->lights.get();  }
	inline ObjectSection* getObject() { return this->object.get();  }
	inline ParticlesSection* getParticles() { return this->particles.get();  }
	inline PhysicsSection* getPhysics() { return this->physics.get();  }

private:
	std::unique_ptr<QTabWidget> sections;

	// Sections
	std::unique_ptr<WorldSection> world;
	std::unique_ptr<LightsSection> lights;
	std::unique_ptr<ObjectSection> object;
	std::unique_ptr<ParticlesSection> particles;
	std::unique_ptr<PhysicsSection> physics;
};
