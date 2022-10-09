#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	float n;
	long int m;
	clrscr();
	printf("Enter a number ( 0<n<1 ): ");
	scanf("%f",&n);
	while (1)
	{	if (n!=floor(n))
			n*=10;
		else  break;
	}
	m=n;
	printf("\n%i",m);
	getch();
	return 0;
}
