#pragma once

#include "Grid.h"
#include "Player.h"

class Rays {
public:
    Rays();

    void Render(Grid& grid, Player& player);

private:
    void drawSkyAndGround();
    void drawRayColumn(int columnIndex, float angle, const Grid& grid, const Player& player, bool rays);
    float castHorizontalRay(float ra, const Grid& grid, const Player& player, float& hx, float& hy);
    float castVerticalRay(float ra, const Grid& grid, const Player& player, float& vx, float& vy);
    float dist(float ax, float ay, float bx, float by) const;
};
