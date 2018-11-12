#include "Transform.h"

void Transform::translate(const QVector3D &dt)
{
	m_dirty = true;
	m_translation += dt;
}

void Transform::scale(const QVector3D &ds)
{
	m_dirty = true;
	m_scale *= ds;
}

void Transform::rotate(const QQuaternion &dr)
{
	m_dirty = true;
	m_rotation = dr * m_rotation;
}

void Transform::grow(const QVector3D &ds)
{
	m_dirty = true;
	m_scale += ds;
}

void Transform::setTranslation(const QVector3D &t)
{
	m_dirty = true;
	m_translation = t;
}

void Transform::setScale(const QVector3D &s)
{
	m_dirty = true;
	m_scale = s;
}

void Transform::setRotation(const QQuaternion &r)
{
	m_dirty = true;
	m_rotation = r;
}

const QMatrix4x4 &Transform::toMatrix()
{
	if (m_dirty)
	{
		m_dirty = false;
		m_world.setToIdentity();
		m_world.translate(m_translation);
		m_world.rotate(m_rotation);
		m_world.scale(m_scale);
	}
	return m_world;
}

QDebug operator<<(QDebug dbg, const Transform &transform)
{
	dbg << "Transform\n{\n";
	dbg << "Position: <" << transform.translation().x() << ", " << transform.translation().y() << ", " << transform.translation().z() << ">\n";
	dbg << "Scale: <" << transform.scale().x() << ", " << transform.scale().y() << ", " << transform.scale().z() << ">\n";
	dbg << "Rotation: <" << transform.rotation().x() << ", " << transform.rotation().y() << ", " << transform.rotation().z() << " | " << transform.rotation().scalar() << ">\n}";
	return dbg;
}

QDataStream &operator<<(QDataStream &out, const Transform &transform)
{
	out << transform.m_translation;
	out << transform.m_scale;
	out << transform.m_rotation;
	return out;
}

QDataStream &operator>>(QDataStream &in, Transform &transform)
{
	in >> transform.m_translation;
	in >> transform.m_scale;
	in >> transform.m_rotation;
	transform.m_dirty = true;
	return in;
}