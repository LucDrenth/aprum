//
// Created by Luc Drenth on 30/09/2021.
//

#include <GL/glew.h>
#include "engine/logger/GLErrorHandler.h"
#include "Window.h"

#include <GLFW/glfw3.h>

#include <iostream>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

Window::Window()
{
}

/**
 * inits window. inits game. Runs program untill window is closed.
 * @param game
 */
void Window::run(IGame& game)
{
    if (init() == -1)
    {
        std::cout << "ERROR: Window init failed" << std::endl;
        return;
    }

    game.init();

    while (!glfwWindowShouldClose(window_))
    {
        // clear window
        GLCall(glClear(GL_COLOR_BUFFER_BIT));

        // start imgui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // update game
        game.update();

        // draw imgui frame
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // swap buffers
        GLCall(glfwSwapBuffers(window_));

        // poll events
        GLCall(glfwPollEvents());
    }

    // cleanup imgui
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    // clean up game
    game.destroy();

    // cleanup glfw
    glfwTerminate();
}

int Window::init()
{
    if (!glfwInit())
    {
        std::cout << "ERROR: glfwInit failed" << std::endl;
        return -1;
    }

    /* Create a windowed mode window and its OpenGL context */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    window_ = glfwCreateWindow(640, 480, "Aprum engine", nullptr, nullptr);
    if (!window_)
    {
        glfwTerminate();
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window_);

    if (glewInit() != GLEW_OK)
    {
        std::cout << "ERROR: glew error" << std::endl;
        return -1;
    }

    std::cout << glGetString(GL_VERSION) << std::endl;

    initImgui();

    return 0;
}

void Window::initImgui()
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window_, true);
    ImGui_ImplOpenGL3_Init((char *)glGetString(GL_NUM_SHADING_LANGUAGE_VERSIONS));
}
