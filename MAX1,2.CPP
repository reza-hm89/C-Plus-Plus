#include<iostream.h>
#include<conio.h>
void main()
{       int max1,max2,n,i,num;
	clrscr();
	cout<<"Enter n:";
	cin>>n;
	cout<<"\nEnter Number1: ";
	cin>>num;
	max1=num;
	max2=num;
	for (i=2;i<=n;i++)
	{
		cout<<"\nEnter Number"<<i<<" : ";
		cin>>num;
		if (num>max1)
		{
			max2=max1;
			max1=num;
		}
		if (max2>max1)
			max1=max2;
	}
	cout<<"max1= "<<max1<<endl;
	cout<<"max2= "<<max2;
	getch();
}

