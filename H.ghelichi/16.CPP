#include<conio.h>
#include<stdio.h>
#include<iostream.h>
#include<string.h>
void main()
{
	int n,i,j,t,ave,max1,max2;
	char ch[20],name1[20],name2[20];
	clrscr();
	printf("Enter Number of student:");
	scanf("%d",&n);
	printf("\nEnter your average:");
	scanf("%d",&ave);
	printf("\nEnter your Name:");
	cin.get(ch,20);
	cin.get();
	max1=max2=ave;
	strcpy(name1,ch);
	strcpy(name2,ch);
	for (i=2;i<=n;i++)
	{
		printf("\nEnter your average:");
		scanf("%d",&ave);
		printf("\nEnter your Name:");
		cin.get(ch,20);
		cin.get();
		if (ave>max1)
		{       max2=max1;
			max1=ave;
			strcpy(name2,name1);
			strcpy(name1,ch);
		}
		else if (ave>max2)
		{	max2=ave;
			strcpy(name2,ch);
		}
	}
	/*if (max2>max1)
	{       t=max1;
		max1=max2;
		max2=t;
	} */
	printf("\nMax 1 =%d\tName= %c",max1,name1);
	printf("\nMax 2 =%d\tName= %c",max2,name2);
	getch();
}