#pragma once

#include <GLFW/glfw3.h>
#include <math.h>

constexpr float PI = 3.1415926535f;

class Player {

public:

    Player();

    void Move(int key, int action);
    void Render();

private:

    float posX;
    float posY;

    float delX;
    float delY;

    float angle;

    static constexpr float MOVEMENT_SPEED = 5.0f;
    static constexpr float ANGLE_INCREMENT = 0.1f;
};