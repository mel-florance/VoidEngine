#include "DefaultMaterial.h"

DefaultMaterial::DefaultMaterial(const QString& name, QSharedPointer<Shader> shader) : Material(name, shader)
{
	this->uniforms["albedo"] = this->shader->getProgram()->uniformLocation("albedo");
	this->uniforms["metallic"] = this->shader->getProgram()->uniformLocation("metallic");
	this->uniforms["roughness"] = this->shader->getProgram()->uniformLocation("roughness");
	this->uniforms["ao"] = this->shader->getProgram()->uniformLocation("ao");

	this->uniforms["albedoMap"] = this->shader->getProgram()->uniformLocation("albedoMap");
	this->uniforms["normalMap"] = this->shader->getProgram()->uniformLocation("normalMap");
	this->uniforms["MRAMap"] = this->shader->getProgram()->uniformLocation("MRAMap");
}

void DefaultMaterial::bindUniforms(Camera* camera, QVector<QSharedPointer<Light>>& lights)
{
	this->shader->getProgram()->setUniformValue("mProj", camera->getProjection());
	this->shader->getProgram()->setUniformValue("mView", camera->toMatrix());
	this->shader->getProgram()->setUniformValue("camPos", camera->getTranslation());

	this->textures[ALBEDO]->bind(0);
	this->textures[NORMAL]->bind(1);
	this->textures[MRA]->bind(2);
	//this->textures[METALLIC]->bind(2);
	//this->textures[ROUGHNESS]->bind(3);
	//this->textures[AO]->bind(4);

	//this->shader->getProgram()->setUniformValue("albedo", this->albedo);
	//this->shader->getProgram()->setUniformValue("metallic", this->metallic);
	//this->shader->getProgram()->setUniformValue("roughness", this->roughness);
	//this->shader->getProgram()->setUniformValue("ao", this->ao);

	for (int i = 0; i < lights.size(); i++)
	{
		QSharedPointer<Light> light = lights[i];
		QString pos = "lightPositions[" + QString::number(i) + "]";
		QString col = "lightColors[" + QString::number(i) + "]";
		this->shader->getProgram()->setUniformValue(pos.toStdString().c_str(), light->getPosition());
		this->shader->getProgram()->setUniformValue(col.toStdString().c_str(), light->getColor());
	}
}

DefaultMaterial::~DefaultMaterial()
{

}
