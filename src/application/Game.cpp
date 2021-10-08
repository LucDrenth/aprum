//
// Created by Luc Drenth on 30/09/2021.
//

#include "Game.h"
#include "graphics/renderer/Renderer.h"
#include "entity/mesh/VertexArray.h"
#include "graphics/window/Window.h"

#include "imgui.h"


Game::Game(){}

void Game::init()
{
    camera_.setWidth(640);
    camera_.setHeight(480);
    camera_.setPosition(glm::vec3(0.0f, 0.0f, 2.0f));

    float positions[] = {
            // position             // color
            -0.5f, 0.0f,  0.5f,     0.5f, 0.0f, 0.0f,
            -0.5f, 0.0f, -0.5f,     0.0f, 0.5f, 0.0f,
             0.5f, 0.0f, -0.5f,     0.0f, 0.0f, 0.5f,
             0.5f, 0.0f,  0.5f,     0.5f, 0.5f, 0.0f,
             0.0f, 0.8f,  0.0f,     0.0f, 0.5f, 0.5f,
    };

    unsigned int indices[] = {
            0, 1, 2,
            0, 2, 3,
            0, 1, 4,
            1, 2, 4,
            2, 3, 4,
            3, 0, 4
    };

    VertexBufferLayout layout;
    layout.push(GL_FLOAT, 3); // position
    layout.push(GL_FLOAT, 3); // color

    pyramid_.init(positions, sizeof(positions), layout, indices, sizeof(indices) / sizeof(unsigned int));

    entity1_.init(pyramid_);
    entity1_.velocity_.x = 0.01f;
    entity1_.rotationVelocity_.x = 1.0f;

    entity2_.init(pyramid_);
    entity2_.velocity_.y = 0.01f;
    entity2_.rotationVelocity_.y = 1.0f;

    entity3_.init(pyramid_);
    entity3_.velocity_.z = 0.01f;
    entity3_.rotationVelocity_.z = 1.0f;

    shaderProgram_.init("../res/shaders/Basic.vert", "../res/shaders/Basic.frag");
    shaderProgram_.use();

    texture_.init("../res/images/wood.jpg");
    texture_.bind(0);

    shaderProgram_.setUniform1i("u_TextureSlot", 0);
}

void Game::update()
{
    entity1_.draw(shaderProgram_);
    entity2_.draw(shaderProgram_);
    entity3_.draw(shaderProgram_);

    entity1_.update();
    entity2_.update();
    entity3_.update();

    camera_.uploadUniform(shaderProgram_, "u_camera");
    camera_.pollInput(*window_);

    {
        ImGui::Begin("Hello, world!");
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
                    1000.0f / ImGui::GetIO().Framerate,
                    ImGui::GetIO().Framerate);
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
