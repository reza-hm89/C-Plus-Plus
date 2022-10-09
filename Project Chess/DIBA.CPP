#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
struct position
{
int i;
int j;
};//position
//---------------------------------------------------------------------------
short int inv[9][9];
char gamewith='w';
int select=1;
int savei=0,savej=0;
int x=14;
position move_array[64];
int move_num;
int b_outrow=1;
int w_outrow=1;
int b_outcol=9;
int w_outcol=0;
//---------------------------------------------------------------------------
void draw_s(int i,int j,int c)
{
char p[8]={10,20,30,40,50,60,70,80};
setcolor(c);
circle(i*50+95,j*50+15,7);
setfillpattern(p,c);
setfillstyle(1,c);
floodfill(i*50+93,j*50+12,c);
int shape[18]={i*50+105,j*50+22,i*50+100,j*50+25,i*50+110,j*50+40,
i*50+110,j*50+43,i*50+80,j*50+43,i*50+80,j*50+40,i*50+90,j*50+25,
i*50+85,j*50+22,i*50+105,j*50+22};
drawpoly(9,shape);
floodfill(i*50+95,j*50+35,c);
}//draw s
//---------------------------------------------------------------------------
void draw_f(int i,int j,int c)
{
char p[8]={10,20,30,40,50,60,70,80};
setcolor(c);
circle(i*50+95,j*50+12,4);
setfillpattern(p,c);
setfillstyle(1,c);
floodfill(i*50+93,j*50+13,c);
rectangle(i*50+80,j*50+40,i*50+110,j*50+43);
floodfill(i*50+81,j*50+41,c);
ellipse(i*50+95,j*50+28,0,360,10,12);
floodfill(i*50+95,j*50+28,c);
}//draw f
//---------------------------------------------------------------------------
void draw_r(int i,int j,int c)
{
char p[8]={10,20,30,40,50,60,70,80};
setcolor(c);
setfillpattern(p,c);
setfillstyle(1,c);
rectangle(i*50+80,j*50+40,i*50+110,j*50+43);
floodfill(i*50+81,j*50+41,c);
int shape1[10]={i*50+100,j*50+25,i*50+105,j*50+40,i*50+85,j*50+40,i*50+90,j*50+25,i*50+100,j*50+25};
drawpoly(5,shape1);
floodfill(i*50+95,j*50+28,c);
rectangle(i*50+80,j*50+13,i*50+110,j*50+25);
floodfill(i*50+81,j*50+18,c);
rectangle(i*50+80,j*50+7,i*50+87,j*50+17);
floodfill(i*50+81,j*50+8,c);
rectangle(i*50+103,j*50+7,i*50+110,j*50+17);
floodfill(i*50+104,j*50+8,c);
rectangle(i*50+92,j*50+7,i*50+98,j*50+17);
floodfill(i*50+93,j*50+8,c);
}//draw r
//---------------------------------------------------------------------------
void draw_v(int i,int j,int c)
{
char p[8]={10,20,30,40,50,60,70,80};
setcolor(c);
setfillpattern(p,c);
setfillstyle(1,c);
rectangle(i*50+80,j*50+40,i*50+110,j*50+43);
floodfill(i*50+81,j*50+41,c);
int shape[16]={i*50+80,j*50+8,i*50+90,j*50+30,i*50+95,j*50+8,i*50+100,j*50+30,
	       i*50+110,j*50+8,i*50+105,j*50+40,i*50+85,j*50+40,i*50+80,j*50+8};
drawpoly(8,shape);
floodfill(i*50+95,j*50+35,c);
}//draw v
//---------------------------------------------------------------------------
void draw_sh(int i,int j,int c)
{
char p[8]={10,20,30,40,50,60,70,80};
setcolor(c);
setfillpattern(p,c);
setfillstyle(1,c);
circle(i*50+95,j*50+12,4);
floodfill(i*50+93,j*50+13,c);
rectangle(i*50+80,j*50+40,i*50+110,j*50+43);
floodfill(i*50+81,j*50+41,c);
int shape[16]={i*50+80,j*50+8,i*50+90,j*50+30,i*50+95,j*50+8,i*50+100,j*50+30,
	       i*50+110,j*50+8,i*50+105,j*50+40,i*50+85,j*50+40,i*50+80,j*50+8};
drawpoly(8,shape);
floodfill(i*50+95,j*50+35,c);
circle(i*50+95,j*50+25,12);
floodfill(i*50+88,j*50+16,c);
floodfill(i*50+102,j*50+16,c);
}//draw sh
//---------------------------------------------------------------------------
void draw_a(int i,int j,int c)
{
char p[8]={10,20,30,40,50,60,70,80};
setcolor(c);
setfillpattern(p,c);
setfillstyle(1,c);
rectangle(i*50+80,j*50+40,i*50+110,j*50+43);
floodfill(i*50+81,j*50+41,c);
int shape[16]={i*50+90,j*50+8,i*50+102,j*50+8,i*50+105,j*50+40,i*50+85,j*50+40,
	       i*50+90,j*50+22,i*50+80,j*50+25,i*50+78,j*50+22,i*50+90,j*50+8};
drawpoly(8,shape);
floodfill(i*50+97,j*50+21,c);
if(c==0) c=8;
else     c=7;
setcolor(c);
setfillpattern(p,c);
setfillstyle(1,c);
circle(i*50+91,j*50+15,2);
floodfill(i*50+91,j*50+15,c);
}//draw a
//---------------------------------------------------------------------------
void draw_inv()
{
char p[8]={10,20,30,40,50,60,70,80};
int driver,mode=0,check=1;
driver=DETECT;
initgraph(&driver,&mode,"");
setcolor(7);
rectangle(0,0,getmaxx(),getmaxy());
setfillpattern(p,7);
setfillstyle(1,7);
floodfill(100,100,7);
setcolor(4);
settextstyle(1,0,1);
setusercharsize(1,1,1,1);
outtextxy(225,5,"CHESS GAME");
rectangle(600,20,620,40);
setcolor(15);
rectangle(602,22,618,38);
setfillpattern(p,15);
setfillstyle(1,15);
floodfill(610,25,15);
for(int i=1;i<=8;i++)
	{
	check*=-1;
	for(int j=1;j<=8;j++)
		{
		if(check==1)
			{
			setcolor(7);
			rectangle(i*50+70,j*50,i*50+120,j*50+50);
			setfillpattern(p,7);
			setfillstyle(1,7);
			floodfill(i*50+80,j*50+10,7);
			}//if
		else
			{
			setcolor(8);
			rectangle(i*50+70,j*50,i*50+120,j*50+50);
			setfillpattern(p,8);
			setfillstyle(1,8);
			floodfill(i*50+80,j*50+10,8);
			}//else
		check*=-1;
		}//for
	}//for
setcolor(4);
rectangle(117,47,523,453);
rectangle(116,46,524,454);
rectangle(115,45,525,455);
settextstyle(0,0,1);
outtextxy(50+92,460,"1");outtextxy(100+92,460,"2");outtextxy(150+92,460,"3");
outtextxy(200+92,460,"4");outtextxy(250+92,460,"5");outtextxy(300+92,460,"6");
outtextxy(350+92,460,"7");outtextxy(400+92,460,"8");
}//draw_inv
//---------------------------------------------------------------------------
void insert_array()
{
for(int i=1;i<=8;i++)
	for(int j=1;j<=8;j++)
		inv[i][j]=0;
inv[1][1]=inv[1][8]=101;
inv[1][2]=inv[1][7]=102;
inv[1][3]=103;
inv[1][6]=104;
inv[1][4]=105;
inv[1][5]=106;
for(i=1;i<=8;i++)
	inv[2][i]=100;
inv[8][1]=inv[8][8]=201;
inv[8][2]=inv[8][7]=202;
inv[8][3]=203;
inv[8][6]=204;
inv[8][4]=205;
inv[8][5]=206;
for(i=1;i<=8;i++)
	inv[7][i]=200;
}//inset array
//---------------------------------------------------------------------------
void clr_elements(int i,int j)
{
int c;
char p[8]={10,20,30,40,50,60,70,80};
if((i+j)%2==0)
	c=8;
if((i+j)%2==1)
	c=7;
setcolor(c);
setfillpattern(p,c);
setfillstyle(1,c);
rectangle(j*50+73,i*50+3,j*50+117,i*50+47);
floodfill(j*50+95,i*50+25,c);
}//clr elements
//---------------------------------------------------------------------------
void show_elements(int i,int j)
{
switch (inv[i][j])
	{
	case 100:
	draw_s(j,i,15);
	break;
	case 101:
	draw_r(j,i,15);
	break;
	case 102:
	draw_a(j,i,15);
	break;
	case 103:
	draw_f(j,i,15);
	break;
	case 104:
	draw_f(j,i,15);
	break;
	case 105:
	draw_v(j,i,15);
	break;
	case 106:
	draw_sh(j,i,15);
	break;
	case 200:
	draw_s(j,i,0);
	break;
	case 201:
	draw_r(j,i,0);
	break;
	case 202:
	draw_a(j,i,0);
	break;
	case 203:
	draw_f(j,i,0);
	break;
	case 204:
	draw_f(j,i,0);
	break;
	case 205:
	draw_v(j,i,0);
	break;
	case 206:
	draw_sh(j,i,0);
	break;
	}//switch
}//show elements
//---------------------------------------------------------------------------
void show_out_elements(int i,int j)
{
switch (inv[i][j])
	{
	case 100:
	draw_s(w_outcol,w_outrow,15);
	w_outrow++;
	if(w_outrow==9)
		{
		w_outrow=1;
		w_outcol--;
		}//if
	break;
	case 101:
	draw_r(w_outcol,w_outrow,15);
	w_outrow++;
	if(w_outrow==9)
		{
		w_outrow=1;
		w_outcol--;
		}//if
	break;
	case 102:
	draw_a(w_outcol,w_outrow,15);
	w_outrow++;
	if(w_outrow==9)
		{
		w_outrow=1;
		w_outcol--;
		}//if
	break;
	case 103:
	draw_f(w_outcol,w_outrow,15);
	w_outrow++;
	if(w_outrow==9)
		{
		w_outrow=1;
		w_outcol--;
		}//if
	break;
	case 104:
	draw_f(w_outcol,w_outrow,15);
	w_outrow++;
	if(w_outrow==9)
		{
		w_outrow=1;
		w_outcol--;
		}//if
	break;
	case 105:
	draw_v(w_outcol,w_outrow,15);
	w_outrow++;
	if(w_outrow==9)
		{
		w_outrow=1;
		w_outcol--;
		}//if
	break;
	case 106:
	draw_sh(w_outcol,w_outrow,15);
	w_outrow++;
	if(w_outrow==9)
		{
		w_outrow=1;
		w_outcol--;
		}//if
	break;
	case 200:
	draw_s(b_outcol,b_outrow,0);
	b_outrow++;
	if(b_outrow==9)
		{
		b_outrow=1;
		b_outcol++;
		}//if
	break;
	case 201:
	draw_r(b_outcol,b_outrow,0);
	b_outrow++;
	if(b_outrow==9)
		{
		b_outrow=1;
		b_outcol++;
		}//if
	break;
	case 202:
	draw_a(b_outcol,b_outrow,0);
	b_outrow++;
	if(b_outrow==9)
		{
		b_outrow=1;
		b_outcol++;
		}//if
	break;
	case 203:
	draw_f(b_outcol,b_outrow,0);
	b_outrow++;
	if(b_outrow==9)
		{
		b_outrow=1;
		b_outcol++;
		}//if
	break;
	case 204:
	draw_f(b_outcol,b_outrow,0);
	b_outrow++;
	if(b_outrow==9)
		{
		b_outrow=1;
		b_outcol++;
		}//if
	break;
	case 205:
	draw_v(b_outcol,b_outrow,0);
	b_outrow++;
	if(b_outrow==9)
		{
		b_outrow=1;
		b_outcol++;
		}//if
	break;
	case 206:
	draw_sh(b_outcol,b_outrow,0);
	b_outrow++;
	if(b_outrow==9)
		{
		b_outrow=1;
		b_outcol++;
		}//if
	break;
	}//switch
}//show out elements
//---------------------------------------------------------------------------
void where_can_go(int i,int j)
{
move_num=0;
for(int k=0;k<64;k++)
	{
	move_array[k].i=0;
	move_array[k].j=0;
	}//for
switch(inv[i][j])
	{
	case 100:
	if(inv[i+1][j]==0)
		{
		move_array[move_num].i=i+1;
		move_array[move_num].j=j;
		setcolor(3);
		if(inv[move_array[move_num].i][move_array[move_num].j]==206)
			setcolor(13);
		rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
		move_num++;
		}//if
	if((inv[i+2][j]==0&&i==2) && inv[i+1][j]==0)
		{
		move_array[move_num].i=i+2;
		move_array[move_num].j=j;
		setcolor(3);
		if(inv[move_array[move_num].i][move_array[move_num].j]==206)
			setcolor(13);
		rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
		move_num++;
		}//if
	if(inv[i+1][j-1]>=200)
		{
		move_array[move_num].i=i+1;
		move_array[move_num].j=j-1;
		setcolor(3);
		if(inv[move_array[move_num].i][move_array[move_num].j]==206)
			setcolor(13);
		rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
		move_num++;
		}//if
	if(inv[i+1][j+1]>=200)
		{
		move_array[move_num].i=i+1;
		move_array[move_num].j=j+1;
		setcolor(3);
		if(inv[move_array[move_num].i][move_array[move_num].j]==206)
			setcolor(13);
		rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
		move_num++;
		}//if
	break;
	case 200:
	if(inv[i-1][j]==0)
		{
		move_array[move_num].i=i-1;
		move_array[move_num].j=j;
		setcolor(3);
		if(inv[move_array[move_num].i][move_array[move_num].j]==106)
			setcolor(13);
		rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
		move_num++;
		}//if
	if((inv[i-2][j]==0&&i==7)&&inv[i-1][j]==0)
		{
		move_array[move_num].i=i-2;
		move_array[move_num].j=j;
		setcolor(3);
		if(inv[move_array[move_num].i][move_array[move_num].j]==106)
			setcolor(13);
		rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
		move_num++;
		}//if
	if(inv[i-1][j-1]>=100 && inv[i-1][j-1]<150)
		{
		move_array[move_num].i=i-1;
		move_array[move_num].j=j-1;
		setcolor(3);
		if(inv[move_array[move_num].i][move_array[move_num].j]==106)
			setcolor(13);
		rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
		move_num++;
		}//if
	if(inv[i-1][j+1]>=100 && inv[i-1][j+1]<150)
		{
		move_array[move_num].i=i-1;
		move_array[move_num].j=j+1;
		setcolor(3);
		if(inv[move_array[move_num].i][move_array[move_num].j]==106)
			setcolor(13);
		rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
		move_num++;
		}//if
	break;
	case 102:
	if((inv[i-2][j-1]<100 || inv[i-2][j-1]>150) && (i-2>0 && j-1>0))
		{
		move_array[move_num].i=i-2;
		move_array[move_num].j=j-1;
		setcolor(3);
		if(inv[move_array[move_num].i][move_array[move_num].j]==206)
			setcolor(13);
		rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
		move_num++;
		}//if
	if((inv[i-1][j+2]<100 || inv[i-1][j+2]>150) && (i-1>0 && j+2<9))
		{
		move_array[move_num].i=i-1;
		move_array[move_num].j=j+2;
		setcolor(3);
		if(inv[move_array[move_num].i][move_array[move_num].j]==206)
			setcolor(13);
		rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
		move_num++;
		}//if
	if((inv[i+1][j+2]<100 || inv[i+1][j+2]>150) && (i+1<9 && j+2<9))
		{
		move_array[move_num].i=i+1;
		move_array[move_num].j=j+2;
		setcolor(3);
		if(inv[move_array[move_num].i][move_array[move_num].j]==206)
			setcolor(13);
		rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
		move_num++;
		}//if
	if((inv[i-2][j+1]<100 || inv[i-2][j+1]>150) && (i-2>0 && j+1<9))
		{
		move_array[move_num].i=i-2;
		move_array[move_num].j=j+1;
		setcolor(3);
		if(inv[move_array[move_num].i][move_array[move_num].j]==206)
			setcolor(13);
		rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
		move_num++;
		}//if
	if((inv[i+2][j+1]<100 || inv[i+2][j+1]>150) && (i+2<9 && j+1<9))
		{
		move_array[move_num].i=i+2;
		move_array[move_num].j=j+1;
		setcolor(3);
		if(inv[move_array[move_num].i][move_array[move_num].j]==206)
			setcolor(13);
		rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
		move_num++;
		}//if
	if((inv[i+2][j-1]<100 || inv[i+2][j-1]>150) && (i+2<9 && j-1>0))
		{
		move_array[move_num].i=i+2;
		move_array[move_num].j=j-1;
		setcolor(3);
		if(inv[move_array[move_num].i][move_array[move_num].j]==206)
			setcolor(13);
		rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
		move_num++;
		}//if
	if((inv[i+1][j-2]<100 || inv[i+1][j-2]>150) && (i+1<9 && j-2>0))
		{
		move_array[move_num].i=i+1;
		move_array[move_num].j=j-2;
		setcolor(3);
		if(inv[move_array[move_num].i][move_array[move_num].j]==206)
			setcolor(13);
		rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
		move_num++;
		}//if
	if((inv[i-1][j-2]<100 || inv[i-1][j-2]>150) && (i-1>0 && j-2>0))
		{
		move_array[move_num].i=i-1;
		move_array[move_num].j=j-2;
		setcolor(3);
		if(inv[move_array[move_num].i][move_array[move_num].j]==206)
			setcolor(13);
		rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
		move_num++;
		}//if
	break;
	case 202:
	if(inv[i-2][j-1]<200 && (i-2>0 && j-1>0))
		{
		move_array[move_num].i=i-2;
		move_array[move_num].j=j-1;
		setcolor(3);
		if(inv[move_array[move_num].i][move_array[move_num].j]==106)
			setcolor(13);
		rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
		move_num++;
		}//if
	if(inv[i-1][j+2]<200 && (i-1>0 && j+2<9))
		{
		move_array[move_num].i=i-1;
		move_array[move_num].j=j+2;
		setcolor(3);
		if(inv[move_array[move_num].i][move_array[move_num].j]==106)
			setcolor(13);
		rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
		move_num++;
		}//if
	if(inv[i+1][j+2]<200 && (i+1<9 && j+2<9))
		{
		move_array[move_num].i=i+1;
		move_array[move_num].j=j+2;
		setcolor(3);
		if(inv[move_array[move_num].i][move_array[move_num].j]==106)
			setcolor(13);
		rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
		move_num++;
		}//if
	if(inv[i-2][j+1]<200 && (i-2>0 && j+1<9))
		{
		move_array[move_num].i=i-2;
		move_array[move_num].j=j+1;
		setcolor(3);
		if(inv[move_array[move_num].i][move_array[move_num].j]==106)
			setcolor(13);
		rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
		move_num++;
		}//if
	if(inv[i+2][j+1]<200 && (i+2<9 && j+1<9))
		{
		move_array[move_num].i=i+2;
		move_array[move_num].j=j+1;
		setcolor(3);
		if(inv[move_array[move_num].i][move_array[move_num].j]==106)
			setcolor(13);
		rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
		move_num++;
		}//if
	if(inv[i+2][j-1]<200 && (i+2<9 && j-1>0))
		{
		move_array[move_num].i=i+2;
		move_array[move_num].j=j-1;
		setcolor(3);
		if(inv[move_array[move_num].i][move_array[move_num].j]==106)
			setcolor(13);
		rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
		move_num++;
		}//if
	if(inv[i+1][j-2]<200 && (i+1<9 && j-2>0))
		{
		move_array[move_num].i=i+1;
		move_array[move_num].j=j-2;
		setcolor(3);
		if(inv[move_array[move_num].i][move_array[move_num].j]==106)
			setcolor(13);
		rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
		move_num++;
		}//if
	if(inv[i-1][j-2]<200 && (i-1>0 && j-2>0))
		{
		move_array[move_num].i=i-1;
		move_array[move_num].j=j-2;
		setcolor(3);
		if(inv[move_array[move_num].i][move_array[move_num].j]==106)
			setcolor(13);
		rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
		move_num++;
		}//if
	break;
	case 101:
	for(int t=1;t<=9;t++)
		{
		if((inv[i][j+t]<100 || inv[i][j+t]>150) && (j+t<9))
			{
			move_array[move_num].i=i;
			move_array[move_num].j=j+t;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==206)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i][j+t]>=100)
			break;
		}//for
	for(t=1;t<=9;t++)
		{
		if((inv[i][j-t]<100 || inv[i][j-t]>150) && (j-t>0))
			{
			move_array[move_num].i=i;
			move_array[move_num].j=j-t;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==206)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i][j-t]>=100)
			break;
		}//for
	for(t=1;t<=9;t++)
		{
		if((inv[i+t][j]<100 || inv[i+t][j]>150) && (i+t<9))
			{
			move_array[move_num].i=i+t;
			move_array[move_num].j=j;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==206)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i+t][j]>=100)
			break;
		}//for
	for(t=1;t<=9;t++)
		{
		if((inv[i-t][j]<100 || inv[i-t][j]>150) && (i-t>0))
			{
			move_array[move_num].i=i-t;
			move_array[move_num].j=j;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==206)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i-t][j]>=100)
			break;
		}//for
	break;
	case 103:
	for(t=1;t<=9;t++)
		{
		if((inv[i+t][j+t]<100 || inv[i+t][j+t]>150) && (i+t<9 && j+t<9))
			{
			move_array[move_num].i=i+t;
			move_array[move_num].j=j+t;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==206)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i+t][j+t]>=100)
			break;
		}//for
	for(t=1;t<=9;t++)
		{
		if((inv[i-t][j-t]<100 || inv[i-t][j-t]>150) && (i-t>0 && j-t>0))
			{
			move_array[move_num].i=i-t;
			move_array[move_num].j=j-t;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==206)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i-t][j-t]>=100)
			break;
		}//for
	for(t=1;t<=9;t++)
		{
		if((inv[i+t][j-t]<100 || inv[i+t][j-t]>150) && (i+t<9 && j-t>0))
			{
			move_array[move_num].i=i+t;
			move_array[move_num].j=j-t;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==206)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i+t][j-t]>=100)
			break;
		}//for
	for(t=1;t<=9;t++)
		{
		if((inv[i-t][j+t]<100 || inv[i-t][j+t]>150) && (i-t>0 && j+t<9))
			{
			move_array[move_num].i=i-t;
			move_array[move_num].j=j+t;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==206)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i-t][j+t]>=100)
			break;
		}//for
	break;
	case 104:
	for(t=1;t<=9;t++)
		{
		if((inv[i+t][j+t]<100 || inv[i+t][j+t]>150) && (i+t<9 && j+t<9))
			{
			move_array[move_num].i=i+t;
			move_array[move_num].j=j+t;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==206)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i+t][j+t]>=100)
			break;
		}//for
	for(t=1;t<=9;t++)
		{
		if((inv[i-t][j-t]<100 || inv[i-t][j-t]>150) && (i-t>0 && j-t>0))
			{
			move_array[move_num].i=i-t;
			move_array[move_num].j=j-t;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==206)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i-t][j-t]>=100)
			break;
		}//for
	for(t=1;t<=9;t++)
		{
		if((inv[i+t][j-t]<100 || inv[i+t][j-t]>150) && (i+t<9 && j-t>0))
			{
			move_array[move_num].i=i+t;
			move_array[move_num].j=j-t;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==206)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i+t][j-t]>=100)
			break;
		}//for
	for(t=1;t<=9;t++)
		{
		if((inv[i-t][j+t]<100 || inv[i-t][j+t]>150) && (i-t>0 && j+t<9))
			{
			move_array[move_num].i=i-t;
			move_array[move_num].j=j+t;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==206)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i-t][j+t]>=100)
			break;
		}//for
	break;
	case 203:
	for(t=1;t<=9;t++)
		{
		if((inv[i+t][j+t]<200 || inv[i+t][j+t]>250) && (i+t<9 && j+t<9))
			{
			move_array[move_num].i=i+t;
			move_array[move_num].j=j+t;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==106)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i+t][j+t]>=100)
			break;
		}//for
	for(t=1;t<=9;t++)
		{
		if((inv[i-t][j-t]<200 || inv[i-t][j-t]>250) && (i-t>0 && j-t>0))
			{
			move_array[move_num].i=i-t;
			move_array[move_num].j=j-t;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==106)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i-t][j-t]>=100)
			break;
		}//for
	for(t=1;t<=9;t++)
		{
		if((inv[i+t][j-t]<200 || inv[i+t][j-t]>250) && (i+t<9 && j-t>0))
			{
			move_array[move_num].i=i+t;
			move_array[move_num].j=j-t;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==106)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i+t][j-t]>=100)
			break;
		}//for
	for(t=1;t<=9;t++)
		{
		if((inv[i-t][j+t]<200 || inv[i-t][j+t]>250) && (i-t>0 && j+t<9))
			{
			move_array[move_num].i=i-t;
			move_array[move_num].j=j+t;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==106)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i-t][j+t]>=100)
			break;
		}//for
	break;
	case 204:
	for(t=1;t<=9;t++)
		{
		if((inv[i+t][j+t]<200 || inv[i+t][j+t]>250) && (i+t<9 && j+t<9))
			{
			move_array[move_num].i=i+t;
			move_array[move_num].j=j+t;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==106)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i+t][j+t]>=100)
			break;
		}//for
	for(t=1;t<=9;t++)
		{
		if((inv[i-t][j-t]<200 || inv[i-t][j-t]>250) && (i-t>0 && j-t>0))
			{
			move_array[move_num].i=i-t;
			move_array[move_num].j=j-t;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==106)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i-t][j-t]>=100)
			break;
		}//for
	for(t=1;t<=9;t++)
		{
		if((inv[i+t][j-t]<200 || inv[i+t][j-t]>250) && (i+t<9 && j-t>0))
			{
			move_array[move_num].i=i+t;
			move_array[move_num].j=j-t;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==106)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i+t][j-t]>=100)
			break;
		}//for
	for(t=1;t<=9;t++)
		{
		if((inv[i-t][j+t]<200 || inv[i-t][j+t]>250) && (i-t>0 && j+t<9))
			{
			move_array[move_num].i=i-t;
			move_array[move_num].j=j+t;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==106)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i-t][j+t]>=100)
			break;
		}//for
	break;
	case 201:
	for(t=1;t<=9;t++)
		{
		if((inv[i][j+t]<200 || inv[i][j+t]>250) && (j+t<9))
			{
			move_array[move_num].i=i;
			move_array[move_num].j=j+t;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==106)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i][j+t]>=100)
			break;
		}//for
	for(t=1;t<=9;t++)
		{
		if((inv[i][j-t]<200 || inv[i][j-t]>250) && (j-t>0))
			{
			move_array[move_num].i=i;
			move_array[move_num].j=j-t;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==106)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i][j-t]>=100)
			break;
		}//for
	for(t=1;t<=9;t++)
		{
		if((inv[i+t][j]<200 || inv[i+t][j]>250) && (i+t<9))
			{
			move_array[move_num].i=i+t;
			move_array[move_num].j=j;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==106)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i+t][j]>=100)
			break;
		}//for
	for(t=1;t<=9;t++)
		{
		if((inv[i-t][j]<200 || inv[i-t][j]>250) && (i-t>0))
			{
			move_array[move_num].i=i-t;
			move_array[move_num].j=j;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==106)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i-t][j]>=100)
			break;
		}//for
	break;
	case 105:
	for(t=1;t<=9;t++)
		{
		if((inv[i][j+t]<100 || inv[i][j+t]>150) && (j+t<9))
			{
			move_array[move_num].i=i;
			move_array[move_num].j=j+t;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==206)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i][j+t]>=100)
			break;
		}//for
	for(t=1;t<=9;t++)
		{
		if((inv[i][j-t]<100 || inv[i][j-t]>150) && (j-t>0))
			{
			move_array[move_num].i=i;
			move_array[move_num].j=j-t;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==206)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i][j-t]>=100)
			break;
		}//for
	for(t=1;t<=9;t++)
		{
		if((inv[i+t][j]<100 || inv[i+t][j]>150) && (i+t<9))
			{
			move_array[move_num].i=i+t;
			move_array[move_num].j=j;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==206)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i+t][j]>=100)
			break;
		}//for
	for(t=1;t<=9;t++)
		{
		if((inv[i-t][j]<100 || inv[i-t][j]>150) && (i-t>0))
			{
			move_array[move_num].i=i-t;
			move_array[move_num].j=j;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==206)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i-t][j]>=100)
			break;
		}//for
	for(t=1;t<=9;t++)
		{
		if((inv[i+t][j+t]<100 || inv[i+t][j+t]>150) && (i+t<9 && j+t<9))
			{
			move_array[move_num].i=i+t;
			move_array[move_num].j=j+t;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==206)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i+t][j+t]>=100)
			break;
		}//for
	for(t=1;t<=9;t++)
		{
		if((inv[i-t][j-t]<100 || inv[i-t][j-t]>150) && (i-t>0 && j-t>0))
			{
			move_array[move_num].i=i-t;
			move_array[move_num].j=j-t;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==206)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i-t][j-t]>=100)
			break;
		}//for
	for(t=1;t<=9;t++)
		{
		if((inv[i+t][j-t]<100 || inv[i+t][j-t]>150) && (i+t<9 && j-t>0))
			{
			move_array[move_num].i=i+t;
			move_array[move_num].j=j-t;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==206)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i+t][j-t]>=100)
			break;
		}//for
	for(t=1;t<=9;t++)
		{
		if((inv[i-t][j+t]<100 || inv[i-t][j+t]>150) && (i-t>0 && j+t<9))
			{
			move_array[move_num].i=i-t;
			move_array[move_num].j=j+t;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==206)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i-t][j+t]>=100)
			break;
		}//for
	break;
	case 205:
	for(t=1;t<=9;t++)
		{
		if((inv[i][j+t]<200 || inv[i][j+t]>250) && (j+t<9))
			{
			move_array[move_num].i=i;
			move_array[move_num].j=j+t;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==106)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i][j+t]>=100)
			break;
		}//for
	for(t=1;t<=9;t++)
		{
		if((inv[i][j-t]<200 || inv[i][j-t]>250) && (j-t>0))
			{
			move_array[move_num].i=i;
			move_array[move_num].j=j-t;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==106)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i][j-t]>=100)
			break;
		}//for
	for(t=1;t<=9;t++)
		{
		if((inv[i+t][j]<200 || inv[i+t][j]>250) && (i+t<9))
			{
			move_array[move_num].i=i+t;
			move_array[move_num].j=j;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==106)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i+t][j]>=100)
			break;
		}//for
	for(t=1;t<=9;t++)
		{
		if((inv[i-t][j]<200 || inv[i-t][j]>250) && (i-t>0))
			{
			move_array[move_num].i=i-t;
			move_array[move_num].j=j;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==106)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i-t][j]>=100)
			break;
		}//for
	for(t=1;t<=9;t++)
		{
		if((inv[i+t][j+t]<200 || inv[i+t][j+t]>250) && (i+t<9 && j+t<9))
			{
			move_array[move_num].i=i+t;
			move_array[move_num].j=j+t;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==106)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i+t][j+t]>=100)
			break;
		}//for
	for(t=1;t<=9;t++)
		{
		if((inv[i-t][j-t]<200 || inv[i-t][j-t]>250) && (i-t>0 && j-t>0))
			{
			move_array[move_num].i=i-t;
			move_array[move_num].j=j-t;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==106)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i-t][j-t]>=100)
			break;
		}//for
	for(t=1;t<=9;t++)
		{
		if((inv[i+t][j-t]<200 || inv[i+t][j-t]>250) && (i+t<9 && j-t>0))
			{
			move_array[move_num].i=i+t;
			move_array[move_num].j=j-t;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==106)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i+t][j-t]>=100)
			break;
		}//for
	for(t=1;t<=9;t++)
		{
		if((inv[i-t][j+t]<200 || inv[i-t][j+t]>250) && (i-t>0 && j+t<9))
			{
			move_array[move_num].i=i-t;
			move_array[move_num].j=j+t;
			setcolor(3);
			if(inv[move_array[move_num].i][move_array[move_num].j]==106)
				setcolor(13);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		if(inv[i-t][j+t]>=100)
			break;
		}//for
	break;
	case 106:
	int shi,shj;
	for(int m=1;m<=8;m++)
		for(int n=1;n<=8;n++)
			if(inv[m][n]==206)
				{
				shi=m;
				shj=n;
				}//if
	if((inv[i+1][j+1]<100 || inv[i+1][j+1]>150) && (i+1<9 && j+1<9))
		{
		int deltai=abs(i+1-shi);
		int deltaj=abs(j+1-shj);
		if(deltai>1 || deltaj>1)
			{
			move_array[move_num].i=i+1;
			move_array[move_num].j=j+1;
			setcolor(3);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		}//if
	if((inv[i][j+1]<100 || inv[i][j+1]>150) && (j+1<9))
		{
		int deltai=abs(i-shi);
		int deltaj=abs(j+1-shj);
		if(deltai>1 || deltaj>1)
			{
			move_array[move_num].i=i;
			move_array[move_num].j=j+1;
			setcolor(3);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		}//if
	if((inv[i-1][j+1]<100 || inv[i-1][j+1]>150) && (i-1>0 && j+1<9))
		{
		int deltai=abs(i-1-shi);
		int deltaj=abs(j+1-shj);
		if(deltai>1 || deltaj>1)
			{
			move_array[move_num].i=i-1;
			move_array[move_num].j=j+1;
			setcolor(3);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		}//if
	if((inv[i-1][j]<100 || inv[i-1][j]>150) && (i-1>0))
		{
		int deltai=abs(i-1-shi);
		int deltaj=abs(j-shj);
		if(deltai>1 || deltaj>1)
			{
			move_array[move_num].i=i-1;
			move_array[move_num].j=j;
			setcolor(3);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		}//if
	if((inv[i-1][j-1]<100 || inv[i-1][j-1]>150) && (i-1>0 && j-1>0))
		{
		int deltai=abs(i-1-shi);
		int deltaj=abs(j-1-shj);
		if(deltai>1 || deltaj>1)
			{
			move_array[move_num].i=i-1;
			move_array[move_num].j=j-1;
			setcolor(3);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		}//if
	if((inv[i][j-1]<100 || inv[i][j-1]>150) && (j-1>0))
		{
		int deltai=abs(i-shi);
		int deltaj=abs(j-1-shj);
		if(deltai>1 || deltaj>1)
			{
			move_array[move_num].i=i;
			move_array[move_num].j=j-1;
			setcolor(3);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		}//if
	if((inv[i+1][j-1]<100 || inv[i+1][j-1]>150) && (i+1<9 && j-1>0))
		{
		int deltai=abs(i+1-shi);
		int deltaj=abs(j-1-shj);
		if(deltai>1 || deltaj>1)
			{
			move_array[move_num].i=i+1;
			move_array[move_num].j=j-1;
			setcolor(3);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		}//if
	if((inv[i+1][j]<100 || inv[i+1][j]>150) && (i+1<9))
		{
		int deltai=abs(i+1-shi);
		int deltaj=abs(j-shj);
		if(deltai>1 || deltaj>1)
			{
			move_array[move_num].i=i+1;
			move_array[move_num].j=j;
			setcolor(3);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		}//if
	break;
	case 206:
	for(m=1;m<=8;m++)
		for(n=1;n<=8;n++)
			if(inv[m][n]==106)
				{
				shi=m;
				shj=n;
				}//if
	if((inv[i+1][j+1]<200) && (i+1<9 && j+1<9))
		{
		int deltai=abs(i+1-shi);
		int deltaj=abs(j+1-shj);
		if(deltai>1 || deltaj>1)
			{
			move_array[move_num].i=i+1;
			move_array[move_num].j=j+1;
			setcolor(3);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		}//if
	if((inv[i][j+1]<200) && (j+1<9))
		{
		int deltai=abs(i-shi);
		int deltaj=abs(j+1-shj);
		if(deltai>1 || deltaj>1)
			{
			move_array[move_num].i=i;
			move_array[move_num].j=j+1;
			setcolor(3);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		}//if
	if((inv[i-1][j+1]<200) && (i-1>0 && j+1<9))
		{
		int deltai=abs(i-1-shi);
		int deltaj=abs(j+1-shj);
		if(deltai>1 || deltaj>1)
			{
			move_array[move_num].i=i-1;
			move_array[move_num].j=j+1;
			setcolor(3);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		}//if
	if((inv[i-1][j]<200) && (i-1>0))
		{
		int deltai=abs(i-1-shi);
		int deltaj=abs(j-shj);
		if(deltai>1 || deltaj>1)
			{
			move_array[move_num].i=i-1;
			move_array[move_num].j=j;
			setcolor(3);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		}//if
	if((inv[i-1][j-1]<200) && (i-1>0 && j-1>0))
		{
		int deltai=abs(i-1-shi);
		int deltaj=abs(j-1-shj);
		if(deltai>1 || deltaj>1)
			{
			move_array[move_num].i=i-1;
			move_array[move_num].j=j-1;
			setcolor(3);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		}//if
	if((inv[i][j-1]<200) && (j-1>0))
		{
		int deltai=abs(i-shi);
		int deltaj=abs(j-1-shj);
		if(deltai>1 || deltaj>1)
			{
			move_array[move_num].i=i;
			move_array[move_num].j=j-1;
			setcolor(3);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		}//if
	if((inv[i+1][j-1]<200) && (i+1<9 && j-1>0))
		{
		int deltai=abs(i+1-shi);
		int deltaj=abs(j-1-shj);
		if(deltai>1 || deltaj>1)
			{
			move_array[move_num].i=i+1;
			move_array[move_num].j=j-1;
			setcolor(3);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		}//if
	if((inv[i+1][j]<200) && (i+1<9))
		{
		int deltai=abs(i+1-shi);
		int deltaj=abs(j-shj);
		if(deltai>1 || deltaj>1)
			{
			move_array[move_num].i=i+1;
			move_array[move_num].j=j;
			setcolor(3);
			rectangle(move_array[move_num].j*50+73,move_array[move_num].i*50+3,move_array[move_num].j*50+117,move_array[move_num].i*50+47);
			move_num++;
			}//if
		}//if
	break;
	}//switch
}//where can go
//---------------------------------------------------------------------------
void allowed_moves(int j,int i)
{
char p[8]={10,20,30,40,50,60,70,80};
int flag=0;
if((inv[i][j]==0)&&(select==1)) flag=1;
if((i==savei)&&(j==savej))
	{
	for(int k=0;k<move_num;k++)
		{
		if((move_array[k].i+move_array[k].j)%2==0)
			setcolor(8);
		else
			setcolor(7);
		rectangle(move_array[k].j*50+73,move_array[k].i*50+3,move_array[k].j*50+117,move_array[k].i*50+47);
		move_array[k].i=move_array[k].j=0;

		}//for
	move_num=0;
	savei=0;
	savej=0;
	select=1;
	flag=1;
	x=14;
	if((i+j)%2==0)
		setcolor(8);
	else
		setcolor(7);
	rectangle(j*50+73,i*50+3,j*50+117,i*50+47);
	}//if
if((gamewith=='w')&&(select==1)&&(inv[i][j]>=200)&&(inv[i][j]<250)) flag=1;
if((gamewith=='b')&&(select==1)&&(inv[i][j]>=100)&&(inv[i][j]<150)) flag=1;
if((gamewith=='b')&&(select==2)&&(inv[i][j]>=200)&&(inv[i][j]<250)) flag=1;
if((gamewith=='w')&&(select==2)&&(inv[i][j]>=100)&&(inv[i][j]<150)) flag=1;
if((select==2)&&((inv[i][j]==106)||(inv[i][j]==206))) flag=1;
if(select==1&&flag!=1)
	{
	where_can_go(i,j);
	if(move_num==0)
		flag=1;
	}//if
if(select==1&&flag!=1)
	{
	select=2;
	savei=i;
	savej=j;
	x=12;
	setcolor(10);
	rectangle(savej*50+73,savei*50+3,savej*50+117,savei*50+47);
	flag=1;
	}//if
if(flag!=1)
	{
	flag=1;
	for(int k=0;k<move_num;k++)
		if(move_array[k].i==i&&move_array[k].j==j)
			flag=0;
	}//if
if(flag!=1)
	{
	for(int k=0;k<move_num;k++)
		{
		if((move_array[k].i+move_array[k].j)%2==0)
			setcolor(8);
		else
			setcolor(7);
		rectangle(move_array[k].j*50+73,move_array[k].i*50+3,move_array[k].j*50+117,move_array[k].i*50+47);
		}//for
	show_out_elements(i,j);
	inv[i][j]=inv[savei][savej];
	inv[savei][savej]=0;
	if((inv[i][j]==200)&&(i==1)) inv[i][j]=205;
	if((inv[i][j]==100)&&(i==8)) inv[i][j]=105;
	clr_elements(savei,savej);
	clr_elements(i,j);
	show_elements(i,j);
	if(gamewith=='w')
		gamewith='b';
	else
		gamewith='w';
	select=1;
	savei=savej=0;
	x=14;
	int c;
	if(gamewith=='w') c=15;
	else	c=0;
	setcolor(c);
	rectangle(602,22,618,38);
	setfillpattern(p,c);
	setfillstyle(1,c);
	floodfill(610,25,c);
	}//if
}//allowed moves
//---------------------------------------------------------------------------
void play(int m,int n,int o,int p)
{
int bx=m,posx=o;
int by=n,posy=p;
int check=-1;
char ch;
setcolor(14);
rectangle(posx*50+70,posy*50,posx*50+120,posy*50+50);
while((ch=getch())!=27)
	{
	if(ch==0)
		ch=getch();
	switch (ch)
		{
		case 80:
		check*=-1;
		bx=posx;
		by=posy;
		posy++;
		break;

		case 75:
		check*=-1;
		by=posy;
		bx=posx;
		posx--;
		break;

		case 77:
		check*=-1;
		by=posy;
		bx=posx;
		posx++;
		break;

		case 72:
		check*=-1;
		bx=posx;
		by=posy;
		posy--;
		break;

		case 13:
		allowed_moves(posx,posy);
		break;
		}//switch
	if(posx==0) posx=8;
	if(posx==9) posx=1;
	if(posy==0) posy=8;
	if(posy==9) posy=1;
	if(bx==0) bx=8;
	if(bx==9) bx=1;
	if(by==0) by=8;
	if(by==9) by=1;
	if(check==1)
		{
		setcolor(8);
		rectangle(bx*50+70,by*50,bx*50+120,by*50+50);
		}//if
	else
		{
		setcolor(7);
		rectangle(bx*50+70,by*50,bx*50+120,by*50+50);
		}//else
	setcolor(x);
	rectangle(posx*50+70,posy*50,posx*50+120,posy*50+50);
	}//while
}//play
//---------------------------------------------------------------------------
void main()
{
clrscr();
insert_array();
draw_inv();
for(int i=1;i<=8;i++)
	for(int j=1;j<=8;j++)
		show_elements(i,j);
play(1,1,1,1);
restorecrtmode();
}//main