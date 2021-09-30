//
// Created by Luc Drenth on 30/09/2021.
//

#pragma once

#include "engine/graphics/renderer/VertexBuffer.h"
#include "engine/graphics/renderer/IndexBuffer.h"
#include "engine/IGame.h"

class Game : public IGame
{
private:
    VertexBuffer vertexBuffer_;
    IndexBuffer indexBuffer_;

    unsigned int program_;
    int uColorLocation_;
    float red_;

public:
    Game();
    void init() override;
    void update() override;
    void destroy() override;
};
