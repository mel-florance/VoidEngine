#pragma once

#include <Qstring>
#include <QVector3D>

#include "../rendering/Shader.h"

class Material
{
public:
	Material(const QString& name, QSharedPointer<Shader> shader);
	virtual ~Material();

	inline QString& getName() { return this->name; }
	inline void setName(const QString& name) { this->name = name; }

	inline QSharedPointer<Shader> getShader() { return this->shader; }
	inline void setShader(QSharedPointer<Shader> shader) { this->shader = shader; }

protected:
	QString name;
	QSharedPointer<Shader> shader;
	QMap<QString, int> uniforms;

};

Q_DECLARE_METATYPE(Material*);