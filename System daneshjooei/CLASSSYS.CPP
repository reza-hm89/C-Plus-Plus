#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
//=================================================
void menu();
void enter_d();
void show_list();
void show_unit();
void unit_selection();
void enter_grade();
void search();
void vahed();
void edit();
//=================================================
struct	unit
{
	int code;
	char dars[20];
};
//=================================================
class  student
{
	char name[30],family[30],pedar[50];
	long int shsh,code,id;
	int avg,DarsCnt;
	unit myunit[20];

	public:
		int dars[2][50];
		char namedars[50][20];
		student() { DarsCnt=0; }
		void input();
		void edit(int);
		void show1();
		void show2(int);
		void show3();
		void SelectUnit(char dars[])
		{
			strcpy(namedars[DarsCnt++],dars);
		}
		int Ret_NumOfDars()
		{
			return DarsCnt;
		}
		void SetAvg(float a)
		{
			avg=a;
		}
		long Ret_ID()
		{
			return id;
		}
		char* Ret_Name()
		{
			return name;
		}
		char* Ret_Family()
		{
			return family;
		}
};
//=================================================
void student :: input ()
{
	clrscr();
	gotoxy(30,1);
	cprintf("*** Enter Your Data ***");
	gotoxy(1,3);
	cprintf("First Name: ");
	cin>>(name);
	gotoxy(1,5);
	cprintf("Last Name:");
	cin>>(family);
	gotoxy(1,7);
	cprintf("Father Name:");
	cin>>(pedar);
	gotoxy(1,9);
	cprintf("shomare shenasname:");
	cin>>shsh;
	gotoxy(1,11);
	cprintf("shomare daneshjooei:");
	cin>>id;
	gotoxy(1,13);
	cprintf("code melli:");
	cin>>code;
}
//=================================================
void student :: edit(int n)
{
	int intg;
	char Tname[20];
	switch (n)
	{
		case 10: gotoxy(7,5);
			 cout<<"              ";
			 gotoxy(7,5);
			 cin>>Tname;
			 strcpy(name,name);
			 gotoxy(7,5);
			 cout<<name;
			 break;
		case 12: gotoxy(36,5);
			 cout<<"              ";				 gotoxy(36,5);
			 cin>>name;
			 strcpy(family,name);
			 gotoxy(36,5);
			 cout<<family;
			 break;
		case 14: gotoxy(58,5);
			 cout<<"              ";
			 gotoxy(58,5);
			 cin>>name;
			 strcpy(pedar,name);
			 gotoxy(58,5);
			 cout<<pedar;
			 break;
		case 16: gotoxy(8,7);
			 cout<<"              ";
			 gotoxy(8,7);
			 cin>>intg;
			 shsh=intg;
			 gotoxy(8,7);
			 cout<<shsh;
			 break;
		case 18: gotoxy(29,7);
			 cout<<"              ";
			 gotoxy(29,7);
			 cin>>intg;
			 id=intg;
			 gotoxy(29,7);
			 cout<<id;
			 break;
		case 20: gotoxy(62,7);
			 cout<<"              ";
			 gotoxy(62,7);
			 cin>>intg;
			 code=intg;
			 gotoxy(62,7);
			 cout<<code;
			 break;
	  }
}
//=================================================
void student :: show1()
{
	clrscr();
	gotoxy(1,5);
	cout<<"Name: "<<name;
	gotoxy(25,5);
	cout<<"Last name: "<<family;
	gotoxy(50,5);
	cout<<"Father: "<<pedar;
	gotoxy(1,7);
	cout<<"sh.sh: "<<shsh;
	gotoxy(25,7);
	cout<<"ID: "<<id;
	gotoxy(50,7);
	cout<<"code melli: "<<code;
}
//=================================================
void student :: show2(int y)
{
	gotoxy(10,y);
	cout<<name;
	gotoxy(20,y);
	cout<<family;
	gotoxy(30,y);
	cout<<pedar;
	gotoxy(40,y);
	cout<<shsh;
	gotoxy(50,y);
	cout<<id;
	gotoxy(60,y);
	cout<<code;
	gotoxy(70,y);
	cout<<avg;
}
//=================================================
void student :: show3()
{
	gotoxy(1,3);
	cprintf("First Name: ");
	cout<<(name);
	gotoxy(1,5);
	cprintf("Last Name:");
	cout<<(family);
	gotoxy(1,7);
	cprintf("Father Name:");
	cout<<(pedar);
	gotoxy(1,9);
	cprintf("shomare shenasname:");
	cout<<shsh;
	gotoxy(1,11);
	cprintf("shomare daneshjooei:");
	cout<<id;
	gotoxy(1,13);
	cprintf("code melli:");
	cout<<code;
	gotoxy(40,3);
	cout<<"Unit";
	gotoxy(45,3);
	cout<<"grade";
	gotoxy(55,3);
	cout<<"Dars";
	gotoxy(35,4);
	cout<<"------------------------------";
	int x=40,y=5;
	for (int j=1;j<=DarsCnt;j++)
	{
		gotoxy(x,y);
		cout<<dars[0][j];
		gotoxy(x+5,y);
		cout<<dars[1][j];
		gotoxy(x+15,y);
		cout<<namedars[j];
		y+=2;
	}
}
//=================================================
int ok,ok2;
student st[20];
unit 	u[40];
int n;
//=================================================
void menu()
{
	setgraphmode(getgraphmode());
	cleardevice();
	setbkcolor(6);
	setfillstyle(8,4);
	bar(1,1,640,480);
	settextstyle(5,0,4);
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
		menu();
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
	for (i=0;i<n;i++)
	{
	ok=1;
	st[i].input();
	}
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
	for (i=0;i<n;i++)
	{
		if (id==st[i].Ret_ID())
		{
			sw=1;
			j=i;
			st[i].show1();
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
			st[j].edit(y);
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
	student temp;
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
		for (i=0;i<n;i++)
		{
			for (int j=0;j<n-i-1;j++)
				if (strcmp(st[j].Ret_Name(),st[j+1].Ret_Name())>0)
				{
					temp=st[j];
					st[j]=st[j+1];
					st[j+1]=temp;
				}
		}
	}
	else if (num==2)
	{
		for (i=0;i<n;i++)
		{
			for (int j=0;j<n-i-1;j++)
				if (strcmp(st[j].Ret_Family(),st[j+1].Ret_Family())>0)
				{
					temp=st[j];
					st[j]=st[j+1];
					st[j+1]=temp;
				}
		}
	}
	else if (num==3)
	{
		for (i=0;i<n;i++)
		{
			for (int j=0;j<n-i-1;j++)
				if (st[j].Ret_ID()>st[j+1].Ret_ID())
				{
					temp=st[j];
					st[j]=st[j+1];
					st[j+1]=temp;
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
	for (i=0;i<n;i++)
	{
		st[i].show2(y);
		y+=2;
	}
	getch();
	menu();
}
////////////////////////////////////////////////////////////
void vahed()
{
	u[1].code=100;
	strcpy(u[1].dars,"Ryazi 1");
	u[2].code=101;
	strcpy(u[2].dars,"Fizik 1");
	u[3].code=102;
	strcpy(u[3].dars,"Ryazi 2");
	u[4].code=103;
	strcpy(u[4].dars,"Fizik 2");
	u[5].code=104;
	strcpy(u[5].dars,"uarname sazi 1");
	u[6].code=105;
	strcpy(u[6].dars,"uarname sazi 2");
	u[7].code=106;
	strcpy(u[7].dars,"sakhteman gossaste");
	u[8].code=107;
	strcpy(u[8].dars,"sakhteman dadeh");
	u[9].code=108;
	strcpy(u[9].dars,"moadelat difranseil");
	u[10].code=109;
	strcpy(u[10].dars,"amar va ehtemalat");
	u[11].code=110;
	strcpy(u[11].dars,"ryazi mohandesi");
	u[12].code=111;
	strcpy(u[12].dars,"madar 1");
	u[13].code=112;
	strcpy(u[13].dars,"madar 2");
	u[14].code=113;
	strcpy(u[14].dars,"taruiyat 1");
	u[15].code=114;
	strcpy(u[15].dars,"taruiyat 2");
	u[16].code=115;
	strcpy(u[16].dars,"akhlagh");
	u[17].code=116;
	strcpy(u[17].dars,"farsi");
	u[18].code=117;
	strcpy(u[18].dars,"zauan");
	u[19].code=118;
	strcpy(u[19].dars,"zauan takhassosi");
	u[20].code=119;
	strcpy(u[20].dars,"az fizik 1");
	u[21].code=120;
	strcpy(u[21].dars,"az fizik 2");
	u[22].code=121;
	strcpy(u[22].dars,"az madar");
	u[23].code=122;
	strcpy(u[23].dars,"ossool micro");
	u[24].code=123;
	strcpy(u[24].dars,"payegah dadeh");
	u[25].code=124;
	strcpy(u[25].dars,"madar manteghi");
	u[26].code=125;
	strcpy(u[26].dars,"shauakehay PC");
	u[27].code=126;
	strcpy(u[27].dars,"system amel");
	u[28].code=127;
	strcpy(u[28].dars,"mohandesi narmafzar");
	u[29].code=128;
	strcpy(u[29].dars,"hoosh masnooei");
	u[30].code=129;
	strcpy(u[30].dars,"gerafik PC");
}
////////////////////////////////////////////////////////////
void unit_selection()
{
	int i,j,y=5,x=10;
	long int id;
	char ans='y';
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
	y=5;
	x=10;
	for (i=0;i<n;i++)
	if (id==st[i].Ret_ID())
	{
	j=i;
	for (i=1;i<=30;i++)
	{
		gotoxy(x,y);
		cprintf("%d",u[i].code);
		gotoxy(x+5,y);
		cprintf("%s",u[i].dars);
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
		 cout<<"û";
		 st[j].SelectUnit(u[i].dars);
		 }
		 break;
	}
	ch=getch();
	}
	}
	//c[j]=tedad;
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
	for (i=0;i<n;i++)
	{
		if (st[i].Ret_ID()==id)
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
			for (j=0;j<st[i].Ret_NumOfDars();j++)
			{
				gotoxy(5,y);
				cout<<st[i].dars[0][j];
				gotoxy(10,y);
				cout<<st[i].dars[1][j];
				gotoxy(20,y);
				cout<<st[i].namedars[j];
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
	for (i=0;i<n;i++)
	{
		if (id==st[i].Ret_ID())
		{       int y=8;
			gotoxy(5,5);
			cout<<"Unit";
			gotoxy(15,5);
			cout<<"Grade";
			gotoxy(25,5);
			cout<<"Dars";
			gotoxy(4,6);
			cout<<"-------------------------------------------------";
			for(j=0;j<st[i].Ret_NumOfDars();j++)
			{
				gotoxy(25,y);
				cout<<st[i].namedars[j];
				y+=2;
			}
			int x=7;
			y=8;
			for (j=0;j<st[i].Ret_NumOfDars();j++)
			{
			gotoxy(x,y);
			cin>>st[i].dars[0][j];
			s1+=st[i].dars[0][j];
			gotoxy(x+10,y);
			cin>>st[i].dars[1][j];
			y+=2;
			sum+=((st[i].dars[1][j])*(st[i].dars[0][j]));
			}
			st[i].SetAvg((float)sum/s1);
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
	for (int i=0;i<n;i++)
	{
		if(id==st[i].Ret_ID())
		{
			k=i;
			st[i].show3();

		}
	}
	getch();
	gotoxy(1,30);
	cout<<"Do you want to delete this student(y/n)? ";
	cin>>del;
	if (del=='y')
	{
		for (int j=k;j<n;j++)
			st[j]=st[j+1];
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
	int driver=DETECT,mode=0;
	initgraph(&driver,&mode,"c:\\tc\\bgi");
	menu();
	arrow();
	getch();
}