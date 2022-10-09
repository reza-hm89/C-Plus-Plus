#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
void main()
{
	int d=DETECT,m=0;
	initgraph(&d,&m,"c:\\tc\\bgi");
	int xcenter,ycenter ,r,x,y,p,i;
	float q,z=3.14;
	cout<<"Enter r:";
	cin>>r;
	xcenter=ycenter=r;
	x=0;
	y=r;
	p=1-r;
	putpixel(xcenter+x,ycenter+y,4);
	while (q<(2*z*r)/8) {
	q++;
	x++;
	if (p<0)
		p+=2*(x+1);
	else {
		p+=2*(x-y)+1;
		y--;
		}
	putpixel(xcenter+x,ycenter+y,4);
	putpixel(xcenter-x,ycenter+y,4);
	putpixel(xcenter+x,ycenter-y,4);
	putpixel(xcenter-x,ycenter-y,4);
	putpixel(xcenter+y,ycenter+x,4);
	putpixel(xcenter-y,ycenter+x,4);
	putpixel(xcenter+y,ycenter-x,4);
	putpixel(xcenter-y,ycenter-x,4);
		}
	for (i=1;i<640;i++) {
		k=getpixel(i,100);
		cout<<k;<<" ";
		}
	getch();
}