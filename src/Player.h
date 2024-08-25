#pragma once

#include <GLFW/glfw3.h>
#include <MATH/Utils.h>
#include "Grid.h"

class Player {
public:
    Player();

    void DetectKeyInputs(int key, int action);
    void DetectMouseDelta(double xpos, double ypos, float deltaTime);
    void Update(float deltaTime, Grid& grid); 
    void Render();

    // Public members (if needed) can be declared here
    float posX;
    float posY;
    float angle;
private:

    bool keys[GLFW_KEY_LAST] = { false }; // Array to track key states
    static constexpr float MOVEMENT_SPEED = 64; // Movement speed
    static constexpr float ANGLE_SENSITIVITY = RAD * 32; // Sensitivity of mouse movement

    float forwardX;
    float forwardY;
    float rightX;
    float rightY;

    float moveX;
    float moveY;

    Grid grid;
};
