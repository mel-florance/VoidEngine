#pragma once

#include <QMap>
#include <QSharedPointer>
#include "../texturing/Texture.h"

class TexturesManager
{
public:
	TexturesManager();
	~TexturesManager();

	inline QMap<QString, QSharedPointer<Texture>>& getTextures() { return this->textures; }
	inline void addTexture(const QString& name, QSharedPointer<Texture> texture) { 
		this->textures.insert(name, texture); 
	}

	inline QSharedPointer<Texture> getTexture(const QString& name)
	{
		if (this->textures.contains(name))
			return this->textures.value(name);

		return nullptr;
	}

	inline void removeTexture(const QString& name) { this->textures.remove(name); }

private:
	QMap<QString, QSharedPointer<Texture>> textures;
};

