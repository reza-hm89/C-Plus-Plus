#include<iostream.h>
#include<conio.h>
void main()
{
	int s;
	clrscr();
	cout<<"Enter Your Character:(Exit by Enter)";
	while (s!=13)
	{
		s=getch();
		cout<<s<<"\t";
	}
	getch();
}