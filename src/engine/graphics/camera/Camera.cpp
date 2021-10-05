//
// Created by Luc Drenth on 05/10/2021.
//

#include "Camera.h"

Camera::Camera()
{

}

void Camera::moveX(float x)
{
    xPos_ += x;
}

void Camera::moveY(float y)
{
    yPos_ += y;
}

void Camera::moveZ(float z)
{
    zPos_ += z;
}

void Camera::rotateX(float x)
{
    rotateX_ += x;
}

void Camera::rotateY(float y)
{
    rotateY_ += y;
}

void Camera::rotateZ(float z)
{
    rotateZ_ += z;
}

float Camera::getXPos() const
{
    return xPos_;
}

void Camera::setXPos(float xPos)
{
    xPos_ = xPos;
}

float Camera::getYPos() const
{
    return yPos_;
}

void Camera::setYPos(float yPos)
{
    yPos_ = yPos;
}

float Camera::getZPos() const
{
    return zPos_;
}

void Camera::setZPos(float zPos)
{
    zPos_ = zPos;
}

float Camera::getRotateX() const
{
    return rotateX_;
}

void Camera::setRotateX(float rotateX)
{
    rotateX_ = rotateX;
}

float Camera::getRotateY() const
{
    return rotateY_;
}

void Camera::setRotateY(float rotateY)
{
    rotateY_ = rotateY;
}

float Camera::getRotateZ() const
{
    return rotateZ_;
}

void Camera::setRotateZ(float rotateZ)
{
    rotateZ_ = rotateZ;
}
