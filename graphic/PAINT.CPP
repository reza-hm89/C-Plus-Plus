					/* Include header files */
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
#include<ctype.h>
				  /* Global variable declaration */

	int iRow=0,iCol=0,iStatus=0;
	int fColor=0,bColor=15,Action=1;

				  /**** Function Declaration ****/
	void initmouse(void); //initialize mouse
	void yesmouse(void); //show mouse
	void nomouse(void); //hide mouse
	void mouse(void);  //get mouse postion and button status
	void graphics_mode(void); //initialize graphic mode
	void screen(void);   //draw screen
	void titlebar(void); //draw title bar
	void toolbar(void); //draw toolbar
	void colorbar(void); // draw color bars
	void actionbox(void); //draw action box
	void colorbox(void);  // draw current colors box
	void fbcolors(int x,int y); //change colors
	void draw(int x1,int y1,int x2,int y2); //draw selected shape


					  /* Initialize Mouse */

void initmouse(void)
{
	iRow = 0,iCol = 0,iStatus = 0;
	asm { //means below code is assembly language
		mov ax,0; //0 mean initialize
		int 0x33; //0x33 in interrupt for mouse
	}
}
					  /* Enable mouse */

void yesmouse(void)
{
	asm {
		 mov ax,1; //1 mean show
		 int 0x33;
	}
}

					 /* Disable mouse */

void nomouse(void)
{
	asm {
		 mov ax,2; //2 mean hide
		 int 0x33;
	}
}

			  /* Find Row , Column and Status */

void mouse(void)
{
	 asm {
		  mov ax,3;   // 3 mean let mouse move
		  int 0x33;
		  mov iRow,dx;  // get mouse position and click status
		  mov iCol,cx;
		  mov iStatus,bx;
	 }
}


void graphics_mode(void)
{
	int gD = DETECT,gM = DETECT; //auto detect graphic driver and mode
	initgraph(&gD,&gM,"c:\\tc\\bgi");
}

void titlebar(void)
{
	setfillstyle(1,1);
	bar(0,0,640,20); //title bar in blue color
	
	setcolor(15);
	rectangle(621,3,636,18); //close box
	line(621,3,636,18);
	line(636,3,621,18);

	settextstyle(1,0,1); //write title
	outtextxy(295,0,"Musawwir");
}

void actionbox(void)
{
	setfillstyle(1,7); //erase previous action text
	bar(0,200,79,225);

	setcolor(1);
	settextstyle(2,0,5); //write current action text
	if(Action==1) {outtextxy(10,200,"Rectangel");}
	if(Action==2) {outtextxy(10,200,"Circle");}
	if(Action==3) {outtextxy(10,200,"Line");}
	if(Action==4) {outtextxy(10,200,"Bar");}
	if(Action==5) {outtextxy(10,200,"Arc");}
	if(Action==6) {outtextxy(10,200,"Pixels");}
	if(Action==7) {outtextxy(10,200,"PieSlice");}
	if(Action==8) {outtextxy(10,200,"Bar3D");}
}

void colorbox(void)
{
	setfillstyle(1,bColor); //display current foreground color
	bar(38,283,58,303);
	setfillstyle(1,fColor); //display current background color
	bar(20,265,40,285);
	setcolor(0);
	rectangle(38,283,58,303); //draw rectangles around them
	rectangle(20,265,40,285);
}

void toolbar(void)
{
	setfillstyle(1,7); //draw left gray area
	bar(0,21,79,435);
	setcolor(0);

	rectangle(12,30,32,50);  //draw 8 rectanlges for tools
	rectangle(42,30,62,50);
	rectangle(12,62,32,82);
	rectangle(42,62,62,82);
	rectangle(12,92,32,112);
	rectangle(42,92,62,112);
	rectangle(12,122,32,142);
	rectangle(42,122,62,142);

	rectangle(16,33,28,46);  //draw shapes in those rectangel to show which action they are
	circle(52,40,8);
	line(15,80,27,64);
	setfillstyle(1,0);
	bar(46,64,58,80);
	arc(22,102,0,170,5);
	settextstyle(1,0,1);
	outtextxy(52,85,".");
	pieslice(22,132,0,170,5);
	bar3d(45,126,56,140,3,1);

	settextstyle(1,0,1);   //write action heading
	outtextxy(8,170,"Action");
	actionbox();
	setcolor(0);
	settextstyle(1,0,1);  // write color heading and draw a box around colors
	outtextxy(8,230,"Colors");
	rectangle(7,260,73,310);
	colorbox();

}

void colorbar(void)
{
	int ccount;

	setfillstyle(1,7); //draw bottom gray area
	bar(0,436,640,480);
	for(ccount=0;ccount<16;ccount++) //draw 16 blocks with 16 colors
	{                               //2 times for fore and back color
		setfillstyle(1,ccount);
		bar(80+(ccount*20),441,80+(ccount*20)+15,456);
		bar(80+(ccount*20),461,80+(ccount*20)+15,476);
		setcolor(0);
		rectangle(80+(ccount*20),441,80+(ccount*20)+15,456);
		rectangle(80+(ccount*20),461,80+(ccount*20)+15,476);
	}
	settextstyle(2,0,5);   //write their headings
	outtextxy(2,441,"Fore Color");
	outtextxy(2,461,"Back Color");
}

void screen(void)
{
	setfillstyle(1,15);  //draw white drawing area
	bar(80,21,640,435);

	titlebar();     //call other components to complete screens
	toolbar();
	colorbar();
}

void fbcolors(int x,int y) //x and y are mouse postion passed from main
{

if((y>=441) && (y<=456))  // first color boxes row?
{                       //check which box and set fore color accordingly
	if((x>=80) && (x<=95)) {fColor=0;}
	if((x>=100) && (x<=115)) {fColor=1;}
	if((x>=120) && (x<=135)) {fColor=2;}
	if((x>=140) && (x<=155)) {fColor=3;}
	if((x>=160) && (x<=175)) {fColor=4;}
	if((x>=180) && (x<=195)) {fColor=5;}
	if((x>=200) && (x<=215)) {fColor=6;}
	if((x>=220) && (x<=235)) {fColor=7;}
	if((x>=240) && (x<=255)) {fColor=8;}
	if((x>=260) && (x<=275)) {fColor=9;}
	if((x>=280) && (x<=295)) {fColor=10;}
	if((x>=300) && (x<=315)) {fColor=11;}
	if((x>=320) && (x<=335)) {fColor=12;}
	if((x>=340) && (x<=355)) {fColor=13;}
	if((x>=360) && (x<=375)) {fColor=14;}
	if((x>=380) && (x<=395)) {fColor=15;}
}

if((y>=461) && (y<=476))  // second color boxes row?
{                       //check which box and set back color accordingly
	if((x>=80) && (x<=95)) {bColor=0;}
	if((x>=100) && (x<=115)) {bColor=1;}
	if((x>=120) && (x<=135)) {bColor=2;}
	if((x>=140) && (x<=155)) {bColor=3;}
	if((x>=160) && (x<=175)) {bColor=4;}
	if((x>=180) && (x<=195)) {bColor=5;}
	if((x>=200) && (x<=215)) {bColor=6;}
	if((x>=220) && (x<=235)) {bColor=7;}
	if((x>=240) && (x<=255)) {bColor=8;}
	if((x>=260) && (x<=275)) {bColor=9;}
	if((x>=280) && (x<=295)) {bColor=10;}
	if((x>=300) && (x<=315)) {bColor=11;}
	if((x>=320) && (x<=335)) {bColor=12;}
	if((x>=340) && (x<=355)) {bColor=13;}
	if((x>=360) && (x<=375)) {bColor=14;}
	if((x>=380) && (x<=395)) {bColor=15;}
}

colorbox();   //refresh color boxes to reflect changes
}

void draw(int x1,int y1,int x2,int y2) //two mouse potions passed by main
{

int radius;  //radius for arc,circle,bar3d
radius=sqrt(pow((x2-x1),2)+pow((y2-y1),2)); //calculate radius from distance formula

setcolor(fColor); //set  fore color to forgound
setfillstyle(1,fColor); //set fill color to forgound


nomouse();      //hide mouse show mouse pointer wont come in b/w drawing

if(Action==1) rectangle(x1,y1,x2,y2); //draw recangel
if(Action==2) circle(x1,y1,radius);  //draw circle
if(Action==3) line(x1,y1,x2,y2);  //draw line
if(Action==4) bar(x1,y1,x2,y2);  //drawbar

if(Action==5)
{
arc(x1+(x2-x1),y1+(y2-y1),0,180,radius/2);//draw arc using half raduis and use middle of two mouse position as center
}

if(Action==6)
{
putpixel(x1,y1,fColor); //put a pixel at current mouse position
}

if(Action==7)
{
pieslice(x1+(x2-x1),y1+(y2-y1),0,180,radius/2); //draw pieslice using half raduis and use middle of two mouse position as center
}

if(Action==8)
{
bar3d(x1,y1,x2,y2,radius/4,1);//draw bar3d using quarter raduis and 3d portion at top (denoted by 1)
}

titlebar(); //refresh other screen components to erase over drawn parts
toolbar();
colorbar();

yesmouse(); //show mouse again
}

void main(void)
{
	int x1,y1,x2,y2; //for two mouse positions

	initmouse(); //initialize mouse
	graphics_mode(); //intialize graphics mode
	screen();     //draw complete screen
	yesmouse();  // show mouse

	while(1)    // unconditional loop, will be terminated on exit(0) statment which ends program
	{
		mouse(); //let mouse mouse and get mouse variables

		if((iRow>=3) && (iRow<=18) && (iCol>=621) && (iCol<=636) && (iStatus==1))
		{  //close box clicked?
		closegraph();
		exit(0);     //end program
		}

		if((iRow>=441) && (iRow<=476) && (iCol>=80) && (iCol<=395) && (iStatus==1))
		{  // color bar at bottom clicked?
		fbcolors(iCol,iRow); //check which color clicked and set it
		}

		if((iRow>=30) && (iRow<=50) && (iCol>=12) && (iCol<=32) && (iStatus==1))
		{  //rectangle clicked?
		Action=1;
		actionbox(); //refrsh action text
		}

		if((iRow>=30) && (iRow<=50) && (iCol>=42) && (iCol<=62) && (iStatus==1))
		{
		Action=2; //circle clicked?
		actionbox(); //refrsh action text
		}

		if((iRow>=62) && (iRow<=82) && (iCol>=12) && (iCol<=32) && (iStatus==1))
		{
		Action=3; //line clicked?
		actionbox(); //refrsh action text
		}

		if((iRow>=62) && (iRow<=82) && (iCol>=42) && (iCol<=62) && (iStatus==1))
		{
		Action=4; //bar clicked?
		actionbox(); //refrsh action text
		}

		if((iRow>=92) && (iRow<=112) && (iCol>=12) && (iCol<=32) && (iStatus==1))
		{
		Action=5; //arc clicked?
		actionbox(); //refrsh action text
		}

		if((iRow>=92) && (iRow<=112) && (iCol>=42) && (iCol<=62) && (iStatus==1))
		{
		Action=6;  //pixel clicked?
		actionbox(); //refrsh action text
		}
		if((iRow>=122) && (iRow<=142) && (iCol>=12) && (iCol<=32) && (iStatus==1))
		{
		Action=7;   //pieslice clicked?
		actionbox(); //refrsh action text
		}
		if((iRow>=122) && (iRow<=142) && (iCol>=42) && (iCol<=62) && (iStatus==1))
		{
		Action=8;   //bar3d  clicked?
		actionbox(); //refrsh action text
		}

		if((iRow>=21) && (iRow<=435) && (iCol>=81) && (iCol<=640) && (iStatus==1))
		{       //draw area clicked?
			y1=iRow;  //set clicked location as first point
			x1=iCol;
			if(Action!=6)  //6 means pixel which not need dragging of mouse
				{
					while(iStatus!=0) //let user mouse drag until he leaves the button
					mouse();
				}
			y2=iRow;//set that position as second point
			x2=iCol;
			draw(x1,y1,x2,y2);  //draw selected shape using these two points
		}

	}   //end of while(1) loop

}   //end of code :)
