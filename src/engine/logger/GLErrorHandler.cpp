//
// Created by Luc Drenth on 01/10/2021.
//
#include "GLErrorHandler.h"

#include <GL/glew.h>
#include <iostream>

void GLClearError()
{
    while (glGetError() != GL_NO_ERROR)
    {
    }
}

void GLLogError(const char* function, const char* file, int line)
{
    while (GLenum errorCode = glGetError())
    {
        std::cout << "[OpenGL Error]: " << gluErrorString(errorCode) << " - " << file << ":" << line << " - " <<
                  function << std::endl;
    }
}