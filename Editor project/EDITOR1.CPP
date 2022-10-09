#include<stdio.h>
#include<conio.h>
#include<bios.h>
#include<stdlib.h>
#include<string.h>
#include<fstream.h>
/////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
const int maxrow=25,maxcol=80;
char str[maxrow][maxcol],str1[maxrow][maxcol];
char s[50]="Untitled";
//////////////////////////////////////////////////////////////
void titlebar();
void editor();
void save();
void open();
void clear();
////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
void main()
{
	int i,j;
	for(i=0;i<maxrow;i++)
		for(j=0;j<maxcol;j++)
			str[i][j]=' ';
	for(i=0;i<maxrow;i++)
		for(j=0;j<maxcol;j++)
			str1[i][j]=' ';
	textmode(C80);
	titlebar();
	editor();
	getch();
}
///////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
void titlebar()
{
	int i,j;
	clrscr();
	textbackground(7);
	textcolor(0);
	for (i=1;i<=80;i++)
		for (j=3;j<=25;j++)
		{
			gotoxy(i,j);
			cprintf("Û");
		}
	textcolor(7);
	gotoxy(1,1);
	for (i=1;i<=80;i++)
		cprintf("Û");
	textcolor(0);
	gotoxy(2,1);
	cprintf(s);
	gotoxy(30,1);
	cprintf("NOTEPAD");
	gotoxy(45,1);
	cprintf("F1=New");
	gotoxy(55,1);
	cprintf("F2=Open");
	gotoxy(65,1);
	cprintf("F3=Save");
	gotoxy(1,2);
	for(i=1;i<=80;i++)
		cprintf("~");
	gotoxy(1,24);
	for(i=0;i<80;i++)
		cprintf("~");
}
////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
void editor()
{
	int a,b,i,j,x=1,y=3,k;
	char c;
	textcolor(15);
	textbackground(0);
	for (i=3;i<=23;i++)
		for (j=1;j<80;j++)
		{
			gotoxy(j,i);
			cprintf("%c",str[i][j]);
		}
	gotoxy(x,y);
	while(1)
	{
	textcolor(15);
	textbackground(0);
	a=getch();
		if(a==0) //baraye 2kmehaye ke 2ta code ascii daran
	{
		b=getch();
		b=b+100;
		a=b;
	}
	switch(a)
	{
		case 172:// up
			if(y!=3)
				gotoxy(x,--y);
			break;
		case 180://down
			if(y!=23)
				gotoxy(x,++y);
			break;
		case 175://left
			if(x!=1)
				gotoxy(--x,y);
			else if(y!=3)
			{
				x=79;
				gotoxy(x,--y);
			}
			break;
		case 177://right
			if(x!=79)
				gotoxy(++x,y);
			else if(y!=23)
			{
				x=1;
				gotoxy(x,++y);
			}
			break;
		case 27://escape
			exit(1);
		case 13://enter
			for (i=23;i>y;i--)
				for (j=0;j<=79;j++)
					str[i+1][j]=str[i][j];
			j=0;
			for (i=x-1;i<=79;i++)
				str[y+1][j++]=str[y][i];
			for (i=x;i<=79;i++)
				str[y][i]=' ';
			for (i=3;i<=23;i++)
				for (j=1;j<=79;j++)
				{
					gotoxy(j,i);
					cprintf("%c",str[i][j]);
				}
			x=1;
			gotoxy(x,++y);
			break;
		case 173://page up
			x=1;
			y=3;
			gotoxy(x,y);
			break;
		case 181://page down
			x=79;
			y=23;
			gotoxy(x,y);
			break;
		case 171://home
			x=1;
			gotoxy(x,y);
			break;
		case 179://end
			x=79;
			gotoxy(x,y);
			break;
		case 8://back space
			if (x!=1)  {
			for(i=x-1;i<79;i++)
				str[y][i]=str[y][i+1];
			str[y][i]=' ';
			gotoxy(--x,y);
			for(i=x;i<=79;i++)
				cprintf("%c",str[y][i]);
			gotoxy(x,y);
			}
			else if (x==1 && y!=3) {
				for (i=79;str[y][i]==' ';i--);
				for (j=i,k=79;j>0;j--,k--)
					str[y-1][k]=str[y][j];
				for (i=0;i<80;str[y][i]=' ',i++);
				for (i=0;i<80;i++) {
				gotoxy(i,y);
				cprintf("%c",str[y][i]);
				gotoxy(i,y-1);
				cprintf("%c",str[y-1][i]);
				}
				x=k;
				gotoxy(x,--y);
			}
			break;
		case 183://delete
			for(i=x+1;i<79;i++)
				str[y][i]=str[y][i+1];
			str[y][i]=' ';
			gotoxy(x,y);
			for(i=x;i<=79;i++)
				cprintf("%c",str[y][i]);
			gotoxy(x,y);
			break;
		case 32://space
			if (str[y][79]!=' ') {
			for (i=78;i>=1;i--)
			str[y+1][i+1]=str[y+1][i];
			str[y+1][1]=str[y][79];
			for (j=1;j<80;j++)
			{
				gotoxy(j,y+1);
				cprintf("%c",str[y+1][j]);
			}
			str[y][79]=' ';
			}
			for (i=79;i>=x;i--)
				str[y][i+1]=str[y][i];
			if (x==79) { x=0; y++; }
			str[y][x]=' ';
			for (j=x;j<80;j++)
			{
				gotoxy(j,y);
				cprintf("%c",str[y][j]);
			}
			gotoxy(++x,y);
			break;
		case 159:strcpy(s,"Untitled");
			 clrscr();
			 titlebar();
			 clear();
			 break;
		case 160:open();
			 titlebar();
			 editor();
			 break;
		case 161:save();
			 titlebar();
			 editor();
			 break;
		default:
			if(x==79)
			{
				x=1;
				++y;
			}
			c=a;
			i=y;
			for(j=x;j<79;j++)
			{
				gotoxy(j+1,i);
				cprintf("%c",str[i][j]);
				str1[i][j+1]=str[i][j];
			}
			i=y;
			for(j=x+1;j<=79;j++)
				str[i][j]=str1[i][j];
			gotoxy(x,y);
			cprintf("%c",c);
			str[y][x]=c;
			x++;
	}//end of switch
    }// end of while 1
}
/////////////////////////////////////////////////////////
void save()
{
	char ch;
	int i=0,j;
	gotoxy(1,25);
	textcolor(8);
	textbackground(7);
	cprintf("Save:");
	gotoxy(6,25);
	textcolor(15);
	textbackground(7);
	gets(s);
	ofstream fp(s);
	if (!fp)
		cout<<"Can not open file";
	for (i=3;i<23;i++)
		for (j=0;j<80;j++)
		{
			ch=str[i][j];
			fp.put(ch);
		}
	fp.close();
	textcolor(7);
	for (i=1;i<80;i++)
		cprintf("Û");
}
/////////////////////////////////////////////////////////
void open()
{
	char ch,s1[50];
	int sw=0;
	gotoxy(1,25);
	textcolor(8);
	textbackground(7);
	cprintf("Open:");
	gets(s1);
	ifstream fp(s1);
	gotoxy(10,24);
	if (!fp)
	{
		cprintf("Can not open file");
		getch();
		strcpy(s,"Untitled");
		clrscr();
		titlebar();
		clear();
		sw=1;
	}
	if (!sw)
	{
	textcolor(15);
	textbackground(0);
	for (int i=3;i<24;i++)
		for (int j=0;j<80;j++)
		{
			gotoxy(j,i);
			fp.get(ch);
			str[i][j]=ch;
			cprintf("%c",str[i][j]);
		}
	strcpy(s,s1);
	}
}
///////////////////////////////////////
void clear()
{
	int i,j;
	for (i=0;i<25;i++)
		for (j=0;j<80;j++)
			str[i][j]=' ';
}
