//
// Created by Luc Drenth on 30/09/2021.
//

#pragma once

#include "engine/graphics/shader/ShaderProgram.h"
#include "VertexArray.h"
#include "IndexBuffer.h"

#include <GL/Glew.h>

class Renderer
{
public:
    static void draw(const VertexArray& vertexArray, const IndexBuffer& indexBuffer, const ShaderProgram& shaderProgram);
};