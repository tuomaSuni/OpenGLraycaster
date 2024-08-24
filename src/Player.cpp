#include "Player.h"
#include <cmath> // For std::sqrt

Player::Player()
    : posX(320), posY(320), angle(-90.0f * RAD) {
    UpdateDirectionVectors();
}

void Player::UpdateDirectionVectors() {
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

void Player::Update(float deltaTime) {
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

    // Normalize the movement vector
    float magnitude = std::sqrt(moveX * moveX + moveY * moveY);
    if (magnitude > 0.0f) {
        moveX /= magnitude;
        moveY /= magnitude;
    }

    // Update position based on normalized direction vector
    posX += moveX * MOVEMENT_SPEED * deltaTime;
    posY += moveY * MOVEMENT_SPEED * deltaTime;
}

void Player::MouseMovement(double xpos, double ypos, float deltaTime) {
    static double lastX = xpos;
    static double lastY = ypos;

    double xOffset = xpos - lastX;
    double yOffset = lastY - ypos;

    lastX = xpos;
    lastY = ypos;

    angle += xOffset * ANGLE_SENSITIVITY * deltaTime;

    UpdateDirectionVectors();
}

void Player::Render() {
    glColor3f(1.0f, 0.0f, 0.0f);
    glPointSize(8);
    glBegin(GL_POINTS);
    glVertex2i(posX, posY);
    glEnd();
}
