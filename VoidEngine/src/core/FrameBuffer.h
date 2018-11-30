#pragma once

#include <QOpenGLFramebufferObject>

class FrameBuffer : public QOpenGLFramebufferObject
{
public:
	FrameBuffer(int width, int height, GLenum target = GL_TEXTURE_2D);
	~FrameBuffer();
};

