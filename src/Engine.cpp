#include "Engine.h"
#include "Textures.h"

Engine::Engine(int window_width, int window_height, int LOD, bool render_mode) {

    LOD           = (LOD < 1) ? 1 : (LOD > 8) ? 8 : LOD;
    resolution    = window_width / (1 << (8 - LOD));
    
    render_width  = window_width;
    render_height = window_height;

    staticres     = resolution;
    inc           = 64 / staticres;

    flag          = render_mode;
}

void Engine::Render(Grid& grid, Player& player) {
    float ra = player.angle - RAD * 32;
    ra = fmod(ra + 2 * PI, 2 * PI);
    
    if (flag == true) {
        drawSkyAndGround();

        for (int r = 0; r < resolution; ++r) {
            drawRayColumn(r, ra, grid, player, true);
            ra += RAD * inc;
            ra = fmod(ra + 2 * PI, 2 * PI);
        }
    } else {
        for (int r = 0; r < resolution; ++r) {
            drawRayColumn(r, ra, grid, player, false);
            ra += RAD * inc;
            ra = fmod(ra + 2 * PI, 2 * PI);
        }
    }
}

void Engine::drawSkyAndGround() {
    glColor3f(0.5f, 0.8f, 0.9f);
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(render_width, 0);
    glVertex2f(render_width, render_height/2);
    glVertex2f(0, render_height/2);
    glEnd();

    glColor3f(0.2f, 0.6f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(0, render_height/2);
    glVertex2f(render_width, render_height/2);
    glVertex2f(render_width, render_width);
    glVertex2f(0, render_width);
    glEnd();
}

void Engine::drawRayColumn(int columnIndex, float angle, const Grid& grid, const Player& player, bool draw3Drays) {
    float hx, hy, vx, vy;

    float disH = castHorizontalRay(angle, grid, player, hx, hy);
    float disV = castVerticalRay(angle, grid, player, vx, vy);

    float disT;
    float shading;
    if (disV < disH) {
        hx = vx;
        hy = vy;
        disT = disV;
        glColor3f(0.9f, 0.9f, 0.9f);
        shading = 0.5;
    } else {
        hx = hx;
        hy = hy;
        disT = disH;
        glColor3f(0.7f, 0.7f, 0.7f);
        shading = 1.0;
    }

    if (draw3Drays != true) {
        glLineWidth(3);
        glBegin(GL_LINES);
        glVertex2f(player.posX, player.posY);
        glVertex2f(hx, hy);
        glEnd();
    } else {
        float ca = player.angle - angle;
        disT *= cos(ca);

        float lineH = (grid.BLOCK_DIMENSION * render_height) / disT;
        float ty_step=32.0/(float)lineH;
        float ty_off=0;
        if (lineH>640)
        {
            ty_off=(lineH-640)/2.0;
            lineH = 640;
        }

        float lineO = render_height / 2 - lineH / 2;

        float point = render_width / staticres;
        
        bool drawTextures = true;
        
        if (drawTextures != true)
        {
            glLineWidth(point);
            glBegin(GL_LINES);
            glVertex2i(columnIndex * point + point / 2, lineO);
            glVertex2i(columnIndex * point + point / 2, lineH + lineO);
            glEnd();
        }
        else
        {
            int y;
            float ty=ty_off*ty_step;

            float tx;
            if (shading==1) { tx=(int)(hx/2.0)%32; if (angle > P2) { tx=31-tx;}}
            else            { tx=(int)(hy/2.0)%32; if (angle > PI / 3 && angle < P3) { tx=31-tx;}}
            
            for (y=0;y<lineH;y++)
            {
                int index = Brick[(int)(ty)*32 + (int)(tx)];
                
                glColor3f(colorvalues[index][0] * shading, colorvalues[index][1] * shading, colorvalues[index][2] * shading);
                glPointSize(point);
                glBegin(GL_POINTS);
                glVertex2i(columnIndex * point + point / 2, y+lineO);
                glEnd();
                ty+=ty_step;
            }
        }
    }
}

float Engine::castHorizontalRay(float ra, const Grid& grid, const Player& player, float& hx, float& hy) {
    float disH = 1e6f;
    float aTan = -1 / tan(ra);
    float rx, ry, xo, yo;
    int dof = 0;

    if (ra > PI) {
        ry = (static_cast<int>(player.posY) & ~(grid.BLOCK_DIMENSION-1)) - 0.0001f;
        rx = (player.posY - ry) * aTan + player.posX;
        yo = -grid.BLOCK_DIMENSION;
        xo = -yo * aTan;
    } else if (ra < PI) {
        ry = (static_cast<int>(player.posY) & ~(grid.BLOCK_DIMENSION-1)) + grid.BLOCK_DIMENSION;
        rx = (player.posY - ry) * aTan + player.posX;
        yo = grid.BLOCK_DIMENSION;
        xo = -yo * aTan;
    } else {
        rx = player.posX;
        ry = player.posY;
        disH = 1e6f;
    }

    while (dof < std::sqrt(grid.BLOCK_DIMENSION)) {
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

float Engine::castVerticalRay(float ra, const Grid& grid, const Player& player, float& vx, float& vy) {
    float disV = 1e6f;
    float nTan = -tan(ra);
    float rx, ry, xo, yo;
    int dof = 0;

    if (ra > P2 && ra < P3) {
        rx = (static_cast<int>(player.posX) & ~(grid.BLOCK_DIMENSION-1)) - 0.0001f;
        ry = (player.posX - rx) * nTan + player.posY;
        xo = -grid.BLOCK_DIMENSION;
        yo = -xo * nTan;
    } else if (ra < P2 || ra > P3) {
        rx = (static_cast<int>(player.posX) & ~(grid.BLOCK_DIMENSION-1)) + grid.BLOCK_DIMENSION;
        ry = (player.posX - rx) * nTan + player.posY;
        xo = grid.BLOCK_DIMENSION;
        yo = -xo * nTan;
    } else {
        rx = player.posX;
        ry = player.posY;
        disV = 1e6f;
    }

    while (dof < std::sqrt(grid.BLOCK_DIMENSION)) {
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

float Engine::dist(float ax, float ay, float bx, float by) const {
    float dx = bx - ax;
    float dy = by - ay;
    return std::sqrt(dx * dx + dy * dy);
}
