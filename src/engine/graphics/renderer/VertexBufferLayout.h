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

    template<typename T>
    void push(unsigned int count)
    {
        std::cout << "ERROR: This should not have been called called this" << std::endl;
    }

    template<>
    void push<float>(unsigned int count)
    {
        elements_.push_back({GL_FLOAT, count, GL_FALSE});
        stride_ += count * VertexBufferElement::getSizeOfType(GL_FLOAT);
    }

    template<>
    void push<unsigned int>(unsigned int count)
    {
        elements_.push_back({GL_UNSIGNED_INT, count, GL_FALSE});
        stride_ += count * VertexBufferElement::getSizeOfType(GL_UNSIGNED_INT);
    }

    template<>
    void push<unsigned char>(unsigned int count)
    {
        elements_.push_back({GL_UNSIGNED_BYTE, count, GL_TRUE});
        stride_ += count * VertexBufferElement::getSizeOfType(GL_UNSIGNED_BYTE);
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
