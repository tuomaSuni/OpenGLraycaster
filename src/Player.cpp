#include "Player.h"
#include <cmath> // For std::sqrt

Player::Player() : posX(128), posY(128), angle(1.57079633) {
    forwardX = cos(angle);
    forwardY = sin(angle);
    rightX = -sin(angle);
    rightY = cos(angle);
}

void Player::Move(int key, int action) {
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


    int ipxOld  = posX    / grid.blockDimension;
    int ipyOld  = posY    / grid.blockDimension;
    int ipxNewX = newPosX / grid.blockDimension;
    int ipyNewY = newPosY / grid.blockDimension;

    if (grid.grid[ipyOld * grid.GRID_WIDTH + ipxNewX] == 1) {
        posX = newPosX;
    }

    if (grid.grid[ipyNewY * grid.GRID_WIDTH + ipxOld] == 1) {
        posY = newPosY;
    }
}

void Player::MouseMovement(double xpos, double ypos, float deltaTime) {
    static double lastX = xpos;
    static double lastY = ypos;

    double xOffset = xpos - lastX;
    double yOffset = lastY - ypos;

    lastX = xpos;
    lastY = ypos;

    angle += xOffset * ANGLE_SENSITIVITY * deltaTime;
    
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
    rightX = -sin(angle);
    rightY = cos(angle);
}

void Player::Render() {
    glColor3f(1.0f, 0.0f, 0.0f);
    glPointSize(8);
    glBegin(GL_POINTS);
    glVertex2i(posX, posY);
    glEnd();
}
