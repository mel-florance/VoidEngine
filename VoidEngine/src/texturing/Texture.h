#pragma once

#include <QString>
#include <QOpenGLTexture>

class Texture : public QOpenGLTexture
{
public:
	Texture(QImage& image);
	~Texture();
};

