//
// Created by Luc Drenth on 01/10/2021.
//

#pragma once

#define GLCall(x)\
GLClearError();  \
x;               \
GLLogError(#x, __FILE__, __LINE__);

void GLClearError();
void GLLogError(const char* function, const char* file, int line);