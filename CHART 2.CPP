#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
void main()
{
clrscr();
int td,n[21];
textcolor(15);
cprintf("Tedad Anaasor ra vare konid(0<Tedad<21):");
cin>>td;

while (td<0 || td>20)
{
	gotoxy(41,1);
	cprintf("         ");
	gotoxy(41,1);
	cin>>td;
}
gotoxy(1,2);
cprintf("Adaad nemoodar ra be tartib vared koind(0<adad<45):");
gotoxy(1,3);
int xLoc,yLoc=3;
for (int i=1;i<=td;i++)
{
  gotoxy(1,yLoc);
  textcolor(LIGHTBLUE);
  cout<<"n "<<i<<": ";
  xLoc=wherex();
  cin>>n[i];
  while(n[i]<0 || n[i]>45)
  {
    gotoxy(xLoc,yLoc);
    cprintf("         ");
    gotoxy(xLoc,yLoc);
    cin>>n[i];
  }
  yLoc++;
}
getch();
clrscr();
int x=1;
for (i=1;i<=td;i++)
{
   gotoxy(x,49);
   int k=48;
   textcolor(YELLOW);
   cprintf("%d",n[i]);
   textcolor(14);
   for (int j=1;j<=n[i];j++)
   {
	gotoxy(x,k--);
	delay(20);
	cprintf("Û");//219
   }
   x+=4;
}
getch();
}