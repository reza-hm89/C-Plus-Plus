#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>

void rectangl();
void paint();
void board();
void input();
void initmouse();
void yesmouse();
void mouse();
void colors();

int x1,x2,y1,y2;
int row,col,state;
///////////////////////////////////////////////
void main()
{
	input();
	int d=DETECT,m=DETECT;
	initmouse();
	initgraph(&d,&m,"c:\\tc\\bgi");
	board();
	paint();
	rectangl();
	yesmouse();
	while (1) {
	mouse();
	if((row>=441) && (row<=476) && (col>=80) && (col<=395) && (state==1))
		colors();
	if((row>=1) && (row<=19) && (col>=615) && (col<=635) && (state==1))
		exit(0);
	}
}
//////////////////////////////////////////////
void input()
{
	cout<<"Rectangle(    ,    ,    ,    )";
	gotoxy(11,1); cin>>x1;
	gotoxy(16,1); cin>>y1;
	gotoxy(21,1); cin>>x2;
	gotoxy(26,1); cin>>y2;
}
/////////////////////////////////////////////
void board()
{
	setbkcolor(0);
	//////////////////////////
	setfillstyle(1,57);
	bar(0,0,639,20);
	//////////////////////////
	setfillstyle(1,15);
	bar(0,21,639,479);
	//////////////////////////
	setcolor(7);
	rectangle(615,1,635,19);
	rectangle(617,3,633,17);
	setcolor(15);
	line(616,2,634,2);
	line(616,2,616,18);
	setcolor(56);
	line(634,2,634,18);
	line(616,18,634,18);
	setfillstyle(1,4);
	bar(618,4,632,16);
	/////////////////////////
	setcolor(62);//yellow
	line(620,5,630,15);
	line(630,5,620,15);
}
////////////////////////////////////////////////
void rectangl()
{
	int i,j,t;
	int color=0;
	if (y1<20)  y1=21;
	if (y2<20)  y2=21;
	if (y1>456) y1=455;
	if (y2>456) y2=455;
	if (x1>x2) {
		t=x1;
		x1=x2;
		x2=t;
		}
	if (y1>y2) {
		t=y1;
		y1=y2;
		y2=t;
		}
	/////////////////////////////
	for (i=x1;i<=x2;i++)
	{
		putpixel(i,y1,color);
		putpixel(i,y2,color);
	}
	for (i=y1;i<=y2;i++)
	{
		putpixel(x1,i,color);
		putpixel(x2,i,color);
	}
}
/////////////////////////////////////////////////
void paint()
{
	int ccount;
	setfillstyle(1,7);
	bar(0,456,640,480);
	for(ccount=0;ccount<16;ccount++)
	{
		setfillstyle(1,ccount);
		bar(80+(ccount*20),461,80+(ccount*20)+15,476);
		setcolor(0);
		rectangle(80+(ccount*20),461,80+(ccount*20)+15,476);
	}
	settextstyle(2,0,5);
	outtextxy(2,461,"Color");
}
////////////////////////////////////////////////
void colors()
{
	int x=col,y=row,bColor;
	if((y>=461) && (y<=476))
	{
		if((x>=80) && (x<=95)) {bColor=0;}
		if((x>=100) && (x<=115)) {bColor=1;}
		if((x>=120) && (x<=135)) {bColor=2;}
		if((x>=140) && (x<=155)) {bColor=3;}
		if((x>=160) && (x<=175)) {bColor=4;}
		if((x>=180) && (x<=195)) {bColor=5;}
		if((x>=200) && (x<=215)) {bColor=6;}
		if((x>=220) && (x<=235)) {bColor=7;}
		if((x>=240) && (x<=255)) {bColor=8;}
		if((x>=260) && (x<=275)) {bColor=9;}
		if((x>=280) && (x<=295)) {bColor=10;}
		if((x>=300) && (x<=315)) {bColor=11;}
		if((x>=320) && (x<=335)) {bColor=12;}
		if((x>=340) && (x<=355)) {bColor=13;}
		if((x>=360) && (x<=375)) {bColor=14;}
		if((x>=380) && (x<=395)) {bColor=15;}
	}
	for (int i=x1+1;i<x2;i++)
		for (int j=y1+1;j<y2;j++)
			putpixel(i,j,bColor);

}
//////////////////////////////////////////////
void initmouse()
{
	asm {
		mov ax,0;
		int 33h;
	}
}
//////////////////////////////////////////////
void yesmouse()
{
	asm {
		 mov ax,1;
		 int 33h;
	}
}
/////////////////////////////////////////////
void mouse()
{
	 asm {
		  mov ax,3;
		  int 33h;
		  mov row,dx;
		  mov col,cx;
		  mov state,bx;
	 }
}