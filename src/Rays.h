#pragma once

#include "Grid.h"
#include "Player.h"

class Rays {
public:
    Rays();

    void Render(Grid& grid, Player& player);

private:
    void RenderBackground();
    void RenderRay(int r, float angle, Grid& grid, Player& player);

    float CalculateDistanceToHorizontalWall(float angle, Grid& grid, Player& player);
    float CalculateDistanceToVerticalWall(float angle, Grid& grid, Player& player);

    float NormalizeAngle(float angle);
    float dist(float ax, float ay, float bx, float by);
    float rx; float ry;
};