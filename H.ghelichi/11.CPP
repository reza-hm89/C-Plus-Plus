#include<conio.h>
#include<stdio.h>
void main()
{
	int n,i,num;
	clrscr();
	printf("Enter Number of students:");
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		printf("\nEnter Your average: ");
		scanf("%d",&num);
		if (num>18)
			printf("Rank is: A");
		else if (num>15)
			printf("Rank is: B");
		else if (num>12)
			printf("Rank is: C");
		else if (num>9)
			printf("Rank is: D");
		else
			printf("Rank is: E");
	}
	getch();
}