#include <iostream.h>
#include<conio.h>
#include<stdlib.h>
//=============================================
//Define public var
int a[9][9],b[8][8];
int cur=1,against=2;
int p1,p2;
//=============================================
//Define Function
void Find_Place();
void GameOver();
void Cur_Move(int,int);
void Set_Value(int,int,int,int);
//=============================================
void Clear_B()
{
	int i,j;

	for (i=0;i<8;i++)
		for (j=0;j<8;j++)
			b[i][j]=0;
}
//=============================================
void Counter()
{
	int i,j;

	p1=p2=0;

	for (i=0;i<8;i++)
		for (j=0;j<8;j++)
		{
			if (a[i][j]==1)
				p1++;
			if (a[i][j]==2)
				p2++;
		}

}
//=============================================
void  Border()
{
	int i,j;

	textcolor(WHITE);

	for (i=1;i<=25;i+=3)
	{
		for (j=1;j<=32;j++)
		{
			gotoxy(j,i);
			cprintf("л");
		}
	}
	for (i=1;i<=35;i+=4)
	{
		for (j=1;j<=25;j++)
		{
			gotoxy(i,j);
			cprintf("л");
		}
	}

	textcolor(RED);
	gotoxy(19,11);	cprintf("*");
	gotoxy(15,14);	cprintf("*");
	textcolor(YELLOW);
	gotoxy(15,11);	cprintf("*");
	gotoxy(19,14);	cprintf("*");

	textcolor(WHITE);
	gotoxy(45,5); cprintf("RED   : ");
	gotoxy(45,6); cprintf("YELLOW: ");
	gotoxy(45,8); cprintf("Current: ");

	a[3][4]=a[4][3]=1;
	a[3][3]=a[4][4]=2;
}
//=============================================
void Cursor(int i,int j,int color)
{
	textcolor(color);
	gotoxy(i,j);  cprintf("ллллл");
	gotoxy(i,j+1);cprintf("л");
	gotoxy(i+4,j+1);  cprintf("л");
	gotoxy(i,j+2);cprintf("л");
	gotoxy(i+4,j+2);  cprintf("л");
	gotoxy(i,j+3);cprintf("ллллл");
}
//=============================================
void Movement()
{
	int i=1,j=1,temp;
	int x=0,y=0;
	char ch;

	Cursor(i,j,GREEN);
	Find_Place();

	while (ch!=27)
	{
		Counter();
		textcolor(LIGHTBLUE);
		gotoxy(54,8); cprintf("      ");
		gotoxy(54,8);
		if (cur==1) cprintf("RED");
		if (cur==2) cprintf("YELLOW");

		textcolor(LIGHTBLUE);

		gotoxy(52,5); cprintf("   ");
		gotoxy(52,6); cprintf("   ");
		gotoxy(52,5); cprintf("%d",p1);
		gotoxy(52,6); cprintf("%d",p2);

		ch=getch();

		gotoxy(50,12);
		cprintf("                ");

		Cursor(i,j,WHITE);

		if (ch==72)
		{
			j-=3; if (j<1) j=22;
			x--;  if (x<0) x=7;
		}
		else if (ch==80)
		{
			j+=3; if (j>22) j=1;
			x++;  if (x>7)  x=0;
		}
		else if (ch==77)
		{
			i+=4; if (i>29) i=1;
			y++;  if (y>7)  y=0;
		}
		else if (ch==75)
		{
			i-=4; if (i<1) i=29;
			y--;  if (y<0) y=7;
		}
		else if (ch==13)
		{
			if (b[x][y]==1)
			{
				a[x][y]=cur;

				if (cur==1)
					textcolor(RED);
				else
					textcolor(YELLOW);

				gotoxy(i+2,j+1); cprintf("*");

				Set_Value(x,y,i,j);

				temp=cur;
				cur=against;
				against=temp;

				Counter();

				Clear_B();

				Find_Place();
			}
			else
			{
				textcolor(RED);
				gotoxy(50,12);
				cprintf("                ");
				gotoxy(50,12);
				cprintf("Invalid Movment!");
			}
		}

		Cursor(i,j,GREEN);
	}
}
//=============================================
void Find_Place()
{
	int i,j,sw=0;
	if (cur==1)
	{
		for (i=0;i<8;i++)
		{
			for (j=0;j<8;j++)
				if (a[i][j]==2)
					Cur_Move(i,j);
		}
	}
	else
	{
		for (i=0;i<8;i++)
		{
			for (j=0;j<8;j++)
				if (a[i][j]==1)
					Cur_Move(i,j);
		}
	}

	for (i=0;i<8;i++)
		for (j=0;j<8;j++)
			if (b[i][j]==1)
				sw=1;
	if (sw==0)
	{
		Counter();
		GameOver();
	}
}
//=============================================
void Cur_Move(int i,int j)
{
	int x=i,y=j;

	if (x>0 && y>0 && a[x-1][y-1]==0)
	{
		while (i<7 && j<7 && a[i][j]==against)
		{
			i++;
			j++;
		}
		if (a[i][j]==cur)
			b[x-1][y-1]=1;
	}

	i=x; j=y;

	if (x<7 && y<7 && a[x+1][y+1]==0)
	{
		while (i>0 && j>0 && a[i][j]==against)
		{
			i--;
			j--;
		}
		if (a[i][j]==cur)
			b[x+1][y+1]=1;
	}

	i=x; j=y;

	if (x>0 && y<7 && a[x-1][y+1]==0)
	{
		while (i<7 && j>0 && a[i][j]==against)
		{
			i++;
			j--;
		}
		if (a[i][j]==cur)
			b[x-1][y+1]=1;
	}

	i=x; j=y;

	if (x<7 && y>0 && a[x+1][y-1]==0)
	{
		while (i>0 && j<7 && a[i][j]==against)
		{
			i--;
			j++;
		}
		if (a[i][j]==cur)
			b[x+1][y-1]=1;
	}

	i=x; j=y;

	if (x>0 && a[x-1][y]==0)
	{
		while (i<7 && a[i][j]==against)
		{
			i++;
		}
		if (a[i][j]==cur)
			b[x-1][y]=1;
	}

	i=x; j=y;

	if (x<7 && a[x+1][y]==0)
	{
		while (i>0 && a[i][j]==against)
		{
			i--;
		}
		if (a[i][j]==cur)
			b[x+1][y]=1;
	}

	i=x; j=y;

	if (y>0 && a[x][y-1]==0)
	{
		while (j<7 && a[i][j]==against)
		{
			j++;
		}
		if (a[i][j]==cur)
			b[x][y-1]=1;
	}

	i=x; j=y;

	if (y<7 && a[x][y+1]==0)
	{
		while (j>0 && a[i][j]==against)
		{
			j--;
		}
		if (a[i][j]==cur)
			b[x][y+1]=1;
	}
}
//=============================================
void Set_Value(int i,int j,int i1,int j1)
{
	int x=i,y=j,m=i1,n=j1;

	if (cur==1)
		textcolor(RED);
	else
		textcolor(YELLOW);


	if(i<7 && j<7 && a[i+1][j+1]==against)
	{
		do {
			i++; i1+=4;
			j++; j1+=3;

		} while (i<7 && j<7 && a[i][j]==against);

		if (a[i][j]==cur)
		{

			while (i>x && j>y)
			{
				gotoxy(i1+2,j1+1);
				cprintf("*");
				a[i--][j--]=cur;
				i1-=4; j1-=3;
			}
		}
	}

	i=x; j=y; i1=m; j1=n;

	if(i>0 && j<7 && a[i-1][j+1]==against)
	{
		do {
			i--; i1+=4;
			j++; j1-=3;

		} while (i>0 && j<7 && a[i][j]==against);

		if (a[i][j]==cur)
			while (i<x && j>y)
			{
				gotoxy(i1+2,j1+1);
				cprintf("*");
				a[i++][j--]=cur;
				i1-=4; j1+=3;
			}

	}

	i=x; j=y; i1=m; j1=n;

	if(i<7 && j>0 && a[i+1][j-1]==against)
	{
		do {
			i++; i1-=4;
			j--; j1+=3;

		} while ( i<7 && j>0 && a[i][j]==against);
		if (a[i][j]==cur)
			while (i>x && j<y)
			{
				gotoxy(i1+2,j1+1);
				cprintf("*");
				a[i--][j++]=cur;
				i1+=4; j1-=3;
			}
	}

	i=x; j=y; i1=m; j1=n;

	if(i>0 && j>0 && a[i-1][j-1]==against)
	{
		do {
			i--;  i1-=4;
			j--;  j1-=3;

		} while (i>0 && j>0 && a[i][j]==against);

		if (a[i][j]==cur)
			while (i<x && j<y)
			{
				gotoxy(i1+2,j1+1);
				cprintf("*");
				a[i++][j++]=cur;
				i1+=4; j1+=3;
			}
	}

	i=x; j=y; i1=m; j1=n;

	if(i<7 && a[i+1][j]==against)
	{
		do {
			i++;
			j1+=3;

		} while (i<7 && a[i][j]==against);

		if (a[i][j]==cur)
			while (i>x)
			{
				gotoxy(i1+2,j1+1);
				cprintf("*");
				a[i--][j]=cur;
				j1-=3;
			}
	}

	i=x; j=y; i1=m; j1=n;

	if(i>0 && a[i-1][j]==against)
	{
		do {
			i--;
			j1-=3;

		} while (i>0 && a[i][j]==against);

		if (a[i][j]==cur)
			while (i<x)
			{
				gotoxy(i1+2,j1+1);
				cprintf("*");
				a[i++][j]=cur;
				j1+=3;
			}
	}

	i=x; j=y; i1=m; j1=n;

	if(j<7 && a[i][j+1]==against)
	{
		do {
			j++;
			i1+=4;

		} while (j<7 && a[i][j]==against);

		if (a[i][j]==cur)
			while (j>y)
			{
				gotoxy(i1+2,j1+1);
				cprintf("*");
				a[i][j--]=cur;
				i1-=4;
			}
	}

	i=x; j=y; i1=m; j1=n;

	if(j>0 && a[i][j-1]==against)
	{
		do {
			j--;
			i1-=4;

		} while (j>0 && a[i][j]==against);

		if (a[i][j]==cur)
			while (j<y)
			{
				gotoxy(i1+2,j1+1);
				cprintf("*");
				a[i][j++]=cur;
				i1+=4;
			}
	}
}
//=============================================
void GameOver()
{
	if (p1>p2)
	{
		textcolor(RED);
		gotoxy(50,14);
		cprintf("R E D     W I N");
	}
	else if (p1<p2)
	{
		textcolor(YELLOW);
		gotoxy(50,14);
		cprintf("Y E L L O W     W I N");
	}
	getch();
	exit(0);
}
//=============================================
void main()
{
	clrscr();
	Border();
	Movement();
	getch();
}