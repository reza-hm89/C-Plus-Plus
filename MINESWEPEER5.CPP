#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
#include <dos.h>
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


int NOM=10;
int flags=10;
int SIZE=10;
int x=0,y=0,startx,starty;
unsigned long timer=0;
int finishtime=100;
int dificulty=1;// difficulty level 1->easy  2->medium  3->hard
int table[20][20];
int tstatus[20][20];
// for squares status  1 -> not shown  0 -> shown  2 -> ? sign  3 -> flag
char username[10]="Player";
char st[10];
char minesign[2]="û";
char helpsign[2]="?";

void printnumber(int,int);
void showtable();
int maketable();
int ismine(int,int);
int roundmines(int,int);
void intialize();
void box(int,int,int,int);
void highlight(int,int,int,int);
void printtable();
void printnumber(int,int);
void clearsq(int,int);
void clickmine();
void getkey();
void intialize();
void menu();
void selectmenu(int,int);
void printmenu();
void newgame();
void resumegame();
void printtableresume();
int winn();
void winscreen();
void usertext(int,int);
void winneffect();
void options();
void printoptionmenu();
void entername();
void printsize();
void printnom();
void showmsg(char [80]);
void changesign(int,int);
void printbuttons();
void statuspad(int field);
void finishtimescreen();
void printdifficulty();
void splashscreen();
void endsplash(int);
void pageeffect();



// -------------------------------------------------------------------
void main()
{
  srand(time(0));
  intialize();
  splashscreen();
  maketable();
  printmenu();
  menu();
  closegraph();
  //return 0;
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
	     if (smenu!=4){
	       smenu++;
	       selectmenu(smenu-1,smenu);
	     }
	     break;
    case 13: // ENTER pressed
	     if (smenu==1){
	       endsplash(BC);
	       newgame();
	       printmenu();
	       selectmenu(smenu,smenu);
	       ch=1;
	     }
	     else if (smenu==2){
	       if (!winn() && timer/100!=finishtime){
		 endsplash(BC);
		 resumegame();
		 printmenu();
		 selectmenu(smenu,smenu);
		 ch=1;
	       }
	     }
	     else if (smenu==3){
	       options();
	       printmenu();
	       selectmenu(smenu,smenu);
	       ch=1;
	     }
	     else if (smenu==4) goto End;
	     break;
    }
    if (ch==80 || ch==72 || ch==1){
      switch (smenu) {
      case 1: showmsg("Play a new game.");break;
      case 2: showmsg("Resume last game.");break;
      case 3: showmsg("Change game options.");break;
      case 4: showmsg("Exit to system.");break;
      }
    }
  } while ((ch=getch())!=27);
End:
  endsplash(0);
}

void selectmenu(int olds, int s)
{
  setfillstyle(1,9);
  floodfill(140+1,120+80*(olds-1)+1,14);
  setfillstyle(1,10);
  floodfill(140+1,120+80*(s-1)+1,14);
}

void printmenu()
{
  printbuttons();
  settextjustify(1,1);
  settextstyle(1,0,4);
  setcolor(8);
  outtextxy(322,32,"Main Menu");
  setcolor(15);
  outtextxy(320,30,"Main Menu");
  settextstyle(10,0,2);
  setcolor(15);
  outtextxy(320,110,"Play Game");
  outtextxy(320,185,"Resume");
  outtextxy(320,260,"Options");
  outtextxy(320,335,"Exit");
}

void printbuttons()
{
  setbkcolor(0);
  pageeffect();
  setfillstyle(1,9);
  setcolor(14);
  delay(200);
  bar3d(140,85,500,145,1,1);
  bar3d(150,95,490,135,5,3);
  bar3d(140,160,500,220,1,1);
  bar3d(150,170,490,210,5,3);
  bar3d(140,235,500,295,1,1);
  bar3d(150,245,490,285,5,3);
  bar3d(140,310,500,370,1,1);
  bar3d(150,320,490,360,5,3);
}

void options()
{
  char ch=1;
  int osm=1,SIZEtemp=SIZE,NOMtemp=NOM;
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
	     if (osm!=4){
	       osm++;
	       selectmenu(osm-1,osm);
	     }
	     break;
    case 75: // LEFT Arrow pressed
	     switch (osm){
	     case 2: // number of mines
		    if (NOM!=SIZE/2) {
		      NOM--;flags--;printnom();}
		    break;
	     case 1: // table size
		    if (SIZE!=5)
		    if (NOM<(SIZE-1)*(SIZE-2)) {
		      SIZE--;printsize(); }
		    else
		      showmsg("Cannot change Table size! reduce number of mines.");
		    break;
	     case 4: // difficulty level down
		     if (dificulty!=1){
		       dificulty--;
		       printdifficulty();
		     }
	     }

	     break;
    case 77: // RIGHT Arrow pressed
	     switch (osm){
	     case 2: // number of mines
		    if (NOM!=SIZE*(SIZE-1)) {
		      NOM++;flags++;printnom();}
		    break;
	     case 1: // table size
		    if (SIZE!=15)
		    if (NOM>SIZE/2) {
		      SIZE++;printsize();}
		    else
		      showmsg("Cannot change Table size! Too few number of mines.");
		    break;
	     case 4: // difficulty level up
		     if (dificulty!=3){
		       dificulty++;
		       printdifficulty();
		     }
	     }
	     break;
    case 13: // ENTER pressed
	     if (osm==3) entername();
	     break;
    }
    if (ch==72 || ch==80 || ch==1){
      switch (osm) {
      case 1: showmsg("Left & Right Arrow key to change table size.");break;
      case 2: showmsg("Left & Right Arrow key to change number of mines.");break;
      case 3: showmsg("Press Enter key to enter player name.");break;
      case 4: showmsg("Left & Right Arrow key to change difficulty level.");break;
      }
    }
  } while ((ch=getch())!=27);
  if ((NOM!=NOMtemp) || (SIZE!=SIZEtemp)) maketable();
}

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
  outtextxy(160,110,"Table Size");
  outtextxy(160,185,"Mines");
  outtextxy(160,260,"Name:");
  outtextxy(160,335,"Difficulty");
  setfillstyle(1,0);
  settextstyle(3,0,2);
  settextjustify(1,1);
  setcolor(14);
  bar3d(395,250,480,280,0,0);
  outtextxy(440,259,username);
  printsize();
  printnom();
  printdifficulty();
}

void pageeffect()
{
  register i,j,k;
  cleardevice();
  for (i=0 ; i<2000 ; i++)
    putpixel(rand()%getmaxx(),rand()%getmaxy(),rand()%16);
  for (i=0 ; i<50 ; i++){
    setcolor(rand()%5+7);
    j=rand()%480;
    k=rand()%640;
    line(0,j,getmaxx(),j);
    line(k,0,k,getmaxy());
    delay(4);
  }
}

void printsize()
{
  setfillstyle(1,0);
  settextstyle(3,0,2);
  settextjustify(1,0);
  setcolor(14);
  bar3d(395,105,480,125,0,0);
  sprintf(st,"%d",SIZE);
  outtextxy(440,122,st);
}

void printnom()
{
  setfillstyle(1,0);
  settextstyle(3,0,2);
  settextjustify(1,1);
  setcolor(14);
  bar3d(395,180,480,200,0,0);
  sprintf(st,"%d",NOM);
  outtextxy(440,187,st);
}

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

void showmsg(char msg[80])
{
  setfillstyle(1,9);
  setcolor(15);
  bar3d(1,getmaxy()-20,getmaxx(),getmaxy(),0,0);
  settextstyle(2,0,6);
  settextjustify(0,1);
  setcolor(14);
  outtextxy(3,getmaxy()-13,msg);
}

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

void resumegame()
{
  cleardevice();
  settextstyle(2,0,4);
  printtable();
  printtableresume();
  getkey();
}

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

int winn()
{
  int i,j,empty=0;
  for (i=0 ; i<SIZE ; i++)
    for (j=0 ; j<SIZE ; j++)
      if (tstatus[i][j]==0 && !ismine(j,i)) empty++;
  if (empty==SIZE*SIZE-NOM) return 1;
  return 0;
}

void winscreen()
{
  setfillstyle(1,1);
  setcolor(15);
  bar3d(100,100,540,380,0,0);
  setfillstyle(1,5);
  fillellipse(getmaxx()/2,getmaxy()/2,220,140);
  setcolor(15);
  usertext(getmaxx()/2,getmaxy()/2);
  setcolor(7);
  usertext(getmaxx()/2+3,getmaxy()/2+3);
  do{
    winneffect();
    delay(100);
  } while (!kbhit());
  do { } while (getch()!=13);
  settextjustify(1,1);
}

void usertext(int x,int y)
{
  settextstyle(1,0,8);
  settextjustify(1,0);
  outtextxy(x,y,"You Winn!!");
  settextjustify(1,2);
  outtextxy(x,y,username);
}

void winneffect()
{
  static slice=0;
  setfillstyle(1,rand()%15);
  if (slice==0) floodfill(101,101,15);
  else if (slice==1) floodfill(101,379,15);
  else if (slice==2) floodfill(539,101,15);
  else if (slice==3) floodfill(539,379,15);
  slice++;
  if (slice==4) slice=0;
}

void printtableresume()
{
  settextjustify(1,1);
	for (int i=0; i<SIZE ; i++)
    for (int j=0; j<SIZE ; j++){
      setcolor(15);
      box(startx+SS*j,starty+SS*i,startx+SS*j+(SS-BS),starty+SS*i+(SS-BS));
      if (tstatus[i][j]==0)
	if (roundmines(j,i)==0){
	  setfillstyle(1,TBC);
	  fillellipse(startx+SS*j+(SS-BS)/2,starty+SS*i+(SS-BS)/2,(SS-BS)/3,(SS-BS)/3);
	}
	else{
	  setfillstyle(1,TBC);
	  fillellipse(startx+SS*j+(SS-BS)/2,starty+SS*i+(SS-BS)/2,(SS-BS)/3,(SS-BS)/3);
	  sprintf(st,"%d",roundmines(j,i));
	  setcolor(14);
	  outtextxy(startx+SS*j+(SS-BS)/2,starty+SS*i+(SS-BS)/2,st);
	}
      else if (tstatus[i][j]==2){
	setcolor(15);
	outtextxy(startx+SS*j+(SS-BS)/2,starty+SS*i+(SS-BS)/2,helpsign);}
      else if (tstatus[i][j]==3){
	setcolor(14);
	outtextxy(startx+SS*j+(SS-BS)/2,starty+SS*i+(SS-BS)/2,minesign);}
    }
  statuspad(5);
  highlight(x,y,x,y);
}

int maketable()
{
  int xy[225][2];
  x=0;y=0;
  flags=NOM;
  if (dificulty==1) finishtime=SIZE*5+NOM*6;
  else if (dificulty==2) finishtime=SIZE*2+NOM*4;
  else finishtime=SIZE+NOM*2;
  int i=0,x,y,j,k,pass=0;
  startx=(getmaxx()-SIZE*SS)/2;
  starty=(getmaxy()-SIZE*SS)/2;
  while (i<NOM){
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
    for (j=0 ; j<SIZE ; j++){
      tstatus[i][j]=1;
      table[i][j]=0;
    }
  for (k=0 ; k<NOM ; k++)
      table[xy[k][1]][xy[k][0]]=1;
  return 1;
}

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
      else if (roundmines(j,i)==0){
	setfillstyle(1,TBC);
	fillellipse(startx+SS*j+(SS-BS)/2,starty+SS*i+(SS-BS)/2,(SS-BS)/3,(SS-BS)/3);
      }
      else{
	setfillstyle(1,TBC);
	fillellipse(startx+SS*j+(SS-BS)/2,starty+SS*i+(SS-BS)/2,(SS-BS)/3,(SS-BS)/3);
	sprintf(st,"%d",roundmines(j,i));
	setcolor(14);
	outtextxy(startx+SS*j+(SS-BS)/2,starty+SS*i+(SS-BS)/2,st);
      }
    }
}

int ismine(int x,int y)
{
  if (table[y][x]==1) return 1;
  return 0;
}

int roundmines(int x,int y)
{
  int t=0;
  for (int i=0 ; i<SIZE ; i++)
    for (int j=0 ; j<SIZE ; j++)
    {
      if (abs(x-j)==1){
	if (abs(y-i)==1) t+=table[i][j];
	if (abs(y-i)==0) t+=table[i][j];
      }
      if (abs(y-i)==1)
	if (abs(x-j)==0)t+=table[i][j];
    }

  return t;
}

void box(int x1,int y1,int x2,int y2)
{
  line(x1,y1,x1,y2);
  line(x1,y1,x2,y1);
  line(x2,y2,x2,y1);
  line(x2,y2,x1,y2);
}

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
  setcolor(1);
  setfillstyle(1,5);
  floodfill(x+2,y+2,15);
  box(x,y,x+SS-BS,y+SS-BS);
  statuspad(2);
}

void changesign(int x,int y)
{
  settextjustify(1,1);
  setcolor(15);
  setfillstyle(1,SBC);
  if (tstatus[y][x]!=0)
    fillellipse(startx+SS*x+(SS-BS)/2,starty+SS*y+(SS-BS)/2,(SS-BS)/3,(SS-BS)/3);
  switch (tstatus[y][x]){
  case 1: // clear square
	  statuspad(1);
	  break;
  case 2: // put ? sign
	  setcolor(15);
	  outtextxy(startx+SS*x+(SS-BS)/2,starty+SS*y+(SS-BS)/2,helpsign);
	  break;
  case 3: // put flag
	  setcolor(14);
	  outtextxy(startx+SS*x+(SS-BS)/2,starty+SS*y+(SS-BS)/2,minesign);
	  statuspad(1);
	  break;
  }
}

void printtable()
{
  int i,j;
  setfillstyle(1,SBC);
  setcolor(15);
  setbkcolor(BC);
  fillellipse(320,240,100,50);
  settextjustify(1,1);
  settextstyle(5,0,4);
  outtextxy(320,230,"Get Ready...");
  delay(1500);
  setbkcolor(0);
  cleardevice();
  for (i=0 ; i<2000 ; i++)
    putpixel(rand()%getmaxx(),rand()%getmaxy(),rand()%16);
  settextstyle(1,0,1);
  setfillstyle(1,TBC);
  bar3d(startx-BS,starty-BS,startx+SS*SIZE,starty+SS*SIZE,0,0);
  setfillstyle(1,SBC);
  for (i=startx; i<startx+SS*SIZE ; i+=SS)
    for (j=starty; j<starty+SS*SIZE ; j+=SS){
      setcolor(15);
      delay(5);
      box(i,j,i+SS-BS,j+SS-BS);
      circle(i+(SS-BS)/2,j+(SS-BS)/2,(SS-BS)/3);
      floodfill(i+(SS-BS)/2,j+(SS-BS)/2,15);
    }
  statuspad(5);
  highlight(x,y,x,y);
}

void printnumber(int x,int y)
{
  setcolor(14);
  settextjustify(1,1);
  if (ismine(x,y)) return;
  if (roundmines(x,y)==0 ){
    setfillstyle(1,TBC);
    setcolor(15);
    fillellipse(startx+SS*x+(SS-BS)/2,starty+SS*y+(SS-BS)/2,(SS-BS)/3,(SS-BS)/3);
  }
  else{
    sprintf(st,"%d",roundmines(x,y));
    settextjustify(1,1);
    setfillstyle(1,TBC);
    setcolor(15);
    fillellipse(startx+SS*x+(SS-BS)/2,starty+SS*y+(SS-BS)/2,(SS-BS)/3,(SS-BS)/3);
    setcolor(14);
    outtextxy(startx+SS*x+(SS-BS)/2,starty+SS*y+(SS-BS)/2,st);
  }
}

void statuspad(int field)
{
  setfillstyle(1,9);
  setcolor(14);
  settextjustify(1,1);
  settextstyle(0,0,1);
  int i,j;
  if (field!=5) j=field;
  else j=0;
  for (i=j ;i<=field ; i++)
  switch(i){
  case 0: // player name
	  bar3d(10,starty,80,starty+20,2,2);
	  outtextxy(45,starty+10,username);
	  break;
  case 1: // Number of flags changed
	  bar3d(10,starty+40,80,starty+60,2,2);
	  sprintf(st,"û  %d",flags);
	  outtextxy(45,starty+50,st);
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

void clearsq(int x,int y)
{
  if (tstatus[y][x]==0 || tstatus[y][x]==3) return;
  printnumber(x,y);
  tstatus[y][x]=0;

  int i,j;
  for (i=0 ; i<SIZE ; i++)
    for (j=0 ; j<SIZE ; j++)
    {
      if (abs(x-j)==1){
	if (abs(y-i)==1) if (roundmines(j,i)==0 && !ismine(j,i)) clearsq(j,i);
	if (abs(y-i)==0) if (roundmines(j,i)==0 && !ismine(j,i)) clearsq(j,i);
      }
      if (abs(y-i)==1)
	if (abs(x-j)==0) if (roundmines(j,i)==0 && !ismine(j,i)) clearsq(j,i);
    }

  for (i=-1 ; i<=1 ; i++)
    for (j=-1 ; j<=1 ; j++)
	if (i!=0 || j!=0)
	  if ((x+i>=0 && x+i<SIZE) && (y+j>=0 && y+j<SIZE))
	  {
		printnumber(x+i,y+j);
		tstatus[y+j][x+i]=0;
	  }
}

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
  endsplash(0);
}

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
	  if (tstatus[y][x]!=0 && tstatus[y][x]!=3){
	    if (ismine(x,y)) {
		clickmine();
		return;
	    }
	    if (roundmines(x,y)!=0){
	      printnumber(x,y);
	      setfillstyle(1,SBC);
	    }
	    else
	      clearsq(x,y);
	    tstatus[y][x]=0;
	    if (winn()){
	      winscreen();
	      return;
	    }
	  }
	  break;
  case 32: switch (tstatus[y][x]){
	   case 2:
		   if (flags!=0){
		     flags--;
		     tstatus[y][x]=3;}
		   else
		     tstatus[y][x]=1;
		   changesign(x,y);
		   break;
	   case 3:
		   flags++;
		   tstatus[y][x]=1;
			 changesign(x,y);
			 break;
		 case 1:
			 tstatus[y][x]=2;
			 changesign(x,y);
			 break;
		 }
	}
	do{
		delay(10);
    timer+=1;
    if (timer%100==0) statuspad(3);
    if (timer/100==finishtime) {
      finishtimescreen();
      return;
    }
  } while(!kbhit());
  } while ((c=getch())!=27);
}

void endsplash(int color)
{
  setfillstyle(1,color);
  setcolor(color);
  int i,endmode=rand()%4;
  switch (endmode) {
  case 0:
    for (i=0 ; i<=360 ; i+=5){
      delay(10);
      pieslice(320,240,i-5,i+5,410);
    }
    break;
  case 1:
    for (i=0 ; i<=410 ; i+=10){
      delay(10);
      fillellipse(320,240,i,i);
    }
    break;
  case 2:
    for (i=0 ; i<=640 ; i+=10){
      delay(10);
      bar(i,0,i+10,480);
    }
    break;
  case 3:
    for (i=0 ; i<=480 ; i+=10){
      delay(10);
      bar(0,i,640,i+10);
    }
    break;
  }
}

void splashscreen()
{
  int i;
  setbkcolor(0);
  for (i=0 ; i<1000 ; i++)
    putpixel(rand()%getmaxx(),rand()%getmaxy(),rand()%16);
  settextstyle(4,0,4);
  settextjustify(1,1);
  setcolor(8);
  outtextxy(322,242,"IN THE NAME OF GOD");
  setcolor(11);
  outtextxy(320,240,"IN THE NAME OF GOD");
  delay(3000);
  setcolor(3);
  setfillstyle(1,3);
  for (i=0 ; i<=240 ; i+=10){
    delay(10);
    fillellipse(320,240,i,i);
  }
  settextjustify(1,1);
  settextstyle(1,0,6);
  setcolor(8);
  outtextxy(323,243,"MinesWeeper");
  setcolor(1);
  settextstyle(1,0,6);
  outtextxy(320,240,"MinesWeeper");
  delay(1500);
  setfillstyle(1,0);
  setcolor(0);
  for (i=0 ; i<=360 ; i+=5){
    delay(10);
    pieslice(320,240,0,i,239);
	}
	setcolor(8);
	settextstyle(1,0,6);
	outtextxy(323,243,"By: Mehdi Sherafati");
	settextstyle(1,0,6);
	do{
	setcolor(rand()%16);
	outtextxy(320,240,"By: Mehdi sherafati");
	} while (!kbhit());
	getch();
	setfillstyle(1,0);
	setcolor(0);
	for (i=0 ; i<=410 ; i+=15){
		delay(10);
		fillellipse(320,240,i,i);
	}
}

void intialize()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc\\BGI");
  if (graphresult()!=grOk){
    printf("Graph Error...");
    getch();
    exit(1);
  }
  settextjustify(1,1);
  settextstyle(2,0,4);
}
