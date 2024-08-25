#include "Rays.h"

Rays::Rays() {
}

void Rays::Render(Grid& grid, Player& player) {
    float ra = player.angle - RAD * 28;
    ra = fmod(ra + 2 * PI, 2 * PI); // Normalize angle to [0, 2*PI]
    float someboolean = false;
    if (someboolean == true)
    {
        drawSkyAndGround();

        for (int r = 0; r < 128; ++r) {
            drawRayColumn(r, ra, grid, player, true);
            ra += RAD * 0.5f;
            ra = fmod(ra + 2 * PI, 2 * PI); // Normalize angle to [0, 2*PI]
        }
    }
    else
    {
        for (int r = 0; r < 128; ++r) {
            drawRayColumn(r, ra, grid, player, false);
            ra += RAD * 0.5f;
            ra = fmod(ra + 2 * PI, 2 * PI); // Normalize angle to [0, 2*PI]
        }
    }
}

void Rays::drawSkyAndGround() {
    // Draw the sky
    glColor3f(0.5f, 0.77f, 0.9f); // Sky color
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(640, 0);
    glVertex2f(640, 320);
    glVertex2f(0, 320);
    glEnd();

    // Draw the ground
    glColor3f(0.2f, 0.6f, 0.4f); // Ground color
    glBegin(GL_QUADS);
    glVertex2f(0, 320);
    glVertex2f(640, 320);
    glVertex2f(640, 640);
    glVertex2f(0, 640);
    glEnd();
}

void Rays::drawRayColumn(int columnIndex, float angle, const Grid& grid, const Player& player, bool rays) {
    float hx, hy, vx, vy;

    float disH = castHorizontalRay(angle, grid, player, hx, hy);
    float disV = castVerticalRay(angle, grid, player, vx, vy);

    // Determine the closest intersection
    float disT;
    if (disV < disH) {
        hx = vx;
        hy = vy;
        disT = disV;
        glColor3f(0.8f, 0.8f, 0.8f); // Light color
    } else {
        hx = hx;
        hy = hy;
        disT = disH;
        glColor3f(0.7f, 0.7f, 0.7f); // Darker color
    }

    if (rays == false)
    {
        glLineWidth(3);
        glBegin(GL_LINES);
        glVertex2f(player.posX, player.posY);
        glVertex2f(hx, hy);
        glEnd();
    }
    else
    {
        // Correct the distance for the field of view
        float ca = player.angle - angle;
        disT *= cos(ca);

        // Calculate line height
        float lineH = (64 * 640) / disT;
        lineH = std::min(lineH, 640.0f);

        float lineO = 320 - lineH / 2;

        // Draw the line
        glLineWidth(5);
        glBegin(GL_LINES);
        glVertex2i(columnIndex * 5 + 3, lineO);
        glVertex2i(columnIndex * 5 + 3, lineH + lineO);
        glEnd();
    }
}

float Rays::castHorizontalRay(float ra, const Grid& grid, const Player& player, float& hx, float& hy) {
    float disH = 1e6f;
    float aTan = -1 / tan(ra);
    float rx, ry, xo, yo;
    int dof = 0;

    if (ra > PI) {
        ry = (static_cast<int>(player.posY) & ~63) - 0.0001f;
        rx = (player.posY - ry) * aTan + player.posX;
        yo = -64;
        xo = -yo * aTan;
    } else if (ra < PI) {
        ry = (static_cast<int>(player.posY) & ~63) + 64;
        rx = (player.posY - ry) * aTan + player.posX;
        yo = 64;
        xo = -yo * aTan;
    } else {
        rx = player.posX;
        ry = player.posY;
        disH = 1e6f;
    }

    while (dof < 8) {
        int mx = static_cast<int>(rx) >> 6;
        int my = static_cast<int>(ry) >> 6;
        int mp = my * grid.GRID_WIDTH + mx;
        if (mp >= 0 && mp < grid.GRID_WIDTH * grid.GRID_HEIGHT && grid.grid[mp] == 0) {
            hx = rx;
            hy = ry;
            disH = dist(player.posX, player.posY, hx, hy);
            break;
        } else {
            rx += xo;
            ry += yo;
            ++dof;
        }
    }

    return disH;
}

float Rays::castVerticalRay(float ra, const Grid& grid, const Player& player, float& vx, float& vy) {
    float disV = 1e6f;
    float nTan = -tan(ra);
    float rx, ry, xo, yo;
    int dof = 0;

    if (ra > P2 && ra < P3) {
        rx = (static_cast<int>(player.posX) & ~63) - 0.0001f;
        ry = (player.posX - rx) * nTan + player.posY;
        xo = -64;
        yo = -xo * nTan;
    } else if (ra < P2 || ra > P3) {
        rx = (static_cast<int>(player.posX) & ~63) + 64;
        ry = (player.posX - rx) * nTan + player.posY;
        xo = 64;
        yo = -xo * nTan;
    } else {
        rx = player.posX;
        ry = player.posY;
        disV = 1e6f;
    }

    while (dof < 8) {
        int mx = static_cast<int>(rx) >> 6;
        int my = static_cast<int>(ry) >> 6;
        int mp = my * grid.GRID_WIDTH + mx;
        if (mp >= 0 && mp < grid.GRID_WIDTH * grid.GRID_HEIGHT && grid.grid[mp] == 0) {
            vx = rx;
            vy = ry;
            disV = dist(player.posX, player.posY, vx, vy);
            break;
        } else {
            rx += xo;
            ry += yo;
            ++dof;
        }
    }

    return disV;
}

float Rays::dist(float ax, float ay, float bx, float by) const {
    float dx = bx - ax;
    float dy = by - ay;
    return std::sqrt(dx * dx + dy * dy);
}
