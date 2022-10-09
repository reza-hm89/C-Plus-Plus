#include<iostream.h>
#include<conio.h>
void main()
{
	int i,n;
	float sum=0,s=1;
	clrscr();
	cout<<"Enter N:";
	cin>>n;
	for (i=1;i<=n;i++)
	{
		sum+=(float)(1/s);
		s*=2;
	}
	cout<<"Sum of Series : "<<sum;
	getch();
}