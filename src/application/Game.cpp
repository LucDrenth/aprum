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
            -0.5f, -0.5f, // 0 (bottom left)
             0.5f, -0.5f, // 1 (bottom right)
             0.5f,  0.5f, // 2 (top right)
            -0.5f,  0.5f, // 3 (top left)
    };

    unsigned int indices[] = {
            0, 1, 2,
            2, 3, 0
    };

    vertexBuffer_.init(positions, 4 * 2 * sizeof(float));
    VertexBufferLayout layout;
    layout.push<float>(2);
    vertexArray_.init();
    vertexArray_.addBuffer(vertexBuffer_, layout);
    indexBuffer_.init(indices, 6);

    vertexArray_.unbind();

    shaderProgram_.init("../res/shaders/Basic.vert", "../res/shaders/Basic.frag");
    shaderProgram_.use();

    red_ = 0.85f;
}

void Game::update()
{
    // render
    shaderProgram_.setUniform4f("u_Color", red_, 0.2f, 0.35f, 1.0f);

    vertexArray_.bind();
    indexBuffer_.bind();
    GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

    // update
    red_ += 0.01f;
    if (red_ > 1.0f) {
        red_ = 0;
    }
}

void Game::destroy()
{
}
