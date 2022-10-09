#include<iostream.h>
#include<conio.h>
int main()
{
clrscr();
int i,j,n,x,a[100];
		cout<<"Enter Number of array:";
		cin>>n;
		for (i=1;i<=n;i++)
		{
				cout<<"Enter Number "<<i<<":";
				cin>>a[i];
		}
		cout<<"Enter Your Number:";
		cin>>x;
		for (i=1;i<n;i++)
		{
				if(x==a[i])
					for (j=i;j<n;j++)
							a[j]=a[j+1];
		}
		for (i=1;i<n;i++)
				cout<<a[i]<<"\t";
getch();
return 0;
}