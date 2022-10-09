#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
void main()
{
char *ch[100],*s[1],s2[100];
int i;
i=0;
int driver=DETECT,mode;
float number;
initgraph(&driver,&mode,"c:\\tc\\bgi");
cleardevice();
/*long int m=204210;
ltoa(m,*ch,10);
outtextxy(10,10,*ch);
settextstyle(0,0,0);   */
setcolor(4);
int j=-1;
while (j<3)
{
j++;
*s[1]=getche();
outtextxy(100+(j*10),100+i,(char*)s[1]);
outtext("");
outtext("");
s2[j]=*s[1];
}
number=atof(s2);
printf("%f",number);
getch();
}
