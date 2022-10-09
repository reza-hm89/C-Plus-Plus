#include<iostream.h>
#include<conio.h>
void main()
{
	int i=0,num,s=0;
	char ans='y';
	clrscr();
	cout<<"Enter a Number: ";
	while (ans=='y')
	{
		cin>>num;
		s+=num*num;
		i++;
		cout<<"\n\nDo you want to continue?(y/n)";
		cin>>ans;
		cout<<"\n\nEnter a Number: ";
	}
	cout<<"Squre of numbers is : "<<s;
	cout<<"\nNumbers of Numbers : "<<i;
	getch();
}