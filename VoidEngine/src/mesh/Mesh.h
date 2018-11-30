#pragma once

#include <QVector3D>
#include <QtOpenGL>
#include <QString>
#include <vector>
#include <QMatrix4x4>
#include <QSharedPointer>
#include <QMetaType>

#include "../materials/Material.h"

class Mesh
{
public:
	Mesh(const QString& name);
	~Mesh();

	void setupBuffers(QSharedPointer<QOpenGLShaderProgram> shader);
	void draw();

	inline QString& getName() { return this->name; }
	inline void setName(const QString& name) { this->name = name; }

	inline QOpenGLVertexArrayObject& getVao() { return this->vao; }
	inline QOpenGLBuffer& getIbo() { return this->ibo; }
	inline void setIbo(QOpenGLBuffer ibo) { this->ibo = ibo; }

	inline QVector<unsigned int>& getIndices() { return this->indices; }
	inline void setIndices(QVector<unsigned int> indices) { this->indices = indices; }

	inline QVector<float>& getVertices() { return this->vertices; }
	inline void setVertices(QVector<float> vertices) { this->vertices = vertices; }

	inline QVector<float>& getUvs() { return this->uvs; }
	inline void setUvs(QVector<float> uvs) { this->uvs = uvs; }

	inline QVector<float>& getNormals() { return this->normals; }
	inline void setNormals(QVector<float> normals) { this->normals = normals; }

	inline QVector<float>& getTangents() { return this->tangents; }
	inline void setTangents(QVector<float> tangents) { this->tangents = tangents; }

	inline QSharedPointer<Material> getMaterial() { return this->material; }
	inline void setMaterial(QSharedPointer<Material> material) { this->material = material; }

private:
	QString name;
	QOpenGLVertexArrayObject vao;
	QOpenGLBuffer ibo;
	QVector<unsigned int> indices;
	QVector<float> vertices;
	QVector<float> uvs;
	QVector<float> normals;
	QVector<float> tangents;
	QSharedPointer<Material> material;
};

Q_DECLARE_METATYPE(Mesh*);
