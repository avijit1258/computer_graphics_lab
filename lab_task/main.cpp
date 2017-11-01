#include <graphics.h>
#include <bits/stdc++.h>

#define PI 3.14159265

using namespace std;

int xc = 350, yc= 350;

int tx, ty, rtheta,  mx, my;
float sx, sy;

void set_pixel(int a, int b);
void line_draw(float x0, float y0, float x1, float y1, char str[]);
void line_from_file();
void display();
void circle_draw();
void circle_from_file();
void rectangle1();

float slope(float x1, float x2, float  y1, float  y2)
{

	return (y2 - y1)/(x2 - x1);


}

void set_pixel_with_color(int a, int b, int c)
{

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



void line_from_file(char s[])
{
	int x, y;
    //char s[100];
    //initwindow(700, 700, "Hello graphics");
    //draw_axis();
    //cout << "Enter the name of the file containing circle points";
    //printf("Enter the name of the file \n >");
    //scanf("%s", s);

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

         set_pixel_with_color(x , y , 9);
	     set_pixel_with_color(x+tx, y+ty , 2);//translation
	     set_pixel_with_color( (x*cos (rtheta*PI/180.0) ) - (y * sin (rtheta*PI/180.0)), (x*sin (rtheta*PI/180.0) ) + (y * cos (rtheta*PI/180.0)), 3);
	     set_pixel_with_color(x*mx , y*my, YELLOW);
	     set_pixel_with_color(x*sx, y*sy , 15);


    }
         cout << "actual line --- > BLUE\n";
	     cout << "translated line --- > GREEN\n";
	     cout << "rotated line --- > CYAN\n";
	     cout << "mirrored line --- > RED\n";
	     cout << "scaled line --- > MAGENTA\n";


	fclose(fp);
	//getch();
   //delay(15000);
    //closegraph();
}

void rect_from_file()
{
    initwindow(700, 700, "Hello graphics");
    draw_axis();

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
        cout << "Enter translation values(sx, sy)\n>>>" << endl;
        cin >> sx >> sy ;
    }


	line_from_file("a.txt");
	line_from_file("b.txt");
    line_from_file("c.txt");
	line_from_file("d.txt");

	getch();
   //delay(15000);
    closegraph();
}

int main()
{
    //int gdriver = EGA, gmode = EGAHI, errorcode;
    //initwindow(700, 700, "Hello graphics");
    //initgraph(&gdriver, &gmode, "");
    //settextstyle(SMALL_FONT, HORIZ_DIR , 4);

    //draw_axis();
    //display();
    rectangle1();
    //input_transformation();
    rect_from_file();
    //line_draw();
    //line_from_file();
    //input_transformation();
    //getch();
    //closegraph();
    return 0;
}



void set_pixel(int a, int b)
{

	//putpixel(xc+a, yc-b, GREEN);
	//cout << xc+a << " " << yc-b << endl;
	//cout << a << " " << b << endl;


}

void circle_draw()
{
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

void rectangle1()
{
    float x0, y0, x2, y2;

    printf("Enter start and end points of diagonal(x0,y0) and (x2, y2)\n >");
    scanf("%f %f %f %f", &x0, &y0, &x2, &y2);
    //initwindow(700, 700, "Hello graphics");
    //draw_axis();
    line_draw(x0,y0, x0, y2, "a.txt");
    line_draw(x0,y0, x2, y0, "b.txt");
    line_draw(x2,y0, x2, y2, "c.txt");
    line_draw(x0,y2, x2, y2, "d.txt");
    //getch();
    //closegraph();
}

void line_draw(float x0,float y0 , float x1, float y1 , char str[])
{

    char st[100];
    //printf("Enter the name of file(for example : line.txt) you want to save the line points . \n>>>");

    //scanf("%s",st);
	FILE *fp = fopen(str , "w+");
    //draw_axis();
    //float x0 , y0 , x1 , y1 ;

    int dx, dy, d, x, y;
    int t1, t2;
    float m = slope(x0, x1, y0, y1);
    //printf("%f ", m);




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

	//getch();
    //closegraph();

}


