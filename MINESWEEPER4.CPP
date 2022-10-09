#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
#include <dos.h>
//////////////////////////////////////////////////
// Square Size
#define SS 30
// Between Size
#define BS 3
// Back Color
#define BC 0
// Table Back Color
#define TBC 2
// Square Back Color
#define SBC 9
//////////////////////////////////////////////////
int NOM;
int SIZE=10;
int x=0,y=0,startx,starty;
unsigned long timer=0;
int finishtime=100;
int dificulty=1;// difficulty level 1->easy  2->medium  3->hard
int table[20][20];
char username[10]="Player";
char st[10];
///////////////////////////////////////////////////
int  maketable();
int  ismine(int,int);
void intialize();
void printtable();
void getkey();
void menu();
void selectmenu(int,int);
void printmenu();
void newgame();
void options();
void printoptionmenu();
void entername();
void printsize();
void printbuttons();
void statuspad(int field);
void printdifficulty();
void check(int,int);
// -------------------------------------------------------------------
void main()
{
	intialize();
	printmenu();
	menu();
	closegraph();
}
// -------------------------------------------------------------------
void menu()
{
  char ch=1;
  int smenu=1;
  selectmenu(1,1);
  do{
	switch (ch){
		case 72: // UP Arrow clicked
			if (smenu!=1){
				smenu--;
				selectmenu(smenu+1,smenu);
			}
			break;
		case 80: // DOWN Arrow clicked
			if (smenu!=3){
				smenu++;
				selectmenu(smenu-1,smenu);
			}
			break;
		case 13: // ENTER pressed
			if (smenu==1){
				newgame();
				printmenu();
				selectmenu(smenu,smenu);
				ch=1;
			}
			else if (smenu==2){
				options();
				printmenu();
				selectmenu(smenu,smenu);
				ch=1;
				}
			else if (smenu==3)
				exit(0);
			break;
	}//end switch
	} while ((ch=getch())!=27);
}
//--------------------------------------------------------
void selectmenu(int olds, int s)
{
	setfillstyle(1,9);
	floodfill(141,190+80*(olds-1)+1,14);
	setfillstyle(1,10);
	floodfill(141,190+80*(s-1)+1,14);
}
//--------------------------------------------------------
void printmenu()
{
  cleardevice();
  printbuttons();
  settextjustify(1,1);
  settextstyle(1,0,4);
  setcolor(8);
  outtextxy(322,32,"Main Menu");
  setcolor(15);
  outtextxy(320,30,"Main Menu");
  settextstyle(10,0,2);
  setcolor(15);
  outtextxy(320,185,"New Game");
  outtextxy(320,260,"Options");
  outtextxy(320,335,"Exit");
}
//--------------------------------------------------------
void printbuttons()
{
  setbkcolor(0);
  setfillstyle(1,9);
  setcolor(14);
  delay(200);
  bar3d(140,160,500,220,1,1);
  bar3d(150,170,490,210,5,3);
  bar3d(140,235,500,295,1,1);
  bar3d(150,245,490,285,5,3);
  bar3d(140,310,500,370,1,1);
  bar3d(150,320,490,360,5,3);
}
//---------------------------------------------------------
void options()
{
  char ch=1;
  int osm=1,SIZEtemp=SIZE,NOMtemp=NOM;
  cleardevice();
  printoptionmenu();
  selectmenu(osm,osm);
  do{
    switch (ch){
    case 72: // UP Arrow clicked
	     if (osm!=1){
	       osm--;
	       selectmenu(osm+1,osm);
	     }
	     break;
    case 80: // DOWN Arrow clicked
	     if (osm!=3){
	       osm++;
	       selectmenu(osm-1,osm);
	     }
	     break;
    case 75: // LEFT Arrow pressed
	     switch (osm){
	     case 1: // table size
		    if (SIZE!=5)
		    if (NOM<(SIZE-1)*(SIZE-2)) {
		      SIZE--;printsize(); }
		    break;
	     case 3: // difficulty level down
		     if (dificulty!=1){
		       dificulty--;
		       printdifficulty();
		     }
	     }
	     break;
    case 77: // RIGHT Arrow pressed
	     switch (osm){
	     case 1: // table size
		    if (SIZE!=15)
		    if (NOM>SIZE/2) {
			SIZE++;
			printsize();
			}
		    break;
	     case 3: // difficulty level up
		     if (dificulty!=3){
		       dificulty++;
		       printdifficulty();
		     }
	     }
	     break;
    case 13: // ENTER pressed
	     if (osm==2) entername();
	     break;
    }
  } while ((ch=getch())!=27);
  if ((NOM!=NOMtemp) || (SIZE!=SIZEtemp))
	maketable();
}
//---------------------------------------------
void printoptionmenu()
{
  printbuttons();
  settextjustify(1,1);
  settextstyle(1,0,4);
  setcolor(8);
  outtextxy(322,32,"Options Menu");
  setcolor(15);
  outtextxy(320,30,"Options Menu");
  settextjustify(0,1);
  settextstyle(3,0,4);
  setcolor(15);
  outtextxy(160,185,"Table Size");
  outtextxy(160,260,"Name:");
  outtextxy(160,335,"Difficulty");
  setfillstyle(1,0);
  settextstyle(3,0,2);
  settextjustify(1,1);
  setcolor(14);
  bar3d(395,250,480,280,0,0);
  outtextxy(440,259,username);
  printsize();
  printdifficulty();
}
//---------------------------------------------
void printsize()
{
  setfillstyle(1,0);
  settextstyle(3,0,2);
  settextjustify(1,1);
  setcolor(14);
  bar3d(395,180,480,200,0,0);
  sprintf(st,"%d",SIZE);
  outtextxy(440,187,st);
}
//-----------------------------------------------
void printdifficulty()
{
  setfillstyle(1,0);
  settextstyle(3,0,2);
  settextjustify(1,1);
  setcolor(14);
  bar3d(395,325,480,355,0,0);
  if (dificulty==1) outtextxy(440,338,"Easy");
  else if (dificulty==2) outtextxy(440,338,"Medium");
  else outtextxy(440,338,"Hard");
}
//------------------------------------------------
void entername()
{
  setfillstyle(1,0);
  bar3d(395,250,480,280,0,0);
  gotoxy(51,17);
  gets(username);
  bar3d(395,250,480,280,0,0);
  settextstyle(3,0,2);
  settextjustify(1,1);
  outtextxy(440,259,username);
}
//--------------------------------------------------
void newgame()
{
  cleardevice();
  settextstyle(2,0,4);
  maketable();
  x=0;y=0;
  timer=0;
  printtable();
  getkey();
}
//--------------------------------------------------
void finishtimescreen()
{
  setcolor(15);
  setfillstyle(1,1);
  bar3d(120,200,520,280,0,0);
  setcolor(12);
  settextstyle(7,0,3);
  outtextxy(320,240,"! YOUR TIME IS FINISHED !");
  do { } while (getch()!=13);
}
//---------------------------------------------------
int winn()
{
  int i,j,empty=0;
  for (i=0 ; i<SIZE ; i++)
    for (j=0 ; j<SIZE ; j++)
      if (table[i][j]==1) empty++;
  if (empty==SIZE*SIZE-NOM) return 1;
  return 0;
}
//-----------------------------------------------------
void winscreen()
{
  setfillstyle(1,1);
  setcolor(15);
  bar3d(100,100,540,380,0,0);
  setfillstyle(1,5);
  fillellipse(getmaxx()/2,getmaxy()/2,220,140);
  setcolor(15);
  settextstyle(1,0,8);
  settextjustify(1,0);
  outtextxy(getmaxx()/2,getmaxy()/2,"You Win!!");
  settextjustify(1,2);
  outtextxy(getmaxx()/2,getmaxy()/2,username);
  setcolor(7);
  do { } while (getch()!=13);
  settextjustify(1,1);
}
//----------------------------------------------------
int maketable()
{
  int xy[225][2];
  x=0;y=0;
  int i=0,x,y,j,k,pass=0;
  startx=(getmaxx()-SIZE*SS)/2;
  starty=(getmaxy()-SIZE*SS)/2;
  randomize();
  if (dificulty==1)
	NOM=(random(SIZE)+1);
  if (dificulty==2)
	NOM=(random(SIZE*2)+SIZE);
  if (dificulty==3)
	NOM=(random(SIZE*3)+2*SIZE);
  while (i<NOM){  //mokhtasate bomb x,y
	pass=0;
	x=rand()%SIZE;
	y=rand()%SIZE;
	for (j=0 ; j<i ; j++)
		if (x==xy[j][0] && y==xy[j][1])
			pass=1;
	if (pass) continue;
	xy[i][0]=x;
	xy[i][1]=y;
	i++;
  }
  for (i=0 ; i<SIZE ; i++)
    for (j=0 ; j<SIZE ; j++)
      table[i][j]=0;
  for (k=0 ; k<NOM ; k++)
      table[xy[k][1]][xy[k][0]]=2;
  return 1;
}
//-----------------------------------------------
void showtable()
{
  int i,j;
  settextjustify(1,1);
  for (i=0 ; i<SIZE ; i++)
    for (j=0 ; j<SIZE ; j++){
      setcolor(15);
      delay(1);
      if (ismine(j,i)){
	setfillstyle(1,SBC);
	fillellipse(startx+SS*j+(SS-BS)/2,starty+SS*i+(SS-BS)/2,(SS-BS)/3,(SS-BS)/3);
	setcolor(4);
	outtextxy(startx+SS*j+(SS-BS)/2,starty+SS*i+(SS-BS)/2,"*");
      }
    }
}
//-----------------------------------------------
int ismine(int x,int y)
{
  if (table[y][x]==2) return 1; //2==bomb
  return 0;
}
//---------------------------------------------------
void box(int x1,int y1,int x2,int y2)
{
  line(x1,y1,x1,y2);
  line(x1,y1,x2,y1);
  line(x2,y2,x2,y1);
  line(x2,y2,x1,y2);
}
//-------------------------------------------------
void highlight(int oldx,int oldy,int x,int y)
{
  oldx=startx+oldx*SS;
  oldy=starty+oldy*SS;
  x=startx+x*SS;
  y=starty+y*SS;
  setcolor(15);
  setfillstyle(1,TBC);
  box(oldx,oldy,oldx+SS-BS,oldy+SS-BS);
  floodfill(oldx+2,oldy+2,15);
  ////////////////
  setcolor(1);
  setfillstyle(1,5);
  floodfill(x+2,y+2,15);
  box(x,y,x+SS-BS,y+SS-BS);
  /////////////////
  statuspad(2);
}
//--------------------------------------------------
void printtable()
{
  int i,j;
  setbkcolor(0);
  cleardevice();
  settextstyle(1,0,1);
  setfillstyle(1,TBC);
  bar3d(startx-BS,starty-BS,startx+SS*SIZE,starty+SS*SIZE,0,0);//rasme safeh
  setfillstyle(1,SBC);
  //chape khoneha
  for (i=startx; i<startx+SS*SIZE ; i+=SS)
    for (j=starty; j<starty+SS*SIZE ; j+=SS){
      setcolor(15);
      delay(5);
      box(i,j,i+SS-BS,j+SS-BS);
      circle(i+(SS-BS)/2,j+(SS-BS)/2,(SS-BS)/3);
      floodfill(i+(SS-BS)/2,j+(SS-BS)/2,15);
    }
  statuspad(5);//chape timer,name,...
  highlight(x,y,x,y);
}
//-----------------------------------------------------
void statuspad(int field)
{
  setfillstyle(1,9);
  setcolor(14);
  settextjustify(1,1);
  settextstyle(2,0,5);
  int i,j;
  if (field!=5) j=field;
  else j=0;
  for (i=j ;i<=field ; i++)
  switch(i){
  case 0: // player name
	  bar3d(10,starty+40,80,starty+60,2,2);
	  outtextxy(45,starty+50,username);
	  break;
  case 2: // x,y changed
	  bar3d(10,starty+80,80,starty+100,2,2);
	  sprintf(st,"%d,%d",x+1,y+1);
	  outtextxy(45,starty+90,st);
	  break;
  case 3: // timer changed
	  setfillstyle(1,9);
	  bar3d(10,starty+120,80,starty+140,2,2);
	  setfillstyle(1,12);
	  bar(11,starty+121,11+(timer/100)*68/finishtime,starty+124);
	  sprintf(st,"%ld/%d",timer/100,finishtime);
	  outtextxy(45,starty+130,st);
	  break;
  case 4:
	  setfillstyle(1,9);
	  bar3d(10,starty+160,80,starty+180,2,2);
	  if (dificulty==1) sprintf(st,"Easy");
	  else if (dificulty==2) sprintf(st,"Medium");
	  else sprintf(st,"Hard");
	  outtextxy( 45,starty+170,st);
	  break;
  }
}
//-----------------------------------------------------------
void clickmine()
{
  settextjustify(1,1);
  setfillstyle(1,SBC);
  setcolor(15);
  fillellipse(startx+SS*x+(SS-BS)/2,starty+SS*y+(SS-BS)/2,(SS-BS)/3,(SS-BS)/3);
  setcolor(4);
  outtextxy(startx+SS*x+(SS-BS)/2,starty+SS*y+(SS-BS)/2,"*");
  delay(500);
  showtable();
  do { } while (getch()!=13);
}
//---------------------------------------------------
void getkey()
{
  char c=0;
  do{
	switch (c){
		case 72:
			if (y!=0){
				y-=1;
				highlight(x,y+1,x,y);
			}
			break;
		case 80:
			if (y!=SIZE-1){
				y+=1;
				highlight(x,y-1,x,y);
			}
			break;
		case 75:
			if (x!=0){
				x-=1;
				highlight(x+1,y,x,y);
			}
			break;
		case 77:
			if (x!=SIZE-1){
				x+=1;
				highlight(x-1,y,x,y);
			 }
			break;
		case 13:
			if (table[y][x]==2)
			{
				clickmine();
				return;
			}
			else if (table[y][x]==0)
			{
				check(y,x);
			}
			if (winn())
			{
				winscreen();
				return;
			}
			break;
		}
	do{
		delay(10);
		timer+=1;
		if (timer%100==0)
			statuspad(3);
		if (timer/100==finishtime) {
			finishtimescreen();
			return;
		}
	} while(!kbhit());
  } while ((c=getch())!=27);
}
//------------------------------------------------
void intialize()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc\\BGI");
	if (graphresult()!=grOk){
		printf("Graph Error...");
		getch();
		exit(1);
	}
}
//----------------------------------------
void check(int i,int j)
{
if (table[i][j]==0) {
	table[i][j]=1;
	setcolor(BLUE);
	outtextxy(startx+SS*x+(SS-BS)/2,starty+SS*y+(SS-BS)/2,"1");
	setcolor(YELLOW);
	if ((table[i-1][j-1]==0) && (table[i-1][j]==0) && (table[i-1][j+1]==0))
	{
	if (i>0) {
	table[i-1][j]=1;
	outtextxy(startx+SS*x+(SS-BS)/2,starty+SS*y-SS+(SS-BS)/2,"1");
	}
	}
	if ((table[i+1][j-1]==0) && (table[i+1][j]==0) && (table[i+1][j+1]==0))
	{
	if (i<SIZE) {
	table[i+1][j]=1;
	outtextxy(startx+SS*x+(SS-BS)/2,starty+SS*y+SS+(SS-BS)/2,"1");
	}
	}
	if ((table[i-1][j-1]==0) && (table[i][j-1]==0) && (table[i+1][j-1]==0))
	{
	if (j>0) {
	table[i][j-1]=1;
	outtextxy(startx+SS*x-SS+(SS-BS)/2,starty+SS*y+(SS-BS)/2,"1");
	}
	}
	if ((table[i-1][j+1]==0) && (table[i][j+1]==0) && (table[i+1][j+1]==0))
	{
	if (j<SIZE) {
	table[i][j+1]=1;
	outtextxy(startx+SS*x+SS+(SS-BS)/2,starty+SS*y+(SS-BS)/2,"1");
	}
	}
	if (table[i-1][j-1]==0) {
	if (table[i-1][j]!=2 && table[i-1][j+1]!=2 && table[i][j-1]!=2 && table[i+1][j-1]!=2)
	{
	if (i>0 && j>0) {
	table[i-1][j-1]=1;
	outtextxy(startx+SS*x-SS+(SS-BS)/2,starty+SS*y-SS+(SS-BS)/2,"1");
	}
	}
	}
	if (table[i-1][j+1]==0) {
	if (table[i-1][j]!=2 && table[i-1][j-1]!=2 && table[i][j+1]!=2 && table[i+1][j+1]!=2)
	{
	if (i>0 && j<SIZE) {
	table[i-1][j+1]=1;
	outtextxy(startx+SS*x+SS+(SS-BS)/2,starty+SS*y-SS+(SS-BS)/2,"1");
	}
	}
	}
	if (table[i+1][j+1]==0) {
	if (table[i][j+1]!=2 && table[i-1][j+1]!=2 && table[i+1][j]!=2 && table[i+1][j-1]!=2)
	{
	if (i<SIZE && j<SIZE) {
	table[i+1][j+1]=1;
	outtextxy(startx+SS*x+SS+(SS-BS)/2,starty+SS*y+SS+(SS-BS)/2,"1");
	}
	}
	}
	if (table[i+1][j-1]==0) {
	if (table[i][j-1]!=2 && table[i-1][j-1]!=2 && table[i+1][j]!=2 && table[i+1][j+1]!=2)
	{
	if (i<SIZE && j>0) {
	table[i+1][j-1]=1;
	outtextxy(startx+SS*x-SS+(SS-BS)/2,starty+SS*y+SS+(SS-BS)/2,"1");
	}
	}
	}
	}
}