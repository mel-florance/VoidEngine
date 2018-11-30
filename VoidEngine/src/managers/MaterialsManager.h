#pragma once

#include <QMap>
#include <QSharedPointer>
#include "../materials/Material.h"

class MaterialsManager
{
public:
	MaterialsManager();
	~MaterialsManager();

	inline QMap<QString, QSharedPointer<Material>>& getMaterials() { return this->materials; }
	inline void addMaterial(const QString& name, QSharedPointer<Material> texture) {
		this->materials.insert(name, texture);
	}

	inline QSharedPointer<Material> getMaterial(const QString& name)
	{
		if (this->materials.contains(name))
			return this->materials.value(name);

		return nullptr;
	}

	inline void removeMaterial(const QString& name) { this->materials.remove(name); }

private:
	QMap<QString, QSharedPointer<Material>> materials;
};

