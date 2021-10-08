//
// Created by Luc Drenth on 01/10/2021.
//

#pragma once

#include <vector>
#include <GL/glew.h>
#include <iostream>

struct VertexBufferElement
{
    unsigned int type;
    unsigned int count;
    unsigned char normalized;

    static unsigned int getSizeOfType(unsigned int type)
    {
        switch (type)
        {
            case GL_FLOAT:          return 4;
            case GL_UNSIGNED_INT:   return 4;
            case GL_UNSIGNED_BYTE:  return 1;
            default:
                std::cout <<
                "ERROR: VertexBufferElement getSizeOfType(unsigned int type) received unhandled type" << std::endl;
                return 0;
        }
    }
};

class VertexBufferLayout
{
private:
    std::vector<VertexBufferElement> elements_;
    unsigned int stride_;
public:
    VertexBufferLayout();

    void push(GLuint type, unsigned int count)
    {
        elements_.push_back({type, count, GL_FALSE});
        stride_ += count * VertexBufferElement::getSizeOfType(type);
    }

    inline const std::vector<VertexBufferElement>& getElements() const
    {
        return elements_;
    }

    inline unsigned int getStride() const
    {
        return stride_;
    }
};
