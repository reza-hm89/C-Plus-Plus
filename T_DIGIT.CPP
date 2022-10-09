#include<iostream.h>
#include<conio.h>
long int digit(long int x,long int z);
void main()
{       long int n,k;
	clrscr();
	cout<<"Enter N & K:";
	cin>>n>>k;
	digit(n,k);
	getch();
}
long int digit(long int x,long int z)
{
	long int r,s,i=-1;
	while(x!=0)
	{
		r=x%10;
		i++;
		if (i==z)
			s=r;
		x/=10;
	}
	cout<<s;
	return 0;
}