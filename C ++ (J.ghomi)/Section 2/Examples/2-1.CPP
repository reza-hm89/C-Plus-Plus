#include<iostream.h>
#include<conio.h>
void main()
{
	int num,i,sum=0;
	float avg;
	clrscr();
	for (i=0;i<5;i++)
	{
		cout<<"Enter Number "<<i+1<<": ";
		cin>>num;
		sum+=num;
	}
	avg=(float)sum/5;
	cout<<"Average is :"<<avg;
	getch();
}