
#pragma once

#include <GLFW/glfw3.h>

class Grid {
public:
    Grid();
    void Render();

    static const int GRID_WIDTH = 10;
    static const int GRID_HEIGHT = 10;

    int grid[GRID_HEIGHT * GRID_WIDTH] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 0, 1, 1, 1, 1, 1, 0,
        0, 1, 1, 0, 1, 1, 0, 1, 1, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 1, 1, 1, 1, 1, 0, 0, 0, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 1, 0, 0, 1, 1, 1, 1, 1, 0,
        0, 1, 0, 0, 1, 1, 1, 0, 1, 0,
        0, 1, 1, 1, 1, 0, 1, 0, 1, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    
private:

};