#include<stdio.h>
#include<conio.h>
void main()
{
	int n,r;
	clrscr();
	printf("Enter n: ");
	scanf("%d",&n);
	while (n>0)
	{
		r=n%10;
		printf("%d\n",r);
		n/=10;
	}
	getch();
}