//
// Created by Luc Drenth on 08/10/2021.
//

#include "graphics/shader/ShaderProgram.h"
#include "Mesh.h"

void Mesh::init(const void *vertices, unsigned int verticesSize, VertexBufferLayout& vertexLayout,
                const unsigned int *indices, unsigned int indicesCount)
{
    vertexBuffer_.init(vertices, verticesSize);
    vertexArray_.init();
    vertexArray_.addBuffer(vertexBuffer_, vertexLayout);
    indexBuffer_.init(indices, indicesCount);
}

const VertexBuffer &Mesh::getVertexBuffer() const
{
    return vertexBuffer_;
}

const VertexArray &Mesh::getVertexArray() const
{
    return vertexArray_;
}

const IndexBuffer &Mesh::getIndexBuffer() const
{
    return indexBuffer_;
}
