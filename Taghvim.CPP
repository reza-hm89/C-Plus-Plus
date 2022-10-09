//thie konande:mohsen golian.
//shomare daneshjooie:88413151.
//reshte:sakht afzar.
#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include<stdlib.h>

void taghvim_menu();
void taghvim();
void taghvim2();
void hafte(int);
void mobadel();
void tedaderooz();
void khorooj();
void menu();
char k;
int  row;

void main()
{
	_setcursortype(_NOCURSOR);//baraye hazf cheshmake makan nama.
	textcolor(9);
	clrscr() ;
	row=1;
	//ghesmate kadere meno.
	for(int x=15;x<=60;x++)
	{
	gotoxy(x,10);
	cout<<"#";
	gotoxy(x,37);
	cout<<"#";
	}
	for(int y=10;y<=37;y++)
	{
	gotoxy(15,y);
	cout<<"#";
	gotoxy(60,y);
	cout<<"#";
	}
//*********************************************
	//menoye asly.
	int n ;
	char k ;
	textcolor(3);
	gotoxy(1,1);
	cprintf("tahie konande: mohsen golian");
	textcolor(10);
	gotoxy(32,20);
	cprintf(">>");
	gotoxy(35,20) ;
	cprintf("taghvim" );
	gotoxy(35,22);
	cprintf("mobadel" );
	gotoxy(35,24);
	cprintf("t.r.g.azsal") ;//tedad rooze gozashte az sal.
	gotoxy(35,26);
	cprintf("khorooj");
	menu();
}
//*********************************************
void menu()
{
	char k;
	int y=20;
	textcolor(10);
	while(1)
	{
		k=getch() ;
		switch(k)
		{
			case 80://go down
				gotoxy(32,y) ; cprintf("  " );
				if (y==26) y=20;
				else y+=2;
				gotoxy(32,y) ; cprintf(">>" );
				break ;

			case 72://go up
				gotoxy(32,y) ; cprintf("  " );
				if (y==20) y=26 ;
				else y-=2;
				gotoxy(32,y) ; cprintf(">>" );
				break ;

			case 13://select
				if(y==20) taghvim();
				if(y==22) mobadel();
				if(y==24) tedaderooz();
				if(y==26) khorooj() ;
		}//switch
	}//while
}//menu
//*********************************************//
void taghvim ()
{
char k;
clrscr();
gotoxy(18,24);
textcolor(398);
cprintf("lotfan yek rooz az hafte ra entekhab konid:");
textcolor(10);
gotoxy(4,1);   cprintf(" Shanbe");
gotoxy(4,2);   cprintf("1shanbe");
gotoxy(4,3);   cprintf("2shanbe");
gotoxy(4,4);   cprintf("3shanbe");
gotoxy(4,5);   cprintf("4shanbe");
gotoxy(4,6);   cprintf("5shanbe");
gotoxy(4,7);   cprintf("Jome");
gotoxy(1,row); cprintf(">>");
//r=row;
char c;
textcolor(10);
while(1)
{
	c=getch();
	switch(c)
	{
		case 80: //move down
			gotoxy(1,row); cprintf("  ");
			if(row==7) row=1;
			else row++;
			gotoxy(1,row); cprintf(">>");
			break;

		case 72: //move up
			gotoxy(1,row); cprintf("  ");
			if(row==1) row=7;
			else row--;
			gotoxy(1,row); cprintf(">>");
			break;

		case 13: //select
			row+=3;
			taghvim2();
		case 27://go to main
			main();

	}//switch
}//while
}
//***********************************************************//
void taghvim2()
{
int fasl=1,i,x=12,j,y; //i=shomarande rooz.
while(fasl<5)
{
	clrscr();
	taghvim_menu();
	if(fasl==1)
	{	gotoxy(32,1); textcolor(394);
		cprintf(".: B A H A R :.");
	}
	else if(fasl==2)
	{
		gotoxy(32,1); textcolor(396);
		cprintf(".: T A B E S T A N :.");
	}
	else if(fasl==3)
	{
		gotoxy(32,1); textcolor(398);
		cprintf(".: P A I Z :.");
	}
	else if(fasl==4)
	{
		gotoxy(32,1); textcolor(395);
		cprintf(".: Z E M E S T A N :.");
	}
	textcolor(13);
	gotoxy(18,40); cprintf("Baraye moshahedeye fasle bad ENTER bezanid.");
	textcolor(12);
	gotoxy(18,45);cprintf("braye khorooj az barname klide escap ra bezanid.");
	for(int n=1;n<=3;n++) //moshahedeye har fasl (3mah)
	{                            //n=har fasl.
		if(fasl<3) j=31;     //j=shomarande tedad rooze mah.
		else j=30;

		if(n==1) hafte(4);
		else if(n==2) hafte(13);
		else hafte(22);

		for(i=1;i<=j;i++)
		{
			gotoxy(x,row);
			if(fasl==1) textcolor(10);
			else if(fasl==2) textcolor(12);
			else if(fasl==3) textcolor(14);
			else if(fasl==4) textcolor(11);
			cprintf("%d",i);  //d=yek adade sahih(integer)
			row++;
			if (n==1&&row>10) //namayeshe mahe aval
			{ row=4; x+=3; }
			if (n==2&&row>19) //namayeshe mahe dovom
			{ row=13; x+=3; }
			if (n==3&&row>28) //namayeshe mahe sevom
			{ row=22; x+=3; }
		}//for
		x=12; row+=9;
	}//for
	fasl++; row-=27;
	k=getch();
	if(k==13) continue;
	else
		if(k==27) break;
}//while
main();
}
//***********************************************************//
void hafte(int h)
{
textcolor(15);
gotoxy(4,h+0);   cprintf(" Shanbe");
gotoxy(4,h+1);   cprintf("1shanbe");
gotoxy(4,h+2);   cprintf("2shanbe");
gotoxy(4,h+3);   cprintf("3shanbe");
gotoxy(4,h+4);   cprintf("4shanbe");
gotoxy(4,h+5);   cprintf("5shanbe");
gotoxy(4,h+6);   cprintf(" Jome");
}
//***********************************************************//
//tabdile tarikha .s to g & g to s.
void mobadel ()
{
clrscr();
char k;
int  y=24;
gotoxy(25,20); cout<<"Baraye khoruj ESC ra bezanid" ;
gotoxy(25,24); cout<<"   tabdile ghamari be shamsi:";
gotoxy(25,26); cout<<"   tabdile shamsi be ghamari:";
gotoxy(25,y);  cout<<">>";
while(1) //ta binahayat
 { 	 k=getch();
	 gotoxy(25,y);
	 cout<<"   ";
	 switch(k)
	 {
		case 80:
		if(y==26) y=24;
		else y+=2;
		break;

		case 72:
		if(y==24) y=26;
		else y-=2;
		break;

		case 27:
		main();

		case 13:
		if(y==24)
		{	clrscr();
			int tgh=0,tsh,a,b,c,c1;
		//tgh=tarikhe ghamari,tsh=tarikhe shamsi
		while(tgh<1000)
		{
			clrscr();
			gotoxy(20,24);
			cout<<"lotfan tarikhe ghamari ra vared konid: " ;
			cin>>tgh;
		}
		clrscr();
		a=(tgh/1000)*30;
		b=((tgh%1000)/100)*3;
		c=(((tgh%1000)%100)/30);
		c1=(((tgh%1000)%100)%30);
		if(c1<=15) c--;
		tsh=tgh-(a+b+c);
		gotoxy(25,24);
		cout<<"tarikhe shamsi = "<<tsh;
		getch();
		clrscr();
		mobadel();
		}
		if(y==26)
		{	clrscr();
			int tgh=0,tsh,a,b,c,c1;
		//tgh=tarikhe shamsi,tsh=tarikhe ghamari
		while(tgh<1000)
		{
			clrscr();
			gotoxy(20,24);
			cout<<"lotfan tarikhe shamsi ra vared konid: ";
			cin>>tgh;
		}
		clrscr();
		a=(tgh/1000)*30;
		b=((tgh%1000)/100)*3;
		c=(((tgh%1000)%100)/30);
		c1=(((tgh%1000)%100)%30);
		if(c1>=15)
			c++;
		tsh=tgh+(a+b+c);
		gotoxy(25,24);
		cout<<"tarikhe ghamari = "<<tsh;
		getch();
		clrscr();
		mobadel();
		}//if
	 }//switch
	 gotoxy(25,y);
	 cout<<">>";
 }//while
}//void momadel
//**********************************************
void tedaderooz ()
{
//g=tedade rooze gozashte az sal
clrscr();
int d,m,g;
gotoxy(25,24);
cout<<"please enter day:" ;
gotoxy(42,24);
cin>>d;
while(d>31)
{
gotoxy(42,24);
cout<<"       ";
gotoxy(42,24);
cin>>d;
}
clrscr();
gotoxy(25,26);
cout<<"please enter a month:";
gotoxy(47,26);
cin>>m;
while(m>12)
{
gotoxy(47,26);
cout<<  "      ";
gotoxy(47,26);
cin>>m;
}
if (m<=7)
 g=((m-1)*31)+d;
 else
 g=((m-1)*30)+d;
clrscr();
gotoxy(25,28);
cout<<"tedad rooz gozashte az sal="<<g;
getch();
main();
}
//*****************************************************
void khorooj ()
{
	char ans;
	clrscr();
	gotoxy(22,22); cprintf("Do you want to exit?(Y/N)... ");
	ans=getch();
	if(ans=='n'||ans=='N'||ans==27) main();
	else
	if(ans=='Y'||ans=='y'||ans==13) exit(0);
}
//**********************************************
void taghvim_menu()
{
  textcolor(8);

  gotoxy(3,3);  cprintf("ษอออออออัอออออออออออออออออป");
  for(int i=4;i<=11;i++)
  {gotoxy(3,i); cprintf("บ       ณ                 บ");}
  gotoxy(3,11); cprintf("ศอออออออฯอออออออออออออออออผ");

  gotoxy(3,12);  cprintf("ษอออออออัอออออออออออออออออป");
  for(int j=13;j<=20;j++)
  {gotoxy(3,j); cprintf("บ       ณ                 บ");}
  gotoxy(3,20); cprintf("ศอออออออฯอออออออออออออออออผ");

  gotoxy(3,21);  cprintf("ษอออออออัอออออออออออออออออป");
  for(int k=22;k<=29;k++)
  {gotoxy(3,k); cprintf("บ       ณ                 บ");}
  gotoxy(3,29); cprintf("ศอออออออฯอออออออออออออออออผ");
}