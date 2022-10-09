#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream.h>
///////////////////////////////////////////////////////////////////////
char s[10][20]={"Football","Basketball","volleyball","Wrestling",
"Tennis","Ping Pong","Water polo","Badminton","Horse Racing","Kungfo"};
int ID[100],cnt,col=3;
void Border();
void field();
ofstream save;
ifstream load;
////////////////////////////////////////////////////////////////////////
struct Date {
	int day;
	int month;
	int year;
	};
///////////////////////////////////////////////////////////////////////
struct Data
{
	int  id;
	char name[50];
	char family[50];
	char father[50];
	char field[10][20];
	char sh[20];
	char melli[20];
	char birth[20];
	Date membership;
	Date credit;
};
struct Member
{
	Data d;
	Member *left,*right;
};
/////////////////////////////////////////////////////////////////////////
class BST {
	Member *root;
	public:
		BST() { root=NULL; };
		Member* GetRoot() { return root; };
		Member* Search(int);
		int  Insert();
		int Search(Member*);
		void Revival();
		void Edit();
		void Delete();
		void ShowField();
		void ShowCreditExpire();
		void Inorder(Member*,int);
		void Inorder(Member*,char*);
		void Inorder(Member*);
		void Inorder2(Member*,Date);
		void ShowMember(Member*);
		void ShowOneMember();
		void NewTree(Member*);
		void SearchFamily();
		void Save(Member*);
		void Load();
	};
///////////////////////////////////////////////////////////////////////////
int BST::Insert()
{
	Member *p,*q,*t=new Member();
	int x,sw,n;
	char ans='y',temp[10];
	long money=0;
	p=root;
	q=NULL;
	gotoxy(1,1);
	cprintf("Press any key to start");
	gets(temp);
	gotoxy(25,2);  gets(t->d.name);
	gotoxy(25,4);  gets(t->d.family);
	gotoxy(25,6);  gets(t->d.father);
	gotoxy(25,8);  gets(t->d.sh);
	gotoxy(25,10); gets(t->d.melli);
	gotoxy(25,12); gets(t->d.birth);
	gotoxy(25,14); cprintf("dd/mm/yyyy");
	gotoxy(25,14); scanf("%d",&t->d.membership.day);
	gotoxy(28,14); scanf("%d",&t->d.membership.month);
	gotoxy(31,14); scanf("%d",&t->d.membership.year);
	gotoxy(25,16); cin>>money;
	money/=1000;
	t->d.credit.day=t->d.membership.day;
	t->d.credit.month=t->d.membership.month;
	t->d.credit.year=t->d.membership.year;
	t->d.credit.month+=money;
	while (t->d.credit.month>12)
	{
		t->d.credit.year++;
		t->d.credit.month-=12;
	}
	gotoxy(25,18); cprintf("%d",t->d.credit.day);
	gotoxy(28,18); cprintf("/%d",t->d.credit.month);
	gotoxy(31,18); cprintf("/%d",t->d.credit.year);
	randomize();
	sw=0;
	do
	{
		x=random(100)+1;
		for (int i=0;i<100;i++)
		{
			if (x==ID[i])
				sw=1;
		}
		if (sw==0)
			ID[cnt++]=x;
	}while (sw==1);
	gotoxy(40,18); cprintf("Your membership code: %d",x);
	for (int i=0;i<10;i++)
		t->d.field[i][0]=0;
	i=0;

	do {
		textcolor(15);
		gotoxy(25,20); scanf("%d",&n);
		strcpy(t->d.field[i++],s[n-1]);
		gotoxy(25,20); cprintf("Do want to continue (y/n): ");
		cin>>ans;
		textcolor(1);
		gotoxy(25,20); printf("                            ");
	}while (ans=='y');
	while (p)
	{
		q=p;
		if (p->d.id==x)
			return 0;
		if (p->d.id<x)
			p=p->right;
		else
			p=p->left;
	}
	p=new Member;
	p=t;
	p->d.id=x;
	p->left=p->right=NULL;
	if (!root)
		root=p;
	if (q->d.id<x)
		q->right=p;
	else
		q->left=p;
	return 1;
}
///////////////////////////////////////////////////////////////////////
void BST::Delete()
{
	int id,found=0;
	textcolor(15);
	clrscr();
	Member *p,*q;
	p=root;
	cout<<"Enter a Membership code: ";
	cin>>id;
	if(!p)
	{
		cout<<"Not Found";
		getch();
		return;
	}
	while(p)
	{
		if(p->d.id==id)
		{
			found = 1;
			break;
		}
		else
		{
			q=p;
			if (p->d.id<id)
				p=p->right;
			else
			p=p->left;
		}
	}

	if(!found)
	{
		cout<<"not found!";
		getch();
		return;
	}
	cout<<"Deleted...";
	getch();
	//agar p barg bashad
	if( p->left == NULL && p->right == NULL)
	{
		if(q->left == p)
			q->left = NULL;
		else
			q->right = NULL;
		delete p;
		return;
	}

	if((p->left == NULL && p->right != NULL)|| (p->left != NULL && p->right == NULL))
	{
		//1 farzande rast dashte bashad
		if(p->left == NULL && p->right != NULL)
		{
			if(q->left == p)
			{
				q->left = p->right;
				delete p;
			}
			else
			{
				q->right = p->right;
				delete p;
			}
		}
		else // 1 farzande chap dashte bashad
		{
			if(q->left == p)
			{
				q->left = p->left;
				delete p;
			}
			else
			{
				q->right = p->left;
				delete p;
			}
		}
		return;
	}
	//2 farzand dashte bashad (ba koochektarine samte rast avaz mishavad
	if (p->left != NULL && p->right != NULL)
	{
		Member *pR;
		pR=p->right;
		if((pR->left==NULL) && (pR->right == NULL))
		{
			p=pR;
			delete pR;
			p->right=NULL;
		}
		else // agar samte rasti farzand dashte bashad
		{
		//agar in samte rasti farzande chap dashte bashad
		// peida kardane koochektarine samte chap
		if((p->right)->left != NULL)
		{
			Member *hlp1;       //lpr=hlp1
			Member *hlp2;     //lprp=hlp2
			hlp2=p->right;
			hlp1=(p->right)->left;
			while(hlp1->left!=NULL)
			{
				hlp2=hlp1;
				hlp1=hlp1->left;
			}
			p->d.id=hlp1->d.id;
			delete hlp1;
			hlp2->left = NULL;
		}
		else
		{
			Member *temp;
			temp=p->right;
			p->d.id=temp->d.id;
			p->right=temp->right;
			delete temp;
		}
		}//else
		return;
	}
}
///////////////////////////////////////////////////////////////////////
int BST::Search (Member * cur)
{
	Member *p=root;
	while (p)
	{
		if (p->d.id==cur->d.id)
		{
			return 1;
		}
		else if (p->d.id<cur->d.id)
			p=p->right;
		else
			p=p->left;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////
Member* BST::Search (int x)
{
	Member *p=root;
	while (p)
	{
		if (p->d.id==x)
		{
			return p;
		}
		else if (p->d.id<x)
			p=p->right;
		else
			p=p->left;
	}
	return NULL;
}
///////////////////////////////////////////////////////////////////////
void BST::Revival()
{
	textcolor(15);
	clrscr();
	int id;
	long money;
	Member *cur=new Member();
	cprintf("Enter a membership code: ");
	cin>>id;
	cur=Search(id);
	if (cur)
	{
		gotoxy(1,4);cprintf("Signin Date: %d/%d/%d",cur->d.membership.day,cur->d.membership.month,cur->d.membership.year);
		gotoxy(1,5);cprintf("Credit Date: %d/%d/%d",cur->d.credit.day,cur->d.credit.month,cur->d.credit.year);
		gotoxy(1,7);
		cprintf("Enter money: ");
		cin>>money;
		money/=1000;
		cur->d.credit.month+=money;
		while (cur->d.credit.month>12)
		{
			cur->d.credit.year++;
			cur->d.credit.month-=12;
		}
		gotoxy(1,10);cprintf("New Credit Date: %d/%d/%d",cur->d.credit.day,cur->d.credit.month,cur->d.credit.year);
	}
	else
	{
		gotoxy(1,2);
		cprintf("Not Found");
	}
	getch();
}
///////////////////////////////////////////////////////////////////////
void BST::Edit()
{
	textcolor(15);
	clrscr();
	int n,id;
	char ans='y';
	Member *cur=new Member();
	cprintf("Enter a Membership code: ");
	cin>>id;
	cur=Search(id);
	if (cur)
	{
		col=3;
		Border();
		ShowMember(cur);
		gotoxy(1,7);cprintf("Name: %s",cur->d.name);//7
		gotoxy(1,8);cprintf("Family: %s",cur->d.family);//9
		gotoxy(1,9);cprintf("Father: %s",cur->d.father);//9
		gotoxy(1,10);cprintf("Identity code: %s",cur->d.sh);//15
		gotoxy(1,11);cprintf("National code: %s",cur->d.melli);//15
		gotoxy(1,12);cprintf("BirthYear: %s",cur->d.birth);//12
		gotoxy(1,14);cprintf("Enter 1...6 for edit: ");
		do {
			do {
				textcolor(15);
				gotoxy(1,15);
				cin>>n;
				gotoxy(1,15);
				textcolor(1);
				printf("                       ");
			} while (n<1||n>6);
			switch (n)
			{
				case 1:
					gotoxy(7,7);
					printf("                ");
					textcolor(15);
					gotoxy(7,7);
					cin>>cur->d.name;
					break;

				case 2:
					gotoxy(9,8);
					printf("                ");
					textcolor(15);
					gotoxy(9,8);
					cin>>cur->d.family;
					break;
				case 3:
					gotoxy(9,9);
					printf("                ");
					textcolor(15);
					gotoxy(9,9);
					cin>>cur->d.father;
					break;
				case 4:
					gotoxy(15,10);
					printf("                ");
					textcolor(15);
					gotoxy(15,10);
					cin>>cur->d.sh;
					break;
				case 5:
					gotoxy(15,11);
					printf("                ");
					textcolor(15);
					gotoxy(15,11);
					cin>>cur->d.melli;
					break;
				case 6:
					gotoxy(12,12);
					printf("                ");
					textcolor(15);
					gotoxy(12,12);
					cin>>cur->d.birth;
					break;
			}
			gotoxy(1,17);
			cprintf("Do you want to conitue (y/n): ");
			cin>>ans;
			gotoxy(1,17);
			cprintf("                                ");
		}while (ans=='y');
	}//if
	else
	{
		cprintf("\nNot Found!");
		getch();
	}
}
///////////////////////////////////////////////////////////////////////
void BST::ShowMember(Member *cur)
{
	gotoxy(1,col); cprintf("%d",cur->d.id);
	gotoxy(10,col);cprintf("%s",cur->d.name);
	gotoxy(20,col);cprintf("%s",cur->d.family);
	gotoxy(30,col);cprintf("%s",cur->d.father);
	gotoxy(45,col);cprintf("%s",cur->d.birth);
	gotoxy(56,col);cprintf("%d/%d/%d",cur->d.membership.day,cur->d.membership.month,cur->d.membership.year);
	gotoxy(70,col);cprintf("%d/%d/%d",cur->d.credit.day,cur->d.credit.month,cur->d.credit.year);
	col++;
}
///////////////////////////////////////////////////////////////////////
void BST::ShowOneMember()
{
	textcolor(15);
	clrscr();
	int id;
	Member *cur=new Member();
	cprintf("Enter a Membership code: ");
	cin>>id;
	cur=Search(id);
	if (cur)
	{
		clrscr();
		Border();
		col=3;
		ShowMember(cur);
	}
	else
		cprintf("Not Found!");

	getch();
}
///////////////////////////////////////////////////////////////////////
void BST::Inorder(Member *currentnode)
{
	if (currentnode) {
		Inorder(currentnode->left);
		ShowMember(currentnode);
		Inorder(currentnode->right);
	}
}
///////////////////////////////////////////////////////////////////////
void BST::Inorder(Member *cur,int n)
{
	if (cur)
	{
		Inorder(cur->left,n);
		for (int i=0;i<10;i++)
		{
			if (strcmp(cur->d.field[i],s[n-1])==0)
				ShowMember(cur);
		}
		Inorder(cur->right);
	}
}
///////////////////////////////////////////////////////////////////////
void BST::Inorder(Member *cur,char s[])
{
	if (cur)
	{
		Inorder(cur->left,s);
		if (strcmp(cur->d.family,s)==0)
			ShowMember(cur);
		Inorder(cur->right);
	}
}
///////////////////////////////////////////////////////////////////////
void BST::Inorder2(Member *cur,Date today)
{
	if (cur)
	{
		Inorder2(cur->left,today);
		if (cur->d.credit.year<today.year)
			ShowMember(cur);
		else if (cur->d.credit.year==today.year && cur->d.credit.month<today.month)
			ShowMember(cur);
		else if (cur->d.credit.year==today.year && cur->d.credit.month==today.month && cur->d.credit.day<today.day)
			ShowMember(cur);
		Inorder2(cur->right,today);
	}
}
///////////////////////////////////////////////////////////////////////
void BST::ShowField()
{
	textcolor(15);
	clrscr();
	int i,j,n;
	textcolor(15);
	for (i=1,j=9;i<=5;i++,j+=15)
	{
		gotoxy(j,1); cprintf("%d",i);
	}
	for (i=6,j=9;i<=10;i++,j+=15)
	{
		gotoxy(j,3); cprintf("%d",i);
	}
	gotoxy(1,22);
	for (i=4,j=0;i<65;i+=15,j++)
	{
		gotoxy(i,2);
		cprintf("%s",s[j]);
	}
	for (i=4,j=5;i<65;i+=15,j++)
	{
		gotoxy(i,4);
		cprintf("%s",s[j]);
	}
	gotoxy(1,7);
	cprintf("Enter a number (1...10): ");
	do {
		gotoxy(1,8);
		cin>>n;
		gotoxy(1,8);
		cout<<"               ";
	} while (n<1 || n>10);
	col=10;
	Inorder(root,n);
	getch();
}
///////////////////////////////////////////////////////////////////////
void BST::ShowCreditExpire()
{
	textcolor(15);
	clrscr();
	int d,m,y;
	cprintf("Enter Today date: dd/mm/yyyy");
	gotoxy(19,1); scanf("%d",&d);
	gotoxy(22,1); scanf("%d",&m);
	gotoxy(25,1); scanf("%d",&y);
	col=4;
	Date t;
	t.day=d;
	t.month=m;
	t.year=y;
	Inorder2(root,t);
	getch();
}
///////////////////////////////////////////////////////////////////////
void BST::SearchFamily()
{
	textcolor(15);
	clrscr();
	char f[30];
	cprintf("Enter a family: ");
	cin>>f;
	col=3;
	Inorder(root,f);
	getch();
}
///////////////////////////////////////////////////////////////////////
void BST::Save(Member *cur)
{
	if (cur)
	{
		Save(cur->left);
		save.write((char*)&cur->d.id,sizeof (struct Data));
		Save(cur->right);
	}
}
///////////////////////////////////////////////////////////////////////
void BST::Load()
{
	load.open("c:\\Members",ios::binary);
	Member *p,*q;
	Data d;
	if (!load)
	{
		gotoxy(30,20);
		cprintf("Can not open file");
		getch();
	}
	else {
	while(!load.eof())
	{
	load.read((char*)&d.id,sizeof(struct Data));
	p=root;
	q=NULL;
	while (p)
	{
		q=p;
		if (p->d.id==d.id)
			return ;
		if (p->d.id<d.id)
			p=p->right;
		else
			p=p->left;
	}
	p=new Member;
	p->d=d;
	p->d.id=d.id;
	p->left=p->right=NULL;
	if (!root)
		root=p;
	if (q->d.id<p->d.id)
		q->right=p;
	else
		q->left=p;
	}
	load.close();
	}
}
///////////////////////////////////////////////////////////////////////
void Border()
{
	clrscr();
	textcolor(15);
	int i;
	gotoxy(1,1); cprintf("ID");
	gotoxy(10,1);cprintf("Name");
	gotoxy(20,1);cprintf("Family");
	gotoxy(30,1);cprintf("Father name");
	gotoxy(45,1);cprintf("Birthday");
	gotoxy(56,1);cprintf("SignIn Date");
	gotoxy(70,1);cprintf("Credit Date");
	for (i=1;i<=80;i++)
		cprintf("~");
}
///////////////////////////////////////////////////////////////////////
void Board()
{
	int i,j;
	textbackground(1);
	textcolor(15);
	clrscr();
	gotoxy(5,2);  cprintf("First Name      :");
	gotoxy(5,4);  cprintf("Last Name       :");
	gotoxy(5,6);  cprintf("Father Name     :");
	gotoxy(5,8);  cprintf("Identity Number :");
	gotoxy(5,10); cprintf("National Number :");
	gotoxy(5,12); cprintf("Birth Year      :");
	gotoxy(5,14); cprintf("Membership Date :");
	gotoxy(5,16); cprintf("Enter Your Money:");
	gotoxy(5,18); cprintf("Credit Date Card:");
	gotoxy(5,20); cprintf("Enter your choice:");
}
///////////////////////////////////////////////////////////////////////////
void field()
{
	int i,j;
	textcolor(15);
	for (i=1,j=9;i<=5;i++,j+=15)
	{
		gotoxy(j,22); cprintf("%d",i);
	}
	for (i=6,j=9;i<=10;i++,j+=15)
	{
		gotoxy(j,24); cprintf("%d",i);
	}
	gotoxy(1,22);
	for (i=4,j=0;i<65;i+=15,j++)
	{
		gotoxy(i,23);
		cprintf("%s",s[j]);
	}
	for (i=4,j=5;i<65;i+=15,j++)
	{
		gotoxy(i,25);
		cprintf("%s",s[j]);
	}
}
//////////////////////////////////////////////////////////////////////////
void Menu()
{
	BST bst;
	int row=6;
	char ch;
	bst.Load();
showagain://Label
	textcolor(15);
	textbackground(1);
	clrscr();
	gotoxy(22,2);
	cprintf("***<<SPORT CLUB MANAGEMENT SYSTEM>>***");
	gotoxy(6,6);cprintf("[ ] Insert New Member");
	gotoxy(6,7);cprintf("[ ] Delete Member");
	gotoxy(6,8);cprintf("[ ] Revival Member's Credit Date");
	gotoxy(6,9);cprintf("[ ] Edit Member's Info");
	gotoxy(6,10);cprintf("[ ] Show All Club Members");
	gotoxy(6,11);cprintf("[ ] Show All Branch Members");
	gotoxy(6,12);cprintf("[ ] Show All Club Members (Exp.)");
	gotoxy(6,13);cprintf("[ ] Search by ID");
	gotoxy(6,14);cprintf("[ ] Search by Name");
	gotoxy(6,15);cprintf("[ ] Save Data");
	gotoxy(6,16);cprintf("[ ] Exit From Program");
	textcolor(12);
	gotoxy(7,row);cprintf(">");
	while(1)
	{
		gotoxy(80,25);
		ch=getch();
		gotoxy(7,row);cprintf(" ");
		if(ch==13)
		{
			if(row==6)
			{
				Board();
				field();
				bst.Insert();
				goto showagain;
			}
			else if(row==7)
			{
				bst.Delete();
				goto showagain;
			}
			else if(row==8)
			{
				bst.Revival();
				goto showagain;
			}
			else if(row==9)
			{
				bst.Edit();
				goto showagain;
			}
			else if(row==10)
			{
				col=3;
				Border();
				bst.Inorder(bst.GetRoot());
				getch();
				goto showagain;
			}
			else if(row==11)
			{
				bst.ShowField();
				goto showagain;
			}
			else if(row==12)
			{
				bst.ShowCreditExpire();
				goto showagain;
			}
			else if(row==13)
			{
				bst.ShowOneMember();
				goto showagain;
			}
			else if(row==14)
			{
				bst.SearchFamily();
				goto showagain;
			}
			else if(row==15)
			{       save.open("c:\\Members",ios::binary);
				if (save)
				{
				bst.Save(bst.GetRoot());
				save.close();
				gotoxy(30,20);
				textcolor(RED);
				cprintf("Saved file");
				getch();
				}
			}
			else if (row==16)
				return;
		}
		else if(ch==80)
		{
			row++;
			if(row==17) row=6;
		}
		else if(ch==72)
		{
			row--;
			if(row==5) row=16;
		}
		else if (ch==27)
		{
			return;
		}
		gotoxy(7,row);cprintf(">");
	}//while
}//menu
//////////////////////////////////////////////////////////////////////////
void main()
{
	Menu();
}