//
// Created by Luc Drenth on 08/10/2021.
//

#pragma once


#include "entity/mesh/Mesh.h"
#include "graphics/shader/ShaderProgram.h"

class Entity
{
private:
    Mesh mesh_;

public:
    glm::vec3 position_;
    glm::vec3 rotation_;

    glm::vec3 velocity_;
    glm::vec3 rotationVelocity_;

    bool rotateAroundPoint_;
    glm::vec3 pointToRotateAround_;
    glm::vec3 rotationAroundPoint_;
    glm::vec3 rotationAroundPointVelocity_;

public:
    Entity();

    void init(Mesh& mesh);
    void draw(ShaderProgram& shader);
    void update();
};
