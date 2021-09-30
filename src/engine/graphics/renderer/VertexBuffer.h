//
// Created by Luc Drenth on 30/09/2021.
//

#pragma once

class VertexBuffer
{
private:
    unsigned int rendererId_;

public:
    VertexBuffer();
    ~VertexBuffer();

    void init(const void* data, unsigned int size);
    void bind() const;
    static void unbind();


};
