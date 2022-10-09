#include<stdio.h>
#include<conio.h>
void main()
{
	int n,t=0,r,i=1;
	clrscr();
	printf("Enter a Number:");
	scanf("%d/n",&n);
	while (n!=0)
	{
		r=n%2;
		t=t+(r*i);
		i*=10;
		n/=2;
	}
	printf("%d",t);
	getch();
}