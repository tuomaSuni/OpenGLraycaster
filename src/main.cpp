#include <GLFW/glfw3.h>

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        return -1; // Initialization failed
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(640, 480, "Hello GLFW", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1; // Window creation failed
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

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

    // Clean up and exit
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}