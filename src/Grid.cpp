#include "Grid.h"
#include <GLFW/glfw3.h>

Grid::Grid() {
    // Constructor can be empty or include initialization code if necessary
}

void Grid::Render() {
    
    for (int y = 0; y < GRID_HEIGHT; ++y) {
        for (int x = 0; x < GRID_WIDTH; ++x) {
            
            float x0 = x  * blockDimension + 1;
            float y0 = y  * blockDimension + 1;
            float x1 = x0 + blockDimension - 2;
            float y1 = y0 + blockDimension - 2;

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