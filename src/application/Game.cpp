//
// Created by Luc Drenth on 30/09/2021.
//

#include "Game.h"
#include "engine/graphics/renderer/Renderer.h"
#include "engine/graphics/renderer/VertexArray.h"

Game::Game()
{
}

void Game::init()
{
    float positions[] = {
            -0.5f, -0.5f, 0.15f, 0.7f,  0.75f, // 0 (bottom left)
             0.5f, -0.5f, 0.8f,  0.15f, 0.16f, // 1 (bottom right)
             0.5f,  0.5f, 0.15f, 0.85f, 0.05f, // 2 (top right)
            -0.5f,  0.5f, 0.45f, 0.25f, 0.9f,  // 3 (top left)
    };

    unsigned int indices[] = {
            0, 1, 2,
            2, 3, 0
    };

    vertexBuffer_.init(positions, sizeof(positions));
    VertexBufferLayout layout;
    layout.push(GL_FLOAT, 2);
    layout.push(GL_FLOAT, 3);
    vertexArray_.init();
    vertexArray_.addBuffer(vertexBuffer_, layout);
    indexBuffer_.init(indices, 6);

    shaderProgram_.init("../res/shaders/Basic.vert", "../res/shaders/Basic.frag");
    shaderProgram_.use();

    red_ = 0.01f;
    redDirection_ = 1.0f;
}

void Game::update()
{
    // render
    shaderProgram_.setUniform4f("u_Color", red_, 0.2f, 0.35f, 1.0f);
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
