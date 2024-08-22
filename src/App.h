#pragma once

#include <stdexcept>
#include <GLFW/glfw3.h>

#include "Player.h"
#include "Grid.h"

class App {
public:

    App();

    void Execute();
    void Initialize();
    void Loop();
    void Terminate();

private:

    GLFWwindow* window = NULL;
    const GLFWvidmode* videoMode = NULL;

    const int windowWidth = 640;
    const int windowHeight = 640;

    Player player;
    Grid grid;
};