#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
void main()
{       char ans='y';
	int guess,num;
	clrscr();
	guess=rand();
	cout<<"Guess the magic number:";
	cin>>num;
	while (ans=='y')
	{
		if (num!=guess)
		{
			cout<<"***** Wrong *****";
			if (num>guess)
				cout<<"\nyour guess is too high";
			else if (num<guess)
				cout<<"\nyour guess is too low";
			cout<<"\nDo you want to continue?(y/n)";
				cin>>ans;
			cout<<"\nGuess the magic number:";
				cin>>num;
		}
		else
		{
			cout<<"\n**** RIGHT ****";
			ans='n';
			getch();
		}
	}
	getch();
}