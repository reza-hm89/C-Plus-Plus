#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream.h>
//==============================================
struct date
{
	int day;
	int month;
	int year;
};
//==============================================
struct Program
{
	int code;
	date date_create;
	date date_show;
	date date_first;
	int repeat;
	int channel;
	char name[20];
	char director[15];
	char type[15];
};
//==============================================
struct treenode
{
	Program data;
	treenode *left,*right;
};
//==============================================
treenode *root=NULL;
int day,month,year;
int row=3;
fstream f;
//==============================================
void Menu();
void Sort();
void Movement();
treenode* Insert_Data();
void Add_Program(treenode *cur);
void Edit_Program();
void Delete_Program();
void Register_Show();
void Register_First_Repeat();
void Print_Program(treenode *cur);
void Print_Date();
void Print_Channel();
void Print_Director();
void Print_Repeat();
void Prints(treenode*);
void InOrder(treenode*);
void InOrder1(treenode*);
void InOrder2(treenode*,int);
void InOrder3(treenode*,char[]);
void InOrder4(treenode*,int);
void InOrder5(treenode*);
void InOrder6(treenode*);
void InOrder7(treenode*);
void ReadFile();
void SaveFile();
treenode* Search_Code();
void Print();
//==============================================
void main()
{
	Menu();
	Movement();
}
//==============================================
void Menu()
{
	int i,j,MaxCol=80,MaxRow=25;
	textbackground(BLUE);
	textcolor(WHITE);
	clrscr();
	for (i=1;i<=MaxCol;i++)
	{
		gotoxy(i,1);
		cprintf("Í");
		gotoxy(i,MaxRow);
		cprintf("Í");
	}
	for (j=1;j<=MaxRow;j++)
	{
		gotoxy(1,j);
		cprintf("º");
		gotoxy(MaxCol,j);
		cprintf("º");
	}
	gotoxy(1,1);
	cprintf("É");
	gotoxy(MaxCol,1);
	cprintf("»");
	gotoxy(1,MaxRow);
	cprintf("È");
	gotoxy(MaxCol,MaxRow);
	cprintf("¼");
	gotoxy(10,2);
	cprintf("1.Add Channel");
	gotoxy(10,4);
	cprintf("2.Delete Channel");
	gotoxy(10,6);
	cprintf("3.Edit Channel");
	gotoxy(10,8);
	cprintf("4.Search with code");
	gotoxy(10,10);
	cprintf("5.Register Date of Show Program");
	gotoxy(10,12);
	cprintf("6.Register Date of First Repeat Program");
	gotoxy(10,14);
	cprintf("7.Sort with Code");
	gotoxy(10,16);
	cprintf("8.Print Present Programs in Certain Time");
	gotoxy(10,18);
	cprintf("9.Print Present Programs for Certain Channel");
	gotoxy(10,20);
	cprintf("10.Print Present Programs for Certain Director");
	gotoxy(10,22);
	cprintf("11.Print Programs has Repeated atleast 'n' Time");
	gotoxy(10,24);
	cprintf("12.Exit Program");
}
//==============================================
void Movement()
{
	char ch;
	int y=2;
	treenode *cur;
	cur=new treenode;
	gotoxy(5,y);
	cprintf("->");
	while (1) {
		textcolor(WHITE);
		ch=getch();
		gotoxy(5,y);
		cprintf("  ");
		if (ch==72)
		{
			y-=2;
			if (y<2)
				y=24;
		}
		else if (ch==80)
		{
			y+=2;
			if (y>24)
				y=2;
		}
		else if (ch==13)
		{
			if (y==2) {
				cur=Insert_Data();
				Add_Program(cur);
				Menu();
			}
			else if (y==4) {
				Delete_Program();
				Menu();
			}
			else if (y==6) {
				Edit_Program();
				Menu();
			}
			else if (y==8) {
				if (cur=Search_Code()) {
					Print_Program(cur);
					}
				Menu();
			}
			else if (y==10) {
				Register_Show();
				Menu();
			}
			else if (y==12) {
				Register_First_Repeat();
				Menu();
			}
			else if (y==14) {
				Sort();
				Menu();
			}
			else if (y==16) {
				Print_Date();
				Menu();
			}
			else if (y==18) {
				Print_Channel();
				Menu();
			}
			else if (y==20) {
				Print_Director();
				Menu();
			}
			else if (y==22) {
				Print_Repeat();
				Menu();
			}
			else if (y==24) {
				//SaveFile();
				exit(0);
			}
		}
		gotoxy(5,y);
		cprintf("->");
	}
}
//==============================================
treenode* Insert_Data()
{
	int i,y=0;
	treenode *cur;
	cur=new treenode;
	clrscr();
	gotoxy(2,2);
	cprintf("Program name");
	gotoxy(2,4);
	cprintf("Program Code");
	gotoxy(2,6);
	cprintf("Date Create");
	gotoxy(2,8);
	cprintf("Date Show");
	gotoxy(2,10);
	cprintf("Date first Repeat");
	gotoxy(2,12);
	cprintf("Numbers of repeat");
	gotoxy(2,14);
	cprintf("Director Name");
	gotoxy(2,16);
	cprintf("Channel for Show");
	gotoxy(2,18);
	cprintf("Type Program");
	for (i=1;i<=9;i++)
	{
		gotoxy(19,y+=2);
		textbackground(BLACK);
		cprintf("                          ");
	}
	gotoxy(20,2);
	gets(cur->data.name);
	gotoxy(20,4);
	cin>>cur->data.code;
	gotoxy(20,6);
	cin>>cur->data.date_create.day;
	gotoxy(23,6);
	cprintf("/");
	gotoxy(24,6);
	cin>>cur->data.date_create.month;
	gotoxy(26,6);
	cprintf("/");
	gotoxy(27,6);
	cin>>cur->data.date_create.year;
	gotoxy(20,8);
	cin>>cur->data.date_show.day;
	gotoxy(23,8);
	cprintf("/");
	gotoxy(24,8);
	cin>>cur->data.date_show.month;
	gotoxy(26,8);
	cprintf("/");
	gotoxy(27,8);
	cin>>cur->data.date_show.year;
	gotoxy(20,10);
	cin>>cur->data.date_first.day;
	gotoxy(23,10);
	cprintf("/");
	gotoxy(24,10);
	cin>>cur->data.date_first.month;
	gotoxy(26,10);
	cprintf("/");
	gotoxy(27,10);
	cin>>cur->data.date_first.year;
	gotoxy(20,12);
	cin>>cur->data.repeat;
	gotoxy(20,14);
	gets(cur->data.director);
	gotoxy(20,16);
	cin>>cur->data.channel;
	gotoxy(20,18);
	gets(cur->data.type);
	return cur;
}
//==============================================
void Add_Program(treenode *cur)
{
	treenode *p,*q;
	p=root;
	q=NULL;
	while (p)
	{
		q=p;
		if (p->data.code<cur->data.code)
			p=p->right;
		else
			p=p->left;
	}
	p=new treenode;
	p=cur;
	p->left=p->right=NULL;
	if (!root)
		root=p;
	if (q->data.code<cur->data.code)
		q->right=p;
	else
		q->left=p;
}
//==============================================
void Delete_Program()
{
	int found=0,code;
	textcolor(WHITE);
	clrscr();
	treenode *p,*parent;
	cprintf("Enter Your Code: ");
	cin>>code;
	p=root;
	if(!p)
		return;
	while(p)
	{
		if(p->data.code == code)
		{
			found = 1;
			break;
		}
		else
		{
			parent = p;
			if(p->data.code<code)
				p = p->right;
			else p = p->left;
		}
	}
	if(!found)
	{
		textcolor(RED);
		gotoxy(30,3);
		cprintf("Program not found!");
		getch();
		return;
	}
	textcolor(RED);
	gotoxy(30,3);
	cprintf("Program Deleted...");
	getch();
	// Node with single child
	if((p->left == NULL && p->right != NULL)|| (p->left != NULL && p->right == NULL))
	{
		//right child
		if(p->left == NULL && p->right != NULL)
		{
			if(parent->left == p)
			{
				parent->left = p->right;
				delete p;
			}
			else
			{
				parent->right = p->right;
				delete p;
			}
		}
		else // left child present, no right child
		{
			if(parent->left == p)
			{
				parent->left = p->left;
				delete p;
			}
			else
			{
				parent->right = p->left;
				delete p;
			}
		}
		return;
	}
	//leaf node
	if( p->left == NULL && p->right == NULL)
	{
		if(parent->left == p)
			parent->left = NULL;
		else
			parent->right = NULL;
		delete p;
		return;
	}
	//Node with 2 children
	// replace node with smallest value in right subtree
	if (p->left != NULL && p->right != NULL)
	{
		treenode *chkr;
		chkr = p->right;
		if((chkr->left == NULL) && (chkr->right == NULL))
		{
			p = chkr;
			delete chkr;
			p->right = NULL;
		}
		else // right child has children
		{
		//if the node's right child has a left child
		// Move all the way down left to locate smallest element
		if((p->right)->left != NULL)
		{
			treenode *lcurr;
			treenode *lcurrp;
			lcurrp = p->right;
			lcurr = (p->right)->left;
			while(lcurr->left != NULL)
			{
				lcurrp = lcurr;
				lcurr = lcurr->left;
			}
			p = lcurr;
			delete lcurr;
			lcurrp->left = NULL;
		}
		else
		{
			treenode *tmp;
			tmp = p->right;
			p = tmp;
			p->right = tmp->right;
			delete tmp;
		}
		}//else
		return;
	}
}
//==============================================
void Edit_Program()
{
	char ch;
	int y=2;
	treenode *p;
	p=new treenode;
	p=NULL;
	p=Search_Code();
	if(!p)
		return;
	Print_Program(p);
	textcolor(WHITE);
	gotoxy(50,2);
	cprintf("<-");
	while(ch!=27)
	{
		ch=getch();
		textbackground(BLUE);
		textcolor(WHITE);
		gotoxy(50,y);
		cprintf("  ");
		if (ch==80) {
			y+=2;
			if (y>18)
				y=2;
		}
		else if (ch==72) {
			y-=2;
			if (y<2)
				y=18;
		}
		else if (ch==13) {
			gotoxy(19,y);
			textbackground(BLACK);
			cprintf("                          ");
			gotoxy(20,y);
		switch (y) {
			case 2:
				gets(p->data.name);
				break;
			case 4:
				cin>>p->data.code;
				break;
			case 6:
				cin>>p->data.date_create.day;
				gotoxy(23,6);
				cprintf("/");
				gotoxy(24,6);
				cin>>p->data.date_create.month;
				gotoxy(26,6);
				cprintf("/");
				gotoxy(27,6);
				cin>>p->data.date_create.year;
				break;
			case 8:
				cin>>p->data.date_show.day;
				gotoxy(23,8);
				cprintf("/");
				gotoxy(24,8);
				cin>>p->data.date_show.month;
				gotoxy(26,8);
				cprintf("/");
				gotoxy(27,8);
				cin>>p->data.date_show.year;
				break;
			case 10:
				cin>>p->data.date_first.day;
				gotoxy(23,10);
				cprintf("/");
				gotoxy(24,10);
				cin>>p->data.date_first.month;
				gotoxy(26,10);
				cprintf("/");
				gotoxy(27,10);
				cin>>p->data.date_first.year;
				break;
			case 12:
				cin>>p->data.repeat;
				break;
			case 14:
				gets(p->data.director);
				break;
			case 16:
				cin>>p->data.channel;
				break;
			case 18:
				gets(p->data.type);
				break;
		}//end of switch
		}//end of ch==13
		textbackground(BLUE);
		textcolor(WHITE);
		gotoxy(50,y);
		cprintf("<-");
	}
}
//==============================================
treenode* Search_Code()
{
	int code;
	textcolor(WHITE);
	clrscr();
	cprintf("Enter Your Code: ");
	cin>>code;
	treenode *p=root;
	while (p)
	{
		if (p->data.code==code)
			return p;
		if (p->data.code<code)
			p=p->right;
		else
			p=p->left;
	}
	textcolor(RED);
	gotoxy(35,3);
	cprintf("not found");
	getch();
	return NULL;
}
//==================================================
void Register_Show()
{
	clrscr();
	treenode *p;
	p=root;
	if (!p)
	{
		textcolor(RED);
		gotoxy(30,3);
		cprintf("Not found");
		getch();
		return;
	}
	InOrder5(p);
}
//==================================================
void InOrder5(treenode *cur)
{
	if (cur)
	{
		 InOrder5(cur->left);
		 if (cur->data.date_show.day==0 && cur->data.date_show.month==0 && cur->data.date_show.year==0)
		 {
			clrscr();
			Print_Program(cur);
			textbackground(BLUE);
			textcolor(WHITE);
			gotoxy(1,22);
			cprintf("Enter Day/month/year: ");
			gotoxy(1,23);
			cin>>cur->data.date_show.day;
			gotoxy(3,23);
			cprintf("/");
			gotoxy(4,23);
			cin>>cur->data.date_show.month;
			gotoxy(6,23);
			cprintf("/");
			gotoxy(7,23);
			cin>>cur->data.date_show.year;
			getch();
		 }
		 InOrder5(cur->right);
	}
}
//==================================================
void Register_First_Repeat()
{
	clrscr();
	treenode *p;
	p=root;
	if (!p)
	{
		textcolor(RED);
		gotoxy(30,3);
		cprintf("Not found");
		getch();
		return;
	}
	InOrder6(p);
}
//==================================================
void InOrder6(treenode *cur)
{
	if (cur)
	{
		 InOrder6(cur->left);
		 if (cur->data.date_first.day==0 && cur->data.date_first.month==0 && cur->data.date_first.year==0)
		 {
			clrscr();
			Print_Program(cur);
			textbackground(BLUE);
			textcolor(WHITE);
			gotoxy(1,22);
			cprintf("Enter Day/month/year: ");
			gotoxy(1,23);
			cin>>cur->data.date_first.day;
			gotoxy(3,23);
			cprintf("/");
			gotoxy(4,23);
			cin>>cur->data.date_first.month;
			gotoxy(6,23);
			cprintf("/");
			gotoxy(7,23);
			cin>>cur->data.date_first.year;
			getch();
		 }
		 InOrder6(cur->right);
	}
}

//==================================================
void Sort()
{
	row=3;
	clrscr();
	Print();
	InOrder(root);
	getch();
}
//==================================================
void InOrder(treenode *cur)
{
	if (cur)
	{
		 InOrder(cur->left);
		 Prints(cur);
		 InOrder(cur->right);
	}
}
//==================================================
void Print_Program(treenode *cur)
{
	int i,y=0;
	gotoxy(2,2);
	cprintf("Program name");
	gotoxy(2,4);
	cprintf("Program Code");
	gotoxy(2,6);
	cprintf("Date Create");
	gotoxy(2,8);
	cprintf("Date Show");
	gotoxy(2,10);
	cprintf("Date first Repeat");
	gotoxy(2,12);
	cprintf("Numbers of repeat");
	gotoxy(2,14);
	cprintf("Director Name");
	gotoxy(2,16);
	cprintf("Channel for Show");
	gotoxy(2,18);
	cprintf("Type Program");
	for (i=1;i<=9;i++)
	{
		gotoxy(19,y+=2);
		textbackground(BLACK);
		cprintf("                          ");
	}
	gotoxy(20,2);
	cprintf(cur->data.name);
	gotoxy(20,4);
	cprintf("%d",cur->data.code);
	gotoxy(20,6);
	cprintf("%d",cur->data.date_create.day);
	gotoxy(22,6);
	cprintf("/%d",cur->data.date_create.month);
	gotoxy(26,6);
	cprintf("/%d",cur->data.date_create.year);
	gotoxy(20,8);
	cprintf("%d",cur->data.date_show.day);
	gotoxy(22,8);
	cprintf("/%d",cur->data.date_show.month);
	gotoxy(26,8);
	cprintf("/%d",cur->data.date_show.year);
	gotoxy(20,10);
	cprintf("%d",cur->data.date_first.day);
	gotoxy(22,10);
	cprintf("/%d",cur->data.date_first.month);
	gotoxy(26,10);
	cprintf("/%d",cur->data.date_first.year);
	gotoxy(20,12);
	cprintf("%d",cur->data.repeat);
	gotoxy(20,14);
	cprintf("%s",cur->data.director);
	gotoxy(20,16);
	cprintf("%d",cur->data.channel);
	gotoxy(20,18);
	cprintf("%s",cur->data.type);
	getch();
}
//==============================================================
void Print_Date()
{
	clrscr();
	cprintf("Enter your date (day/month/year) : ");
	cin>>day>>month>>year;
	treenode *p;
	p=root;
	if (!p)
	{
		textcolor(RED);
		gotoxy(30,3);
		cprintf("Not found");
		getch();
		return;
	}
	Print();
	InOrder1(p);
	getch();
}
//==============================================================
void InOrder1(treenode *cur)
{
	if (cur)
	{
		 InOrder1(cur->left);
		 if (cur->data.date_show.day==day && cur->data.date_show.month==month && cur->data.date_show.year==year)
			Prints(cur);
		 InOrder1(cur->right);
	}
}
//==============================================================
void Print_Channel()
{
	int channel;
	clrscr();
	cprintf("Enter Your Channel: ");
	cin>>channel;
	treenode *p;
	p=root;
	if (!p)
	{
		textcolor(RED);
		gotoxy(30,3);
		cprintf("Not found");
		getch();
		return;
	}
	Print();
	InOrder2(p,channel);
	getch();
}
//==============================================================
void InOrder2(treenode *cur,int channel)
{
	if (cur)
	{
		 InOrder2(cur->left,channel);
		 if (cur->data.channel==channel)
			Prints(cur);
		 InOrder2(cur->right,channel);
	}
}
//==============================================================
void Print_Director()
{
	char dir[15];
	clrscr();
	cprintf("Enter Your Director: ");
	gets(dir);
	treenode *p;
	p=root;
	if (!p)
	{
		textcolor(RED);
		gotoxy(30,3);
		cprintf("Not found");
		getch();
		return;
	}
	Print();
	InOrder3(p,dir);
	getch();
}
//===============================================================
void InOrder3(treenode *cur,char dir[])
{
	if (cur)
	{
		 InOrder3(cur->left,dir);
		 if (strcmp(cur->data.director,dir)==0)
			Prints(cur);
		 InOrder3(cur->right,dir);
	}
}
//==============================================================
void Print_Repeat()
{
	int repeat;
	clrscr();
	cprintf("Enter Your Repeat Number: ");
	cin>>repeat;
	treenode *p;
	p=root;
	if (!p)
	{
		textcolor(RED);
		gotoxy(30,3);
		cprintf("Not found");
		getch();
		return;
	}
	Print();
	InOrder4(p,repeat);
	getch();
}
//==============================================================
void InOrder4(treenode *cur,int repeat)
{
	if (cur)
	{
		 InOrder4(cur->left,repeat);
		 if (cur->data.repeat==repeat)
			Prints(cur);
		 InOrder4(cur->right,repeat);
	}
}
//==============================================================
void Prints(treenode *cur)
{
	gotoxy(1,row);
	cprintf(cur->data.name);
	gotoxy(20,row);
	cprintf("%d",cur->data.code);
	gotoxy(30,row);
	cprintf("%d",cur->data.repeat);
	gotoxy(45,row);
	cprintf(cur->data.director);
	gotoxy(60,row);
	cprintf("%d",cur->data.channel);
	gotoxy(73,row);
	cprintf(cur->data.type);
	row+=2;
}
//====================================================
void Print()
{
	clrscr();
	int i;
	row=3;
	textcolor(YELLOW);
	clrscr();
	cprintf("Program Name");
	gotoxy(20,1);
	cprintf("Code");
	gotoxy(30,1);
	cprintf("Repaet");
	gotoxy(45,1);
	cprintf("Director");
	gotoxy(60,1);
	cprintf("Channel");
	gotoxy(73,1);
	cprintf("Type");
	gotoxy(1,2);
	for (i=1;i<=80;i++)
		cprintf("=");
}
//====================================================
void SaveFile()
{
	treenode *t;
	t=new treenode;
	t=root;
	f.open("bst.dat",ios::out | ios::beg);
	if (!f)
	{
		cprintf("Can not open File...");
		getch();
		return;
	}
	InOrder7(t);
	f.close();
}
//===================================================
void InOrder7(treenode *cur)
{
	InOrder7(cur->left);
	f.write((char*)&cur->data,sizeof(struct treenode));
	InOrder7(cur->right);
}
//====================================================
void ReadFile()
{
	treenode *t;
	t=new treenode;
	f.open("bst.dat",ios::in);
	if (!f)
	{
		cprintf("Can not open File...");
		getch();
		return;
	}
	while (!f.eof())
	{
		f.read((char*)&(t->data),sizeof(struct treenode));
		Print_Program(t);
	}
	f.close();
}