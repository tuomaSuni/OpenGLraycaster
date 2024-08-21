#include "App.h"

App::App()
{

}

void App::Execute()
{
    Initialize();
    Loop();
}

void App::Initialize()
{
    if (!glfwInit()) {
        throw std::runtime_error("GLFW initialization failed");
    }

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(640, 480, "Hello GLFW", NULL, NULL);
    if (!window) {
        glfwTerminate();
        throw std::runtime_error("Window creation failed");
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
}

void App::Loop()
{
    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Set the background color to a color of your choice
        glClearColor(0.0f, 0.5f, 0.8f, 1.0f); // RGB and Alpha values
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }
    Terminate();
}

void App::Terminate()
{
    // Clean up and exit
    glfwDestroyWindow(window);
    glfwTerminate();
}
