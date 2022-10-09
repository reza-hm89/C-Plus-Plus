#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int n,s=0,r;
	clrscr();
	printf("Enter n: ");
	scanf("%d",&n);
	while (n!=0)
	{
		r=n%10;
		s+=r;
		n/=10;
	}
	if (s==9)
		printf("Adad bar 9 bakhsh pazir ast");
	else
		printf("Adad bar 9 bakhsh pazir nist");
	getch();
	return 0;
}
