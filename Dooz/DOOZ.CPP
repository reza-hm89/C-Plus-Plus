#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>
#include<fstream.h>
#include<bitmap.h>

int a[3][3];

void board();
void move(int);
void menu();
void credits();
void game();
void loading();

//************************************************************//
void main()
{
	int d=VGA,m=VGAHI;
	initgraph(&d,&m,"c:\\tc\\bgi");
	for (int i=0;i<=2;i++)
		for (int j=0;j<=2;j++)
			a[i][j]=0;
	menu();
	closegraph();
}
//************************************************************//
void board()
{
	cleardevice();
	setbkcolor(9);
	setfillstyle(1,15);
	setcolor(15);
	bar(100,40,470,65);
	bar(100,50,125,420);
	bar(100,410,470,435);
	bar(460,40,485,435);
	bar(100,225,480,250);
	bar(280,50,305,420);
	int a[10]={100,50,120,50,480,420,460,420,100,50};
	fillpoly(5,a);
	int b[10]={460,50,480,50,120,420,100,420,460,50};
	fillpoly(5,b);
}
//************************************************************//
void move(int p)
{
	int f,g,c,s,x,y,k,z,i=1,j=1;
	int cntr=0,choice,index=0,index1=1,save;
	setcolor(5);
	settextstyle(2,0,5);
	outtextxy(5,5,"*/*/*  Press ESC to Exit  */*/*");
	outtextxy(5,20,"*/*/*  Press '' S '' to Save Game  */*/*");
	x=293;
	y=238;
	c=p;
	setcolor(c);
	setfillstyle(1,c);
	fillellipse(550,50,25,25);
	setfillstyle(1,c);
	circle(x,y,12);
	s=getch();
	while(s!=27)
	{
		if (s==80)
		{
			k=y;
			setcolor(15);
			circle(x,k,12);
			y+=185;
			if (y>423)
				y=53;
			setcolor(c);
			circle(x,y,12);
			i++;
			if (i>2)
				i=0;
		}
		else if (s==72)
		{
			k=y;
			setcolor(15);
			circle(x,k,12);
			y-=185;
			if (y<53)
				y=423;
			setcolor(c);
			circle(x,y,12);
			i--;
			if (i<0)
				i=2;
		}
		else if (s==77)
		{
			z=x;
			setcolor(15);
			circle(z,y,12);
			x+=178;
			if (x>471)
				x=115;
			setcolor(c);
			circle(x,y,12);
			j++;
			if (j>2)
				j=0;
		}
		else if (s==75)
		{
			z=x;
			setcolor(15);
			circle(z,y,12);
			x-=178;
			if (x<115)
				x=471;
			setcolor(c);
			circle(x,y,12);
			j--;
			if (j<0)
				j=2;
		}
		else if (s==13 && a[i][j]==0)
		{
			cntr++;
			if (c==1)
			{	a[i][j]=1;
				setfillstyle(1,c);
				fillellipse(x,y,10,10);
				c=4;
				setcolor(c);
				setfillstyle(1,c);
				fillellipse(550,50,25,25);
				sound(1000);
				delay(100);
				sound(1500);
				delay(100);
				sound(2500);
				delay(100);
				nosound();
			}
			else if (c==4)
			{	a[i][j]=4;
				setfillstyle(1,c);
				fillellipse(x,y,10,10);
				c=1;
				setcolor(c);
				setfillstyle(1,c);
				fillellipse(550,50,25,25);
				sound(1000);
				delay(100);
				sound(3500);
				delay(100);
				sound(4500);
				delay(100);
				sound(500);
				delay(100);
				nosound();
			}
		if (cntr>=3)
		{
			settextstyle(7,0,4);
			for (int i1=0;i1<3;i1++)
			{
				if (a[i1][0]!=0)
				{	choice=a[i1][0];
					index=0;
					for (int j1=1;j1<3;j1++)
						if (a[i1][j1]==choice)
							index++;
				if (index==2 && choice==1)
				{
					delay(1000);
					setcolor(1);
					outtextxy(550,70,"B");
					delay(100);
					outtextxy(550,120,"L");
					delay(100);
					outtextxy(550,170,"U");
					delay(100);
					outtextxy(550,220,"E");
					delay(100);
					outtextxy(550,270," ");
					delay(100);
					outtextxy(550,320,"W");
					delay(100);
					outtextxy(550,370,"I");
					delay(100);
					outtextxy(550,420,"N");
					for (i=0,j=639;i<=639,j>0;i++,j--)
						for (k=0,z=479;k<240,z>239;k++,z--)
						{	putpixel(i,k,9);
							putpixel(j,z,9);
						}
					delay(1000);
					main();
				}
				else if (index==2 && choice==4)
				{
					delay(1000);
					setcolor(4);
					outtextxy(550,100,"R");
					delay(100);
					outtextxy(550,150,"E");
					delay(100);
					outtextxy(550,200,"D");
					delay(100);
					outtextxy(550,250," ");
					delay(100);
					outtextxy(550,300,"W");
					delay(100);
					outtextxy(550,350,"I");
					delay(100);
					outtextxy(550,400,"N");
					for (i=0,j=639;i<=639,j>0;i++,j--)
						for (k=0,z=479;k<240,z>239;k++,z--)
						{	putpixel(i,k,9);
							putpixel(j,z,9);
						}
					delay(1000);
					main();
				}
				} //end if a[i1][0]!=0
			}// end for i1
			for (i1=0;i1<3;i1++)
			{
				if (a[0][i1]!=0)
				{	choice=a[0][i1];
					index=0;
					for (int j1=1;j1<3;j1++)
						if (a[j1][i1]==choice)
							index++;
				if (index==2 && choice==1)
				{
					delay(1000);
					setcolor(1);
					outtextxy(550,70,"B");
					delay(100);
					outtextxy(550,120,"L");
					delay(100);
					outtextxy(550,170,"U");
					delay(100);
					outtextxy(550,220,"E");
					delay(100);
					outtextxy(550,270," ");
					delay(100);
					outtextxy(550,320,"W");
					delay(100);
					outtextxy(550,370,"I");
					delay(100);
					outtextxy(550,420,"N");
					delay(2000);
					for (i=0,j=639;i<=639,j>0;i++,j--)
						for (k=0,z=479;k<240,z>239;k++,z--)
						{	putpixel(i,k,9);
							putpixel(j,z,9);
						}
					main();
				}
				else if (index==2 && choice==4)
				{
					delay(1000);
					setcolor(4);
					outtextxy(550,100,"R");
					delay(100);
					outtextxy(550,150,"E");
					delay(100);
					outtextxy(550,200,"D");
					delay(100);
					outtextxy(550,250," ");
					delay(100);
					outtextxy(550,300,"W");
					delay(100);
					outtextxy(550,350,"I");
					delay(100);
					outtextxy(550,400,"N");
					delay(2000);
					for (i=0,j=639;i<=639,j>0;i++,j--)
						for (k=0,z=479;k<240,z>239;k++,z--)
						{	putpixel(i,k,9);
							putpixel(j,z,9);
						}
					main();
				}
				}//end if a[0][i1]!=0
			}//end for i1
			if (a[0][0]!=0)
			{	if (a[0][0]==a[1][1] && a[0][0]==a[2][2] && a[1][1]==a[2][2])
				{
					if (a[0][0]==1)
					{
						delay(1000);
						setcolor(1);
						outtextxy(550,70,"B");
						delay(100);
						outtextxy(550,120,"L");
						delay(100);
						outtextxy(550,170,"U");
						delay(100);
						outtextxy(550,220,"E");
						delay(100);
						outtextxy(550,270," ");
						delay(100);
						outtextxy(550,320,"W");
						delay(100);
						outtextxy(550,370,"I");
						delay(100);
						outtextxy(550,420,"N");
						delay(2000);
						for (i=0,j=639;i<=639,j>0;i++,j--)
							for (k=0,z=479;k<240,z>239;k++,z--)
							{	putpixel(i,k,9);
								putpixel(j,z,9);
							}
						main();
					}
					else if (a[0][0]==4)
					{
						delay(1000);
						setcolor(4);
						outtextxy(550,100,"R");
						delay(100);
						outtextxy(550,150,"E");
						delay(100);
						outtextxy(550,200,"D");
						delay(100);
						outtextxy(550,250," ");
						delay(100);
						outtextxy(550,300,"W");
						delay(100);
						outtextxy(550,350,"I");
						delay(100);
						outtextxy(550,400,"N");
						delay(2000);
						for (i=0,j=639;i<=639,j>0;i++,j--)
							for (k=0,z=479;k<240,z>239;k++,z--)
							{	putpixel(i,k,9);
								putpixel(j,z,9);
							}
						main();
					}
				}
			}
			if (a[0][2]!=0)
			{
				if (a[0][2]==a[1][1] && a[0][2]==a[2][0] && a[1][1]==a[2][0])
				{
					if (a[0][2]==1)
					{
						delay(1000);
						setcolor(1);
						outtextxy(550,70,"B");
						delay(100);
						outtextxy(550,120,"L");
						delay(100);
						outtextxy(550,170,"U");
						delay(100);
						outtextxy(550,220,"E");
						delay(100);
						outtextxy(550,270," ");
						delay(100);
						outtextxy(550,320,"W");
						delay(100);
						outtextxy(550,370,"I");
						delay(100);
						outtextxy(550,420,"N");
						delay(2000);
						for (i=0,j=639;i<=639,j>0;i++,j--)
							for (k=0,z=479;k<240,z>239;k++,z--)
							{	putpixel(i,k,9);
								putpixel(j,z,9);
							}
						main();
					}
					else if (a[0][2]==4)
					{
						delay(1000);
						setcolor(4);
						outtextxy(550,100,"R");
						delay(100);
						outtextxy(550,150,"E");
						delay(100);
						outtextxy(550,200,"D");
						delay(100);
						outtextxy(550,250," ");
						delay(100);
						outtextxy(550,300,"W");
						delay(100);
						outtextxy(550,350,"I");
						delay(100);
						outtextxy(550,400,"N");
						delay(2000);
						for (i=0,j=639;i<=639,j>0;i++,j--)
							for (k=0,z=479;k<240,z>239;k++,z--)
							{	putpixel(i,k,9);
								putpixel(j,z,9);
							}
						main();
					}
				}
			}
		} //end if cntr>=3
		if (cntr>8)
		{
		index1=1;
		for (int i1=0;i1<3;i1++)
		{	for (int j1=0;j1<3;j1++)
				if (a[i1][j1]==0)
					index1=0;
		if (index1==1)
		{
			delay(1000);
			setcolor(5);
			outtextxy(550,100,"N");
			delay(100);
			outtextxy(550,150,"O");
			delay(100);
			outtextxy(550,200," ");
			delay(100);
			outtextxy(550,250,"W");
			delay(100);
			outtextxy(550,300,"I");
			delay(100);
			outtextxy(550,350,"N");
			delay(2000);
			for (i=0,j=639;i<=639,j>0;i++,j--)
				for (k=0,z=479;k<240,z>239;k++,z--)
				{	putpixel(i,k,9);
					putpixel(j,z,9);
				}
			main();
		}
		} // end for i1
		} // end if cntr>8
		} // end if enter
       s=getch();
       }
       for (i=0,j=639;i<=639,j>0;i++,j--)
	       for (k=0,z=479;k<240,z>239;k++,z--)
	       {	putpixel(i,k,9);
			putpixel(j,z,9);
	       }
       delay(1000);
       main();
}
//***********************************************************//
void menu()
{
	int s,i,j,k,z,x,y;
	cleardevice();
	setbkcolor(9);
	delay(1000);
	setcolor(15);
	setfillstyle(1,15);
	for (j=313,i=300;j<=213,i<=425;i++,j--)
	{	outtextxy(i,200,"อ");
		outtextxy(j,200,"อ");
		delay(15);
	}
	delay(200);
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
		delay(30);
	}
	outtextxy(429,48,"ป");
	outtextxy(429,352,"ผ");
	outtextxy(183,352,"ศ");
	outtextxy(183,48,"ษ");
	////////// End KADR     //////////////////////////////
	settextstyle(7,0,1);
	setcolor(59);
	delay(200);
	outtextxy(255,100,"New Game");
	delay(200);
	outtextxy(255,150,"Load Game");
	delay(200);
	outtextxy(255,200,"Credits");
	delay(200);
	outtextxy(255,250,"Exit");
	x=220;
	y=112;
	setcolor(4);
	setfillstyle(1,4);
	fillellipse(x,y,10,10);
	setcolor(1);
	setfillstyle(1,1);
	fillellipse(x+170,y,10,10);

	s=getch();
	while (s!=27)
	{
		if (s==80)
		{
			setcolor(9);
			setfillstyle(1,9);
			fillellipse(x,y,10,10);
			setcolor(9);
			setfillstyle(1,9);
			fillellipse(x+170,y,10,10);
			y+=50;
			if (y>262)
				y=112;
			setcolor(4);
			setfillstyle(1,4);
			fillellipse(x,y,10,10);
			setcolor(1);
			setfillstyle(1,1);
			fillellipse(x+170,y,10,10);
		}
		else if (s==72)
		{
			setcolor(9);
			setfillstyle(1,9);
			fillellipse(x,y,10,10);
			setcolor(9);
			setfillstyle(1,9);
			fillellipse(x+170,y,10,10);
			y-=50;
			if (y<112)
				y=262;
			setcolor(4);
			setfillstyle(1,4);
			fillellipse(x,y,10,10);
			setcolor(1);
			setfillstyle(1,1);
			fillellipse(x+170,y,10,10);
		}
		else if (s==13 && y==112)
			game();
		else if (s==13 && y==212)
			credits();
		else if (s==13 && y==262)
			exit(0);
	s=getch();
	}
}
//*******************************************************//
void game()
{
	int s,x=0,y=0,c;
	cleardevice();
	setcolor(LIGHTGREEN);
	settextstyle(7,0,4);
	outtextxy(160,100,"Select your choice");
	setfillstyle(1,4);
	setcolor(4);
	fillellipse(200,200,20,20);
	setfillstyle(1,1);
	setcolor(1);
	fillellipse(400,200,20,20);
	setfillstyle(7,15);
	setcolor(15);
	int a[8]={200+x,250+y,250+x,300+y,150+x,300+y,200+x,250+y};
	fillpoly(4,a);
	int b[10]={180+x,300+y,220+x,300+y,220+x,400+y
	,180+x,400+y,180+x,300+y};
	fillpoly(5,b);
	s=getch();
	while (s!=27)
	{
		if (s==77)
		{
			setfillstyle(1,9);
			bar(150+x,250,300+x,400);
			x+=200;
			if (x>200)
				x=0;
			setfillstyle(7,15);
			setcolor(15);
			int a[8]={200+x,250+y,250+x,300+y,150+x,300+y,200+x,250+y};
			fillpoly(4,a);
			int b[10]={180+x,300+y,220+x,300+y,220+x,400+y
				  ,180+x,400+y,180+x,300+y};
			fillpoly(5,b);
		}
		else if (s==75)
		{
			setfillstyle(1,9);
			bar(150+x,250,300+x,400);
			x-=200;
			if (x<0)
				x=200;
			setfillstyle(7,15);
			setcolor(15);
			int a[8]={200+x,250+y,250+x,300+y,150+x,300+y,200+x,250+y};
			fillpoly(4,a);
			int b[10]={180+x,300+y,220+x,300+y,220+x,400+y
				  ,180+x,400+y,180+x,300+y};
			fillpoly(5,b);
		}
		else if (s==13 && x==0)
		{	c=4;
			setfillstyle(7,GREEN);
			setcolor(GREEN);
			int a[8]={200+x,250+y,250+x,300+y,150+x,300+y,200+x,250+y};
			fillpoly(4,a);
			int b[10]={180+x,300+y,220+x,300+y,220+x,400+y
				  ,180+x,400+y,180+x,300+y};
			fillpoly(5,b);
			loading();
			board();
			move(c);
		}
		else if (s==13 && x==200)
		{	c=1;
			setfillstyle(7,GREEN);
			setcolor(GREEN);
			int a[8]={200+x,250+y,250+x,300+y,150+x,300+y,200+x,250+y};
			fillpoly(4,a);
			int b[10]={180+x,300+y,220+x,300+y,220+x,400+y
				  ,180+x,400+y,180+x,300+y};
			fillpoly(5,b);
			loading();
			board();
			move(c);
		}
		s=getch();
	}
}
//*******************************************************//
void loading()
{       int c=60;
	cleardevice();
	settextstyle(7,0,7);
	setcolor(c);
	outtextxy(150,170,"L");
	outtextxy(200,170,"O");
	outtextxy(250,170,"A");
	outtextxy(300,170,"D");
	outtextxy(360,170,"I");
	outtextxy(400,170,"N");
	outtextxy(450,170,"G");
	delay(500);
	for (int i=0;i<=2;i++)
	{
	setcolor(c+2);
	outtextxy(150,170,"L");
	delay(200);
	setcolor(c);
	outtextxy(150,170,"L");
	delay(200);
	setcolor(c+2);
	outtextxy(200,170,"O");
	delay(200);
	setcolor(c);
	outtextxy(200,170,"O");
	delay(200);
	setcolor(c+2);
	outtextxy(250,170,"A");
	delay(200);
	setcolor(c);
	outtextxy(250,170,"A");
	delay(200);
	setcolor(c+2);
	outtextxy(300,170,"D");
	delay(200);
	setcolor(c);
	outtextxy(300,170,"D");
	setcolor(c+2);
	delay(200);
	outtextxy(360,170,"I");
	setcolor(c);
	delay(200);
	outtextxy(360,170,"I");
	setcolor(c+2);
	delay(200);
	outtextxy(400,170,"N");
	setcolor(c);
	delay(200);
	outtextxy(400,170,"N");
	setcolor(c+2);
	delay(200);
	outtextxy(450,170,"G");
	setcolor(c);
	delay(200);
	outtextxy(450,170,"G");
	}
}
//*******************************************************//
void credits()
{
	int cntr=0;
	for (int i=0;i<=639;i++)
		for ( int j=0;j<=479;j++)
			putpixel(i,j,9);
	setcolor(56);
	settextstyle(1,0,2);
	displaybitmap(0,0,"e:\\2.BMP");
	outtextxy(50,40,"Created by:");
	outtextxy(210,50,"Reza Hosseini masoum");
	getch();
	for (i=0;i<=639;i++)
		for (j=0;j<=479;j++)
			putpixel(i,j,9);
	main();
}