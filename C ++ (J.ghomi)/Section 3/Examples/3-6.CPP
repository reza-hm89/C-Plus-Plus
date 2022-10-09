#include<iostream.h>
#include<conio.h>
unsigned long fact(int);
void main()
{
	int n;
	clrscr();
	cout<<"Enter a positive integers number: ";
	cin>>n;
	cout<<"\n Number= "<<n<<" , fact= "<<fact(n);
	getch();
}
unsigned long fact(int n)
{
	if (n!=0)
		return(n* fact(n-1));
	return 1;
}