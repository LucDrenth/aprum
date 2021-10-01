//
// Created by Luc Drenth on 30/09/2021.
//

#pragma once

#include "engine/graphics/renderer/VertexBuffer.h"
#include "engine/graphics/renderer/IndexBuffer.h"
#include "engine/graphics/renderer/VertexArray.h"
#include "engine/IGame.h"
#include "engine/graphics/shader/ShaderProgram.h"

class Game : public IGame
{
private:
    VertexArray vertexArray_;
    VertexBuffer vertexBuffer_;
    IndexBuffer indexBuffer_;
    ShaderProgram shaderProgram_;

    float red_;
    float redDirection_;

public:
    Game();
    void init() override;
    void update() override;
    void destroy() override;
};
