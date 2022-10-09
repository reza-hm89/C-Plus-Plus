#include<iostream.h>
#include<conio.h>
int main()
{
	clrscr();
	int n,num,i,a[100],index=0;
	cout<<"Enter Number of Array:";
	cin>>n;
	for (i=1;i<=n;i++)
		cin>>a[i];
	clrscr();
	cout<<"\nEnter Your Number:";
	cin>>num;
	for (i=1;i<=n;i++)
		if(num==a[i])
			index=1;
	if (index==0)
	{
		n++;
		a[n]=num;
	}
	for (i=1;i<=n;i++)
		cout<<a[i]<<"\t";

	getch();
	return 0;
}
