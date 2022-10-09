#include<iostream.h>
#include<conio.h>
void main()
{       int i,j,m,k;
	long float n,a[100];
	clrscr();
	cout<<"Enter Numbers of Array: (n=Fard)";
	cin>>n;
	m=(int) (n/2);
	for (i=0;i<n;i++)
	{       cout<<"\nA["<<i+1<<"]:";
		cin>>a[i];

	}
	for (i=m-1,j=m;i>=0,j<n;i--,j++)
	{
		if(a[j]!=0)
		{	for (k=0;k<=n;k++)
				a[k]=a[k]/a[j];
				break;
		}
		if (a[i]!=0)
		{
			for (k=0;k<=n;k++)
				a[k]=a[k]/a[i];
				break;
		}
	}
	for (i=0;i<n;i++)
		cout<<a[i]<<"\t";
	getch();
}