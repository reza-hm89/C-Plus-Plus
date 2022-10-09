#include<iostream.h>
#include<conio.h>
void main()
{
	int i,j,n,t,a[100];
	clrscr();
	cout<<"Enter n: ";
	cin>>n;
	for (i=0;i<n;i++)
		cin>>a[i];
	while (a[0]) {
	for (i=1; i<=a[0] && i<n ;i++)
		a[i]=a[i]-1;
	a[0]=0;
	for (i=n-1;i>0;i--)
	{
		for (j=n;j>0;j--)
			if (a[j-1]<a[j])
			{
				t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;
			}
	}
	}//end of while
	int sw=0;
	for (i=0;i<n;cout<<a[i],i++)
		if (a[i]<0) sw=1;
	if(!sw)
		cout<<"\nGrafical";
	else
		cout<<"\nNot Grafical";
	getch();
}