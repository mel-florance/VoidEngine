#pragma once

#include <QVector3D>
#include <QVector>
#include <QString>
#include <QMetaType>
#include <QSharedPointer>

#include "../core/Transform.h"
#include "../mesh/Mesh.h"

class Node
{
public:
	Node();
	~Node();

	QString name;
	Transform* transform;
	QVector<QSharedPointer<Mesh>> meshes;
	QVector<Node*> nodes;
	Node* parent;
	unsigned int id;
private:
};

Q_DECLARE_METATYPE(Node*);