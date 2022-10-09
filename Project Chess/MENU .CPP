#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
int main()
{       int s,x=10,i,j,k,z,index=0,a;
	clrscr();
	for (i=38,j=39,z=7,k=7;i<75,j>10,k<30,z<30;i++,j--,k++,z++)
	{
		gotoxy(i,7);
		textcolor(11);
		cprintf("¯");
		delay(20);
		gotoxy(j,7);
		textcolor(11);
		cprintf("®");
		delay(20);
		gotoxy(i,30);
		textcolor(11);
		cprintf("¯");
		delay(20);
		gotoxy(j,30);
		textcolor(11);
		cprintf("®");
		delay(20);
		gotoxy(54,k);
		textcolor(3);
		cprintf("õ");
		delay(20);
		gotoxy(23,z);
		textcolor(3);
		cprintf("ô");
	}
	textcolor(15);
	for (i=1;i<=80;i++)
	{       gotoxy(i,1);
		cprintf("*");
		delay(5);
	}
	for (i=2;i<=49;i++)
	{       gotoxy(80,i);
		cprintf("*");
		delay(5);
	}
	for (i=80;i>=1;i--)
	{       gotoxy(i,49);
		cprintf("*");
		delay(5);
	}
	for (i=49;i>=1;i--)
	{       gotoxy(1,i);
		cprintf("*");
		delay(5);
	}
	gotoxy(32,10);
	textcolor(15);
	cprintf("1.   New Game");
	delay(300);
	gotoxy(32,13);
	cprintf("2.   Load Game");
	delay(300);
	gotoxy(32,16);
	cprintf("3.   Credits ");
	delay(300);
	gotoxy(32,19);
	cprintf("4.   Exit");
	//Chess /***************/
		gotoxy(65,5);
		textcolor(12);
		cprintf("ßßßßßß");
		delay(30);
		delay(30);
		for (i=5;i<=9;i++)
		{	gotoxy(65,i);
			cprintf("Û");
			delay(30);
		}
		gotoxy(65,9);
		cprintf("ßßßßßß");
		delay(30);
		textcolor(14);
		for (i=12;i<=18;i++)
		{	gotoxy(65,i);
			cprintf("Û");
			delay(30);
			gotoxy(70,i);
			cprintf("Û");
			delay(30);
		}
		gotoxy(66,15);
		cprintf("ßßßß");
		delay(30);
		textcolor(13);
		gotoxy(65,21);
		cprintf("ßßßßßß");
		delay(30);
		for (i=21;i<=26;i++)
		{	gotoxy(65,i);
			cprintf("Û");
			delay(30);
		}
		gotoxy(66,24);
		cprintf("ßßßßß");
		delay(30);
		gotoxy(65,27);
		cprintf("ßßßßßß");
		delay(30);
		textcolor(10);
		gotoxy(65,30);
		cprintf("ß");
		delay(30);
		gotoxy(66,29);
		cprintf("ßßßß");
		delay(30);
		gotoxy(70,30);
		cprintf("ß");
		delay(30);
		for (i=30;i<33;i++)
		{       gotoxy(65,i);
			cprintf("Û");
			delay(30);
		}
		gotoxy(66,32);
		cprintf("ÜÜÜÜÜ");
		delay(30);
		for (i=33;i<35;i++)
		{       gotoxy(70,i);
			cprintf("Û");
			delay(30);
		}
		gotoxy(65,35);
		cprintf("ß");
		delay(30);
		gotoxy(66,36);
		cprintf("ßßßß");
		delay(30);
		gotoxy(70,35);
		cprintf("ß");
		delay(30);
		textcolor(9);
		gotoxy(65,39);
		cprintf("ß");
		delay(30);
		gotoxy(66,38);
		cprintf("ßßßß");
		delay(30);
		gotoxy(70,39);
		cprintf("ß");
		delay(30);
		for (i=39;i<42;i++)
		{       gotoxy(65,i);
			cprintf("Û");
			delay(30);
		}
		gotoxy(66,41);
		cprintf("ÜÜÜÜÜ");
		delay(30);
		for (i=42;i<44;i++)
		{       gotoxy(70,i);
			cprintf("Û");
			delay(30);
		}
		gotoxy(65,44);
		cprintf("ß");
		delay(30);
		gotoxy(66,45);
		cprintf("ßßßß");
		delay(30);
		gotoxy(70,44);
		cprintf("ß");
		delay(30);
	//chess/******************/
	//***Mohrehaye shatranj***//
	for(i=3;i<=11;i++)
	      for(j=5;j<=42;j++)
		{	gotoxy(i,j);
			cout<<"²";
			delay(3);
		}
	gotoxy(3,6);
	textcolor(129);
	cprintf("ÜÜÜÜÜÜÜ");
	gotoxy(3,6);
	cprintf("º");
	gotoxy(6,6);
	cprintf("º");
	gotoxy(9,6);
	cprintf("º");
	gotoxy(3,5);
	cprintf("º");
	gotoxy(6,5);
	cprintf("º");
	gotoxy(9,5);
	cprintf("º");
	for(i=5;i<=7;i++)
		for(j=7;j<=15;j++)
			{	gotoxy(i,j);
				cprintf("Û");
			}
	gotoxy(3,15);
	cprintf("ÛÛÛÛÛÛÛ");
	//End of rokh/////////
	//begin of king//
	textcolor(154);
	gotoxy(4,29);
	cprintf("ÜÜÜÜÜ");
	gotoxy(6,28);
	cprintf("Û");
	gotoxy(6,29);
	cprintf("Û");
	gotoxy(6,30);
	cprintf("Û");
	gotoxy(6,31);
	cprintf("Û");
	gotoxy(6,31);
	cprintf("Û");
	gotoxy(4,32);
	cprintf("ÛÛÛÛÛ");
	gotoxy(5,33);
	cprintf("ÛÛÛ");
	gotoxy(6,34);
	cprintf("Û");
	for (i=35;i<=40;i++)
	{       gotoxy(6,i);
		cprintf("Û");
	}
	gotoxy(4,42);
	cprintf("ÛÛÛÛÛ");
	gotoxy(5,41);
	cprintf("ÛÛÛ");

	//**************//
	//Clear*********//
	gotoxy(4,5);
	cout<<"  ";
	delay(5);
	gotoxy(7,5);
	cout<<"  ";
	delay(5);
	gotoxy(10,5);
	cout<<"  ";
	delay(5);
	gotoxy(10,6);
	cout<<"  ";
	delay(5);
	gotoxy(3,7);
	cout<<"  ";
	delay(5);
	gotoxy(8,7);
	cout<<"      ";
	delay(5);
	gotoxy(10,7);
	cout<<"  ";
	delay(5);
	gotoxy(3,8);
	cout<<"  ";
	delay(5);
	gotoxy(8,8);
	cout<<"      ";
	delay(5);
	gotoxy(10,8);
	cout<<"  ";
	delay(5);
	gotoxy(3,9);
	cout<<"  ";
	delay(5);
	gotoxy(8,9);
	cout<<"      ";
	delay(5);
	gotoxy(10,9);
	cout<<"  ";
	delay(5);
	gotoxy(3,10);
	cout<<"  ";
	delay(5);
	gotoxy(8,10);
	cout<<"      ";
	delay(5);
	gotoxy(10,10);
	cout<<"  ";
	delay(5);
	gotoxy(3,11);
	cout<<"  ";
	delay(5);
	gotoxy(8,11);
	cout<<"      ";
	delay(5);
	gotoxy(10,11);
	cout<<"  ";
	delay(5);
	gotoxy(10,12);
	cout<<"  ";
	delay(5);
	gotoxy(3,12);
	cout<<"  ";
	delay(5);
	gotoxy(8,12);
	cout<<"  ";
	delay(5);
	gotoxy(10,12);
	cout<<"  ";
	delay(5);
	gotoxy(3,13);
	cout<<"  ";
	delay(5);
	gotoxy(8,13);
	cout<<"  ";
	delay(5);
	gotoxy(10,13);
	cout<<"  ";
	delay(5);
	gotoxy(3,14);
	cout<<"  ";
	delay(5);
	gotoxy(8,14);
	cout<<"  ";
	delay(5);
	gotoxy(10,14);
	cout<<"  ";
	delay(5);
	gotoxy(10,15);
	cout<<"  ";
	delay(5);
	for (i=3;i<=11;i++)
		for (j=16;j<=27;j++)
		{	gotoxy(i,j);
			cout<<" ";
			delay(5);
		}
	gotoxy(3,28);
	cout<<" ";
	delay(5);
	gotoxy(4,28);
	cout<<"  ";
	delay(5);
	gotoxy(7,28);
	cout<<"  ";
	delay(5);
	gotoxy(9,28);
	cout<<" ";
	delay(5);
	gotoxy(10,28);
	cout<<"  ";
	delay(5);
	gotoxy(3,29);
	cout<<" ";
	delay(5);
	gotoxy(9,29);
	cout<<" ";
	delay(5);
	gotoxy(10,29);
	cout<<"   ";
	delay(5);
	gotoxy(3,30);
	cout<<" ";
	delay(5);
	gotoxy(4,30);
	cout<<"  ";
	delay(5);
	gotoxy(7,30);
	cout<<"   ";
	delay(5);
	gotoxy(10,30);
	cout<<"  ";
	delay(5);
	gotoxy(3,31);
	cout<<" ";
	delay(5);
	gotoxy(4,31);
	cout<<"  ";
	delay(5);
	gotoxy(7,31);
	cout<<"   ";
	delay(5);
	gotoxy(9,31);
	gotoxy(10,31);
	cout<<"  ";
	delay(5);
	cout<<" ";
	gotoxy(3,32);
	cout<<" ";
	delay(5);
	gotoxy(9,32);
	cout<<" ";
	delay(5);
	gotoxy(10,32);
	cout<<"  ";
	delay(5);
	gotoxy(3,33);
	cout<<"  ";
	delay(5);
	gotoxy(8,33);
	cout<<" ";
	delay(5);
	gotoxy(9,33);
	cout<<" ";
	delay(5);
	gotoxy(10,33);
	cout<<"  ";
	delay(5);
	gotoxy(3,34);
	cout<<" ";
	delay(5);
	gotoxy(4,34);
	cout<<" ";
	delay(5);
	gotoxy(5,34);
	cout<<" ";
	delay(5);
	gotoxy(7,34);
	cout<<" ";
	delay(5);
	gotoxy(8,34);
	cout<<" ";
	delay(5);
	gotoxy(9,34);
	cout<<" ";
	delay(5);
	gotoxy(10,34);
	cout<<"  ";
	delay(5);
	gotoxy(3,35);
	cout<<" ";
	delay(5);
	gotoxy(4,35);
	cout<<" ";
	delay(5);
	gotoxy(5,35);
	cout<<" ";
	delay(5);
	gotoxy(7,35);
	cout<<" ";
	delay(5);
	gotoxy(8,35);
	cout<<" ";
	delay(5);
	gotoxy(9,35);
	cout<<" ";
	delay(5);
	gotoxy(10,35);
	cout<<"  ";
	delay(5);
	gotoxy(3,36);
	cout<<" ";
	delay(5);
	gotoxy(4,36);
	cout<<" ";
	delay(5);
	gotoxy(5,36);
	cout<<" ";
	delay(5);
	gotoxy(7,36);
	cout<<" ";
	delay(5);
	gotoxy(8,36);
	cout<<" ";
	delay(5);
	gotoxy(9,36);
	cout<<" ";
	delay(5);
	gotoxy(10,36);
	cout<<"  ";
	delay(5);
	gotoxy(3,37);
	cout<<" ";
	delay(5);
	gotoxy(4,37);
	cout<<" ";
	delay(5);
	gotoxy(5,37);
	cout<<" ";
	delay(5);
	gotoxy(7,37);
	cout<<" ";
	delay(5);
	gotoxy(8,37);
	cout<<" ";
	delay(5);
	gotoxy(9,37);
	cout<<" ";
	delay(5);
	gotoxy(10,37);
	cout<<"  ";
	delay(5);
	gotoxy(3,38);
	cout<<" ";
	delay(5);
	gotoxy(4,38);
	cout<<" ";
	delay(5);
	gotoxy(5,38);
	cout<<" ";
	delay(5);
	gotoxy(7,38);
	cout<<" ";
	delay(5);
	gotoxy(8,38);
	cout<<" ";
	delay(5);
	gotoxy(9,38);
	cout<<" ";
	delay(5);
	gotoxy(10,38);
	cout<<"  ";
	delay(5);
	gotoxy(3,39);
	cout<<" ";
	delay(5);
	gotoxy(4,39);
	cout<<" ";
	delay(5);
	gotoxy(5,39);
	cout<<" ";
	delay(5);
	gotoxy(7,39);
	cout<<" ";
	delay(5);
	gotoxy(8,39);
	cout<<" ";
	delay(5);
	gotoxy(9,39);
	cout<<" ";
	delay(5);
	gotoxy(10,39);
	cout<<"  ";
	delay(5);
	gotoxy(3,40);
	cout<<" ";
	delay(5);
	gotoxy(4,40);
	cout<<" ";
	delay(5);
	gotoxy(5,40);
	cout<<" ";
	delay(5);
	gotoxy(7,40);
	cout<<" ";
	delay(5);
	gotoxy(8,40);
	cout<<" ";
	delay(5);
	gotoxy(9,40);
	cout<<" ";
	delay(5);
	gotoxy(10,40);
	cout<<"  ";
	delay(5);
	gotoxy(8,41);
	cout<<"    ";
	delay(5);
	gotoxy(3,41);
	cout<<"  ";
	delay(5);
	gotoxy(9,42);
	cout<<"     ";
	delay(5);
	gotoxy(3,42);
	cout<<" ";
	delay(5);
	//End of clear/////////////
	gotoxy(28,10);
	printf("%c",16);
	gotoxy(80,49);
	s=getch();
	while (s!=27)
	{
		gotoxy(32,10);
		textcolor(15);
		cprintf("1.   New Game");
		gotoxy(32,13);
		textcolor(15);
		cprintf("2.   Load Game");
		gotoxy(32,16);
		textcolor(15);
		cprintf("3.   Credits");
		if (s==80)
		{       if(index==1)
			{	for (i=29;i<49;i++)
				{
					for (j=35;j<49;j++)
					{
						gotoxy(i,j);
						cout<<"  ";
					}
				}
			}
			index=0;
			gotoxy(35,25);
			cout<<"         ";
			gotoxy(28,x);
			cout<<" ";
			x+=3;
			if(x>19)
			{	gotoxy(28,10);
				x=10;
			}
			gotoxy(28,x);
			printf("%c",16);
			gotoxy(80,49);
		}
		if (s==72)
		{
			if(index==1)
			{	for (i=29;i<49;i++)
				{
					for (j=35;j<49;j++)
					{
						gotoxy(i,j);
						cout<<"  ";
					}
				}
			}
			index=0;
			gotoxy(35,25);
			cout<<"         ";
			gotoxy(28,x);
			cout<<" ";
			x-=3;
			if (x<10)
			{	gotoxy(28,10);
				x=19;
			}
			cout<<" ";
			gotoxy(28,x);
			printf("%c",16);
			gotoxy(80,49);
		}
		if ( s==13 && x==10 )
		{
			index=2;
			gotoxy(32,10);
			textcolor(10);
			cprintf("\a1.   New Game");
			gotoxy(35,25);
			textcolor(14);
			cprintf("N");
			delay(50);
			gotoxy(36,25);
			cprintf("e");
			delay(50);
			gotoxy(37,25);
			cprintf("w ");
			delay(50);
			gotoxy(39,25);
			cprintf("G");
			delay(50);
			gotoxy(40,25);
			cprintf("a");
			delay(50);
			gotoxy(41,25);
			cprintf("m");
			delay(50);
			gotoxy(42,25);
			cprintf("e");
			delay(500);
		}
		if ( s==13 && x==13 )
		{
			gotoxy(32,13);
			textcolor(10);
			cprintf("\a2.   Load Game");
			gotoxy(35,25);
			textcolor(14);
			cprintf("L");
			delay(50);
			gotoxy(36,25);
			cprintf("o");
			delay(50);
			gotoxy(37,25);
			cprintf("a");
			delay(50);
			gotoxy(38,25);
			cprintf("d ");
			delay(50);
			gotoxy(40,25);
			cprintf("G");
			delay(50);
			gotoxy(41,25);
			cprintf("a");
			delay(50);
			gotoxy(42,25);
			cprintf("m");
			delay(50);
			gotoxy(43,25);
			cprintf("e");
			delay(50);
		}
		if (s==13 && x==16 )
		{
			cout<<"";
			gotoxy(32,16);
			textcolor(10);
			cprintf("\a3.   Credits");
			for (i=32,j=35;i<50,j<49;i++,j++)
			{       index=1;
				gotoxy(31,35);
				textcolor(13);
				cprintf("É");
				gotoxy(i,35);
				cprintf("Í");
				delay(20);
				gotoxy(i,48);
				cprintf("Í");
				delay(20);
				gotoxy(46,35);
				cprintf("»");
				gotoxy(31,j);
				cprintf("º");
				delay(20);
				gotoxy(31,48);
				cprintf("È");
				gotoxy(46,j);
				cprintf("º");
				delay(20);
			}
			gotoxy(46,48);
			cout<<"¼";
			gotoxy(39,41);
			cprintf("3");
			delay(350);
			gotoxy(39,41);
			cprintf("2");
			delay(350);
			gotoxy(39,41);
			cprintf("1");
			delay(350);
			gotoxy(39,41);
			cprintf(" ");
			delay(50);
			textcolor(15);
			gotoxy(34,38);
			textcolor(15);
				delay(350);
				cout<<"A";
				delay(25);
				cout<<"n";
				delay(25);
				cout<<"o";
				delay(25);
				cout<<"u";
				delay(25);
				cout<<"s";
				delay(25);
				cout<<"h";
				delay(25);
				cout<<"e";
				delay(25);
			gotoxy(36,40);
				cout<<"M";
				delay(25);
				cout<<"a";
				delay(25);
				cout<<"n";
				delay(25);
				cout<<"s";
				delay(25);
				cout<<"o";
				delay(25);
				cout<<"u";
				delay(25);
				cout<<"r";
				delay(25);
				cout<<"i";
				delay(25);
			gotoxy(36,42);
				textcolor(18);
				cprintf("  * * *");
			gotoxy(34,44);
				delay(25);
				cout<<"R";
				delay(25);
				cout<<"e";
				delay(25);
				cout<<"z";
				delay(25);
				cout<<"a";
				delay(25);
			gotoxy(36,46);
				cout<<"H";
				delay(25);
				cout<<"o";
				delay(25);
				cout<<"s";
				delay(25);
				cout<<"e";
				delay(25);
				cout<<"i";
				delay(25);
				cout<<"n";
				delay(25);
				cout<<"i";
				delay(25);
		}
		if (s==13 && x==19)
		{       cout<<"\a";
			return 0;
		}
		s=getch();
	}
	getch();
	return 0;
}
