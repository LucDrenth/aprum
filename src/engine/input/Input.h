//
// Created by Luc Drenth on 07/10/2021.
//

/**
 * Singleton
 */

#pragma once


#include <GLFW/glfw3.h>

class Input
{
private:
    static Input* instance_;
public:
    static Input* get()
    {
        if (instance_ == nullptr)
        {
            instance_ = new Input();
        }
        return instance_;
    }

private:
    Input();

    float mouseX_;
    float mouseY_;
    float mouseMovedX_;
    float mouseMovedY_;

public:
    void endFrame();

    float getMouseX() const;

    void setMouseX(float mouseX);

    float getMouseY() const;

    void setMouseY(float mouseY);

    float getMouseMovedX() const;

    void setMouseMovedX(float mouseMovedX);

    float getMouseMovedY() const;

    void setMouseMovedY(float mouseMovedY);
};

void registerInputCallbacks(GLFWwindow* window);
void onMouseMove(GLFWwindow* window, double xpos, double ypos);
