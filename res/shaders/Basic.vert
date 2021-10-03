#version 330 core

layout(location = 0) in vec2 aPosition;
layout(location = 1) in vec3 aColor;
layout(location = 2) in vec2 aTextureCoordinates;

out vec3 color;
out vec2 textureCoordinates;

uniform mat4 u_modelViewProjectionMatrix;

void main()
{
    gl_Position = u_modelViewProjectionMatrix * vec4(aPosition, 0.0, 1.0);
    color = aColor;
    textureCoordinates = aTextureCoordinates;
}