#include<graphics.h>
#include<conio.h>
#include<iostream.h>
#include<dos.h>
#include<stdio.h>
void main()
{       int d=DETECT,m=0,c=LIGHTBLUE,p=RED,i,j,k,t;
	//cleardevice();
	initgraph(&d,&m,"c:\\tc\\bgi");
	delay(1000);
	setbkcolor(0);
	settextstyle(5,0,8);
	setfillstyle(1,0);
	rectangle(250,270,352,290);
	setcolor(8);
	rectangle(249,269,353,291);
	for (i=0,k=251;i<=101,k<=351;i++,k++)
	{       setcolor(c);
		outtextxy(150,120,"Loading...");
	       //	delay(2);
	       /*	t=c;
		c=p;
		p=t;*/
		setfillstyle(3,0);
		textcolor(8);
		for (j=271;j<=289;j++)
		{	putpixel(k,j,7);
			delay(2);

		}
		gotoxy(37,20);
		printf("%d%",i);
	}
	delay(1000);
	getch();
	closegraph();
}