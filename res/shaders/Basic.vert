#version 330 core

layout(location = 0) in vec3 aPosition;
layout(location = 1) in vec3 aColor;
//layout(location = 2) in vec2 aTextureCoordinates;

out vec3 color;
//out vec2 textureCoordinates;

uniform mat4 u_modelMatrix;
uniform mat4 u_viewMatrix;
uniform mat4 u_projectionMatrix;

void main()
{
    gl_Position = u_projectionMatrix * u_viewMatrix * u_modelMatrix * vec4(aPosition, 1.0);
    color = aColor;
//    textureCoordinates = aTextureCoordinates;
}