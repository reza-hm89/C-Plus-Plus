#include<iostream.h>
#include<conio.h>
int x;
void f1(void);
void f2(void);
void main()
{
	clrscr();
	x=100;
	f1();
	f2();
	cout<<"\n In main x is: "<<x;
	getch();
}
void f1()
{
	cout<<"\n In f1 x is: "<<x;
}
void f2()
{
	int x;
	cout<<"\n In f2 x changes:";
	for (x=1;x<6;x++)
		cout<<" x="<<x;
	cout<<"\n global x in f2 is : "<<::x;
}
