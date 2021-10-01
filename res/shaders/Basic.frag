#version 330 core

out vec4 outputColor;

in vec3 color;

uniform vec4 u_Color;

void main()
{
   outputColor = vec4(u_Color.x, color.y, color.z, 1.0f);
}