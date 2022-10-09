#include<iostream.h>
#include<conio.h>
void main()
{       int n,r,s=1,sum=0,i=1;
	clrscr();
	cout<<"enter Number(mabnay 2):";
	cin>>n;
	while(n!=0)
	{
		s*=i;
		if ((n%10)!=0)
			sum+=s;
		i=2;
		n/=10;
	}
	cout<<sum;
	getch();
}