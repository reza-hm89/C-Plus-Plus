#include<iostream.h>
#include<conio.h>
void main()
{
	int a,b,p,s;
	clrscr();
	cout<<"Enter length,width: ";
	cin>>a>>b;
	p=2*(a+b);
	s=a*b;
	gotoxy(20,10);
	cout<<"s = "<<s<<" p = "<<p;
	getch();
}