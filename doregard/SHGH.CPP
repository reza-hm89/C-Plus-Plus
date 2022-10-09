#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#include<fstream.h>

#define MAX 10

enum MyBOOL{FALSE,TRUE};

void CleanMinpath(int ID);
void set(int ID,MyBOOL sw);
void CheckPath();
void setOpath(long l);
long getPath(int k,int z);
void InterData();
void choice();
void begin();
void Save();
void Load();

long *visited;
long *minpath;
long *opath;
long  length;
int   n;
long  a[MAX][MAX];
long  Infinity;
//////////////////////////////////////////////////////////
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
	outtextxy(190-80,240,"Ghasemi");
	delay(100);
	setfillstyle(1,0);
	bar(10,10,630,430);
	settextstyle(1,0,6);
	outtextxy(230-80,260,"Ghasemi");
	delay(100);
	setfillstyle(1,0);
	bar(10,10,620,430);
	settextstyle(1,0,5);
	outtextxy(250-100,269,"Ghasemi");
	delay(100);
	setfillstyle(1,0);
	bar(10,10,620,430);
	settextstyle(1,0,4);
	outtextxy(260-100,278,"Ghasemi");
	delay(100);
	setfillstyle(1,0);
	bar(10,10,600,400);
	settextstyle(1,0,5);
	outtextxy(250-80,269,"Ghasemi");
	delay(100);
	setfillstyle(1,0);
	bar(10,10,600,400);
	settextstyle(1,0,6);
	outtextxy(230-80,260,"Ghasemi");
	delay(100);
	setfillstyle(1,0);
	bar(10,10,600,400);
	settextstyle(1,0,9);
	outtextxy(190-80,240,"Ghasemi");
	delay(100);
	setfillstyle(1,0);
	bar(10,10,600,400);
	settextstyle(1,0,11);
	outtextxy(150-80,220,"Ghasemi");
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
	outtextxy(190-80,240,"Ghasemi");
settextstyle(1,0,4);
outtextxy(20,30,"Writer :");
bar(600,300,630,470);
settextstyle(0,0,0);
outtextxy(220,450,"Press sny key to start");
setfillstyle(SOLID_FILL,8);
for (i=1;i!=479;i++,j++)        //kadre chapo raast
   {
	bar(0,i,7,i++);
	bar(632,j,639,j++);
   }
}
//////////////////////////////////////////////////////////////////////////
void CleanMinpath(int ID)
{

minpath[0]=ID;
for(int i=1;i<n;i++)
      minpath[i]=-1;

}
///////////////////////////////////////////////////////////////////////////
void set(int ID,MyBOOL sw)
{
if(ID==-1)
	for(int i=0;i<n;i++)
		visited[i]=sw;

else
   visited[ID]=sw;
}
/////////////////////////////////////////////////////////////////////////
void setOpath(long l)
{
opath[0]=l;
for(int i=0;i<n;i++)
    opath[i+1]=minpath[i];

opath[n+1]=minpath[0];
}
/////////////////////////////////////////////////////////////
long getPath(int k,int z)
{
int next,min,vcnt=1;
long plength=0;
minpath[0]=k;
minpath[1]=z;
set(z,TRUE);
plength+=a[k][z];
for(int g=z;vcnt<n-1;vcnt++)
{
   min=Infinity;
   for(int i=0;i<n;i++)
   if(a[g][i]<Infinity && !visited[i] && a[g][i]<=min)
	min=a[g][next=i];

   set(next,TRUE);
   g=minpath[vcnt+1]=next;
   plength+=min;

}
plength+=a[minpath[n-1]][k];
return(plength);
}
//////////////////////////////////////////////////////////////
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
	outtextxy(470,420,"Save kardan dar file");
	outtextxy(470,380,"Load kardan az file");
	outtextxy(470,340,"Voroode dasti");
	outtextxy(470,460,"Exit");
	outtextxy(435,340,"¯");
	int y=340;
	char ch;
	while (ch!=27)
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
		  setfillstyle(1,0);
		  bar(1,285,640,480);
		  InterData();
		  break;
	   }
	   else if (ch==13 && y==420)
	   {
		  setfillstyle(1,0);
		  bar(1,285,640,480);
		  Save();
		  break;
	   }
	   else if(ch==13 && y==380)
	   {
		 setfillstyle(1,0);
		  bar(1,285,640,480);
		  Load();
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
//////////////////////////////////////////////////////////////////////////
void InterData()
{
restorecrtmode();
textmode(LASTMODE);
clrscr();
cout<<"meghdare binahayat ra vared konid:";
cin>>Infinity;
int i,j;

cout<<"\n\ntedade shahrha:(MAX:"<<MAX<<")";
cin>>n;

cout<<"\nMatrixe rah hara vared konid:";

for(i=0;i<n;i++)
{
	cout<<"\nsatre"<<i<<":[";
	for(j=0;j<n;j++)
		cin>>a[i][j];
	cout<<"]";
}
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
		if (a[i][j]==0)
			a[i][j]=Infinity;
}
clrscr();
cout<<"Matrix:\n\n\n";
char ch=236;
for (i=0;i<n;i++)
{
	for (j=0;j<n;j++)
	if (a[i][j]==Infinity)
		cprintf("%6c",ch);
	else
		cprintf("%6.1d",a[i][j]);
	cout<<"\n\n";
}
cout<<"\n\n";
CheckPath();
}
/////////////////////////////////////////Checkpath/////////////////////////
void CheckPath()
{

cout<<"Calculating";
delay(500);
cout<<".";
delay(500);
cout<<".";
delay(500);
cout<<".\n";
long newLength=Infinity;
visited=new long[n];
minpath=new long[n];
opath=new long[n+2];
length=Infinity;
for(int id=0;id<n;id++)
{
	for(int i=0;i<n;i++)
	{       set(-1,FALSE);
		set(id,TRUE);
		CleanMinpath(id);
		newLength=getPath(id,i);
		if(newLength<=length)
			setOpath(length=newLength);
	}
}
if(length<Infinity)
{
	cout<<"\n\nMinimum toole masir: "<<length<<"\n";
	cout<<"masir:";
	for(int i=1;i<n+2;i++)
	{
		cout<<"("<<opath[i]<<")";
		if (i!=n+1)
			cout<<" ¯ ";
	}

}
else
     cout<<"!!!ERROR:Masiri peida nashod!!!!";
getch();
setgraphmode(getgraphmode());
choice();
}
////////////////////////////////Load////////////////////////////////////
void Load()
{
restorecrtmode();
textmode(LASTMODE);
ifstream Load;
Load.open("ShGhData.dat",ios::binary);
if (!Load)
{
	cout<<"!!Shoma ghablan etelaati ra zakhire nakarde iid!!";
	getch();
	setgraphmode(getgraphmode());
	choice();
}
Load>>n>>Infinity;
for (int i=0;i<n;i++)
	for (int j=0;j<n;j++)
		Load>>a[i][j];
clrscr();
cout<<"Loading Informations";
delay(500);
cout<<".";
delay(500);
cout<<".";
delay(500);
cout<<".\n";
delay(200);
Load.close();
clrscr();
cout<<"Loaded Path Matrix:\n\n\n";
char ch=236;
for (i=0;i<n;i++)
{
	for (j=0;j<n;j++)
	if (a[i][j]==Infinity)
		cprintf("%6c",ch);
	else
		cprintf("%6.1d",a[i][j]);
	cout<<"\n\n";
}
cout<<"\n\n";
CheckPath();
}
//////////////////////////////Save////////////////////////////////////////
void Save()
{
restorecrtmode();
textmode(LASTMODE);
ofstream Save;
Save.open("ShGhData.dat",ios::binary);
Save.close();
Save.open("ShGhData.dat",ios::binary);
Save<<n<<' '<<Infinity<<' ';
for (int i=0;i<n;i++)
	for (int j=0;j<n;j++)
		Save<<a[i][j]<<' ';
clrscr();
cout<<"Saving Informations";
delay(500);
cout<<".";
delay(500);
cout<<".";
delay(500);
cout<<".\n";
Save.close();
setgraphmode(getgraphmode());
choice();
}
//////////////////////////////////////////////////////////////////////////
void main()
{
  int driver=DETECT,mode;
  initgraph(&driver,&mode,"c:\\tc\\bgi");
  begin();

  if (!getch())
	getch();
  cleardevice();
  choice();
  closegraph();

}