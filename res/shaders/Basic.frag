#version 330 core

out vec4 outputColor;

in vec3 color;
//in vec2 textureCoordinates;

//uniform vec4 u_Color;
uniform sampler2D u_TextureSlot;

void main()
{
//   vec4 textureColor = texture(u_TextureSlot, textureCoordinates);
   outputColor = vec4(color, 1.0f);
//   outputColor = textureColor;
}