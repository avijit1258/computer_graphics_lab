#include <stdio.h>
#include <graphics.h>


void wait_for_char()
{

   int in = 0;
   while(in == 0){

        in = getchar();
   }
}

int main()
{
   FILE *fp = fopen("cp.txt","w+"); 
   
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "Welcome to Circle draw with Bressenhams");
   int r ;
   
   scanf("%d", &r);


   int x = 0, y = r, d = 3 - 2*r;
   int xc = 320 , yc = 225;
   
   
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
   delay(15000);
   wait_for_char();
   closegraph();

    return 0;

}
