//
// Created by Luc Drenth on 05/10/2021.
//

#pragma once


class Camera
{
private:
    float xPos_;
    float yPos_;
    float zPos_;
    float rotateX_;
    float rotateY_;
    float rotateZ_;

public:
    Camera();

    void moveX(float x);
    void moveY(float y);
    void moveZ(float z);

    void rotateX(float x);
    void rotateY(float y);
    void rotateZ(float z);

    float getXPos() const;
    void setXPos(float xPos);
    float getYPos() const;
    void setYPos(float yPos);
    float getZPos() const;
    void setZPos(float zPos);
    float getRotateX() const;
    void setRotateX(float rotateX);
    float getRotateY() const;
    void setRotateY(float rotateY);
    float getRotateZ() const;
    void setRotateZ(float rotateZ);
};
