#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<stdio.h>
/////////////////////
void input_rec();
void input_lin();
void input_cir();
void input_bez();
////////////////////
void initmouse();
void yesmouse();
void mouse();
void hidemouse();
///////////////////
void paint();
void board();
void colors();
void forms1();
void forms2();
//////////////////
void rectangl();
void lin();
void bezier();
void circl();
/////////////////
float power(float,float);
float fact(int);
//////////////////////////////
struct controlpoint{
	int cx;
	int cy;
	};
struct controlpoint
	clp[4];
//////////////////////////////
int x1,x2,y1,y2;
int row,col,state;
int sw=0,bcolor=0;
int jump=0;
///////////////////////////////////////////////
void main()
{
	clrscr();
	int d=DETECT,m=DETECT;
	initmouse();
	initgraph(&d,&m,"c:\\tc\\bgi");
	board();
	paint();
	yesmouse();
	while (1) {
	bcolor=0;
	mouse();
	if((row>=435) && (row<=455) && (col>=80) && (col<=220) && (state==1))
		{	forms1();   forms2();  paint();  }
	if((row>=441) && (row<=476) && (col>=80) && (col<=395) && (state==1))
		{	colors();   forms2();     paint();  }
	if((row>440) && (row<=460) && (col>=445) && (col<=572) && (state==1))
		{
			setcolor(15);
			rectangle(445,440,572,460);
			setcolor(0);
			line(445,440,445,460);
			line(445,440,572,440);
			delay(150);
			board();
			paint();
		}
	if((row>=1) && (row<=19) && (col>=615) && (col<=635) && (state==1))
		exit(0);
	}
}
//////////////////////////////////////////////
void input_rec()
{
	char s1[10],s2[10],s3[10],s4[10];
	gotoxy(1,1);
	cout<<"Rectangle(    ,    ,    ,    )";
	gotoxy(11,1); gets(s1);
	gotoxy(16,1); gets(s2);
	gotoxy(21,1); gets(s3);
	gotoxy(26,1); gets(s4);
	x1=atoi(s1);
	y1=atoi(s2);
	x2=atoi(s3);
	y2=atoi(s4);
}
/////////////////////////////////////////////
void input_lin()
{
	char s1[10],s2[10],s3[10],s4[10];
	gotoxy(1,1);
	cout<<"Line(    ,    ,    ,    )";
	gotoxy(6,1); gets(s1);
	gotoxy(11,1); gets(s2);
	gotoxy(16,1); gets(s3);
	gotoxy(21,1); gets(s4);
	x1=atoi(s1);
	y1=atoi(s2);
	x2=atoi(s3);
	y2=atoi(s4);
}
/////////////////////////////////////////////
void input_cir()
{
	char s1[10];
	gotoxy(1,1);
	cout<<"Circle(   )";
	gotoxy(8,1);
	gets(s1);
	x1=atoi(s1);
}
/////////////////////////////////////////////
void input_bez()
{
	int x=col,y=row;
	jump=0;
	outtextxy(1,1,"Press one or 2 points to draw a bezier & press bezier button & 'enter'");
	yesmouse();
	while(!kbhit())
	{
		mouse();
		x=col;y=row;
		if((state &1)==1)
		{
			hidemouse();
			jump++;
			while((state &1)==1)
			{
				setcolor(15);
				mouse();
				x=col;y=row;
				if(x>0&&x<640&&y>20&&y<420){
					putpixel(x,y,bcolor);
					clp[jump].cx=x;
					clp[jump].cy=y;
				}
				if(x>200&&x<220&y>435&&y<455)
				{
					bezier();
					jump=0;
				}
			}
		}
		yesmouse();
	}
}
/////////////////////////////////////////////////////////////
void rectangl()
{
	int i,j,t;
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
		putpixel(i,y1,0);
		putpixel(i,y2,0);
	}
	for (i=y1;i<=y2;i++)
	{
		putpixel(x1,i,0);
		putpixel(x2,i,0);
	}
	for (i=x1+1;i<x2;i++)
		for (j=y1+1;j<y2;j++)
			putpixel(i,j,bcolor);
}
//////////////////////////////////////////////////
void circl()
{
	int r=x1;
	int xcenter,ycenter,k,x,y,p,i;
	float q,z=3;
	xcenter=ycenter=r;
	x=0;
	y=r;
	p=1-r;
	putpixel(xcenter-y,ycenter,bcolor);
	putpixel(xcenter+y,ycenter,bcolor);
	putpixel(xcenter,ycenter+y,bcolor);
	putpixel(xcenter,ycenter-y,bcolor);
	while (q<(1.93*z*r)/8) {
	q++;
	x++;
	if (p<0)
		p+=2*(x+1);
	else {
		p+=2*(x-y)+1;
		y--;
		}
	putpixel(xcenter+x,ycenter+y,bcolor);
	putpixel(xcenter-x,ycenter+y,bcolor);
	putpixel(xcenter+x,ycenter-y,bcolor);
	putpixel(xcenter-x,ycenter-y,bcolor);
	putpixel(xcenter+y,ycenter+x,bcolor);
	putpixel(xcenter-y,ycenter+x,bcolor);
	putpixel(xcenter+y,ycenter-x,bcolor);
	putpixel(xcenter-y,ycenter-x,bcolor);
	}
}
//////////////////////////////////////////////////
void lin()
{
	int ds,df,dx,dy;
	int i,j,i1,j1,temp,index,index1,index2;
	int des,offset;
	float m,count;
	////////////////////
	if (!(x2-x1)){
	if (y2<y1) {
		temp=y1;
		y1=y2;
		y2=temp; }
	for (i=y1;i<=y2;i++)
		putpixel(x1,i,bcolor);
		return;
		}
	////////////////////
	if (!(y1-y2)) {
	if (x2<x1) {
		temp=x1;
		x1=x2;
		x2=temp; }
	for (i=x1;i<=x2;i++)
		putpixel(i,y1,bcolor);    }
	///////////////////
	if (x1-x2)
	m=((y2-y1)/(float)(x2-x1));
	if (m>0) {
		index1=1;
		index2=2;
		if  (x2<x1) {
			temp=x1;
			x1=x2;
			x2=temp; }
		if (y2<y1) {
			temp=y1;
			y1=y2;
			y2=temp; }
		/////////////////////
		dx=x2-x1;
		dy=y2-y1;
		///////////////////
		if (dx>dy) {
			count=-(float)(dx/2);
			offset=dx;
			des=dy;	}
		else	{
			count=-(float)(dy/2);
			offset=dy;
			des=dx; }
		///////////////////
		if (m<1) {
			m=1/m;
			ds=x1;
			df=x2;
			j=y1;
			index=1; }
		else {
			ds=y1;
			df=y2;
			j=x1;
			index=2; }
		}//if (m>0)

	else if (m<0) {
		m=-m;
		index1=1;
		if  (x2<x1) {
			temp=x1;
			x1=x2;
			x2=temp; }
		if (y2>y1) {
			temp=y1;
			y1=y2;
			y2=temp; }
		/////////////////////
		dx=x2-x1;
		dy=y1-y2;
		///////////////////
		if (dx>dy) {
			index2=1;
			count=-(float)(dx/2);
			offset=dx;
			des=dy;	}
		else	{
			index1=2;
			index2=2;
			count=-(float)(dy/2);
			offset=dy;
			des=dx; }
		///////////////////
		////////////////////////
		if (m<1) {
			m=1/m;
			ds=x1;
			df=x2;
			j=y1;
			index=1; }
		else {
			ds=y1;
			df=y2;
			j=x1;
			index=2; }
		}// if (m<0)
	////////////////////
	if (index1==1) {
	for (i=ds;i<=df;i++)
	{
		if (index==1) {
			i1=i;  j1=j; }
		else if (index==2) {
			i1=j;  j1=i; }
		count+=des;
		if (count>=0) {
		if (index2==1)	j--;
		else if (index2==2) j++;
		count-=offset; }
		putpixel(i1,j1,bcolor);
	}
	}
	else if (index1==2) {
	for (i=ds;i>=df;i--)
	{
		if (index==1) {
			i1=i;  j1=j; }
		else if (index==2) {
			i1=j;  j1=i; }
		count+=des;
		if (count>=0) {
		j++;
		count-=offset; }
		putpixel(i1,j1,bcolor);
	}
	}
}
/////////////////////////////////////////////////////////////
void bezier ()
{
	float  x11[11],y11[11];
	moveto(clp[1].cx,clp[1].cy);
	setcolor(15);
	for(int j1=1;j1<jump;j1++)
		lineto(clp[j1].cx,clp[j1].cy);
	jump--;
	for(int  u1=0;u1<=10;u1++)
	{
		double u=double(u1)/10.0;
		float temp=0,temp1=0;
		for(int k=0;k<jump;k++)
		{
			temp=(float(clp[k+1].cx)*(float(fact(jump-1))/(float(fact(k)*fact(jump-k-1))))*power((1.0-u),(jump-k-1))*power(u,k));
			temp1=temp1+temp;
		}
		x11[u1]=temp1;
	}
	for(int u11=0;u11<=10;u11++)
	{
		double uu=double(u11)/10.0;
		float temp=0,temp1=0;
		for(int k=0;k<jump;k++)
		{
			temp=(float(clp[k+1].cy)*(float(fact(jump-1))/(float(fact(k)*fact(jump-k-1))))*power((1.0-uu),(jump-k-1))*power(uu,k));
			temp1=temp1+temp;
		}
		y11[u11]=temp1;
	}
	setcolor(bcolor);
	moveto(int(x11[0]),int(y11[0]));
	for( j1=0;j1<=10;j1++){lineto(int(x11[j1]),int(y11[j1]));}
}
/////////////////////////////////////////////////
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
void paint()
{
	int ccount;
	//////////////////////////
	setfillstyle(1,57);
	bar(0,0,639,20);
	settextstyle(7,0,2);
	setcolor(4);
	outtextxy(230,0,"*** P A I N T ***");
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
	////////////////////////
	setfillstyle(1,7);
	bar(0,430,640,480);
	///////////////////////
	settextstyle(2,0,4);
	outtextxy(560,465,"Reza-Hosseini");
	////////////////////////
	setfillstyle(1,15);
	bar(446,441,571,459);
	settextstyle(2,0,6);
	setcolor(0);
	outtextxy(450,440,"Clear Screen");
	setcolor(0);
	rectangle(445,440,572,460);
	setcolor(15);
	line(445,440,445,460);
	line(445,440,572,440);
	////////////////////////
	setcolor(0);
	rectangle(80,435,100,455);
	rectangle(120,435,140,455);
	rectangle(160,435,180,455);
	rectangle(200,435,220,455);
	////////////////////////////
	rectangle(85,440,95,450);
	circle(130,445,8);
	line(163,440,177,450);
	arc(210,445,0,170,5);
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
void forms1()
{
	int x=col,y=row,bcolor;
	sw=0;
	if (y>435 && y<455) {
		if (x>80 && x<100){
			outtextxy(250,440,"Rectangle");
			input_rec();
			sw=1;
		}
		if (x>120 && x<140){
			outtextxy(250,440,"Circle");
			input_cir();
			sw=2;
		}
		if (x>160 && x<180){
			outtextxy(250,440,"Line");
			input_lin();
			sw=3;
		}
		if (x>200 && x<220){
			outtextxy(250,440,"Bezier");
			input_bez();
			sw=4;
		}
	}
}
////////////////////////////////////////////////
void forms2()
{
	if (sw==1) rectangl();
	if (sw==2) circl();
	if (sw==3) lin();
}
////////////////////////////////////////////////
void colors()
{
	int x=col,y=row;
	if((y>=461) && (y<=476))
	{
		if((x>=80) && (x<=95)) {bcolor=0;}
		if((x>=100) && (x<=115)) {bcolor=1;}
		if((x>=120) && (x<=135)) {bcolor=2;}
		if((x>=140) && (x<=155)) {bcolor=3;}
		if((x>=160) && (x<=175)) {bcolor=4;}
		if((x>=180) && (x<=195)) {bcolor=5;}
		if((x>=200) && (x<=215)) {bcolor=6;}
		if((x>=220) && (x<=235)) {bcolor=7;}
		if((x>=240) && (x<=255)) {bcolor=8;}
		if((x>=260) && (x<=275)) {bcolor=9;}
		if((x>=280) && (x<=295)) {bcolor=10;}
		if((x>=300) && (x<=315)) {bcolor=11;}
		if((x>=320) && (x<=335)) {bcolor=12;}
		if((x>=340) && (x<=355)) {bcolor=13;}
		if((x>=360) && (x<=375)) {bcolor=14;}
		if((x>=380) && (x<=395)) {bcolor=15;}
	}
}
////////////////////////////////////////////
float power(float a,float b)
{
	float temp =1;
	for(int i=1.0;i<=b;i++)
	temp=temp*a;
	return temp;
}
////////////////////////////////////////////
float fact(int a)
{
	float p=1;
	int i=1;
	for( i=1;i<=a;i++)
		p=p*i;
	return(p);
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
////////////////////////////////////////////
void hidemouse()
{
	asm {
	mov ax,2
	int 33h
	}
}