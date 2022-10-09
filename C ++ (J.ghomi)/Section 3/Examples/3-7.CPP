#include<iostream.h>
#include<conio.h>
void test();
void main()
{
	register int i;
	clrscr();
	for (i=0;i<5;i++)
		test();
	getch();
}
void test()
{
	int x=0;//automatic variable
	static int y=0;
	cout<<"\n auto x="<<x<<" , static y="<<y;
	x++;
	y++;
}