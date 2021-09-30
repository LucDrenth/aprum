//
// Created by Luc Drenth on 30/09/2021.
//

#pragma once

class IndexBuffer
{
private:
    unsigned int rendererId_;
    unsigned int count_;

public:
    IndexBuffer();
    ~IndexBuffer();

    void init(const unsigned int* data, unsigned int count);
    void bind() const;
    static void unbind();

    inline unsigned int getCount() const;
};
