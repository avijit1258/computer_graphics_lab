#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;



float slope(float x1, float x2, float  y1, float  y2)
{

	return (y2 - y1)/(x2 - x1);


}
void set_pixel(int a, int b)
{
    int xc = 350, yc= 350;
	putpixel(xc+a, yc-b, GREEN);
	//cout << xc+a << " " << yc-b << endl;
	//cout << a << " " << b << endl;


}

void set_pixel_c(int a, int b, int c)
{
    //int xc = 350, yc= 350;
	putpixel(a, b, c);
	//cout << xc+a << " " << yc-b << endl;
	//cout << a << " " << b << endl;


}

void set_pixel_with_color(int a, int b, int c)
{
    int xc = 350, yc= 350;

	putpixel(xc+a, yc-b, c);


}
void draw_axis()
{

	    //initgraph(&gd,&gm,NULL);
	    //initwindow(640, 480, "Hello graphics");
        //setbkcolor(15);

        setcolor(CYAN);
        line(350, 1 , 350 , 700 );
        setcolor(CYAN);
        line(1, 350, 700 , 350);
        int t = 70;
        setcolor(RED);
        for(int i = 1 ; i <= 10 ; i++)
        {
            if(i != 5)
            {
                line(t,1, t, 700);
                line(1, t, 700, t);
            }

            t = t + 70;
        }

        int t1 = 10;
        setcolor(BLUE);
        for(int i = 1 ; i <= 70 ; i++)
        {
                if(t1 % 70 != 0)
                {
                        line(t1,1, t1, 700);
                        line(1, t1, 700, t1);

                }


            t1 = t1 + 10;
        }
        //setbkcolor(WHITE);

		//line()


}
