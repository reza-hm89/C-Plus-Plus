#include<conio.h>
#include<stdio.h>
#include<iostream.h>
#include<string.h>
void main()
{
	int i,index,max=0,a[11];
	clrscr();
	for (i=1;i<=10;i++)
	{
		printf("Enter a number %d:",i);
		scanf("%d",&a[i]);
		if (a[i]>max)
		{
			max=a[i];
			index=i;
		}
	}
	printf("Max & index of max : %d%5d",max,index);
	getch();
}