#include "Rays.h"
#include <cmath>
#include <algorithm> // For std::min

Rays::Rays() {
    // Constructor body can be empty if no initialization is needed
}

void Rays::Render(Grid& grid, Player& player) {
    RenderBackground();

    float angle = NormalizeAngle(player.angle - RAD * 28);

    for (int r = 0; r < 128; ++r) {
        RenderRay(r, angle, grid, player);
        angle = NormalizeAngle(angle + RAD * 0.5f);
    }
}

void Rays::RenderBackground() {
    glColor3f(0.2f, 0.6f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(0, 320);
    glVertex2f(640, 320);
    glVertex2f(640, 640);
    glVertex2f(0, 640);
    glEnd();

    glColor3f(0.5f, 0.77f, 0.9f);
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(640, 0);
    glVertex2f(640, 320);
    glVertex2f(0, 320);
    glEnd();
}

void Rays::RenderRay(int r, float angle, Grid& grid, Player& player) {
    float disH = CalculateDistanceToHorizontalWall(angle, grid, player);
    float disV = CalculateDistanceToVerticalWall(angle, grid, player);

    float hitX, hitY, disT;
    glColor3f(disV < disH ? 0.8f : 0.7f, disV < disH ? 0.8f : 0.7f, disV < disH ? 0.8f : 0.7f);

    if (disV < disH) {
        hitX = player.posX + disV * cos(angle);
        hitY = player.posY + disV * sin(angle);
        disT = disV;
    } else {
        hitX = player.posX + disH * cos(angle);
        hitY = player.posY + disH * sin(angle);
        disT = disH;
    }

    float ca = NormalizeAngle(player.angle - angle);
    disT *= cos(ca);

    float lineH = (64 * 640) / disT;
    float lineO = 640 / 2 - lineH / 2;
    lineH = std::min(lineH, 640.0f);

  /*  glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2i(player.posX, player.posY);
    glVertex2i(hitX, hitY);
    glEnd();*/

    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(r * 5, lineO);
    glVertex2i(r * 5, lineH + lineO);
    glEnd();
}

float Rays::CalculateDistanceToHorizontalWall(float angle, Grid& grid, Player& player) {
    float disH = 1000000.0f;
    float aTan = -1 / tan(angle);
    float rx = player.posX;
    float ry = player.posY;
    float xo, yo;

    if (angle > PI) {
        ry = (static_cast<int>(player.posY) >> 6 << 6) - 0.0001f;
        rx = (player.posY - ry) * aTan + player.posX;
        yo = -64;
        xo = -yo * aTan;
    } else {
        ry = (static_cast<int>(player.posY) >> 6 << 6) + 64;
        rx = (player.posY - ry) * aTan + player.posX;
        yo = 64;
        xo = -yo * aTan;
    }

    int dof = 0;
    while (dof < 8) {
        int mx = static_cast<int>(rx) >> 6;
        int my = static_cast<int>(ry) >> 6;
        int mp = my * grid.GRID_WIDTH + mx;

        if (mp >= 0 && mp < grid.GRID_WIDTH * grid.GRID_HEIGHT && grid.grid[mp] == 0) {
            disH = dist(player.posX, player.posY, rx, ry);
            break;
        } else {
            rx += xo;
            ry += yo;
            ++dof;
        }
    }
    return disH;
}

float Rays::CalculateDistanceToVerticalWall(float angle, Grid& grid, Player& player) {
    float disV = 1000000.0f;
    float nTan = -tan(angle);
    float rx = player.posX;
    float ry = player.posY;
    float xo, yo;

    if (angle > P2 && angle < P3) {
        rx = (static_cast<int>(player.posX) >> 6 << 6) - 0.0001f;
        ry = (player.posX - rx) * nTan + player.posY;
        xo = -64;
        yo = -xo * nTan;
    } else {
        rx = (static_cast<int>(player.posX) >> 6 << 6) + 64;
        ry = (player.posX - rx) * nTan + player.posY;
        xo = 64;
        yo = -xo * nTan;
    }

    int dof = 0;
    while (dof < 8) {
        int mx = static_cast<int>(rx) >> 6;
        int my = static_cast<int>(ry) >> 6;
        int mp = my * grid.GRID_WIDTH + mx;

        if (mp >= 0 && mp < grid.GRID_WIDTH * grid.GRID_HEIGHT && grid.grid[mp] == 0) {
            disV = dist(player.posX, player.posY, rx, ry);
            break;
        } else {
            rx += xo;
            ry += yo;
            ++dof;
        }
    }
    return disV;
}

float Rays::NormalizeAngle(float angle) {
    if (angle < 0) angle += 2 * PI;
    if (angle > 2 * PI) angle -= 2 * PI;
    return angle;
}

float Rays::dist(float ax, float ay, float bx, float by) {
    return std::sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
}
