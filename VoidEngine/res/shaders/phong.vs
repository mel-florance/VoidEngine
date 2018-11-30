#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 uvs;
layout (location = 2) in vec3 normal;
layout (location = 3) in vec3 tangent;

out vec4 fColor;

uniform mat4 mProj;
uniform mat4 mView;
uniform mat4 mTransform;

void main()
{
  gl_Position = mProj * mView * mTransform * vec4(position, 1.0);
  fColor = vec4(position, 1.0f);
}