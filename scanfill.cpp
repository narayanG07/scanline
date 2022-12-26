#include<iostream>
#include<graphics.h>
using namespace std;
void boundfill(int x,int y,int fcol,int bcol)
{
    if(getpixel(x,y)!=fcol && getpixel(x,y)!=bcol)
    {
        delay(2);
        putpixel(x,y,fcol);
        boundfill(x+1,y,fcol,bcol);
        boundfill(x,y+1,fcol,bcol);
        boundfill(x,y-1,fcol,bcol);
        boundfill(x-1,y,fcol,bcol);
    }
}

void floodfill(int x,int y,int old,int fill)
{
    int current;
    current=getpixel(x,y);
    if(current==old)
    {   delay(2);
        putpixel(x,y,2);
        floodfill(x+1,y,old,fill);    
        floodfill(x,y+1,old,fill);
        floodfill(x,y-1,old,fill);
        floodfill(x-1,y,old,fill);
    }
}
void scanline(int x1,int y1,int x2,int y2)
    {
        int x,y;
        setcolor(RED);
        rectangle(x1,y1,x2,y2);
        x=x1+1;
        y=y1+1;
        x2--;
        y2--;
        while(y2>=y)
        {
            moveto(x,y);
            lineto(x2,y);
            y++;
            delay(10);
        }
    }

int main()
{   int x1,y1,x2,y2,a,b;
    cout<<"enter the diagonal coordinates of rectangle :";
    cin>>x1>>y1>>x2>>y2;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    setcolor(4);
    rectangle(x1,y1,x2,y2);
    a=(x1+x2)/2;
    b=(y1+y2)/2;
    floodfill(a,b,0,2);
    boundfill(a,b,2,4);
    setcolor(YELLOW);
    scanline(x1,y1,x2,y2);
    getch();
    closegraph();
}
