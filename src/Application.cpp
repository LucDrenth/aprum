//
// Created by Luc Drenth on 24/09/2021.
//
#include "engine/logger/Logger.h"
#include "engine/graphics/shader/Shader.h"
#include "engine/graphics/renderer/Renderer.h"
#include "engine/graphics/renderer/IndexBuffer.h"
#include "engine/graphics/renderer/VertexBuffer.h"

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

    float positions[] = {
            -0.5f, -0.5f, // 0
             0.5f, -0.5f, // 1
             0.5f,  0.5f, // 2
            -0.5f,  0.5f, // 3
    };

    unsigned int indices[] = {
            0, 1, 2,
            2, 3, 0
    };

    unsigned int vao;
    GLCall(glGenVertexArrays(1, &vao));
    GLCall(glBindVertexArray(vao));

    VertexBuffer vertexBuffer(positions, 4 * 2 * sizeof(float));

    GLCall(glEnableVertexAttribArray(0));
    GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, nullptr));

    IndexBuffer indexBuffer(indices, 6);

    Shader basicVertexShader(GL_VERTEX_SHADER, "../res/shaders/Basic.vert");
    Shader basicFragmentShader(GL_FRAGMENT_SHADER, "../res/shaders/Basic.frag");

    GLCall(unsigned int program = glCreateProgram());
    GLCall(glAttachShader(program, basicVertexShader.getId()));
    GLCall(glAttachShader(program, basicFragmentShader.getId()));
    GLCall(glLinkProgram(program));
    GLCall(glValidateProgram(program));
    GLCall(glUseProgram(program));

    int uColorLocation = glGetUniformLocation(program, "u_Color");
    if (uColorLocation == -1)
    {
        log.warn("shader uniform u_Color was not found");
    }

    float red = 0.85f;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        GLCall(glClear(GL_COLOR_BUFFER_BIT));

        // render
        glUniform4f(uColorLocation, red, 0.2f, 0.35f, 1.0f);
        GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

        // update
        red += 0.05f;
        if (red > 1.0f) {
            red = 0;
        }

        /* Swap front and back buffers */
        GLCall(glfwSwapBuffers(window));

        /* Poll for and process events */
        GLCall(glfwPollEvents());
    }

    GLCall(glDeleteProgram(program));

    glfwTerminate();
    return 0;
}