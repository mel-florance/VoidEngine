#pragma once

#include <QVector2D>
#include <QVector3D>

class Vertex
{
public:
	Q_DECL_CONSTEXPR Vertex();
	Q_DECL_CONSTEXPR explicit Vertex(const QVector3D &position);
	Q_DECL_CONSTEXPR Vertex(const QVector3D &position, const QVector3D& normal);
	Q_DECL_CONSTEXPR Vertex(const QVector3D &position, const QVector3D& normal, const QVector2D& uvs);
	Q_DECL_CONSTEXPR Vertex(const QVector3D &position, const QVector3D& normal, const QVector2D& uvs, const QVector3D& tangent);

	Q_DECL_CONSTEXPR const QVector3D& position() const;
	Q_DECL_CONSTEXPR const QVector3D& normal() const;
	Q_DECL_CONSTEXPR const QVector2D& uvs() const;
	Q_DECL_CONSTEXPR const QVector3D& tangent() const;

	void setPosition(const QVector3D& position);
	void setNormal(const QVector3D& normal);
	void setUvs(const QVector2D& uvs);
	void setTangent(const QVector3D& tangent);

	static const int PositionTupleSize = 3;
	static const int NormalTupleSize = 3;
	static const int TangentTupleSize = 3;
	static const int UvsTupleSize = 2;

	static Q_DECL_CONSTEXPR int positionOffset();
	static Q_DECL_CONSTEXPR int normalOffset();
	static Q_DECL_CONSTEXPR int uvsOffset();
	static Q_DECL_CONSTEXPR int tangentOffset();
	static Q_DECL_CONSTEXPR int stride();

private:
	QVector3D m_position;
	QVector2D m_uvs;
	QVector3D m_normal;
	QVector3D m_tangent;
};

Q_DECLARE_TYPEINFO(Vertex, Q_MOVABLE_TYPE);

Q_DECL_CONSTEXPR inline Vertex::Vertex() {}
Q_DECL_CONSTEXPR inline Vertex::Vertex(const QVector3D &position) 
	: m_position(position) {}
Q_DECL_CONSTEXPR inline Vertex::Vertex(const QVector3D &position, const QVector3D& normal) 
	: m_position(position), m_normal(normal) {}
Q_DECL_CONSTEXPR inline Vertex::Vertex(const QVector3D &position, const QVector3D& normal, const QVector2D& uvs) 
	: m_position(position), m_normal(normal), m_uvs(uvs) {}
Q_DECL_CONSTEXPR inline Vertex::Vertex(const QVector3D &position, const QVector3D& normal, const QVector2D& uvs, const QVector3D& tangent)
	: m_position(position), m_normal(normal), m_uvs(uvs), m_tangent(tangent) {}

Q_DECL_CONSTEXPR inline const QVector3D& Vertex::position() const { return m_position; }
Q_DECL_CONSTEXPR inline const QVector2D& Vertex::uvs() const { return m_uvs; }
Q_DECL_CONSTEXPR inline const QVector3D& Vertex::normal() const { return m_normal; }
Q_DECL_CONSTEXPR inline const QVector3D& Vertex::tangent() const { return m_tangent; } 

void inline Vertex::setPosition(const QVector3D& position) { m_position = position; }
void inline Vertex::setUvs(const QVector2D& uvs) { m_uvs = uvs; }
void inline Vertex::setNormal(const QVector3D& normal) { m_normal = normal; }
void inline Vertex::setTangent(const QVector3D& tangent) { m_tangent = tangent; }

Q_DECL_CONSTEXPR inline int Vertex::positionOffset() { return offsetof(Vertex, m_position); }
Q_DECL_CONSTEXPR inline int Vertex::uvsOffset() { return offsetof(Vertex, m_uvs); }
Q_DECL_CONSTEXPR inline int Vertex::normalOffset() { return offsetof(Vertex, m_normal); }
Q_DECL_CONSTEXPR inline int Vertex::tangentOffset() { return offsetof(Vertex, m_tangent); }
Q_DECL_CONSTEXPR inline int Vertex::stride() { return sizeof(Vertex); }
