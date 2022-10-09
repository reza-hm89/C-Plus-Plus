#include<iostream.h>
#include<conio.h>
void main()
{
	char a;
	clrscr();
	cout<<"Enter a Character: ";
	cin>>a;
	while (a!='&')
	{
		cout<<"\nYou Enter: "<<(char)a;
		cout<<"\nNext Character : "<<(char)(a+1);
		getch();
		clrscr();
		cout<<"\nEnter a Character: ";
		cin>>a;
	}
	getch();
}