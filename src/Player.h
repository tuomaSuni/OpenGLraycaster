#pragma once

#include <GLFW/glfw3.h>
#include "GeometryMath.h"

class Player {
public:
    Player();

    void Move(int key, int action);
    void MouseMovement(double xpos, double ypos, float deltaTime);
    void Update(float deltaTime); 
    void Render();

    // Public members (if needed) can be declared here
    float posX;
    float posY;
    float angle;
private:
    void UpdateDirectionVectors();

    bool keys[GLFW_KEY_LAST] = { false }; // Array to track key states
    static constexpr float MOVEMENT_SPEED = 64; // Movement speed
    static constexpr float ANGLE_SENSITIVITY = RAD * 8; // Sensitivity of mouse movement

    float forwardX;
    float forwardY;
    float rightX;
    float rightY;
};
