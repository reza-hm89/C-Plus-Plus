#include<iostream.h>
#include<conio.h>
long int fact(int);
int main()
{
	int i,f,n;
	clrscr();
	cout<<"Enter N: ";
	cin>>n;
	f=fact(n);
	cout<<"Fact = "<<f;
	getch();
	return 0;
}
long int fact(int x)
{
	int i,f=1;
	for(i=1;i<=x;i++)
		f*=i;
	return f;
}