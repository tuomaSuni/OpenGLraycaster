#include "Player.h"

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
    if (keys[GLFW_KEY_W]) {
        posX += forwardX * MOVEMENT_SPEED * deltaTime;
        posY += forwardY * MOVEMENT_SPEED * deltaTime;
    }
    if (keys[GLFW_KEY_S]) {
        posX -= forwardX * MOVEMENT_SPEED * deltaTime;
        posY -= forwardY * MOVEMENT_SPEED * deltaTime;
    }
    if (keys[GLFW_KEY_A]) {
        posX -= rightX * MOVEMENT_SPEED * deltaTime;
        posY -= rightY * MOVEMENT_SPEED * deltaTime;
    }
    if (keys[GLFW_KEY_D]) {
        posX += rightX * MOVEMENT_SPEED * deltaTime;
        posY += rightY * MOVEMENT_SPEED * deltaTime;
    }
}

void Player::MouseMovement(double xpos, double ypos, float deltaTime) {
    static double lastX = xpos;
    static double lastY = ypos;

    double xOffset = xpos - lastX;
    double yOffset = lastY - ypos; // Reversed since y-coordinates go from top to bottom

    lastX = xpos;
    lastY = ypos;

    angle += xOffset * ANGLE_SENSITIVITY * deltaTime;

    UpdateDirectionVectors();
}

void Player::Render() {
    glColor3f(0.0f, 1.0f, 1.0f); // Set color to cyan
    glPointSize(8);

    glBegin(GL_POINTS);
    glVertex2i(posX, posY);
    glEnd();
}
