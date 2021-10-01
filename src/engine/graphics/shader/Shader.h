//
// Created by Luc Drenth on 29/09/2021.
//
#include <iostream>

#pragma once

class Shader
{
private:
    unsigned int rendererId_;

public:
    Shader(unsigned int type, std::string& path);

private:
    unsigned int compile(unsigned int type, std::string& source);
    unsigned int handleCompileError(unsigned int type, std::string& source, unsigned int id) const;
    static std::string parse(std::string &path);

public:
    unsigned int getRendererId() const;
};
