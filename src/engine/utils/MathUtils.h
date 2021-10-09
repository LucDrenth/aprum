//
// Created by Luc Drenth on 07/10/2021.
//

#pragma once

#include "glm/gtc/matrix_transform.hpp"

struct Position
{
    float p1;
    float p2;
};

Position rotateAroundPoint(float rotation, float p1, float p2);
glm::mat4 rotateAroundAxisX(glm::mat4 data, float rotation, float x, float y);
glm::mat4 rotateAroundAxisY(glm::mat4 data, float rotation, float y, float z);
glm::mat4 rotateAroundAxisZ(glm::mat4 data, float rotation, float x, float z);

glm::vec3 rotateAroundAxisX(glm::vec3 position, float rotation, float x, float y);
glm::vec3 rotateAroundAxisY(glm::vec3 position, float rotation, float y, float z);
glm::vec3 rotateAroundAxisZ(glm::vec3 position, float rotation, float x, float z);