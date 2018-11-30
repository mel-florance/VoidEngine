#include "MeshLoader.h"
#include "../mesh/Vertex.h"

QSharedPointer<Shader> MeshLoader::shader(nullptr);

MeshLoader::MeshLoader() : nodeId(0)
{

}

bool MeshLoader::Update(float percentage)
{
	emit progress(percentage);
	return true;
}

void MeshLoader::process()
{
	this->importMesh(this->path.toLocal8Bit().constData());
}

bool MeshLoader::importMesh(const std::string& filename)
{  
	Assimp::Importer importer;
	importer.SetProgressHandler((Assimp::ProgressHandler*) this);

	const aiScene* scene = importer.ReadFile(filename,
		aiProcess_CalcTangentSpace
		| aiProcess_GenSmoothNormals
		| aiProcess_Triangulate
		//| aiProcess_FlipUVs
		//| aiProcess_GenNormals
		//| aiProcess_JoinIdenticalVertices
		//| aiProcess_MakeLeftHanded
		//| aiProcess_RemoveComponent
		//| aiProcess_PreTransformVertices
		//| aiProcess_FindInstances
		//| aiProcess_FlipWindingOrder
		//| aiProcess_SplitByBoneCount
		//| aiProcess_Debone
		//| aiProcess_OptimizeMeshes 
		//| aiProcess_OptimizeGraph
		//| aiProcess_TransformUVCoords
		//| aiProcess_ValidateDataStructure
		//| aiProcess_FixInfacingNormals
		//| aiProcess_ImproveCacheLocality
		//| aiProcess_LimitBoneWeights
		//| aiProcess_RemoveRedundantMaterials
		//| aiProcess_SplitLargeMeshes
		//| aiProcess_GenUVCoords
		//| aiProcess_SortByPType
		//| aiProcess_FindDegenerates
		//| aiProcess_FindInvalidData
	);

	if (!scene)
	{
		qDebug() << importer.GetErrorString();
		return false;
	}

	if (scene->HasMeshes())
	{
		for (unsigned int i = 0; i < scene->mNumMeshes; ++i)
			this->meshes.push_back(this->processMesh(scene->mMeshes[i]));
	}
	else
	{
		qDebug() << "Error: No meshes found";
		return false;
	}

	if (scene->mRootNode != NULL)
	{
		this->rootNode = new Node();
		this->processNode(scene, scene->mRootNode, 0, this->rootNode);
		//this->rootNode.reset(rootNode);
	}
	else
	{
		qDebug() << "Error loading model";
		return false;
	}

	qDebug() << "Loaded model:" << scene->mRootNode->mName.C_Str();
	emit finished(this->rootNode);

	return true;
}

void MeshLoader::processNode(const aiScene* scene, aiNode* node, Node* parentNode, Node* newNode)
{
	const char* name = node->mName.length != 0 ? node->mName.C_Str() : "child_node";

	newNode->name = name;
	newNode->id = QRandomGenerator::global()->generate();
	newNode->transform = new Transform();
	//newNode.transform->setWorld(QMatrix4x4(node->mTransformation[0]));
	newNode->meshes.resize(node->mNumMeshes);

	for (uint i = 0; i < node->mNumMeshes; ++i)
	{
		QSharedPointer<Mesh> mesh = meshes[node->mMeshes[i]];
		newNode->meshes[i] = mesh;
	}

	for (uint i = 0; i < node->mNumChildren; ++i)
	{
		newNode->nodes.push_back(new Node());
		this->processNode(scene, node->mChildren[i], parentNode, newNode->nodes[i]);
	}
}

QSharedPointer<Mesh> MeshLoader::processMesh(aiMesh* object)
{
	const char* name = object->mName.length != 0 ? object->mName.C_Str() : "";
	QSharedPointer<Mesh> mesh = QSharedPointer<Mesh>::create(name);

	if (object->HasFaces())
	{
		for (unsigned int i = 0; i < object->mNumFaces; i++)
		{
			mesh->getIndices().push_back(object->mFaces[i].mIndices[0]);
			mesh->getIndices().push_back(object->mFaces[i].mIndices[1]);
			mesh->getIndices().push_back(object->mFaces[i].mIndices[2]);
		}
	}
	
	for (GLuint i = 0; i < object->mNumVertices; i++)
	{
		if (object->HasPositions()) {
			mesh->getVertices().push_back(object->mVertices[i].x);
			mesh->getVertices().push_back(object->mVertices[i].y);
			mesh->getVertices().push_back(object->mVertices[i].z);
		}


		if (object->HasTextureCoords(0)) 
		{
			mesh->getUvs().push_back(object->mTextureCoords[0][i].x);
			mesh->getUvs().push_back(object->mTextureCoords[0][i].y);
		}

		if (object->HasNormals()) {
			mesh->getNormals().push_back(object->mNormals[i].x);
			mesh->getNormals().push_back(object->mNormals[i].y);
			mesh->getNormals().push_back(object->mNormals[i].z);
		}

		if (object->HasTangentsAndBitangents()) {
			mesh->getTangents().push_back(object->mTangents[i].x);
			mesh->getTangents().push_back(object->mTangents[i].y);
			mesh->getTangents().push_back(object->mTangents[i].z);
		}
	}

	m_indices = mesh->getIndices();
	m_vertices = mesh->getVertices();
	m_normals = mesh->getNormals();
	m_uvs = mesh->getUvs();
	m_tangents = mesh->getTangents();

	return mesh;
}

MeshLoader::~MeshLoader()
{

}
