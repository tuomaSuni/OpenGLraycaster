#pragma once

#include <stdexcept>
#include <GLFW/glfw3.h>
#include <memory>

#include "Player.h"
#include "Grid.h"
#include "Rays.h"

class App {
public:
    App();
    void Execute();
    void Terminate();
private:
    void Initialize();
    void InitializeGLFW();
    void CreateWindow();
    void SetOpenGLSettings();
    void SetCallbacks();
    static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    void KeyCallbackImpl(int key, int action);
    static void MouseCallback(GLFWwindow* window, double xpos, double ypos);
    void MouseCallbackImpl(double xpos, double ypos);
    void Loop();
    void ProcessFrame();
    void Render();

    std::unique_ptr<GLFWwindow, decltype(&glfwDestroyWindow)> window;
    const GLFWvidmode* videoMode = nullptr;

    int windowWidth = 640;
    int windowHeight = 640;

    float lastFrameTime = 0.0f;
    float deltaTime;

    Player player;
    Grid grid;
    Rays rays;
};
