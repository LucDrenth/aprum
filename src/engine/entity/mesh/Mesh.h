//
// Created by Luc Drenth on 08/10/2021.
//

#pragma once

#include "VertexBuffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"

#include "glm/vec3.hpp"

#include <vector>

class Mesh
{
private:
    VertexBuffer vertexBuffer_;
    VertexArray vertexArray_;
    IndexBuffer indexBuffer_;

public:
    void init(const void* vertices, unsigned int verticesSize, VertexBufferLayout& vertexLayout, const unsigned int *indices, unsigned int indicesCount);

    const VertexBuffer &getVertexBuffer() const;
    const VertexArray &getVertexArray() const;
    const IndexBuffer &getIndexBuffer() const;
};
