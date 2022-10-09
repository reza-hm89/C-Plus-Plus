#include<graphics.h>
#include<conio.h>
void main()
{
	int i, driver=DETECT,mode;
	clrscr();
	initgraph(&driver,&mode,"c:\\tc\\bgi");
	setbkcolor(0);
	setfillstyle(1,15);
	fillellipse(55,27,4,4);
	fillellipse(55,41,8,10);
	line(45,50,65,50);
	line(45,52,65,52);
	int fill[18]={50,50,60,50,60,70,70,75,70,80
	,40,80,40,75,50,70,50,50};
	drawpoly(9,fill);
	fillpoly(9,fill);
	for (i=50;i<=60;i++)
		putpixel(i,51,0);
	getch();
}