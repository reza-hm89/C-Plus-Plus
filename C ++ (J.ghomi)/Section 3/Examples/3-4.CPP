#include<iostream.h>
#include<conio.h>
int prime(int);
void main()
{
	int n;
	char ans='y';
	clrscr();
	while (ans=='y')
	{
	cout<<"Enter your number: ";
	cin>>n;
	if (!prime(n))
		cout<<"\nNumber "<<n<<" is prime";
	else
		cout<<"\nNumber "<<n<<" is not prime";
	cout<<"\nDo you want to coninue?(y/n) : ";
	cin>>ans;
	}
	getch();
}
int prime(int n)
{
	int index=0,i;
	for (i=2;i<=n/2;i++)
		if (n%i==0)
			index=1;
	return index;
}