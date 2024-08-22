#pragma once

#include <GLFW/glfw3.h>

class Player {

public:

    Player();

    void Move(int key, int action);
    void Render();

private:

    float posX;
    float posY;
};