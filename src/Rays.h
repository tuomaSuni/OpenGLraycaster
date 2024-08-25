 #pragma once

#include "Grid.h"
#include "Player.h"

class Rays {
public:
    Rays();

    void Render(Grid& grid, Player& player);
    float dist(float ax, float ay, float bx, float by);
private:
    Grid grid;
    Player player;
};