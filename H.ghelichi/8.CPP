#include<stdio.h>
#include<conio.h>
void main()
{
	int n,num=10,t=0,r;
	clrscr();
	while (num<=10000)
	{
		n=num;
		t=0;
		while (n!=0)
		{
			r=n%10;
			t=r+(t*10);
			n/=10;
		}
	if (num==t)
		printf("%d\t",t);
		num++;
	}

	getch();
}