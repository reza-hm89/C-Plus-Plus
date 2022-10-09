#include<iostream.h>
#include<conio.h>
void main()
{
	int s=0,i,n,u;
	float ave,g,sum=0;
	clrscr();
	cout<<"Enter Number of Doroos:";
	cin>>n;
	for (i=0;i<n;i++)
	{
		cout<<"Enter Your grade & unit "<<i+1<<" :";
		cin>>g>>u;
		s+=u;
		sum+=(g*u);
	}
	ave=sum/s;
	cout<<"\n\nyour Average is : "<<ave;
	getch();
}