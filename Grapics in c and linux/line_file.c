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
    
   
   
   int x, y;
   char s[100];

   //cout << "Enter the name of the file containing circle points";
   scanf("%s", s);

   FILE *fp = fopen(s,"r+");

   int gd = DETECT, gm;
   initgraph(&gd, &gm, "Welcome to Circle draw with Bressenhams");
   //printf("%s \n", s);
   while(fscanf(fp, "%d %d", &x , &y) == 2) 
   {
	//printf("%d %d", x, y);
	putpixel(x, y, GREEN);

    }
   
   
   //delay(15000);
   wait_for_char();
   closegraph();

   return 0;

}
