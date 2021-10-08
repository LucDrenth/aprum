//
// Created by Luc Drenth on 08/10/2021.
//

#pragma once

#include "graphics/renderer/VertexBuffer.h"
#include "graphics/renderer/VertexArray.h"
#include "graphics/renderer/IndexBuffer.h"

#include "glm/vec3.hpp"

#include <vector>

class Mesh
{
private:
    glm::vec3 position_;
    glm::vec3 rotation_;

    VertexBuffer vertexBuffer_;
    VertexArray vertexArray_;
    IndexBuffer indexBuffer_;

public:
    Mesh();
    void init(const void* vertices, unsigned int verticesSize, VertexBufferLayout& vertexLayout, const unsigned int *indices, unsigned int indicesCount);

    const glm::vec3 &getPosition() const;
    const glm::vec3 &getRotation() const;
    const VertexBuffer &getVertexBuffer() const;
    const VertexArray &getVertexArray() const;
    const IndexBuffer &getIndexBuffer() const;
};
