#include<graphics.h>
#include<conio.h>
void main()
{       int driver=DETECT,mode;
	clrscr();
	initgraph(&driver,&mode,"c:\\tc\\bgi");
	setbkcolor(1);
	pieslice(60,40,0,360,10);
	//setfillstyle(1,0);
	//fillellipse(55,37,2,5);
	setfillstyle(1,15);
	//arc(55,37,0,170,5);
	int a[18]={50,50,70,50,65,60,65,90,75,100,45,100,55,90,55,60,50,50};
	drawpoly(9,a);
	fillpoly(9,a);
	getch();
}