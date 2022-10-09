#include<iostream.h>
#include<conio.h>
int main()
{
clrscr();
	int num,r,s=0;
	cout<<"Enter Your Number:\n";
	cin>>num;
	while(num!=0)
	{
		r=num%10;
		s=(s*10)+r;
		num/=10;
	}
	cout<<"Invert is: "<<s;
	getch();

}

