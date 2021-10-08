//
// Created by Luc Drenth on 08/10/2021.
//

#include "graphics/renderer/Renderer.h"
#include "Entity.h"

Entity::Entity() : velocity_(0.0f),
    rotationVelocity_(0.0f),
    position_(glm::vec3(0.0f)),
    rotation_(glm::vec3(0.0f)) {}

void Entity::init(Mesh& mesh)
{
    mesh_ = mesh;
}

void Entity::draw(ShaderProgram& shader)
{
    Renderer::draw(mesh_, shader, position_, rotation_);
}

void Entity::update()
{
    position_ += velocity_;
    rotation_ += rotationVelocity_;
}
