#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	int n,i;
	cout<<"Enter n: ";
	cin>>n;
	int *a,x,j;
	a=new int [n];
	for (i=0;i<n;i++)
		cin>>a[i];
	for (i=1;i<n;i++)
	{
		x=a[i];
		j=i-1;
		while (j>=0 && x<a[j])
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=x;
	}
	for (i=0;i<n;i++)
		cout<<a[i]<<"\t";
	getch();
}