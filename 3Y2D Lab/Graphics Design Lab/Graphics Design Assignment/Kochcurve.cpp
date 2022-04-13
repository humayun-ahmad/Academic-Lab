/***
Assignment 06: Koch Curve(fractal)
***/
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
using namespace std;

void koch(int x1,int y1,int x2,int y2,int it)
{
    float angle = 60*3.1416/180;
    int x3 = (2*x1+x2)/3;
    int y3 = (2*y1+y2)/3;

    int x4 = (x1+2*x2)/3;
    int y4 = (y1+2*y2)/3;

    int x = x3+(x4-x3)*cos(angle)+(y4-y3)*sin(angle);
    int y = y3-(x4-x3)*sin(angle)+(y4-y3)*cos(angle);

    if(it>0)
    {
        koch(x1,y1,x3,y3,it-1);
        koch(x3,y3,x,y,it-1);
        koch(x,y,x4,y4,it-1);
        koch(x4,y4,x2,y2,it-1);
    }
    else{
        line(x1,y1,x3,y3);
        line(x3,y3,x,y);
        line(x,y,x4,y4);
        line(x4,y4,x2,y2);
    }
}

int main(void)
{
    int gd = DETECT,gm;
    int x1, y1, x2, y2;
    printf("Enter the value of x1, y1: ");
    scanf("%d%d",&x1,&y1);
    printf("Enter the value of x2, y2: ");
    scanf("%d%d",&x2,&y2);
    initgraph(&gd,&gm,(char*)"");
    koch(x1,y1,x2,y2,2);
    getch();
    closegraph();
    return 0;

}

