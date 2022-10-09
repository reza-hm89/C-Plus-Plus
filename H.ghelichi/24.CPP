#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int x,i=1,sign=1;
	float sum=0,f=1,s=1;
	clrscr();
	printf("Enter  x ( sin(x) ): ");
	scanf("%d",&x);
	while (i<=(2*x)-1)
	{
		s*=x;
		f*=i;
		sum=((s/f)*sign)+sum;
		sign=-sign;
		i++;
	}
	printf("\n%f",sum);
	getch();
	return 0;
}
