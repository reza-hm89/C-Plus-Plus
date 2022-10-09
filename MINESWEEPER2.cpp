#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<stdlib.h>
#include<time.h>
/////////////////////////////////////////////////
void Table(int);
void Move(int,int,int);
void Movement(int);
int  Calculate(int,int,int,int,int);
void Print(int,int,int);
int  Bomb(int);
int  Win(int);
void Time1();
void Input();
int find(int,int);
void Help();
void Help_count();
void Menu();
void Difficulty();
void Random(int);
/////////////////////////////////////////////////
short int Difficult=1;
int a[20][20];
struct time t1,t2;
int sec,min,help=6;
/////////////////////////////////////////////////
void main()
{
	int d=DETECT,m=0;
	initgraph(&d,&m,"c:\\tc\\bgi");
	Menu();
}
/////////////////////////////////////////////////
void Input()
{
	int n;
	for (int i=0;i<20;i++)
		for (int j=0;j<20;j++)
			a[i][j]=0;
	sec=min=0;
	restorecrtmode();
	textmode(LASTMODE);
	textbackground(1);
	clrscr();
	textcolor(15);
	do {
	gotoxy(45,1);
	cout<<"                                  ";
	gotoxy(1,1);
	cprintf("Enter a Number between 2-12 for draw Puzzle: ");
	cin>>n;
	} while (n<2 || n>12);
	Random(n);
	Table(n);
	Movement(n);
	Menu();
	return;
}
/////////////////////////////////////////////////
void Table(int n)
{
	int i,j,k,incCol=4,incRow=4;
	clrscr();
	textcolor(15);
	for (j=1;j<=incRow*n+1;j+=incRow)
		for (i=1;i<=incCol*n;i++)
		{
			gotoxy(i,j);
			cprintf("อ");
		}
	for (i=(incCol/2+1),k=1;i<incCol*n;i+=incCol,k++)
	{
		gotoxy(i,j-incRow+1);
		cprintf("%d",k);
	}
	for (i=1;i<=incCol*n+incCol;i+=incCol)
		for (j=1;j<=incRow*n+1;j++)
		{
			gotoxy(i,j);
			cprintf("บ");
			if (!(j%incRow)) {
				gotoxy(i,++j);
				cprintf("ฮ");
			}
		}
	for (j=(incRow/2+1),k=1;j<=incRow*n;j+=incRow,k++)
	{
		gotoxy(i-incCol+2,j);
		cprintf("%d",k);
	}
	for (i=incCol+1;i<n*incCol;i+=incCol)
	{
		gotoxy(i,1);
		cprintf("ห");
	}
	for(j=1;j<n*incRow;j+=incRow)
	{
		gotoxy(i,j);
		cprintf("น");
	}
	gotoxy(i,1);
	cprintf("ป");
	gotoxy(i,j);
	cprintf("ผ");
	for (i=incRow+1;i<n*incRow;i+=incRow)
	{
		gotoxy(1,i);
		cprintf("ฬ");
	}
	for(j=incCol+1;j<n*incCol;j+=incCol)
	{
		gotoxy(j,i);
		cprintf("ส");
	}
	gotoxy(1,1);
	cprintf("ษ");
	gotoxy(1,i);
	cprintf("ศ");
}
//////////////////////////////////////////////////////
void Move(int x,int y,int c)
{
	textcolor(c);
	gotoxy(x,y);
	cprintf("ฺฤฟ");
	gotoxy(x,y+1);
	cprintf("ณ");
	gotoxy(x+2,y+1);
	cprintf("ณ");
	gotoxy(x,y+2);
	cprintf("ภฤู");
	gotoxy(80,50);

}
/////////////////////////////////////////////////////
void Movement(int n)
{
	int x=2,y=2;
	int i=0,j=0;
	char ch='a';
	Move(x,y,15);
	gotoxy(70,45);
	textcolor(WHITE);
	Help();
	cprintf("Help=");
	cout<<help;
	gotoxy(70,49);
	cprintf("Time:");
	while(ch!=27)
	{
		Time1();
		ch=getch();
		Move(x,y,1);
		if (ch==72)
		{
			y-=4;
			if (y<2)
				y=4*n-2;
			i--;
			if (i<0)
				i=n-1;
		}
		if (ch==80)
		{
			y+=4;
			if (y>(4*n))
				y=2;
			i++;
			if (i>n-1)
				i=0;
		}
		else if (ch==75)
		{
			x-=4;
			if (x<2)
				x=4*n-2;
			j--;
			if (j<0)
				j=n-1;
		}
		else if (ch==77)
		{
			x+=4;
			if (x>(n*4))
				x=2;
			j++;
			if (j>n-1)
				j=0;
		}
		else if (ch==13)
		{
			if (Calculate(i,j,x,y,n))
				return;
			if (Win(n))
				return;
		}
		else if (ch=='h')
		{
			if (help>0)
			{
				if (find(i,j))
				{
					Help_count();
					Print(x+1,y+1,YELLOW);
					a[i][j]=1;
				}
				gotoxy(75,45);
				cout<<help;
				if (Win(n))
					return;
			}
		}
		Move(x,y,15);
	}
}
///////////////////////////////////////////////////////
int Calculate(int i,int j,int x,int y,int n)
{
	if (a[i][j]==0)
	{
		a[i][j]=1;
		Print(x+1,y+1,GREEN);
		if ((a[i-1][j-1]!=2) && (a[i-1][j]!=2) && (a[i-1][j+1]!=2))
		{
		if (i>0 && a[i-1][j]!=1) {
			a[i-1][j]=1;
			Print(x+1,y-3,YELLOW);
			}
		}
		if ((a[i+1][j-1]!=2) && (a[i+1][j]!=2) && (a[i+1][j+1]!=2))
		{
		if (i<n-1 && a[i+1][j]!=1) {
			a[i+1][j]=1;
			Print(x+1,y+5,YELLOW);
			}
		}
		if ((a[i-1][j-1]!=2) && (a[i][j-1]!=2) && (a[i+1][j-1]!=2))
		{
		if (j>0 && a[i][j-1]!=1) {
			a[i][j-1]=1;
			Print(x-3,y+1,YELLOW);
			}
		}
		if ((a[i-1][j+1]!=2) && (a[i][j+1]!=2) && (a[i+1][j+1]!=2))
		{
		if (j<n-1 && a[i][j+1]!=1) {
			a[i][j+1]=1;
			Print(x+5,y+1,YELLOW);
			}
		}
		if (a[i-1][j-1]!=2) {
		if (a[i-1][j]!=2 && a[i-1][j+1]!=2 && a[i][j-1]!=2 && a[i+1][j-1]!=2)
		{
		if (i>0 && j>0 && a[i-1][j-1]!=1) {
			a[i-1][j-1]=1;
			Print(x-3,y-3,YELLOW);
			}
		}
		}
		if (a[i-1][j+1]!=2) {
		if (a[i-1][j]!=2 && a[i-1][j-1]!=2 && a[i][j+1]!=2 && a[i+1][j+1]!=2)
		{
		if (i>0 && j<n-1 && a[i-1][j+1]!=1) {
			a[i-1][j+1]=1;
			Print(x+5,y-3,YELLOW);
			}
		}
		}
		if (a[i+1][j+1]!=2) {
		if (a[i][j+1]!=2 && a[i-1][j+1]!=2 && a[i+1][j]!=2 && a[i+1][j-1]!=2)
		{
		if (i<n-1 && j<n-1 && a[i+1][j+1]!=1) {
			a[i+1][j+1]=1;
			Print(x+5,y+5,YELLOW);
			}
		}
		}
		if (a[i+1][j-1]!=2) {
		if (a[i][j-1]!=2 && a[i-1][j-1]!=2 && a[i+1][j]!=2 && a[i+1][j+1]!=2)
		{
		if (i<n-1 && j>0 && a[i+1][j-1]!=1) {
			a[i+1][j-1]=1;
			Print(x-3,y+5,YELLOW);
			}
		}
		}
	}
	else if (a[i][j]==2)
	{
		Bomb(n);
		return 1;
	}
	return 0;
}
///////////////////////////////////////////////////////
void Print(int x,int y,int c)
{
	textcolor(c);
	gotoxy(x,y);
	cprintf("1");
}
///////////////////////////////////////////////////////
int Win(int n)
{
	int i,j,incWin=0,incLost=0;
	int x=2,y=2;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
		{
			if (a[i][j]==1)
				incWin++;
			if (a[i][j]==2)
				incLost++;
		}
	if (incWin==n*n-incLost)
	{
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
			{
				if (a[i][j]==2)
				{
					textcolor(RED);
					gotoxy(x+1,y+1);
					cprintf("B");
				}
				x+=4;
				if (x>4*n)
				{
					x=2;
					y+=4;
				}
			}
		textcolor(RED);
		gotoxy(57,2);
		cprintf("***Y O U     W I N***");
		getch();
		return 1;
	}//end if
	return 0;
}
///////////////////////////////////////////////////////
void Random(int n)
{
	int i=0,j=0,k=0,r,x,n2;
	n2=n*n;
	r=n2/3;
	randomize();
	if (Difficult==1)
		x=random(r)+1;
	if (Difficult==2)
		x=random(r)+r;
	if (Difficult==3)
		x=random(r)+r+r;
	randomize();
	rand();
	while (k<=x)
	{
		i=random(n);
		j=random(n);
		if (a[i][j]!=2) {
			a[i][j]=2;
			k++;
			}
	}
}
///////////////////////////////////////////////////////
int Bomb(int n)
{
	int i,j,x=2,y=2;
	textcolor(RED);
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
		{
			if (a[i][j]==2)
			{
				gotoxy(x+1,y+1);
				cprintf("B");
			}
			x+=4;
			if (x>4*n)
			{	x=2;
				y+=4;
			}
		}
	gotoxy(55,2);
	cprintf("***Y O U     L O S T***");
	getch();
	return 1;
}
///////////////////////////////////////////////////////
void Menu()
{
	int i,j,k,z,x,y;
	char s='a';
	setgraphmode(getgraphmode());
	cleardevice();
	setbkcolor(9);
	setcolor(15);
	setfillstyle(1,15);
	for (j=313,i=300;j<=213,i<=425;i++,j--)
	{	outtextxy(i,200,"อ");
		outtextxy(j,200,"อ");
	}
	///////////  KADR    /////////////////////////////////
	for (i=200,j=200,k=197,z=202;i>=50,j<=350,k<=350,z>=50;z-=4,k+=4,i-=4,j+=4)
	{	outtextxy(190,i,"ออออออออออออออออออออออออออออออ");
		setfillstyle(1,9);
		bar(190,i+6,430,i+8);
		outtextxy(190,j,"ออออออออออออออออออออออออออออออ");
		setfillstyle(1,9);
		bar(190,j-4,430,j);
		outtextxy(183,k,"บ");
		outtextxy(429,k,"บ");
		outtextxy(183,z,"บ");
		outtextxy(429,z,"บ");
	}
	outtextxy(429,48,"ป");
	outtextxy(429,352,"ผ");
	outtextxy(183,352,"ศ");
	outtextxy(183,48,"ษ");
	////////// End KADR     //////////////////////////////
	settextstyle(7,0,1);
	setcolor(59);
	delay(200);
	outtextxy(240,100,"New Game");
	delay(200);
	outtextxy(240,175,"Difficulty");
	delay(200);
	outtextxy(240,250,"Exit");
	x=220;
	y=112;
	setcolor(BLUE);
	setfillstyle(1,BLUE);
	fillellipse(x,y,10,10);
	while (1)
	{
		s=getch();
		setcolor(9);
		setfillstyle(1,9);
		fillellipse(x,y,10,10);
		if (s==80)
		{
			y+=75;
			if (y>262)
				y=112;
		}
		else if (s==72)
		{
			y-=75;
			if (y<112)
				y=262;
		}
		else if (s==13 && y==112)
		{
			Input();
			return;
		}
		else if (s==13 && y==187)
			Difficulty();
		else if (s==13 && y==262)
			exit(0);
		setcolor(BLUE);
		setfillstyle(1,BLUE);
		fillellipse(x,y,10,10);
	}
}
///////////////////////////////////////////////
void Difficulty()
{
	char ch='a';
	int y=1;
	settextstyle(1,0,1);
	setcolor(15);
	line(340,190,350,190);
	line(350,150,365,150);
	line(350,225,365,225);
	line(350,150,350,225);
	setcolor(YELLOW);
	outtextxy(360,155,"Easy");
	setcolor(59);
	outtextxy(360,175,"Normal");
	outtextxy(360,195,"Hard");
	while(ch!=75)
	{
		ch=getch();
		switch (y) {
			case 1: setcolor(59);
				outtextxy(360,155,"Easy");
				break;
			case 2: setcolor(59);
				outtextxy(360,175,"Normal");
				break;
			case 3: setcolor(59);
				outtextxy(360,195,"Hard");
				break;
			}
		if (ch==72) {
			y--;
			if (y<1)
				y=3;
			}
		if (ch==80) {
			y++;
			if (y>3)
				y=1;
			}
		else if (ch==13)
			Difficult=y;
		switch (y) {
			case 1: setcolor(YELLOW);
				outtextxy(360,155,"Easy");
				break;
			case 2: setcolor(YELLOW);
				outtextxy(360,175,"Normal");
				break;
			case 3: setcolor(YELLOW);
				outtextxy(360,195,"Hard");
				break;
			}
	}
	setfillstyle(1,LIGHTBLUE);
	bar(340,140,430,230);
}
////////////////////////////////////////////////////////
void Time1()
{
	gettime(&t1);
	gettime(&t2);
	while (!kbhit()) {
		gettime(&t2);
		if (t2.ti_sec>t1.ti_sec) {
			gotoxy(75,49);
			cout<<"     ";
			gotoxy(75,49);;
			cout<<min<<":"<<sec++;
			if (sec>=59) {
				min++;
				sec=0;
			}
		}
		gettime(&t1);
	}
}
void Help()
{
	if (Difficult==1)
		help=6;
	if (Difficult==2)
		help=3;
	if (Difficult==3)
		help=1;
}
///////////////////////////////////////////
void Help_count()
{
	help--;

	if (help<0)
		help=0;
}
///////////////////////////////////
int find(int i,int j)
{
	if (a[i][j]==0)
		return 1;
	return 0;
}