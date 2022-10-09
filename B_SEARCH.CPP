#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	int n,i;
	cout<<"Enter n: ";
	cin>>n;
	int *a,x;
	a=new int [n];
	int low=0,high=n-1,mid;
	for (i=0;i<n;i++)
		cin>>a[i];
	cout<<"Enter x: ";
	cin>>x;
	while (low<=high)
	{
	mid=(low+high)/2;
	if (x==a[mid]) {
		cout<<"Founded";
		getch();
		return;
		}
	else if (x<a[mid])
		high=mid-1;
	else if (x>a[mid])
		low=mid+1;
	}
	cout<<"Not founded";
	getch();
}