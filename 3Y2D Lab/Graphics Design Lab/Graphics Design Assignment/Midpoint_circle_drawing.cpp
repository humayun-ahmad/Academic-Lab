/***
Assignment 02: Midpoint Circle Drawing
***/
#include<stdio.h>
#include<conio.h>
#include<graphics.h>

int main()
{
    int gd = DETECT,gm;
    int x,y,xc,yc,r,p;
    printf("Input center of the circle: ");
    scanf("%d%d",&xc,&yc);
    printf("Input radius of the circle: ");
    scanf("%d",&r);
    initgraph(&gd,&gm,(char*)"");
    p = 1-r;
    x = 0;
    y = r;

    while(x<=y)
    {
    putpixel(x+xc,y+yc,WHITE);
    putpixel(x+xc,-y+yc,WHITE);
    putpixel(-x+xc,-y+yc,WHITE);
    putpixel(-x+xc,y+yc,WHITE);
    putpixel(y+xc,x+yc,WHITE);
    putpixel(y+xc,-x+yc,WHITE);
    putpixel(-y+xc,-x+yc,WHITE);
    putpixel(-y+xc,x+yc,WHITE);

    if(p<0)
    {
        x = x+1;
        p = p+2*x+3;
    }
    else{
        x = x+1;
        y = y-1;
        p = p+2*(x-y)+5;
    }
    }
    getch();
    closegraph;
    return 0;
}
