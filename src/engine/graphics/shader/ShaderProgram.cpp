//
// Created by Luc Drenth on 01/10/2021.
//

#include "ShaderProgram.h"
#include "engine/logger/GLErrorHandler.h"
#include "Shader.h"
#include <GL/glew.h>

ShaderProgram::ShaderProgram()
{
}

void ShaderProgram::init(std::string vertexShaderPath, std::string fragmentShaderPath)
{
    Shader basicVertexShader(GL_VERTEX_SHADER, vertexShaderPath);
    Shader basicFragmentShader(GL_FRAGMENT_SHADER, fragmentShaderPath);

    GLCall(program_ = glCreateProgram());
    GLCall(glAttachShader(program_, basicVertexShader.getRendererId()));
    GLCall(glAttachShader(program_, basicFragmentShader.getRendererId()));
    GLCall(glLinkProgram(program_));
    GLCall(glValidateProgram(program_));
}

ShaderProgram::~ShaderProgram()
{
    GLCall(glDeleteProgram(program_));
}

void ShaderProgram::use() const
{
    GLCall(glUseProgram(program_));
}

int ShaderProgram::getUniformLocation(const std::string &name)
{
    if (uniformLocationCache_.find(name) != uniformLocationCache_.end())
        return uniformLocationCache_[name];

    GLCall( int location = glGetUniformLocation(program_, name.c_str()) );
    if (location == -1)
        std::cout << "WARNING: No active shader uniform variable found with name " << name  << std::endl;

    uniformLocationCache_[name] = location;

    return location;
}

void ShaderProgram::setUniform1f(const std::string &name, float f)
{
    GLCall( glUniform1f(getUniformLocation(name), f) );
}

void ShaderProgram::setUniform2f(const std::string &name, float f0, float f1)
{
    GLCall( glUniform2f(getUniformLocation(name), f0, f1) );
}

void ShaderProgram::setUniform3f(const std::string &name, float f0, float f1, float f2)
{
    GLCall( glUniform3f(getUniformLocation(name), f0, f1, f2) );
}

void ShaderProgram::setUniform4f(const std::string &name, float f0, float f1, float f2, float f3)
{
    GLCall( glUniform4f(getUniformLocation(name), f0, f1, f2, f3) );
}

void ShaderProgram::setUniform1i(const std::string &name, int value)
{
    GLCall(glUniform1i(getUniformLocation(name), value));
}
