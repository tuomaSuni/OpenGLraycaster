#pragma once

#include <GLFW/glfw3.h>
#include "GeometryMath.h"

class Player {

public:

    Player();

    void Move(int key, int action);
    void Render();

    float posX;
    float posY;

    float delX;
    float delY;

    float angle;
    
private:

    static constexpr float MOVEMENT_SPEED = 5.0f;
    static constexpr float ANGLE_INCREMENT = 0.0174533;
};