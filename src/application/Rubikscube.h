//
// Created by Luc Drenth on 09/10/2021.
//

#pragma once


#include "entity/Entity.h"

enum Turn
{
    L,
    L_PRIME,
    R,
    R_PRIME,
    F,
    F_PRIME,
    B_,
    B_PRIME,
    U,
    U_PRIME,
    D,
    D_PRIME,
};

class Rubikscube
{
public:
    Entity cubes_[3][3][3];

public:
    void init();
    void draw(ShaderProgram& shader);
    void update();
};
