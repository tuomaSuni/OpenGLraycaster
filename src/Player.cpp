#include "Player.h"

Player::Player()
{
    posX = 320;
    posY = 320;

    angle = 0;

    delX = cos(angle) * MOVEMENT_SPEED;
    delY = sin(angle) * MOVEMENT_SPEED;
}

void Player::Move(int key, int action)
{
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        switch (key) {
            case GLFW_KEY_LEFT:
                angle -= ANGLE_INCREMENT;
                if (angle < 0)
                {
                    angle += 2 * PI;
                }
                delX = cos(angle) * MOVEMENT_SPEED;
                delY = sin(angle) * MOVEMENT_SPEED;
                break;
            case GLFW_KEY_RIGHT:
                angle += ANGLE_INCREMENT;
                if (angle > 2 * PI)
                {
                    angle -= 2 * PI;
                }
                delX = cos(angle) * MOVEMENT_SPEED;
                delY = sin(angle) * MOVEMENT_SPEED;
                break;
            case GLFW_KEY_UP:
                posX += delX;
                posY += delY;
                break;
            case GLFW_KEY_DOWN:
                posX -= delX;
                posY -= delY;
                break;
        }
    }
}

void Player::Render()
{
    glColor3f(0.0f, 1.0f, 1.0f); // Set color to cyan
    glPointSize(8);

    glBegin(GL_POINTS);
    glVertex2i(posX, posY);
    glEnd();

    glColor3f(0.7f, 0.7f, 1.0f); // Set color to cyan

    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2i(posX, posY);
    glVertex2i(posX+delX*2, posY+delY*2);
    glEnd();
}