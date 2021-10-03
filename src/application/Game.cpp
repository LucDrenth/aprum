//
// Created by Luc Drenth on 30/09/2021.
//

#include "Game.h"
#include "graphics/renderer/Renderer.h"
#include "graphics/renderer/VertexArray.h"
#include "logger/GLErrorHandler.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

Game::Game() : red_(0.01f), redDirection_(1.0f) {}

void Game::init()
{
    float positions[] = {
            -0.5f, -0.5f, 0.15f, 0.7f,  0.75f, 0.0f, 0.0f, // 0 (bottom left)
             0.5f, -0.5f, 0.8f,  0.15f, 0.16f, 1.0f, 0.0f, // 1 (bottom right)
             0.5f,  0.5f, 0.15f, 0.85f, 0.05f, 1.0f, 1.0f, // 2 (top right)
            -0.5f,  0.5f, 0.45f, 0.25f, 0.9f,  0.0f, 1.0f, // 3 (top left)
    };

    unsigned int indices[] = {
            0, 1, 2,
            2, 3, 0
    };

    GLCall(glEnable(GL_BLEND));
    GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

    vertexBuffer_.init(positions, sizeof(positions));
    VertexBufferLayout layout;
    layout.push(GL_FLOAT, 2); // position
    layout.push(GL_FLOAT, 3); // color
    layout.push(GL_FLOAT, 2); // texture coordinate
    vertexArray_.init();
    vertexArray_.addBuffer(vertexBuffer_, layout);
    indexBuffer_.init(indices, 6);

    glm::mat4 projectionMatrix = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
    glm::mat4 viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(-0.5f, -0.5f, 0));
    glm::mat4 modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.2f, 0.2f, 0));
    glm::mat4 mvpMatrix = projectionMatrix * viewMatrix * modelMatrix;

    shaderProgram_.init("../res/shaders/Basic.vert", "../res/shaders/Basic.frag");
    shaderProgram_.use();

    texture_.init("../res/images/wood.jpg");
    texture_.bind(0);

    shaderProgram_.setUniform1i("u_TextureSlot", 0);
    shaderProgram_.setUniformMat4f("u_modelViewProjectionMatrix", mvpMatrix);
}

void Game::update()
{
    // render
//    shaderProgram_.setUniform4f("u_Color", red_, 0.2f, 0.35f, 1.0f);
    Renderer::draw(vertexArray_, indexBuffer_, shaderProgram_);

    // update
    red_ += 0.01f * redDirection_;
    if (red_ >= 1.0f) {
        redDirection_ = -1.0f;
    } else if(red_ <= 0)
        redDirection_ = 1.0f;
}

void Game::destroy()
{
}
