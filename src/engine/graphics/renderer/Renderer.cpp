//
// Created by Luc Drenth on 30/09/2021.
//

#include "Renderer.h"
#include "engine/logger/GLErrorHandler.h"

void Renderer::draw(const VertexArray& vertexArray, const IndexBuffer& indexBuffer, const ShaderProgram& shaderProgram)
{
    shaderProgram.use();
    vertexArray.bind();
    indexBuffer.bind();

    GLCall(glDrawElements(GL_TRIANGLES, indexBuffer.getCount(), GL_UNSIGNED_INT, nullptr));
}
