#include <graphics.h>
#include <bits/stdc++.h>

#define PI 3.14159265

using namespace std;

int xc = 320, yc= 240;


void set_pixel(int a, int b);
void line_draw();


float slope(float x1, float x2, float  y1, float  y2)
{

	return (y2 - y1)/(x2 - x1);


}

void draw_axis()
{

	    //initgraph(&gd,&gm,NULL);
	    //initwindow(640, 480, "Hello graphics");


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
        setbkcolor(WHITE);

		//line()


}


void line_from_file()
{
	int x, y;
    char s[100];

    //cout << "Enter the name of the file containing circle points";
    printf("Enter the name of the file \n >");
    scanf("%s", s);

    FILE *fp = fopen(s,"r+");


    //printf("%s \n", s);
    while(fscanf(fp, "%d %d", &x , &y) == 2)
    {
	     //printf("%d %d", x, y);

	     set_pixel(x+30, y+30);
	     set_pixel( (x*cos (90.0*PI/180) ) - (y * sin (PI/2.0)), (x*sin (90.0*PI/180) ) + (y * cos (PI/2.0)));

    }

	fclose(fp);
   //delay(15000);

}

int main()
{
    initwindow(700, 700, "Hello graphics");
    settextstyle(SMALL_FONT, HORIZ_DIR , 4);
    draw_axis();
    line_draw();
    line_from_file();
    getch();
    closegraph();
    return 0;
}
void set_pixel(int a, int b)
{

	putpixel(xc+a, yc-b, GREEN);


}

void line_draw()
{
	FILE *fp = fopen("lp.txt", "w+");



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


}


