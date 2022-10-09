#include<iostream.h>
#include<conio.h>
void main()
{
	int n;
	clrscr();
	cout<<"Enter your average: ";
	cin>>n;
	while(n)
	{
		if (n>17)
			cout<<"Grade= "<<n<<"   Score  A";
		else if (n>15)
			cout<<"Grade= "<<n<<"   Score  B";
		else if (n>12)
			cout<<"Grade= "<<n<<"   Score  C";
		else if (n>7)
			cout<<"Grade= "<<n<<"   Score  D";
		else
			cout<<"Grade= "<<n<<"   Score  E";
		cout<<"\nEnter your average: ";
		cin>>n;
	}
	getch();
}