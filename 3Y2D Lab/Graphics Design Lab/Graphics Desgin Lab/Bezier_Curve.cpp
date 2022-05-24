#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

int main(){
    freopen("input.txt", "r", stdin);
    int gd = DETECT, gm;
    int x[4], y[4], i;

    initgraph(&gd,&gm,(char*)"");

     for(i=0; i<4;i++)
    {
        printf("[%d]Enter the x & y coordinates of the 4 coordinates: ",i+1);
        scanf("%d%d",&x[i],&y[i]);
        putpixel(x[i],y[i],3);
    }

    for(double t = 0.0; t <= 1.0; t+= 0.0005){
        double xt = pow(1-t,3)*x[0] + 3*t*pow(1-t,2)*x[1] + 3*t*t*pow(1-t,1)*x[2] + pow(t,3)*x[3];
        double yt = pow(1-t,3)*y[0] + 3*t*pow(1-t,2)*y[1] + 3*t*t*pow(1-t,1)*y[2] + pow(t,3)*y[3];
        putpixel(xt,yt,WHITE);
    }

    getch();
    closegraph();

    return 0;
}
