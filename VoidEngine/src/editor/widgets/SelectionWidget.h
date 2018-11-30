#pragma once

#include <QVector>
#include <QtWidgets>

#include "../../mesh/Mesh.h"
#include "../../scene/Node.h"

class SelectionWidget : public QWidget
{
	Q_OBJECT
public:
	SelectionWidget(QWidget* parent = Q_NULLPTR);

	inline void addNode(Node* node) { this->nodes.push_back(node); }
	inline Node* getNode(int index) { return this->nodes.at(index); }
	inline Node* getFirst() { return this->nodes.first(); }
	inline Node* getLast() { return this->nodes.last(); }
	inline QVector<Node*>& getNodes() { return this->nodes; }
	inline void clear() { this->nodes.clear(); }
	inline int getSize() { return this->nodes.size(); }

	~SelectionWidget();

public slots:
signals:

private:
	QVector<Node*> nodes;
};
