#include<stdio.h>
#include<conio.h>
void main()
{
	int n,r;
	clrscr();
	printf("Enter a Number:");
	scanf("%d/n",&n);
	while (n!=0)
	{
		r=n%10;
		printf("%3d",r);
		n/=10;
	}
	getch();
}