//
// Created by Luc Drenth on 30/09/2021.
//

#pragma once

#include "graphics/shader/ShaderProgram.h"
#include "entity/mesh/VertexArray.h"
#include "entity/mesh/IndexBuffer.h"
#include "entity/mesh/Mesh.h"

#include <GL/Glew.h>

class Renderer
{
public:
    static void draw(const VertexArray& vertexArray, const IndexBuffer& indexBuffer, const ShaderProgram& shaderProgram);
    static void draw(const Mesh& mesh, ShaderProgram& shaderProgram, glm::vec3& position, glm::vec3& rotation);
};