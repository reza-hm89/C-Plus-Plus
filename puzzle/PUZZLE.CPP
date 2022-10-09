#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
void main()
{
	int i,j=5,k=0,s,i1=0,j1=0,a[4][4],index=0;
	clrscr();
	gotoxy(31,3);
	textcolor(11);
	cprintf("Created by Reza H.M");
	gotoxy(1,1);
	cout<<"\"ESC\" for exit the game";
	randomize();
	while (k<15)
	{
		index=0;
		s=(random(15)+1);
		for (i=0;i<4;i++)
			for (j=0;j<4;j++)
				if (s==a[i][j])
					index=1;
		if (index==0)
		{
			a[i1][j1++]=s;
			k++;
		}
		if (j==3){
			i1++;
			j1=0;
		}
	}
	a[3][3]=0;
	j=5;
	while (j<46)
	{
		for (i=20;i<=60;i++)
		{
			gotoxy(i,j);
			cout<<"-";
			gotoxy(i,j);
			cout<<"-";
		}
		j+=10;
	}
	j=20;
	while (j<61)
	{
		for (i=5;i<=45;i++)
		{
			gotoxy(j,i);
			cout<<"|";
			gotoxy(j,i);
			cout<<"|";
		}
		j+=10;
	}
	i=10; j=25;
	i1=0; j1=0;
	k=0;
	while (i<=45)
	{
		j=25;
		while (j<=55)
		{
			gotoxy(j,i);
			cout<<a[i1][j1++];
			j+=10;
			if (j==3) {
				i1++;
				j1=0;
			}
		}
		i+=10;
	}
	gotoxy(55,40);
	cout<<"     ";
	int c;
	gotoxy(55,40);
	int x=3,y=3,t;
	i1=3; j1=3;
	i=55; j=40;
	c=getch();
	while (c!=27)
	{
		if (c==80)
		{
			i1++;
			if (i1>3) i1=3;
			t=a[i1][j1];
			a[i1][j1]=a[x][y];
			a[x][y]=t;
			gotoxy(i,j);
			cout<<a[x][y];
			x++;
			if (x>3)  x=3;
			j+=10;
			if (j>40)	j=40;
			gotoxy(i,j);
			cout<<"  ";
		}
		else if (c==72)
		{
			i1--;
			if (i1<0) i1=0;
			t=a[i1][j1];
			a[i1][j1]=a[x][y];
			a[x][y]=t;
			gotoxy(i,j);
			cout<<a[x][y];
			x--;
			if (x<0)  x=0;
			j-=10;
			if (j<10)	j=10;
			gotoxy(i,j);
			cout<<"  ";
		}
		else if (c==75)
		{
			j1--;
			if (j1<0) j1=0;
			t=a[i1][j1];
			a[i1][j1]=a[x][y];
			a[x][y]=t;
			gotoxy(i,j);
			cout<<a[x][y];
			y--;
			if (y<0)  y=0;
			i-=10;
			if (i<25) 	i=25;
			gotoxy(i,j);
			cout<<"  ";
		}
		else if (c==77)
		{
			j1++;
			if (j1>3) j1=3;
			t=a[i1][j1];
			a[i1][j1]=a[x][y];
			a[x][y]=t;
			gotoxy(i,j);
			cout<<a[x][y];
			y++;
			if (y>3)  y=3;
			i+=10;
			if (i>55) 	i=55;
			gotoxy(i,j);
			cout<<"  ";
		}
		if (a[0][0]==1 && a[0][1]==2 && a[0][2]==3 && a[0][3]==4 &&
		a[1][0]==5 && a[1][1]==6 && a[1][2]==7 && a[1][3]==8 &&
		a[2][0]==9 && a[2][1]==10 && a[2][2]==11 && a[2][3]==12 &&
		a[3][0]==13 && a[3][1]==14 && a[3][2]==15)
		{
			gotoxy(33,1);
			textcolor(10);
			cprintf("Y O U    W I N");
			c=27;
			delay(2000);
			getch();
		}
		else
			c=getch();
	}
}