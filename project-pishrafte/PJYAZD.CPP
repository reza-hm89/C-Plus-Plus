#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream.h>
void enter_d();
void menu();
struct  student{
	char name[30],family[30],pedar[50];
	long int shsh,code,id;
	float ave;
	int dars[2][50];
	char namedars[50][20];
	}st;
void menu()
{
int driver=DETECT,mode;
initgraph(&driver,&mode,"c:\\tc\\bgi");
cleardevice();
setbkcolor(6);
setfillstyle(8,4);
bar(1,1,640,480);
settextstyle(7,0,4);
setcolor(14);
outtextxy(225,15,"Enter data");
setcolor(8);
outtextxy(240,70,"Show list");
outtextxy(220,125,"Show units");
outtextxy(202,180,"Unit selection");
outtextxy(202,235," Enter grades");
outtextxy(285,300,"Edit");
outtextxy(270,365,"Search");
outtextxy(285,430,"Exit");
}
////////////////////////////////////////////////////////////
void arrow()
{
char ch=5;
int y=1;
while (ch!=27)
{
	ch=getch();
	if (!ch)
	ch=getch();
	if (ch==80 || ch==72)
	{
		setcolor(8);
		switch (y) {
		case 1:outtextxy(225,15,"Enter data");
		break;
		case 2:outtextxy(240,70,"Show list");
		break;
		case 3:outtextxy(220,125,"Show units");
		break;
		case 4:outtextxy(202,180,"Unit selection");
		break;
		case 5:outtextxy(202,235," Enter grades");
		break;
		case 6:outtextxy(285,300,"Edit");
		break;
		case 7:outtextxy(270,365,"Search");
		break;
		case 8:outtextxy(285,430,"Exit");
		}
	switch (ch){
	case 80:y++;
		break;
	case 72:y--;
	break;
	}
	if (y>8)
		y=1;
	if (y<1)
		y=8;
	}
	setcolor(14);
	switch (y) {
		case 1:outtextxy(225,15,"Enter data");
		break;
		case 2:outtextxy(240,70,"Show list");
		break;
		case 3:outtextxy(220,125,"Show units");
		break;
		case 4:outtextxy(202,180,"Unit selection");
		break;
		case 5:outtextxy(202,235," Enter grades");
		break;
		case 6:outtextxy(285,300,"Edit");
		break;
		case 7:outtextxy(270,365,"Search");
		break;
		case 8:outtextxy(285,430,"Exit");
	}
	if (ch==13)
	{
		switch (y){
		case 1:enter_d();
		break;
		case 8:exit(0);
		break;
		}
	}

}
}
//////////////////////////////////////////////////////////
void enter_d()
{
	restorecrtmode();
	textmode(LASTMODE);
	ofstream fp("data.dat",ios::app|ios::binary);
	while (1) {
	clrscr();
	textcolor(6);
	gotoxy(20,2);
	textcolor(6);
	cprintf("name:");
	textcolor(15);
	cin>>st.name,20;
	if (!st.name[0])
	{
		setgraphmode(getgraphmode());
		fp.close();
		menu();
		arrow();
	}
	gotoxy(20,4);
	textcolor(6);
	cprintf("Family:");
	textcolor(15);
	gets(st.family);
	gotoxy(20,6);
	textcolor(6);
	cprintf("Father:");
	textcolor(15);
	gets(st.pedar);
	textcolor(6);
	gotoxy(20,8);
	cprintf("shomare sh:");
	textcolor(15);
	cin>>st.shsh;
	textcolor(6);
	gotoxy(20,10);
	cprintf("code melli:");
	textcolor(15);
	cin>>st.code;
	textcolor(6);
	gotoxy(20,12);
	cprintf("Average:");
	textcolor(15);
	cin>>st.ave;
	fp.write((char*)&st,sizeof(struct student));
	}
 }
 ////////////////////////////////////////////////////////
void main()
{

	menu();
	arrow();
	getch();
}