
#include "TXLib.h"

void game_ball_demo (int x1, int y1, int vx1, int vy1,
                     int x2, int y2, int vx2, int vy2,
                     int r,
                     int x3, int y3, int vx3, int vy3,
                     int x4, int y4, int vx4, int vy4);

void draw_ball (int x, int y, int r, COLORREF color);

void draw_ball3d (int x, int y, int r);

void draw_ball_demo (int x, int y, int rmax, int red0, double vred, int green0, int vgreen, int blue0, int vblue);

void move_ball_0 (int *x, int *y, int *vx, int *vy, int dt, int right, int left, int up, int down);

void move_ball (int *x, int *y, int *vx, int *vy, int dt);

void control_ball (int *vx, int *vy, int right, int left, int up, int down);

double dist (int x1, int x2, int y1, int y2);



int main()
    {
    txCreateWindow (800, 800);
    //x1 = rand() % 800;
    //y1 = rand() % 800;
    //x2 = rand() % 800;
    //y2 = rand() % 800;

    //srand (time (0)); полный рандом старая версия

    //DRY

    game_ball_demo (500, 200, 2, 2,
                    100, 200, 3, 3,
                    25,
                    rand () % 800, rand () % 800, 10, 10,
                    rand () % 800, rand () % 800, 10, 10);

    //draw_ball ();

    //draw_ball3d ();

    //draw_ball_demo

    //move_ball_0 ();

    //move_ball ();

    //control_ball ();

    //dist ();



    return 0;
    }

void game_ball_demo (int x1, int y1, int vx1, int vy1,
                     int x2, int y2, int vx2, int vy2,
                     int r,
                     int x3, int y3, int vx3, int vy3,
                     int x4, int y4, int vx4, int vy4)
{
    int dt = 1;

    while (true)
    {
        draw_ball_demo (x1, y1, 20, 35, 2.2, 35, 2.2, 0, 2.2);

        move_ball (&x1, &y1, &vx1, &vy1, dt);

        control_ball (&vx1, &vy1, VK_RIGHT, VK_LEFT, VK_UP, VK_DOWN);



        draw_ball_demo (x2, y2, 20, 35, 2.2, 35, 2.2, 0, 2.2);

        move_ball (&x2, &y2, &vx2, &vy2, dt);

        control_ball (&vx2, &vy2, 'D', 'A', 'W', 'S');



        draw_ball_demo (x3, y3, 20, 50, 2.2, 0, 2.2, 0, 2.2);

        move_ball (&x3, &y3, &vx3, &vy3, dt);



        draw_ball_demo (x4, y4, 20, 50, 2.2, 0, 2.2, 0, 2.2);

        move_ball (&x4, &y4, &vx4, &vy4, dt);




        int dist13 = dist (x3, x1, y3, y1);

        int dist14 = dist (x4, x1, y4, y1);

        int dist23 = dist (x3, x2, y3, y2);

        int dist24 = dist (x4, x2, y4, y2);


        if (dist13 < 30 || dist14 < 30 || dist23 < 30 || dist24 < 30)
        {
            txMessageBox ("Габелла");

            break;
        }


        txSleep (5);
    }
}

void draw_ball (int x, int y, int r, COLORREF color)
{
    txSetFillColor (color);

    txSetColor (color);

    txCircle (x, y, r);
}

void draw_ball3d (int x, int y, int r)
{
    int red = 50;

    int vr = 130;

    int dt = 1;

    while (r > 0)
    {

        draw_ball (x, y, r, RGB (red, 0, 0));

        red++;

        vr--;

        r = vr*dt;
    }

}

void draw_ball_demo (int x, int y, int rmax, int red0, double vred, int green0, int vgreen, int blue0, int vblue)
{
    double t = 0;



    while (t <= 100)
    {
        draw_ball (x - 0.015 * t, y - 0.015 * t, rmax - (rmax / 100.0) * t, RGB (red0 + vred * t, green0 + vgreen * t, blue0 + vblue * t));//red = 35..255; vred = (255-35)/100.0 = 2.2; x = x0 + vx * t

        t = t + 10;
    }

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

double dist (int x1, int x2, int y1, int y2)
{

  return  sqrt ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

}







