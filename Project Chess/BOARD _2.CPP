#include<graphics.h>
#include<conio.h>
#include<iostream.h>
#include<stdio.h>
void sarbaz;
void rook();
void fill();
void move();
void insert(int x,int y);
void clear(int k,int x,int z,int y,int p);
void board();
void main()
{       int driver=DETECT,mode;
	int x=15,y=59,a[8][8];
	clrscr();
	initgraph(&driver,&mode,"c:\\tc\\bgi");
	setbkcolor(0);
	board();
	insert(x,y);
	move();
	getch();
	closegraph();
}
/////////////////////////////////////////////////////////////////////
void board()	// Board of Chess//
{       int s,i,j,n=50,m=50,x=8,z=7,k;
	char ch;

	while (m<450)
	{       n=50;
		x=z+x;
		z=x-z;
		x=x-z;
		while (n<450)
	{
		for (i=n;i<=n+50;i++)
		{
			for(j=m;j<=m+50;j++)
				putpixel(i,j,x);
		}
		x=z+x;
		z=x-z;
		x=x-z;
		n+=50;
	}
		m+=50;
	}
	setcolor(7);
	rectangle(50,50,450,450);
	setcolor(8);
	rectangle(49,49,451,451);
	setcolor(7);
	rectangle(48,48,452,452);
	for (i=11,ch='A';i<=30,ch<='H';i+=6,ch++)
	{
		gotoxy(i,2);
		printf("%c",ch);
	}
	for (i=6,j=1;i<=30,j<=8;i+=3,j++)
	{
		gotoxy(4,i);
		printf("%d",j);
	}
}	//End Board of Chess//

//////////////////////////////////////////////////////////////////////
void move()
{	// Move /////////////
	int q,w,e,r,t,temp,p=7,o=8,c=12,y,x,i,j,k,z,s,a[8][8];
	for (i=0;i<8;i++)
		for (j=0;j<8;j++)
			a[i][j]=0;
	for (i=0;i<8;i++)
	{	a[i][1]=11;
		a[i][6]=21;
	}
	a[0][0]=a[0][7]=a[7][0]=a[7][7]=12;
	setcolor(c);
	rectangle(50,50,100,100);
	s=getch();
	i=j=0;
	x=50;
	y=100;
	k=50;
	z=100;
	while(s!=27)
	{
	s=getch();
	if (s==72)
	{
		temp=p;
		p=o;
		o=temp;
		setcolor(7);
		rectangle(k,x,z,y);
		x-=50;
		y-=50;
		if (y<=50 || x<50)
		{
			y=450;
			x=400;
		}
		setcolor(c);
		rectangle(k,x,z,y);

		j--;
		if (j<0)	j=7;

	}
	else if (s==80)
	{
		temp=p;
		p=o;
		o=temp;
		setcolor(7);
		rectangle(k,x,z,y);
		x+=50;
		y+=50;
		if (y>450 || x>400)
		{
			y=100;
			x=50;
		}
		setcolor(c);
		rectangle(k,x,z,y);

		j++;
		if (j>7)	j=0;

	}
	else if (s==77)
	{
		temp=p;
		p=o;
		o=temp;
		setcolor(7);
		rectangle(k,x,z,y);
		k+=50;
		z+=50;
		if (z>450 || k>400)
		{
			k=50;
			z=100;
		}
		setcolor(c);
		rectangle(k,x,z,y);
		i++;
		if (i>7)	i=0;

	}
	else if (s==75)
	{
		temp=p;
		p=o;
		o=temp;
		setcolor(7);
		rectangle(k,x,z,y);
		k-=50;
		z-=50;
		if (z<100 || k<50)
		{
			k=400;
			z=450;
		}
		setcolor(c);
		rectangle(k,x,z,y);
		i--;
		if (i<0)	i=7;

	}
	else if (s==13 && a[i][j]!=0 && c==12)
	{
		setcolor(58);
		rectangle(k,x,z,y);
		c=58;
		q=k; w=x; e=z; r=y; t=p;
	}
	else if (s==13 && c==58)
	{
		c=12;
		setcolor(c);
		clear(q,w,e,r,t);
		rectangle(k,x,z,y);

	}
	}
}	//End of Move /////////////
////////////////////////////////////////////////////////////////////////
void sarbaz(int x,int y,int c)
{
	setcolor(c);
	setfillstyle(1,c);
	fillellipse(x+60,y+56,9,9);
	int a[22]={x+50,y+65,x+70,y+65,x+65,y+70,x+65,y+81,x+77,y+86,
	x+77,y+88,x+43,y+88,x+43,y+86,x+55,y+81,x+55,y+70,x+50,y+65};
	drawpoly(11,a);
	fillpoly(11,a);
}
////////////////////////////////////////////////////////////////////////
void rook(int x,int y,int c)
{
	setcolor(c);
	setfillstyle(1,c);
	int rook[44]={45+x,45+y,50+x,45+y,50+x,50+y,60+x,50+y,60+x,45+y
	,65+x,45+y,65+x,50+y,75+x,50+y,75+x,50+y,
	75+x,45+y,80+x,45+y,80+x,55+y,68+x,57+y,68+x,77+y,80+x,80+y,80+x,
	83+y,45+x,83+y,45+x,80+y,57+x,77+y,57+x,57+y,45+x,55+y,45+x,45+y};
	drawpoly(22,rook);
	fillpoly(22,rook);
}
///////////////////////////////////////////////////////////////////////
void fill(int x,int y,int c)
{
	setfillstyle(1,15);
	fillellipse(55+x,27+y,4,4);
	fillellipse(55+x,41+y,8,10);
	line(45+x,50+y,65+x,50+y);
	line(45+x,52+y,65+x,52+y);
	int fill[18]={50+x,50+y,60+x,50+y,60+x,70+y,70+x,75+y,70+x,80+y
	,40+x,80+y,40+x,75+y,50+x,70+y,50+x,50+y};
	drawpoly(9,fill);
	fillpoly(9,fill);
}
////////////////////////////////////////////////////////////////////////
void insert(int x,int y)
{       int c=15,i;
	for (i=x;i<x+(50*8);i+=50)
		sarbaz(i,y,c);
	c=0; y=309;
	for (i=x;i<x+(50*8);i+=50)
		sarbaz(i,y,c);
	c=15; y=x=12; 		rook(x,y,c);
	x=363;        		rook(x,y,c);
	c=0; x=12; y=363; 	rook(x,y,c);
	x=363;			rook(x,y,c);
	x=50; y=13; c=15;	fill(x,y,c);
}
///////////////////////////////////////////////////////////////////////
void clear(int k,int x,int z,int y,int t )
{       int i,j;
	for (i=k+1;i<z;i++)
		for (j=x+1;j<y;j++)
			putpixel(i,j,t);
}
///////////////////////////////////////////////////////////////////////
