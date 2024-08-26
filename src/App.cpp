#include "App.h"

App::App() : window(nullptr, glfwDestroyWindow),
             engine(WINDOW_WIDTH, WINDOW_HEIGHT, 8, RENDER_MODE) {
    if (RENDER_MODE == false)
    {
        WINDOW_WIDTH = 640;
        WINDOW_HEIGHT = 640;
    }
}

void App::Execute() {
    Initialize();
    Loop();
}

void App::Initialize() {
    InitializeGLFW();
    CreateWindow();
    SetOpenGLSettings();
    SetCallbacks();
}

void App::InitializeGLFW() {
    if (!glfwInit()) {
        throw std::runtime_error("GLFW initialization failed");
    }
}

void App::CreateWindow() {
    videoMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    if (!videoMode) {
        glfwTerminate();
        throw std::runtime_error("Failed to get video mode");
    }

    window.reset(glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "OpenGL Raycaster", nullptr, nullptr));
    
    if (!window) {
        glfwTerminate();
        throw std::runtime_error("Window creation failed");
    }
}

void App::SetOpenGLSettings() {
    glfwSetWindowAttrib(window.get(), GLFW_RESIZABLE, GLFW_FALSE);
    glfwMakeContextCurrent(window.get());
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glOrtho(0, WINDOW_WIDTH, WINDOW_HEIGHT, 0, -1, 1); // Orthographic projection

    int xpos = (videoMode->width - WINDOW_WIDTH) / 2;
    int ypos = (videoMode->height - WINDOW_HEIGHT) / 2;
    glfwSetWindowPos(window.get(), xpos, ypos);

    glfwSetInputMode(window.get(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void App::SetCallbacks() {
    glfwSetKeyCallback(window.get(), KeyCallback);
    glfwSetCursorPosCallback(window.get(), MouseCallback);
    glfwSetWindowUserPointer(window.get(), this); // Set the window user pointer to this instance
}

void App::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    App* app = reinterpret_cast<App*>(glfwGetWindowUserPointer(window));
    if (app) {
        app->KeyCallbackImpl(key, action);
    }
}

void App::KeyCallbackImpl(int key, int action) {
    player.DetectKeyInputs(key, action);
}

void App::MouseCallback(GLFWwindow* window, double xpos, double ypos) {
    App* app = reinterpret_cast<App*>(glfwGetWindowUserPointer(window));
    if (app) {
        app->MouseCallbackImpl(xpos, ypos);
    }
}

void App::MouseCallbackImpl(double xpos, double ypos) {
    player.DetectMouseDelta(xpos, ypos);
}

void App::Loop() {
    while (!glfwWindowShouldClose(window.get())) {
        ProcessFrame();
        Render();
        glfwSwapBuffers(window.get());
        glfwPollEvents();
    }
}

void App::ProcessFrame() {
    float currentFrameTime = static_cast<float>(glfwGetTime());
    deltaTime = currentFrameTime - lastFrameTime;
    lastFrameTime = currentFrameTime;

    glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void App::Render() {
    player.Update(deltaTime, grid); // Update the player's position
    grid.Render();
    player.Render();
    engine.Render(grid, player);
}

void App::Terminate() {
    glfwTerminate();
}
