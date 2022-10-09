#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
void main()
{
   clrscr();
   int i,y,x;
   char ch,ch2;
   long double a=0,b;
   char s1[10]={0},s2[10];
   int sw;
  textcolor(14);
  for (i=0,x=1;i<21;i++,x++)
  {
      gotoxy(x,1);
      putch(22);
      gotoxy(x,4);
      putch(22);
      gotoxy(x,8);
      putch(22);
      gotoxy(x,12);
      putch(22);
      gotoxy(x,16);
      putch(22);
      gotoxy(x,20);
      putch(22);
  }
  gotoxy(1,2);
  putch(254);
  gotoxy(1,3);
  putch(254);
  gotoxy(1,4);
  putch(254);
  gotoxy(20,2);
  putch(254);
  gotoxy(20,3);
  putch(254);
  gotoxy(20,4);
  putch(254);

  for (i=0,y=5;i<16;i++,y++)
  {
      gotoxy(1,y);
      putch(254);
      gotoxy(5,y);
      putch(254);
      gotoxy(10,y);
      putch(254);
      gotoxy(15,y);
      putch(254);
      gotoxy(20,y);
      putch(254);
  }

  gotoxy(17,6);
  cout<<"/";
  gotoxy(17,10);
  cout<<"*";
  gotoxy(17,14);
  cout<<"-";
  gotoxy(17,18);
  cout<<"+";
  gotoxy(12,18);
  cout<<"=";
  gotoxy(7,18);
  cout<<"0";
  gotoxy(2,18);
  cout<<".";
  gotoxy(2,6);
  cout<<"1";
  gotoxy(7,6);
  cout<<"2";
  gotoxy(12,6);
  cout<<"3";
  gotoxy(2,10);
  cout<<"4";
  gotoxy(7,10);
  cout<<"5";
  gotoxy(12,10);
  cout<<"6";
  gotoxy(2,14);
  cout<<"7";
  gotoxy(7,14);
  cout<<"8";
  gotoxy(12,14);
  cout<<"9";

      sw=0;
  while(1)
  {
     if (sw==0)
     {
     gotoxy(3,2);
     cout<<"                 ";
     gotoxy(3,2);
     gets(s1);
     a=atof(s1);
     sw=1;
     }
     gotoxy(3,2);
     cout<<"                 ";
     gotoxy(3,2);
     scanf("%c",&ch);
     gotoxy(3,2);
     cout<<"                 ";
     gotoxy(3,2);
     gets(s2);
     b=atof(s2);

     switch(ch)
     {
	case '+':
	a+=b;
	break;
	case '-':
	a-=b;
	break;
	case '*':
	a*=b;
	break;
	case '/':
	a/=b;
	break;
     }
     gotoxy(3,2);
     cout<<"                 ";
     gotoxy(3,2);
     cout<<a;

     ch2=getch();

     if(ch2==27)// 27: Esc ascii code
       exit(0);
       if (ch==13)
       sw=0;
  }
}//main