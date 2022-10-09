#include<stdio.h>
#include<conio.h>
void main()
{
	int n,num,t=0,r;
	clrscr();
	printf("Enter a Number:");
	scanf("%d/n",&num);
	n=num;
	while (n!=0)
	{
		r=n%10;
		t=r+(t*10);
		n/=10;
	}
	if (num==t)
		printf("Adad mosavi ast.");
	else
		printf("Adad mosavi nist.");
	getch();
}