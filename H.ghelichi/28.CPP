#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int a,b,c,x1,x2,delta;
	clrscr();
	printf("Enter a,b,c: ");
	scanf("%d%d%d",&a,&b,&c);
	delta=(b*b)-(4*a*c);
	if (delta>0)
	{
		x1=(-b+sqrt(delta))/(2*a);
		x2=(-b-sqrt(delta))/(2*a);
		printf("X1 = %d\tX2= %d",x1,x2);
	}
	else if (delta==0)
	{
		x1=(-b)/(2*a);
		printf("X = %d",x1);
	}
	else
		printf ("mo'adele risheye haghighi nadard");

	getch();
	return 0;
}
