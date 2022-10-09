#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
	clrscr();
	int i,j;
	/////////////////////////////
	textbackground(1);
	window(1,1,80,50);
	textcolor(15);
	for (i=2;i<80;i++)
		for (j=2;j<50;j++)
		{
			gotoxy(i,j);
			cprintf(" ");
		}
	for (j=5;j<=25;j+=2)
		for (i=15;i<=65;i++)
		{
			gotoxy(i,j);
			cout<<"-";
		}
	for (i=15;i<=65;i+=5)
		for (j=5;j<=25;j++)
		{
			gotoxy(i,j);
			cout<<"|";
		}
	for (i=1,j=17;i<=10;i++,j+=5)
	{
		gotoxy(j,3);
		cprintf("%d",i);
	}
	for (i=1,j=6;i<=10;i++,j+=2)
	{
		gotoxy(13,j);
		cprintf("%d",i);
	}
	gotoxy(1,26);
	cout<<"(x,y)=";
	////////////////////////////////
	int a[11][11];
	int n,k,x,y,inc=0;
	for (i=1;i<=10;i++)
		for (j=1;j<=10;j++)
		a[i][j]=2;
	gotoxy(1,1);
	cout<<"Enter numbers of Boomb: ";
	cin>>n;
	randomize();
	for (k=0;k<n;)
	{
		i=(random(10))+1;
		j=(random(10))+1;
		if (a[i][j]!=0)
		{
			a[i][j]=0;
			k++;
		}
	}
	do {
	gotoxy(8,26);
	cout<<"           ";
	gotoxy(8,26);
	do {
	gotoxy(8,26);
	cout<<"  ";
	gotoxy(8,26);
	cin>>i;
	} while (i>10);
	do {
	gotoxy(11,26);
	cin>>j;
	} while (j>10);
	for (k=0,x=17;k<j;k++,x+=5);
	for (k=0,y=6;k<i;k++,y+=2);
	gotoxy(x-5,y-2);
	if (a[i][j]) {
		a[i][j]=1;
		textcolor(GREEN);
		cprintf("%d",a[i][j]);
		if ((a[i-1][j-1]!=0) && (a[i-1][j]!=0) && (a[i-1][j+1]!=0))
		{
		if (i>1) {
			a[i-1][j]=1;
			gotoxy(x-5,y-4);
			cout<<a[i-1][j];
			}
		}
		if ((a[i+1][j-1]!=0) && (a[i+1][j]!=0) && (a[i+1][j+1]!=0))
		{
		if (i<10) {
			a[i+1][j]=1;
			gotoxy(x-5,y);
			cout<<a[i+1][j];
			}
		}
		if ((a[i-1][j-1]!=0) && (a[i][j-1]!=0) && (a[i+1][j-1]!=0))
		{
		if (j>1) {
			a[i][j-1]=1;
			gotoxy(x-10,y-2);
			cout<<a[i][j-1];
			}
		}
		if ((a[i-1][j+1]!=0) && (a[i][j+1]!=0) && (a[i+1][j+1]!=0))
		{
		if (j<10) {
			a[i][j+1]=1;
			gotoxy(x,y-2);
			cout<<a[i][j+1];
		}
		}
		if (a[i-1][j-1]) {
		if (a[i-1][j] && a[i-1][j+1] && a[i][j-1] && a[i+1][j-1])
		{
		if (i>1 && j>1) {
			a[i-1][j-1]=1;
			gotoxy(x-10,y-4);
			cout<<a[i-1][j-1];
			}
		}
		}
		if (a[i-1][j+1]) {
		if (a[i-1][j] && a[i-1][j-1] && a[i][j+1] && a[i+1][j+1])
		{
		if (i>1 && j<10) {
			a[i-1][j+1]=1;
			gotoxy(x,y-4);
			cout<<a[i-1][j+1];
			}
		}
		}
		if (a[i+1][j+1]) {
		if (a[i][j+1] && a[i-1][j+1] && a[i+1][j] && a[i+1][j-1])
		{
		if (i<10 && j<10) {
			a[i+1][j+1]=1;
			gotoxy(x,y);
			cout<<a[i+1][j+1];
			}
		}
		}
		if (a[i+1][j-1]) {
		if (a[i][j-1] && a[i-1][j-1] && a[i+1][j] && a[i+1][j+1])
		{
		if (i<10 && j>1) {
			a[i+1][j-1]=1;
			gotoxy(x-10,y);
			cout<<a[i+1][j-1];
			}
		}
		}
	}
	else {
		for (i=1,y=6;i<=10;i++,y+=2)
		{
			for (j=1,x=17;j<=10;j++,x+=5)
				if (a[i][j]==0)
				{
					textcolor(RED);
					gotoxy(x,y);
					cprintf("b");
				}
		}
	break;
	}
	for (int i1=1;i1<=10;i1++) {
		for (int j1=1;j1<=10;j1++)
			if (a[i1][j1]==1)
				inc++;
		}
	if (inc==100-n)
	{
		for (i=1,y=6;i<=10;i++,y+=2)
		{
			for (j=1,x=17;j<=10;j++,x+=5)
				if (a[i][j]==0)
				{
					textcolor(RED);
					gotoxy(x,y);
					cprintf("b");
				}
		}
		gotoxy(40,12);
		cprintf("Y O U   W I N");
		getch();
		break;
	}
	} while (a[i][j]!=0);
	getch();
}