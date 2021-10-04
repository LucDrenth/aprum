//
// Created by Luc Drenth on 30/09/2021.
//

#include "Game.h"
#include "graphics/renderer/Renderer.h"
#include "graphics/renderer/VertexArray.h"
#include "logger/GLErrorHandler.h"

#include "glm/gtc/matrix_transform.hpp"

#include "imgui.h"

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

    // imgui test
    showDemoWindow_ = true;
    showAnotherWindow_ = false;
    clearColor_ = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
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

    // imgui tests
    {
        static float f = 0.0f;
        static int counter = 0;

        ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

        ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
        ImGui::Checkbox("Demo Window", &showDemoWindow_);      // Edit bools storing our window open/close state
        ImGui::Checkbox("Another Window", &showAnotherWindow_);

        ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
        ImGui::ColorEdit3("clear color", (float*)&clearColor_); // Edit 3 floats representing a color

        if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
            counter++;
        ImGui::SameLine();
        ImGui::Text("counter = %d", counter);

        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::End();
    }
}

void Game::destroy()
{
}
