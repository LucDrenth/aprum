//
// Created by Luc Drenth on 30/09/2021.
//

#include "Renderer.h"
#include "engine/logger/GLErrorHandler.h"

#include "glm/gtc/matrix_transform.hpp"

void Renderer::draw(const VertexArray& vertexArray, const IndexBuffer& indexBuffer, const ShaderProgram& shaderProgram)
{
    shaderProgram.use();
    vertexArray.bind();
    indexBuffer.bind();

    GLCall(glDrawElements(GL_TRIANGLES, indexBuffer.getCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::draw(const Mesh& mesh, ShaderProgram& shaderProgram, glm::vec3& position, glm::vec3& rotation)
{
    mesh.getVertexArray().bind();
    draw(mesh.getVertexArray(), mesh.getIndexBuffer(), shaderProgram);

    glm::mat4 modelMatrix = glm::mat4(1.0f);

    // position
    modelMatrix = glm::translate(modelMatrix, position);

    // rotation
    modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

    shaderProgram.setUniformMat4f("u_modelMatrix", modelMatrix);
}