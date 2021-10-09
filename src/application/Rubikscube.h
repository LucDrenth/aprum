//
// Created by Luc Drenth on 09/10/2021.
//

#pragma once


#include "entity/Entity.h"

class Rubikscube
{
private:
    Entity cubes[3][3][3];

public:
    void init();
};
