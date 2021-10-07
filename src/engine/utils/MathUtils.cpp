//
// Created by Luc Drenth on 07/10/2021.
//

#include "MathUtils.h"

Position rotateAroundPoint(float rotation, float p1, float p2)
{
    float sinus = sin(rotation);
    float coSinus = cos(rotation);

    Position result = {-p1 * coSinus + p2 * sinus, -p1 * sinus - p2 * coSinus};
    return result;
}

glm::mat4 rotateAroundAxisX(glm::mat4 data, float rotation, float x, float y)
{
    Position position = rotateAroundPoint(rotation, x, y);
    return glm::translate(data, glm::vec3(position.p1, position.p2, 0.0f));
}

glm::mat4 rotateAroundAxisY(glm::mat4 data, float rotation, float y, float z)
{
    Position position = rotateAroundPoint(rotation, y, y);
    return glm::translate(data, glm::vec3(0.0f, position.p1, position.p2));
}

glm::mat4 rotateAroundAxisZ(glm::mat4 data, float rotation, float x, float z)
{
    Position position = rotateAroundPoint(rotation, x, z);
    return glm::translate(data, glm::vec3(position.p1, 0.0f, position.p2));
}