//
// Created by Luc Drenth on 30/09/2021.
//

#pragma once

#include <GL/Glew.h>

#define GLCall(x)\
GLClearError();  \
x;               \
GLLogError(#x, __FILE__, __LINE__);

void GLClearError();
void GLLogError(const char* function, const char* file, int line);
