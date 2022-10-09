#include<stdio.h>
#include<conio.h>
void main()
{
	int n,i,s=0;
	clrscr();
	printf("Enter N:");
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		s+=i;
	printf("Sum : %d",s);
	getch();
}