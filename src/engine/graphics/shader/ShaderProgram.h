//
// Created by Luc Drenth on 01/10/2021.
//

#pragma once

#include "glm/glm.hpp"

#include <iostream>
#include <unordered_map>

class ShaderProgram
{
private:
    unsigned int program_;
    std::unordered_map<std::string, int> uniformLocationCache_;

public:
    ShaderProgram();
    ~ShaderProgram();

    void init(std::string vertexShaderPath, std::string fragmentShaderPath);
    void use() const;

    void setUniform1f(const std::string& name, float f);
    void setUniform2f(const std::string& name, float f0, float f1);
    void setUniform3f(const std::string& name, float f0, float f1, float f2);
    void setUniform4f(const std::string& name, float f0, float f1, float f2, float f3);
    void setUniform1i(const std::string& name, int value);
    void setUniformMat4f(const std::string& name, const glm::mat4& matrix);

private:
    int getUniformLocation(const std::string& name);
};
