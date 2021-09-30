//
// Created by Luc Drenth on 30/09/2021.
//

#include "Game.h"
#include "engine/graphics/renderer/Renderer.h"
#include "engine/graphics/renderer/VertexBuffer.h"
#include "engine/graphics/renderer/IndexBuffer.h"
#include "engine/graphics/shader/Shader.h"

#include <GL/glew.h>

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

    unsigned int vao;
    GLCall(glGenVertexArrays(1, &vao));
    GLCall(glBindVertexArray(vao));

    vertexBuffer_.init(positions, 4 * 2 * sizeof(float));

    GLCall(glEnableVertexAttribArray(0));
    GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, nullptr));

    indexBuffer_.init(indices, 6);

    Shader basicVertexShader(GL_VERTEX_SHADER, "../res/shaders/Basic.vert");
    Shader basicFragmentShader(GL_FRAGMENT_SHADER, "../res/shaders/Basic.frag");

    GLCall(program_ = glCreateProgram());
    GLCall(glAttachShader(program_, basicVertexShader.getId()));
    GLCall(glAttachShader(program_, basicFragmentShader.getId()));
    GLCall(glLinkProgram(program_));
    GLCall(glValidateProgram(program_));
    GLCall(glUseProgram(program_));

    uColorLocation_ = glGetUniformLocation(program_, "u_Color");
    if (uColorLocation_ == -1)
    {
        std::cout << "shader uniform uColorLocation_ was not found" << std::endl;
    }

    red_ = 0.85f;
}

void Game::update()
{
    // render
    glUniform4f(uColorLocation_, red_, 0.2f, 0.35f, 1.0f);
    GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

    // update
    red_ += 0.01f;
    if (red_ > 1.0f) {
        red_ = 0;
    }
}

void Game::destroy()
{
    GLCall(glDeleteProgram(program_));
}
