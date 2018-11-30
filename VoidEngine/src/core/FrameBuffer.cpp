#include "FrameBuffer.h"

FrameBuffer::FrameBuffer(int width, int height, GLenum target) 
	: QOpenGLFramebufferObject(width, height, target)
{

}

FrameBuffer::~FrameBuffer()
{

}
