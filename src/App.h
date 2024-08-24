// App.h

#pragma once

#include <stdexcept>
#include <GLFW/glfw3.h>
#include <memory>
#include <iostream> // for std::cerr

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
    static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods); // Static callback
    void KeyCallbackImpl(int key, int action); // Non-static method
    static void MouseCallback(GLFWwindow* window, double xpos, double ypos); // Static callback
    void MouseCallbackImpl(double xpos, double ypos); // Non-static method
    void Loop();
    

    std::unique_ptr<GLFWwindow, decltype(&glfwDestroyWindow)> window;
    const GLFWvidmode* videoMode = nullptr;
    
    int windowWidth = 1280;
    int windowHeight = 640;
    
    float lastFrameTime = 0.0f;
    float deltaTime;

    Player player;
    Grid grid;
    Rays rays;
};
