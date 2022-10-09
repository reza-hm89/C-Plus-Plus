#include<graphics.h>
#include<conio.h>
void main()
{       int driver=DETECT,mode;
	int x=0,y=0,a[8][8];
	clrscr();
	initgraph(&driver,&mode,"c:\\tc\\bgi");
	setbkcolor(0);
	setfillstyle(1,15);
	//fillellipse(55,44,2,2);
	int V[16]={46+x,38+y,50+x,43+y,55+x,41+y,60+x,43+y,
	64+x,38+y,64+x,48+y,46+x,48+y,46+x,38+y};
	drawpoly(8,V);
	fillpoly(8,V);
	line(46+x,49+y,64+x,49+y);
	pieslice(55+x,50+y,180,360,9);
	line(45+x,58+y,65+x,58+y);
	line(45+x,60+y,65+x,60+y);
	int vazir[18]={50+x,58+y,60+x,58+y,60+x,78+y,73+x,82+y,73+x,84+y
	,37+x,84+y,37+x,82+y,50+x,78+y,50+x,58+y};
	drawpoly(9,vazir);
	fillpoly(9,vazir);
	getch();
}