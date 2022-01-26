/***
setcolor();
sefillstyle();
floodfill();

COLOR               INT VALUES
-------------------------------
BLACK                   0
BLUE                    1
GREEN                   2
CYAN                    3
RED                     4
MAGENTA                 5
BROWN                   6
LIGHTGRAY               7
DARKGRAY                8
LIGHTBLUE               9
LIGHTGREEN             10
LIGHTCYAN              11
LIGHTRED               12
LIGHTMAGENTA           13
YELLOW                 14
WHITE                  15
***/

#include<graphics.h>
#include<stdio.h>
int main()
{
    initwindow(500,500, "Flag of Bangladesh");
    setcolor(GREEN);
    rectangle(100,104,400,300);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(250,250,GREEN);


    setcolor(RED);
    circle(240,200, 50);
    setfillstyle(SOLID_FILL,RED);
    floodfill(240,200,RED);

    getch();
}
