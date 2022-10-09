#ifndef GRAPH.H
#define GRAPH.H

#ifndef GRAPHICS_H
#define GRAPHICS_H
#include<graphics.h>
#endif

#ifndef CONIO_H
#define CONIO_H
#include<conio.h>
#endif

#ifndef DOS_H
#define DOS_H
#include<dos.h>
#endif
void  cur(int i,int j)
{
	setcolor(4);
	outtextxy(i+120,j,"||||||||");
	outtextxy(i-30,j,"||||||||");
	sound(555);
	delay(70);
	nosound();
}
void curs(int i,int j)
{
	setcolor(3);
	outtextxy(i+220,j,"||||||||");
	outtextxy(i-40,j,"||||||||");
	sound(333);
	delay(70);
	nosound();
}
void loadgraph()
{
	int d,m;
	d=DETECT;
	initgraph(&d,&m,"c:\\tc\\bgi");
}

void start()
{
	int cc=0,kk=640,ll=480;
	int i=0,j=0;
	for(int ff=0;ff<235&&!kbhit();ff=ff+3)
	{

		setcolor(1);
		rectangle(ff,cc,kk,ll);
		setfillstyle(1,BLACK);
		floodfill(251,251,1);
		cc++;
		kk=kk-3;
		ll--;
		delay(20);
	}
	delay(100);
	setcolor(15);
	rectangle(ff+3,cc+1,kk-3,ll-1);
	setfillstyle(1,6);
	floodfill(250,175,15);
	delay(100);
	cc=cc+1;
	ll=ll-1;
	do
	{
		setcolor(0);
		line(kk-i,cc,kk-i,ll);
		setcolor(15);
		line(kk-i-1,cc,kk-i-1,ll);
		sound(j);
		++i;
		++j;
		if(j==100)
			j=50;
		delay(30);
	}while(i<160&&!kbhit());

	nosound();
}
void exit()
{
		cleardevice();
		int i=1;
		int ii=0,j=0;
		setfillstyle(9,8);
		floodfill(123,50,13);
		setcolor(15);
		do
		{
			setcolor(6);
			line(238+ii,78,238+ii,384);
			setcolor(15);
			line(238+ii+1,78,238+ii+1,384);
			sound(j);
			++ii;
			++j;
			if(j==100)
				nosound();
			delay(50);
		}while(ii<160&&!kbhit());
		cleardevice();
		nosound();
		settextstyle(1,0,4);
		outtextxy(0,200,"THANK YOU FOR USING THIS SOFTWARE");
		setcolor(4);
		settextstyle(1,0,8);
		outtextxy(300,100,"3");
		sleep(i);
		cleardevice();
		setcolor(3);
		outtextxy(300,100,"2");
		sleep(i);
		cleardevice();
		setcolor(2);
		outtextxy(300,100,"1");
		sleep(i);
}
#endif