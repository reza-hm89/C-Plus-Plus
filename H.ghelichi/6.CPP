#include<stdio.h>
#include<conio.h>
void main()
{
	int n,t=0,r;
	clrscr();
	printf("Enter a Number:");
	scanf("%d/n",&n);
	while (n!=0)
	{
		r=n%10;
		t=r+(t*10);
		n/=10;
	}
	printf("Number is: %d",t);
	getch();
}