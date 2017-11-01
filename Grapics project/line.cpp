#include "line.h"
#include <iostream>
#include <graphics.h>
#include "util.h"
#include <bits/stdc++.h>

#define PI 3.14159265

using namespace std;

int xc = 350, yc= 350;

int tx, ty, rtheta,  mx, my;
float sx, sy;


void input_transformation()
{
    int x, y;
    char s[100];
    initwindow(700, 700, "Hello graphics");
    draw_axis();
    printf("Enter the name of the file \n >");
    scanf("%s", s);

    FILE *fp = fopen(s,"r+");

    tx = 0, ty = 0;
    rtheta = 0, sx = 1, sy = 1;
    mx=1, my = 1;
    char ch;
    cout << "Do you want to translate the line ? (y/n) \n>>>" ;
    cin >> ch;
    if(ch == 'y')
    {
        cout << "Enter translation values(tx, ty)\n>>>" << endl;
        cin >> tx >> ty ;
    }

    cout << "Do you want to rotate the line ? (y/n) \n>>>" ;
    cin >> ch;
    if(ch == 'y')
    {
        cout << "Enter rotation axis(theta)\n>>>" << endl;
        cin >> rtheta;
    }

    cout << "Do you want to mirror the line ? (y/n) \n>>>" ;
    cin >> ch;
    if(ch == 'y')
    {
        cout << "Against x-axis or y-axis (x/y)\n>>>" << endl;
        cin >> ch;
        if(ch == 'x')
        {
            my = -1;
            mx = 1;
        }else if(ch == 'y')
        {
            mx = -1;
            my = 1;
        }else
        {

        }
    }

    cout << "Do you want to scale the line ? (y/n) \n>>>" ;
    cin >> ch;
    if(ch == 'y')
    {
        cout << "Enter scaling values(sx, sy)\n>>>" << endl;
        cin >> sx >> sy ;
    }


    //cout << "Enter the name of the file containing circle points";


    //printf("%s \n", s);
    while(fscanf(fp, "%d %d", &x , &y) == 2)
    {
	     //printf("%d %d", x, y);
	     //cout << x << " " << y << endl;
	     //set_pixel(x, y);
         //set_pixel_with_color(x , y , 1);
	     //set_pixel_with_color(x+30, y+30 , 2);
	     //set_pixel_with_color( (x*cos (90.0*PI/180) ) - (y * sin (PI/2.0)), (x*sin (90.0*PI/180) ) + (y * cos (PI/2.0)), 3);
	     //set_pixel_with_color(x , -y, 4);
	     //set_pixel_with_color(x*0.5, y*1.5 , 5);

         set_pixel_with_color(x , y , YELLOW);
	     set_pixel_with_color(x+tx, y+ty , 2);//translation
	     set_pixel_with_color( (x*cos (rtheta*PI/180.0) ) - (y * sin (rtheta*PI/180.0)), (x*sin (rtheta*PI/180.0) ) + (y * cos (rtheta*PI/180.0)), 3);
	     set_pixel_with_color(x*mx , y*my, 4);
	     set_pixel_with_color(x*sx, y*sy , 5);

    }

         cout << "actual line --- > YELLOW\n";
	     cout << "translated line --- > GREEN\n";
	     cout << "rotated line --- > CYAN\n";
	     cout << "mirrored line --- > RED\n";
	     cout << "scaled line --- > MAGENTA\n";

	fclose(fp);
   //delay(15000);
    getch();

    closegraph();
}

void line_draw()
{
    initwindow(700, 700, "Hello graphics");
    draw_axis();
    char st[100];
    printf("Enter the name of file(for example : line.txt) you want to save the line points . \n>>>");

    scanf("%s",st);
	FILE *fp = fopen(st , "w+");
    draw_axis();
    float x0 , y0 , x1 , y1 ;
    printf("Enter start and end points (x0,y0) and (x1, y1)\n >");
    scanf("%f %f %f %f", &x0, &y0, &x1, &y1);
    int dx, dy, d, x, y;
    int t1, t2;
    float m = slope(x0, x1, y0, y1);
    printf("%f ", m);




	if(( 0  < m && 1 >=  m)&&(x0 < x1))
	{
		    dx=x1-x0;
		    dy=y1-y0;

		    x=x0;
		    y=y0;


		    d=2*dy-dx;


			    while(x<x1)
			    {
				if(d>=0)
				{

				    set_pixel( x,y );

				    fprintf(fp, "%d %d\n",x,y);
				    //printf("%d %d\n",x, y );
				    y++;
				    d=d+2*dy-2*dx;
				}
				else
				{

				    set_pixel(x,y);
				    fprintf(fp, "%d %d\n",x,y);
				    //printf("%d %d\n",x, y );

				    d=d+2*dy;
				}
				x++;
				//delay(10);
			    }

	}else if(( 0  < m && 1 >=  m)&&(x0 > x1))
	{
            t1 = x0;
            x0 = x1;
            x1 = t1;

            t2 = y0;
            y0 = y1;
            y1 = t2;

		    dx=x1-x0;
		    dy=y1-y0;

		    x=x0;
		    y=y0;


		    d=2*dy-dx;


			    while(x < x1)
			    {
					if(d>=0)
					{

					    set_pixel( x,y );

					    fprintf(fp, "%d %d\n",x,y);
					    //printf("%d %d\n",x, y );
					    y++;
					    d=d+2*dy-2*dx;
					}
					else
					{

					    set_pixel(x,y);

					    fprintf(fp, "%d %d\n",x,y);
					    //printf("%d %d\n",x, y );
					    d=d+2*dy;
					}
					x++;
					//delay(10);
			    }

	}else if(( 0  >= m && -1 <=  m)&&(x0 < x1))
	{

			y0 = -1 * y0;
			y1 = -1 * y1;

		    dx=x1-x0;
		    dy=y1-y0;

		    x=x0;
		    y=y0;


		    d=2*dy-dx;


			    while(x < x1)
			    {

					if(d>=0)
					{

					    set_pixel( x,-y );

					    fprintf(fp, "%d %d\n",x,-y);
					    //printf("%d %d\n",x, y );
					    y++;
					    d=d+2*dy-2*dx;
					}
					else
					{

					    set_pixel(x,-y);

					    fprintf(fp, "%d %d\n",x,-y);
					    //printf("%d %d\n",x, y );
					    d=d+2*dy;
					}
					x++;
					//delay(10);
			    }

	}else if(( 0  >= m && -1 <=  m)&&(x0 > x1))
	{
			t1 = x0;
            x0 = x1;
            x1 = t1;

            t2 = y0;
            y0 = y1;
            y1 = t2;

			y0 = -1 * y0;
			y1 = -1 * y1;

		    dx=x1-x0;
		    dy=y1-y0;

		    x=x0;
		    y=y0;


		    d=2*dy-dx;


			    while(x < x1)
			    {

					if(d>=0)
					{

					    set_pixel( x,-y );

					    fprintf(fp, "%d %d\n",x,-y);
					    //printf("%d %d\n",x, y );
					    y++;
					    d=d+2*dy-2*dx;
					}
					else
					{

					    set_pixel(x,-y);

					    fprintf(fp, "%d %d\n",x,-y);
					    //printf("%d %d\n",x, y );
					    d=d+2*dy;
					}
					x++;
					//delay(10);
			    }

	}else if( m > 1 && y0 < y1)
	{



		    dy=x1-x0;
		    dx=y1-y0;

		    x=x0;
		    y=y0;


		    d=2*dy-dx;


			    while(y < y1)
			    {

					if(d>=0)
					{

					    set_pixel( x, y );

					    fprintf(fp, "%d %d\n", x , y );
					    //printf("%d %d\n",x, y );
					    x++;
					    d=d+2*dy-2*dx;
					}
					else
					{

					    set_pixel(x ,y);

					    fprintf(fp, "%d %d\n",x,y);
					    //printf("%d %d\n",x, y );
					    d=d+2*dy;
					}
					y++;
					//delay(10);
			    }

	}else if( m > 1 && y0 > y1)
	{

            t1 = x0;
            x0 = x1;
            x1 = t1;

            t2 = y0;
            y0 = y1;
            y1 = t2;


		    dy=x1-x0;
		    dx=y1-y0;

		    x=x0;
		    y=y0;


		    d=2*dy-dx;


			    while(y < y1)
			    {

					if(d>=0)
					{

					    set_pixel( x, y );

					    fprintf(fp, "%d %d\n", x , y );
					    //printf("%d %d\n",x, y );
					    x++;
					    d=d+2*dy-2*dx;
					}
					else
					{

					    set_pixel(x ,y);

					    fprintf(fp, "%d %d\n",x,y);
					    //printf("%d %d\n",x, y );
					    d=d+2*dy;
					}
					y++;
					//delay(10);
			    }

	}else if( m < -1 && y0 > y1)
	{

		    y0 = -1 * y0;
		    y1 = -1 * y1;


		    dy=x1-x0;
		    dx=y1-y0;

		    x=x0;
		    y=y0;


		    d=2*dy-dx;


			    while(y < y1)
			    {

					if(d>=0)
					{

					    set_pixel( x, -y );

					    fprintf(fp, "%d %d\n", x , -y );
					    //printf("%d %d\n",x, y );
					    x++;
					    d=d+2*dy-2*dx;
					}
					else
					{

					    set_pixel(x ,-y);

					    fprintf(fp, "%d %d\n",x,-y);
					    //printf("%d %d\n",x, y );
					    d=d+2*dy;
					}
					y++;
					//delay(10);
			    }

	}else if( m < -1 && y0 < y1)
	{
	        t1 = x0;
            x0 = x1;
            x1 = t1;

            t2 = y0;
            y0 = y1;
            y1 = t2;

		    y0 = -1 * y0;
		    y1 = -1 * y1;


		    dy=x1-x0;
		    dx=y1-y0;

		    x=x0;
		    y=y0;


		    d=2*dy-dx;


			    while(y < y1)
			    {

					if(d>=0)
					{

					    set_pixel( x, -y );

					    fprintf(fp, "%d %d\n", x , -y );
					    //printf("%d %d\n",x, y );
					    x++;
					    d=d+2*dy-2*dx;
					}
					else
					{

					    set_pixel(x ,-y);

					    fprintf(fp, "%d %d\n",x,-y);
					    //printf("%d %d\n",x, y );
					    d=d+2*dy;
					}
					y++;
					//delay(10);
			    }

	}
	fclose(fp);

	getch();
    closegraph();

}
void line_from_file()
{
	int x, y;
    char s[100];
    initwindow(700, 700, "Hello graphics");
    draw_axis();
    //cout << "Enter the name of the file containing circle points";
    printf("Enter the name of the file \n >");
    scanf("%s", s);

    FILE *fp = fopen(s,"r+");


    //printf("%s \n", s);
    while(fscanf(fp, "%d %d", &x , &y) == 2)
    {
	     //printf("%d %d", x, y);
	     //cout << x << " " << y << endl;
	     //set_pixel(x, y);
         //set_pixel_with_color(x , y , 1);
	     //set_pixel_with_color(x+30, y+30 , 2);
	     //set_pixel_with_color( (x*cos (90.0*PI/180) ) - (y * sin (PI/2.0)), (x*sin (90.0*PI/180) ) + (y * cos (PI/2.0)), 3);
	     //set_pixel_with_color(x , -y, 4);
	     //set_pixel_with_color(x*0.5, y*1.5 , 5);

         set_pixel_with_color(x , y , 1);
	     set_pixel_with_color(x+tx, y+ty , 2);//translation
	     set_pixel_with_color( (x*cos (rtheta*PI/180.0) ) - (y * sin (rtheta*PI/180.0)), (x*sin (rtheta*PI/180.0) ) + (y * cos (rtheta*PI/180.0)), 3);
	     set_pixel_with_color(x*mx , y*my, 4);
	     set_pixel_with_color(x*sx, y*sy , 5);


    }
         cout << "actual line --- > BLUE\n";
	     cout << "translated line --- > GREEN\n";
	     cout << "rotated line --- > CYAN\n";
	     cout << "mirrored line --- > RED\n";
	     cout << "scaled line --- > MAGENTA\n";


	fclose(fp);
	getch();
   //delay(15000);
    closegraph();
}


