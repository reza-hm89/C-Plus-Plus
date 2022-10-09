#include<iostream.h>
#include<conio.h>
void main()
{       int i;
	clrscr();
	for (i=10;i<70;i++)
	{
		gotoxy(i,5);
		cout<<"²";
		gotoxy(i,45);
		cout<<"²";
	}
	for (i=5;i<46;i++)
	{
		gotoxy(10,i);
		cout<<"ô";
		gotoxy(70,i);
		cout<<"õ";
	}
	getch();
	getch();
}