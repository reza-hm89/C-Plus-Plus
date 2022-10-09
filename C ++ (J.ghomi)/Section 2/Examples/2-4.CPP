#include<iostream.h>
#include<conio.h>
void main()
{
	int i=0;
	clrscr();
	cout<<"Enter your statement(END with '.'): \n";
	while(cin.get()!='.')
		i++;
	cout<<"Numbers of characters: "<<i;
	getch();
}