#include<iostream.h>
#include<conio.h>
void main()
{       int i;
	clrscr();
	for (i=10;i<70;i++)
	{
		gotoxy(i,5);
		cout<<"?";
		gotoxy(i,45);
		cout<<"?";
	}
	for (i=5;i<46;i++)
	{
		gotoxy(10,i);
		cout<<"?";
		gotoxy(70,i);
		cout<<"?";
	}
	getch();
	getch();
}