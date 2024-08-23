#include "Grid.h"
#include <GLFW/glfw3.h>

Grid::Grid() {
    // Constructor can be empty or include initialization code if necessary
}

void Grid::Render() {
    // Define the padding between blocks
    const float padding = 1.0f; // Padding in pixels
    
    // Calculate block width and height with padding
    float blockWidth = (640.0f / GRID_WIDTH) - padding;
    float blockHeight = (640.0f / GRID_HEIGHT) - padding;

    // Render blocks with padding
    for (int y = 0; y < GRID_HEIGHT; ++y) {
        for (int x = 0; x < GRID_WIDTH; ++x) {
            float x0 = x * (blockWidth + padding);
            float y0 = y * (blockHeight + padding);
            float x1 = x0 + blockWidth;
            float y1 = y0 + blockHeight;

            if (grid[y * GRID_WIDTH + x] == 1) {
                glColor3f(1.0f, 1.0f, 1.0f); // White block
            } else {
                glColor3f(0.0f, 0.0f, 0.0f); // Black block
            }

            glBegin(GL_QUADS);
            glVertex2f(x0, y0);
            glVertex2f(x1, y0);
            glVertex2f(x1, y1);
            glVertex2f(x0, y1);
            glEnd();
        }
    }
}