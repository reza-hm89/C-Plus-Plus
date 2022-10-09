#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<stdio.h>
///

void clr(int x,int y);
void clr_ar(int x,int y);   ///pak kardane kadr.
void ins_ar(int x,int y);  ///keshidane kadr.
void pr(int x,int y,char ch);
///..............................................................................sar-a-sari
int enb[30][30];  ///enable
int bmb[30][30];  ///bomb
int bm_near[30][30];  ///tedade bomb-haye atrafe har khane.
int sz;

///....................................................................................

int main()
{
int exit=2;
randomize();
textcolor(6);
clrscr();
while(exit==2)
{
int bm_num,tx1,xx,yy,win,i,j,pos,x_pos,y_pos,emp;
int end=0;
win=1;
char name[100];
clrscr();
////
cout<<"\nWellcome to... \n\n";
delay(500);
cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
delay(500);
cout<<"@@  @@@@@  @@     @@  @@@@ @@    @@\n";
delay(500);
cout<<"@@ @ @@@ @ @@@@ @@@@ @ @@@ @@ @@@@@\n";
delay(500);
cout<<"@@ @@ @ @@ @@@@ @@@@ @@ @@ @@    @@\n";
delay(500);
cout<<"@@ @@@@@@@ @@@@ @@@@ @@@ @ @@ @@@@@\n";
delay(500);
cout<<"@@ @@@@@@@ @@     @@ @@@@  @@    @@\n";
delay(500);
cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
delay(500);
cout<<"\n                         Sweeeper!!\n";
delay(1000);
cout<<"\n Directed By "<<(char)2<<" *Sadegh Eftekhari*\n\n\n";
delay(2000);
cout<<"----------------------------------------------------\n";
cout<<" |  Up ,Down ,Left ,Right :  Move To Other Points.|\n";
cout<<" |  Space                 :  Select a Point.      |\n";
cout<<" |  Escape                :  Exit The Game.       |\n";
cout<<"----------------------------------------------------\n\n\n";
cout<<"    LOADING (10 s) :";
for(i=0;i<=20;i++){
cout<<">";
delay(500);
}
textcolor(4);
clrscr();
////
cout<<"\n"<<(char)2<<" : What Is Your Name ?      ";
gets(name);
clrscr();
do
{
cout<<"\n"<<(char)2<<" : Hi "<<name<<", Enter a Size For Game(5-20) :       ";
cin>>sz;
clrscr();
}while(sz>20 || sz<5);
do
{
cout<<"\n"<<(char)2<<" : Now Enter Number Of Mines (1-"<<(sz*sz)/3<<") :       ";
cin>>bm_num;
clrscr();
}while(bm_num<1 || bm_num>(sz*sz)/3);
/// ijade khane-ha..............................................................................

for(xx=1;xx<=sz;xx++)
for(yy=1;yy<=sz;yy++)
{
enb[xx-1][yy-1]=1;
bmb[xx-1][yy-1]=0;
bm_near[xx-1][yy-1]=0;
}

///ijade bomb-ha.......................................................................................

i=1;
while(i<=bm_num)
{
xx=1+random(sz);
yy=1+random(sz);
if (bmb[xx-1][yy-1]==0){
bmb[xx-1][yy-1]=1;
i++;
}
}

////bomb-haye atraf......................................................................
for(xx=1;xx<=sz;xx++)
for(yy=1;yy<=sz;yy++)
{
	for(i=xx-1;i<=xx+1;i++)
	for(j=yy-1;j<=yy+1;j++)
	{
		if (i>=1 && i<=sz && j>=1 && j<=sz)
		{
			if (bmb[i-1][j-1]==1)
			{
				bm_near[xx-1][yy-1]++;
			}
		}
	}
}
////chap...................................................................................
textcolor(3);
clrscr();
cout<<(char)2<<" : "<<name<<" Is Playing a Game With "<<bm_num<<" Mines.\n";
for(yy=1;yy<=2*sz;yy++) /// chape khane-ha...
{
	for(xx=1;xx<=2*sz;xx++)
	{
		if (yy%2==0 && xx%2==0)
		{
			cout<<" #";
		}
	}
	cout<<"\n";
}

///kelidha..................................................................................
x_pos=1;
y_pos=1;
ins_ar(x_pos,y_pos);
while(end==0)
{
	char key;
	key=getch();
	if (key==0)
	{
		///..................................................................................................up
		key=getch();
		if (key==72)      ///key up
		{
			if( y_pos>1)
			{
				clr_ar(x_pos,y_pos);
				y_pos--;
				ins_ar(x_pos,y_pos);
			}
		}
		/////..........................................................................................................left
		else if (key==75)      ///key up
		{
			if( x_pos>1)
			{
				clr_ar(x_pos,y_pos);
				x_pos--;
				ins_ar(x_pos,y_pos);
			}
		}
		/////..........................................................................................................down
		else if (key==80)      ///key up
		{
			if( y_pos<sz)
			{
				clr_ar(x_pos,y_pos);
				y_pos++;
				ins_ar(x_pos,y_pos);
			}
		}
		/////..........................................................................................................right
		else if (key==77)      ///key up
		{
			if( x_pos<sz)
			{
				clr_ar(x_pos,y_pos);
				x_pos++;
				ins_ar(x_pos,y_pos);
			}
		}
		///
	}else if(key==32)
	{
		if (enb[x_pos-1][y_pos-1]==1)
		{
			if (bmb[x_pos-1][y_pos-1]==0)
			{
				if (bm_near[x_pos-1][y_pos-1]==0)
				{
					pr(x_pos*2,y_pos*2+1,'.');
					enb[x_pos-1][y_pos-1]=0;
					clr(x_pos,y_pos);
						emp=0;
						for(xx=1;xx<=sz;xx++){
						for(yy=1;yy<=sz;yy++) {
						if (enb[xx-1][yy-1]==1){
						emp++;}}}
					if (emp==bm_num)
					end=1;

				}else
				{

					gotoxy(x_pos*2,y_pos*2+1);
					cout<<bm_near[x_pos-1][y_pos-1];
					enb[x_pos-1][y_pos-1]=0;
						emp=0;
						for(xx=1;xx<=sz;xx++){
						for(yy=1;yy<=sz;yy++) {
						if (enb[xx-1][yy-1]==1){
						emp++;}}}
					if (emp==bm_num)
					end=1;
				}
			}else
			{
				gotoxy(x_pos*2,y_pos*2+1);
				cout<<(char)15;
				cout<<(char)7;
				end=1;win=0;
			}
		}
	}else if (key==27){return 0;}
}
///
if (win==0)
{
	gotoxy(1,2*sz+3);
	cout<<"Sorry, You Lose!!\n";
}else
{
	gotoxy(1,2*sz+3);
	cout<<"\a YOU\n\n";
	cout<<"#####################################\n";
	cout<<"## ############# ##     ## #### ## ##\n";
	cout<<"## ############# #### ####  ### ## ##\n";
	cout<<"## #####   ##### #### #### #  # ## ##\n";
	cout<<"### ### ### ### ##### #### ###  #####\n";
	cout<<"####   #####   ####     ## #### ## ##\n";
	cout<<"#####################################\n";
}
///
cout<<"1-Exit.\n";
cout<<"2-Try Again.\n";
tx1=getch();
if (tx1==50)
exit=2;
else
exit=0;
///
}   ///end do

return 0;
}

///tabe...........................................................................................................

void clr(int x,int y)
{
int i,j,sw;
					   ///khane pooch ast!
			for(i=x-1;i<=x+1;i++)
			for(j=y-1;j<=y+1;j++)
			{
			if (i==x && j==y)
			sw=0;
			else
			sw=1;
			if (sw==1)
			{
			if (i>=1 && i<=sz && j>=1 && j<=sz)
			{
				if (enb[i-1][j-1]==1)
				{
					if (bmb[i-1][j-1]==0)
					{
						if (bm_near[i-1][j-1]==0)
						{
							enb[i-1][j-1]=0;
							pr(i*2,j*2+1,'.');
							clr(i,j);
						}else
						{
							enb[i-1][j-1]=0;
							gotoxy(i*2,j*2+1);
							cout<<bm_near[i-1][j-1];
						}
					}


				}
			}
			}
			}
return;
}


///.................................................................................................

void clr_ar(int x,int y)
{
gotoxy(2*x-1,2*y);
cout<<' ';
gotoxy(2*x,2*y);
cout<<' ';
gotoxy(2*x+1,2*y);
cout<<' ';
gotoxy(2*x-1,2*y+1);
cout<<' ';
gotoxy(2*x+1,2*y+1);
cout<<' ';
gotoxy(2*x-1,2*y+2);
cout<<' ';
gotoxy(2*x,2*y+2);
cout<<' ';
gotoxy(2*x+1,2*y+2);
cout<<' ';
return;
}

///////..................................................................................

void ins_ar(int x,int y)
{
gotoxy(2*x,2*y);
cout<<(char)31;
gotoxy(2*x-1,2*y+1);
cout<<(char)16;
gotoxy(2*x+1,2*y+1);
cout<<(char)17;
gotoxy(2*x,2*y+2);
cout<<(char)30;
return;
}
///......................
void pr(int x,int y,char ch)
{
gotoxy(x,y);
cout<<ch;
}













