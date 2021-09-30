//
// Created by Luc Drenth on 24/09/2021.
//
#include "engine/logger/Logger.h"
#include "engine/graphics/shader/Shader.h"
#include "engine/graphics/renderer/Renderer.h"
#include "engine/graphics/renderer/IndexBuffer.h"
#include "engine/graphics/renderer/VertexBuffer.h"
#include "Game.h"

#define GL_SILENCE_DEPRECATION
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
    Logger log;
    log.setLogLevel(INFO);

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    window = glfwCreateWindow(640, 480, "Hello World", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
    {
        log.error("glew error");
        return -1;
    }

    glfwSwapInterval(1); // does this actually do anything?

    std::cout << glGetString(GL_VERSION) << std::endl;
    if (sizeof(unsigned int) != sizeof(GLuint))
    {
        log.error("sizeof(unsigned int) != sizeof(GLuint)");
        return -1;
    }

    Game game;

    while (!glfwWindowShouldClose(window))
    {
        GLCall(glClear(GL_COLOR_BUFFER_BIT));

        game.update();

        GLCall(glfwSwapBuffers(window));
        GLCall(glfwPollEvents());
    }

    game.destroy();
    glfwTerminate();

    return 0;
}