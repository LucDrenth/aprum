//
// Created by Luc Drenth on 30/09/2021.
//

#pragma once

#include "engine/IGame.h"

#include <GLFW/glfw3.h>

class Window
{
private:
    GLFWwindow* window_;

public:
    Window();
    int init();
    void run(IGame& game);

private:
    void initImgui();
};
