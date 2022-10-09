
// Chesss Game Designed by
//	- Niket Nilay
//		And
//	Nitin Singh Rajput

// although all functions used are of C but the code is compiled in
// TURBO C++ compiler

// This Game Doesn't have Artificial Intellingence.
// There is no scoring done.
// Input is through keyboard( Mouse implementation is pending).
// Place "goti1.h", "drawboard.h", and "end.h" in the "include" folder.
// The game just allows valid moves... and rules like cash ling.
// input is in the form of x and y coordinates like :-
// x1/y1:- a8
// x2/y2:- a7


#include<graphics.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<goti1.h>
#include<drawbo~1.h>
#include<end.h>
#include<dos.h>

void main()
    {
     int i;
     char k;
     int vcheck;
     char a[3],b[3];
     char x1,y1,x2,y2;
     char col;
     long int count=1;

     int gdriver = DETECT, gmode, errorcode;
     initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
     errorcode = graphresult();
     if(errorcode != grOk)
       {
	printf("Graphics error: %s\n", grapherrormsg(errorcode));
	printf("Press any key to halt:");
	getch();
	exit(1);
       }

     drawboard();
     goti();

     setcolor(3);
     outtextxy(2,1,"PRESS Q To QUIT");
     while(1)
       {

	if(wwins==1||bwins==1)
	  {
	   gotoxy(65,20);
	   if(wwins==1)
	   printf("WHITE WIN'S");
	   else
	   printf("BLACK WIN'S");
	   getch();
	   cleardevice();
	   closegraph();
	   restorecrtmode();
	   end();
	  }

	k=getche();
	if(k=='q')
	  {
	   cleardevice();
	   closegraph();
	   restorecrtmode();
	   end();
	  }

	if(count%2!=0)
	  {
	   col='w';
	   gotoxy(65,14);
	   printf("WHITE's MOVE");
	  }

	if(count%2==0)
	  {
	   col='b';
	   gotoxy(65,14);
	   printf("BLACK's MOVE");
	  }

	gotoxy(65,16);
	printf("             ");
	gotoxy(65,18);
	printf("             ");
	gotoxy(65,20);
	printf("           ");
	gotoxy(65,16);
	printf("(x1,y1):- ");
	scanf("%s",a);
	x1=a[0];
	y1=a[1];
	if((x1<97||x1>104||y1<49||y1>56))
	  {
	   gotoxy(65,20);
	   printf("INVALID");
	   continue;
	  }
	gotoxy(65,18);
	printf("(x2,y2):- ");
	scanf("%s",b);
	x2=b[0];
	y2=b[1];
	if((x2<97||x2>104||y2<49||y2>56))
	  {
	   gotoxy(65,20);
	   printf("INVALID");
	   continue;
	  }
	count=count+1;
	vcheck=move(col,x1,y1,x2,y2);
	if(vcheck==1)
	  {
	   count--;
	   gotoxy(65,20);
	   printf("WRONG MOVE  ");
	  }
       }
    }