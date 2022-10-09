#include<stdio.h>
#include<conio.h>
void main()
{
	int n,i,s=0,sign=1;
	clrscr();
	printf("Enter N:");
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{	s=(i*sign)+s;
		sign=-sign;
	}
	printf("Sum : %d",s);
	getch();
}