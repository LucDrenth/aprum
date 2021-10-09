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

void Mesh::init(Shape shape)
{
    VertexBufferLayout layout;
    layout.push(GL_FLOAT, 3); // position
    layout.push(GL_FLOAT, 3); // color

    switch(shape)
    {
        case CUBE:
        {
            float vertices[] = {
                    // position             // color
                    -1.0f, -1.0f, -1.0f, 0.5f, 0.0f, 0.0f,
                     1.0f, -1.0f, -1.0f, 0.0f, 0.5f, 0.0f,
                     1.0f,  1.0f, -1.0f, 0.0f, 0.0f, 0.5f,
                    -1.0f,  1.0f, -1.0f, 0.5f, 0.5f, 0.0f,
                    -1.0f, -1.0f,  1.0f, 0.0f, 0.5f, 0.5f,
                     1.0f, -1.0f,  1.0f, 0.0f, 0.0f, 0.5f,
                     1.0f,  1.0f,  1.0f, 0.5f, 0.5f, 0.0f,
                    -1.0f,  1.0f,  1.0f, 0.0f, 0.5f, 0.5f,
            };
            unsigned int indices[] = {
                    5, 4, 0, 1, 5, 0, 6, 5, 1, 2, 6, 1,
                    7, 6, 2, 3, 7, 2, 4, 7, 3, 0, 4, 3,
                    6, 7, 4, 5, 6, 4, 1, 0, 3, 2, 1, 3
            };

            init(vertices, sizeof(vertices), layout, indices, sizeof(indices) / sizeof(unsigned int));
        }
        break;

        case PYRAMID:
        {
            float vertices[] = {
                    // position             // color
                    -0.5f, 0.0f,  0.5f,     0.5f, 0.0f, 0.0f,
                    -0.5f, 0.0f, -0.5f,     0.0f, 0.5f, 0.0f,
                     0.5f, 0.0f, -0.5f,     0.0f, 0.0f, 0.5f,
                     0.5f, 0.0f,  0.5f,     0.5f, 0.5f, 0.0f,
                     0.0f, 0.8f,  0.0f,     0.0f, 0.5f, 0.5f,
            };
            unsigned int indices[] = {
                    0, 1, 2,
                    0, 2, 3,
                    0, 1, 4,
                    1, 2, 4,
                    2, 3, 4,
                    3, 0, 4
            };

            init(vertices, sizeof(vertices), layout, indices, sizeof(indices) / sizeof(unsigned int));
        }
        break;
    }
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
