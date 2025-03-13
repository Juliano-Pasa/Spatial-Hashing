#include <cassert>

#include "Game.hpp"
#include "GLUtils.hpp"
#include <stdio.h>

namespace spatialhash
{
    #define WINDOW_HEIGHT 600
    #define WINDOW_WIDTH 600

    Game::Game()
    {
    }

    void Game::Start()
    {
        InitializeGLFW();
        InitializeCallbacks();
        InitializeGLAD();
        InitializeGL();

        plane = new Plane(window);
        plane->Initialize();

        MainLoop();
        glfwTerminate();
    }

    void Game::InitializeGLFW()
    {
        assert(glfwInit() && "GLFW was unable to initialize.");

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_FALSE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

        window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Window", NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            assert(false && "Failed to create glfw window.");
        }

        glfwMakeContextCurrent(window);
    }

    void Game::InitializeGLAD()
    {
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            glfwTerminate();
            assert(false && "GLAD was unable to load openGL.");
        }

        GLUtils::checkForOpenGLError(__FILE__, __LINE__);
        GLUtils::dumpGLInfo();
    }

    void Game::InitializeGL()
    {
        glad_glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glad_glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glad_glEnable(GL_PRIMITIVE_RESTART);
    }

    void Game::InitializeCallbacks()
    {
        glfwSetErrorCallback(Game::GLFWErrorCallback);
    }

    void Game::GLFWErrorCallback(int error, const char* description)
    {
        fputs(description, stderr);
    }

    void Game::MainLoop()
    {
        double thisTime;
        double lastTime = glfwGetTime();

        while (!glfwWindowShouldClose(window))
        {
            glfwPollEvents();
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            GLUtils::checkForOpenGLError(__FILE__, __LINE__);

            thisTime = glfwGetTime();
            plane->Update(thisTime - lastTime);
            lastTime = thisTime;

            plane->Render();
            glfwSwapBuffers(window);
        }
    }
}