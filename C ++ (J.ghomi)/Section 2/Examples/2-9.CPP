#include<iostream.h>
#include<conio.h>
void main()
{
	int r,num,s=0;
	char ans='y';
	clrscr();
	while (ans=='y')
	{
		cout<<"Enter a Number: ";
		cin>>num;
		s=0;
		while (num!=0)
		{
			r=num%10;
			s=s*10+r;
			num/=10;
		}
		cout<<"\tInvert: "<<s;
		cout<<"\nDo you want to continue?(y/n)";
		cin>>ans;
	}
	getch();
}