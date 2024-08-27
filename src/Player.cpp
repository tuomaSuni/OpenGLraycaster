#include "Player.h"

Player::Player() : posX(96), posY(96), angle(PI / 2) {
    forwardX = cos(angle);
    forwardY = sin(angle);
    rightX   =-sin(angle);
    rightY   = cos(angle);
}

void Player::DetectKeyInputs(int key, int action) {
    if (action == GLFW_PRESS) {
        keys[key] = true;
    } else if (action == GLFW_RELEASE) {
        keys[key] = false;
    }
}

void Player::Update(float deltaTime, Grid& grid) {

    float moveX = 0.0f;
    float moveY = 0.0f;

    if (keys[GLFW_KEY_W]) {
        moveX += forwardX;
        moveY += forwardY;
    }
    if (keys[GLFW_KEY_S]) {
        moveX -= forwardX;
        moveY -= forwardY;
    }
    if (keys[GLFW_KEY_A]) {
        moveX -= rightX;
        moveY -= rightY;
    }
    if (keys[GLFW_KEY_D]) {
        moveX += rightX;
        moveY += rightY;
    }

    float magnitude = std::sqrt(moveX * moveX + moveY * moveY);
    if (magnitude > 0.0f) {
        moveX /= magnitude;
        moveY /= magnitude;
    }

    float newPosX = posX + moveX * MOVEMENT_SPEED * deltaTime;
    float newPosY = posY + moveY * MOVEMENT_SPEED * deltaTime;


    int ipxOld  = posX    / grid.BLOCK_DIMENSION;
    int ipyOld  = posY    / grid.BLOCK_DIMENSION;
    int ipxNewX = newPosX / grid.BLOCK_DIMENSION;
    int ipyNewY = newPosY / grid.BLOCK_DIMENSION;

    if (grid.grid[ipyOld * grid.GRID_WIDTH + ipxNewX] == 1) {
        posX = newPosX;
    }

    if (grid.grid[ipyNewY * grid.GRID_WIDTH + ipxOld] == 1) {
        posY = newPosY;
    }
}

void Player::DetectMouseDelta(double xpos, double ypos) {
    static double lastX = xpos;
    static double lastY = ypos;

    double xOffset = xpos - lastX;
    double yOffset = lastY - ypos;

    lastX = xpos;
    lastY = ypos;

    angle += xOffset * ANGLE_SENSITIVITY / 100;
    
    if (angle > 2 * PI)
    {
        angle -= 2 * PI;
    }
    if (angle < 0)
    {
        angle += 2 * PI;
    }

    forwardX = cos(angle);
    forwardY = sin(angle);
    rightX   =-sin(angle);
    rightY   = cos(angle);
}

void Player::Render() {
    glColor3f(1.0f, 0.0f, 0.0f);
    glPointSize(8);
    glBegin(GL_POINTS);
    glVertex2i(posX, posY);
    glEnd();
}
