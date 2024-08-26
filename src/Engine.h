#pragma once

#include "Grid.h"
#include "Player.h"

class Engine {
public:
    Engine(int window_width, int window_height);

    void Render(Grid& grid, Player& player);

private:
    void drawSkyAndGround();
    void drawRayColumn(int columnIndex, float angle, const Grid& grid, const Player& player, bool mode);
    float castHorizontalRay(float ra, const Grid& grid, const Player& player, float& hx, float& hy);
    float castVerticalRay(float ra, const Grid& grid, const Player& player, float& vx, float& vy);
    float dist(float ax, float ay, float bx, float by) const;

    bool Mode_3D = true;
    
    int resolution = 1024;
    float staticres = resolution;
    float inc = 64 / staticres;
    
    int render_width;
    int render_height;
};
