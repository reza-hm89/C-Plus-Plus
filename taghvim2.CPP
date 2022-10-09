#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
void calendar();
void convert1();
void convert2();
void exit();
char k;
int main()
{
	gotoxy(30,15);
	cout<<"ENTER RA BEZANID";
   while(k!=13)
   {
	k=getch();
	gotoxy(28,17);
	cout<<"ENTER RA BEZANID";
   }
   clrscr();
	int y=14;
	gotoxy(25,14);
	cout<<"   1.TAGHVIM";
	gotoxy(25,15);
	cout<<"   2.TABDILE TAGHVIM";
	gotoxy(25,16);
	cout<<"   3.MOHASEBEYE TEDAD ROOZHAYE GOZASHTE AZ SAL";
   gotoxy(25,17);
   cout<<"   4.KHAREJ SHODAN AZ BARNAME";
	while(k!=27)
	{
	 k=getch();
       gotoxy(25,y);
       cout<<"   ";
		switch(k)
		{
			case 80:
			if(y==17)
			{
				y=14;
			}
			else
				y++;
				break;
			case 72:
			if(y==14)
			{
			  y=17;
			}
			else
				y--;
				break;
	 case 13:
	 if(y==14)
	 {
		calendar();
	    return 0;
	 }
	 if(y==15)
	 {
		convert1();
	    return 0;
    }
	 if(y==16)
	 {
		convert2();
	    return 0;
	 }
	 if(y==17)
	 {
		exit();
	    return 0;
	 }

		}
		gotoxy(25,y);
		cout<<"=>";

	 }


}
void calendar()
{
	clrscr();
	int y=2,i,day=31,n,x1=30,lim=50,y1=2,month;
   gotoxy(25,7);
	cout<<" saturday = 0";
	gotoxy(25,8);
	cout<<"   sunday = 1";
	gotoxy(25,9);
	cout<<"   monday = 2";
	gotoxy(25,10);
	cout<<"  tuesday = 3";
	gotoxy(25,11);
	cout<<"wednesday = 4";
	gotoxy(25,12);
	cout<<" thursday = 5";
	gotoxy(25,13);
	cout<<"   friday = 6";
	gotoxy(25,16);
	cout<<"ROOZ RA ENTEKHAB KONID:";
   gotoxy(50,16);
   cin>>n;
   gotoxy(50,16);
   while(n>6 || n<0)
   {
   gotoxy(50,16);
   cout<<"  ";
   gotoxy(25,18);
   cout<<"ADAD VARED SHODE BAYAD AZ 0 TA 6 BASHAD";
   gotoxy(50,16);
   cin>>n;
   }
   if(n>=0 && n<=6)
   {
   gotoxy(25,18);
   cout<<"                                           ";
   gotoxy(25,18);
   cout<<"BARAYE DIDANE TAGHVIM ENTER RA BEZANID";
   getch();
   }
   int x=3*n+30;
	clrscr();
   for(month=1;month<=12;month++)
   {  if(month>=1 && month<=3)
	{
	gotoxy(2,2);
	cout<<"fasl: bahar";
	gotoxy(15,7);
	cout<<"Farvardin";
	gotoxy(15,15);
	cout<<"Ordibehesht";
	gotoxy(15,23);
	cout<<"Khordad";
      }
      if(month>=4 && month<=6)
      {
	 gotoxy(2,2);
	 cout<<"fasl: tabestan";
	 gotoxy(15,7);
	 cout<<"Tir";
	 gotoxy(15,15);
	 cout<<"Mordad";
	 gotoxy(15,23);
	 cout<<"Shahrivar";
      }
      if(month>=7 && month<=9)
      {
	gotoxy(2,2);
	 cout<<"fasl: paeez";
	 gotoxy(15,7);
	 cout<<"Mehr";
	 gotoxy(15,15);
	 cout<<"Aban";
	 gotoxy(15,23);
	 cout<<"Azar";
      }

      if(month>=10 && month<=12)
      {
	gotoxy(2,2);
	 cout<<"fasl: zemestan";
	 gotoxy(15,7);
	 cout<<"Dey";
	 gotoxy(15,15);
	 cout<<"Bahman";
	 gotoxy(15,23);
	 cout<<"Esfand";
      }
		gotoxy(x1,y1);
		cout<<"sa";
		gotoxy(x1+3,y1);
		cout<<"su";
		gotoxy(x1+6,y1);
		cout<<"mo";
		gotoxy(x1+9,y1);
		cout<<"tu";
		gotoxy(x1+12,y1);
		cout<<"we";
		gotoxy(x1+15,y1);
		cout<<"th";
		gotoxy(x1+18,y1);
		cout<<"fr";
      y+=3;
       if(month==7 || month==12)
       {
		 day--;
       }
       for(i=1;i<=day;i++)
       {
			gotoxy(x,y);
			cout<<i;
			x+=3;
			if(x>=lim)
			{
					x=30;
					y++;
			}
       }
      y++;
      x1=30;
      y1+=9;
      if(month%3==0)
      {
	getch();
		clrscr();
		y1=2;
		y=2;
      }
   }
}
void convert1()
{
	clrscr();
   int y=14;
   gotoxy(30,14);
   cout<<"   1.ghamari => shamsi";
   gotoxy(30,16);
   cout<<"   2.shamsi => ghamari";
   while(k!=27)
   {
	k=getch();
      gotoxy(30,y);
      cout<<"   ";
      switch(k)
      {
	case 80:
	 if(y==16)
	 {
		y=14;
	 }
	 else
	 y+=2;
		break;
	 case 72:
	 if(y==14)
	 {
		y=16;
	 }
	 else
	 y-=2;
		break;
	 case 13:
	 if(y==14)
	 {
		clrscr();
			int n,a,b,c,d,e;
	    gotoxy(30,14);
	    cout<<"ghamari:";
			   cin>>n;
				a=n/1000;
			a*=30;
			   b=n%1000;
			c=b/100;
			c*=3;
			d=b%100;
			e=d/30;
			   e*=1;
	    n=n-a-c-e+1;
	    gotoxy(30,16);
			cout<<"shamsi:"<<n;
			getch();
	 }
	 if(y==16)
	 {
			clrscr();
			int n,a,b,c,d,e;
	    gotoxy(30,14);
	    cout<<"shamsi:";
			   cin>>n;
				a=n/1000;
			a*=30;
			   b=n%1000;
			c=b/100;
			c*=3;
			d=b%100;
			e=d/30;
			   e*=1;
	    n=n+a+c+e+1;
	    gotoxy(30,16);
			cout<<"ghamari:"<<n;
			getch();
	 }
      }
      gotoxy(30,y);
      cout<<"=>";
   }
}
void convert2()
{
	clrscr();
   int month,day,p;
   gotoxy(30,14);
   cout<<"day:";
   cin>>day;
   while(day>31 || day<1)
   {
	gotoxy(34,14);
      cout<<"   ";
      gotoxy(30,14);
      cout<<"dey:";
      cin>>day;
   }
   gotoxy(30,16);
   cout<<"month:";
   cin>>month;
   while(month>12 || month<1)
   {
	gotoxy(36,16);
	cout<<"   ";
	gotoxy(30,16);
	cout<<"month:";
	cin>>month;
   }
   if(month<=6)
   {
	p=(month-1)*31+day;
   }
   else
   {
	p=(month-1)*30+6+day;
   }
   gotoxy(15,18);
   cout<<"tedade roozhaee gozashte az sal:"<<p<<" rooz";
   getch();

}
void exit()
{
	clrscr();
   int y=15;
   gotoxy(20,12);
   cout<<"AYA MIKHAHID AZ BARNAME KHAREJ SHAVID?";
   gotoxy(20,15);
   cout<<"  BALE";
   gotoxy(20,16);
   cout<<"  KHEIR";
   while(k!=27)
   {
    k=getch();
    gotoxy(20,y);
    cout<<"  ";
    switch(k)
    {
	case 80:
      if(y==16)
      {
	y=15;
      }
      else y++;
	break;
      case 72:
      if(y==15)
      {
	y=16;
      }
      else y--;
	break;
      case 13:
      if(y==15)
      {
	exit(0);
      }
	break;
      if(y==16)
      {
	exit(1);
      }
		break;
    }
    gotoxy(20,y);
    cout<<"=>";
   }

}


