#include<iostream>
#include<graphics.h>
using namespace std;
int main()
{
    initwindow(1024, 700);
    circle(300, 300, 200);
    circle(200, 200, 20);
    circle(400, 200, 20);
    rectangle(290,220,310,320);
    arc(300, 300, 200, 340, 160);
    cin.get();
}
