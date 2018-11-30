#include "Material.h"

Material::Material(const QString& name, QSharedPointer<Shader> shader) : name(name), shader(shader)
{
	this->uniforms["mProj"] = this->shader->getProgram()->uniformLocation("mProj");
	this->uniforms["mView"] = this->shader->getProgram()->uniformLocation("mView");
	this->uniforms["camPos"] = this->shader->getProgram()->uniformLocation("camPos");
	this->uniforms["mTransform"] = this->shader->getProgram()->uniformLocation("mTransform");

	for (int i = 0; i < 4; i++)
	{
		this->shader->getProgram()->uniformLocation("lightPositions[" + QString::number(i) + "]");
		this->shader->getProgram()->uniformLocation("lightColors[" + QString::number(i) + "]");
	}
}

Material::~Material()
{
}
