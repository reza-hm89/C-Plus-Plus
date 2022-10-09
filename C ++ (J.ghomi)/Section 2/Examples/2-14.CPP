#include<iostream.h>
#include<conio.h>
void main()
{
	int i=0,j=0,a;
	clrscr();
	cout<<"Enter a Number: ";
	cin>>a;
	while (a)
	{
		if (a%2)
			i++;
		else
			j++;
		cout<<"\nEnter a Number: ";
		cin>>a;
	}
	clrscr();
	cout<<"Even numbers: "<<j;
	cout<<"\n\Odd numbers: "<<i;
	getch();
}