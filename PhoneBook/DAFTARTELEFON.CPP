#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream.h>
struct Book{
	char name[20];
	char name2[30];
	char Tel[30];
} a[100]; //--> yani arrayei az noe in struct
int n;
void menu();
void get_data();  //daryaafte ettelaat
void sort_name(); //morattab saazi bar asaase naame khanevadegy
void sort_Tel(); //morattab saazi bar asaase shomare telefon
void show();  //neshaan dadane tamaame daftarche telefon pas az morattab saazi
void Search_Tel(); //Jostojoo kardane yek shomare telefon
void Search_Name(); //jostojoo kardane name khanevadegy
void Edit(); //viraayeshe etelaate yek shomare telefon
//////////////////////
void menu()
{
int i=0;
textcolor(15);
clrscr();
textcolor(15);
cprintf("1.vared kardane ettelaat");
gotoxy(1,2);
cprintf("2.morattab kardane daftarche bar asaase naame khanevadegy");
gotoxy(1,3);
cprintf("3.morattab kardane daftarche bar asaase shomare telefon");
gotoxy(1,4);
cprintf("4.jostojoo kardane yek shomare telefon");
gotoxy(1,5);
cprintf("5.jostojoo kardane name khanevadegy");
gotoxy(1,6);
cprintf("6.viraayeshe etelaate yek shomare telefon");
gotoxy(1,7);
cprintf("7.Exit");
gotoxy(1,10);
cprintf("  entekhaabe khodra vaared konid:(1-7) ");
while (i<1 || i>7)
{
gotoxy(40,10); //in dastoor makan namaa ro be jaayi ke mikhaym mibare va chizayi ke mikhaymo oonja chaap mikone
printf("     "); //va koll safhe namaayesh 80ta sotoon dare va 25ta satr
gotoxy(40,10);    //be in shekl estefaade mishe "gotoxy(sotoon,satr);"
cin>>i;
if (i==1)
	get_data();
else if (i==2)
	sort_name();
else if (i==3)
	sort_Tel();
else if (i==4)
	Search_Tel();
else if (i==5)
	Search_Name();
else if (i==6)
	Edit();
else if (i==7)
	exit(0); //in dastoor az barnaame khaarej mishe
}
}
///////////////////////////////////
void get_data()
{
textcolor(14);
clrscr();
textcolor(14);
int i;
cprintf("lotfan tedad ra vared konid:");
cin>>n;
for (i=0;i<n;i++)
{
clrscr();
cprintf("Name:");
gets(a[i].name);
cprintf("\nNaame khanevadegy:");
gets(a[i].name2);
cprintf("\nShomare telefon:");
gets(a[i].Tel);
}
menu();
}
/////////////////////////////
void sort_Tel()
{
Book temp;
for (int i=n-1;i>0;i--)
for (int j=0;j<i;j++)
	if (strcmp(a[j].Tel,a[j+1].Tel)>0)
	{
	     temp=a[j];
	     a[j]=a[j+1];
	     a[j+1]=temp;
	}
show();//shows the sorted list
}
///////////////////////////////
void sort_name()
{
Book temp;
for (int i=n-1;i>0;i--)
for (int j=0;j<i;j++)
	if (strcmp(a[j].name2,a[j+1].name2)>0)
	{
	     temp=a[j];
	     a[j]=a[j+1];
	     a[j+1]=temp;
	}
show();//shows the sorted list
}
////////////////////////////////
void show() //shows list
{
textcolor(15);
clrscr();
textcolor(15);
int i,cntr=3;
gotoxy(1,1);cprintf("name");
gotoxy(30,1);cprintf("naame khanevadegy");
gotoxy(65,1);cprintf("Tel");
gotoxy(1,2);
for (i=1;i<72;cprintf("-"),i++);
for (i=0;i<n;i++)
{
gotoxy(1,cntr);
puts(a[i].name);
gotoxy(30,cntr);
puts(a[i].name2);
gotoxy(65,cntr);
puts(a[i].Tel);
if (cntr==24)
{
	cntr=3;
	getch();
	window(1,3,80,25);
	clrscr();
	window(1,1,80,25);
}
cntr++;
}
getch();
menu();
}
/////////////////////////////////
void Search_Tel()
{
char s[30];
textcolor(15);
clrscr();
textcolor(15);
cprintf("Shomare telefon ra vared konid:");
gets(s);
textcolor(4);
clrscr();
textcolor(4);
for (int i=0;i<n;i++)
	if (strcmp(a[i].Tel,s)==0)
	{
	   cprintf("Tel:");
	   puts(s);
	   cprintf("\n");
	   textcolor(15);
	   cprintf("name:");
	   puts(a[i].name);
	   cprintf("\n");
	   cprintf("name khanevadegy:");
	   puts(a[i].name2);
	   getch();
	   menu();
	   return;
	}
cprintf("!!!Peida nashod!!!");
getch();
menu();
}
///////////////////////////////////
void Search_Name()
{
char s[30];
textcolor(15);
clrscr();
textcolor(15);
cprintf("Naame khanevadegy ra vared konid:");
gets(s);
textcolor(14);
clrscr();
textcolor(14);
for (int i=0;i<n;i++)
	if (strcmp(a[i].name2,s)==0)
	{

	   cprintf("name:");
	   puts(a[i].name);
	   cprintf("\n");
	   cprintf("name khanevadegy:");
	   puts(a[i].name2);
	   textcolor(15);
	   cprintf("\n");
	   cprintf("Tel:");
	   puts(a[i].Tel);
	   getch();
	   menu();
	   return;
	}
cprintf("!!!Peida nashod!!!");
getch();
menu();
}
/////////////////////////////////
void Edit()
{
char s[30];
textcolor(15);
clrscr();
textcolor(15);
clrscr();
cprintf("Shomare telefon ra vared koind:");
gets(s);
textcolor(14);
clrscr();
textcolor(14);
for (int i=0;i<n;i++)
	if (strcmp(a[i].Tel,s)==0)
	{

	   cprintf("name:");
	   gets(a[i].name);
	   cprintf("\n");
	   cprintf("name khanevadegy:");
	   gets(a[i].name2);
	   textcolor(15);
	   cprintf("\n");
	   cprintf("Tel:");
	   gets(a[i].Tel);
	   getch();
	   menu();
	   return;
	}
cprintf("!!!Peida nashod!!!");
getch();
menu();
}
///////////////////////////////////
void main()
{
menu();
}
