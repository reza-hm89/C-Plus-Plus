#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>

void menu();
void enter_d();
void show_list();
void show_unit();
void unit_selection();
void enter_grade();
void search();
void vahed();
void edit();
int tedad,ok,ok2;

struct  student{
	char name[30],family[30],pedar[50];
	long int shsh,code,id;
	int dars[2][50];
	char namedars[50][20];
	int avg;
	};
struct	unit{
	int code;
	char dars[20];
	};
	student a[20],a1;
	unit 	b[40];
	int n,c[100];
void menu()
{
setgraphmode(getgraphmode());
cleardevice();
setbkcolor(6);
setfillstyle(8,4);
bar(1,1,640,480);
settextstyle(7,0,4);
setcolor(8);
outtextxy(225,15,"Enter data");
setcolor(8);
outtextxy(240,70,"Show list");
outtextxy(220,125,"Show units");
outtextxy(202,180,"Unit selection");
outtextxy(202,235," Enter grades");
outtextxy(285,300,"Edit");
outtextxy(270,365,"Search");
outtextxy(285,430,"Exit");
}
////////////////////////////////////////////////////////////
void arrow()
{
char ch=5;
int y=0;

while (ch!=27)
{
	if (ch==80 || ch==72)
	{
		setcolor(8);
		switch (y) {
		case 1:outtextxy(225,15,"Enter data");
		break;
		case 2:outtextxy(240,70,"Show list");
		break;
		case 3:outtextxy(220,125,"Show units");
		break;
		case 4:outtextxy(202,180,"Unit selection");
		break;
		case 5:outtextxy(202,235," Enter grades");
		break;
		case 6:outtextxy(285,300,"Edit");
		break;
		case 7:outtextxy(270,365,"Search");
		break;
		case 8:outtextxy(285,430,"Exit");
		}
	switch (ch){
	case 80:y++;
		break;
	case 72:y--;
	break;
	}
	if (y>8)
		y=1;
	if (y<1)
		y=8;
	}
	setcolor(14);
	switch (y) {
		case 1:outtextxy(225,15,"Enter data");
		break;
		case 2:outtextxy(240,70,"Show list");
		break;
		case 3:outtextxy(220,125,"Show units");
		break;
		case 4:outtextxy(202,180,"Unit selection");
		break;
		case 5:outtextxy(202,235," Enter grades");
		break;
		case 6:outtextxy(285,300,"Edit");
		break;
		case 7:outtextxy(270,365,"Search");
		break;
		case 8:outtextxy(285,430,"Exit");
	}
	if (ch==13)
	{
		switch (y){
		case 1:enter_d();
		break;
		case 2:show_list();
		break;
		case 3:show_unit();
		break;
		case 4:unit_selection();
		break;
		case 5:enter_grade();
		break;
		case 6:edit();
		break;
		case 7:search();
		break;
		case 8:exit(0);
		break;
		}
	}
	ch=getch();
}
}
//////////////////////////////////////////////////////////
void enter_d()
{
int i;
restorecrtmode();
textmode(LASTMODE);
clrscr();
cout<<"Enter numbers of students: ";
cin>>n;
	for (i=1;i<=n;i++)
	{
	ok=1;
	clrscr();
	gotoxy(30,1);
	cprintf("*** Enter Your Data ***");
	gotoxy(1,3);
	cprintf("First Name: ");
	cin>>(a[i].name);
	gotoxy(1,5);
	cprintf("Last Name:");
	cin>>(a[i].family);
	gotoxy(1,7);
	cprintf("Father Name:");
	cin>>(a[i].pedar);
	gotoxy(1,9);
	cprintf("shomare shenasname:");
	cin>>a[i].shsh;
	gotoxy(1,11);
	cprintf("shomare daneshjooei:");
	cin>>a[i].id;
	gotoxy(1,13);
	cprintf("code melli:");
	cin>>a[i].code;
	}
	menu();
}
////////////////////////////////////////////////////////////
void edit()
{
	restorecrtmode();
	textmode(LASTMODE);
	clrscr();
	long int id;
	int i,j,sw=0;
	char ch,ans='y';
	if (ok==1)
	{
	while (ans=='y')
	{
	sw=0;
	cout<<"enter your ID: ";
	cin>>id;
	for (i=1;i<=n;i++)
	{
		if (id==a[i].id)
		{
			sw=1;
			j=i;
			gotoxy(1,5);
			cout<<"Name: "<<a[i].name;
			gotoxy(25,5);
			cout<<"Last name: "<<a[i].family;
			gotoxy(50,5);
			cout<<"Father: "<<a[i].pedar;
			gotoxy(1,7);
			cout<<"sh.sh: "<<a[i].shsh;
			gotoxy(25,7);
			cout<<"ID: "<<a[i].id;
			gotoxy(50,7);
			cout<<"code melli: "<<a[i].code;
		}
	}
	if (sw==1)
	{
	gotoxy(10,10);
	cout<<"Edit name";
	gotoxy(10,12);
	cout<<"Edit family";
	gotoxy(10,14);
	cout<<"Edit father's name";
	gotoxy(10,16);
	cout<<"Edit shomare shenasname";
	gotoxy(10,18);
	cout<<"Edit ID";
	gotoxy(10,20);
	cout<<"Edit code melli";

	gotoxy(5,10);
	cout<<"->";
	int y=10;
	char name[20];
	long int intg;
	while (ch!=27)
	{
		ch=getch();
		if (ch==72)
		{
			gotoxy(5,y);
			cout<<"  ";
			y-=2;
			if (y<10) y=20;
			gotoxy(5,y);
			cout<<"->";
		}
		else if (ch==80)
		{
			gotoxy(5,y);
			cout<<"  ";
			y+=2;
			if (y>20) y=10;
			gotoxy(5,y);
			cout<<"->";
		}
		if (ch==13)
		{
		  switch (y)
		  {
			case 10: gotoxy(7,5);
				 cout<<"              ";
				 gotoxy(7,5);
				 cin>>name;
				 strcpy(a[j].name,name);
				 gotoxy(7,5);
				 cout<<a[j].name;
				 break;
			case 12: gotoxy(36,5);
				 cout<<"              ";
				 gotoxy(36,5);
				 cin>>name;
				 strcpy(a[j].family,name);
				 gotoxy(36,5);
				 cout<<a[j].family;
				 break;
			case 14: gotoxy(58,5);
				 cout<<"              ";
				 gotoxy(58,5);
				 cin>>name;
				 strcpy(a[j].pedar,name);
				 gotoxy(58,5);
				 cout<<a[j].pedar;
				 break;
			case 16: gotoxy(8,7);
				 cout<<"              ";
				 gotoxy(8,7);
				 cin>>intg;
				 a[j].shsh=intg;
				 gotoxy(8,7);
				 cout<<a[j].shsh;
				 break;
			case 18: gotoxy(29,7);
				 cout<<"              ";
				 gotoxy(29,7);
				 cin>>intg;
				 a[j].id=intg;
				 gotoxy(29,7);
				 cout<<a[j].id;
				 break;
			case 20: gotoxy(62,7);
				 cout<<"              ";
				 gotoxy(62,7);
				 cin>>intg;
				 a[j].code=intg;
				 gotoxy(62,7);
				 cout<<a[j].code;
				 break;
		  }
		}
	}//end sw
	}
	clrscr();
	cout<<"Next student(y/n)? ";
	cin>>ans;
	}
	}//if ok
	else cout<<"First Enter Data...";
	getch();
	menu();
}
////////////////////////////////////////////////////////////
void show_list()
{
	int y=4,num,i;
	char t[20];
	restorecrtmode();
	textmode(LASTMODE);
	clrscr();
	cout<<"1.Sort by name\n";
	cout<<"2.Sort by family\n";
	cout<<"3.Sort by ID";
	cout<<"\n\nEnter your sort(1-3): ";
	cin>>num;
	if (num==1)
	{
		for (i=1;i<=n;i++)
		{
			for (int j=1;j<n;j++)
				if (strcmp(a[j].name,a[j+1].name)>0)
				{
					a1=a[j];
					a[j]=a[j+1];
					a[j+1]=a1;
				}
		}
	}
	else if (num==2)
	{
		for (i=1;i<=n;i++)
		{
			for (int j=1;j<n;j++)
				if (strcmp(a[j].family,a[j+1].family)>0)
				{
					a1=a[j];
					a[j]=a[j+1];
					a[j+1]=a1;
				}
		}
	}
	else if (num==3)
	{
		for (i=1;i<=n;i++)
		{
			for (int j=1;j<n;j++)
				if (a[j].id>a[j+1].id)
				{
					a1=a[j];
					a[j]=a[j+1];
					a[j+1]=a1;
				}
		}
	}
	clrscr();
	gotoxy(10,1);
	cprintf("Name");
	gotoxy(20,1);
	cprintf("Family");
	gotoxy(30,1);
	cprintf("Father");
	gotoxy(40,1);
	cprintf("Sh.sh");
	gotoxy(50,1);
	cprintf("ID");
	gotoxy(60,1);
	cprintf("sh.melli");
	gotoxy(70,1);
	cprintf("Average");
	for (i=1;i<=n;i++)
	{
		gotoxy(10,y);
		cout<<a[i].name;
		gotoxy(20,y);
		cout<<a[i].family;
		gotoxy(30,y);
		cout<<a[i].pedar;
		gotoxy(40,y);
		cout<<a[i].shsh;
		gotoxy(50,y);
		cout<<a[i].id;
		gotoxy(60,y);
		cout<<a[i].code;
		gotoxy(70,y);
		cout<<a[i].avg;
		y+=2;
	}
	getch();
	menu();
}
////////////////////////////////////////////////////////////
void vahed()
{
	b[1].code=100;
	strcpy(b[1].dars,"Ryazi 1");
	b[2].code=101;
	strcpy(b[2].dars,"Fizik 1");
	b[3].code=102;
	strcpy(b[3].dars,"Ryazi 2");
	b[4].code=103;
	strcpy(b[4].dars,"Fizik 2");
	b[5].code=104;
	strcpy(b[5].dars,"barname sazi 1");
	b[6].code=105;
	strcpy(b[6].dars,"barname sazi 2");
	b[7].code=106;
	strcpy(b[7].dars,"sakhteman gossaste");
	b[8].code=107;
	strcpy(b[8].dars,"sakhteman dadeh");
	b[9].code=108;
	strcpy(b[9].dars,"moadelat difranseil");
	b[10].code=109;
	strcpy(b[10].dars,"amar va ehtemalat");
	b[11].code=110;
	strcpy(b[11].dars,"ryazi mohandesi");
	b[12].code=111;
	strcpy(b[12].dars,"madar 1");
	b[13].code=112;
	strcpy(b[13].dars,"madar 2");
	b[14].code=113;
	strcpy(b[14].dars,"tarbiyat 1");
	b[15].code=114;
	strcpy(b[15].dars,"tarbiyat 2");
	b[16].code=115;
	strcpy(b[16].dars,"akhlagh");
	b[17].code=116;
	strcpy(b[17].dars,"farsi");
	b[18].code=117;
	strcpy(b[18].dars,"zaban");
	b[19].code=118;
	strcpy(b[19].dars,"zaban takhassosi");
	b[20].code=119;
	strcpy(b[20].dars,"az fizik 1");
	b[21].code=120;
	strcpy(b[21].dars,"az fizik 2");
	b[22].code=121;
	strcpy(b[22].dars,"az madar");
	b[23].code=122;
	strcpy(b[23].dars,"ossool micro");
	b[24].code=123;
	strcpy(b[24].dars,"payegah dadeh");
	b[25].code=124;
	strcpy(b[25].dars,"madar manteghi");
	b[26].code=125;
	strcpy(b[26].dars,"shabakehay PC");
	b[27].code=126;
	strcpy(b[27].dars,"system amel");
	b[28].code=127;
	strcpy(b[28].dars,"mohandesi narmafzar");
	b[29].code=128;
	strcpy(b[29].dars,"hoosh masnooei");
	b[30].code=129;
	strcpy(b[30].dars,"gerafik PC");
}
////////////////////////////////////////////////////////////
void unit_selection()
{
	int i,j,y=5,x=10;
	long int id;
	char ans='y';
	tedad=0;
	restorecrtmode();
	textmode(LASTMODE);
	if (ok==1)
	{
	while (ans=='y')
	{
	ok2=1;
	clrscr();
	vahed();
	cout<<"Enter your id: ";
	cin>>id;
	tedad=0;
	y=5;
	x=10;
	for (i=1;i<=n;i++)
	if (id==a[i].id)
	{
	j=i;
	for (i=1;i<=30;i++)
	{
		gotoxy(x,y);
		cprintf("%d",b[i].code);
		gotoxy(x+5,y);
		cprintf("%s",b[i].dars);
		y+=2;
		if (i==15){
		x=50;
		y=5;}
	}

	char ch;
	y=5;
	x=5;
	i=1;
	int z=0,z1=0,y1;
	gotoxy(x,y);
	ch=getch();
	cout<<"->";
	while (ch!=27)
	{
	switch (ch) {
	case 80: gotoxy(x,y);
		 cout<<"  ";
		 y+=2;
		 i++;
		 if (x==5)
		 if (i>15) i=1;
		 if (x==45)
		 if (i>30) i=15;
		 if (y>33) y=5;
		 gotoxy(x,y);
		 cout<<"->";
		 break;
	case 72: gotoxy(x,y);
		 cout<<"  ";
		 i--;
		 if (x==5)
		 if (i<1) i=15;
		 if (x==45)
		 if (i<15) i=30;
		 y-=2;
		 if (y<5) y=33;
		 gotoxy(x,y);
		 cout<<"->";
		 break;
	case 77: gotoxy(x,y);
		 cout<<"  ";
		 z++;
		 x=45;
		 if (z==1) i+=15;;
		 gotoxy(x,y);
		 cout<<"->";;
		 z1=0;
		 break;
	case 75: gotoxy(x,y);
		 cout<<"  ";
		 z1++;
		 x=5;
		 if (z1==1) i-=15;
		 gotoxy(x,y);
		 cout<<"->";
		 z=0;
		 break;
	case 13: if (y1!=y)   {
		 y1=y;
		 gotoxy(x+4,y1);
		 tedad++;
		 cout<<"û";
		 strcpy(a[j].namedars[tedad],b[i].dars);  }
		 break;
	}
	ch=getch();
	}
	}
	c[j]=tedad;
	clrscr();
	cout<<"Next student(y/n)?";
	cin>>ans;
	}
	}//if ok
	else cout<<"First Enter Data...";
	getch();
	menu();
}
///////////////////////////////////////////////////////////
void show_unit()
{
	int i,j,id,y=7;
	char ans='y';
	restorecrtmode();
	textmode(LASTMODE);
	if (ok==1)
	{
	while (ans=='y')
	{
	clrscr();
	cout<<"Enter ID: ";
	cin>>id;
	for (i=1;i<=n;i++)
	{
		if (a[i].id==id)
		{
			y=7;
			gotoxy(5,3);
			cout<<"Unit";
			gotoxy(10,3);
			cout<<"Grade";
			gotoxy(20,3);
			cout<<"Dars";
			for (int j1=1;j1<=79;j1++)
			{
				gotoxy(j1,4);
				cout<<"-";
			}
			for (j=1;j<=tedad;j++)
			{
				gotoxy(5,y);
				cout<<a[i].dars[0][j];
				gotoxy(10,y);
				cout<<a[i].dars[1][j];
				gotoxy(20,y);
				cout<<a[i].namedars[j];
				y+=2;
			}
		}
	}
	cout<<"\n\n\nNext student(y/n)? ";
	cin>>ans;
	}
	}//if ok
	else cout<<"First Enter Data";
	getch();
	menu();
}
 ////////////////////////////////////////////////////////
void enter_grade()
{
	int id,i,j,s1=0,sum=0;
	char ans='y';
	restorecrtmode();
	textmode(LASTMODE);
	if (ok2==1) {
	while (ans=='y')
	{
	clrscr();
	s1=0; sum=0;
	cout<<"Enter your ID: ";
	cin>>id;
	for (i=1;i<=n;i++)
	{
		if (id==a[i].id)
		{       int y=8;
			gotoxy(5,5);
			cout<<"Unit";
			gotoxy(15,5);
			cout<<"Grade";
			gotoxy(25,5);
			cout<<"Dars";
			gotoxy(4,6);
			cout<<"-------------------------------------------------";
			for(j=1;j<=c[i];j++)
			{
				gotoxy(25,y);
				cout<<a[i].namedars[j];
				y+=2;
			}
			int x=7;
			y=8;
			for (j=1;j<=c[i];j++)
			{
			gotoxy(x,y);
			cin>>a[i].dars[0][j];
			s1+=a[i].dars[0][j];
			gotoxy(x+10,y);
			cin>>a[i].dars[1][j];
			y+=2;
			sum+=((a[i].dars[1][j])*(a[i].dars[0][j]));
			}
			a[i].avg=sum/s1;
		}
	}
	clrscr();
	cout<<"Next student(y/n)? ";
	cin>>ans;
	}
	}
	else cout<<"First select unit...";
	getch();
	menu();
}
//////////////////////////////////////////////////////////////
void search()
{
	int id,k;
	char ans='y',del;
	restorecrtmode();
	textmode(LASTMODE);
	if (ok==1)
	{
	while (ans=='y')
	{
	clrscr();
	cout<<"Enter Id for search: ";
	cin>>id;
	for (int i=1;i<=n;i++)
	{
		if(id==a[i].id)
		{
			k=i;
			gotoxy(1,3);
			cprintf("First Name: ");
			cout<<(a[i].name);
			gotoxy(1,5);
			cprintf("Last Name:");
			cout<<(a[i].family);
			gotoxy(1,7);
			cprintf("Father Name:");
			cout<<(a[i].pedar);
			gotoxy(1,9);
			cprintf("shomare shenasname:");
			cout<<a[i].shsh;
			gotoxy(1,11);
			cprintf("shomare daneshjooei:");
			cout<<a[i].id;
			gotoxy(1,13);
			cprintf("code melli:");
			cout<<a[i].code;
			gotoxy(40,3);
			cout<<"Unit";
			gotoxy(45,3);
			cout<<"grade";
			gotoxy(55,3);
			cout<<"Dars";
			gotoxy(35,4);
			cout<<"------------------------------";
			int x=40,y=5;
			for (int j=1;j<=c[i];j++)
			{
				gotoxy(x,y);
				cout<<a[i].dars[0][j];
				gotoxy(x+5,y);
				cout<<a[i].dars[1][j];
				gotoxy(x+15,y);
				cout<<a[i].namedars[j];
				y+=2;
			}
		}
	}
	getch();
	gotoxy(1,30);
	cout<<"Do you want to delete this student(y/n)? ";
	cin>>del;
	if (del=='y')
	{
		for (int j=k;j<n;j++)
			a[j]=a[j+1];
		n--;
	}
	clrscr();
	cout<<"Next student(y/n)?";
	cin>>ans;
	}
	}// if ok
	else cout<<"First Enter Data...";
	getch();
	menu();
}
////////////////////////////////////////////////////////////
void main()
{
	int driver=DETECT,mode;
	initgraph(&driver,&mode,"c:\\tc\\bgi");
	menu();
	arrow();
	getch();
}