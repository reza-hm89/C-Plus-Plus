#include<stdio.h>
#include<conio.h>
int main()
{
	int sum=0,i,j;
	clrscr();
	for (j=2;j<=10000;j++)
	{
	sum=0;
	for(i=1;i<=j-1;i++)
	{
		if((j%i)==0)
			sum+=i;
	}
	if (sum==i)
		printf("%d\t",sum);
	}
	getch();
	return 0;
}
