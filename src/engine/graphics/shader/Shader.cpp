//
// Created by Luc Drenth on 29/09/2021.
//

#include "Shader.h"
#include "engine/logger/GLErrorHandler.h"

#include <GL/glew.h>
#include <fstream>
#include <sstream>

Shader::Shader(unsigned int type, std::string& path)
{
    std::string source = parse(path);
    rendererId_ = compile(type, source);
}

unsigned int Shader::compile(unsigned int type, std::string &source)
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    GLCall(glShaderSource(id, 1, &src, nullptr));
    GLCall(glCompileShader(id));

    int result;
    GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));

    if (result == GL_TRUE)
    {
        return id;
    }

    return handleCompileError(type, source, id);
}

unsigned int Shader::handleCompileError(unsigned int type, std::string &source, unsigned int id) const
{
    int length;
    GLCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
    char message[length];
    GLCall(glGetShaderInfoLog(id, length, &length, message));

    const std::string shaderTypeAsString = type == GL_VERTEX_SHADER ? "vertex" : "fragment";
    std::cout << "failed to compile " << shaderTypeAsString << " shader" << std::endl;
    std::cout << message << std::endl;
    GLCall(glDeleteShader(rendererId_));

    return -1;
}

std::string Shader::parse(std::string &path)
{
    std::stringstream result;
    std::ifstream file(path);

    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            result << line << '\n';
        }
        file.close();
    } else
        std::cout << "Unable to open file: " << path << std::endl;

    return result.str();
}

unsigned int Shader::getRendererId() const
{
    return rendererId_;
}
