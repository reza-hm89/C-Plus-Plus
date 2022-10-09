#include<conio.h>
#include<stdio.h>
void main()
{       int s,s1=0,s2=1,n,i;
	clrscr();
	printf("Enter N:");
	scanf("%d",&n);
	if (n==0)
		printf("0");
	else if (n==1)
		printf("1");
	else
	{       printf("1\t");
		for (i=2;i<=n;i++)
		{
			s=s1+s2;
			printf("%d\t",s);
			s1=s2;
			s2=s;
		}
	}
	getch();
}
