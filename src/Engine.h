#pragma once

#include "Grid.h"
#include "Player.h"

class Engine {
public:
    Engine(int window_width, int window_height, int LOD, bool render_mode);

    void Render(Grid& grid, Player& player);
    
private:
    void drawSkyAndGround();
    void drawRayColumn(int columnIndex, float angle, const Grid& grid, const Player& player, bool mode);
    float castHorizontalRay(float ra, const Grid& grid, const Player& player, float& hx, float& hy);
    float castVerticalRay(float ra, const Grid& grid, const Player& player, float& vx, float& vy);
    float dist(float ax, float ay, float bx, float by) const;

    bool flag;
    
    int render_width;
    int render_height;

    int resolution;
    float staticres;
    float inc;

    float colorvalues[2][3] = {{0.6f, 0.6f, 0.6f}, {0.7f, 0.3f, 0.2f}};
};
