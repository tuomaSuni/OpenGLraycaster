#include "Rays.h"

Rays::Rays()
{
}

void Rays::Render(Grid &grid, Player &player) {

    int r, mx, my, mp, dof;
    float rx, ry, ra, xo, yo;

    ra = player.angle;  // Accessing the player's angle

    for(r = 0; r < 1; r++)
    {

        // Direction 1

        dof = 0;
        float disH = 1000000;

        float hx = player.posX;
        float hy = player.posY;

        float aTan = -1 / tan(ra);

        if(ra > PI) { 
            ry = (((int)player.posY >> 6) << 6) - 0.0001; 
            rx = (player.posY - ry) * aTan + player.posX; 
            yo = -64; 
            xo = -yo * aTan;
        }
        if(ra < PI) { 
            ry = (((int)player.posY >> 6) << 6) + 64;     
            rx = (player.posY - ry) * aTan + player.posX; 
            yo = 64; 
            xo = -yo * aTan;
        }
        if(ra == 0 || ra == PI) {
            rx = player.posX; 
            ry = player.posY; 
            dof = 8;
        }
        while(dof < 8)
        {
            mx = (int)(rx) >> 6;
            my = (int)(ry) >> 6;
            mp = my * grid.GRID_WIDTH + mx;
            if(mp > 0 && mp < grid.GRID_WIDTH * grid.GRID_HEIGHT && grid.grid[mp]==0) {
                hx = rx;
                hy = ry;
                disH = dist(player.posX,player.posY,hx,hy);
                dof = 8;
            } else {
                rx += xo; 
                ry += yo; 
                dof += 1;
            }
        }

        // Direction 0


        dof = 0;
        float disV = 1000000;
        float vx = player.posX;
        float vy = player.posY;

        float nTan = -tan(ra);

        if(ra > P2 && ra < P3) { 
            rx = (((int)player.posX >> 6) << 6) - 0.0001; 
            ry = (player.posX - rx) * nTan + player.posY; 
            xo = -64; 
            yo = -xo * nTan;
        }
        if(ra < P2 || ra > P3) { 
            rx = (((int)player.posX >> 6) << 6) + 64;     
            ry = (player.posX - rx) * nTan + player.posY; 
            xo = 64; 
            yo = -xo * nTan;
        }
        if(ra == 0 || ra == PI) {
            rx = player.posX; 
            ry = player.posY; 
            dof = 8;
        }
        while(dof < 8)
        {
            mx = (int)(rx) >> 6;
            my = (int)(ry) >> 6;
            mp = my * grid.GRID_WIDTH + mx;
            if(mp > 0 && mp < grid.GRID_WIDTH * grid.GRID_HEIGHT && grid.grid[mp]==0) {
                vx = rx;
                vy = ry;
                disV = dist(player.posX,player.posY,vx,vy);
                dof = 8;
            } else {
                rx += xo; 
                ry += yo; 
                dof += 1;
            }
        }

        if (disV < disH) {
            rx = vx;
            ry = vy;
        }
        if (disV > disH) {
            rx = hx;
            ry = hy;
        }

        glColor3f(0.0f, 1.0f, 1.0f);
        glLineWidth(3);
        glBegin(GL_LINES);
        glVertex2i(player.posX, player.posY);
        glVertex2i(rx, ry);
        glEnd();
    }
}

float Rays::dist(float ax, float ay, float bx, float by)
{
    return sqrt((bx-ax) * (bx-ax) + (by-ay) *(by-ay));
}
