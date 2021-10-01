//
// Created by Luc Drenth on 30/09/2021.
//

#include "IndexBuffer.h"
#include "Renderer.h"

IndexBuffer::IndexBuffer()
{
}

void IndexBuffer::init(const unsigned int *data, unsigned int count)
{
    count_ = count;

    GLCall(glGenBuffers(1, &rendererId_));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererId_));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer()
{
    GLCall(glDeleteBuffers(1, &rendererId_));
}

void IndexBuffer::bind() const
{
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererId_));
}

void IndexBuffer::unbind()
{
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

unsigned int IndexBuffer::getCount() const
{
    return count_;
}
