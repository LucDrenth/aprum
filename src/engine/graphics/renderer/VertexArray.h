//
// Created by Luc Drenth on 01/10/2021.
//

#pragma once


#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray
{
private:
    unsigned int rendererId_;

public:
    VertexArray();
    ~VertexArray();

    void init();
    void addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
    void bind() const;
    void unbind() const;
};
