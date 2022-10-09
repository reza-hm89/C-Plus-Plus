#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fstream.h>
//////////////////////////////////
void board();
void newpage();
void file();
void file_new();
void file_open();
void file_save();
void file_exit();
void help();
void toolbar();
void movementfile();
void movementhelp();
void openfile();
void savefile();
void show();
void showempty();
void editor();
///////////////////////////////////
int  index;
char sve[50];
char edit[25][80],hlp[25][80];
///////////////////////////////////
void main()
{
	char ch;
	int i,j;
	strcpy(sve," ");
	for (i=0;i<25;i++)
		for (j=0;j<80;j++)
			edit[i][j]=' ';
	board();
	toolbar();
	while (1) {
		ch=getch();
		if (!ch)
			ch=getch();
		switch (ch) {
			case 33:file();
				movementfile();
				break;
			case 35:help();
				movementhelp();
				break;
			case 45:exit(0);
				break;
			case 60:newpage();
				showempty();
				index=1;
				editor();
				break;
			case 61:
				if (index==0) {
					board();
					toolbar();
					openfile();
				}
				if (index==1) {
					board();
					newpage();
					toolbar();
					show();
					openfile();
					toolbar();
				}
				break;
			case 62:
				if (index==0) {
					board();
					toolbar();
					savefile();
				}
				if (index==1) {
					board();
					newpage();
					toolbar();
					show();
					savefile();					toolbar();
					}
				break;
				}
		}
}
////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
void editor()
{
	int i,j,x=2,y=3,k;
	char c,ch;
	textcolor(YELLOW);
	textbackground(1);
	for (i=3;i<23;i++)
		for (j=2;j<80;j++)
		{
			gotoxy(j,i);
			cprintf("%c",edit[i][j]);
		}
	gotoxy(x,y);
	while(1)
	{
	textcolor(YELLOW);
	textbackground(1);
	ch=getch();
		if(ch==0)
			ch=getch();
	switch(ch)
	{
		case 45:exit(0);
			break;
		case 60:newpage();
			showempty();
			index=1;
			editor();
			break;
		case 61:
			if (index==0) {
				board();
				toolbar();
				openfile();
			}
			if (index==1) {
				board();
				newpage();
				toolbar();
				show();
				openfile();
				toolbar();
			}
			break;
		case 62:
			if (index==0) {
				board();
				toolbar();
				savefile();
			}
			if (index==1) {
				board();
				newpage();
				toolbar();
				show();
				savefile();					toolbar();
				}
			break;
		case 72:
			if(y!=3)
				gotoxy(x,--y);
			break;
		case 80:
			if(y!=23)
				gotoxy(x,++y);
			break;
		case 75:
			if(x!=2)
				gotoxy(--x,y);
			else if(y!=3)
			{
				x=79;
				gotoxy(x,--y);
			}
			break;
		case 77:
			if(x!=79)
				gotoxy(++x,y);
			else if(y!=23)
			{
				x=2;
				gotoxy(x,++y);
			}
			break;
		case 27:
			return;
		case 73:
			x=2;
			y=3;
			gotoxy(x,y);
			break;
		case 81:
			x=79;
			y=23;
			gotoxy(x,y);
			break;
		case 71:
			x=2;
			gotoxy(x,y);
			break;
		case 79:
			x=79;
			gotoxy(x,y);
			break;
		case 8:
			if (x!=2)  {
			for(i=x-1;i<79;i++)
				edit[y][i]=edit[y][i+1];
			edit[y][i]=' ';
			gotoxy(--x,y);
			for(i=x;i<=79;i++)
				cprintf("%c",edit[y][i]);
			gotoxy(x,y);
			}
			else if (x==2 && y!=3) {
				for (i=79;edit[y][i]==' ';i--);
				for (j=i,k=79;j>1;j--,k--)
					edit[y-1][k]=edit[y][j];
				for (i=2;i<80;edit[y][i]=' ',i++);
				for (i=2;i<80;i++) {
				gotoxy(i,y);
				cprintf("%c",edit[y][i]);
				gotoxy(i,y-1);
				cprintf("%c",edit[y-1][i]);
				}
				x=k;
				gotoxy(x,--y);
			}
			break;
		case 83://delete
			for(i=x+1;i<79;i++)
				edit[y][i]=edit[y][i+1];
			edit[y][i]=' ';
			gotoxy(x,y);
			for(i=x;i<=79;i++)
				cprintf("%c",edit[y][i]);
			gotoxy(x,y);
			break;
		case 32://space
			if (edit[y][79]!=' ') {
			for (i=78;i>=2;i--)
			edit[y+1][i+1]=edit[y+1][i];//shift
			edit[y+1][2]=edit[y][79];
			for (j=2;j<80;j++)
			{
				gotoxy(j,y+1);
				cprintf("%c",edit[y+1][j]);
			}
			hlp[y][x]=edit[y][x];
			edit[y][79]=' ';
			}
			for (i=79;i>=x;i--)
				edit[y][i+1]=edit[y][i];
			edit[y][x]=' ';
			if (x==79) {
			x=2; y++;
			edit[y][x]=hlp[y-1][79];
			edit[y-1][79]=' ';
			gotoxy(79,y-1);
			cprintf("%c",edit[y-1][79]);
			gotoxy(2,y);
			cprintf("%c",edit[y][2]);
			}
			for (j=x;j<80;j++)
			{
				gotoxy(j,y);
				cprintf("%c",edit[y][j]);
			}
			gotoxy(++x,y);
			break;
		case 13://enter
			for (i=23;i>y;i--)
				for (j=2;j<=79;j++)
					edit[i+1][j]=edit[i][j];
			j=1;
			for (i=x-1;i<=79;i++)
				edit[y+1][j++]=edit[y][i];
			for (i=x;i<=79;i++)
				edit[y][i]=' ';
			for (i=3;i<=23;i++)
				for (j=2;j<=79;j++)
				{
					gotoxy(j,i);
					cprintf("%c",edit[i][j]);
				}
			if (y!=23) {
			x=2;
			gotoxy(x,++y); }
			gotoxy(x,y);
			break;
		default:
			if(x==79)
			{
				x=2;
				++y;
			}
			c=ch;
			i=y;
			for(j=x;j<79;j++)
			{
				gotoxy(j+1,i);
				cprintf("%c",edit[i][j]);
				hlp[i][j+1]=edit[i][j];
			}
			i=y;
			for(j=x+1;j<=79;j++)
				edit[i][j]=hlp[i][j];
			gotoxy(x,y);
			cprintf("%c",c);
			edit[y][x]=c;
			x++;
	}
    }
}
//////////////////////////////////////////////////////////////////
void movementhelp()
{
	int y=3;
	char ch;
	textbackground(7);
	help();
	textcolor(GREEN);
	gotoxy(42,3);
	cprintf("ллллллллллл");
	textcolor(0);
	textbackground(GREEN);
	gotoxy(43,3);
	cprintf("Contents");
	while (ch!=27) {
		ch=getch();
		textbackground(7);
		help();
		if (ch==80) {
			y++;
			if (y>4) y=3;
		}
		else if (ch==72) {
			y--;
			if (y<3) y=4;
		}
		textcolor(GREEN);
		gotoxy(42,y);
		cprintf("ллллллллллл");
		textcolor(0);
		textbackground(GREEN);
		switch (y) {
			case 3: gotoxy(43,3);
				cprintf("Contents");
				break;
			case 4: gotoxy(43,4);
				cprintf("About...");
				break;
		}
	}
	newpage();
}
//////////////////////////////////////////////////////////////////
void movementfile()
{
	int y=3;
	char ch;
	textcolor(GREEN);
	gotoxy(6,3);
	cprintf("ллллллллллллллл");
	textbackground(GREEN);
	file_new();
	textbackground(7);
	file_open();
	file_save();
	file_exit();
	while (ch!=27) {
		ch=getch();
		file();
		file_new();
		file_open();
		file_save();
		file_exit();
		textcolor(GREEN);
		if (ch==72) {
			y--;
			if (y<3) y=7;
			if (y==6) y=5;
		}
		else if (ch==80) {
			y++;
			if (y>7) y=3;
			if (y==6)y=7;
		}
		gotoxy(6,y);
		cprintf("ллллллллллллллл");
		textbackground(GREEN);
		switch (y) {
			case 3: file_new();
				break;
			case 4:	file_open();
				break;
			case 5: file_save();
				break;
			case 7: file_exit();
				break;
			}
		if (ch==13) {
		switch (y) {
			case 3: newpage();
				showempty();
				index=1;
				editor();
				break;
			case 4:
				if (index==0) {
					board();
					toolbar();
					openfile();
				}
				if (index==1) {
					board();
					newpage();
					toolbar();
					show();
					openfile();
					toolbar();
				}
				break;
			case 5:
				if (index==0) {
					board();
					toolbar();
					savefile();
				}
				if (index==1) {
					board();
					newpage();
					toolbar();
					show();
					savefile();
					toolbar();
				}
				break;
			case 7: exit(0);
				break;
			}
		ch=27;
		}
		}
}
//////////////////////////////////////////////////////////////////
void savefile()
{
	int i,j;
	char chr;
	textcolor(7);
	for (i=20;i<=60;i++)
	{
		gotoxy(i,10);
		cprintf("л");
		gotoxy(i,11);
		cprintf("л");
		gotoxy(i,12);
		cprintf("л");
	}
	textcolor(0);
	textbackground(7);
	gotoxy(22,10);
	cprintf("Enter your text file name to save:");
	textcolor(1);
	gotoxy(22,11);
	cprintf("ллллллллллллллллллллллллллллллллллллл");
	gotoxy(23,11);
	textcolor(YELLOW);
	textbackground(1);
	cgets(sve);
	ofstream fp(sve);
	gotoxy(10,24);
	//getch();
	for (i=3;i<24;i++)
		for (j=2;j<80;j++)
		{
			chr=edit[i][j];
			fp.put(chr);
		}
	if (index==0) {
		board();
		toolbar();
	}
	if (index==1) {
		board();
		newpage();
		show();
	}
	fp.close();
}
/////////////////////////////////////////////////////////////////
void openfile()
{
	int i,flag=0;
	char opn[50],chr;
	textcolor(7);
	for (i=20;i<=60;i++)
	{
		gotoxy(i,10);
		cprintf("л");
		gotoxy(i,11);
		cprintf("л");
		gotoxy(i,12);
		cprintf("л");
	}
	textcolor(0);
	textbackground(7);
	gotoxy(22,10);
	cprintf("Enter your text file name to open:");
	textcolor(1);
	gotoxy(22,11);
	cprintf("ллллллллллллллллллллллллллллллллллллл");
	textcolor(0);
	gotoxy(23,11);
	textcolor(YELLOW);
	textbackground(1);
	cgets(opn);
	ifstream fp(opn);
	gotoxy(10,24);
	if (!fp)
	{
		textcolor(1);
		gotoxy(22,11);
		cprintf("ллллллллллллллллллллллллллллллллллллл");
		textcolor(RED);
		gotoxy(23,11);
		cprintf("Can not open file!...");
		//getch();
		flag=1;
	}
	if (flag==0)
	{
	textcolor(15);
	textbackground(0);
	for (int i=3;i<24;i++)
		for (int j=2;j<80;j++)
		{
			gotoxy(j,i);
			fp.get(chr);
			edit[i][j]=chr;
			cprintf("%c",edit[i][j]);
		}
	strcpy(sve,opn);
	}
	if (index==0) {
		board();
		toolbar();
	}
	if (index==1) {
		board();
		newpage();
		show();
	}
	fp.close();
}
/////////////////////////////////////////////////////////////////
void file()
{
	int i,j;
	textcolor(7);
	for (i=4;i<=22;i++)
		for (j=2;j<9;j++)
		{
			gotoxy(i,j);
			cprintf("л");
		}
	textcolor(0);
	textbackground(7);
	for (i=5;i<21;i++)
	{
		gotoxy(i,2);
		cprintf("Ф");
		gotoxy(i,6);
		cprintf("Ф");
		gotoxy(i,8);
		cprintf("Ф");
	}
	for (i=3;i<8;i++)
	{
		gotoxy(5,i);
		cprintf("Г");
		gotoxy(21,i);
		cprintf("Г");
	}
	gotoxy(5,2); cprintf("к");
	gotoxy(21,2);cprintf("П");
	gotoxy(5,8); cprintf("Р");
	gotoxy(21,8);cprintf("й");
	gotoxy(5,6); cprintf("У");
	gotoxy(21,6); cprintf("Д");
}
/////////////////////////////////////////////////////
void file_new()
{
	gotoxy(7,3);
	textcolor(4);
	cprintf("N");
	gotoxy(8,3);
	textcolor(0);
	cprintf("ew        F2");
}
/////////////////////////////////////////////////////
void file_open()
{
	gotoxy(7,4);
	textcolor(4);
	cprintf("O");
	gotoxy(8,4);
	textcolor(0);
	cprintf("pen...    F3");
}
////////////////////////////////////////////////////
void file_save()
{
	gotoxy(7,5);
	textcolor(4);
	cprintf("S");
	gotoxy(8,5);
	textcolor(0);
	cprintf("ave...    F4");
}
////////////////////////////////////////////////////////
void file_exit()
{
	gotoxy(7,7);
	textcolor(4);
	cprintf("E");
	gotoxy(8,7);
	textcolor(0);
	cprintf("xit     Alt+X");
}
///////////////////////////////////////////////////////////////////
void help()
{
	int i,j;
	textcolor(7);
	for (i=40;i<55;i++)
		for (j=2;j<6;j++)
		{
			gotoxy(i,j);
			cprintf("л");
		}
	textcolor(0);
	gotoxy(41,2); cprintf("ФФФФФФФФФФФФ");
	gotoxy(41,5); cprintf("ФФФФФФФФФФФФ");
	gotoxy(41,3); cprintf("Г");
	gotoxy(41,4); cprintf("Г");
	gotoxy(53,3); cprintf("Г");
	gotoxy(53,4); cprintf("Г");
	gotoxy(41,2); cprintf("к");
	gotoxy(53,2);cprintf("П");
	gotoxy(41,5); cprintf("Р");
	gotoxy(53,5);cprintf("й");
	textcolor(0);
	gotoxy(43,3);
	cprintf("Contents");
	gotoxy(43,4);
	cprintf("About...");
}
//////////////////////////////////////////////////////////////////
void board()
{
	textmode(C80);
	clrscr();
	int i,j;
	textbackground(15);
	textcolor(15);
	for (i=1;i<=80;i++)
		for (j=1;j<=25;j++)
		{
			gotoxy(i,j);
			cprintf("л");
		}
	textcolor(15);
	for (i=1;i<=80;i++)
		for (j=1;j<25;j++)
		{
			gotoxy(i,j);
			cprintf("Б");
		}
	textcolor(7);
	for (i=1;i<=80;i++)
	{
		gotoxy(i,1);
		cprintf("л");
	}
	gotoxy(4,1);
	textcolor(4);
	cprintf("F");
	gotoxy(5,1);
	textcolor(0);
	cprintf("ile");
	/////////////////edit
	gotoxy(12,1);
	textcolor(4);
	cprintf("E");
	gotoxy(13,1);
	textcolor(0);
	cprintf("dit");
	////////////////search
	gotoxy(20,1);
	textcolor(4);
	cprintf("S");
	gotoxy(21,1);
	textcolor(0);
	cprintf("earch");
	////////////////window
	gotoxy(30,1);
	textcolor(4);
	cprintf("W");
	gotoxy(31,1);
	textcolor(0);
	cprintf("indow");
	////////////////help
	gotoxy(40,1);
	textcolor(4);
	cprintf("H");
	gotoxy(41,1);
	textcolor(0);
	cprintf("elp");
}
//////////////////////////////////////////////
void newpage()
{
	int i,j;
	textcolor(1);
	for (i=1;i<=80;i++)
		for (j=2;j<=24;j++)
		{
			gotoxy(i,j);
			cprintf("л");
		}
	textattr(15);
	textbackground(1);
	for (i=1;i<=80;i++)
	{
		gotoxy(i,2);
		cprintf("Э");
		gotoxy(i,24);
		cprintf("Э");
	}
	for (i=3;i<=23;i++)
	{
		gotoxy(1,i);
		cprintf("К");
		gotoxy(80,i);
		cprintf("К");
	}
	gotoxy(1,2);  cprintf("Щ");
	gotoxy(1,24); cprintf("Ш");
	gotoxy(80,2); cprintf("Л");
	gotoxy(80,24);cprintf("М");
	gotoxy(34,2); puts(sve);

}
//////////////////////////////////////////////////////////
void toolbar()
{
	textcolor(4);
	textbackground(7);
	gotoxy(2,25);
	cprintf("F1");
	textcolor(0);
	gotoxy(5,25);
	cprintf("Help");
	///////////////////////
	textcolor(4);
	gotoxy(13,25);
	cprintf("F2");
	textcolor(0);
	gotoxy(16,25);
	cprintf("New");
	/////////////////////////
	textcolor(4);
	gotoxy(23,25);
	cprintf("F3");
	textcolor(0);
	gotoxy(26,25);
	cprintf("Open");
	////////////////////////
	textcolor(4);
	gotoxy(34,25);
	cprintf("F4");
	textcolor(0);
	gotoxy(37,25);
	cprintf("Save");
	////////////////////////
	textcolor(4);
	gotoxy(45,25);
	cprintf("Alt+X");
	textcolor(0);
	gotoxy(51,25);
	cprintf("Exit");
}
////////////////////////////////////////////////////////
void show()
{
	int i,j;
	char ch;
	textcolor(YELLOW);
	textbackground(1);
	for (i=3;i<23;i++)
		for (j=2;j<79;j++)
		{
			gotoxy(j,i);
			cprintf("%c",edit[i][j]);
		}
}
///////////////////////////////////////////////////////////
void showempty()
{
	int i,j;
	char ch;
	textcolor(YELLOW);
	textbackground(1);
	for (i=3;i<23;i++)
		for (j=2;j<79;j++)
		{
			gotoxy(j,i);
			edit[i][j]=' ';
		}
}