#include<conio.h>
#include<stdio.h>
#include<iostream.h>
#include<string.h>
void main()
{
	int i,ave,sum=0,a[10];
	clrscr();
	for (i=1;i<=10;i++)
	{
		printf("Enter average %d:",i);
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	ave=sum/10;
	printf("Average of students average : %d",ave);
	for (i=1;i<10;i++)
		if (a[i]<ave)
			printf("\n%d",a[i]);
	getch();
}