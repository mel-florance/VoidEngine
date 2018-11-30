#version 330 core

layout (location = 0) in highp vec3 position;
layout (location = 1) in highp vec2 uvs;
layout (location = 2) in highp vec3 normal;
layout (location = 3) in highp vec3 tangent;

out highp vec2 fUvs;
out highp vec3 fPos;
out highp vec3 fNormal;
out highp vec3 fTangent;

uniform mat4 mProj;
uniform mat4 mView;
uniform mat4 mTransform;

void main()
{
    fUvs = uvs;
    fPos = vec3(mTransform * vec4(position, 1.0));
    fNormal = mat3(mTransform) * normal;   
    fTangent = tangent;

    gl_Position = mProj * mView * vec4(fPos, 1.0);
}