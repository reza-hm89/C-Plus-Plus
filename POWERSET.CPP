#include<iostream.h>
#include<conio.h>
int a[100];
char s[100];
void Power(int,int);
void main()
{
	int n;
	clrscr();
	cout<<"Enter n: ";
	cin>>n;
	cout<<"Enter your Character:\n";
	for (int i=0;i<n;i++)
		cin>>s[i];
	cout<<"{  ";
	Power(3,0);
	cout<<"  }";
	getch();
}
void Power(int n,int i)
{
	if (i==n)
	{
		char ch=s[0];
		cout<<"{";
		for (int j=0;j<n;j++)
		{
			if (a[j]==1)
				cout<<s[j];
		}
		cout<<"},";
	}
	else
	{
		a[i]=1;
		Power(n,i+1);
		a[i]=0;
		Power(n,i+1);
	}
}