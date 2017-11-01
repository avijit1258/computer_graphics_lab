#include <iostream>
#include <bits/stdc++.h>
#include "line.h"
#include "cohen-shutherland.h"
#include "circle.h"

using namespace std;

void display();

int main()
{
    //cout << "Hello world!" << endl;
    //print();
    //line_clip();
    display();
    return 0;
}

void display(){
    printf("Welcome to Computer Graphics World:\n");
    while(1)
    {
        char n;
        char in;



   here :

        printf("\n 1:Line \n 2:Circle\n E:Exit\n");
        scanf(" %c",&n);
            if(n!='1'&&n!='2'&&n!='E'){

                    printf("Enter a valid input");
                    goto here;

            }


        if(n=='1')
        {
            jump:
            printf("---->1:Line Draw \n---->2:Line Draw from file\n---->3:Line Transformation\n--->4:Cohen-shuterland\n5:Back\n");
            scanf(" %c",&in);


            if(in!='1'&&in!='2'&&in!='3'&&in!='B'&&in!='4'){

                    printf("Enter a valid input\n");
                    goto jump;

            }

            if(in=='1')
            {
                line_draw();
                goto jump;
            }
            else if (in=='2')
            {
                line_from_file();
                goto jump;

            }
            else if(in=='3')
            {
                input_transformation();
                goto jump;

            }else if(in == '4')
            {
                line_clip();
                goto jump;
            }

            else if(in=='B')
            {

                goto here;
            }


        }
        else if (n=='2')
        {
            pump:
            printf("\n---->1:Circle Draw \n---->2:Circle Draw from file\n---->3:Circle Transformation\n---->B:Main Menu\n");
            scanf(" %c",&in);

            if(in!='1'&&in!='2'&&in!='B' && in!='3'){

                goto pump;

            }

            if (in=='1')
            {
                circle_draw();
                goto pump;

            }
            else if(in=='2')
            {
                circle_from_file();
                goto pump;

            }
            else if(in =='3')
            {
                input_circle_transformation();
                goto pump;
            }

            else if(in=='B')
            {

                goto here;
            }


        }else if (n=='E')
        {
            break;
        }


    }
    printf("\n");
}


