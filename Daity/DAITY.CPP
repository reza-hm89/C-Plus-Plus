#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
char a[100][100];
int b[100],c[100];
void vahed()
{
	b[1]=210;
	strcpy(a[1],"Esprial miveh");
	b[2]=210;
	strcpy(a[2],"Espiral shokolat");
	b[3]=250;
	strcpy(a[3],"Espriral talebi");
	b[4]=250;
	strcpy(a[4],"Espiral yakhi");
	b[5]=240;
	strcpy(a[5],"Koko piral");
	b[6]=200;
	strcpy(a[6],"Viferi");
	b[7]=130;
	strcpy(a[7],"Aroosaki");
	b[8]=200;
	strcpy(a[8],"Livani 2 rang");
	b[9]=110;
	strcpy(a[9],"Livani sadeh");
	b[10]=200;
	strcpy(a[10],"Livani neskafeh 80");
	b[11]=270;
	strcpy(a[11],"Livani neskafeh LX");
	b[12]=270;
	strcpy(a[12],"Livani Karamel LX");
	b[13]=270;
	strcpy(a[13],"Magnom");
	b[14]=270;
	strcpy(a[14],"Admiral");
	b[15]=190;
	strcpy(a[15],"Ghifi tootfarangi");
	b[16]=190;
	strcpy(a[16],"Ghifi vanili");
	b[17]=150;
	strcpy(a[17],"1 Litri zarfi");
	b[18]=180;
	strcpy(a[18],"1 Litri pakati");
	b[19]=300;
	strcpy(a[19],"1 Litri lx karamel");
	b[20]=300;
	strcpy(a[20],"1 Litri lx tootfarangi");
	b[21]=350;
	strcpy(a[21],"1 Litri lx zafaran");
	b[22]=400;
	strcpy(a[22],"1 Litri lx shatoot");
	b[23]=450;
	strcpy(a[23],"1 Litri lx majoon");
	b[24]=200;
	strcpy(a[24],"2 Litri zarfi");
	b[25]=200;
	strcpy(a[25],"2 Litri pakati");
	b[26]=240;
	strcpy(a[26],"Zing Zing");
	b[27]=250;
	strcpy(a[27],"Akalifa");
	b[28]=250;
	strcpy(a[28],"Rashin");
	b[29]=250;
	strcpy(a[29],"Piano");
	b[30]=300;
	strcpy(a[30],"Cake bastani");
	b[31]=200;
	strcpy(a[31],"Deser miveh");
	b[32]=200;
	strcpy(a[32],"Choobi 3 rang");
	b[33]=300;
	strcpy(a[33],"Armoos");
	b[34]=200;
	strcpy(a[34],"Mivei yakhi");
	b[35]=100;
	strcpy(a[35],"Rookesh shokolat 76");
	b[36]=100;
	strcpy(a[36],"Rookesh shokolat 51");
	b[37]=200;
	strcpy(a[37],"Rookesh miveh");
	b[38]=300;
	strcpy(a[38],"1 Litri lx ghahve");
}
////////////////////////////////////////////////////////////////////
void list()
{
	textbackground(11);
	int i,j,y=5,x=12;
	clrscr();
	vahed();
	textcolor(8);

	for (i=1;i<80;i++)
	{
		gotoxy(i,1);
		cprintf("Э");
		gotoxy(i,45);
		cprintf("Э");
		gotoxy(i,49);
		cprintf("Э");
	}
	for (i=1;i<50;i++)
	{
		gotoxy(1,i);
		cprintf("К");
		gotoxy(40,i);
		cprintf("К");
		gotoxy(80,i);
		cprintf("К");
	}
	gotoxy(1,1);
	cprintf("Щ");
	gotoxy(1,49);
	cprintf("Ш");
	gotoxy(80,1);
	cprintf("Л");
	gotoxy(80,49);
	cprintf("М");
	gotoxy(40,1);
	cprintf("Ы");
	gotoxy(40,49);
	cprintf("Ъ");
	gotoxy(40,45);
	cprintf("Ю");
	gotoxy(1,45);
	cprintf("Ь");
	gotoxy(80,45);
	cprintf("Й");
	for (i=1;i<=38;i++)
	{
		textcolor(8);
		gotoxy(x,y);
		cprintf("%d",b[i]);
		gotoxy(x+5,y);
		cprintf("%s",a[i]);
		y+=2;
		if (i==19){
		x=52;
		y=5;}
	}
	char ch;
	y=5;
	x=3;
	i=1;
	short unsigned int z=0,z1=0,num=1,n=0;
	gotoxy(x,y);
	printf("->");
	gotoxy(52,47);
	cprintf("Created by Reza H.M");
	ch=getch();
	while (ch!=27)
	{
	switch (ch) {
	case 80: gotoxy(x,y);
		 cout<<"  ";
		 i++;
		 if (x==3)
		 if (i>19) i=1;
		 if (x==43)
		 if (i>38) i=20;
		 y+=2;
		 if (y>41) y=5;
		 gotoxy(x,y);
		 printf("->");
		 break;
	case 72: gotoxy(x,y);
		 printf("  ");
		 i--;
		 if (x==3)
		 if (i<1) i=19;
		 if (x==43)
		 if (i<20) i=38;
		 y-=2;
		 if (y<5) y=41;
		 gotoxy(x,y);
		 printf("->");
		 break;
	case 77: gotoxy(x,y);
		 printf("  ");
		 z++;
		 x=43;
		 if (z==1) i+=19;
		 gotoxy(x,y);
		 printf("->");
		 z1=0;
		 break;
	case 75: gotoxy(x,y);
		 printf("  ");
		 z1++;
		 x=3;
		 if (z1==1) i-=19;
		 gotoxy(x,y);
		 printf("->");
		 z=0;
		 break;
	case 13: gotoxy(x+2,y);
		 textattr(0);
		 cprintf("ллллл");
		 gotoxy(x+3,y);
		 textattr(3);
		 cscanf("%d",&n);
		 if (n!=0 && n<=100)
		 {
		 num=n;
		 c[i]=b[i]*num;
		 n=0;
		 }
		 else if (num!=n)
		 {
			gotoxy(x+2,y);
			textattr(3);
			cprintf("ллллл");
			c[i]=0;
			n=0;
		 }
		 break;
	}
	gotoxy(80,49);
	ch=getch();
	unsigned long sum=0;
	for (int count=1;count<=38;count++)
		if (c[count])
			sum+=c[count];
	gotoxy(3,47);
	printf("                   ");
	gotoxy(3,47);
	cout<<"sum: "<<sum;
	}
}
void main()
{
	list();
}