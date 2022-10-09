#include <graphics.h>
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <string.h>
#include <fstream.h>
//////////////////////////
struct lessonpr{
char cod[10];
char prname[20];
char unit[10];
};
lessonpr pr[30];
int lp=0;
//////////////////////////
struct lessonch{
char chname[10][10];
char grade[10][10];
};
int lc=0;
/////////////////////////
struct student{
char name[20];
char family[20];
char faname[20];
char id[9];
char codem[11];
lessonch chname1;
};
student st[18];
int cntr=0;
///////////////////////
char op;
int x=0,y=0;
///////////////////////
void please()
   {
    char s[]={"Please Wait "};
    int c,t,j;
    for(c=10,t=0;s[t];gotoxy(c,15),delay(300),textcolor(14),putch(s[t]),c++,t++);
    for(c=25,j=0;j<30;gotoxy(c,15),delay(100),textcolor(1),cprintf("Ü"),c++,j++);
    for(c=25,j=0;j<30;gotoxy(c,15),delay(100),textcolor(15),cprintf("Ü"),c++,j++);
    for(c=25,j=0;j<30;gotoxy(c,15),delay(100),textcolor(4),cprintf("Ü"),c++,j++);
    for(c=25,j=0;j<30;gotoxy(c,15),delay(100),textcolor(2),cprintf("Ü"),c++,j++);
    }
//////////////////////////////
void file()
   {
     setfillstyle(1,1);	bar(4,41,205,135);
     setcolor(15); rectangle(8,45,200,130);
     setcolor(0);  outtextxy(25,55,"Input data student");setcolor(4);  outtextxy(25,55,"I");
     setcolor(0);  outtextxy(25,75,"Choose unit student");setcolor(4);  outtextxy(25,75,"C");
     setcolor(15); line(8,88,200,88);
     setcolor(0);  outtextxy(25,95,"Input grade lesson");setcolor(4);  outtextxy(25,95,"I");
     setcolor(15); line(8,108,200,108);
     setcolor(0);  outtextxy(25,115,"Exit :");setcolor(4);  outtextxy(25,115,"E");
     setcolor(0);  outtextxy(135,115,"Esc");setcolor(4);  outtextxy(135,115,"E");

     }
//////////////////////////////
void edit()
   {
    setfillstyle(1,1);	bar(55,41,305,235);
    setcolor(15); rectangle(58,45,300,230);
    setcolor(0);  outtextxy(70,55,"Modify student"); setcolor(4);  outtextxy(70,55,"M");
    setcolor(0);  outtextxy(70,75,"Delete one student");setcolor(4);  outtextxy(70,75,"D");
    setcolor(0);  outtextxy(70,95,"Delete more student");setcolor(4);  outtextxy(70,95,"D");
    setcolor(15); line(58,108,300,108);
    setcolor(0);  outtextxy(70,115,"Modify lesson choose student");setcolor(4);  outtextxy(70,115,"M");
    setcolor(0);  outtextxy(70,135,"Delete lesson choose student");setcolor(4);  outtextxy(70,135,"D");
    setcolor(15); line(58,148,300,148);
    setcolor(0);  outtextxy(70,155,"Modify lesson present term");setcolor(4);  outtextxy(70,155,"M");
    setcolor(0);  outtextxy(70,175,"Delete lesson present term");setcolor(4);  outtextxy(70,175,"D");
    setcolor(0);  outtextxy(70,195,"Added lesson present term");setcolor(4);  outtextxy(70,195,"A");
    setcolor(15); line(58,208,300,208);
    setcolor(0);  outtextxy(70,215,"Exit :"); setcolor(4);  outtextxy(70,215,"E");
    setcolor(0);  outtextxy(255,215,"Esc");setcolor(4);  outtextxy(255,215,"E");
    }
//////////////////////////////
void view()
   {
    setfillstyle(1,1);	bar(115,41,395,155);
    setcolor(15); rectangle(119,45,390,150);
    setcolor(0);  outtextxy(130,55,"Sort student by ID");setcolor(4); outtextxy(130,55,"S"); outtextxy(258,55,"ID");
    setcolor(0);  outtextxy(130,75,"Sort student by Family");setcolor(4);  outtextxy(130,75,"S");outtextxy(258,75,"F");
    setcolor(15); line(119,88,390,88);
    setcolor(0);  outtextxy(130,95,"Lesson peresent term");setcolor(4);  outtextxy(130,95,"L");
    setcolor(0);  outtextxy(130,115,"Lesson choose and grade student");setcolor(4);  outtextxy(130,115,"L");
    setcolor(15); line(119,128,390,128);
    setcolor(0);  outtextxy(130,135,"Exit :"); setcolor(4);  outtextxy(130,135,"E");
    setcolor(0);  outtextxy(350,135,"Esc");setcolor(4);  outtextxy(350,135,"E");
    }
//////////////////////////////
void search()
   {
    setfillstyle(1,1);	bar(175,41,295,115);
    setcolor(15); rectangle(178,45,290,110);
    setcolor(0); outtextxy(190,55,"By ID");setcolor(4);outtextxy(190,55,"B");outtextxy(214,55,"I");
    setcolor(0); outtextxy(190,75,"By Family");setcolor(4);outtextxy(190,75,"B");outtextxy(214,75,"F");
    setcolor(15); line(178,88,290,88);
    setcolor(0);  outtextxy(190,95,"Exit :"); setcolor(4);  outtextxy(190,95,"E");
    setcolor(0);  outtextxy(254,95,"Esc");setcolor(4);  outtextxy(254,95,"E");
    }
//////////////////////////////
void option()
   {
    setfillstyle(1,1);	bar(235,41,355,115);
    setcolor(15); rectangle(238,45,350,110);
    setcolor(0); outtextxy(250,55,"Time");setcolor(4);outtextxy(250,55,"T");
    setcolor(0); outtextxy(250,75,"Date");setcolor(4);outtextxy(250,75,"D");
    setcolor(15); line(238,88,350,88);
    setcolor(0);  outtextxy(250,95,"Exit :"); setcolor(4);  outtextxy(250,95,"E");
    setcolor(0);  outtextxy(304,95,"Esc");setcolor(4);  outtextxy(304,95,"E");
    }
///////////////////////////////
void p_wait()
   {
    int i,y=500;
    setfillstyle(1,7);	bar(3,455,616,476); setcolor(15); rectangle(3,455,616,476);  setcolor(15);  line(140,455,140,476);
    setcolor(4);  outtextxy(8,462,"Please Wait... ");
    setcolor(14);  rectangle(501,460,601,470);  rectangle(500,461,600,471);
    for(i=1;i<=20;setfillstyle(1,2),delay(300),bar(y,462,y+5,469),rectangle(y,462,y+5,469),y+=5,i++);
    delay(400);    setfillstyle(1,7);	bar(7,457,616,474);
    }
/////////////////////////////
void clear(){
    setfillstyle(1,7);	bar(3,18,616,40); setcolor(15);    rectangle(3,18,616,40);
    setcolor(0);   outtextxy(10,25,"File"); setcolor(4); outtextxy(10,25,"F");  outtextxy(10,30,"-");
    setcolor(0);   outtextxy(70,25,"Edit"); setcolor(4); outtextxy(70,25,"E");  outtextxy(70,30,"-");
    setcolor(0);   outtextxy(130,25,"View"); setcolor(4); outtextxy(130,25,"V"); outtextxy(130,30,"-");
    setcolor(0);   outtextxy(190,25,"Search"); setcolor(4); outtextxy(190,25,"S"); outtextxy(190,30,"-");
    setcolor(0);   outtextxy(250,25,"Option"); setcolor(4); outtextxy(250,25,"O"); outtextxy(250,30,"-");
    setfillstyle(1,2);	bar(4,41,610,420);
	  }
//////////////////////////
void clear1()
   {
    setfillstyle(1,7);	bar(3,455,616,476); setcolor(15); rectangle(3,455,616,476);  setcolor(15);  line(140,455,140,476);
    setcolor(0);   outtextxy(10,463,"Ctrl+S:"); setcolor(4); outtextxy(10,463,"C");
    setcolor(0);   outtextxy(70,463,"Activate"); setcolor(4); outtextxy(70,463,"A");
    setcolor(15);  line(140,455,140,476);
    setcolor(0);   outtextxy(150,463,"Exit:"); setcolor(4); outtextxy(150,463,"E");
    setcolor(0);   outtextxy(195,463,"Alt+x"); setcolor(4); outtextxy(195,463,"A");
    }
//////////////////////////////
void menu()
   {
    setbkcolor(0);
    setfillstyle(1,2);	bar3d(2,17,617,477,20,20);
    setcolor(2);  outtextxy(70 ,8,"  Ramezan     ***** ");
    setcolor(15);  outtextxy(270,8,"   Ali");
    setcolor(4);  outtextxy(370,8,"  *****      Valeh");
//  p_wait();
    clear();
    clear1();
	 }
////////////////////////////
void str(int a,char c[])
{
 int a1,a2;
 a1=a/10;
 a2=a-(a1*10);
 c[0]=48+a1;
 c[1]=48+a2;
 c[2]=':';
 }
//////////////////////////
void timer()
   {
    char c[8];
    struct time t;
    struct time t1;
    setcolor(4);
    gettime(&t);
    str(t.ti_hour,c);outtextxy(550,465,c);
    str(t.ti_min,c);outtextxy(575,465,c);
    str(t.ti_sec,c);c[2]=0;outtextxy(600,465,c);
while(!kbhit())
     {
      gettime(&t);  delay(50);
      gettime(&t1);
      if (t.ti_hour!=t1.ti_hour){ str(t.ti_hour,c);
	  setfillstyle(1,7); bar(550,460,560,470); outtextxy(550,465,c); }
      if (t.ti_min!=t1.ti_min){ str(t.ti_min,c);
	  setfillstyle(1,7); bar(575,460,585,470);outtextxy(575,465,c);  }
      if (t.ti_sec!=t1.ti_sec){ str(t.ti_sec,c);   c[2]=0;
	  setfillstyle(1,7); bar(600,460,615,470);outtextxy(600,465,c); }
      }//while
   setcolor(15);
  }
//////////////////////////////////
void date()
  {
    char c[8];
    struct date d;
    struct date d1;
    setcolor(4);
    getdate(&d);
    str(d.da_year,c);outtextxy(536,465,"2009/  /");
    str(d.da_day,c);outtextxy(575,465,c);
    str(d.da_mon,c);c[2]=0;outtextxy(600,465,c);
while(!kbhit())
     {
      getdate(&d);  delay(50);
      getdate(&d1);
      if (d.da_year!=d1.da_year){ str(d.da_year,"2009/  /");
	  setfillstyle(1,7); bar(550,460,560,470); outtextxy(536,465,"2009/  /"); }
      if (d.da_day!=d1.da_day){ str(d.da_day,c);
	  setfillstyle(1,7); bar(575,460,585,470);outtextxy(575,465,c);  }
      if (d.da_mon!=d1.da_mon){ str(d.da_mon,c);
	  setfillstyle(1,7); bar(600,460,615,470);outtextxy(600,465,c); }
      }//while
   setcolor(15);
  }

///////////////////////////
void inputst()
   {
    p_wait(); clear1();
 char ans='y';
while(ans=='y'||ans=='Y'){
    setfillstyle(1,9);bar(90,90,500,400);
    setcolor(15);rectangle(93,93,497,397);rectangle(95,95,495,395);
    setfillstyle(1,12);bar(110,110,220,130);setcolor(15);rectangle(110,110,220,130);
    setcolor(0);outtextxy(120,116,"Name:");setfillstyle(1,0);bar(230,110,490,130);setcolor(15);rectangle(230,110,490,130);
    setfillstyle(1,12);bar(110,140,220,160);setcolor(15);rectangle(110,140,220,160);
    setcolor(0);outtextxy(120,146,"Family:");setfillstyle(1,0);bar(230,140,490,160);setcolor(15);rectangle(230,140,490,160);
    setfillstyle(1,12);bar(110,174,220,195);setcolor(15);rectangle(110,174,220,195);
    setcolor(0);outtextxy(120,180,"Father Name:");setfillstyle(1,0);bar(230,174,490,195);setcolor(15);rectangle(230,174,490,195);
    setfillstyle(1,12);bar(110,204,220,225);setcolor(15);rectangle(110,204,220,225);
    setcolor(0);outtextxy(120,210,"ID:"); setfillstyle(1,0);bar(230,204,490,225);setcolor(15);rectangle(230,204,490,225);
    setfillstyle(1,12);bar(110,234,220,257);setcolor(15);rectangle(110,234,220,257);
    setcolor(0);outtextxy(120,242,"Code M:");setfillstyle(1,0);bar(230,234,490,257);setcolor(15);rectangle(230,234,490,257);
	 ////////////////

gotoxy(31,8);gets(st[cntr].name);setfillstyle(1,8);bar(230,110,490,130);rectangle(230,110,490,130);setcolor(15);outtextxy(240,117,st[cntr].name);
gotoxy(31,10);gets(st[cntr].family);setfillstyle(1,8);bar(230,140,490,160);setcolor(15);rectangle(230,140,490,160);setcolor(15);outtextxy(240,147,st[cntr].family);
gotoxy(31,12);gets(st[cntr].faname);setfillstyle(1,8);bar(230,174,490,195);setcolor(15);rectangle(230,174,490,195);setcolor(15);outtextxy(240,181,st[cntr].faname);
gotoxy(31,14);gets(st[cntr].id);setfillstyle(1,8);bar(230,204,490,225);setcolor(15);rectangle(230,204,490,225);setcolor(15);outtextxy(240,211,st[cntr].id);
gotoxy(31,16);gets(st[cntr].codem);setfillstyle(1,8);bar(230,234,490,257);setcolor(15);rectangle(230,234,490,257);setcolor(15);outtextxy(240,241,st[cntr].codem);
cntr++;
    /////
    while(!kbhit()){
    setfillstyle(1,0);bar(110,270,490,290);
    delay(600);
    setcolor(4);outtextxy(210,277,"C  O  N  T  I  N  U  E");setcolor(15);rectangle(110,270,490,290);
    delay(600);
    setfillstyle(1,0);bar(120,327,230,347);setcolor(15);rectangle(120,327,230,347);
    setcolor(15);outtextxy(140,335,"Y   E   S");setcolor(4);outtextxy(140,335,"Y");
    setfillstyle(1,0);bar(370,327,480,347);setcolor(15);rectangle(370,327,480,347);
    setcolor(15);outtextxy(390,333,"  N    O ");setcolor(4);outtextxy(390,333,"  N");
    }//while
ans=getch();
    }//while1
}
//////////////////////////
void gvsortbyid(){
    setfillstyle(1,9);bar(50,50,540,400);
    setcolor(15);rectangle(53,53,537,397);rectangle(55,55,535,395);
      setfillstyle(1,12);bar(60,60,140,80);setcolor(15);rectangle(60,60,140,80);
    setcolor(0);outtextxy(90,67,"ID");
	setfillstyle(1,12);bar(150,60,230,80);setcolor(15);rectangle(150,60,230,80);
    setcolor(0);outtextxy(170,67,"Name");
	setfillstyle(1,12);bar(240,60,330,80);setcolor(15);rectangle(240,60,330,80);
    setcolor(0);outtextxy(260,67,"Family");
	setfillstyle(1,12);bar(340,60,440,80);setcolor(15);rectangle(340,60,440,80);
    setcolor(0);outtextxy(350,67,"Code M");
	setfillstyle(1,12);bar(450,60,530,80);setcolor(15);rectangle(450,60,530,80);
    setcolor(0);outtextxy(460,67,"F.Name");
}
////////////////////////
void gvsortbyf(){
    setfillstyle(1,9);bar(50,50,540,400);
    setcolor(15);rectangle(53,53,537,397);rectangle(55,55,535,395);
      setfillstyle(1,12);bar(60,60,140,80);setcolor(15);rectangle(60,60,140,80);
    setcolor(0);outtextxy(70,67,"Family");
	setfillstyle(1,12);bar(150,60,230,80);setcolor(15);rectangle(150,60,230,80);
    setcolor(0);outtextxy(170,67,"Name");
	setfillstyle(1,12);bar(240,60,330,80);setcolor(15);rectangle(240,60,330,80);
    setcolor(0);outtextxy(275,67,"ID");
	setfillstyle(1,12);bar(340,60,440,80);setcolor(15);rectangle(340,60,440,80);
    setcolor(0);outtextxy(350,67,"Code M");
	setfillstyle(1,12);bar(450,60,530,80);setcolor(15);rectangle(450,60,530,80);
    setcolor(0);outtextxy(460,67,"F.Name");
}
//////////////////////
void gsbyid(){
    setfillstyle(1,9);bar(90,90,500,400);
    setcolor(15);rectangle(93,93,497,397);rectangle(95,95,495,395);
    setfillstyle(1,12);bar(110,110,220,130);setcolor(15);rectangle(110,110,220,130);
    setcolor(0);outtextxy(120,116,"Name:");setfillstyle(1,0);bar(230,110,490,130);setcolor(15);rectangle(230,110,490,130);
    setfillstyle(1,12);bar(110,140,220,160);setcolor(15);rectangle(110,140,220,160);
    setcolor(0);outtextxy(120,146,"Family:");setfillstyle(1,0);bar(230,140,490,160);setcolor(15);rectangle(230,140,490,160);
    setfillstyle(1,12);bar(110,174,220,195);setcolor(15);rectangle(110,174,220,195);
    setcolor(0);outtextxy(120,180,"Father Name:");setfillstyle(1,0);bar(230,174,490,195);setcolor(15);rectangle(230,174,490,195);
    setfillstyle(1,12);bar(110,204,220,225);setcolor(15);rectangle(110,204,220,225);
    setcolor(0);outtextxy(120,210,"ID:"); setfillstyle(1,0);bar(230,204,490,225);setcolor(15);rectangle(230,204,490,225);
    setfillstyle(1,12);bar(110,234,220,257);setcolor(15);rectangle(110,234,220,257);
    setcolor(0);outtextxy(120,242,"Code M:");setfillstyle(1,0);bar(230,234,490,257);setcolor(15);rectangle(230,234,490,257);
}
/////////////////////
void del(){
    setfillstyle(1,5);bar(185,175,360,260);setcolor(15);
    rectangle(187,177,358,258);rectangle(189,179,356,256);outtextxy(210,210,"DELETED");
}
/////////////////////
void empty(){
    setfillstyle(1,5);bar(185,175,360,260);setcolor(15);
    rectangle(187,177,358,258);rectangle(189,179,356,256);outtextxy(210,210,"list is empty");
}
/////////////////////////
void notf(){
    setfillstyle(1,5);bar(185,175,360,260);setcolor(15);
    rectangle(187,177,358,258);rectangle(189,179,356,256);outtextxy(210,210,"NOT FOUND !!!");
}
/////////////////////////
void box(){
int i,x1=60,x2=140,y1=90,y2=110;
for(i=0,x1=60,y1=85,x2=530,y2=105;i<cntr;y1+=25,y2+=25,i++) {
setfillstyle(1,0);bar(x1,y1,x2,y2);setcolor(15);rectangle(x1,y1,x2,y2);  }
}
/////////////////////
void namayesh(){
int i,x3=70,y3=93;
for(i=0,y3=93;i<cntr;y3+=25,i++)
{
outtextxy(x3,y3,st[i].id);
outtextxy(x3+90,y3,st[i].name);
outtextxy(x3+180,y3,st[i].family);
outtextxy(x3+280,y3,st[i].codem);
outtextxy(x3+390,y3,st[i].faname);
delay(400);
}
}
//////////////////////////
void namayesh1(){
int i;
setfillstyle(1,8);bar(230,110,490,130);rectangle(230,110,490,130);setcolor(15);outtextxy(240,117,st[i].name);
setfillstyle(1,8);bar(230,140,490,160);setcolor(15);rectangle(230,140,490,160);setcolor(15);outtextxy(240,147,st[i].family);
setfillstyle(1,8);bar(230,174,490,195);setcolor(15);rectangle(230,174,490,195);setcolor(15);outtextxy(240,181,st[i].faname);
setfillstyle(1,8);bar(230,204,490,225);setcolor(15);rectangle(230,204,490,225);setcolor(15);outtextxy(240,211,st[i].id);
setfillstyle(1,8);bar(230,234,490,257);setcolor(15);rectangle(230,234,490,257);setcolor(15);outtextxy(240,241,st[i].codem);
}
/////////////////////////
void vsortbyid(){
int i,j,t;
student help;
 if(!cntr)
   {
    gvsortbyid();
    empty();
    getch();
    return;
    }//end
 for(i=cntr-1;i>0;i--)
    for(j=0;j<i;j++)
       if(strcmp(st[j].id,st[j+1].id)>0)
	 {
	  help=st[j];
	  st[j]=st[j+1];
	  st[j+1]=help;
	  }//endif
gvsortbyid();
box();
namayesh();
getch();
}
//////////////////////////
void vsortbyfamily(){
int i,j,t;
student help;
 if(!cntr)
   {
    gvsortbyf();
    empty();
    getch();
    return;
    }//end if
 for(i=cntr-1;i>0;i--)
    for(j=0;j<i;j++)
       if(strcmp(st[j].family,st[j+1].family)>0)
	 {
	  help=st[j];
	  st[j]=st[j+1];
	  st[j+1]=help;
	   }//endif
gvsortbyf();
box();
int x3=70,y3=93;
for(i=0,y3=93;i<cntr;y3+=25,i++)
{
outtextxy(x3,y3,st[i].family);
outtextxy(x3+90,y3,st[i].name);
outtextxy(x3+180,y3,st[i].id);
outtextxy(x3+280,y3,st[i].codem);
outtextxy(x3+390,y3,st[i].faname);
delay(400);
}
getch();
}
///////////////////////////
void searchbyid()
{
 int i,j,sw=0;
 char num[10];
 if(!cntr)
   {
    gvsortbyid();
    empty();
    getch();
    return;
    }//end if
    setfillstyle(1,12);bar(110,204,220,225);setcolor(15);rectangle(110,204,220,225);
    setcolor(0);outtextxy(120,210,"ID:"); setfillstyle(1,0);bar(230,204,490,225);setcolor(15);rectangle(230,204,490,225);
    gotoxy(31,14);gets(num);setfillstyle(1,8);bar(230,204,490,225);setcolor(15);rectangle(230,204,490,225);setcolor(15);outtextxy(240,211,num);
 for(i=0;i<cntr && !sw;i++)
   if(strcmp(st[i].id,num)==0)
       sw=1;
 if(sw)
   {
    gsbyid();
    i--;
    namayesh1();
    }//end if
 else {gvsortbyid(); notf();}
 getch();
 }
/////////////////////////////
void searchbyfamily()
{
 int i,j,sw=0;
 char num[20];
 if(!cntr)
   {
    gvsortbyf();
    empty();
    getch();
    return;
    }//end if
    setfillstyle(1,12);bar(110,140,220,160);setcolor(15);rectangle(110,140,220,160);
    setcolor(0);outtextxy(120,146,"Family:");setfillstyle(1,0);bar(230,140,490,160);setcolor(15);rectangle(230,140,490,160);
 gotoxy(31,10);gets(num);setfillstyle(1,8);bar(230,140,490,160);setcolor(15);rectangle(230,140,490,160);setcolor(15);outtextxy(240,147,num);
 for(i=0;i<cntr&&!sw;i++)
    if(strcmp(st[i].family,num)==0)
	 sw=1;
   if(sw)
   {
    gsbyid();
    i--;
    namayesh1();
    }//end if
 else {gvsortbyf(); notf();}
 getch();
 }
//////////////////////////
 void deletebyid()
{
 int i,j,sw=0;
 char num[10];
 if(!cntr)
   {
    gvsortbyid();
    empty();
    getch();
    return;
    }//end if
    setfillstyle(1,12);bar(110,204,220,225);setcolor(15);rectangle(110,204,220,225);
    setcolor(0);outtextxy(120,210,"ID:"); setfillstyle(1,0);bar(230,204,490,225);setcolor(15);rectangle(230,204,490,225);
    gotoxy(31,14);gets(num);setfillstyle(1,8);bar(230,204,490,225);setcolor(15);rectangle(230,204,490,225);setcolor(15);outtextxy(240,211,num);
 for(i=0;i<cntr && !sw;i++)
    if(strcmp(st[i].id,num)==0)
       sw=1;
 if(sw)
   {
    for(j=i-1;j<cntr;j++)
       st[j]=st[j+1];
    cntr--;
     gvsortbyid();
     del();
    }//end if
  else{gvsortbyid(); notf();}
 getch();
 }
//////////////////////////
 void deletebytid()
{
 int i,j,sw=0,t,k;
 char num[10];
 if(!cntr)
   {
    gvsortbyid();
    empty();
    getch();
    return;
    }//end if
    setfillstyle(1,12);bar(110,204,220,225);setcolor(15);rectangle(110,204,220,225);
    setcolor(0);outtextxy(120,210,"Tedad:"); setfillstyle(1,0);bar(230,204,490,225);setcolor(15);rectangle(230,204,490,225);
    gotoxy(31,14);cin>>t;setfillstyle(1,8);bar(230,204,490,225);setcolor(15);rectangle(230,204,490,225);//setcolor(15);outtextxy(240,211,t);
 if(t<=cntr)
 for(k=1;k<=t;k++){
    setfillstyle(1,12);bar(110,204,220,225);setcolor(15);rectangle(110,204,220,225);
    setcolor(0);outtextxy(120,210,"ID:"); setfillstyle(1,0);bar(230,204,490,225);setcolor(15);rectangle(230,204,490,225);
    gotoxy(31,14);gets(num);setfillstyle(1,8);bar(230,204,490,225);setcolor(15);rectangle(230,204,490,225);setcolor(15);outtextxy(240,211,num);
 for(i=0;i<cntr && !sw;i++)
    if(strcmp(st[i].id,num)==0)
       sw=1;
 if(sw)
   {
    for(j=i-1;j<cntr;j++)
       st[j]=st[j+1];
    cntr--;
     gvsortbyid();
     del();
     getch();
    }//end if
  else {gvsortbyid(); notf();getch();}

 }//for1
 else {gvsortbyid();
    setfillstyle(1,5);bar(185,175,360,260);setcolor(15);
    rectangle(187,177,358,258);rectangle(189,179,356,256);outtextxy(210,210,"Bishtar Az Tedad..");
     }
 getch();
 }
////////////////////////////
void editst()
 {
  int i,j,sw=0;
  char num[20];
  if(!cntr)
   {
    gvsortbyid();
    empty();
    getch();
    return;
    }//end if
    setfillstyle(1,12);bar(110,204,220,225);setcolor(15);rectangle(110,204,220,225);
    setcolor(0);outtextxy(120,210,"ID:"); setfillstyle(1,0);bar(230,204,490,225);setcolor(15);rectangle(230,204,490,225);
    gotoxy(31,14);gets(num);setfillstyle(1,8);bar(230,204,490,225);setcolor(15);rectangle(230,204,490,225);setcolor(15);outtextxy(240,211,num);

  for(i=0;i<cntr && !sw;i++)
  if(strcmp(st[i].id,num)==0)
       sw=1;
  if(sw)
   {
    gsbyid();
    i--;
    namayesh1();
    getch();
strcpy(st[cntr].id,num);
gotoxy(31,8);gets(st[cntr].name);setfillstyle(1,8);bar(230,110,490,130);rectangle(230,110,490,130);setcolor(15);outtextxy(240,117,st[cntr].name);
gotoxy(31,10);gets(st[cntr].family);setfillstyle(1,8);bar(230,140,490,160);setcolor(15);rectangle(230,140,490,160);setcolor(15);outtextxy(240,147,st[cntr].family);
gotoxy(31,12);gets(st[cntr].faname);setfillstyle(1,8);bar(230,174,490,195);setcolor(15);rectangle(230,174,490,195);setcolor(15);outtextxy(240,181,st[cntr].faname);
//gotoxy(31,14);gets(st[cntr].id);setfillstyle(1,8);bar(230,204,490,225);setcolor(15);rectangle(230,204,490,225);setcolor(15);outtextxy(240,211,st[cntr].id);
gotoxy(31,16);gets(st[cntr].codem);setfillstyle(1,8);bar(230,234,490,257);setcolor(15);rectangle(230,234,490,257);setcolor(15);outtextxy(240,241,st[cntr].codem);
    st[i++]=st[cntr];
    gvsortbyid();
    setfillstyle(1,5);bar(185,175,360,260);setcolor(15);
    rectangle(187,177,358,258);rectangle(189,179,356,256);outtextxy(210,210,"EDit and Saved");
    }//end if
  else {gvsortbyid();notf();}
  getch();
  }
///////////////////////////////dorus erae shodeh////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void ogrpr(){
    setfillstyle(1,9);bar(90,90,500,400);
    setcolor(15);rectangle(93,93,497,397);rectangle(95,95,495,395);
    setfillstyle(1,12);bar(110,110,220,130);setcolor(15);rectangle(110,110,220,130);
    setcolor(0);outtextxy(120,116,"Code:");setfillstyle(1,0);bar(230,110,490,130);setcolor(15);rectangle(230,110,490,130);
    setfillstyle(1,12);bar(110,140,220,160);setcolor(15);rectangle(110,140,220,160);
    setcolor(0);outtextxy(120,146,"Pr.Lesson:");setfillstyle(1,0);bar(230,140,490,160);setcolor(15);rectangle(230,140,490,160);
    setfillstyle(1,12);bar(110,174,220,195);setcolor(15);rectangle(110,174,220,195);
    setcolor(0);outtextxy(120,180,"UNIT:");setfillstyle(1,0);bar(230,174,490,195);setcolor(15);rectangle(230,174,490,195);
}
////////////////////////
void agrpr(){
    setfillstyle(1,9);bar(50,50,340,400);
    setcolor(15);rectangle(53,53,337,397);rectangle(55,55,335,395);
      setfillstyle(1,12);bar(60,60,140,80);setcolor(15);rectangle(60,60,140,80);
    setcolor(0);outtextxy(70,67,"CODE");
	setfillstyle(1,12);bar(150,60,230,80);setcolor(15);rectangle(150,60,230,80);
    setcolor(0);outtextxy(165,67,"Lesson");
	setfillstyle(1,12);bar(240,60,330,80);setcolor(15);rectangle(240,60,330,80);
    setcolor(0);outtextxy(265,67,"unit");
}
////////////////////////
void addedpr()
   {
    int i,sw=0;
    char num[10];
    char ans='y';
      /* p_wait();*/
while(ans=='y'||ans=='Y'){
ogrpr();
gotoxy(31,8);gets(num);setfillstyle(1,8);bar(230,110,490,130);rectangle(230,110,490,130);setcolor(15);outtextxy(240,117,num);
    sw=0;
    for(i=0;i<lp && !sw;i++)
    if(strcmp(pr[i].cod,num)==0)
	  sw=1;
  if(sw==1){
    setfillstyle(1,5);bar(185,175,360,260);setcolor(15);
    rectangle(187,177,358,258);rectangle(189,179,356,256);outtextxy(210,210,"There is a Code");break; }
  else{
       strcpy(pr[lp].cod,num);
gotoxy(31,10);gets(pr[lp].prname);setfillstyle(1,8);bar(230,140,490,160);setcolor(15);rectangle(230,140,490,160);setcolor(15);outtextxy(240,147,pr[lp].prname);
gotoxy(31,12);gets(pr[lp].unit);setfillstyle(1,8);bar(230,174,490,195);setcolor(15);rectangle(230,174,490,195);setcolor(15);outtextxy(240,181,pr[lp].unit);
lp++;
      }//else
while(!kbhit()){
    setfillstyle(1,0);bar(110,270,490,290);
    delay(600);
    setcolor(4);outtextxy(210,277,"C  O  N  T  I  N  U  E");setcolor(15);rectangle(110,270,490,290);
    delay(600);
    setfillstyle(1,0);bar(120,327,230,347);setcolor(15);rectangle(120,327,230,347);
    setcolor(15);outtextxy(140,335,"Y   E   S");setcolor(4);outtextxy(140,335,"Y");
    setfillstyle(1,0);bar(370,327,480,347);setcolor(15);rectangle(370,327,480,347);
    setcolor(15);outtextxy(390,333,"  N    O ");setcolor(4);outtextxy(390,333,"  N");
    }//while
ans=getch();
    }//while1
}
/////////////////////
void outlpr(){
int i;
if(!lp)
   {
    empty();
    getch();
    return;
    }//end if
int x1=60,x2=140,y1=90,y2=110;
agrpr();
for(i=0,x1=60,y1=85,x2=330,y2=105;i<lp;y1+=25,y2+=25,i++) {
     setfillstyle(1,0);bar(x1,y1,x2,y2);setcolor(15);rectangle(x1,y1,x2,y2);}
int x3=70,y3=93;
for(i=0,y3=93;i<lp;y3+=25,i++)
{
outtextxy(x3,y3,pr[i].cod);
outtextxy(x3+90,y3,pr[i].prname);
outtextxy(x3+180,y3,pr[i].unit);
delay(400);
}
}
/////////////////////////
void editpr(){
  int i,j,sw=0;
  char num[20];
  if(!lp)
   {
    empty();
    getch();
    return;
    }//end if
    setfillstyle(1,12);bar(110,140,220,160);setcolor(15);rectangle(110,140,220,160);
    setcolor(0);outtextxy(120,146,"Pr.Lesson:");setfillstyle(1,0);bar(230,140,490,160);setcolor(15);rectangle(230,140,490,160);
gotoxy(31,10);gets(num);setfillstyle(1,8);bar(230,140,490,160);setcolor(15);rectangle(230,140,490,160);setcolor(15);outtextxy(240,147,num);

for(i=0;i<lp && !sw;i++)
  if(strstr(pr[i].prname,num))
       sw=1;
  if(!sw){ notf();return;}
  else
   {
   ogrpr();
    i--;
setfillstyle(1,8);bar(230,110,490,130);rectangle(230,110,490,130);setcolor(15);outtextxy(240,117,pr[i].cod);
setfillstyle(1,8);bar(230,140,490,160);setcolor(15);rectangle(230,140,490,160);setcolor(15);outtextxy(240,147,pr[i].prname);
setfillstyle(1,8);bar(230,174,490,195);setcolor(15);rectangle(230,174,490,195);setcolor(15);outtextxy(240,181,pr[i].unit);
getch();
gotoxy(31,8);gets(pr[lp].cod);setfillstyle(1,8);bar(230,110,490,130);rectangle(230,110,490,130);setcolor(15);outtextxy(240,117,pr[lp].cod);
gotoxy(31,10);gets(pr[lp].prname);setfillstyle(1,8);bar(230,140,490,160);setcolor(15);rectangle(230,140,490,160);setcolor(15);outtextxy(240,147,pr[lp].prname);
gotoxy(31,12);gets(pr[lp].unit);setfillstyle(1,8);bar(230,174,490,195);setcolor(15);rectangle(230,174,490,195);setcolor(15);outtextxy(240,181,pr[lp].unit);
    pr[i++]=pr[lp];
    setfillstyle(1,5);bar(185,175,360,260);setcolor(15);
    rectangle(187,177,358,258);rectangle(189,179,356,256);outtextxy(210,210,"EDit and Saved");
    getch();
    }//end if
}
//////////////////////////
void delepr(){
 int i,j,sw=0;
char num[10];
  if(!lp)
   {
    empty();
    getch();
    return;
    }//end if
    setfillstyle(1,12);bar(110,110,220,130);setcolor(15);rectangle(110,110,220,130);
    setcolor(0);outtextxy(120,116,"Code:");setfillstyle(1,0);bar(230,110,490,130);setcolor(15);rectangle(230,110,490,130);
gotoxy(31,8);gets(num);setfillstyle(1,8);bar(230,110,490,130);rectangle(230,110,490,130);setcolor(15);outtextxy(240,117,num);

////////////////////////////
 for(i=0;i<lp && !sw;i++)
    if(strcmp(pr[i].cod,num)==0)
       sw=1;
 if(!sw) { notf();getch();return;}
 else
   {
    for(j=i-1;j<lp;j++)
       pr[j]=pr[j+1];
    lp--;
    del();
    getch();
    }//end if

}
///////////////////////choose unit////////////////////////////////
void inputlch(){
char ans='y';
int i,j,t,sw=0;
char num1[10];
char num2[]={"NULL"};
char num[10];
if(!lp)
   {
    setfillstyle(1,5);bar(100,100,520,140);setcolor(15);rectangle(102,102,518,138);rectangle(104,104,516,136);
    outtextxy(120,117,"zaman entekhab vahed shoma fara nareside ast !!!");
    getch();
    return;
    }//end if
if(!cntr)
   {
    empty();
    getch();
    return;
    }//end if
    setfillstyle(1,12);bar(110,204,220,225);setcolor(15);rectangle(110,204,220,225);
    setcolor(0);outtextxy(120,210,"ID:"); setfillstyle(1,0);bar(230,204,490,225);setcolor(15);rectangle(230,204,490,225);
    gotoxy(31,14);gets(num1);setfillstyle(1,8);bar(230,204,490,225);setcolor(15);rectangle(230,204,490,225);setcolor(15);outtextxy(240,211,num1);
    clear();
  for(i=0;i<cntr && !sw;i++)
    if(strcmp(st[i].id,num1)==0)
	  sw=1;
	  i--;
  if(sw==0){
	setfillstyle(1,5);bar(185,175,360,260);setcolor(15);
    rectangle(187,177,358,258);rectangle(189,179,356,256);outtextxy(210,210,"NOT EXIST");getch();  return; }
else {
int x1=60,x2=140,y1=90,y2=110;

     setfillstyle(1,9);bar(20,50,310,400);
    setcolor(15);rectangle(23,53,307,397);rectangle(25,55,305,395);
      setfillstyle(1,12);bar(30,60,110,80);setcolor(15);rectangle(30,60,110,80);
    setcolor(0);outtextxy(40,67,"CODE");
	setfillstyle(1,12);bar(120,60,200,80);setcolor(15);rectangle(120,60,200,80);
    setcolor(0);outtextxy(135,67,"Lesson");
	setfillstyle(1,12);bar(210,60,300,80);setcolor(15);rectangle(210,60,300,80);
    setcolor(0);outtextxy(225,67,"unit");

for(j=0,x1=30,y1=85,x2=300,y2=105;j<lp;y1+=25,y2+=25,j++) {
     setfillstyle(1,0);bar(x1,y1,x2,y2);setcolor(15);rectangle(x1,y1,x2,y2);}
int x3=40,y3=93;
for(j=0,y3=93;j<lp;y3+=25,j++)
{
outtextxy(x3,y3,pr[j].cod);
outtextxy(x3+90,y3,pr[j].prname);
outtextxy(x3+180,y3,pr[j].unit);
delay(400);
}
getch();
///////////////////////////////
while(ans=='y'||ans=='Y'){
    setfillstyle(1,9);bar(320,50,500,400);
    setcolor(15);rectangle(323,53,497,397);rectangle(325,55,495,395);
	 setfillstyle(1,12);bar(330,60,490,80);setcolor(15);rectangle(330,60,490,80);
    setcolor(0);outtextxy(385,67,"Code");
    setfillstyle(1,0);bar(330,90,490,120);rectangle(330,90,490,120);
gotoxy(45,7);gets(num);setfillstyle(1,8);bar(330,90,490,120);rectangle(330,90,490,120);setcolor(15);outtextxy(350,100,num);

sw=0;
for(t=0;t<lp && !sw;t++)
  if(strcmp(pr[t].cod,num)==0)
       sw=1;
if(sw==0){  	setfillstyle(1,5);bar(340,175,490,260);setcolor(15);
rectangle(343,177,487,258);rectangle(345,179,485,256);outtextxy(370,200,"NOT EXIST");getch();  }
else{
     t--;
     strcpy(st[i].chname1.chname[lc],/*pr[t].prname*/num);
     strcpy(st[i].chname1.grade[lc],num2);
     lc++;
    setfillstyle(1,5);bar(340,175,490,260);setcolor(15);
rectangle(343,177,487,258);rectangle(345,179,485,256);outtextxy(365,200,"Lesson Choose");getch();
     }
while(!kbhit()){
    setfillstyle(1,0);bar(330,270,490,290);
    delay(600);
    setcolor(4);outtextxy(340,277,"CONTINUE");setcolor(15);rectangle(330,270,490,290);
    delay(600);
    setfillstyle(1,0);bar(330,310,490,330);setcolor(15);rectangle(330,310,490,330);
    setcolor(15);outtextxy(345,315,"Y  E  S");setcolor(4);outtextxy(345,315,"Y");
    setfillstyle(1,0);bar(330,340,490,360);setcolor(15);rectangle(330,340,490,360);
    setcolor(15);outtextxy(345,345," N   O ");setcolor(4);outtextxy(345,345," N");
    }//while
ans=getch();
}//while
}//else
}
//////////////////////////
void outlch(){
int num,i,j,t,c;
 if(!cntr)
   {
    empty();
    getch();
    return;
    }//end if
    setfillstyle(1,9);bar(50,50,540,400);
    setcolor(15);rectangle(53,53,537,397);rectangle(55,55,535,395);
      setfillstyle(1,12);bar(60,60,140,80);setcolor(15);rectangle(60,60,140,80);
    setcolor(0);outtextxy(70,67,"Family");
	setfillstyle(1,12);bar(150,60,230,80);setcolor(15);rectangle(150,60,230,80);
    setcolor(0);outtextxy(170,67,"Name");
	setfillstyle(1,12);bar(240,60,330,80);setcolor(15);rectangle(240,60,330,80);
    setcolor(0);outtextxy(275,67,"ID");
	setfillstyle(1,12);bar(340,60,440,80);setcolor(15);rectangle(340,60,440,80);
    setcolor(0);outtextxy(350,67,"Choose Le..");
	/*setfillstyle(1,12);bar(450,60,530,80);setcolor(15);rectangle(450,60,530,80);
    setcolor(0);outtextxy(460,67,"F.Name");*/
 box();
//////////////
int x3=70,y3=93,x4=70;
for(i=0,y3=93;i<cntr;y3+=25,i++)
{
outtextxy(x3,y3,st[i].family);
outtextxy(x3+90,y3,st[i].name);
outtextxy(x3+180,y3,st[i].id);

for(t=0,x4=70;t<lc;x4+=50,t++){outtextxy(x4+280,y3,st[i].chname1.chname[t]);}
//outtextxy(x3+390,y3,st[i].chname1.chname[t]);
delay(400);
}
getch();
}
//////////////////////////
void delelch(){
int i,j,t,sw=0;
char num1[10];
char num[10];
if(!lc)
   {
    setfillstyle(1,5);bar(100,100,520,140);setcolor(15);rectangle(102,102,518,138);rectangle(104,104,516,136);
    outtextxy(120,117,"zaman entekhab vahed shoma fara nareside ast !!!");
    getch();
    return;
    }//end if
if(!cntr)
   {
    empty();
    getch();
    return;
    }//end if
    setfillstyle(1,12);bar(110,204,220,225);setcolor(15);rectangle(110,204,220,225);
    setcolor(0);outtextxy(120,210,"ID:"); setfillstyle(1,0);bar(230,204,490,225);setcolor(15);rectangle(230,204,490,225);
    gotoxy(31,14);gets(num1);setfillstyle(1,8);bar(230,204,490,225);setcolor(15);rectangle(230,204,490,225);setcolor(15);outtextxy(240,211,num1);
  for(i=0;i<cntr && !sw;i++)
    if(strcmp(st[i].id,num1)==0)
	  sw=1;
  if(sw==0){
	setfillstyle(1,5);bar(340,175,490,260);setcolor(15);
rectangle(343,177,487,258);rectangle(345,179,485,256);outtextxy(370,200,"NOT EXIST");getch();   return; }
else{
     i--;
    setfillstyle(1,9);bar(50,50,540,400);
    setcolor(15);rectangle(53,53,537,397);rectangle(55,55,535,395);
      setfillstyle(1,12);bar(60,60,140,80);setcolor(15);rectangle(60,60,140,80);
    setcolor(0);outtextxy(70,67,"ID");
	setfillstyle(1,12);bar(150,60,230,80);setcolor(15);rectangle(150,60,230,80);
    setcolor(0);outtextxy(170,67,"Choose Le..");
	box();
//////////////
int x3=70,y3=93,x4=70;
for(j=0,y3=93;j<cntr;y3+=25,j++)
{
outtextxy(x3,y3,st[j].id);
for(t=0,x4=70;t<lc;x4+=50,t++){outtextxy(x4+90,y3,st[j].chname1.chname[t]);}
delay(400);
}
getch();
///////////////////////////////
    setfillstyle(1,9);bar(320,50,500,400);
    setcolor(15);rectangle(323,53,497,397);rectangle(325,55,495,395);
	 setfillstyle(1,12);bar(330,60,490,80);setcolor(15);rectangle(330,60,490,80);
    setcolor(0);outtextxy(385,67,"chname");
    setfillstyle(1,0);bar(330,90,490,120);rectangle(330,90,490,120);
gotoxy(45,7);gets(num);setfillstyle(1,8);bar(330,90,490,120);rectangle(330,90,490,120);setcolor(15);outtextxy(350,100,num);

sw=0;
for(t=0;t<lc && !sw;t++)
   if(strcmp(st[i].chname1.chname[t],num)==0);
      sw=1;
if(sw==0) {
	setfillstyle(1,5);bar(340,175,490,260);setcolor(15);
rectangle(343,177,487,258);rectangle(345,179,485,256);outtextxy(370,200,"NOT EXIST");getch();   return; }
else{
     t--;
     strcpy(st[i].chname1.chname[t],st[i].chname1.chname[t+1]);
	setfillstyle(1,5);bar(340,175,490,260);setcolor(15);
rectangle(343,177,487,258);rectangle(345,179,485,256);outtextxy(370,200,"Lesson Deleted");getch();   return;
     }
     }//else
}
//////////////////////////
void ingrade(){
char num[10];
char ans='y';
int sw,sw1,sw2,h,i,t,j,k=0,p;
char nomreh[6];
if(!lc)
   {
    setfillstyle(1,5);bar(340,175,490,260);setcolor(15);
rectangle(343,177,487,258);rectangle(345,179,485,256);outtextxy(350,200,"darsi entekhab nashodeh ast");
   getch();
    return;
    }//end if
    setfillstyle(1,9);bar(320,50,500,400);
    setcolor(15);rectangle(323,53,497,397);rectangle(325,55,495,395);
	 setfillstyle(1,12);bar(330,60,490,80);setcolor(15);rectangle(330,60,490,80);
    setcolor(0);outtextxy(375,67,"lesson name");
    setfillstyle(1,0);bar(330,90,490,120);rectangle(330,90,490,120);
gotoxy(45,7);gets(num);setfillstyle(1,8);bar(330,90,490,120);rectangle(330,90,490,120);setcolor(15);outtextxy(350,100,num);
i=-1;
while(ans=='y'||ans=='Y'){
sw=0;
i++;
for(  ;i<cntr && !sw ;i++)
for(t=0;t<lc;t++)
  if(strcmp(st[i].chname1.chname[t],num)==0)
       sw=1;
    if(sw==0)
     {    setfillstyle(1,5); bar(340,175,490,260); setcolor(15); rectangle(343,177,487,258);rectangle(345,179,485,256);
	  outtextxy(350,200,"THE END");getch(); ans='n';
      }
 if(sw==1)
    {
     setfillstyle(1,9);bar(50,50,540,400);
     setcolor(15);rectangle(53,53,537,397);rectangle(55,55,535,395);
     setfillstyle(1,12);bar(60,60,140,80);setcolor(15);rectangle(60,60,140,80);
     setcolor(0);outtextxy(70,67,"ID");
	setfillstyle(1,12);bar(150,60,230,80);setcolor(15);rectangle(150,60,230,80);
     setcolor(0);outtextxy(160,67,"Grade");
     box();
     i--;
     outtextxy(80,95,st[i].id);
     sw1=0;
     for(t=0;t<lc && !sw1;t++)
	if(strcmp(st[i].chname1.chname[t],num)==0) sw1=1;
	 t--;
      setfillstyle(1,9);bar(320,50,500,400);
      setcolor(15);rectangle(323,53,497,397);rectangle(325,55,495,395);
      setfillstyle(1,12);bar(330,60,490,80);setcolor(15);rectangle(330,60,490,80);
      setcolor(0);outtextxy(375,67,"Grade");
      setfillstyle(1,0);bar(330,90,490,120);rectangle(330,90,490,120);

      gotoxy(45,7);gets(nomreh);setfillstyle(1,8);bar(330,90,490,120);rectangle(330,90,490,120);setcolor(15);outtextxy(350,100,nomreh);

      strcpy(st[i].chname1.grade[t],nomreh);
     setfillstyle(1,5);bar(340,175,490,260);setcolor(15);
rectangle(343,177,487,258);rectangle(345,179,485,256);outtextxy(350,200,"grade saved");getch();
     lc++;
     k++;
     }//if

}//while
getch();
}
/*//////////////////////output//////////////////
i=-1;
for(j=1;j<=k;j++){
sw=0;
i++;
for(;i<cntr && !sw ;i++)
   for(t=0;t<lc;t++)
      if(strcmp(st[i].chname1.chname[t],num)==0)
       sw=1;
       i--;
    if(sw)
    {
     cout<<"\nID:";puts(st[i].id);
     sw1=0;
 for(t=0;t<lc && !sw1;t++)
   if(strcmp(st[i].chname1.chname[t],num)==0)
     sw1=1;
       t--;
   if(sw1){
	puts(st[i].chname1.chname[t]);
	puts(st[i].chname1.grade[t]); }
     getch();
     cout<<"\n*******************\n\n";
       }//if
       }//for
    getch();  */

/////////////////////////
void outgrade(){
int num,i,j,t,c;
 if(!cntr)
   {
    empty();
    getch();
    return;
    }//end if
    setfillstyle(1,9);bar(50,50,540,400);
    setcolor(15);rectangle(53,53,537,397);rectangle(55,55,535,395);
      setfillstyle(1,12);bar(60,60,140,80);setcolor(15);rectangle(60,60,140,80);
    setcolor(0);outtextxy(70,67,"ID");
	setfillstyle(1,12);bar(150,60,230,80);setcolor(15);rectangle(150,60,230,80);
    setcolor(0);outtextxy(160,67,"Choose Le..");
	setfillstyle(1,12);bar(240,60,330,80);setcolor(15);rectangle(240,60,330,80);
    setcolor(0);outtextxy(275,67,"Grade");
 box();
//////////////
int x3=70,y3=93,x4=70;
for(i=0,y3=93;i<cntr;y3+=25,i++)
{
outtextxy(x3,y3,st[i].id);
for(t=0,x4=70;t<lc;x4+=50,t++){outtextxy(x4+90,y3,st[i].chname1.chname[t]);
outtextxy(x3+180,y3,st[i].chname1.grade[t]); }
delay(400);
}
getch();
}
///////////////////////////
void main()
   {
	char op;
    int ib;
    int   driver = DETECT,mode=0;
    int   i,j,t,l,h;
//   char pas[]={"10568"};
  //  char pas1[6];
    char pas2;
    clrscr();
/*    textcolor(4);gotoxy(20,10);cprintf("IN THE");
    textcolor(15);gotoxy(27,10);cprintf("NAME OF");
    textcolor(2);gotoxy(35,10);cprintf("GOD");
    textcolor(5);gotoxy(20,20);cprintf("Enter Password:");
    i=-1;
    while(pas2!=13){ pas2=getch(); i++;
     pas1[i]=pas2;textcolor(15);cprintf("*");}pas1[i]=0;
    clrscr();
    if(strcmp(pas,pas1)==0){
    for(i=0,j=1,l=0,h=15;i<5;textcolor(j),gotoxy(l,h),cprintf("WELCOME"),delay(300),j++,l+=5,h+=5,i++);
    for(i=0,j=1,l=5,h=10;i<8;textcolor(j),gotoxy(l,h),cprintf("WELCOME"),delay(300),j++,l+=5,h+=5,i++);
    clrscr();
    please();                   */


    initgraph(&driver,&mode,"c:\\tc\\bgi");

    ////////////////////////////////////
ifstream in1("d:\\student.txt",ios::app);
     for(ib=0;!in1.eof();ib++)
    {
     in1.getline(st[ib].name,50);
     in1.getline(st[ib].family,50);
     in1.getline(st[ib].faname,50);
     in1.getline(st[ib].id,50);
     in1.getline(st[ib].codem,50);
     cntr=ib;
    }
    in1.close();
////////////////////////////////////
ifstream in2("d:\\lessonpr.txt",ios::app);
    for( i=0;!in2.eof();i++)
    {
     in2.getline(pr[i].cod,50);
     in2.getline(pr[i].prname,50);
     in2.getline(pr[i].unit,50);
     lp=i;
    }
   in2.close();
//////////////////////////////////////
  ifstream in3("d:\\lessonch.txt",ios::app);
    for( j=0;!in3.eof();j++)
    {
     in3.getline(st[j].name,50);
     in3.getline(st[j].family,50);
     in3.getline(st[j].faname,50);
     in3.getline(st[j].id,50);
     in3.getline(st[j].codem,50);
     for(t=0;t<lc;t++)
    in3.getline(st[j].chname1.chname[t],50);
     cntr=j;
    }
   in3.close();
//////////////////////////////////
  ifstream in4("d:\\lchgr.txt",ios::app);
    for( j=0;!in4.eof();j++)
    {
     in4.getline(st[j].name,50);
     in4.getline(st[j].family,50);
     in4.getline(st[j].faname,50);
     in4.getline(st[j].id,50);
     in4.getline(st[j].codem,50);
     for(t=0;t<lc;t++){
    in4.getline(st[j].chname1.chname[t],50);
    in4.getline(st[j].chname1.grade[t],50);  }
     cntr=j;
    }
   in4.close();
////////////////////////////////////
    menu();
    op=getch();
    if(op==19)
    while(op!=45)
       {
	op=getch();
	clear();
	switch(op)
		{
////////////////////////////////////////////////////
		case 'f':  y=50; int swf=1,wf=67;  char chf;
		setfillstyle(1,2);	bar(4,20,54,39);
		setcolor(0);   outtextxy(10,25,"File");
		setcolor(4); outtextxy(10,25,"F");  outtextxy(10,30,"-");
		op=getch();
		if(op==13)
     while (swf)
     {
      file();
     if(y<50)   y=110;
     if(y>110)  y=50;
     if(y==50)
      { setfillstyle(1,2); bar(13,y,196,wf);
	setcolor(0); outtextxy(25,55,"Input data student"); setcolor(4); outtextxy(25,55,"I");
	chf=getch();
	if(chf==13){ clear(); inputst(); break; }
	}
     if(y==70)
      { setfillstyle(1,2); bar(13,y,196,wf+20);
	setcolor(0); outtextxy(25,75,"Choose unit student"); setcolor(4); outtextxy(25,75,"C");
       chf=getch();
       if(chf==13){clear();inputlch();break;}
       }
     if(y==90)
      { setfillstyle(1,2); bar(13,y,196,wf+40);
	setcolor(0);  outtextxy(25,95,"Input grade lesson"); setcolor(4);  outtextxy(25,95,"I");
       chf=getch();
       if(chf==13){clear();ingrade();break;}
       }
    if(y==110)
      { setfillstyle(1,2); bar(13,y,196,wf+60);
	setcolor(0);  outtextxy(25,115,"Exit :"); setcolor(4);  outtextxy(25,115,"E");
	setcolor(0);  outtextxy(135,115,"Esc");  setcolor(4);  outtextxy(135,115,"E");
       }
     op=getch();
     switch(op)
	  {
	   case 80:  y+=20;  break;
	   case 72:  y-=20;  break;
	   case 27:  swf=0;   break;
	   }//switch
	 } //while
		break;
/////////////////////////////////////////////////////////////
		case 'e':    y=50; int swe=1,we=67;char che;
		    setfillstyle(1,2);	bar(55,20,114,39);
		    setcolor(0);   outtextxy(70,25,"Edit");
		    setcolor(4); outtextxy(70,25,"E");  outtextxy(70,30,"-");
		    op=getch();
		if(op==13)
       while(swe){
       edit();
     if(y<50)   y=210;
     if(y>210)  y=50;
     if(y==50)
       { setfillstyle(1,2);	bar(61,y,297,we);
	setcolor(0);  outtextxy(70,55,"Modify student"); setcolor(4);  outtextxy(70,55,"M");
	che=getch();
	if(che==13){clear();editst();break;}
	}
     if(y==70)
       { setfillstyle(1,2);	bar(61,y,297,we+20);
	setcolor(0);  outtextxy(70,75,"Delete one student");setcolor(4);  outtextxy(70,75,"D");
	che=getch();
	if(che==13){clear();deletebyid();break;}
	}
     if(y==90)
       { setfillstyle(1,2);	bar(61,y,297,we+40);
	setcolor(0);  outtextxy(70,95,"Delete more student");setcolor(4);  outtextxy(70,95,"D");
	che=getch();
	if(che==13){clear();deletebytid();break;}
	}
     if(y==110)
       { setfillstyle(1,2);	bar(61,y,297,we+60);
	setcolor(0);  outtextxy(70,115,"Modify lesson choose student");setcolor(4);  outtextxy(70,115,"M");
	che=getch();
	if(che==13){clear();outlch();break;}
	}
     if(y==130)
       { setfillstyle(1,2);	bar(61,y,297,we+80);
	setcolor(0);  outtextxy(70,135,"Delete lesson choose student");setcolor(4);  outtextxy(70,135,"D");
	 che=getch();
	 if(che==13){clear(); delelch();break;}
	}
     if(y==150)
       { setfillstyle(1,2);	bar(61,y,297,we+100);
	setcolor(0);  outtextxy(70,155,"Modify lesson present term");setcolor(4);  outtextxy(70,155,"M");
	che=getch();
	if(che==13){clear(); editpr(); break;}
	}
     if(y==170)
       { setfillstyle(1,2);	bar(61,y,297,we+120);
	setcolor(0);  outtextxy(70,175,"Delete lesson present term");setcolor(4);  outtextxy(70,175,"D");
	che=getch();
	if(che==13){clear(); delepr();break;}
	}
     if(y==190)
       { setfillstyle(1,2);	bar(61,y,297,we+140);
	setcolor(0);  outtextxy(70,195,"Added lesson present term");setcolor(4);  outtextxy(70,195,"A");
	che=getch();
	if(che==13){ clear(); addedpr(); break;}
	}
     if(y==210)
       { setfillstyle(1,2);	bar(61,y,297,we+160);
	setcolor(0);  outtextxy(70,215,"Exit :"); setcolor(4);  outtextxy(70,215,"E");
	setcolor(0);  outtextxy(255,215,"Esc");setcolor(4);  outtextxy(255,215,"E");
	}
     op=getch();
     switch(op)
	  {
	   case 80:  y+=20;  break;
	   case 72:  y-=20;  break;
	   case 27:  swe=0;   break;
	   }//switch
	 } //while
		break;
////////////////////////////////////////////////////////////
		case 'v':    y=50; int swv=1,wv=67;int chv;
		    setfillstyle(1,2);	bar(115,20,174,39);
		    setcolor(0);   outtextxy(130,25,"View");
		    setcolor(4); outtextxy(130,25,"V"); outtextxy(130,30,"-");
		       op=getch();
		if(op==13)
      while(swv){
     view();
     if(y<50)   y=130;
     if(y>130)  y=50;
     if(y==50)
      { setfillstyle(1,2);	bar(122,y,387,wv);
       setcolor(0);  outtextxy(130,55,"Sort student by ID");setcolor(4); outtextxy(130,55,"S"); outtextxy(258,55,"ID");
       chv=getch();
       if(chv==13){clear(); vsortbyid(); break; }
       }
     if(y==70)
      { setfillstyle(1,2);	bar(122,y,387,wv+20);
       setcolor(0);  outtextxy(130,75,"Sort student by Family");setcolor(4);  outtextxy(130,75,"S");outtextxy(258,75,"F");
       chv=getch();
       if(chv==13){clear(); vsortbyfamily(); break; }
       }
     if(y==90)
      { setfillstyle(1,2);	bar(122,y,387,wv+40);
       setcolor(0);  outtextxy(130,95,"Lesson peresent term");setcolor(4);  outtextxy(130,95,"L");
       chv=getch();
       if(chv==13){clear(); outlpr(); break; }
       }
     if(y==110)
      { setfillstyle(1,2);	bar(122,y,387,wv+60);
       setcolor(0);  outtextxy(130,115,"Lesson choose and grade student");setcolor(4);  outtextxy(130,115,"L");
       chv=getch();
       if(chv==13){clear();outgrade();break;}
       }
      if(y==130)
	{ setfillstyle(1,2);	bar(122,y,387,wv+80);
	 setcolor(0);  outtextxy(130,135,"Exit :"); setcolor(4);  outtextxy(130,135,"E");
	 setcolor(0);  outtextxy(350,135,"Esc");setcolor(4);  outtextxy(350,135,"E");
	 }
     op=getch();
     switch(op)
	  {
	   case 80:  y+=20;  break;
	   case 72:  y-=20;  break;
	   case 27:  swv=0;   break;
	   }//switch
	 } //while
		break;
//////////////////////////////////////////////////////////////
		case 's':   y=50; int sws=1,ws=67;int chs;
		    setfillstyle(1,2);	bar(175,20,245,39);
		    setcolor(0); outtextxy(190,25,"Search");
		    setcolor(4); outtextxy(190,25,"S"); outtextxy(190,30,"-");
		op=getch();
		if(op==13)
     while(sws){
      search();
     if(y<50)   y=90;
     if(y>90)  y=50;
     if(y==50)
       { setfillstyle(1,2);	bar(180,y,288,ws);
	setcolor(0); outtextxy(190,55,"By ID");setcolor(4);outtextxy(190,55,"B");outtextxy(214,55,"I");
	chs=getch();
	if(chs==13){clear();searchbyid();break;}
	}
     if(y==70)
       { setfillstyle(1,2);	bar(180,y,288,ws+20);
	setcolor(0); outtextxy(190,75,"By Family");setcolor(4);outtextxy(190,75,"B");outtextxy(214,75,"F");
	chs=getch();
	if(chs==13){clear();searchbyfamily();break;}
	}
     if(y==90)
       { setfillstyle(1,2);	bar(180,y,288,ws+40);
	setcolor(0);  outtextxy(190,95,"Exit :"); setcolor(4);  outtextxy(190,95,"E");
	setcolor(0);  outtextxy(254,95,"Esc");setcolor(4);  outtextxy(254,95,"E");
	}
    op=getch();
     switch(op)
	  {
	   case 80:  y+=20;  break;
	   case 72:  y-=20;  break;
	   case 27:  sws=0;   break;
	   }//switch
	 } //while
		break;
////////////////////////////////////////////////////////////////
		case 'o':  y=50; int swo=1,wo=67; char cho;
		    setfillstyle(1,2);	bar(241,20,327,39);
		    setcolor(0); outtextxy(250,25,"Option");
		    setcolor(4); outtextxy(250,25,"O"); outtextxy(250,30,"-");
		op=getch();
		if(op==13)
     while(swo){
      option();
     if(y<50)   y=90;
     if(y>90)  y=50;
     if(y==50)
       { setfillstyle(1,2);	bar(241,y,347,wo);
	setcolor(0); outtextxy(250,55,"Time");setcolor(4);outtextxy(250,55,"T");
	  cho=getch();
	if(cho==13){clear(); timer(); clear1(); break;}
	}
     if(y==70)
       { setfillstyle(1,2);	bar(241,y,347,wo+20);
	setcolor(0); outtextxy(250,75,"Date");setcolor(4);outtextxy(250,75,"D");
	 cho=getch();
	if(cho==13){clear(); date(); clear1(); break;}
	}
     if(y==90)
       { setfillstyle(1,2);	bar(241,y,347,wo+40);
	setcolor(0);  outtextxy(250,95,"Exit :"); setcolor(4);  outtextxy(250,95,"E");
	setcolor(0);  outtextxy(304,95,"Esc");setcolor(4);  outtextxy(304,95,"E");
	cho=getch();
	if(cho==13)break;
	}
    op=getch();
     switch(op)
	  {
	   case 80:  y+=20;  break;
	   case 72:  y-=20;  break;
	   case 27:  swo=0;   break;
	   }//switch
	 } //while
		break;
		 }//end switch
	 }//end while
	 ///////////////////////////
ofstream out1("d:\\student.txt");
     for(ib=0;ib<cntr;ib++)
    {
     out1<<st[ib].name<<endl;
     out1<<st[ib].family<<endl;
     out1<<st[ib].faname<<endl;
     out1<<st[ib].id<<endl;
     out1<<st[ib].codem<<endl;
    }
    out1.close();
/////////////////////////////
    ofstream out2("d:\\lessonpr.txt");
    for( i=0;i<lp;i++)
    {
     out2<<pr[i].cod<<endl;
     out2<<pr[i].prname<<endl;
     out2<<pr[i].unit<<endl;
    }
   out2.close();
//////////////////////////////////
  ofstream out3("d:\\lessonch.txt");
    for( j=0;j<cntr;j++)
    {
     out3<<st[j].name<<endl;
     out3<<st[j].family<<endl;
     out3<<st[j].faname<<endl;
     out3<<st[j].id<<endl;
     out3<<st[j].codem<<endl;
     for(t=0;t<lc;t++)
     out3<<st[j].chname1.chname[t]<<endl;
      }
   out3.close();
//////////////////////////////////
  ofstream out4("d:\\lchgr.txt");
    for( j=0;j<cntr;j++)
    {
     out4<<st[j].name<<endl;
     out4<<st[j].family<<endl;
     out4<<st[j].faname<<endl;
     out4<<st[j].id<<endl;
     out4<<st[j].codem<<endl;
     for(t=0;t<lc;t++){
     out4<<st[j].chname1.chname[t]<<endl;
     out4<<st[j].chname1.grade[t]<<endl;}
      }
   out4.close();
////////////////////////////////////////

//	 }//ifpas
// else cprintf("Invalid Password");
    closegraph();
   }



