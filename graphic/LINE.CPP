#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
void main()
{       int d=0,mode;
	int x1=50,x2=100,y1=200,y2=1;
	int ds,df,dx,dy;
	int i,j,i1,j1,temp,index,index1,index2;
	int des,offset;
	float m,count;
	initgraph(&d,&mode,"c:\\tc\\bgi");
	cleardevice();
	cin>>x1>>y1>>x2>>y2;
	////////////////////
	if (!(x2-x1)){
	if (y2<y1) {
		temp=y1;
		y1=y2;
		y2=temp; }
	for (i=y1;i<=y2;i++)
		putpixel(x1,i,15);     }
	////////////////////
	if (!(y1-y2)) {
	if (x2<x1) {
		temp=x1;
		x1=x2;
		x2=temp; }
	for (i=x1;i<=x2;i++)
		putpixel(i,y1,15);    }
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
		putpixel(i1,j1,15);
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
		putpixel(i1,j1,15);
	}
	}
	////////////////////
	getch();
	closegraph();
}