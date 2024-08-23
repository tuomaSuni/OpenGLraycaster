#include "App.h"

App::App()
{
    player = Player();
    grid = Grid();
    rays = Rays();
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

    videoMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    window = glfwCreateWindow(windowWidth, windowHeight, "OpenGLraycaster", NULL, NULL);
    if (!window) {
        glfwTerminate();
        throw std::runtime_error("Window creation failed");
    }

    glfwMakeContextCurrent(window);
    glViewport(0, 0, windowWidth, windowHeight);
    glOrtho(0, windowWidth, windowHeight, 0, -1, 1); // Orthographic projection

    int xpos = (videoMode->width - windowWidth) / 2;
    int ypos = (videoMode->height - windowHeight) / 2;
    glfwSetWindowPos(window, xpos, ypos);

    // Set up key callback to handle movement
    glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        Player* player = reinterpret_cast<Player*>(glfwGetWindowUserPointer(window));
        if (player) {
            player->Move(key, action); // Pass key and action to Move
        }
    });

    glfwSetWindowUserPointer(window, &player);
}

void App::Loop()
{
    while (!glfwWindowShouldClose(window)) {
        
        glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        
        grid.Render();
        player.Render(); // Render the player
        rays.Render(grid, player);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    Terminate();
}

void App::Terminate()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}
