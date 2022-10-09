#include<stdio.h>
#include<conio.h>
int main()
{
	clrscr();
	int sum=0,i,a,b;
	int num;
	printf("Enter two numbers:\n");
	scanf("%d%d",&a,&b);
	for(i=1;i<=b;i++)
		sum+=a;
	printf("\na * b = %d",sum);
	getch();
	return 0;
}
