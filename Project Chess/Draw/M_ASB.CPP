#include<graphics.h>
#include<conio.h>
#include<iostream.h>
#include<stdio.h>
void main()
{       int driver=DETECT,mode;
	int i,j,x=0,y=0,c=15,a[8][8];
	clrscr();
	initgraph(&driver,&mode,"c:\\tc\\bgi");
	setbkcolor(0);
	j=46;
	while (j<=62)
	{	for(i=48;i<=61;i++)
		putpixel(i,j,15);
		j++;
	}
	j=47;
	while (j<=60)
	{	for(i=60;i<=64;i++)
		putpixel(i,j,15);
		j++;
	}
	j=44;
	while (j<=48)
	{	for(i=47;i<=62;i++)
		putpixel(i,j,15);
		j++;
	}
	for(i=46;i<=60;i++)
		putpixel(i,43,15);
	for(i=45;i<=59;i++)
		putpixel(i,42,15);
	for(i=44;i<=58;i++)
		putpixel(i,41,15);
	for(i=43;i<=57;i++)
		putpixel(i,40,15);
	for(i=48;i<=61;i++)
		putpixel(i,63,15);
	for(i=49;i<=61;i++)
		putpixel(i,64,15);
	for(i=49;i<=60;i++)
		putpixel(i,65,15);
	for(i=45;i<=61;i++)
		putpixel(47,i,15);
	for(i=44;i<=61;i++)
		putpixel(46,i,15);
	for(i=44;i<=62;i++)
		putpixel(45,i,15);
	for(i=50;i<=62;i++)
		putpixel(43,i,15);
	for(i=50;i<=62;i++)
		putpixel(44,i,15);
	for(i=53;i<=62;i++)
		putpixel(42,i,15);
	putpixel(38,59,15);
	putpixel(39,59,15);
	putpixel(40,59,15);
	putpixel(41,59,15);
	putpixel(38,58,15);
	putpixel(39,58,15);
	putpixel(40,58,15);
	putpixel(41,58,15);
	putpixel(41,57,15);
	putpixel(38,60,15);
	putpixel(39,60,15);
	putpixel(40,60,15);
	putpixel(41,60,15);
	putpixel(41,62,15);
	putpixel(40,62,15);
	putpixel(39,63,15);
	putpixel(41,61,15);
	moveto(48+x,46+y);
	lineto(44+x,42+y);
	setfillstyle(1,0);
	fillellipse(49,51,3,3);
	arc(50+x,54+y,0,130,15);
	arc(51+x,56+y,95,170,10);
	line(64+x,55+y,61+x,66+y);
	moveto(41+x,56+y);
	lineto(37+x,59+y);
	lineto(37+x,61+y);
	lineto(40+x,61+y);
	lineto(37+x,64+y);
	lineto(48+x,62+y);
	lineto(51+x,66+y);
	//circle(49+x,51+y,1);
	line(46+x,66+y,64+x,66+y);
	line(46+x,68+y,64+x,68+y);
	int asb[18]={50+x,66+y,60+x,66+y,62+x,78+y,73+x,82+y,73+x,84+y
	,37+x,84+y,37+x,82+y,48+x,78+y,50+x,66+y};
	setfillstyle(1,15);
	drawpoly(9,asb);
	fillpoly(9,asb);
	getch();
}
