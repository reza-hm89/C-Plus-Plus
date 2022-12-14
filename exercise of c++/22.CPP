# include<iostream.h>
# include<conio.h>
int act[127][3]={0},towers[8][3]={0};
int k=0;
//==============================================================================
void hanoi(int n,int from,int dest,int help)
{
if(n==1)
	{
	act[k][0]=n;
	act[k][1]=from;
	act[k][2]=dest;
	k++;
	}//If
else
	{
	hanoi(n-1,from,help,dest);
	act[k][0]=n;
	act[k][1]=from;
	act[k][2]=dest;
	k++;
	hanoi(n-1,help,dest,from);
	}//Esle
}//Hanoi
//==============================================================================
void print_hanoi(int tow[8][3])
{
int c,i,j,t,m,n;
char ch=219;
//------------------------------------------------------------------------------
clrscr();
gotoxy(17,1);
textcolor(14);
cprintf("Graphic Hanoi Towers - Directed By Saeed Ghasemi");
gotoxy(10,20);
textcolor(15);
for(c=0;c<17;c++)
	cprintf("%c",ch);
gotoxy(32,20);
textcolor(15);
for(c=0;c<17;c++)
	cprintf("%c",ch);
gotoxy(54,20);
textcolor(15);
for(c=0;c<17;c++)
	cprintf("%c",ch);
for(c=10;c<=19;c++)
	{
	gotoxy(18,c);
	cprintf("%c",ch);
	}//For
for(c=10;c<=19;c++)
	{
	gotoxy(40,c);
	cprintf("%c",ch);
	}//For
for(c=10;c<=19;c++)
	{
	gotoxy(62,c);
	cprintf("%c",ch);
	}//For
//------------------------------------------------------------------------------
t=1;
for(i=1;i<8;i++)
	for(j=1;j<=1;j++)
 	{
 	gotoxy(j*17+t,i+12);
 	if(tow[i-1][j-1]==0)
 		textcolor(15);
 	else
 		textcolor(tow[i-1][j-1]+1);
 	cprintf("%c",ch);
 	m=((tow[i-1][j-1]*2)/2);
 		for(n=0;n<m;n++)
 		{
 		gotoxy(j*17+t+n+1,i+12);
 		cprintf("%c",ch);
 		}//For
 		for(n=m;n>0;n--)
 		{
 		gotoxy(j*17+t-n,i+12);
 		cprintf("%c",ch);
 		}//For
 	}//For
t=6;
for(i=1;i<8;i++)
	for(j=2;j<=2;j++)
 	{
 	gotoxy(j*17+t,i+12);
  	if(tow[i-1][j-1]==0)
 		textcolor(15);
 	else
 		textcolor(tow[i-1][j-1]+1);
 	cprintf("%c",ch);
 	m=((tow[i-1][j-1]*2)/2);
 		for(n=0;n<m;n++)
 		{
 		gotoxy(j*17+t+n+1,i+12);
      cprintf("%c",ch);
 		}//For
 		for(n=m;n>0;n--)
 		{
 		gotoxy(j*17+t-n,i+12);
 		cprintf("%c",ch);
 		}//For
 	}//For
t=11;
for(i=1;i<8;i++)
	for(j=3;j<=3;j++)
 	{
 	gotoxy(j*17+t,i+12);
  	if(tow[i-1][j-1]==0)
 		textcolor(15);
 	else
 		textcolor(tow[i-1][j-1]+1);
 	cprintf("%c",ch);
 	m=((tow[i-1][j-1]*2)/2);
 		for(n=0;n<m;n++)
 		{
 		gotoxy(j*17+t+n+1,i+12);
 		cprintf("%c",ch);
 		}//For
 		for(n=m;n>0;n--)
 		{
 		gotoxy(j*17+t-n,i+12);
 		cprintf("%c",ch);
 		}//For
   }//For
//------------------------------------------------------------------------------
gotoxy(80,25);
getch();
}//Print_hanoi
//==============================================================================
void main()
{
int m,i,p=6,j,l;
//------------------------------------------------------------------------------
clrscr();
cout<<"Please Enter Number Of Your Rings : ";
cin>>m;
if(m>7)m=7;
if(m<0)m=1;
for(i=m;i>=1;i--)
	{
	towers[p][0]=i;
	p--;
	}//For
towers[7][0]=7-m;
towers[7][1]=7;
towers[7][2]=7;
//------------------------------------------------------------------------------
hanoi(m,1,3,2);
//------------------------------------------------------------------------------
l=0;
//------------------------------------------------------------------------------
print_hanoi(towers);
//------------------------------------------------------------------------------
while(act[l][0]!=0)
	{
	towers[towers[7][act[l][1]-1]][act[l][1]-1]=0;
	towers[7][act[l][1]-1]++;
	towers[towers[7][act[l][2]-1]-1][act[l][2]-1]=act[l][0];
	towers[7][act[l][2]-1]--;
	l++;
	print_hanoi(towers);
	}//While
//------------------------------------------------------------------------------
gotoxy(22,3);
textcolor(12);
cprintf("It Is The End Of Hanoi Towers Program");
gotoxy(80,25);
getch();
//------------------------------------------------------------------------------
}//Main
