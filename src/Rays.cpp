#include "Rays.h"

Rays::Rays()
{
}

void Rays::Render(Grid &grid, Player &player) {

    glColor3f(0.5f, 0.77f, 0.9f);
    glBegin(GL_QUADS);
    glVertex2f(0, 0); // Bottom-left
    glVertex2f(640, 0); // Bottom-right
    glVertex2f(640, 320); // Top-right
    glVertex2f(0,  320); // Top-left
    glEnd();
    
    glColor3f(0.2f, 0.6f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(0, 320); // Bottom-left
    glVertex2f(640, 320); // Bottom-right
    glVertex2f(640,  640); // Top-right
    glVertex2f(0,  640); // Top-left
    glEnd();

    int r, mx, my, mp, dof;
    float rx, ry, ra, xo, yo;

    ra = player.angle - RAD * 28;
    
    if (ra < 0)
    {
        ra += 2 * PI;
    }

    if (ra > 2 * PI)
    {
        ra -= 2 * PI;
    }

    for(r = 0; r < 128; r++)
    {
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

        float disT;

        if (disV < disH) {
            rx = vx;
            ry = vy;
            disT = disV;
            glColor3f(0.8f, 0.8f, 0.8f);
        }
        if (disV > disH) {
            rx = hx;
            ry = hy;
            disT = disH;
            glColor3f(0.7f, 0.7f, 0.7f);
        }
       /* glLineWidth(3);
        glBegin(GL_LINES);
        glVertex2i(player.posX, player.posY);
        glVertex2i(rx, ry);
        glEnd();*/

        float ca=player.angle-ra;
        if (ca < 0)
        {
            ca += 2 * PI;
        }
        if (ca > 2 * PI)
        {
            ca -= 2 * PI;
        }
        disT = disT * cos(ca);
        

        float lineH = (64*640) / disT;
        
        if (lineH > 640)
        {
            lineH = 640;
        }

        float lineO = 320 - lineH / 2;
        
        glLineWidth(5);
        glBegin(GL_LINES);
        glVertex2i(r*5+3,lineO);
        glVertex2i(r*5+3,lineH+lineO);
        glEnd();

        ra += RAD * 0.5f;

        if (ra < 0)
        {
            ra += 2 * PI;
        }

        if (ra > 2 * PI)
        {
            ra -= 2 * PI;
        }
    }
}

float Rays::dist(float ax, float ay, float bx, float by)
{
    return sqrt((bx-ax) * (bx-ax) + (by-ay) *(by-ay));
}