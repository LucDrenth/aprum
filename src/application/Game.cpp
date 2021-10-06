//
// Created by Luc Drenth on 30/09/2021.
//

#include "Game.h"
#include "graphics/renderer/Renderer.h"
#include "graphics/renderer/VertexArray.h"
#include "logger/GLErrorHandler.h"
#include "graphics/window/Window.h"

#include "glm/gtc/matrix_transform.hpp"

#include "imgui.h"


Game::Game() : modelRotate_(0.0f) {}

void Game::init()
{
    camera_.setWidth(640);
    camera_.setHeight(480);
    camera_.setPosition(glm::vec3(0.0f, 0.0f, 2.0f));

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

    shaderProgram_.init("../res/shaders/Basic.vert", "../res/shaders/Basic.frag");
    shaderProgram_.use();

    texture_.init("../res/images/wood.jpg");
    texture_.bind(0);

    shaderProgram_.setUniform1i("u_TextureSlot", 0);

    glm::mat4 modelMatrix = glm::mat4(1.0f);
    shaderProgram_.setUniformMat4f("u_modelMatrix", modelMatrix);
}

void Game::update()
{
    Renderer::draw(vertexArray_, indexBuffer_, shaderProgram_);

    glm::mat4 modelMatrix = glm::mat4(1.0f);
    modelMatrix = glm::rotate(modelMatrix, glm::radians(modelRotate_), glm::vec3(0.0f, 1.0f, 0.0f));
    shaderProgram_.setUniformMat4f("u_modelMatrix", modelMatrix);
    modelRotate_ += 0.5f;

    camera_.uploadUniform(shaderProgram_, "u_camera");
    camera_.pollInput(*window_);

    // imgui
    {
        ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.
        if (ImGui::Button("move camera left"))
        {
//            camera_.moveX(1.0f);
        }
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::End();
    }
}

void Game::destroy()
{
}

void Game::setWindow(Window* window)
{
    window_ = window;
}
