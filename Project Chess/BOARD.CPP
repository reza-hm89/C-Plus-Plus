#include<graphics.h>
#include<conio.h>
#include<iostream.h>
#include<stdio.h>
void main()
{       int driver=DETECT,mode;
	int i,j,n=50,m=50,x=7,z=15,temp;
	char k;
	clrscr();
	initgraph(&driver,&mode,"c:\\tc\\bgi");
	setbkcolor(9);
	// Board of Chess//
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
	setcolor(6);
	rectangle(50,50,450,450);
	setcolor(13);
	rectangle(49,49,451,451);
	setcolor(6);
	rectangle(48,48,452,452);
	for (i=11,k='A';i<=30,k<='H';i+=6,k++)
	{
		gotoxy(i,2);
		printf("%c",k);
	}
	for (i=6,j=1;i<=30,j<=8;i+=3,j++)
	{
		gotoxy(4,i);
		printf("%d",j);
	}
	// Board of Chess//
	getch();
	getch();
	closegraph();
}