#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<stdio.h>

int X[100],Y[100];
int Len=6;

void LeftShift()
{
	for (int i=0;i<Len-1;i++)
	{
		X[i]=X[i+1];
		Y[i]=Y[i+1];
	}
}
void Eating(int x,int y)
{
	X[Len]=y;
	Y[Len]=x;
	Len++;
}
void main()
{
	clrscr();
	X[0]=2;Y[0]=5;
	X[1]=2;Y[1]=6;
	X[2]=2;Y[2]=7;
	X[3]=2;Y[3]=8;
	X[4]=2;Y[4]=9;
	X[5]=2;Y[5]=10;

	int point[2][200]={0};
	int i,j,k,sw,Height=25;
	int Lastvec=-1,vector=3,time=0,x=-1,y=-1,cnt=0;
	char ch;
	randomize();
	gotoxy(1,1);
	cprintf("Length of Sneak is 6");

	while (1)
	{
		if (!kbhit())
		{
			textcolor(RED);
			gotoxy(20,1);
			cprintf("%d",Len);
			textcolor(WHITE);
			if (Len>50)
			{
				textcolor(GREEN);
				gotoxy(33,Height/2);
				cprintf("Y O U    W I N");
				getch();
				getch();
				return;
			}
			for (i=0;i<Len-1;i++)
				if (X[i]==X[Len-1] && Y[i]==Y[Len-1])
				{
					textcolor(RED);
					gotoxy(33,Height/2);
					cprintf("G A M E  O V E R");
					getch();
					getch();
					return;
				}
			textcolor(WHITE);
			delay(100);
			time++;
			if (time>20)
			{
				x=random(79)+1;
				y=random(Height-1)+2;
				time=0;
				sw=0;
				for (i=0;i<Len;i++)
					if (x==Y[i] || y==X[i])
						sw=1;
				if (!sw)
				{
					point[0][cnt]=x;
					point[1][cnt]=y;
					cnt++;
					gotoxy(x,y);
					cprintf("*");
				}
			}
			for (i=0;i<Len;i++)
			{
				gotoxy(Y[i],X[i]);
				cprintf(".");
			}
				gotoxy(Y[i-1],X[i-1]);
				textcolor(LIGHTBLUE);
				cprintf("");
				textcolor(WHITE);

			if (vector==3 && Lastvec!=2)
			{
				Lastvec=3;
				for (i=0;i<cnt;i++)
					if (point[0][i]==Y[Len-1]+1 && point[1][i]==X[Len-1])
					{
						Eating(point[0][i],point[1][i]);
						for (j=i;j<cnt-1;j++)
						{
							point[0][j]=point[0][j+1];
							point[1][j]=point[1][j+1];
						}
						cnt--;
					}
				gotoxy(Y[0],X[0]);
				cout<<" ";
				LeftShift();
				Y[Len-1]++;
				if (Y[Len-1]>=80)
					Y[Len-1]=1;
			}
			if (vector==2 && Lastvec!=3)
			{
				Lastvec=2;
				for (i=0;i<cnt;i++)
					if (point[0][i]==Y[Len-1]-1 && point[1][i]==X[Len-1])
					{
						Eating(point[0][i],point[1][i]);
						for (j=i;j<cnt-1;j++)
						{
							point[0][j]=point[0][j+1];
							point[1][j]=point[1][j+1];
						}
						cnt--;
					}
				gotoxy(Y[0],X[0]);
				cout<<" ";
				LeftShift();
				Y[Len-1]--;
				if (Y[Len-1]<=1)
					Y[Len-1]=79;
			}
			else if (vector==1 && Lastvec!=0)
			{
				Lastvec=1;
				for (i=0;i<cnt;i++)
					if (point[0][i]==Y[Len-1] && point[1][i]==X[Len-1]+1)
					{
						Eating(point[0][i],point[1][i]);
						for (j=i;j<cnt-1;j++)
						{
							point[0][j]=point[0][j+1];
							point[1][j]=point[1][j+1];
						}
						cnt--;
					}
				gotoxy(Y[0],X[0]);
				cout<<" ";
				LeftShift();
				X[Len-1]++;
				if (X[Len-1]>Height)
					X[Len-1]=2;
			}
			else if (vector==0 && Lastvec!=1)
			{
				Lastvec=0;
				for (i=0;i<cnt;i++)
					if (point[0][i]==Y[Len-1] && point[1][i]==X[Len-1]-1)
					{
						Eating(point[0][i],point[1][i]);
						for (j=i;j<cnt-1;j++)
						{
							point[0][j]=point[0][j+1];
							point[1][j]=point[1][j+1];
						}
						cnt--;
					}
				gotoxy(Y[0],X[0]);
				cout<<" ";
				LeftShift();
				X[Len-1]--;
				if (X[Len-1]<2)
					X[Len-1]=Height;
			}
		}
		else
		{
			ch=getch();
			switch(ch)
			{
				case 72:
					if (Lastvec!=1)
						vector=0;
					break;
				case 80:
					if (Lastvec!=0)
						vector=1;
					break;
				case 75:
					if (Lastvec!=3)
						vector=2;
					break;
				case 77:
					if (Lastvec!=2)
						vector=3;
					break;
				case 27:return;
			}
		}
	}
}