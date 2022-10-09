
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>

void drawboard()
    {
     int i,j,count=1;
     char num[1],color[1];
     char text[][8]={
			"A",
			"B",
			"C",
			"D",
			"E",
			"F",
			"G",
			"H"};


     setfillstyle(WIDE_DOT_FILL,BLUE);

     /* draw the 3-d bar */
     bar3d(220,8, 222+205,8+15, 5, 1);
     setcolor(YELLOW);
     outtextxy(240,12,"NikVinNit's Chess Game");

     //Draws 64 Blocks of the chess board and fills them
     setcolor(LIGHTBLUE);
     for(i=100;i<=500;i=i+50)
	{
	 delay(100);
	 line(i,50,i,450);
	}
     for(i=50;i<=450;i=i+50)
	{
	 delay(100);
	 line(100,i,500,i);
	}
     for(j=75;j<=425;j=j+50)
	{
	 count++;
	 //code to choose fill color as black or white
	 if(count%2==0)
	   {
	    for(i=125;i<=475;i=i+100)
	       {
		delay(100);
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(i,j,LIGHTBLUE);
	       }
	   }
	 else
	   {
	    for(i=175;i<=475;i=i+100)
	       {
		delay(100);
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(i,j,LIGHTBLUE);
	       }
	   }
	}

     //Prints 8,7,6,5,4,3,2,1 For Block identification
     j=75;
     setcolor(RED);
     for(i=8;i>=1;i--)
	{
	 delay(100);
	 itoa(i,num,10);
	 outtextxy(88,j,num);
	 j=j+50;
	}

     j=75;
     for(i=8;i>=1;i--)
	{
	 delay(100);
	 itoa(i,num,10);
	 outtextxy(502,j,num);
	 j=j+50;
	}

     // Prints A,B,C,D,E,F,G,H For Block identification
     j=124;
     for(i=0;i<=7;i++)
	{
	 delay(100);
	 setcolor(RED);
	 outtextxy(j,458,text[i]);
	 j=j+50;
	}

     j=124;
     for(i=0;i<=7;i++)
	{
	 delay(100);
	 setcolor(RED);
	 outtextxy(j,41,text[i]);
	 j=j+50;
	}
    }

void goti()
    {
     int i;
     for(i=100;i<=472;i=i+50)
     pawn(i,100,'b');

     for(i=100;i<=472;i=i+50)
     pawn(i,350,'w');

     bishop(200,50,'b');
     bishop(350,50,'b');
     bishop(200,400,'w');
     bishop(350,400,'w');
     rookh(100,50,'b');
     rookh(450,50,'b');
     rookh(100,400,'w');
     rookh(450,400,'w');
     horse(150,50,'b');
     horse(400,50,'b');
     horse(150,400,'w');
     horse(400,400,'w');
     king(250,50,'b');
     king(250,400,'w');
     queen(300,50,'b');
     queen(300,400,'w');
    }