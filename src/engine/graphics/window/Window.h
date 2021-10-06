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
    int width_;
    int height_;

public:
    Window();

    int init();
    void run(IGame& game);

private:
    void initImgui();

public:
    int getWidth() const;
    void setWidth(int width);
    int getHeight() const;
    void setHeight(int height);
    GLFWwindow* glfw();
};
