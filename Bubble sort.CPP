#include<iostream.h>
#include<conio.h>
void main()
{
	int i,j,n,t,sorted=0,a[20];
	clrscr();
	cout<<"Enter n:";
	cin>>n;
	for (i=0;i<n;i++)
	{
		cout<<"Enter Number "<<i+1<<":";
		cin>>a[i];
	}
	for (i=0;i<n && !sorted;i++)
	{
		sorted=1;
		for (j=0;j<n-1;j++)
		{
			if (a[j]>a[j+1])
			{
				sorted=0;
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for (i=0;i<n;i++)
		cout<<a[i]<<"\t";
	getch();
}