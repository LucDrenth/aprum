//
// Created by Luc Drenth on 09/10/2021.
//

#include "Rubikscube.h"

void Rubikscube::init()
{
    static Mesh cubeMesh;
    cubeMesh.init(Shape::CUBE);

    float spaceBetweenCubes = 2.0f;

    for (int z = 0; z <= 2; z++)
    {
        for (int y = 0; y <= 2; y++)
        {
            for (int x = 0; x <= 2; x++)
            {
                cubes_[x][y][z].init(cubeMesh);
                cubes_[x][y][z].position_ = glm::vec3(
                        (float)x * spaceBetweenCubes,
                        (float)y * spaceBetweenCubes,
                        (float)z * spaceBetweenCubes);

                if (x == 0)
                {
                    cubes_[x][y][z].rotateAroundPoint_ = true;
                    cubes_[x][y][z].pointToRotateAround_ = glm::vec3(0.5f, 0.5f, 0.5f);
                    cubes_[x][y][z].rotationAroundPointVelocity_ = glm::vec3(0.0f, 0.03f, 0.0f);
                }
            }
        }
    }
}

void Rubikscube::draw(ShaderProgram& shader)
{
    for (int z = 0; z <= 2; z++)
    {
        for (int y = 0; y <= 2; y++)
        {
            for (int x = 0; x <= 2; x++)
            {
                cubes_[x][y][z].draw(shader);
            }
        }
    }
}

void Rubikscube::update()
{
    for (int z = 0; z <= 2; z++)
    {
        for (int y = 0; y <= 2; y++)
        {
            for (int x = 0; x <= 2; x++)
            {
                cubes_[x][y][z].update();
            }
        }
    }
}
