#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
#include<ctype.h>

void initmouse();
void yesmouse(); //show mouse
void mouse();  //get mouse postion and button status
void board();
void chart();
void rate();
void error_infix();
void input();
void insert();
///////////////////////////
int row,col,status;
/////////////////////////////////////////////
void initmouse()
{
	row=0,col=0,status=0;
	asm {
		mov ax,0;
		int 33h;
	}
}
//////////////////////////////////////////////
void yesmouse()
{
	asm {
		 mov ax,1; //1 mean show
		 int 33h;
	}
}
/////////////////////////////////////////////
void mouse()
{
	 asm {
		  mov ax,3;
		  int 33h;
		  mov row,dx;
		  mov col,cx;
		  mov status,bx;
	 }
}
////////////////////////////////////////////
void board()
{
	setbkcolor(0);
	//////////////////////////
	setcolor(57);
	setfillstyle(1,1);
	bar(0,0,639,479);
	rectangle(0,0,639,479);
	rectangle(1,1,638,478);
	rectangle(2,2,637,477);
	setfillstyle(1,57);
	bar(0,0,639,20);
	//////////////////////////
	setcolor(7);
	rectangle(615,1,635,19);
	rectangle(617,3,633,17);
	setcolor(15);
	line(616,2,634,2);
	line(616,2,616,18);
	setcolor(56);
	line(634,2,634,18);
	line(616,18,634,18);
	setfillstyle(1,4);
	bar(618,4,632,16);
	/////////////////////////
	setcolor(62);//yellow
	line(620,5,630,15);
	line(630,5,620,15);
	/////////////////////////
	settextstyle(2,0,6);
	outtextxy(200,1,"*** Function & Chart ***");
	/////////////////////////
	//rasme iinfix
	setcolor(7);
	rectangle(9,24,131,41);
	rectangle(11,26,129,39);
	setcolor(WHITE);
	line(10,25,130,25);
	line(10,25,10,40);
	setcolor(8);
	line(10,40,130,40);
	line(130,25,130,40);
	setfillstyle(1,8);
	bar(12,27,128,38);
	setcolor(WHITE);
	settextstyle(2,0,5);
	outtextxy(20,24,"Infix Function");
	setfillstyle(1,7);
	bar(135,24,630,41);
}
/////////////////////////////////////////
void chart()
{
	setfillstyle(1,15);
	bar(15,120,625,465);
	setcolor(7);
	bar(15,120,625,465);
	rectangle(16,121,624,464);
	setfillstyle(1,8);
	bar(16,121,624,140);
	///////////////////////
	setcolor(7);
	line(25,290,615,290);
	line(310,145,310,460);
	///////////////////////
	//  '>' '^'
	line(610,285,615,290);
	line(610,295,615,290);
	line(305,150,310,144);
	line(310,144,315,150);
}
////////////////////////////////////////////
void error_infix()
{
	setfillstyle(1,7);
	bar(200,150,420,230);
	setfillstyle(1,8);
	//bar(202,152,418,162);
	setcolor(8);
	rectangle(199,149,421,231);
	rectangle(201,151,419,229);
	setfillstyle(1,RED);
	setcolor(8);
	circle(220,180,15);
	pieslice(220,180,1,360,15);
	setcolor(RED);
	line(220,180,235,180);
	setcolor(15);
	line(215,170,225,190);
	line(225,170,215,190);
	outtextxy(240,170,"Error Inputing Function!");
	setcolor(8);
	rectangle(290,200,330,215);
	rectangle(288,198,332,217);
	setcolor(15);
	line(289,199,331,199);
	line(289,199,289,216);
	setcolor(BROWN);
	line(289,216,331,216);
	line(331,199,331,216);
	outtextxy(305,200,"OK");
}
////////////////////////////////////////////
void var()
{
	int i=0,cntr=0;
	while (cntr<8)  {
	setfillstyle(1,7);
	bar(15+i,60,80+i,75);
	i+=78;  cntr++;     }
}
////////////////////////////////////////////
void rate()
{
	setcolor(15);
	outtextxy(15,90,"From");
	outtextxy(135,90,"To");
	outtextxy(245,90,"Accuracy Rate");
	setfillstyle(1,7);
	bar(55,90,125,105);
	bar(155,90,225,105);
	bar(360,90,430,105);
	////////////////////////
	//button rate
	setcolor(7);
	rectangle(498,83,602,112);
	rectangle(500,85,600,110);
	setcolor(WHITE);
	line(499,84,601,84);
	line(499,84,499,111);
	setcolor(8);
	line(601,84,601,111);
	line(499,111,601,111);
	setfillstyle(1,8);
	bar(501,86,599,109);
	setcolor(WHITE);
	settextstyle(2,0,5);
	outtextxy(510,90,"Draw Chart");
	//setfillstyle(1,7);
       //	bar(135,24,630,41);
}
////////////////////////////////////////////
void insert()
{
	while (!kbhit())
	{
		mouse();
		if ((row>=86) && (row<=109) && (col>=501) && (col<=599) && (status==1))
		{
			setcolor(8);
			line(499,84,601,84);
			line(499,84,499,111);
			setcolor(15);
			line(601,84,601,111);
			line(499,111,601,111);
			delay(200);
			setcolor(WHITE);
			line(499,84,601,84);
			line(499,84,499,111);
			setcolor(8);
			line(601,84,601,111);
			line(499,111,601,111);
			chart();
		}
		if((row>=1) && (row<=19) && (col>=615) && (col<=635) && (status==1))
		{
			setcolor(56);
			line(616,2,634,2);
			line(616,2,616,18);
			setcolor(15);
			line(634,2,634,18);
			line(616,18,634,18);
			delay(200);
			setcolor(15);
			line(616,2,634,2);
			line(616,2,616,18);
			setcolor(56);
			line(634,2,634,18);
			line(616,18,634,18);
			return;
		}
		if((row>=27) && (row<=38) && (col>=12) && (col<=128) && (status==1))
		{
			setcolor(8);
			line(10,25,130,25);
			line(10,25,10,40);
			setcolor(15);
			line(10,40,130,40);
			line(130,25,130,40);
			delay(200);
			setcolor(WHITE);
			line(10,25,130,25);
			line(10,25,10,40);
			setcolor(8);
			line(10,40,130,40);
			line(130,25,130,40);
			input();
		}
	}//while kbhit()
	getch();
}
////////////////////////////////////////////
void input()
{
	while (!kbhit()) {
	delay(150);
	setcolor(8);
	outtextxy(145,25,"|");
	delay(150);
	setcolor(7);
	outtextxy(145,25,"|");
	}
	int j=153,i=145,k=0;
	char s[1],ch,in[100];
	ch=getch();
	s[0]=NULL;
	moveto(145,25);
	while(ch!=13) {
	setcolor(2);
	if (ch==8){
		moveto(155-i,25);
		setfillstyle(1,7);
		bar(j,24,j-8,41);
		j-=8;
		if (j<145)  j=153;
		i=j;
		k--;
		}
	else {
		s[0]=ch;
		in[k++]=s[0];
		outtextxy(i,25,s);
		i+=8;
		j=i;
	}
	ch=getch();
	} //while ch!=13
	in[k]=NULL;
	cout<<in;
	getch();
}
////////////////////////////////////////////
void graphics_mode()
{
	int d=DETECT,m=DETECT;
	initgraph(&d,&m,"c:\\tc\\bgi");
}
///////////////////////////////////////////
void main()
{
	initmouse();
	graphics_mode();
	cleardevice();
	board();
	yesmouse();
	//chart();
	//error_infix();
	var();
	rate();
	insert();
}
