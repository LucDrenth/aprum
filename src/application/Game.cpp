//
// Created by Luc Drenth on 30/09/2021.
//

#include "Game.h"
#include "graphics/renderer/Renderer.h"
#include "graphics/renderer/VertexArray.h"
#include "logger/GLErrorHandler.h"

#include "glm/gtc/matrix_transform.hpp"

#include "imgui.h"

Game::Game() : red_(0.01f), redDirection_(1.0f), rotation_(0) {}

void Game::init()
{
    float positions[] = {
            // position             // color
            -0.5f, 0.0f,  0.5f,     0.5f, 0.0f,  0.0f,
            -0.5f, 0.0f, -0.5f,     0.0f,  0.5f, 0.0f,
             0.5f, 0.0f, -0.5f,     0.0f, 0.0f, 0.5f,
             0.5f, 0.0f,  0.5f,     0.5f, 0.5f, 0.0f,
             0.0f, 0.8f,  0.0f,     0.0f, 0.5f,  0.5f,
    };

    unsigned int indices[] = {
            0, 1, 2,
            0, 2, 3,
            0, 1, 4,
            1, 2, 4,
            2, 3, 4,
            3, 0, 4
    };

    GLCall(glEnable(GL_BLEND));
    GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

    vertexBuffer_.init(positions, sizeof(positions));
    VertexBufferLayout layout;
    layout.push(GL_FLOAT, 3); // position
    layout.push(GL_FLOAT, 3); // color
    vertexArray_.init();
    vertexArray_.addBuffer(vertexBuffer_, layout);
    indexBuffer_.init(indices, sizeof(indices) / sizeof(unsigned int));

    glm::mat4 modelMatrix = glm::mat4(1.0f);
    glm::mat4 viewMatrix = glm::mat4(1.0f);
    glm::mat4 projectionMatrix = glm::mat4(1.0f);

    modelMatrix = glm::rotate(modelMatrix, glm::radians(60.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    viewMatrix = glm::translate(viewMatrix, glm::vec3(0.0f, -0.5f, -2.0f));
    projectionMatrix = glm::perspective(glm::radians(45.0f), (float)(640/480), 0.1f, 100.0f);

    shaderProgram_.init("../res/shaders/Basic.vert", "../res/shaders/Basic.frag");
    shaderProgram_.use();

    texture_.init("../res/images/wood.jpg");
    texture_.bind(0);

    shaderProgram_.setUniform1i("u_TextureSlot", 0);
    shaderProgram_.setUniformMat4f("u_modelMatrix", modelMatrix);
    shaderProgram_.setUniformMat4f("u_viewMatrix", viewMatrix);
    shaderProgram_.setUniformMat4f("u_projectionMatrix", projectionMatrix);

    // imgui test
    showDemoWindow_ = true;
    showAnotherWindow_ = false;
    clearColor_ = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
}

void Game::update()
{
    Renderer::draw(vertexArray_, indexBuffer_, shaderProgram_);

    glm::mat4 modelMatrix = glm::mat4(1.0f);
    modelMatrix = glm::rotate(modelMatrix, glm::radians((float)rotation_), glm::vec3(0.0f, 1.0f, 0.0f));
    shaderProgram_.setUniformMat4f("u_modelMatrix", modelMatrix);

    // imgui tests
    {
        static float f = 0.0f;
        static int counter = 0;

        ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.
        ImGui::SliderInt("rotation", &rotation_, 0, 360);            // Edit 1 float using a slider from 0.0f to 1.0f
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::End();
    }
}

void Game::destroy()
{
}
