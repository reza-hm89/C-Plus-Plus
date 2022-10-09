#include<stdio.h>
#include<conio.h>
void main()
{
	int n,i;
	clrscr();
	printf("Enter n: ");
	scanf("%d",&n);
	for (i=1;i<=n/2;i++)
	{
		if (n%i==0 && i%2==0)
			printf("%d\t",i);
	}
	getch();
}