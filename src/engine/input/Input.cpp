//
// Created by Luc Drenth on 07/10/2021.
//

#include "Input.h"
#include <iostream>

Input* Input::instance_ = nullptr;

Input::Input() : mouseMovedX_(0.0f), mouseMovedY_(0.0f), mouseX_(0.0f), mouseY_(0.0f)
{

}

void Input::endFrame()
{
    mouseMovedX_ = 0.0f;
    mouseMovedY_ = 0.0f;
}

float Input::getMouseX() const
{
    return mouseX_;
}

void Input::setMouseX(float mouseX)
{
    mouseX_ = mouseX;
}

float Input::getMouseY() const
{
    return mouseY_;
}

void Input::setMouseY(float mouseY)
{
    mouseY_ = mouseY;
}

float Input::getMouseMovedX() const
{
    return mouseMovedX_;
}

void Input::setMouseMovedX(float mouseMovedX)
{
    mouseMovedX_ = mouseMovedX;
}

float Input::getMouseMovedY() const
{
    return mouseMovedY_;
}

void Input::setMouseMovedY(float mouseMovedY)
{
    mouseMovedY_ = mouseMovedY;
}

void registerInputCallbacks(GLFWwindow* window)
{
    glfwSetCursorPosCallback(window, onMouseMove);
}

void onMouseMove(GLFWwindow* window, double xpos, double ypos)
{
    Input* input = Input::get();
    input->setMouseMovedX(xpos - input->getMouseX());
    input->setMouseMovedY(ypos - input->getMouseY());
    input->setMouseX(xpos);
    input->setMouseY(ypos);
}