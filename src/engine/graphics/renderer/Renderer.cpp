//
// Created by Luc Drenth on 30/09/2021.
//

#include "Renderer.h"
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

void Renderer::draw(const VertexArray& vertexArray, const IndexBuffer& indexBuffer, const ShaderProgram& shaderProgram)
{
    shaderProgram.use();
    vertexArray.bind();
    indexBuffer.bind();

    GLCall(glDrawElements(GL_TRIANGLES, indexBuffer.getCount(), GL_UNSIGNED_INT, nullptr));
}
