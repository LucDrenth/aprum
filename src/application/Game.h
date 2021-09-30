//
// Created by Luc Drenth on 30/09/2021.
//

#pragma once

class Game
{
private:
    unsigned int program_;
    int uColorLocation_;
    float red_;

public:
    Game();
    void update();
    void destroy() const;
};
