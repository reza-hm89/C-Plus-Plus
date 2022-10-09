#include<graphics.h>
#include<conio.h>
void main()
{       int driver=DETECT,mode;
	int c=15,x=0,y=0,a[8][8];
	clrscr();
	initgraph(&driver,&mode,"c:\\tc\\bgi");
	setbkcolor(0);
	setcolor(c);
	setfillstyle(1,c);
	int rook[44]={50+x,50+y,55+x,50+y,55+x,55+y,60+x,55+y,60+x,50+y
	,65+x,50+y,65+x,55+y,70+x,55+y,70+x,50+y,
	70+x,50,75+x,50,75+x,60,68+x,65,68+x,75,73+x,78,73+x,
	80,52+x,80,52+x,78,57+x,75,57+x,65,50+x,60,50+x,50};
	drawpoly(22,rook);
	fillpoly(22,rook);
	getch();
}