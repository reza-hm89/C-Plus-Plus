#include<stdio.h>
#include<conio.h>
int main()
{
	clrscr();
	int sum=0,i;
	int num;
	printf("Enter your number:\n");
	scanf("%d",&num);
	for(i=1;i<=num-1;i++)
	{
		if((num%i)==0)
			sum+=i;
	}
	if (sum==num)
		printf("\nYour Number is Kamel");
	else
		printf("\nYour number is not kamel");

	getch();
	return 0;
}
