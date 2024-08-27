#pragma once

#include <GLFW/glfw3.h>
#include <MATH/Utils.h>
#include "Grid.h"

class Player {
public:
    Player();

    void DetectKeyInputs(int key, int action);
    void DetectMouseDelta(double xpos, double ypos);
    void Update(float deltaTime, Grid& grid); 
    void Render();

    float posX;
    float posY;
    float angle;
private:

    bool keys[GLFW_KEY_LAST] = { false };
    static constexpr float MOVEMENT_SPEED = 64;
    static constexpr float ANGLE_SENSITIVITY = RAD * 2;

    float forwardX;
    float forwardY;
    float rightX;
    float rightY;

    float moveX;
    float moveY;

    Grid grid;
};
