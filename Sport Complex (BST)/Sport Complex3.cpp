#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>
#include<stdlib.h>
ofstream save;
ifstream load;
int ID[100],count=0;
int y;

struct Info
{
	int  code;
	char first[20],last[20],father[20];
	int  sport[4];
	char shsh[10],meli[10],birth[5];
	int d,m,y;
	int creditD,creditM,creditY;
};
struct Listnode
{
	Info data;
	Listnode *left,*right;
};

char Sport[4][20]={"Football","Basketball","volleyball","Wrestling"};

class BST {
	public:
		Listnode *root;
		BST() { root=NULL; };
		Listnode* Search(int);
		int Search(Listnode*);
		int  Insert();
		void Tamdid();
		void Edit();
		void Delete();
		void ShowField();
		void ShowCreditExpire();
		void InorderBySport(Listnode*,int);
		void InorderByFamily(Listnode*,char*);
		void InorderByCode(Listnode*);
		void InorderByExpire(Listnode*,int,int,int);
		void ShowMember(Listnode*);
		void Show1();
		void NewTree(Listnode*);
		void SearchFamily();
		void Save(Listnode*);
		void Load();
	};
BST bst;

int BST::Insert()
{
	Info data;
	int n;
	long money;
	clrscr();
	cout<<"\nName              : ";
	cout<<"\nLast Name         : ";
	cout<<"\nFather Name       : ";
	cout<<"\nID Number         : ";
	cout<<"\nMelli code        : ";
	cout<<"\nBirth Year        : ";
	cout<<"\nSignIn Date(D/M/Y): ";
	cout<<"\nPay Money         : ";
	cout<<"\nCredit Date Card  : ";
	cout<<"\nID                : ";

	gotoxy(30,2);  cin>>data.first;
	gotoxy(30,3);  cin>>data.last;
	gotoxy(30,4);  cin>>data.father;
	gotoxy(30,5);  cin>>data.shsh;
	gotoxy(30,6); cin>>data.meli;
	gotoxy(30,7); cin>>data.birth;
	gotoxy(30,8); cin>>data.d;
	gotoxy(33,8); cin>>data.m;
	gotoxy(36,8); cin>>data.y;
	gotoxy(30,9); cin>>money;
	money/=1000;
	data.creditD=data.d;
	data.creditM=data.m;
	data.creditY=data.y;
	data.creditM+=money;

	while (data.creditM>12)
	{
		data.creditY++;
		data.creditM-=12;
	}

	gotoxy(30,10); cout<<data.creditD;
	gotoxy(33,10); cout<<data.creditM;
	gotoxy(36,10); cout<<data.creditY;
	data.code=ID[count++];
	gotoxy(30,11); cout<<data.code;
	gotoxy(1,13);
	cout<<"Now,Your are Member...Please press any key to select your sports: ";
	getch();

	clrscr();
	for (int i=0;i<4;i++)
	{
		cout<<i+1<<"\t"<<Sport[i]<<"\n";
		data.sport[i]=0;
	}

	do {
		gotoxy(1,12);
		cout<<"Enter a number (1...4): ";
		gotoxy(1,13);
		cin>>n;
		data.sport[n-1]=1;
		gotoxy(1,13);
		cout<<"             ";

	} while(n<1||n>4);

	Listnode *p,*q;
	p=root;
	q=NULL;

	while (p)
	{
		q=p;
		if (p->data.code==data.code)
			return 0;
		if (p->data.code<data.code)
			p=p->right;
		else
			p=p->left;
	}
	p=new Listnode();
	p->data=data;
	p->left=p->right=NULL;
	if (!root)
		root=p;
	if (q->data.code<p->data.code)
		q->right=p;
	else
		q->left=p;
	return 1;
}
///////////////////////////////////////////////////////////////////////
void BST::Delete()
{
	int id,found=0;
	clrscr();
	Listnode *p,*q;
	p=root;
	cout<<"Enter a code: ";
	cin>>id;
	if(!p)
	{
		cout<<"Not Found";
		getch();
		return;
	}
	while(p)
	{
		if(p->data.code==id)
		{
			found = 1;
			break;
		}
		else
		{
			q=p;
			if (p->data.code<id)
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
		else
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
	if (p->left != NULL && p->right != NULL)
	{
		Listnode *pR;
		pR=p->right;
		if((pR->left==NULL) && (pR->right == NULL))
		{
			p->data.code=pR->data.code;
			delete pR;
			p->right=NULL;
		}
		else
		{
		if((p->right)->left != NULL)
		{
			Listnode *hlp1;
			Listnode *hlp2;
			hlp2=p->right;
			hlp1=(p->right)->left;
			while(hlp1->left!=NULL)
			{
				hlp2=hlp1;
				hlp1=hlp1->left;
			}
			p->data.code=hlp1->data.code;
			delete hlp1;
			hlp2->left = NULL;
		}
		else
		{
			Listnode *temp;
			temp=p->right;
			p->data.code=temp->data.code;
			p->right=temp->right;
			delete temp;
		}
		}
		return;
	}
}
///////////////////////////////////////////////////////////////////////
int BST::Search (Listnode * cur)
{
	Listnode *p=root;
	while (p)
	{
		if (p->data.code==cur->data.code)
		{
			return 1;
		}
		else if (p->data.code<cur->data.code)
			p=p->right;
		else
			p=p->left;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////
Listnode* BST::Search (int id)
{
	Listnode *p=root;
	while (p)
	{
		if (p->data.code==id)
		{
			return p;
		}
		else if (p->data.code<id)
			p=p->right;
		else
			p=p->left;
	}
	return NULL;
}
///////////////////////////////////////////////////////////////////////
void BST::Tamdid()
{
	clrscr();
	int id;
	long money;
	Listnode *cur=new Listnode();
	cout<<"Enter a code: ";
	cin>>id;
	cur=Search(id);
	if (cur)
	{
		cout<<"\nCredit Date: "
			<<cur->data.creditD<<"\\"
			<<cur->data.creditM<<"\\"
			<<cur->data.creditY;
		gotoxy(1,7);
		cout<<"\nEnter money: ";
		cin>>money;
		money/=1000;
		cur->data.creditM+=money;
		while (cur->data.creditM>12)
		{
			cur->data.creditY++;
			cur->data.creditM-=12;
		}
		cout<<"\n\nNew Credit Date: "<<cur->data.creditD<<"\\"<<cur->data.creditM<<"\\"<<cur->data.creditY;
	}
	else
	{
		cout<<"\nNot Found";
	}
	getch();
}
///////////////////////////////////////////////////////////////////////
void BST::Edit()
{
	clrscr();
	int n,id,j;
	char ch;
	Listnode *cur=new Listnode();
	cout<<"Enter a code: ";
	cin>>id;
	cur=Search(id);
	if (cur)
	{
		gotoxy(3,4);cout<<"Name: "<<cur->data.first;
		gotoxy(3,5);cout<<"Family: "<<cur->data.last;
		gotoxy(3,6);cout<<"Father: "<<cur->data.father;
		gotoxy(3,7);cout<<"Identity code: "<<cur->data.shsh;
		gotoxy(3,8);cout<<"National code: "<<cur->data.meli;
		gotoxy(3,9);cout<<"BirthYear: "<<cur->data.birth;
		gotoxy(1,4);
		cout<<"->";
		do {
			ch=getch();
			gotoxy(1,j);
			cout<<"  ";
			if (ch==80)
				j++;
			else if (ch==72)
				j--;
			else if (ch==13)
			{
				switch (j)
				{
				 case 4:
					gotoxy(10,4);
					cout<<"                ";
					gotoxy(10,4);
					cin>>cur->data.first;
					break;
				case 5:
					gotoxy(12,5);
					cout<<"                ";
					gotoxy(12,5);
					cin>>cur->data.last;
					break;
				case 6:
					gotoxy(12,6);
					cout<<"                ";
					gotoxy(12,6);
					cin>>cur->data.father;
					break;
				case 7:
					gotoxy(19,7);
					cout<<"                ";
					gotoxy(19,7);
					cin>>cur->data.shsh;
					break;
				case 8:
					gotoxy(19,8);
					cout<<"                ";
					gotoxy(19,8);
					cin>>cur->data.meli;
					break;
				case 9:
					gotoxy(15,9);
					cout<<"                ";
					gotoxy(15,9);
					cin>>cur->data.birth;
					break;
				}
			}
			if (j>9) j=4;
			if (j<4) j=9;
			gotoxy(1,j);
			cout<<"->";
		}while(ch!=27);
	}//if
	else
	{
		cout<<"\nNot Found!";
		getch();
	}
}
///////////////////////////////////////////////////////////////////////
void BST::ShowMember(Listnode *cur)
{
	gotoxy(1,y); cout<<cur->data.code;
	gotoxy(10,y);cout<<cur->data.first;
	gotoxy(20,y);cout<<cur->data.last;
	gotoxy(30,y);cout<<cur->data.father;
	gotoxy(45,y);cout<<cur->data.birth;
	gotoxy(56,y);cout<<cur->data.d<<"\\"<<cur->data.m<<"\\"<<cur->data.y;
	gotoxy(70,y);cout<<cur->data.creditD<<"\\"<<cur->data.creditM<<"\\"<<cur->data.creditY;
	y++;
}
///////////////////////////////////////////////////////////////////////
void BST::Show1()
{
	clrscr();
	int id;
	Listnode *cur=new Listnode();
	cout<<"Enter a Membership code: ";
	cin>>id;
	cur=Search(id);
	if (cur)
	{
		clrscr();
		y=3;
		ShowMember(cur);
	}
	else
		cout<<"Not Found!";
	getch();
}
///////////////////////////////////////////////////////////////////////
void BST::InorderByCode(Listnode *currentnode)
{
	if (currentnode) {
		InorderByCode(currentnode->left);
		ShowMember(currentnode);
		InorderByCode(currentnode->right);
	}
}
///////////////////////////////////////////////////////////////////////
void BST::InorderBySport(Listnode *cur,int n)
{
	if (cur)
	{
		InorderBySport(cur->left,n);
		if (cur->data.sport[n-1]==1)
				ShowMember(cur);
		InorderBySport(cur->right,n);
	}
}
///////////////////////////////////////////////////////////////////////
void BST::InorderByFamily(Listnode *cur,char s[])
{
	if (cur)
	{
		InorderByFamily(cur->left,s);
		if (strcmp(cur->data.last,s)==0)
			ShowMember(cur);
		InorderByFamily(cur->right,s);
	}
}
///////////////////////////////////////////////////////////////////////
void BST::InorderByExpire(Listnode *cur,int d,int m,int y)
{
	if (cur)
	{
		InorderByExpire(cur->left,d,m,y);
		if (cur->data.creditY<y)
			ShowMember(cur);
		else if (cur->data.creditY==y && cur->data.creditM<m)
			ShowMember(cur);
		else if (cur->data.creditY==y && cur->data.creditM==m && cur->data.creditD<d)
			ShowMember(cur);
		InorderByExpire(cur->right,d,m,y);
	}
}
///////////////////////////////////////////////////////////////////////
void BST::ShowCreditExpire()
{
	clrscr();
	int d,m,y;
	cout<<"Enter Today date: dd/mm/yyyy";
	gotoxy(19,1); cin>>d;
	gotoxy(22,1); cin>>m;
	gotoxy(25,1); cin>>y;
	y=4;
	InorderByExpire(root,d,m,y);
	getch();
}
///////////////////////////////////////////////////////////////////////
void BST::SearchFamily()
{
	clrscr();
	char f[30];
	cout<<"Enter a family: ";
	cin>>f;
	y=3;
	InorderByFamily(root,f);
	getch();
}
///////////////////////////////////////////////////////////////////////
void BST::Save(Listnode *cur)
{
	if (cur)
	{
		Save(cur->left);
		save.write((char*)&cur->data.code,sizeof (struct Info));
		Save(cur->right);
	}
}
///////////////////////////////////////////////////////////////////////
void BST::Load()
{
	load.open("c:\\Members",ios::binary);
	Listnode *p,*q;
	Info d;
	if (!load)
	{
		gotoxy(30,20);
		cout<<"Can not open file";
		getch();
	}
	else {
	while(!load.eof())
	{
	load.read((char*)&d.code,sizeof(struct Info));
	p=root;
	q=NULL;
	while (p)
	{
		q=p;
		if (p->data.code==d.code)
			return ;
		if (p->data.code<d.code)
			p=p->right;
		else
			p=p->left;
	}
	p=new Listnode;
	p->data=d;
	p->data.code=d.code;
	p->left=p->right=NULL;
	if (!root)
		root=p;
	if (q->data.code<p->data.code)
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
	gotoxy(1,1); cout<<"ID";
	gotoxy(10,1);cout<<"Name";
	gotoxy(20,1);cout<<"Family";
	gotoxy(30,1);cout<<"Father name";
	gotoxy(45,1);cout<<"Birthday";
	gotoxy(56,1);cout<<"SignIn Date";
	gotoxy(70,1);cout<<"Credit Date";
	for (i=1;i<=80;i++)
		cout<<"~";
}

void Menu()
{
	int n;
	clrscr();
	cout<<"\n1.Insert";
	cout<<"\n2.Delete";
	cout<<"\n3.Credit Date";
	cout<<"\n4.Edit";
	cout<<"\n5.Show All Members";
	cout<<"\n6.Show All Special Sport";
	cout<<"\n7.Show All Expire Date";
	cout<<"\n8.Search by ID";
	cout<<"\n9.Search by Family";
	cout<<"\n10.Save";
	cout<<"\n11.Exit";
	cout<<"\n\nEnter a number (1...11): ";

	do {

		gotoxy(1,15);cout<<"         ";
		gotoxy(1,15);cin>>n;
	}while (n<1||n>11);

	switch(n)
	{
		case 1:
			bst.Insert();
			Menu();
			break;
		case 2:
			bst.Delete();
			Menu();
			break;
		case 3:
			bst.Tamdid();
			Menu();
			break;
		case 4:
			bst.Edit();
			Menu();
			break;
		case 5:
			clrscr();
			Border();
			y=3;
			bst.InorderByCode(bst.root);
			getch();
			Menu();
			break;
		case 6:
			clrscr();
			int n;
			do {
				gotoxy(1,1);
				cout<<"Enter a number (1...4): ";
				gotoxy(1,2);
				cin>>n;
				gotoxy(1,2);
				cout<<"             ";
			} while(n<1||n>4);
			clrscr();
			Border();
			y=3;
			bst.InorderBySport(bst.root,n);
			getch();
			Menu();
			break;
		case 7:
			bst.ShowCreditExpire();
			Menu();
			break;
		case 8:
			bst.Show1();
			Menu();
			break;
		case 9:
			bst.SearchFamily();
			Menu();
			break;
		case 10:
			clrscr();
			save.open("c:\\Members",ios::binary);
			if (save)
			{
				bst.Save(bst.root);
				cout<<"saved";
				getch();
			}
			Menu();
			break;
		case 11:
			exit(0);
			break;
	}
}

void main()
{
	int sw,i,j,x;
	randomize();
	for (i=0;i<100;)
	{
		sw=0;
		x=random(100)+1;
		for(j=0;j<i;j++)
			if (x==ID[j])
				sw=1;
		if(!sw)
			ID[i++]=x;
	}
	bst.Load();
	Menu();
}