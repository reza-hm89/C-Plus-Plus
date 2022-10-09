#include<conio.h>
#include<stdio.h>
void main()
{
	int n,i=0,sum=0,j=1;
	clrscr();
	printf("Enter n:");
	scanf("%d",&n);
	while (sum<n)
	{
		sum+=j;
		j+=2;
		i++;
	}
	if (i*i==n)
		printf("\nJazr : %d",i);
	else
		printf("\nAdad jazr sahih nadarad");
	getch();
}