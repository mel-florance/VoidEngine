#include "Texture.h"

Texture::Texture(QImage& image) : QOpenGLTexture(image)
{
	//this->setFormat(QOpenGLTexture::RGBAFormat);
	this->setMinificationFilter(QOpenGLTexture::Linear);
	this->setMagnificationFilter(QOpenGLTexture::LinearMipMapNearest);
	this->setWrapMode(QOpenGLTexture::ClampToBorder);
	this->generateMipMaps(true);
}

Texture::~Texture()
{
		
}
