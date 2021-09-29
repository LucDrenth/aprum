//
// Created by Luc Drenth on 24/09/2021.
//
#include "logger/Logger.h"
#include "shader/Shader.h"

#define GL_SILENCE_DEPRECATION
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#define GLCall(x)\
GLClearError();  \
x;               \
GLLogError(#x, __FILE__, __LINE__);

static void GLClearError()
{
    while (glGetError() != GL_NO_ERROR)
    {
    }
}

static void GLLogError(const char* function, const char* file, int line)
{
    while (GLenum errorCode = glGetError())
    {
        std::cout << "[OpenGL Error]: " << gluErrorString(errorCode) << " - " << file << ":" << line << " - " <<
        function << std::endl;
    }
}

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

    unsigned int VBO, VAO;
    GLCall(glGenBuffers(1, &VBO));
    GLCall(glGenVertexArrays(1, &VAO));
    GLCall(glBindVertexArray(VAO));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, VBO));
    GLCall(glBufferData(GL_ARRAY_BUFFER, 4 * 2 * sizeof(float), positions, GL_STATIC_DRAW));

    GLCall(glEnableVertexAttribArray(0));
    GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, nullptr));

    unsigned int ibo;
    GLCall(glGenBuffers(1, &ibo));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW));

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