#include<stdio.h>
#include<conio.h>
void main()
{
	int n,x,i;
	float s=1,f=1,sum=1;
	clrscr();
	printf("Enter N & X:");
	scanf("%d%d",&n,&x);
	if (n==1)
		printf("e^x : 1");
	else
	{
		for (i=1;i<=n-1;i++)
		{
			s*=x;
			f*=i;
			sum+=(s/f);
		}
	}
	printf("\ne^x : %f",sum);
	getch();
}