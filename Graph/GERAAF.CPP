#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include<math.h>
int a[2][12]={{320,210,430,130,510,120,520,130,510,210,430,320}
		,{20,40,40,90,90,130,130,170,170,220,220,250}};
int b[2][12]={{317,207,427,112,523,100,533,110,524,207,427,317}
		,{2,20,20,86,86,126,126,167,167,234,234,263}};
char str[255];
int  ras;
int  matrix[12][12];
void begin();
void start();
void get_yaal();
void draw_line();
void choice();
void matrix_menu();
void hamjavari();
void yaalha();
void hambastegy();
void hambandi();
/////////////////////////****************************\\\\\\\\\\\\\\\\\\\\\\\
void begin()
{
int i,j;
cleardevice();
for(int cntr=10;cntr<14;cntr++)
{
setfillstyle(1,0);
bar(1,1,640,480);
	delay(3);
	i=320;j=1;
	setcolor(cntr);
	while (1)
	{
	if ((i<639) && (j==1) )
	i+=6;
	if ((i>639) && (j<480))
		j+=6;
	if ((j>=480))
		i-=6;
	if ((i<5) )
		j-=6;
	if ((j<5))
		i+=6;
	line(320,240,i,j);
	delay(1);
	if (i==320 && j==1 )
		break;
	}
	delay(2);
}
cleardevice();
j=319;
 for (i=319;i!=639;i++,j--)      //kadre bala
   {
	delay(1);
	setfillstyle(SOLID_FILL ,8);
	bar(i,1,i++,7);
	bar(j,1,j--,7);
   }
   j=1;
   for (i=1;i!=479;i++,j++)        //kadre chapo raast
   {
	delay(1);
	bar(0,i,7,i++);
	bar(632,j,639,j++);
   }
   j=639;
   for (i=0;i!=322;i++)           //kadre payin
   {
	delay(1);
	bar(i,472,i++,479);
	bar(j,472,j--,479);
	j--;
   }
	setcolor(13);
	settextstyle(1,0,9);
	outtextxy(90,140,"Shiva");
	delay(100);
	setfillstyle(1,0);
	bar(10,10,600,400);
	settextstyle(1,0,6);
	outtextxy(130,160,"Shiva");
	delay(100);
	setfillstyle(1,0);
	bar(10,10,600,400);
	settextstyle(1,0,5);
	outtextxy(150,169,"Shiva");
	delay(100);
	setfillstyle(1,0);
	bar(10,10,600,400);
	settextstyle(1,0,4);
	outtextxy(160,178,"Shiva");
	delay(100);
	setfillstyle(1,0);
	bar(10,10,600,400);
	settextstyle(1,0,5);
	outtextxy(150,169,"Shiva");
	delay(100);
	setfillstyle(1,0);
	bar(10,10,600,400);
	settextstyle(1,0,6);
	outtextxy(130,160,"Shiva");
	delay(100);
	setfillstyle(1,0);
	bar(10,10,600,400);
	settextstyle(1,0,9);
	outtextxy(90,140,"Shiva");
	delay(100);
	setfillstyle(1,0);
	bar(10,10,600,400);
	settextstyle(1,0,11);
	outtextxy(50,120,"Shiva");
	setfillstyle(1,0);
	bar(10,10,600,400);
	settextstyle(1,0,9);
	outtextxy(190-60,240,"Ghasemi");
	delay(100);
	setfillstyle(1,0);
	bar(10,10,630,430);
	settextstyle(1,0,6);
	outtextxy(230-60,260,"Ghasemi");
	delay(100);
	setfillstyle(1,0);
	bar(10,10,620,430);
	settextstyle(1,0,5);
	outtextxy(250-60,269,"Ghasemi");
	delay(100);
	setfillstyle(1,0);
	bar(10,10,620,430);
	settextstyle(1,0,4);
	outtextxy(260-60,278,"Ghasemi");
	delay(100);
	setfillstyle(1,0);
	bar(10,10,600,400);
	settextstyle(1,0,5);
	outtextxy(250-60,269,"Ghasemi");
	delay(100);
	setfillstyle(1,0);
	bar(10,10,600,400);
	settextstyle(1,0,6);
	outtextxy(230-60,260,"Ghasemi");
	delay(100);
	setfillstyle(1,0);
	bar(10,10,600,400);
	settextstyle(1,0,9);
	outtextxy(190-60,240,"Ghasemi");
	delay(100);
	setfillstyle(1,0);
	bar(10,10,600,400);
	settextstyle(1,0,11);
	outtextxy(150-60,220,"Ghasemi");
	setfillstyle(1,0);
	bar(10,10,600,400);
setfillstyle(9,8);
bar(7,7,632,472);
setcolor(13);
int   x[10],y[10];
    int   x_center = 510, y_center = 120, rad = 100;
    for ( i = 0; i < 10; i++ )
    {
       x[i] =  x_center + rad *  cos(36*i*3.14159/180);
       y[i] =  y_center + rad *  sin(36*i*3.14159/180);
    }
    for ( i = 0; i < 10; i++ )
       for ( j = 0; j < 10; j++ )
	  line(x[i],y[i],x[j],y[j]);
settextstyle(1,0,9);
	outtextxy(90,140,"Shiva");
settextstyle(1,0,9);
	outtextxy(190-40,240,"Ghasemi");
settextstyle(1,0,4);
outtextxy(20,30,"Writer :");
bar(600,300,630,470);
settextstyle(0,0,0);
outtextxy(220,450,"Press sny key to start");
}
//////////**************************************************\\\\\\\\\\\\\\\\\
void start()
{
begin();
getch();
cleardevice();
settextstyle(0,0,0);
line(1,280,640,280);
line(1,281,640,281);
line(1,282,640,282);
char *n1[1];
*n1[0]=NULL;
setcolor(15);
outtextxy(1,302,"(For example with 3 vertexes we have a,b,c)");
outtextxy(3,290,"Enter number of Vertexes(0<V<13):");
int x=270;
*n1[0]=10;
setcolor(9);
int n=0;
while (1)
{
*n1[0]=getch();
if (*n1[0]==13)
	break;
outtextxy(x,290,n1[0]);
x+=10;
n=(n*10)+(*n1[0])-48;
}
char *ch[1];
*ch[0]='a';
setfillstyle(1,14);
setcolor(14);
//settextstyle(2,0,4);
outtextxy(140,10,"");
for (int i=0;i<n;pieslice(a[0][i],a[1][i],0,360,3),i++,(*ch[0])++){
	outtextxy(b[0][i],b[1][i],ch[0]);
	outtextxy(10,10,"");
	}
ras=n;
settextstyle(0,0,0);
}
/////////////////////*************************************\\\\\\\\\\\\\\\\\\
void get_yaal()
{
 setfillstyle(1,0);
 char *ch[1];
 str[0]=NULL;
 *ch[0]=NULL;
 int i=0,x=1,y=370;
 setcolor(9);
 outtextxy(1,330,"Enter yaalha:(For example a,b c,d a,c b,c )");
 setcolor(14);
 while (1)
 {
    *ch[0]=getch();
    if (*ch[0]==13)
	break;
    else if (*ch[0]==8)
    {
	x-=9;
	bar(x,y,x+9,y+10);
	str[--i]=NULL;
    }
    else
    {
    outtextxy(x,y,ch[0]);
    str[i++]=*ch[0];
    x+=9;
    if (x>346)
    {
	x=1;
	y+=15;
    }
    }
 }
 draw_line();
}
///////////////////*************************\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
void draw_line()
{
for (int i=0;i<12;i++)
	for(int j=0;j<12;j++)
		matrix[i][j]=0;
char ch;
int color[7]={9,10,11,12,13,14,15};
int len,beg=0,end=0,col;
len=strlen(str);
for (i=0;i<len;i+=4)
{
  ch='a';
  for (j=0;j<12;j++,ch++)
  {
	if (str[i]==ch)
		beg=j;
	if (str[i+2]==ch)
		end=j;
  }
  delay(100);
  setcolor(color[random(7)]);
  line(a[0][beg],a[1][beg],a[0][end],a[1][end]);
  if (beg==end)
  {
	setcolor(15);
	setfillstyle(1,15);
	pieslice(a[0][beg],a[1][beg],0,360,7);
  }
  matrix[beg][end]=1;
}
}
////////////*********************************************\\\\\\\\\\\\\\\\\\\
void choice()
{
	setcolor(13);
	setfillstyle(1,0);
	line(411,286,639,286);
	line(411,285,639,285);
	for (int i=286;i<479;delay(3),i++)
	{
	line(411,i,411,i);
	line(639,i,639,i);
	line(412,i,412,i);
	line(638,i,638,i);
	}
	delay(30);
	line(411,479,639,479);
	delay(30);
	line(411,478,639,478);
	outtextxy(415,300,"Select:");
	setcolor(12);
	outtextxy(470,400,"Barrasie hambandi");
 //	outtextxy(470,380,"Noghteye boresh");
	outtextxy(470,340,"Rasme matrixha");
	outtextxy(470,460,"Exit");
	outtextxy(435,340,"¯");
	int y=340;
	char ch;
	while (1)
	{
	   ch=getch();
	   if (!ch)
		ch=getch();
	   setcolor(0);
	   outtextxy(435,y,"¯");
	   switch (ch){
	   case 80:y+=60;break;
	   case 72:y-=60;break;
	   }
	   if (ch==13 && y==340)
	   {
		  setfillstyle(1,0);
		  bar(1,285,640,480);
		  matrix_menu();
		  break;
	   }
	   else if (ch==13 && y==400)
	   {
		  setfillstyle(1,0);
		  bar(1,285,640,480);
		  hambandi();
		  break;
	   }
	   else if (ch==13 && y==460)
		exit(0);
	   if (y>460)
		y=340;
	   if (y<340)
		y=460;
	   setcolor(12);
	   outtextxy(435,y,"¯");
	}
}
///////////////////////////*********************************\\\\\\\\\\\\\\\\
void matrix_menu()
{
setcolor(13);
setfillstyle(1,0);
line(411,286,639,286);
line(411,285,639,285);
for (int i=286;i<479;delay(3),i++)
{
line(411,i,411,i);
line(639,i,639,i);
line(412,i,412,i);
line(638,i,638,i);
}
delay(30);
line(411,479,639,479);
delay(30);
line(411,478,639,478);
outtextxy(415,300,"Type:");
setcolor(12);
//outtextxy(470,400,"Hamband");
outtextxy(470,340,"Hambastegi");
outtextxy(470,380,"Hamjavari");
outtextxy(470,420,"Yaalha");
outtextxy(470,460,"Menu");
outtextxy(435,340,"¯");
int y=340;
char ch;
while (1)
{
   ch=getch();
   if (!ch)
	ch=getch();
   setcolor(0);
   outtextxy(435,y,"¯");
   switch (ch){
   case 80:y+=40;break;
   case 72:y-=40;break;
   }
   if (ch==13 && y==340)
   {
	hambastegy();
	break;
   }
   else if (ch==13 && y==380)
   {
	  hamjavari();
	  break;
   }
   else if (ch==13 && y==420)
   {
	yaalha();
	break;
   }
   else if (ch==13 && y==460)
   {
	  setfillstyle(1,0);
	  bar(1,285,640,480);
	  choice();
	  break;
   }
   if (y>460)
	y=340;
   if (y<340)
	y=460;
   setcolor(12);
   outtextxy(435,y,"¯");
}
}
/////////////////////////*******************************\\\\\\\\\\\\\\\\\\\\\
void hamjavari()
{
char *ch;
int i,j,y=355,x=15;
setfillstyle(1,0);
bar(1,285,640,480);
setcolor(14);
settextstyle(10,0,1);
outtextxy(3,295,"Hamjavari:");
settextstyle(0,0,0);
*ch=201;
outtextxy(3,345,ch);
*ch=187;
outtextxy((ras*10)+15,345,ch);
*ch=186;
for (i=0;i<(10*ras);i+=8)
{
	outtextxy(3,350+i,ch);
	outtextxy((ras*10)+15,350+i,ch);
}
*ch=200;
outtextxy(3,350+i,ch);
*ch=188;
outtextxy((ras*10)+15,350+i,ch);
for (i=0;i<ras;i++)
{
	for (j=0;j<ras;x+=10,j++)
	{
		delay(7);
		*ch=(char)matrix[i][j];
		*ch+=48;
		outtextxy(x,y,ch);
	}
	*ch=186;
	y+=10;
	x=15;
}
matrix_menu();
}
////////////////////////////***********yaalha**********\\\\\\\\\\\\\\\\\\\\\
void yaalha()
{
char *ch;
int i=0,j=0,y=330,number=1,x=1;
setfillstyle(1,0);
bar(1,285,640,480);
setcolor(14);
settextstyle(10,0,1);
outtextxy(5,280,"Yaalha:");
settextstyle(0,0,0);
setfillstyle(1,14);
bar(x+16,y-4,x+25,y-6);
setcolor(0);
line(x+16,y-5,x+25,y-5);
setcolor(14);
while (j<strlen(str))
{
delay(17);
if (number<10){
*ch=number;
*ch+=48;
outtextxy(x,y,ch);  }
else{
*ch=number%10;
*ch+=48;
outtextxy(x+8,y,ch);
*ch=number/10;
*ch+=48;
outtextxy(x,y,ch);}
*ch=str[j];
outtextxy(x+23,y,ch);
outtextxy(x+31,y," ");
*ch=str[j+2];
outtextxy(x+41,y,ch);
setfillstyle(1,14);
bar(x+16,y-4,x+18,y+9);
setcolor(0);
line(x+17,y-4,x+17,y+9);
setcolor(14);
i+=8;
y+=10;
j+=4;
if (y>470){
y=330;x+=75;
}
number++;
}
bar(x+16,y,x+25,y+2);
setcolor(0);
line(x+16,y+1,x+25,y+1);
setcolor(14);
matrix_menu();
}
////////////////*******************vabastegy*********\\\\\\\\\\\\\\\\\\
void hambastegy()
{
char *ch,*ch2;
int i,yal=0,y=350,arr[12][40],j=0;
for (i=0;i<12;i++)
	for (j=0;j<40;j++)
		arr[i][j]=0;
j=0;
if (str[strlen(str)-1]==' ')
	yal=strlen(str)/4;
else
	yal=(strlen(str)+1)/4;
for (i=0;i<strlen(str);i+=4){
arr[str[i]-97][j]=1;
arr[str[i+2]-97][j++]=1;
}
setfillstyle(1,0);
bar(1,285,640,480);
setcolor(14);
settextstyle(10,0,1);
outtextxy(3,277,"Hambastegi:");
settextstyle(0,0,0);
*ch='a';
int x;
setfillstyle(1,14);
bar(11,342,22,346);
for (i=0;i<ras;i++){
outtextxy(1,y,ch);
(*ch)++;
setfillstyle(1,14);
bar(11,y-4,14,y+9);
setcolor(0);
line(13,y-4,13,y+9);
setcolor(14);
bar(11+(yal*10),y-4,14+(yal*10),y+9);
setcolor(0);
line(12+(yal*10),y-4,12+(yal*10),y+9);
setcolor(14);
x=17;
for (j=0;j<yal;j++){
	*ch2=arr[i][j];
	*ch2+=48;
	outtextxy(x,y,ch2);
	x+=9;
}
y+=10;
}
bar(11,y,22,y+4);
bar(14+(yal*10),y,(yal*10)+3,y+4);
bar(14+(yal*10),342,(yal*10)+3,346);
matrix_menu();
}
/////////////////////////****************************\\\\\\\\\\\\\\\\\\\\
void hambandi()
{
int a[12];
for (int i=0;i<12;i++ )
		a[i]=0;
for (i=0;i<strlen(str);i+=2)
	a[str[i]-97]=1;
setcolor(13);
int flag=0;
for (i=0;i<ras;i++)
	if (a[i]==0)
		flag=1;
settextstyle(10,0,4);
if (flag==1)
	    outtextxy(20,350,"Hamband Nist");
else
	outtextxy(20,350,"Hamband Ast");
settextstyle(0,0,0);
choice();
}
/////////////////////////////////////////
void main()
{
  int driver=DETECT,mode;
  initgraph(&driver,&mode,"c:\\tc\\bgi");
  cleardevice();
  start();
  get_yaal();
  choice();
  getch();
}
