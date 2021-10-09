//
// Created by Luc Drenth on 08/10/2021.
//

#include "utils/MathUtils.h"
#include "graphics/renderer/Renderer.h"
#include "Entity.h"

Entity::Entity() : velocity_(0.0f),
    rotationVelocity_(0.0f),
    position_(glm::vec3(0.0f)),
    rotation_(glm::vec3(0.0f)),
    rotateAroundPoint_(false),
    pointToRotateAround_(glm::vec3(0.0f)),
    rotationAroundPoint_(glm::vec3(0.0f)),
    rotationAroundPointVelocity_(glm::vec3(0.0f)) {}

void Entity::init(Mesh& mesh)
{
    mesh_ = mesh;
}

void Entity::draw(ShaderProgram& shader)
{
    if (!rotateAroundPoint_)
    {
        Renderer::draw(mesh_, shader, position_, rotation_);
        return;
    }

    glm::vec3 posAfterRotation = rotateAroundAxisX(
            position_, rotationAroundPoint_.x, pointToRotateAround_.x, pointToRotateAround_.y);

    posAfterRotation = rotateAroundAxisY(
            posAfterRotation, rotationAroundPoint_.y, pointToRotateAround_.y, pointToRotateAround_.z);

    posAfterRotation = rotateAroundAxisZ(
            posAfterRotation, rotationAroundPoint_.z, pointToRotateAround_.x, pointToRotateAround_.z);

    Renderer::draw(mesh_, shader, posAfterRotation, rotation_);
}

void Entity::update()
{
    position_ += velocity_;
    rotation_ += rotationVelocity_;
    rotationAroundPoint_ += rotationAroundPointVelocity_;
}
