#include<conio.h>
#include<iostream.h>
void main()
{       int s,s1=0,s2=1,n,i;
	clrscr();
	cout<<"Enter N:";
	cin>>n;
	if (n==1)
		cout<<"1";
	else
	{       cout<<"1\t";
		for (i=2;i<=n;i++)
		{
			s=s1+s2;
			cout<<s<<"\t";
			s1=s2;
			s2=s;
		}
	}
	getch();
}
