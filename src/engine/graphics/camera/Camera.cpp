//
// Created by Luc Drenth on 05/10/2021.
//

#include "Camera.h"

#include <glm/glm.hpp>
#include <glm/gtx/vector_angle.hpp>

Camera::Camera() :
        position_(),
        orientation_(glm::vec3(0.0f, 0.0f, -1.0f)),
        upDirection_(glm::vec3(0.0f, 1.0f, 0.0f)),
        speed_(0.1f),
        sensitivity_(100.0f),
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

// TODO finish this
void Camera::pollMouseInput(Window &window)
{
    if (glfwGetMouseButton(window.glfw(), GLFW_MOUSE_BUTTON_2) == GLFW_PRESS)
    {
        // get cursor position
        double mouseX;
        double mouseY;
        glfwGetCursorPos(window.glfw(), &mouseX, &mouseY);

        // capture mouse position
        if (!mouseCaptured_)
        {
            mouseCaptured_ = true;
            mouseCapturedX_ = (float)mouseX;
            mouseCapturedY_ = (float)mouseY;

            std::cout << "capture at x: " << mouseCapturedX_ << ", y: " << mouseCapturedY_ << std::endl;
            return;
        }

        float mouseMovedX = (float)mouseX - mouseCapturedX_;
        float mouseMovedY = (float)mouseY - mouseCapturedY_;
        std::cout << mouseMovedX << " / " << mouseMovedY << std::endl;

        glfwSetCursorPos(window.glfw(), mouseCapturedX_, mouseCapturedY_);

    }
    if (glfwGetMouseButton(window.glfw(), GLFW_MOUSE_BUTTON_2) == GLFW_RELEASE)
    {
        mouseCaptured_ = false;
    }

//    // Handles mouse inputs
//    if (glfwGetMouseButton(window.glfw(), GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
//    {
//        // Hides mouse cursor
//        glfwSetInputMode(window.glfw(), GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
//
//        // Prevents camera from jumping on the first click
//        if (firstClick_)
//        {
//            glfwSetCursorPos(window.glfw(), (window.getWidth() / 2), (window.getHeight() / 2));
//            firstClick_ = false;
//        }
//
//        // Stores the coordinates of the cursor
//        double mouseX;
//        double mouseY;
//        // Fetches the coordinates of the cursor
//        glfwGetCursorPos(window.glfw(), &mouseX, &mouseY);
//
//        // Normalizes and shifts the coordinates of the cursor such that they begin in the middle of the screen
//        // and then "transforms" them into degrees
//        float rotX = sensitivity_ * (float)(mouseY - (window.getHeight() / 2)) / window.getHeight();
//        float rotY = sensitivity_ * (float)(mouseX - (window.getWidth() / 2)) / window.getWidth();
//
//        std::cout << mouseX << " / " << mouseY << std::endl;
//
//        // Calculates upcoming vertical change in the Orientation
//        glm::vec3 newOrientation = glm::rotate(orientation_, glm::radians(-rotX), glm::normalize(glm::cross(orientation_, upDirection_)));
//
//        // Decides whether or not the next vertical Orientation is legal or not
//        if (abs(glm::angle(newOrientation, upDirection_) - glm::radians(90.0f)) <= glm::radians(85.0f))
//        {
//            orientation_ = newOrientation;
//        }
//
//        // Rotates the Orientation left and right
//        orientation_ = glm::rotate(orientation_, glm::radians(-rotY), upDirection_);
//
//        // Sets mouse cursor to the middle of the screen so that it doesn't end up roaming around
//        glfwSetCursorPos(window.glfw(), (window.getWidth() / 2), (window.getHeight() / 2));
//    }
//    else if (glfwGetMouseButton(window.glfw(), GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
//    {
//        // Unhides cursor since camera is not looking around anymore
//        glfwSetInputMode(window.glfw(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
//        // Makes sure the next time the camera looks around it doesn't jump
//        firstClick_ = true;
//    }
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

