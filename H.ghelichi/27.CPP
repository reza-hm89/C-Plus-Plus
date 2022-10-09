#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int n,s=0,r,x=1;
	clrscr();
	printf("Enter n: ");
	scanf("%d",&n);
	while (n!=0)
	{
		r=n%10;
		if (r==1)
			s+=x;
		x*=2;
		n/=10;
	}
	printf("\n%d",s);
	getch();
	return 0;
}
