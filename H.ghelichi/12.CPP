#include<conio.h>
#include<stdio.h>
void main()
{
	int n,i,sum=0,j=1;
	clrscr();
	printf("Enter n:");
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		sum+=j;
		j+=2;
	}
	printf("\nSum : %d",sum);
	getch();
}