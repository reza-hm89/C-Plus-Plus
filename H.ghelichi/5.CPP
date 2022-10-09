#include<stdio.h>
#include<conio.h>
void main()
{
	int n,i=0;
	clrscr();
	printf("Enter a Number:");
	scanf("%d/n",&n);
	while (n!=0)
	{
		n/=10;
		i++;
	}
	printf("Number of digits: %d",i);
	getch();
}