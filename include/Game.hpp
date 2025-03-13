#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "glad.h"
#include "glm/glm.hpp"

#include <GLFW/glfw3.h>

#include "Plane.hpp"

namespace spatialhash
{
    using namespace std;

    class Game
    {
    public:
        Game();
        void Start();

    private:
        void InitializeGLFW();
        void InitializeGLAD();
        void InitializeGL();
        void InitializeCallbacks();

        static void GLFWErrorCallback(int error, const char* description);

        void MainLoop();

        GLFWwindow* window;
        Plane* plane;
    };
}

#endif // __GAME_HPP__