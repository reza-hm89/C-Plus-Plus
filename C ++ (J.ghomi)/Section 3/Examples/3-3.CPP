#include<iostream.h>
#include<conio.h>
void f(int,int);
void main()
{
	int x,y;
	clrscr();
	cout<<"Enter two integer numbers: ";
	cin>>x>>y;
	cout<<"You entered: x= "<<x<<"  y= "<<y;
	f(x,y);
	cout<<"\nAfter return from f1 : x= "<<x<<"  y="<<y;
	getch();
}
void f(int x,int y)
{
	cout<<"\nf1 recieves : x= "<<x<<"  y="<<y;
	x++;
	y++;
	cout<<"\nNew values in f1 : x= "<<x<<"  y="<<y;
}