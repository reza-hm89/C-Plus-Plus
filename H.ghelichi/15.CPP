#include<conio.h>
#include<stdio.h>
void main()
{
	int n,i,j,index=0;
	clrscr();
	for (i=3;i<1000;i++)
	{
		index=0;
		for (j=2;j<=i/2;j++)
		{	if (i%j==0)
				index=1;
		}
	if (index==0)
		printf("%d\t",i);
	}
	getch();
}