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
