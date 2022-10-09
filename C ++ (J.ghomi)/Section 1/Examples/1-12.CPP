#define  PI 3.14
#include<iostream.h>
#include<conio.h>
void main()
{
	int r;
	float p,s;
	clrscr();
	cout<<"Enter Radius: ";
	cin>>r;
	s=r*r*PI;
	p=PI*r*2;
	cout<<"\nArea : "<<s;
	cout<<"\nPerime : "<<p;
	getch();
}