//
// Created by Luc Drenth on 02/10/2021.
//

#pragma once

#include <iostream>

class Texture
{
private:
    unsigned int rendererId_;
    std::string filePath_;
    unsigned char* localBuffer_;
    int width_;
    int height_;
    int bitsPerPixel_;

public:
    Texture();
    ~Texture();

    void init (const std::string& filePath);
    void bind (unsigned int slot = 0);
    void unbind();
};
