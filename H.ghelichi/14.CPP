#include<conio.h>
#include<stdio.h>
void main()
{
	int n,i,index=0;
	clrscr();
	printf("Enter n:");
	scanf("%d",&n);
	if (n==2 || n==1)
		printf("Adad aval ast");
	else
	{
	for (i=2;i<=n/2;i++)
	{
		if (n%i==0)
			index=1;
	}
	if (index==0)
		printf("Adad aval ast");
	else
		printf("Adad aval nist");
	}
	getch();
}