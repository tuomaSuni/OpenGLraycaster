#include "Grid.h"

Grid::Grid() {}

void Grid::Render() {
    
    for (int y = 0; y < GRID_HEIGHT; ++y) {
        for (int x = 0; x < GRID_WIDTH; ++x) {
            
            float x0 = x  * BLOCK_DIMENSION + 1;
            float y0 = y  * BLOCK_DIMENSION + 1;
            float x1 = x0 + BLOCK_DIMENSION - 2;
            float y1 = y0 + BLOCK_DIMENSION - 2;

            if (grid[y * GRID_WIDTH + x] == 1) {
                glColor3f(1.0f, 1.0f, 1.0f);
            } else {
                glColor3f(0.0f, 0.0f, 0.0f);
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