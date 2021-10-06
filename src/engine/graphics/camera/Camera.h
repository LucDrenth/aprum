//
// Created by Luc Drenth on 05/10/2021.
//

#pragma once

#include "glm/glm.hpp"
#include "graphics/window/Window.h"
#include "graphics/shader/ShaderProgram.h"
#include "GLFW/glfw3.h"

class Camera
{
private:
    glm::vec3 position_;
    glm::vec3 orientation_;
    glm::vec3 upDirection_;

    int width_;
    int height_;

    float speed_;
    float sensitivity_;

    bool mouseCaptured_;
    float mouseCapturedX_;
    float mouseCapturedY_;

public:
    Camera();

    void pollInput(Window& window);
    void pollKeyboardInput(Window& window);
    void pollMouseInput(Window& window);

    void uploadUniform(ShaderProgram& shaderProgram, const std::string& uniform);

    const glm::vec3 &getPosition() const;
    void setPosition(const glm::vec3 &position);
    const glm::vec3 &getOrientation() const;
    void setOrientation(const glm::vec3 &orientation);
    const glm::vec3 &getUpDirection() const;
    void setUpDirection(const glm::vec3 &upDirection);
    int getWidth() const;
    void setWidth(int width);
    int getHeight() const;
    void setHeight(int height);
    float getSpeed() const;
    void setSpeed(float speed);
    float getSensitivity() const;
    void setSensitivity(float sensitivity);
};
