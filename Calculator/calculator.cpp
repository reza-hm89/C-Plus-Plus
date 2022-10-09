#include <math.h>
#include <dos.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define   ENTER 13
#define   BKSP  8
const int MAX=20;
const int ESC=27;
struct key{
int x;
int y;
char p;
};
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
struct key keys[]={
{31,11,'('},{36,11,')'},{41,11,'^'},{46,11,16},
{31,13,'7'},{36,13,'8'},{41,13,'9'},{46,13,'/'},
{31,15,'4'},{36,15,'5'},{41,15,'6'},{46,15,'*'},
{31,17,'1'},{36,17,'2'},{41,17,'3'},{46,17,'-'},
{31,19,'0'},{36,19,'.'},{41,19,'='},{46,19,'+'},
};
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int pr[]={17,0,16,12,13,14,8,9,10,4,5,6};
int getkey(void )
{
int key,low,high;
key=getch();
return (key) ?  key : getch()+256;
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void press(int i)
{
window(keys[i].x,keys[i].y,keys[i].x+3,keys[i].y);
textbackground(WHITE);
textcolor(1);
clrscr();
cprintf(" %c",keys[i].p);
sleep(0.025);
window(keys[i].x,keys[i].y,keys[i].x+3,keys[i].y);
textbackground(BLACK);
textcolor(WHITE);
clrscr();
cprintf(" %c",keys[i].p);
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void display(char *s)
{
int len=strlen(s);
window(31,8,49,9);
textbackground(WHITE);
textcolor(BLACK);
clrscr();
if (!len) len++;
gotoxy(19-len-1,2);
if (strlen(s)==0) cprintf("0.");
else if (!strchr(s,'.'))   cprintf("%s.",s);
else cprintf("%s ",s);
}
/******************************************************************/
void ftoa(char *s,double x)
{
sprintf(s,"%f",x);
int i=strlen(s)-1;
while(s[i]=='0') s[i--]=0;
if (s[i]=='.') s[i--]=0;
if (!x) strcpy(s,"");
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void calculater()
{
int ch,op=0;
double x=0,y=0,k=0;
char str[50]={0};
char str2[50]={0};
display(str);
/******************************************************************/
do {
ch=getkey();
switch (ch){
case '.':
case '0':
case '1':
case '2':
case '3':
case '4':
case '5':
case '6':
case '7':
case '8':
case '9':{
char st[]={ch,0};
press(pr[ch-'.']);
if(strlen(str) < 14 ){
if (ch!='.')
strcat(str,st);
else
if (!strchr(str,'.'))
strcat(str,st);
display(str);
}
}
break;
case  '+':
case  '-':
(ch=='+') ? press(19) : press(15);
if (!k){
x=atof(str);
strcpy(str2,str);
}else
switch(op){
case 1:x+=atof(str);
break;
case 2:x-=atof(str);
break;
case 3:x*=atof(str);
break;
case 4:x/=atof(str);
break;
        }
         ftoa(str,x);
        display(str);
    op = (ch=='+') ? 1 : 2;
  k=1;
       strcpy(str,"");
     break;
      case  '*':
      case  '/':
       (ch=='*') ? press(11) : press(7);
       if (!k){
      x=atof(str);
      strcpy(str2,str);
        }else
   switch(op){
     case 1:x+=atof(str);
     break;
     case 2:x-=atof(str);
     break;
     case 3:x*=atof(str);
     break;
     case 4:{double y;
      y=atof(str);
      if (y) x/=atof(str);
     }
break;
         }
        ftoa(str,x);
        display(str);
        op = (ch=='*') ? 3 : 4;
        k=1;
        strcpy(str,"");
       break;
/************************************************************/
case '(':{
double x;
press(0);
/*   x=atof(str);
   if(x>0) {
   x=sqrt(x);
   ftoa(str,x);
   display(str);
   }*/
}
break;
/************************************************************/
      case ')': {
   double x;
   press(1);
       // x=atof(str);
       // x*=-1;
       // ftoa(str,x);
       // display(str);
  }
   break;
/************************************************************/
      case '=':
      case ENTER:
  press(18);
  if (!op) x=atof(str);
   else if ( k )    y=atof(str);
        else y=atof(str2);
        switch(op){
   case 1: x+=y;
         break;
   case 2: x-=y;
        break;
   case 3: x*=y;
         break;
   case 4: x/=y;
         break;
        }
        ftoa(str,x);
        display(str);
        k=0;
       break;
/******************************************************************/
      case BKSP:{
   press(3);
   int i=strlen(str);
   if (i){
   str[i-1]=0;
   display(str);
         }
  }
        break;
/******************************************************************/
     case '^':
       press(2);
       op=0;
       x=0,y=0,k=0;
       strcpy(str,"");
       strcpy(str2,"");
       display(str);
     continue;
    }
   }while(ch!=ESC);
  }
/******************************************************************/
void menu4(void);
void meno1(void)
{ _setcursortype(_NOCURSOR);
  textbackground(1);
  clrscr();
  textbackground(0);
  window(7,6,19,10);
  clrscr();
  textbackground(19);
  textcolor(15);
  window(6,5,18,9);
  clrscr();
  gotoxy(1,2);cprintf(" Esc   :Exit  ");
  gotoxy(1,3);cprintf(" Enter :Result ");
  gotoxy(1,4);cprintf(" Bksp  :Undo   ");
  window(31,8,52,21);
  textbackground(0) ;
  clrscr();
  window(30,7,50,20);
  textbackground(19);
  clrscr();
  window(31,8,49,9);
  textbackground(7);
  textcolor(YELLOW);
  clrscr();
  _setcursortype(_NOCURSOR);
  for (int i=0 ; i<MAX ;i++){
  window(keys[i].x,keys[i].y,keys[i].x+3,keys[i].y);
  textbackground(0);
  textcolor(15);
  clrscr();
  cprintf(" %c",keys[i].p);
  }
  }
  void main()
  {
  int i;
  meno1();
  calculater();
  _setcursortype(_NORMALCURSOR);
  clrscr();
  } 
