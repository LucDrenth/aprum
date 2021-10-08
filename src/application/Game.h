//
// Created by Luc Drenth on 30/09/2021.
//

#pragma once

#include "entity/mesh/Mesh.h"
#include "entity/mesh/VertexBuffer.h"
#include "entity/mesh/IndexBuffer.h"
#include "entity/mesh/VertexArray.h"
#include "IGame.h"
#include "graphics/shader/ShaderProgram.h"
#include "graphics/texture/Texture.h"
#include "imgui.h"
#include "graphics/camera/Camera.h"
#include "graphics/window/Window.h"

class Game : public IGame
{
private:
    Mesh pyramid_;

    ShaderProgram shaderProgram_;
    Texture texture_;
    Window* window_;

    Camera camera_;

public:
    Game();
    void init() override;
    void update() override;
    void destroy() override;
    void setWindow(Window* window) override;
};
