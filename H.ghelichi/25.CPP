#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int n,s;
	clrscr();
	printf("Enter n: ");
	scanf("%d",&n);
	if (n%2==0)
		s=3*n-7;
	else
		s=4*n+5;
	printf("%d",s);
	getch();
	return 0;
}
