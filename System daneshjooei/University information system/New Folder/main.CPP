#include<iostream.h>
#include<string.h>
#include"class.h"
#include"graph.h"
ifstream fin,fin1,fin2,fin3,fin4;
//										MAIN
main()
{
	clrscr();
	int j=1,m,n,i=0,h=0,k=0,l=0,o,e;
	int d,q;
	char hi;
	loadgraph();
	start();
	na:
	cleardevice();
	setcolor(12);
	settextstyle(3,0,5);
	outtextxy(150,18,"MAIN MENU");
	setcolor(10);
	settextstyle(1,0,2);
	outtextxy(470,420,"Se@l software");
	outtextxy(530,440,"Shawon");
	setcolor(15);
	rectangle(200,75,300,95);  //add
	rectangle(205,70,295,100);
	rectangle(200,115,300,135);     //dis
	rectangle(205,110,295,140);
	rectangle(200,155,300,175);          //delete
	rectangle(205,150,295,180);
	rectangle(200,195,300,215);           //search
	rectangle(205,190,295,220);
	rectangle(200,235,300,255);				//exit
	rectangle(205,230,295,260);
	settextstyle(1,0,1.5);
	setcolor(9);
	outtextxy(208,71,"Add new");
	outtextxy(217,111,"Display");
	outtextxy(227,232,"Exit");
	outtextxy(217,192,"Search");
	outtextxy(217,152,"Delete");
	student s[30];
	teacher t[30];
	account a[30];
	library lb[30];
	security sc[30];
	char ch,w,ii,jj;
	moveto(201,71);
	do
	{
		ch=getch();
		if(ch==0)
		{
			ch=getch();
			setcolor(0);
			outtextxy(getx()-30,gety(),"||||||||");
			outtextxy(getx()+120,gety(),"||||||||");
		}
		if(ch==72&&201==getx()&&71==gety())
		{
			moveto(201,231);
			cur(getx(),gety());
		}
		else if(ch==80&&201==getx()&&231==gety())
		{
			moveto(201,71);

			cur(getx(),gety());
		}
		else if(ch==80)
		{
			moveto(getx(),gety()+40);
			cur(getx(),gety());
		}
		else if(ch==72)
		{
			moveto(getx(),gety()-40);
			cur(getx(),gety());
		}
	}while(ch!=13);

	if(gety()==71)
	{
		goto add;
	}
	else if(gety()==111)
	{
		goto display;
	}
	else if(gety()==151)
	{
		goto del;
	}
	else if(gety()==191)
	{
		goto search;
	}
	else if(gety()==231)
	{
			exit();
			goto last;
	}
	add:
	{
	//						CREATE
		n:
		char ch1;
		cleardevice();
		setcolor(6);
		settextstyle(4,0,5);
		outtextxy(170,18,"CREATE");
		setcolor(15);
		rectangle(200,70,300,100);
		rectangle(205,75,295,95);
		rectangle(200,110,300,140);
		rectangle(205,115,295,135);
		rectangle(200,150,300,180);
		rectangle(205,155,295,175);
		rectangle(200,190,300,220);
		rectangle(205,195,295,215);
		settextstyle(1,0,1.5);
		setcolor(2);
		outtextxy(210,72,"Student");
		outtextxy(210,112,"Teacher");
		outtextxy(210,152,"Employe");
		outtextxy(230,192,"Back");
		moveto(201,71);
		do
		{
			ch1=getch();
			if(ch1==0)
			{
				ch1=getch();
				setcolor(0);
				outtextxy(getx()-30,gety(),"||||||||");
				outtextxy(getx()+120,gety(),"||||||||");
			}
			if(ch1==72&&201==getx()&&71==gety())
			{
				moveto(201,191);
				cur(getx(),gety());
			}
			else if(ch1==80&&201==getx()&&191==gety())
			{
				moveto(201,71);
				cur(getx(),gety());
			}
			else if(ch1==72)
			{
				moveto(getx(),gety()-40);
				cur(getx(),gety());
			}
			else if(ch1==80)
			{
				moveto(getx(),gety()+40);
				cur(getx(),gety());
			}
		}while(ch1!=13);
		if(gety()==71)
		{
			n=1;
		}
		if(gety()==111)
		{
			n=2;
		}
		if(gety()==151)
		{
			n=3;
		}
		if(gety()==191)
		{
			n=4;
		}
		if(n==1)
		{
				cleardevice();
				s[j].get();
				++j;
				goto n;

		}
		if(n==2)
		{
			cleardevice();
			t[i].get();
			++i;
			goto n;
		}
		if(n==3)
		{
			char ch3;
			int g;
			r:
			cleardevice();
			setcolor(5);
			settextstyle(4,0,5);
			outtextxy(220,18,"CREATE");
			setcolor(15);
			rectangle(200,70,400,110);
			rectangle(205,75,395,105);
			rectangle(200,130,400,170);
			rectangle(205,135,395,165);
			rectangle(200,190,400,230);
			rectangle(205,195,395,225);
			rectangle(200,250,400,290);
			rectangle(205,255,395,285);
			settextstyle(8,0,1);
			setcolor(14);
			outtextxy(217,75,"Account section");
			settextstyle(8,0,1);
			outtextxy(217,135,"Library section");
			outtextxy(215,195,"Security section");
			outtextxy(270,255,"Back");
			moveto(201,71);
			do
			{
				ch3=getch();
				if(ch3==0)
				{
					ch3=getch();
					setcolor(0);
					outtextxy(getx()+220,gety(),"||||||||");
					outtextxy(getx()-40,gety(),"||||||||");
				}
				if(ch3==72&&201==getx()&&71==gety())
				{
					moveto(201,256);
					curs(getx(),gety());
				}
				else if(ch3==80&&201==getx()&&251==gety())
				{
					moveto(201,71);
					curs(getx(),gety());
				}
				else if(ch3==72)
				{
					moveto(getx(),gety()-60);
					curs(getx(),gety());
				}
				else if(ch3==80)
				{
					moveto(getx(),gety()+60);
					curs(getx(),gety());
				}
			}while(ch3!=13);
			if(gety()==71)
			{
				g=1;
			}
			else if(gety()==131)
			{
				g=2;
			}
			else if(gety()==191)
			{
				g=3;
			}
			else if(gety()==251)
			{
				goto n;
			}
			if(g==1)
			{
					cleardevice();
					a[h].get();
					++h;
					goto r;
			}
			else if(g==2)
			{
					cleardevice();
					lb[k].get();
					++k;
					goto r;
			}
			else if(g==3)
			{
					cleardevice();
					sc[l].get();
					++l;
					goto r;
			}
		}
		if(n==4)
		{
			clrscr();
			goto na;
		}
	}
	//						DISPLAY
	display:
	{
		l:setcolor(15);
		char ch1;
		cleardevice();
		settextstyle(4,1,5);
		outtextxy(100,70,"DISPLAY");
		rectangle(200,70,300,100);
		rectangle(205,75,295,95);
		rectangle(200,110,300,140);
		rectangle(205,115,295,135);
		rectangle(200,150,300,180);
		rectangle(205,155,295,175);
		rectangle(200,190,300,220);
		rectangle(205,195,295,215);
		settextstyle(1,0,1.5);
		setcolor(3);
		outtextxy(210,72,"Student");
		outtextxy(210,112,"Teacher");
		outtextxy(210,152,"Employe");
		outtextxy(210,192,"Back");
		moveto(201,71);
		do
		{
			ch1=getch();
			if(ch1==0)
			{
				ch1=getch();
				setcolor(0);
				outtextxy(getx()-30,gety(),"||||||||");
				outtextxy(getx()+120,gety(),"||||||||");
			}
			if(ch1==72&&201==getx()&&71==gety())
			{
				moveto(201,191);
				cur(getx(),gety());
			}
			else if(ch1==80&&201==getx()&&191==gety())
			{
				moveto(201,71);
				cur(getx(),gety());
			}
			else if(ch1==72)
			{
				moveto(getx(),gety()-40);
				cur(getx(),gety());
			}
			else if(ch1==80)
			{
				moveto(getx(),gety()+40);
				cur(getx(),gety());
			}
		}while(ch1!=13);
		if(gety()==71)
		{
			o=1;
		}
		if(gety()==111)
		{
			o=2;
		}
		if(gety()==151)
		{
			o=3;
		}
		if(gety()==191)
		{
			goto na;
		}
		if(o==1)
		{
			cleardevice();
			int y=0,i,mm=0;
			char name[40];
			char gender[6];
			char age[10];
			char dep[10];
			char id[20];
			char sem_n[10];
		 fin.open("st.doc",ios::in);
		 fin.seekg(0,ios::beg);
		 while(fin)
		 {
			fin.getline(name,40);
			strcpy(s[y].name,name);
			fin.getline(gender,6);
			strcpy(s[y].gender,gender);
			fin.getline(age,10);
			strcpy(s[y].age,age);
			fin.getline(dep,10);
			strcpy(s[y].dep,dep);
			fin.getline(id,20);
			strcpy(s[y].id,id);
			fin.getline(sem_n,10);
			strcpy(s[y].sem_n,sem_n);
			++y;
		 }
		 fin.close();
		 char wy;
		 for(i=0;i<y-1;++i)
		 {
			s[i].display();
			++mm;
			if(mm==6)
			{

				mm=0;
				cout<<"PRESS ANY KEY TO CONTINUE";
				wy=getch();
				cleardevice();
				moveto(0,0);
			}
		 }
		 ch1=getch();
		 if(ch1==13)
			goto l;
		}
		if(o==2)
		{
			cleardevice();
			int p=0,mm;
			char name[40],gender[10],age[10],dep[10],salary[10],des[40];
			char tele[30],wy;
			fin1.open("tea.doc",ios::in);
			fin1.seekg(0,ios::beg);
			while(fin1)
			{
				fin1.getline(name,40);
				strcpy(t[p].name,name);
				fin1.getline(gender,10);
				strcpy(t[p].gender,gender);
				fin1.getline(age,10);
				strcpy(t[p].age,age);
				fin1.getline(dep,10);
				strcpy(t[p].dep,dep);
				fin1.getline(salary,10);
				strcpy(t[p].salary,salary);
				fin1.getline(des,40);
				strcpy(t[p].des,des);
				fin1.getline(tele,30);
				strcpy(t[p].tele,tele);
				++p;
			}
			fin1.close();
			for(int x=0;x<p-1;++x)
			{
				t[x].display();
				++mm;
				if(mm==6)
				{
					mm=0;
					cout<<"PRESS ANY KEY TO CONTINUE";
					wy=getch();
					cleardevice();
				}
			}
			ch1=getch();
			if(ch1==13)
				goto l;
		}
		if(o==3)
		{
			int u;
			char ch4;
			int g,qq;
			uu:setcolor(15);
			cleardevice();
			settextstyle(4,1,5);
			outtextxy(100,70,"DISPLAY");
			rectangle(200,70,400,110);
			rectangle(205,75,395,105);
			rectangle(200,130,400,170);
			rectangle(205,135,395,165);
			rectangle(200,190,400,230);
			rectangle(205,195,395,225);
			rectangle(200,250,400,290);
			rectangle(205,255,395,285);
			settextstyle(8,0,1);
			setcolor(14);
			outtextxy(217,75,"Account section");
			settextstyle(8,0,1);
			outtextxy(217,135,"Library section");
			outtextxy(215,195,"Security section");
			outtextxy(270,255,"Back");
			moveto(201,71);
			do
			{
				ch4=getch();
				if(ch4==0)
				{
					ch4=getch();
					setcolor(0);
					outtextxy(getx()+220,gety(),"||||||||");
					outtextxy(getx()-40,gety(),"||||||||");
				}
				if(ch4==72&&201==getx()&&71==gety())
				{
					moveto(201,256);
					curs(getx(),gety());
				}
				else if(ch4==80&&201==getx()&&251==gety())
				{
					moveto(201,71);
					curs(getx(),gety());
				}
				else if(ch4==72)
				{
					moveto(getx(),gety()-60);
					curs(getx(),gety());
				}
				else if(ch4==80)
				{
					moveto(getx(),gety()+60);
					curs(getx(),gety());
				}
			}while(ch4!=13);
			if(gety()==71)
			{
				u=1;
			}
			else if(gety()==131)
			{
				u=2;
			}
			else if(gety()==191)
			{
				u=3;
			}
			else if(gety()==251)
			{
				goto l;
			}
			if(u==1)
			{
				cleardevice();
				int m=0,mp=0;
				char name[40],gender[10],age[10],work_y[10],title[15],salary[10],ww;
				fin2.open("acc.doc",ios::in);
				fin2.seekg(0,ios::beg);
				while(fin2)
				{
					fin2.getline(name,40);
					strcpy(a[m].name,name);
					fin2.getline(gender,10);
					strcpy(a[m].gender,gender);
					fin2.getline(age,10);
					strcpy(a[m].age,age);
					fin2.getline(work_y,10);
					strcpy(a[m].work_y,work_y);
					fin2.getline(title,15);
					strcpy(a[m].title,title);
					fin2.getline(salary,40);
					strcpy(a[m].salary,salary);
					++m;
				}
				fin2.close();
				for(int x=0;x<m-1;++x)
				{
					a[x].display();
					++mp;
					if(mp==6)
					{
						mp=0;
						cout<<"PRESS ANY KEY TO CONTINUE";
						ww=getch();
						cleardevice();
					}
				}
				qq=getch();
				if(qq==13)
					goto uu;
			}
			if(u==2)
			{
				cleardevice();
				int qm=0,mm=0;
				char name[40],gender[10],age[10],work_y[10],title[15],salary[10],wy;
				fin3.open("lib.doc",ios::in);
				fin3.seekg(0,ios::beg);
				while(fin3)
				{
					fin3.getline(name,40);
					strcpy(lb[qm].name,name);
					fin3.getline(gender,10);
					strcpy(lb[qm].gender,gender);
					fin3.getline(age,10);
					strcpy(lb[qm].age,age);
					fin3.getline(work_y,10);
					strcpy(lb[qm].work_y,work_y);
					fin3.getline(title,15);
					strcpy(lb[qm].title,title);
					fin3.getline(salary,40);
					strcpy(lb[qm].salary,salary);
					++qm;
				}
				fin3.close();
				for(int x=0;x<qm-1;++x)
				{
					lb[x].display();
					++mm;
					if(mm==6)
					{
						mm=0;
						cout<<"PRESS ANY KEY TO CONTINUE";
						wy=getch();
						cleardevice();
					}
				}
				qq=getch();
				if(qq==13)
				{
					goto uu;
				}
			}
			if(u==3)
			{
				cleardevice();
				int l=0,mm=0;
				char name[40],gender[10],age[10],work_y[10],title[15],salary[10],wy;
				fin4.open("sec.doc",ios::in);
				fin4.seekg(0,ios::beg);
				while(fin4)
				{
					fin4.getline(name,40);
					strcpy(sc[l].name,name);
					fin4.getline(gender,10);
					strcpy(sc[l].gender,gender);
					fin4.getline(age,10);
					strcpy(sc[l].age,age);
					fin4.getline(work_y,10);
					strcpy(sc[l].work_y,work_y);
					fin4.getline(title,15);
					strcpy(sc[l].title,title);
					fin4.getline(salary,40);
					strcpy(sc[l].salary,salary);
					++l;
				}
				fin4.close();
				for(int x=0;x<l-1;++x)
				{
					sc[x].display();
					++mm;
					if(mm==6)
					{
						mm=0;
						cout<<"PRESS ANY KEY TO CONTINUE";
						wy=getch();
						cleardevice();
					}
				}
				qq=getch();
				if(qq==13)
					goto uu;
			}
		}
	}
	//									SEARCH
	search:
	{
	fa:char ch2;
	cleardevice();
	setcolor(10);
	settextstyle(4,0,5);
	outtextxy(220,18,"SEARCH");
	setcolor(15);
	rectangle(200,70,400,110);
	rectangle(205,75,395,105);
	rectangle(200,130,400,170);
	rectangle(205,135,395,165);
	rectangle(200,190,400,230);
	rectangle(205,195,395,225);
	rectangle(200,250,400,290);
	rectangle(205,255,395,285);
	settextstyle(8,0,1);
	setcolor(14);
	outtextxy(217,75,"Search by name");
	settextstyle(8,0,1);
	outtextxy(217,135,"Search by id");
	outtextxy(215,195,"Search by title");
	outtextxy(270,255,"Back");
	moveto(201,71);
	do
	{
		ch2=getch();
		if(ch2==0)
		{
			ch2=getch();
			setcolor(0);
			outtextxy(getx()+220,gety(),"||||||||");
			outtextxy(getx()-40,gety(),"||||||||");
		}
		if(ch2==72&&201==getx()&&71==gety())
		{
			moveto(201,256);
			curs(getx(),gety());
		}
		else if(ch2==80&&201==getx()&&251==gety())
		{
			moveto(201,71);
			curs(getx(),gety());
		}
		else if(ch2==72)
		{
			moveto(getx(),gety()-60);
			curs(getx(),gety());
		}
		else if(ch2==80)
		{
			moveto(getx(),gety()+60);
			curs(getx(),gety());
		}
	}while(ch2!=13);
	char jj;
	if(gety()==71)
	{
		e=1;
	}
	else if(gety()==131)
	{
		e=2;
	}
	else if(gety()==191)
	{
		e=3;
	}
	else if(gety()==251)
	{
		goto na;
	}
	if(e==1)
	{
		h:char ch1;
		int yy=0;
		cleardevice();
		setcolor(10);
		settextstyle(4,0,5);
		outtextxy(170,18,"SEARCH");
		setcolor(15);
		rectangle(200,70,300,100);
		rectangle(205,75,295,95);
		rectangle(200,110,300,140);
		rectangle(205,115,295,135);
		rectangle(200,150,300,180);
		rectangle(205,155,295,175);
		rectangle(200,190,300,220);
		rectangle(205,195,295,215);
		settextstyle(5,0,1);
		setcolor(6);
		outtextxy(210,70,"Student");
		outtextxy(210,110,"Teacher");
		outtextxy(210,150,"Employe");
		outtextxy(210,190,"Back");
		moveto(201,71);
		do
		{
			ch1=getch();
			if(ch1==0)
			{
				ch1=getch();
				setcolor(0);
				outtextxy(getx()-30,gety(),"||||||||");
				outtextxy(getx()+120,gety(),"||||||||");
			}
			if(ch1==72&&201==getx()&&71==gety())
			{
				moveto(201,191);
				cur(getx(),gety());
			}
			else if(ch1==80&&201==getx()&&191==gety())
			{
				moveto(201,71);
				cur(getx(),gety());
			}
			else if(ch1==72)
			{
				moveto(getx(),gety()-40);
				cur(getx(),gety());
			}
			else if(ch1==80)
			{
				moveto(getx(),gety()+40);
				cur(getx(),gety());
			}
		}while(ch1!=13);
		if(gety()==71)
		{
			yy=1;
		}
		if(gety()==111)
		{
			yy=2;
		}
		if(gety()==151)
		{
			yy=3;
		}
		if(gety()==191)
		{
			goto fa;
		}
		if(yy==1)
		{
			cleardevice();
			char q[100],*mm,nn;
			int in=0;
			char name[40],gender[6],age[10],dep[10],id[20],sem_n[10];
			gotoxy(30,10);
			cout<<"ENTER NAME\n";
			gotoxy(30,11);
			gets(mm);
			fin.open("st.doc",ios::in);
			fin.seekg(0,ios::beg);
			while(fin)
			{
				fin.getline(name,40);
				fin.getline(gender,6);
				fin.getline(age,10);
				fin.getline(dep,10);
				fin.getline(id,20);
				fin.getline(sem_n,10);
				if(strcmp(name,mm)==0)
				{
					cleardevice();
					++in;
					gotoxy(30,12);
					cout<<"found\n";
					gotoxy(30,13);
					cout<<"NAME : "<<name<<"\n";gotoxy(30,14);cout<<"GENDER : "<<gender<<"\n";
					gotoxy(30,15);cout<<"AGE : "<<age<<"\n";gotoxy(30,16);
					cout<<"DEPERTMENT : "<<dep<<"\n";gotoxy(30,17);cout<<"Id no : "<<id<<"\n";
					gotoxy(30,18);cout<<"SEMISTER NO : "<<sem_n;
				}
			}
			fin.close();
			if(in==0)
			{
				cleardevice();
				gotoxy(30,11);
				cout<<"SORRY, NOT FOUND";
			}
			nn=getch();
			if(nn==13)
			 goto h;
		 }
		if(yy==2)
		{
			cleardevice();
			char name[40],gender[10],age[10],dep[10],salary[10],des[40];
			char tele[30],*mm,kl;
			gotoxy(30,10);
			cout<<"Enter name\n";
			gotoxy(30,11);
			gets(mm);
			int in=0;
			fin1.open("tea.doc",ios::in);
			fin1.seekg(0,ios::beg);
			while(fin1)
			{
				fin1.getline(name,40);
				fin1.getline(gender,10);
				fin1.getline(age,10);
				fin1.getline(dep,10);
				fin1.getline(salary,10);
				fin1.getline(des,40);
				fin1.getline(tele,30);
				if(strcmp(name,mm)==0)
				{
					cleardevice();
					++in;
					gotoxy(30,12);
					cout<<"found\n";
					gotoxy(30,13);
					cout<<"NAME : "<<name<<"\n";gotoxy(30,14);cout<<"GENDER : "<<gender<<"\n";
					gotoxy(30,15);cout<<"AGE : "<<age<<"\n";gotoxy(30,16);
					cout<<"DEPERTMENT : "<<dep<<"\n";gotoxy(30,17);cout<<"SALARY : "<<salary<<"\n";
					gotoxy(30,18);cout<<"DESIGNATION : "<<des<<"\n"; gotoxy(30,19);
					cout<<"TELEPHONE NO : "<<tele;
				}
			}
			fin1.close();
			if(in==0)
			{
				cleardevice();
				gotoxy(30,15);
				cout<<"SORRY, NOT FOUND";
			}
			kl=getch();
			if(kl==13)
			{
				goto h;
			}
		}
		else if(yy==3)
		{
			fr:char ch7;
			int u=0;
			cleardevice();
			setcolor(10);
			settextstyle(4,0,5);
			outtextxy(220,18,"SEARCH");
			setcolor(15);
			rectangle(200,70,400,110);
			rectangle(205,75,395,105);
			rectangle(200,130,400,170);
			rectangle(205,135,395,165);
			rectangle(200,190,400,230);
			rectangle(205,195,395,225);
			rectangle(200,250,400,290);
			rectangle(205,255,395,285);
			settextstyle(8,0,1);
			setcolor(8);
			outtextxy(217,75,"Account section");
			settextstyle(8,0,1);
			outtextxy(217,135,"Library section");
			outtextxy(215,195,"Security section");
			outtextxy(270,255,"Back");
			moveto(201,71);
			do
			{
				ch7=getch();
				if(ch7==0)
				{
					ch7=getch();
					setcolor(0);
					outtextxy(getx()+220,gety(),"||||||||");
					outtextxy(getx()-40,gety(),"||||||||");
				}
				if(ch7==72&&201==getx()&&71==gety())
				{
					moveto(201,256);
					curs(getx(),gety());
				}
				else if(ch7==80&&201==getx()&&251==gety())
				{
					moveto(201,71);
					curs(getx(),gety());
				}
				else if(ch7==72)
				{
					moveto(getx(),gety()-60);
					curs(getx(),gety());
				}
				else if(ch7==80)
				{
					moveto(getx(),gety()+60);
					curs(getx(),gety());
				}
			}while(ch7!=13);
			if(gety()==71)
			{
				u=1;
			}
			else if(gety()==131)
			{
				u=2;
			}
			else if(gety()==191)
			{
				u=3;
			}
			else if(gety()==251)
			{
				goto h;
			}
			if(u==1)
			{
				cleardevice();
				char *nam,kl;
				int in=0;
				gotoxy(30,10);
				cout<<"ENTER NAME\n";
				gotoxy(30,11);
				gets(nam);
				char name[40],gender[10],age[10],work_y[10],title[15],salary[10];
				fin2.open("acc.doc",ios::in);
				fin2.seekg(0,ios::beg);
				while(fin2)
				{
					fin2.getline(name,40);
					fin2.getline(gender,10);
					fin2.getline(age,10);
					fin2.getline(work_y,10);
					fin2.getline(title,15);
					fin2.getline(salary,40);
					if(strcmp(name,nam)==0)
					{
						gotoxy(30,12);
						cout<<"Found\n";++in;
						gotoxy(30,13);
						cout<<"Name : "<<name;gotoxy(30,14);cout<<"Gender : "<<gender;
						gotoxy(30,15);cout<<"Age : "<<age;gotoxy(30,16);cout<<"Working time : "<<work_y;
						gotoxy(30,17);cout<<"Title : "<<title;gotoxy(30,18);
						cout<<"Salary : "<<salary;
					}
				}
				fin2.close();
				kl=getch();
				if(in==0)
				{
					cleardevice();
					gotoxy(30,10);cout<<"SORRY, NOT FOUND";
				}
				if(kl==13)
					goto fa;
			}
			if(u==2)
			{
				cleardevice();
				char *nam,kl;
				int in=0;
				gotoxy(30,10);
				cout<<"ENTER NAME\n";
				gotoxy(30,11);
				gets(nam);
				char name[40],gender[10],age[10],work_y[10],title[15],salary[10];
				fin3.open("lib.doc",ios::in);
				fin3.seekg(0,ios::beg);
				while(fin3)
				{
					fin3.getline(name,40);
					fin3.getline(gender,10);
					fin3.getline(age,10);
					fin3.getline(work_y,10);
					fin3.getline(title,15);
					fin3.getline(salary,40);
					if(strcmp(name,nam)==0)
					{
						++in;
						gotoxy(30,12);
						cout<<"Found\n";
						gotoxy(30,13);
						cout<<"Name : "<<name;gotoxy(30,14);cout<<"Gender : "<<gender;
						gotoxy(30,15);cout<<"Age : "<<age;gotoxy(30,16);cout<<"Working time : "<<work_y;
						gotoxy(30,17);cout<<"Title : "<<title;gotoxy(30,18);
						cout<<"Salary : "<<salary;
					}
				}
				fin3.close();
				if(in==0)
				{
					cleardevice();
					gotoxy(30,11);cout<<"Sorry";
					gotoxy(30,12);cout<<"Not found";
				}
				kl=getch();
				if(kl==13)
					goto fr;
			}
			if(u==3)
			{
				cleardevice();
				char *nam,kl;
				int in=0;
				gotoxy(30,10);
				cout<<"ENTER NAME\n";
				gotoxy(30,11);
				gets(nam);
				char name[40],gender[10],age[10],work_y[10],title[15],salary[10];
				fin4.open("sec.doc",ios::in);
				fin4.seekg(0,ios::beg);
				while(fin4)
				{
					fin4.getline(name,40);
					fin4.getline(gender,10);
					fin4.getline(age,10);
					fin4.getline(work_y,10);
					fin4.getline(title,15);
					fin4.getline(salary,40);
					if(strcmp(name,nam)==0)
					{
						gotoxy(30,12);
						cout<<"Found\n";
						gotoxy(30,13);++in;
						cout<<"Name : "<<name;gotoxy(30,14);cout<<"Gender : "<<gender;
						gotoxy(30,15);cout<<"Age : "<<age;gotoxy(30,16);cout<<"Working time : "<<work_y;
						gotoxy(30,17);cout<<"Title : "<<title;gotoxy(30,18);
						cout<<"Salary : "<<salary;
					}
				}
				fin4.close();
				if(in==0)
				{
					cleardevice();
					gotoxy(30,11);cout<<"SORRY, NOT FOUND";
				}
				kl=getch();
				if(kl==13)
					goto fr;
			}
		}
	}
	if(e==2)
	{
		cleardevice();
		int in=0;
		char *idd;
		settextstyle(2,0,4);
		outtextxy(120,120,"This searching option is only for student depertment");
		outtextxy(210,140,"Enter Id no:");
		gotoxy(40,10);
		gets(idd);
		char name[40],gender[6],age[10],dep[10],id[20],sem_n[10];
		fin.open("st.doc",ios::in);
		fin.seekg(0,ios::beg);
		while(fin)
		{
			fin.getline(name,40);
			fin.getline(gender,6);
			fin.getline(age,10);
			fin.getline(dep,10);
			fin.getline(id,20);
			fin.getline(sem_n,10);
			if(strcmp(id,idd)==0)
			{
					++in;
					gotoxy(30,11);
					cout<<"found\n";
					gotoxy(30,12);
					cout<<"NAME : "<<name<<"\n";gotoxy(30,13);cout<<"GENDER : "<<gender<<"\n";
					gotoxy(30,14);cout<<"AGE : "<<age<<"\n";gotoxy(30,15);
					cout<<"DEPERTMENT : "<<dep<<"\n";gotoxy(30,16);cout<<"Id no : "<<id<<"\n";
					gotoxy(30,17);cout<<"SEMISTER NO : "<<sem_n;
				}
			}
			fin.close();
			if(in==0)
			{
				gotoxy(30,11);
				cout<<"SORRY, NOT FOUND";
			}
		char kl;
		kl=getch();
		if(kl==13)
			goto fa;
	}
	if(e==3)
	{
		char ch8;
		int u=0;
		cc:cleardevice();
		setcolor(10);
		settextstyle(4,0,5);
		outtextxy(220,18,"SEARCH");
		setcolor(15);
		rectangle(200,70,400,110);
		rectangle(205,75,395,105);
		rectangle(200,130,400,170);
		rectangle(205,135,395,165);
		rectangle(200,190,400,230);
		rectangle(205,195,395,225);
		rectangle(200,250,400,290);
		rectangle(205,255,395,285);
		settextstyle(8,0,1);
		setcolor(13);
		outtextxy(217,75,"Account section");
		settextstyle(8,0,1);
		outtextxy(217,135,"Library section");
		outtextxy(215,195,"Security section");
		outtextxy(270,255,"Back");
		moveto(201,71);
		do
		{
			ch8=getch();
			if(ch8==0)
			{
				ch8=getch();
				setcolor(0);
				outtextxy(getx()+220,gety(),"||||||||");
				outtextxy(getx()-40,gety(),"||||||||");
			}
			if(ch8==72&&201==getx()&&71==gety())
			{
				moveto(201,256);
				curs(getx(),gety());
			}
			else if(ch8==80&&201==getx()&&251==gety())
			{
				moveto(201,71);
				curs(getx(),gety());
			}
			else if(ch8==72)
			{
				moveto(getx(),gety()-60);
				curs(getx(),gety());
			}
			else if(ch8==80)
			{
				moveto(getx(),gety()+60);
				curs(getx(),gety());
			}
		 }while(ch8!=13);
		if(gety()==71)
		{
			u=1;
		}
		else if(gety()==131)
		{
			u=2;
		}
		else if(gety()==191)
		{
			u=3;
		}
		else if(gety()==251)
		{
			goto fa;
		}
		if(u==1)
		{
			cleardevice();
			char *nam,kl;
			int in=0;
			gotoxy(30,10);
			cout<<"ENTER NAME\n";
			gotoxy(30,11);
			gets(nam);
			char name[40],gender[10],age[10],work_y[10],title[15],salary[10];
			fin2.open("acc.doc",ios::in);
			fin2.seekg(0,ios::beg);
			while(fin2)
			{
				fin2.getline(name,40);
				fin2.getline(gender,10);
				fin2.getline(age,10);
				fin2.getline(work_y,10);
				fin2.getline(title,15);
				fin2.getline(salary,40);
				if(strcmp(name,nam)==0)
				{
					gotoxy(30,12);
					cout<<"Found\n";++in;
					gotoxy(30,13);
					cout<<"Name : "<<name;gotoxy(30,14);cout<<"Gender : "<<gender;
					gotoxy(30,15);cout<<"Age : "<<age;gotoxy(30,16);cout<<"Working time : "<<work_y;
					gotoxy(30,17);cout<<"Title : "<<title;gotoxy(30,18);
					cout<<"Salary : "<<salary;
				}
			}
			fin2.close();
			kl=getch();
			if(in==0)
			{
				cleardevice();
				gotoxy(30,10);cout<<"SORRY, NOT FOUND";
			}
			if(kl==13)
				goto cc;
		}
		if(u==2)
		{
			cleardevice();
			char *nam,kl;
			int in=0;
			gotoxy(30,10);
			cout<<"ENTER NAME\n";
			gotoxy(30,11);
			gets(nam);
			char name[40],gender[10],age[10],work_y[10],title[15],salary[10];
			fin3.open("lib.doc",ios::in);
			fin3.seekg(0,ios::beg);
			while(fin3)
			{
				fin3.getline(name,40);
				fin3.getline(gender,10);
				fin3.getline(age,10);
				fin3.getline(work_y,10);
				fin3.getline(title,15);
				fin3.getline(salary,40);
				if(strcmp(name,nam)==0)
				{
					++in;
					gotoxy(30,12);
					cout<<"Found\n";
					gotoxy(30,13);
					cout<<"Name : "<<name;gotoxy(30,14);cout<<"Gender : "<<gender;
					gotoxy(30,15);cout<<"Age : "<<age;gotoxy(30,16);cout<<"Working time : "<<work_y;
					gotoxy(30,17);cout<<"Title : "<<title;gotoxy(30,18);
					cout<<"Salary : "<<salary;
				}
			}
			fin3.close();
			if(in==0)
			{
				cleardevice();
				gotoxy(30,11);cout<<"Sorry";
				gotoxy(30,12);cout<<"Not found";
			}
			kl=getch();
			if(kl==13)
				goto cc;
		}
		if(u==3)
		{
			cleardevice();
			char *nam,kl;
			int in=0;
			gotoxy(30,10);
			cout<<"ENTER NAME\n";
			gotoxy(30,11);
			gets(nam);
			char name[40],gender[10],age[10],work_y[10],title[15],salary[10];
			fin4.open("sec.doc",ios::in);
			fin4.seekg(0,ios::beg);
			while(fin4)
			{
				fin4.getline(name,40);
				fin4.getline(gender,10);
				fin4.getline(age,10);
				fin4.getline(work_y,10);
				fin4.getline(title,15);
				fin4.getline(salary,40);
				if(strcmp(name,nam)==0)
				{
					gotoxy(30,12);
					cout<<"Found\n";
					gotoxy(30,13);++in;
					cout<<"Name : "<<name;gotoxy(30,14);cout<<"Gender : "<<gender;
					gotoxy(30,15);cout<<"Age : "<<age;gotoxy(30,16);cout<<"Working time : "<<work_y;
					gotoxy(30,17);cout<<"Title : "<<title;gotoxy(30,18);
					cout<<"Salary : "<<salary;
				}
			}
			fin4.close();
			if(in==0)
			{
				cleardevice();
				gotoxy(30,11);cout<<"SORRY, NOT FOUND";
			}
			kl=getch();
			if(kl==13)
			{
				goto cc;
			}
		}
	}
}
del:
{
		int y=0;
		d:	char ch5;
		cleardevice();
		setcolor(9);
		settextstyle(4,0,5);
		outtextxy(175,18,"DELETE");
		setcolor(15);
		rectangle(200,70,300,100);
		rectangle(205,75,295,95);
		rectangle(200,110,300,140);
		rectangle(205,115,295,135);
		rectangle(200,150,300,180);
		rectangle(205,155,295,175);
		rectangle(200,190,300,220);
		rectangle(205,195,295,215);
		settextstyle(1,0,1.5);
		setcolor(5);
		outtextxy(210,72,"Student");
		outtextxy(210,112,"Teacher");
		outtextxy(210,152,"Employe");
		outtextxy(220,192,"Back");
		moveto(201,71);
		do
		{
			ch5=getch();
			if(ch5==0)
			{
				ch5=getch();
				setcolor(0);
				outtextxy(getx()-30,gety(),"||||||||");
				outtextxy(getx()+120,gety(),"||||||||");
			}
			if(ch5==72&&201==getx()&&71==gety())
			{
				moveto(201,191);
				cur(getx(),gety());
			}
			else if(ch5==80&&201==getx()&&191==gety())
			{
				moveto(201,71);
				cur(getx(),gety());
			}
			else if(ch5==72)
			{
				moveto(getx(),gety()-40);
				cur(getx(),gety());
			}
			else if(ch5==80)
			{
				moveto(getx(),gety()+40);
				cur(getx(),gety());
			}
		}while(ch5!=13);
		if(gety()==71)
		{
			e=1;
		}
		if(gety()==111)
		{
			e=2;
		}
		if(gety()==151)
		{
			e=3;
		}
		if(gety()==191)
		{
			goto na;
		}
		if(e==1)
		{
			cleardevice();
			char q[100],*mm,*nn;
			char name[40],gender[6],age[10],dep[10],id[20],sem_n[10];
			int in=0;
			gotoxy(30,10);
			cout<<"enter id number";
			gotoxy(30,11);
			gets(mm);
			fin.open("st.doc",ios::in);
			fin.seekg(0,ios::beg);
			while(fin)
			{
				fin.getline(name,40);
				strcpy(s[y].name,name);
				fin.getline(gender,6);
				strcpy(s[y].gender,gender);
				fin.getline(age,10);
				strcpy(s[y].age,age);
				fin.getline(dep,10);
				strcpy(s[y].dep,dep);
				fin.getline(id,20);
				strcpy(s[y].id,id);
				fin.getline(sem_n,10);
				strcpy(s[y].sem_n,sem_n);
				++y;
			}
			fin.close();
			for(int i=0;i<y-1;++i)
			{
				if(strcmp(mm,s[i].id)==0)
				{
					int p;
					gotoxy(30,15);++in;
					cout<<"Found and successfully deleted";
					for(p=i;p<y-1;++p)
					{
						s[p]=s[p+1];
					}
					--y;
				}
			}
			int z;
			z=y;
			ofstream fout;
			fout.open("st.doc",ios::out|ios::trunc);
			for(i=0;i<z-1;++i)
			{
				fout<<s[i].name<<"\n"<<s[i].gender<<"\n"<<s[i].age<<"\n"
				<<s[i].dep<<"\n"<<s[i].id<<"\n"<<s[i].sem_n<<"\n";
			}
			fout.close();
			if(in==0)
			{
				cleardevice();gotoxy(30,14);
				cout<<"Sorry, there is such no record";
			}
			char fg;
			fg=getch();
			if(fg==13)
				goto d;
		}
		if(e==2)
		{
			cleardevice();
			char q[100],*mm,*nn;
			int in=0;
			char name[40],gender[6],age[10],dep[10],salary[10],des[40],tele[30];
			int te=0;
			gotoxy(30,11);
			cout<<"PLEASE ENTER NAME";
			gotoxy(30,12);
			gets(nn);
			fin1.open("tea.doc",ios::in);
			fin1.seekg(0,ios::beg);
			while(fin1)
			{
				fin1.getline(name,40);
				strcpy(t[te].name,name);
				fin1.getline(gender,6);
				strcpy(t[te].gender,gender);
				fin1.getline(age,10);
				strcpy(t[te].age,age);
				fin1.getline(dep,10);
				strcpy(t[te].dep,dep);
				fin1.getline(salary,10);
				strcpy(t[te].salary,salary);
				fin1.getline(des,40);
				strcpy(t[te].des,des);
				fin1.getline(tele,30);
				strcpy(t[te].tele,tele);
				++te;
			}
			fin1.close();
			for(int i=0;i<te-1;++i)
			{
				if(strcmp(nn,t[i].name)==0)
				{
					int p;++in;
					gotoxy(30,14);
					cout<<"Found and successfully deleted";
					for(p=i;p<te-1;++p)
					{
						t[p]=t[p+1];
					}
					--te;
				}
			}
			int z;
			z=te;
			f1.open("tea.doc",ios::out);
			for(i=0;i<z-1;++i)
			{
				f1<<t[i].name<<"\n"<<t[i].gender<<"\n"<<t[i].age<<"\n"
				<<t[i].dep<<"\n"<<t[i].salary<<"\n"<<t[i].des<<"\n"
				<<t[i].tele<<"\n";
			}
			f1.close();
			if(in==0)
			{
				cleardevice();
				gotoxy(30,11);cout<<"Sorry, there is such no record";
			}
			char fg;
			fg=getch();
			if(fg==13)
				goto d;

		}
		if(e==3)
		{
			char ch6;
			int g;
			dr:
			cleardevice();
			setcolor(7);
			settextstyle(4,0,5);
			outtextxy(220,18,"DELETE");
			setcolor(15);
			rectangle(200,70,400,110);
			rectangle(205,75,395,105);
			rectangle(200,130,400,170);
			rectangle(205,135,395,165);
			rectangle(200,190,400,230);
			rectangle(205,195,395,225);
			rectangle(200,250,400,290);
			rectangle(205,255,395,285);
			settextstyle(8,0,1);
			setcolor(11);
			outtextxy(217,75,"Account section");
			settextstyle(8,0,1);
			outtextxy(217,135,"Library section");
			outtextxy(215,195,"Security section");
			outtextxy(270,255,"Back");
			moveto(201,71);
			do
			{
				ch6=getch();
				if(ch6==0)
				{
					ch6=getch();
					setcolor(0);
					outtextxy(getx()+220,gety(),"||||||||");
					outtextxy(getx()-40,gety(),"||||||||");
				}
				if(ch6==72&&201==getx()&&71==gety())
				{
					moveto(201,256);
					curs(getx(),gety());
				}
				else if(ch6==80&&201==getx()&&251==gety())
				{
					moveto(201,71);
					curs(getx(),gety());
				}
				else if(ch6==72)
				{
					moveto(getx(),gety()-60);
					curs(getx(),gety());
				}
				else if(ch6==80)
				{
					moveto(getx(),gety()+60);
					curs(getx(),gety());
				}
			}while(ch6!=13);
			if(gety()==71)
			{
				g=1;
			}
			else if(gety()==131)
			{
				g=2;
			}
			else if(gety()==191)
			{
				g=3;
			}
			else if(gety()==251)
			{
				goto d;
			}
			if(g==1)
			{
				cleardevice();
				char q[100],*mm,*pp;
				char name[40],gender[6],age[10],work_y[10],title[15],salary[10];
				int ac=0,in=0;
				gotoxy(30,11);
				cout<<"PLEASE ENTER NAME";gotoxy(30,12);
				gets(pp);
				fin2.open("acc.doc",ios::in);
				fin2.seekg(0,ios::beg);
				while(fin2)
				{
					fin2.getline(name,40);
					strcpy(a[ac].name,name);
					fin2.getline(gender,6);
					strcpy(a[ac].gender,gender);
					fin2.getline(age,10);
					strcpy(a[ac].age,age);
					fin2.getline(work_y,10);
					strcpy(a[ac].work_y,work_y);
					fin2.getline(title,15);
					strcpy(a[ac].title,title);
					fin2.getline(salary,10);
					strcpy(a[ac].salary,salary);
					++ac;
				}
				fin2.close();
				for(int i=0;i<ac-1;++i)
				{
					if(strcmp(pp,a[i].name)==0)
					{
						int p; ++in;
						gotoxy(30,14);
						cout<<"Found and successfully deleted";
						for(p=i;p<ac-1;++p)
						{
							a[p]=a[p+1];
						}
						--ac;
					}
				}
				int z;
				z=ac;
				f2.open("acc.doc",ios::out);
				for(i=0;i<z-1;++i)
				{
					f2<<a[i].name<<"\n"<<a[i].gender<<"\n"<<a[i].age<<"\n"
					<<a[i].work_y<<"\n"<<a[i].title<<"\n"<<a[i].salary<<"\n";
				}
				f2.close();
				if(in==0)
				{
					cleardevice();
					gotoxy(30,11);cout<<"Sorry, there is such no record";
				}
				char fg;
				fg=getch();
				if(fg==13)
					goto dr;
			}
			if(g==2)
			{
				cleardevice();
				char q[100],*mm,*pl;
				char name[40],gender[6],age[10],work_y[10],title[15],salary[10];
				int aa=0,in=0;
				gotoxy(30,11);
				cout<<"PLEASE ENTER NAME";
				gotoxy(30,12);
				gets(pl);
				fin3.open("lib.doc",ios::in);
				fin3.seekg(0,ios::beg);
				while(fin3)
				{
					fin3.getline(name,40);
					strcpy(lb[aa].name,name);
					fin3.getline(gender,6);
					strcpy(lb[aa].gender,gender);
					fin3.getline(age,10);
					strcpy(lb[aa].age,age);
					fin3.getline(work_y,10);
					strcpy(lb[aa].work_y,work_y);
					fin3.getline(title,15);
					strcpy(lb[aa].title,title);
					fin3.getline(salary,10);
					strcpy(lb[aa].salary,salary);
					++aa;
				}
				fin3.close();
				for(int i=0;i<aa-1;++i)
				{
					if(strcmp(pl,lb[i].name)==0)
					{
						int p; ++in;
						gotoxy(30,14);
						cout<<"Found and successfully deleted";
						for(p=i;p<aa-1;++p)
						{
							lb[p]=lb[p+1];
						}
						--aa;
					}
				}
				int z;
				z=aa;
				f2.open("lib.doc",ios::out);
				for(i=0;i<z-1;++i)
				{
					f2<<lb[i].name<<"\n"<<lb[i].gender<<"\n"<<lb[i].age<<"\n"
					<<lb[i].work_y<<"\n"<<lb[i].title<<"\n"<<lb[i].salary<<"\n";
				}
				f2.close();
				if(in==0)
				{
					cleardevice();
					gotoxy(30,11);cout<<"Sorry, there is such no record";
				}
				char fg;
				fg=getch();
				if(fg==13)
					goto dr;
			}
			if(g==3)
			{
				cleardevice();
				char *mn;
				char name[40],gender[6],age[10],work_y[10],title[15],salary[10];
				int a=0,in=0;
				gotoxy(30,11);
				cout<<"PLEASE ENTER NAME";
				gotoxy(30,12);
				gets(mn);
				fin4.open("sec.doc",ios::in);
				fin4.seekg(0,ios::beg);
				while(fin4)
				{
					fin4.getline(name,40);
					strcpy(sc[a].name,name);
					fin4.getline(gender,6);
					strcpy(sc[a].gender,gender);
					fin4.getline(age,10);
					strcpy(sc[a].age,age);
					fin4.getline(work_y,10);
					strcpy(sc[a].work_y,work_y);
					fin4.getline(title,15);
					strcpy(sc[a].title,title);
					fin4.getline(salary,10);
					strcpy(sc[a].salary,salary);
					++a;
				}
				fin4.close();
				for(int i=0;i<a-1;++i)
				{
					if(strcmp(mn,sc[i].name)==0)
					{
						int p; ++in;
						gotoxy(30,14);
						cout<<"Found and successfully deleted";
						for(p=i;p<a-1;++p)
						{
							sc[p]=sc[p+1];
						}
						--a;
					}
				}
				int z;
				z=a;
				f2.open("sec.doc",ios::out);
				for(i=0;i<z-1;++i)
				{
					f2<<sc[i].name<<"\n"<<sc[i].gender<<"\n"<<sc[i].age<<"\n"
					<<sc[i].work_y<<"\n"<<sc[i].title<<"\n"<<sc[i].salary<<"\n";
				}
				f2.close();
				if(in==0)
				{
					cleardevice();
					gotoxy(30,11);cout<<"Sorry, there is such no record";
				}
				char fg;
				fg=getch();
				if(fg==13)
					goto dr;
			}
		}
}
	last:
	return 0;
}
