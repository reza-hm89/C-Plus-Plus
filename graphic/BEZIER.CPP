#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include <math.h>
int row,col,state;

void initmouse();
void mouse();//getmousepos(int *button,int *x,int *y);
void yesmouse();
void hidemouse();
//union REGS i,o;
void bezier (int);
struct controlpoint{
int cx;int cy;};
struct controlpoint clp[4];
float power(float a,float b );
float fact(int a);
/////////////////////////////////////////
void main()
{
	int gd,gm=0;
	int x=col,y=row;
	clrscr();
	gd=DETECT;
	initgraph(&gd,&gm,"c:\\tc\\bgi ");
	int j=0;
	cleardevice();
	yesmouse();
	/*setcolor(YELLOW);
	settextstyle(4,0,7);
	outtextxy(100,20,"Bezier Curve");
	setcolor(BLUE);
	setbkcolor(BLACK);
	rectangle(100,100,540,380);
	setcolor(YELLOW);
	outtextxy(190,370,"done? ");
	rectangle(350,400,380,430);
	rectangle(400,400,430,430);
	setfillstyle(SOLID_FILL,GREEN);
	floodfill(360,420,YELLOW);
	floodfill(420,420,YELLOW);
     */  	settextstyle(4,0,2);
	outtextxy(360,402,"Y");
	outtextxy(410,402,"N");
	settextstyle(4,0,1);
	while(!kbhit())
	{
		mouse();//getmousepos(&button,&x,&y);
		x=col;y=row;
		if((state &1)==1)
		{
			hidemouse();
			j++;
			while((state &1)==1)
			{
				setcolor(GREEN);
				mouse();
				//getmousepos(&button,&x,&y);
				x=col;y=row;
				if(x>100&&x<540&&y>100&&y<380){
					putpixel(x,y,GREEN);
					clp[j].cx=x;
					clp[j].cy=y;
				}
				if(x>350&&y>400&&x<380&&y<430)
				{
					bezier(j);
					j=0;
					//goto label1;
				}
				if(x>400&&x<430&&y>400&&y<430)
				      j=0; //	goto label1;

			}

		}
		yesmouse();
	}
}
//////////////////////////////////////////////////////////
void bezier (int j)
{
	float  x11[11],y11[11];
	moveto(clp[1].cx,clp[1].cy);
	for(int j1=1;j1<j;j1++)
		lineto(clp[j1].cx,clp[j1].cy);
	j--;
	for(int  u1=0;u1<=10;u1++)
	{
		double u=double(u1)/10.0;
		float temp=0,temp1=0;
		for(int k=0;k<j;k++)
		{
			temp=(float(clp[k+1].cx)*(float(fact(j-1))/(float(fact(k)*fact(j-k-1))))*power((1.0-u),(j-k-1))*power(u,k));
			temp1=temp1+temp;
		}
		x11[u1]=temp1;
	}
	for(int u11=0;u11<=10;u11++)
	{
		double uu=double(u11)/10.0;
		float temp=0,temp1=0;
		for(int k=0;k<j;k++)
		{
			temp=(float(clp[k+1].cy)*(float(fact(j-1))/(float(fact(k)*fact(j-k-1))))*power((1.0-uu),(j-k-1))*power(uu,k));
			temp1=temp1+temp;
		}
		y11[u11]=temp1;
	}
	setcolor(RED);
	moveto(int(x11[0]),int(y11[0]));
	for( j1=0;j1<=10;j1++){lineto(int(x11[j1]),int(y11[j1]));}
	delay(1000);
}
///////////////////////////////////////////
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
/*
initmouse()
{
i.x.ax=0;
int86(0x33,&i,&o);
return(o.x.ax);
}
///////////////////////////////////////////
void showmouseptr()
{
 i.x.ax=1;
int86(0x33,&i,&o);
}
/////////////////////////////////////////////
void getmousepos(int *button, int *x,int *y)
{
	i.x.ax =3;
	int86(0x33,&i,&o);
	*button =o.x.bx;
	*x=o.x.cx;
	*y=o.x.dx;
}   */
//////////////////////////////////////////////
void hidemouse()
{
	asm {
	mov ax,2
	int 33h
	}
}
/////////////////////////////////////////////
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