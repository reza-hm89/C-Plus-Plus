#include<stdio.h>
#include<conio.h>
void main()
{
	int x,i,f=1,p=1,sign=-1;
	float sum=1;
	clrscr();
	printf("Enter x: ");
	scanf("%d",&x);
	for (i=1;i<=4;i++)
	{
		f*=i;
		p*=x;
		sum+=(float)(f/p)*sign;
		sign=-sign;
	}
	printf("%f",sum);
	getch();
}