#include <iostream.h>
#include<conio.h>
#include<stdlib.h>

int a[8][8],b[8][8];
int Player1,Player2;
int X,Y;
int Current=1;

void  BackGround()
{
	int i,j;

	gotoxy(1,1);
	cout<<"  1 2 3 4 5 6 7 8";
	cout<<"\n\n1\n\n2\n\n3\n\n4\n\n5\n\n6\n\n7\n\n8";

	for (i=2;i<=18;i+=2)
	{

		for (j=2;j<=17;j++)
		{
			gotoxy(j,i);
			cprintf("-");
		}
	}

	for (i=2;i<=18;i+=2)
	{
		for (j=2;j<=18;j++)
		{
			gotoxy(i,j);
			cprintf("|");
		}
	}

	gotoxy(11,9);	cprintf("1");
	gotoxy(9,11);	cprintf("1");
	gotoxy(9,9);	cprintf("2");
	gotoxy(11,11);	cprintf("2");

	gotoxy(25,1); cprintf("Player1: ");
	gotoxy(25,2); cprintf("Player2: ");
	gotoxy(25,4); cprintf("Current: ");

}

void GOTOXY()
{
	gotoxy(1,20);
	cout<<"Enter your choice: (1<X<8 & 1<Y<8)";
	gotoxy(1,21);
	cout<<"X= ";
	gotoxy(1,22);
	cout<<"Y= ";
	do {
		gotoxy(4,21);
		cin>>X;
		gotoxy(4,22);
		cin>>Y;
		gotoxy(4,22);
		cprintf("         ");
		gotoxy(4,21);
		cprintf("         ");


	}while ((X<1 && X>8) || (Y<1 && Y>8));

}

void Find_Correct(int i,int j,int enemy)
{
	int x=i,y=j;

	if (x>0 && y>0 && a[x-1][y-1]==0)
	{
		while (i<7 && j<7 && a[i][j]==enemy)
		{
			i++;
			j++;
		}
		if (a[i][j]==Current)
			b[x-1][y-1]=1;
	}

	i=x; j=y;

	if (x<7 && y<7 && a[x+1][y+1]==0)
	{
		while (i>0 && j>0 && a[i][j]==enemy)
		{
			i--;
			j--;
		}
		if (a[i][j]==Current)
			b[x+1][y+1]=1;
	}

	i=x; j=y;

	if (x>0 && y<7 && a[x-1][y+1]==0)
	{
		while (i<7 && j>0 && a[i][j]==enemy)
		{
			i++;
			j--;
		}
		if (a[i][j]==Current)
			b[x-1][y+1]=1;
	}

	i=x; j=y;

	if (x<7 && y>0 && a[x+1][y-1]==0)
	{
		while (i>0 && j<7 && a[i][j]==enemy)
		{
			i--;
			j++;
		}
		if (a[i][j]==Current)
			b[x+1][y-1]=1;
	}

	i=x; j=y;

	if (x>0 && a[x-1][y]==0)
	{
		while (i<7 && a[i][j]==enemy)
		{
			i++;
		}
		if (a[i][j]==Current)
			b[x-1][y]=1;
	}

	i=x; j=y;

	if (x<7 && a[x+1][y]==0)
	{
		while (i>0 && a[i][j]==enemy)
		{
			i--;
		}
		if (a[i][j]==Current)
			b[x+1][y]=1;
	}

	i=x; j=y;

	if (y>0 && a[x][y-1]==0)
	{
		while (j<7 && a[i][j]==enemy)
		{
			j++;
		}
		if (a[i][j]==Current)
			b[x][y-1]=1;
	}

	i=x; j=y;

	if (y<7 && a[x][y+1]==0)
	{
		while (j>0 && a[i][j]==enemy)
		{
			j--;
		}
		if (a[i][j]==Current)
			b[x][y+1]=1;
	}
}

void Set_Position(int i,int j,int enemy)
{
	int x=i,y=j;
	int x1=2*i+3,y1=2*j+3;

	if(i<7 && j<7 && a[i+1][j+1]==enemy)
	{
		do {
			i++;j++;
			x1+=2;y1+=2;

		} while (i<7 && j<7 && a[i][j]==enemy);

		if (a[i][j]==Current)
		{
			while (i>=x && j>=y)
			{
				gotoxy(y1,x1);
				cprintf("%d",Current);
				a[i--][j--]=Current;
				x1-=2; y1-=2;
			}
		}
	}

	i=x; j=y; x1=2*x+3; y1=2*y+3;

	if(i>0 && j<7 && a[i-1][j+1]==enemy)
	{
		do {
			i--; j++;
			x1-=2; y1+=2;


		} while (i>0 && j<7 && a[i][j]==enemy);

		if (a[i][j]==Current)
			while (i<=x && j>=y)
			{
				gotoxy(y1,x1);
				cprintf("%d",Current);
				a[i++][j--]=Current;
				x1+=2; y1-=2;
			}

	}

	i=x; j=y; x1=2*x+3; y1=2*y+3;

	if(i<7 && j>0 && a[i+1][j-1]==enemy)
	{
		do {
			i++; j--;
			x1+=2; y1-=2;

		} while ( i<7 && j>0 && a[i][j]==enemy);
		if (a[i][j]==Current)
			while (i>=x && j<=y)
			{
				gotoxy(y1,x1);
				cprintf("%d",Current);
				a[i--][j++]=Current;
				x1-=2; y1+=2;
			}
	}

	i=x; j=y; x1=2*x+3; y1=2*y+3;

	if(i>0 && j>0 && a[i-1][j-1]==enemy)
	{
		do {
			i--; j--;
			x1-=2; y1-=2;

		} while (i>0 && j>0 && a[i][j]==enemy);

		if (a[i][j]==Current)
			while (i<=x && j<=y)
			{
				gotoxy(y1,x1);
				cprintf("%d",Current);
				a[i++][j++]=Current;
				x1+=2; y1+=2;
			}
	}

	i=x; j=y; x1=2*x+3; y1=2*y+3;

	if(i<7 && a[i+1][j]==enemy)
	{
		do {
			i++;
			x1+=2;

		} while (i<7 && a[i][j]==enemy);

		if (a[i][j]==Current)
			while (i>=x)
			{
				gotoxy(y1,x1);
				cprintf("%d",Current);
				a[i--][j]=Current;
				x1-=2;
			}
	}

	i=x; j=y; x1=2*x+3; y1=2*y+3;

	if(i>0 && a[i-1][j]==enemy)
	{
		do {
			i--;
			x1-=2;

		} while (i>0 && a[i][j]==enemy);

		if (a[i][j]==Current)
			while (i<=x)
			{
				gotoxy(y1,x1);
				cprintf("%d",Current);
				a[i++][j]=Current;
				x1+=2;
			}
	}

	i=x; j=y; x1=2*x+3; y1=2*y+3;
	if(j<7 && a[i][j+1]==enemy)
	{
		do {
			j++;
			y1+=2;

		} while (j<7 && a[i][j]==enemy);

		if (a[i][j]==Current)
			while (j>=y)
			{
				gotoxy(y1,x1);
				cprintf("%d",Current);
				a[i][j--]=Current;
				y1-=2;
			}
	}

	i=x; j=y; x1=2*x+3; y1=2*y+3;

	if(j>0 && a[i][j-1]==enemy)
	{
		do {
			j--;
			y1-=2;

		} while (j>0 && a[i][j]==enemy);

		if (a[i][j]==Current)
			while (j<=y)
			{
				gotoxy(y1,x1);
				cprintf("%d",Current);
				a[i][j++]=Current;
				y1+=2;
			}
	}
}

void Find()
{
	int i,j;
	if (Current==1)
	{
		for (i=0;i<8;i++)
			for (j=0;j<8;j++)
				if (a[i][j]==2)
					Find_Correct(i,j,2);
	}
	else if (Current==2)
	{
		for (i=0;i<8;i++)
			for (j=0;j<8;j++)
				if (a[i][j]==1)
					Find_Correct(i,j,1);
	}
}

void main()
{
	clrscr();

	int enemy=2,temp;
	a[3][4]=a[4][3]=1;
	a[3][3]=a[4][4]=2;

	BackGround();

	while (getch()!=27)
	{
		gotoxy(34,4);
		cout<<Current;

		Find();
		temp=0;
		for (int i=0;i<8;i++)
			for (int j=0;j<8;j++)
				if (b[i][j]==1)
					temp=1;
		if (temp==0)
		{
			if (Player1>Player2)
			{
				gotoxy(30,10);
				cout<<"Player1 WIN";
			}
			else if (Player1<Player2)
			{
				gotoxy(30,10);
				cout<<"Player2 WIN";
			}
		}

		GOTOXY();

		if (b[X-1][Y-1]==1)
		{
			Set_Position (X-1,Y-1,enemy);

		temp=Current;
		Current=enemy;
		enemy=temp;
		}
		else
		{
			gotoxy(1,24);
			cout<<"Invalid choice";
			getch();
			gotoxy(1,24);
			cout<<"                ";
		}
		Player1=Player2=0;
		for (i=0;i<8;i++)
		for (j=0;j<8;j++)
		{
			if (a[i][j]==1)
				Player1++;
			else if (a[i][j]==2)
				Player2++;

			b[i][j]=0;
		}
		gotoxy(33,1);
		cout<<Player1;
		gotoxy(33,2);
		cout<<Player2;
	}

}