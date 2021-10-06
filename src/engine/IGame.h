//
// Created by Luc Drenth on 30/09/2021.
//

#pragma once

class Window;

class IGame
{
public:
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void destroy() = 0;
    virtual void setWindow(Window* window) = 0;
};
