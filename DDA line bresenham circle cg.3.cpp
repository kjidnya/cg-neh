#include <iostream>
#include <graphics.h>
using namespace std;

class DDA
{
	int x1,y1,x2,y2;
	public:
	DDA(int xx1,int yy1,int xx2,int yy2)
	{
		x1=xx1;
		y1=yy1;
		x2=xx2;
		y2=yy2;
	}
	void read(){
		cout <<"Enter x and y coordinates of start point:: ";
		cin >> x1>> y1;
		cout <<"Enter x and y coordinates of end point:: ";
		cin >> x2>> y2;
	}
	void drawline();
};
void DDA::drawline()
{
	float dx = x2-x1;
	float dy = y2-y1;

	float length;
	if ( abs(dx) >= abs(dy) )
		length = abs(dx);
	else
		length = abs(dy);

	float xi = dx/length;
	float yi = dy/length;

	float x = x1;
	float y = y1;
	for(int i=1;i<=length;i++)
	{
		putpixel(x,y,RED);
		x += xi;
		y += yi;
	}
}
class brcircle
{
	int r,xc,yc;
public:
	brcircle(int rr,int x1, int y1)
	{
		r = rr;
		xc= x1;
		yc= y1;
	}
	void read()
	{
		cout <<"Enter the radius: ";
		cin >> r;
		cout <<"Enter the x and y coordinates: ";
		cin >> xc>>yc;
	}
	void drawCircle();
	void plot8WaySymmetry(int,int);
};

void brcircle :: plot8WaySymmetry(int x,int y)
{
	putpixel(x+xc,y+yc,RED);
	putpixel(y+yc,x+xc,RED);
	putpixel(xc-x,y+yc,RED);
	putpixel(y+yc,xc-x,RED);
	putpixel(x+xc,yc-y,RED);
	putpixel(yc-y,x+xc,RED);
	putpixel(xc-x,yc-y,RED);
	putpixel(yc-y,xc-x,RED);
}
void brcircle::drawCircle(){
	int x=0,y=r;
	int S = 3 - 2*r;
	putpixel(xc,yc,RED);
	while(x<=y){
		if (S<=0){
			S = S+4*x+6;
			x++;

		}
		else{
			S = S +4*(x-y)+10;
			x++;
			y--;
		}

		plot8WaySymmetry(x,y);

	}
}

int main()
{
	
	int gd = DETECT, gm;
	initgraph(&gd,&gm,NULL);
	// To draw first shape
	brcircle ci(90,160,160),co(140,160,160);
	DDA l1(74,210,160,60),l2(246,210,160,60),l3(246,210,70,210);
	ci.drawCircle();
	co.drawCircle();
	l1.drawline();
	l2.drawline();
	l3.drawline();
	getch();
	closegraph();
	return 0;
}
