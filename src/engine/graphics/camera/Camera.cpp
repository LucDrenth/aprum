//
// Created by Luc Drenth on 05/10/2021.
//

#include "Camera.h"

#include <glm/glm.hpp>
#include <glm/gtx/vector_angle.hpp>
#include "input/Input.h"

Camera::Camera() :
        position_(),
        orientation_(glm::vec3(0.0f, 0.0f, -1.0f)),
        upDirection_(glm::vec3(0.0f, 1.0f, 0.0f)),
        speed_(0.1f),
        sensitivity_(1.0f),
        width_(100),
        height_(100)
{

}

void Camera::pollInput(Window& window)
{
    pollKeyboardInput(window);
    pollMouseInput(window);
}

void Camera::pollKeyboardInput(Window &window)
{
    if (glfwGetKey(window.glfw(), GLFW_KEY_W) == GLFW_PRESS)
    {
        position_ += speed_ * orientation_;
    }
    if (glfwGetKey(window.glfw(), GLFW_KEY_A) == GLFW_PRESS)
    {
        position_ += speed_ * -glm::normalize(glm::cross(orientation_, upDirection_));
    }
    if (glfwGetKey(window.glfw(), GLFW_KEY_S) == GLFW_PRESS)
    {
        position_ += speed_ * -orientation_;
    }
    if (glfwGetKey(window.glfw(), GLFW_KEY_D) == GLFW_PRESS)
    {
        position_ += speed_ * glm::normalize(glm::cross(orientation_, upDirection_));
    }
    if (glfwGetKey(window.glfw(), GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
    {
        position_ += speed_ * upDirection_;
    }
    if (glfwGetKey(window.glfw(), GLFW_KEY_LEFT_ALT) == GLFW_PRESS)
    {
        position_ += speed_ * -upDirection_;
    }
}

void Camera::pollMouseInput(Window &window)
{
    int mouseButtonForCapturing = GLFW_MOUSE_BUTTON_2;

    if (glfwGetMouseButton(window.glfw(), mouseButtonForCapturing) == GLFW_PRESS)
    {
        glfwSetInputMode(window.glfw(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

        // get the rotation
        float rotationX = Input::get()->getMouseMovedX() * sensitivity_;
        float rotationY = Input::get()->getMouseMovedY() * sensitivity_;

        if (rotationY != 0.0f)
        {
            orientation_ = glm::rotate(orientation_, glm::radians(-rotationY), glm::normalize(glm::cross(orientation_, upDirection_)));;
        }

        if (rotationX != 0.0f)
        {
            orientation_ = glm::rotate(orientation_, glm::radians(-rotationX), upDirection_);
        }
    }
    else if (glfwGetMouseButton(window.glfw(), mouseButtonForCapturing) == GLFW_RELEASE)
    {
        glfwSetInputMode(window.glfw(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }
}

void Camera::uploadUniform(ShaderProgram& shaderProgram, const std::string& uniform)
{
    float fieldOfView = 70.0f;
    float nearPlane = 1.0f;
    float farPlane = 100.0f;

    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);

    view = glm::lookAt(position_, position_ + orientation_, upDirection_);
    projection = glm::perspective(glm::radians(fieldOfView), (float)(width_ / height_), nearPlane, farPlane);

    glm::mat4 result = projection * view;
    shaderProgram.setUniformMat4f(uniform, result);
}

const glm::vec3 &Camera::getPosition() const
{
    return position_;
}

void Camera::setPosition(const glm::vec3 &position)
{
    position_ = position;
}

const glm::vec3 &Camera::getOrientation() const
{
    return orientation_;
}

void Camera::setOrientation(const glm::vec3 &orientation)
{
    orientation_ = orientation;
}

const glm::vec3 &Camera::getUpDirection() const
{
    return upDirection_;
}

void Camera::setUpDirection(const glm::vec3 &upDirection)
{
    upDirection_ = upDirection;
}

int Camera::getWidth() const
{
    return width_;
}

void Camera::setWidth(int width)
{
    width_ = width;
}

int Camera::getHeight() const
{
    return height_;
}

void Camera::setHeight(int height)
{
    height_ = height;
}

float Camera::getSpeed() const
{
    return speed_;
}

void Camera::setSpeed(float speed)
{
    speed_ = speed;
}

float Camera::getSensitivity() const
{
    return sensitivity_;
}

void Camera::setSensitivity(float sensitivity)
{
    sensitivity_ = sensitivity;
}

