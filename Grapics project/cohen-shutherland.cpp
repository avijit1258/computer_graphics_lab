#include <graphics.h>
#include <bits/stdc++.h>
#include "util.h"

using namespace std;

int LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8;
int x_left, y_low , x_right, y_high;

int region_code(int x,int y){
	int code = 0;

	if(y > y_high) code |=TOP;
	if(y < y_low) code |=BOTTOM;
	if(x < x_left) code |=LEFT;
	if(x > x_right) code |=RIGHT;
	return code;
}


void line_clip()
{
    int xc=350, yc = 350;
    char choice;
    initwindow(700,700,"hello");
    draw_axis();
    setcolor(15);
	cout<<"Enter bottom left and top right co-ordinates of window: ";
	cin>>x_left>>y_low>>x_right>>y_high;
	rectangle(xc+x_left,yc-y_low,xc+x_right,yc-y_high);
	while(1)
    {

        setcolor(15);
        int x1,y1,x2,y2;
        cout<<"Enter the endpoints of the line: ";
        cin>>x1>>y1>>x2>>y2;
        line(xc+x1,yc-y1,xc+x2,yc-y2);
        getch();

        while(1){
            int bits1=region_code(x1,y1), bits2=region_code(x2,y2);
            int accept = 0;

            float m =(float)(y2-y1)/(x2-x1);

            if(bits1==0 && bits2==0){
                accept = 1;
                break;
            }

            else if((bits1 & bits2)!=0){
                break;
            }else{
                int x,y;
                int temp;

                if(bits1==0)
                    temp = bits2;
                else
                    temp = bits1;

                if(temp & TOP){
                    x = x1+ (y_high-y1)/m;
                    y = y_high;
                }
                else if(temp & BOTTOM){
                    x = x1+ (y_low-y1)/m;
                    y = y_low;
                }else if(temp & LEFT){
                    x = x_left;
                    y = y1+ m*(x_left-x1);
                }else if(temp & RIGHT){ 	//Line clips right edge
                    x = x_right;
                    y = y1+ m*(x_right-x1);
                }

                if(temp == bits1){
                    x1 = x;
                    y1 = y;
                    bits1 = region_code(x1,y1);
                }else{
                    x2 = x;
                    y2 = y;
                    bits2 = region_code(x2,y2);
                }
            }
        }
        setcolor(CYAN);
        cout<<"After clipping:";
        if(accept)
            line(xc+x1,yc-y1,xc+x2,yc-y2);

        cout << "Will you want another line to clip ? (y/n)" << endl;
        cin >> choice;
        if(choice == 'n')
            break;
    }

	getch();
	closegraph();

}
