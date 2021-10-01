//
// Created by Luc Drenth on 01/10/2021.
//

#include "VertexArray.h"
#include "engine/logger/GLErrorHandler.h"

VertexArray::VertexArray()
{
}

VertexArray::~VertexArray()
{
    GLCall(glDeleteVertexArrays(1, &rendererId_));
}

void VertexArray::init()
{
    GLCall(glGenVertexArrays(1, &rendererId_));
}

void VertexArray::addBuffer(const VertexBuffer &vb, const VertexBufferLayout &layout)
{
    bind();
    vb.bind();
    const std::vector<VertexBufferElement>& elements = layout.getElements();
    unsigned int offset = 0;

    for(unsigned int i = 0; i < elements.size(); i++)
    {
        const VertexBufferElement& element = elements[i];
        GLCall(glEnableVertexAttribArray(i));
        GLCall(glVertexAttribPointer(
                i, element.count, element.type, element.normalized, layout.getStride(), (const void*)offset));
        offset += element.count * VertexBufferElement::getSizeOfType(element.type);
    }
}

void VertexArray::bind() const
{
    GLCall(glBindVertexArray(rendererId_));
}

void VertexArray::unbind() const
{
    GLCall(glBindVertexArray(0));
}
