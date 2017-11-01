#include <graphics.h>
#include <bits/stdc++.h>
#include "util.h"

#define PI 3.14159265

using namespace std;


void circle_draw()
{
    int xc = 350, yc= 350;

    initwindow(700, 700, "Hello graphics");
    draw_axis();
    char s[100];
    printf("Enter the name of the file \n >");
    scanf("%s", s);

    FILE *fp = fopen(s,"w+");
    int r;
    cout << "Enter radius of the circle. \n>>>" << endl;
    scanf("%d", &r);


   int x = 0, y = r, d = 3 - 2*r;
   //int xc = 320 , yc = 225;


   while(x <= y)
   {
	putpixel(xc+x,yc+y, GREEN);
  	putpixel(xc+y,yc+x, GREEN);
    putpixel(xc-x,yc+y, GREEN);
	putpixel(xc+x,yc-y, GREEN);
	putpixel(xc-y ,yc+x, GREEN);
	putpixel(xc+y,yc-x, GREEN);
	putpixel(xc-x,yc-y, GREEN);
	putpixel(xc-y, yc-x, GREEN);

    fprintf(fp, "%d %d\n", xc+x,yc+y);
	fprintf(fp, "%d %d\n", xc+y,yc+x);
	fprintf(fp, "%d %d\n", xc-x,yc+y);
	fprintf(fp, "%d %d\n", xc+x,yc-y);
	fprintf(fp, "%d %d\n", xc-y,yc+x);
	fprintf(fp, "%d %d\n", xc+y,yc-x);
	fprintf(fp, "%d %d\n", xc-x,yc-y);
	fprintf(fp, "%d %d\n", xc-y, yc-x);
        //delay(100);
        if(d < 0)
	    d = d + 4 * x + 6;
        else
        {
	    d = d + 4 * (x - y) + 10;
	    y--;
        }
        x++;


   }
    fclose(fp);
    getch();
    closegraph();
}

void circle_from_file()
{
    initwindow(700, 700, "Hello graphics");
    draw_axis();
    int x, y;
    char s[100];
    printf("Enter the name of the file \n >");
    scanf("%s", s);

    FILE *fp = fopen(s,"r+");

    while(fscanf(fp, "%d %d", &x , &y) == 2)
   {
	//printf("%d %d", x, y);
	putpixel(x, y, GREEN);

    }
    fclose(fp);
    getch();
    closegraph();
}

void input_circle_transformation()
{
    int tx, ty, rtheta,  mx, my;
    float sx, sy;
    int xc=350, yc = 350;
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
    /*
    cout << "Do you want to rotate the line ? (y/n) \n>>>" ;
    cin >> ch;
    if(ch == 'y')
    {
        cout << "Enter rotation axis(theta)\n>>>" << endl;
        cin >> rtheta;
    }
    */
    /*
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
    }*/

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

         set_pixel_c(x , y , YELLOW);
	     set_pixel_c(x+tx, y+ty , 2);//translation
	     //set_pixel_c( (x*cos (rtheta*PI/180.0) ) - (y * sin (rtheta*PI/180.0)), (x*sin (rtheta*PI/180.0) ) + (y * cos (rtheta*PI/180.0)), 3);
	     //set_pixel_c(x*mx , y*my, 4);
	     set_pixel_c(x*sx, y*sy , 15);

    }

         cout << "actual line --- > YELLOW\n";
	     cout << "translated line --- > GREEN\n";
	     //cout << "rotated line --- > CYAN\n";
	     //cout << "mirrored line --- > RED\n";
	     cout << "scaled line --- > MAGENTA\n";

	fclose(fp);
   //delay(15000);
    getch();

    closegraph();
}

