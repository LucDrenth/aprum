//
// Created by Luc Drenth on 30/09/2021.
//

#include "VertexBuffer.h"
#include "Renderer.h"

VertexBuffer::VertexBuffer(const void *data, unsigned int size)
{
    GLCall(glGenBuffers(1, &rendererId_));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, rendererId_));
    GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer()
{
    GLCall(glDeleteBuffers(1, &rendererId_));
}

void VertexBuffer::bind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, rendererId_));
}

void VertexBuffer::unbind()
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
