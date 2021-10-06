//
// Created by Luc Drenth on 30/09/2021.
//

#pragma once

#include "engine/graphics/renderer/VertexBuffer.h"
#include "engine/graphics/renderer/IndexBuffer.h"
#include "engine/graphics/renderer/VertexArray.h"
#include "engine/IGame.h"
#include "engine/graphics/shader/ShaderProgram.h"
#include "engine/graphics/texture/Texture.h"
#include "imgui.h"
#include "graphics/camera/Camera.h"
#include "graphics/window/Window.h"

class Game : public IGame
{
private:
    VertexArray vertexArray_;
    VertexBuffer vertexBuffer_;
    IndexBuffer indexBuffer_;
    ShaderProgram shaderProgram_;
    Texture texture_;
    Window* window_;

    Camera camera_;

    float modelRotate_;

public:
    Game();
    void init() override;
    void update() override;
    void destroy() override;
    void setWindow(Window* window) override;
};
