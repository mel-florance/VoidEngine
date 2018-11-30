#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <cassert>
#include <windows.h>

#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QtOpenGL>
#include <QString>
#include <QThread>
#include <QSharedPointer>
#include <QtWidgets>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/ProgressHandler.hpp>

#include "Transform.h"
#include "../mesh/Mesh.h"
#include "../scene/Node.h"
#include "../rendering/Shader.h"


class MeshLoader : public QObject, protected QOpenGLExtraFunctions, public Assimp::ProgressHandler
{
	Q_OBJECT

public:
	MeshLoader();
	~MeshLoader();

	inline Node* getRoot() { return this->rootNode;  }
	inline QVector<QSharedPointer<Mesh>> getMeshes() { return this->meshes;  }
	inline static QSharedPointer<Shader> getShader() { return MeshLoader::shader; }
	inline static void setShader(QSharedPointer<Shader> s) { MeshLoader::shader = s; }

	bool importMesh(const std::string& filename);
	void processNode(const aiScene* scene, aiNode* node, Node* parentNode, Node* newNode);
	Node* getNodeData() { return rootNode; }
	QSharedPointer<Mesh> processMesh(aiMesh* object);

	inline void setPath(const QString& p) { this->path = p; }
	inline const QString& getPath() { return this->path;  }

	bool Update(float percentage = -1.f);

	static QSharedPointer<Shader> shader;

signals:
	void progress(float percentage = -1.f);
	void finished(Node* root);

public slots:
	void process();

private:
	QString path;
	unsigned int nodeId;

	std::vector<GLuint> vaos;
	QVector<QSharedPointer<Mesh>> meshes;
	Node* rootNode;

	QVector<unsigned int> m_indices;
	QVector<float> m_vertices;
	QVector<float> m_uvs;
	QVector<float> m_normals;
	QVector<float> m_tangents;
};

