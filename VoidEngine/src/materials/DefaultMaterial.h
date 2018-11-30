#pragma once

#include "../cameras/Camera.h"
#include "../lighting/Light.h"
#include "../texturing/Texture.h"
#include "Material.h"

class DefaultMaterial : public Material
{
public:
	DefaultMaterial(const QString& name, QSharedPointer<Shader> shader);
	~DefaultMaterial();

	inline QVector3D& getAlbedo() { return this->albedo; }
	inline void setAlbedo(const QVector3D& albedo) { this->albedo = albedo; }

	inline float getMetallic() { return this->metallic; }
	inline void setMetallic(float value) { this->metallic = value; }

	inline float getRoughness() { return this->roughness; }
	inline void setRoughness(float value) { this->roughness = value; }

	inline float getAo() { return this->ao; }
	inline void setAo(float value) { this->ao = value; }

	void bindUniforms(Camera* camera, QVector<QSharedPointer<Light>>& lights);

	enum TEXTURES_TYPES {
		ALBEDO,
		NORMAL,
		MRA
	};

	inline void setTexture(TEXTURES_TYPES type, QSharedPointer<Texture> texture) { this->textures[type] = texture; }
	inline QSharedPointer<Texture> getTexture(TEXTURES_TYPES type) { return this->textures[type]; }

private:
	QVector3D albedo;
	float metallic;
	float roughness;
	float ao;

	QMap<TEXTURES_TYPES, QSharedPointer<Texture>> textures;
};
