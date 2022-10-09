#include<iostream.h>
#include<conio.h>

float Sin(float x)
{
	int sign=1;
	float sum=0,p,f;
	for (int i=1;i<=13;i++)
	{
		f=p=1;
		for ( int j=1;j<=(2*i-1);j++)
		{
			p*=x;
			f*=j;
		}
		sum+=(p/f)*sign;
		sign=-sign;
	}
	return sum;
}

float Cos(float x)
{
	int sign=1;
	float sum=0,p,f;
	for (int i=1;i<=13;i++)
	{
		f=p=1;
		for (int j=1;j<=2*i-2;j++)
		{
			p*=x;
			f*=j;
		}
		sum+=p/f*sign;
		sign=-sign;
	}
	return sum;
}

void main()
{
	int a,b,i,n;
	float avg,sum=0;
	char ch;

	clrscr();
	cout<<"Enter 'c' for cos(x)  or  's' for sin(x): ";
	cin>>ch;
	cout<<"\nEnter a,b for domain [a,b]: ";
	cin>>a>>b;
	cout<<"\nEnter N for divide the function: ";
	cin>>n;

	avg=(float)((a-b)/n);

	if (ch=='c')
	{
		float temp=a;
		for (i=0;i<n && temp<=b;i++)
		{
			sum+=0.5*(Cos(temp)+Cos(temp+avg))*avg;
			temp+=avg;
		}
	}
	else if (ch=='s')
	{
		float temp=a;
		for (i=0;i<n && temp<=b;i++)
		{
			sum+=0.5*(Sin(temp)+Sin(temp+avg))*avg;
			temp+=avg;
		}
	}
	cout<<"\nResult: "<<sum;
	getch();
}