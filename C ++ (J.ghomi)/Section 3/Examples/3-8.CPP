#include<iostream.h>
#include<conio.h>
float calculate (float balance,float rate,int mon)
{
	int i;
	float ben,sben=0;
	for (i=0;i<mon;i++)
	{
		ben=balance*rate/100;
		balance+=ben;
		sben+=ben;
	}
	return sben;
}
void main()
{
	int mon;
	float balance,rate,sben;
	clrscr();
	cout<<"Enter balance,rate,mon: ";
	cin>>balance>>rate>>mon;
	sben=calculate(balance,rate,mon);
	cout<<"\nBenefit= "<<sben<<" ,Balance="<<balance;
	cout<<"\n New balance is: "<<(balance+sben);
	getch();
}
