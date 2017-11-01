#include<graphics.h>
#include<stdio.h>

int xc = 320, yc= 240;
int gd = DETECT,gm ;



void wait_for_char()
{

   int in = 0;
   while(in == 0){

        in = getchar();
   }
}

void set_pixel(int a, int b)
{

	putpixel(xc+a, yc-b, GREEN);
	

}

float slope(float x1, float x2, float  y1, float  y2)
{
	
	return (y2 - y1)/(x2 - x1);


}

void draw_axis()
{

	    initgraph(&gd,&gm,NULL);
            int f = 0;
	    for(f = 0 ; f < 480 ; f++)
		{
			if(f % 20 == 0 )
		        	 putpixel(xc, f, CYAN);
			else
				putpixel(xc, f, RED);	
			
		}
                for(f = 0 ; f < 640 ; f++)
                {
			if(f % 20 == 0 )
		        	 putpixel(f , yc, CYAN);
			else
				putpixel(f, yc, RED);	
			
		}
}


int main()
{
    FILE *fp = fopen("lp.txt", "w+");
    
    
   
    float x0 , y0 , x1 , y1 ;
    printf("Enter start and end points (x0,y0) and (x1, y1)");
    scanf("%f %f %f %f", &x0, &y0, &x1, &y1);
    int dx, dy, d, x, y;
    int t1, t2;
    float m = slope(x0, x1, y0, y1);
    printf("%f ", m);
    draw_axis();



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
					    
					    fprintf(fp, "%d %d\n", x , y );
					    //printf("%d %d\n",x, y );
					    x++;
					    d=d+2*dy-2*dx;
					}
					else
					{
					    
					    set_pixel(x ,-y);
					    
					    fprintf(fp, "%d %d\n",x,y);
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
					    
					    fprintf(fp, "%d %d\n", x , y );
					    //printf("%d %d\n",x, y );
					    x++;
					    d=d+2*dy-2*dx;
					}
					else
					{
					    
					    set_pixel(x ,-y);
					    
					    fprintf(fp, "%d %d\n",x,y);
					    //printf("%d %d\n",x, y );
					    d=d+2*dy;
					}
					y++;
					//delay(10);
			    }

	}
      
    wait_for_char();
    closegraph();
    return 0;
}

