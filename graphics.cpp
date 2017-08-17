#include<graphics.h>
#include<stdio.h>
#include<iostream>
#include<conio.h>

int main()
{
    FILE *fp = fopen("Line_points.txt", "a");
    initwindow(800,800,"Line Generating Program");

    int x0 = 112, y0 = 14, x1 = 456, y1 = 789;

    int dx, dy, p, x, y;

    dx=x1-x0;
    dy=y1-y0;

    x=x0;
    y=y0;

    p=2*dy-dx;

    while(x<x1)
    {
        if(p>=0)
        {
            putpixel(x,y,GREEN);
            fprintf(fp, "%d %d\n",x,y);
            y=y+1;
            p=p+2*dy-2*dx;
        }
        else
        {
            putpixel(x,y,GREEN);
            fprintf(fp, "%d %d\n",x,y);
            p=p+2*dy;
        }
        x=x+1;
    }
    getch();
    return 0;
}
