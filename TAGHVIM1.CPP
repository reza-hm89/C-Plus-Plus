#include<stdio.h>
#include<conio.h>
void main()
{
	int i,k,x,y,z,x1,y1,row,n;
	clrscr();
	printf("                    D A Y S: ");
	printf("\nMonday:        1");
	printf("\ntuesday:       2");
	printf("\nWednesday:     3");
	printf("\nThursday:      4");
	printf("\nFriday:        5");
	printf("\nSaturday:      6");
	printf("\nSunday:        7");
	gotoxy(25,45);
	printf("Created by Reza hosseini");
	gotoxy(31,47);
	printf("09151865928");
	do {
	gotoxy(18,9);
	printf("                 ");
	gotoxy(1,9);
	printf("Enter one number: ");
	scanf("%d",&n);
	} while (n>7);
	clrscr();
	x=5;
	y=n;
	x1=1;
	y1=1;
	k=8;
	z=31;
	for (row=1;row<=12;row++)
	{
		if (row==4 || row==7 || row==10)
		{
			x1=1;
			y1+=10;
			x=5;
			if (y!=k)	y+=10;
			k=y1+7;
			if (y==k)	y=y1;
			if (y<y1)	y=k-1;
		}
		if (row==7 || row==10)	z=30;
		if (row==12)   	z=29;
		gotoxy(x1,y1);
		printf("MO");
		gotoxy(x1,y1+1);
		printf("TU");
		gotoxy(x1,y1+2);
		printf("WE");
		gotoxy(x1,y1+3);
		printf("TH");
		gotoxy(x1,y1+4);
		printf("FR");
		gotoxy(x1,y1+5);
		printf("SA");
		gotoxy(x1,y1+6);
		printf("SU");
		x=x1+5;
		for(i=1;i<=z;i++)
		{
			gotoxy(x,y);
			printf("%d",i);
			y++;
			if (y>=k)
			{
				y=y1;
				x+=3;
			}
		}
		x1=x+8;
	}
	getch();
}