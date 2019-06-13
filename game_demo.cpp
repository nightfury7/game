
#include "TXLib.h"


void game_ball_demo (int x1, int y1, int vx1, int vy1,
                     int x2, int y2, int vx2, int vy2,
                     int r,
                     int x3, int y3, int vx3, int vy3);

void draw_ball (int x, int y, int r, COLORREF color);

void move_ball_0 (int *x, int *y, int *vx, int *vy, int dt, int right, int left, int up, int down);

void move_ball (int *x, int *y, int *vx, int *vy, int dt);

void control_ball (int *vx, int *vy, int right, int left, int up, int down);



int main()
    {
    txCreateWindow (800, 800);

    game_ball_demo (100, 100, 2, 2,
                    200, 200, 3, 3,
                    25,
                    500, 300, 10, 10);

    //draw_ball ();

    //move_ball_0 ();

    //move_ball ();

    //control_ball ();



    return 0;
    }

void game_ball_demo (int x1, int y1, int vx1, int vy1,
                     int x2, int y2, int vx2, int vy2,
                     int r,
                     int x3, int y3, int vx3, int vy3)
{
    int dt = 1;

    while (true)
    {
        draw_ball (x1, y1, 25, TX_RED);

        move_ball (&x1, &y1, &vx1, &vy1, dt);

        control_ball (VK_RIGHT, VK_LEFT, VK_UP, VK_DOWN);



        draw_ball (x2, y2, 25, TX_BLUE);

        move_ball (&x2, &y2, &vx2, &vy2, dt);

        control_ball ('D', 'A', 'W', 'S');



        draw_ball (x3, y3, 25, TX_YELLOW);

        move_ball (&x3, &y3, &vx3, &vy3, dt);



        txSleep (20);
    }
}

void draw_ball (int x, int y, int r, COLORREF color)
{
    txSetFillColor (color);

    txSetColor (color);

    txCircle (x, y, r);
}

void move_ball_0 (int *x, int *y, int *vx, int *vy, int dt, int right, int left, int up, int down)
{

        move_ball (x, y, vx, vy, dt);

        control_ball (vx, vy, right, left, up, down);
}

void move_ball (int *x, int *y, int *vx, int *vy, int dt)
{
        *x = *x + *vx * dt;
        *y = *y + *vy * dt;


        if (*x > 800)
            *vx = - (*vx);

        if (*y > 800)
            *vy = - (*vy);

        if (*x < 0)
            *vx = - (*vx);

        if (*y < 0)
            *vy = - (*vy);
}

void control_ball (int *vx, int *vy, int right, int left, int up, int down)
{
        if (GetAsyncKeyState (right))
            (*vx)++;

        if (GetAsyncKeyState (left))
            (*vx)--;

        if (GetAsyncKeyState (up))
            (*vy)--;

        if (GetAsyncKeyState (down))
            (*vy)++;
}





