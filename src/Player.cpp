#include "Player.h"

Player::Player() : posX(400), posY(300) // Start at center of window
{
}

void Player::Move(int key, int action)
{
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        switch (key) {
            case GLFW_KEY_LEFT:
                posX -= 5.0f;
                break;
            case GLFW_KEY_RIGHT:
                posX += 5.0f;
                break;
            case GLFW_KEY_UP:
                posY -= 5.0f;
                break;
            case GLFW_KEY_DOWN:
                posY += 5.0f;
                break;
        }
    }
}

void Player::Render()
{
    glColor3f(1.0f, 0.0f, 0.0f); // Set color to red

    // Render the player as a small square
    glBegin(GL_QUADS);
    glVertex2f(posX - 5, posY - 5); // Bottom-left corner
    glVertex2f(posX + 5, posY - 5); // Bottom-right corner
    glVertex2f(posX + 5, posY + 5); // Top-right corner
    glVertex2f(posX - 5, posY + 5); // Top-left corner
    glEnd();
}