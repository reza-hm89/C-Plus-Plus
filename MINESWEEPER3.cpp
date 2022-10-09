#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
//void rasm();
int main()
{

/* request auto detection */

int gdriver = DETECT,gmode, errorcode;
initgraph(&gdriver, &gmode, "..//bgi");

int k=0,p=0,j;
int x=0,y=0;

int  a[10][10]={1,1,1,1,1,1,1,1,1,0,
		1,0,1,1,0,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,0,
		1,1,1,1,0,1,1,1,0,1,
		1,1,1,1,1,1,1,1,1,0,
		1,1,0,1,0,1,1,0,1,1,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,0,1,0,1,1,
		1,0,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,0,1,1};
//setfillstyle(SOLID_FILL,20);
//bar(20+x*15,20+y*35,35+x*15,35+y*15);
//bar(20+x*15,20+y*35,35+x*15,35+y*15);
 outtextxy(390,50,"...Minesweeper Game...  ");
 outtextxy(390,10,"...Programmer: Mahdi Rabbanian...  ");

setcolor(17);
for(int i=1;i<=10;i++)
{

for(int j=1;j<=10;j++)
{
  rectangle(10+k,10+p,45+k,45+p);
  k+=35;
}
k=0;
p+=35;
}
setcolor(10);
rectangle(11,11,44,44);
rectangle(12,12,43,43);
//rasm();

k=getch();
while(k!=27)
{
setcolor(0);
rectangle(11+x*35,11+y*35,44+x*35,44+y*35);
rectangle(12+x*35,12+y*35,43+x*35,43+y*35);


switch(k)
{
 case 80:
  y++;
  if(y>=10)
  y=0;

 break;
 case 72:
 y--;
 if(y<0)
  y=9;

 break;
 case 75:

 x--;
 if(x<0)
  x=9;

 break;
 case 77:
 x++;
 if(x>=10)
  x=0;

 break;

 case 13:

 if(a[y][x]==0) // agar bomb bod
 {
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(a[i][j]==0)
			{
			setfillstyle(SOLID_FILL,20);
			bar(20+j*35,20+i*35,35+j*35,35+i*35);

			}
		}
	 }
	 setcolor(14);
	 //gotoxy(600,400);
	 outtextxy(100,400,"You Lose Game ...... Press Any key..... ");
	 //cout<<"";
	 getch();
	 return 0;
 // exit(0);
 }
 else   	//agar bomb nabod
 {
	 setfillstyle(SOLID_FILL,15);
	 bar(20+x*35,20+y*35,35+x*35,35+y*35);

	 //char jahat.......................
	 if(x>0&&x<9&&y>0&&y<9)
	 {
	 if(a[y+1][x-1]!=0)
	 {
	 setfillstyle(SOLID_FILL,15);
	 bar(20+(x-1)*35,20+(y+1)*35,35+(x-1)*35,35+(y+1)*35);
	 }

	  if(a[y][x-1]!=0)
	 {
	 setfillstyle(SOLID_FILL,15);
	 bar(20+(x-1)*35,20+y*35,35+(x-1)*35,35+y*35);
	 }

	 if(a[y-1][x-1]!=0)
	 {
	 setfillstyle(SOLID_FILL,15);
	 bar(20+(x-1)*35,20+(y-1)*35,35+(x-1)*35,35+(y-1)*35);
	 }

	 if(a[y-1][x]!=0)
	 {
	 setfillstyle(SOLID_FILL,15);
	 bar(20+x*35,20+(y-1)*35,35+x*35,35+(y-1)*35);
	 }

	if(a[y-1][x+1]!=0)
	 {
	 setfillstyle(SOLID_FILL,15);
	 bar(20+(x+1)*35,20+(y-1)*35,35+(x+1)*35,35+(y-1)*35);
	 }

	if(a[y][x+1]!=0)
	 {
	 setfillstyle(SOLID_FILL,15);
	 bar(20+(x+1)*35,20+y*35,35+(x+1)*35,35+y*35);
	 }

	 if(a[y+1][x+1]!=0)
	 {
	 setfillstyle(SOLID_FILL,15);
	 bar(20+(x+1)*35,20+(y+1)*35,35+(x+1)*35,35+(y+1)*35);
	 }

	 if(a[y+1][x]!=0)
	 {
	 setfillstyle(SOLID_FILL,15);
	 bar(20+x*35,20+(y+1)*35,35+x*35,35+(y+1)*35);
	 }
	  }
	//rast....................

		int select=0;

		for(i=x;a[x][i]!=0&&select==0&&i<10 ;i++)
		{
			     select=0;
			for(j=0;j<10 ;j++)
			{         // y  i
				if(a[j][i]==0)
				{
				select=1;  //yani bomb peyda kard
			       //	break;
				}
			}

		   if(select==0)
		   {
		   //?
			 for(int k=0;k<10;k++)
			 {
			 bar(20+i*35,20+k*35,35+i*35,35+k*35);
			 }
		   }
		   else
		   {
		   select=1;
		//   break;
		   }

		}
     // chap...............................

	       select=0;

		for(i=x;a[x][i]!=0&&select==0&&i>=0 ;i--)
		{
			     select=0;
			for(j=0;j<10 ;j++)
			{         // y  i
				if(a[j][i]==0)
				{
				select=1;  //yani bomb peyda kard
			       //	break;
				}
			}

		   if(select==0)
		   {
			 for(int k=0;k<10;k++)
			 {
			 bar(20+i*35,20+k*35,35+i*35,35+k*35);
			 }

		   }
		   else
		   {
		   select=1;
		//   break;
		   }

		}

	//bala...........................
	     select=0;
		 for(i=y;a[y][i]!=0&&select==0&&i>=0 ;i--)
		{
			     select=0;
			for(j=0;j<10 ;j++)
			{         // y  i
				if(a[i][j]==0)
				{
				select=1;  //yani bomb peyda kard
			       //	break;
				}
			}

		   if(select==0)
		   {
		   //?
			 for(int k=0;k<10;k++)
			 {
			 bar(20+k*35,20+i*35,35+k*35,35+i*35);
			 }
		   }
		   else
		   {
		   select=1;
		//   break;
		   }

		}
       //paeen.....................................

		  select=0;
		 for(i=y+1;a[y][i]!=0&&select==0&&i<10 ;i++)
		{
			     select=0;
			for(j=0;j<10 ;j++)
			{         // y  i
				if(a[i][j]==0)
				{
				select=1;  //yani bomb peyda kard
			       //	break;
				}
			}

		   if(select==0)
		   {
		   //?
			 for(int k=0;k<10;k++)
			 {
			 bar(20+k*35,20+i*35,35+k*35,35+i*35);
			 }
		   }
		   else
		   {
		   select=1;
		//   break;
		   }

		}


	}//else
  break;
 }//switch
setcolor(10);
rectangle(11+x*35,11+y*35,44+x*35,44+y*35);
rectangle(12+x*35,12+y*35,43+x*35,43+y*35);
k=getch();
} //while
getch();
return 0;
}//main