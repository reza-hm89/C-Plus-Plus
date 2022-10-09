#include<iostream.h>
#include<conio.h>
void main()
{
	int i,j;
	clrscr();
	for (i=1;i<=10;i++)
	{	for (j=1;j<=10;j++)
			cout<<i*j<<"\t";
		cout<<"\n";
	}
	getch();
}