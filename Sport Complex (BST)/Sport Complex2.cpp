#include<dos.h>
#include<conio.h>
#include<iostream.h>
#include<fstream.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void menu();
void searchmenu();
void fieldsmenu();
void showmenu();
ofstream save;
ifstream load;
int i;

char reshteha[4][30]={{"Footbal"},{"Valyball"},{"Basketball"},{"Tennis"}};
int codereshteha[4]={11,12,13,14};

struct mydate
{
	int date,month,year;
};
struct treenode
{
	char name1[50],name2[50],fname[50];
	long int shsh,melli;
	int birth,id;
	mydate begdate;
	int sumdate;  //tedad roozhaye etebar
	int cnt;//tedad reshtehaye entekhabi
	int reshte[4];  //code reshtehaye entekhaabi
	treenode *left,*right;
};
class bst
{
	public:
	       treenode *root;
	       bst() { root=NULL; };
	       void FindFamily(treenode *cur,char []);
	       void regist();
	       void tamdid();
	       void Delete();
	       void edit();
	       treenode* searchid();
	       void searchname();
	       void show2(treenode *ret);
	       void inorderbyex(treenode *cur);
	       void showlistbyex();
	       void inorderbyfield(treenode *cur,int cod);
	       void showlistbyfield(int cod);
	       void showlistall(treenode *cur);//id
	       void show(treenode *ret);
	       void Save(treenode*);
	       void Load();
}ob;
void bst::Save(treenode *cur)
{
	if (cur)
	{
		Save(cur->left);
		save.write((char*)&cur->id,sizeof (struct treenode));
		Save(cur->right);
	}
}
///////////////////////////////////////////////////////////////////////
void bst::Load()
{
	load.open("c:\\Members",ios::binary);
	treenode *p,*q,*d=new treenode();
	if (!load)
	{
		gotoxy(30,20);
		cout<<"Can not open file";
		getch();
	}
	else {
	while(!load.eof())
	{
	load.read((char*)&d->id,sizeof(struct treenode));
	p=root;
	q=NULL;
	while (p)
	{
		q=p;
		if (p->id==d->id)
			return ;
		if (p->id<d->id)
			p=p->right;
		else
			p=p->left;
	}
	p=new treenode;
	p=d;
	p->id=d->id;
	p->left=p->right=NULL;
	if (!root)
		root=p;
	if (q->id<p->id)
		q->right=p;
	else
		q->left=p;
	}
	}
	load.close();
}
void bst::regist()
{
	while (1)
	{
		treenode *newnode;
		newnode=new treenode;
		clrscr();
		int i,j;
		long money;
		gotoxy(1,1);  cout<<"Name";
		gotoxy(10,1); cout<<"Family";
		gotoxy(20,1); cout<<"Father name";
		gotoxy(35,1); cout<<"sh shenasname";
		gotoxy(50,1); cout<<"Code  melli";
		gotoxy(65,1); cout<<"Saale  tavallod";
		gotoxy(1,5);  cout<<"Tarikhe  ozviat";
		gotoxy(20,5); cout<<"Vaj'h pardakhti";
		gotoxy(40,5); cout<<"Moddate  etebar";

		gotoxy(1,3);gets(newnode->name1);
		if (!(newnode->name1[0]))
			break;
		gotoxy(10,3); gets(newnode->name2);
		gotoxy(20,3); gets(newnode->fname);
		gotoxy(35,3); cin>>newnode->shsh;
		gotoxy(50,3);cin>>newnode->melli;
		gotoxy(65,3);cin>>newnode->birth;

		struct date d;
		getdate(&d);//peresnt function
		newnode->begdate.date=d.da_day;
		newnode->begdate.month=d.da_mon;
		newnode->begdate.year=d.da_year;

		gotoxy(1,7);cout<<"    /  /  ";
		gotoxy(1,7);cout<<newnode->begdate.year;
		gotoxy(6,7);cout<<newnode->begdate.month;
		gotoxy(9,7);cout<<newnode->begdate.date;
		gotoxy(20,7);cin>>money;
		newnode->sumdate=(int)(money/500);
		gotoxy(40,7);cout<<newnode->sumdate<<" rooz";

		gotoxy(1,10);cout<<"Tedad reshte:(1..4)";
		newnode->cnt=11;
		while (newnode->cnt <0 || newnode->cnt>4)
		{
			gotoxy(1,11);
			cout<<"             ";
			gotoxy(1,11);
			cin>>newnode->cnt;
		}
		gotoxy(1,13);
		cout<<"Code reshteha(11,12,13,14): ";
		i=0;
		while (i<newnode->cnt)
		{
			gotoxy(32+3*i,41);
			cout<<"      ";
			gotoxy(32+3*i,41);
			cin>>newnode->reshte[i];
			if(newnode->reshte[i]>10 && newnode->reshte[i]<15)
				i++;
		}
		int nid=100;
		treenode *s;
		s=ob.root;
		int sw=1;
		while (sw==1)
		{
			randomize();
			nid=random(1500)+1;
			s=ob.root;
			sw=0;
			while (s)
			{
				if (s->id==nid)
				{
					sw=1;
					break;
				}
				if (s->id < nid)
					s=s->right;
				else
					s=s->left;
			 }
		}
		newnode->id=nid;

		treenode *p,*q;
		p=ob.root;
		q=NULL;
		int x=newnode->id;
		while (p)
		{
			q=p;
			if (p->id<x)
				p=p->right;
			else
				p=p->left;
		}
		p=new treenode;
		p=newnode;
		p->left=p->right=NULL;
		if (!ob.root)
			ob.root=p;
		if (q->id <x)
			q->right=p;
		else
			q->left=p;

		clrscr();
		gotoxy(1,6);cout<<"               ";
		gotoxy(9,6);
		cout<<"saving...";
		clrscr();
		gotoxy(7,2);
		cout<<" Your ID:";
		cout<<nid;
		gotoxy(7,5);
		cout<<" Any one else?";
		gotoxy(9,7);
		cout<<"  (y/n):";
		if(getche()!='y')
		{
			break;
		}
	}
}

void bst::Delete()
{
	int id,found=0;
	clrscr();
	treenode *p,*q;
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
		if(p->id==id)
		{
			found = 1;
			break;
		}
		else
		{
			q=p;
			if (p->id<id)
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
		treenode *pR;
		pR=p->right;
		if((pR->left==NULL) && (pR->right == NULL))
		{
			p->id=pR->id;
			delete pR;
			p->right=NULL;
		}
		else
		{
		if((p->right)->left != NULL)
		{
			treenode *hlp1;
			treenode *hlp2;
			hlp2=p->right;
			hlp1=(p->right)->left;
			while(hlp1->left!=NULL)
			{
				hlp2=hlp1;
				hlp1=hlp1->left;
			}
			p->id=hlp1->id;
			delete hlp1;
			hlp2->left = NULL;
		}
		else
		{
			treenode *temp;
			temp=p->right;
			p->id=temp->id;
			p->right=temp->right;
			delete temp;
		}
		}
		return;
	}
}
//==============================================================
treenode* bst::searchid()
{
	clrscr();
	int sid;
	cout<<"Enter ID:";
	cin>>sid;
	treenode *p=ob.root;

	while (p)
	{
		if (p->id==sid)
			return p;
		if (p->id < sid)
			p=p->right;
		else
			p=p->left;
	}
	cout<<"not found";
	getch();
	return NULL;
}

void bst::show(treenode *ret)
{
gotoxy(1,3);
cout<<"Code ozviat:";
cout<<ret->id<<"\n";
cout<<"Naam:";
cout<<ret->name1<<"\n";
cout<<"Famil:";
cout<<ret->name2<<"\n";
cout<<"Tarikhe ozviat:";
cout<<ret->begdate.date<<"/"<<ret->begdate.month<<"/"<<ret->begdate.year<<"\n";
cout<<"Modddate etebar:";
cout<<ret->sumdate<<"\n";
cout<<"Reshtehaye sabte naami:";
for (int i=0;i<ret->cnt;i++)
	cout<<reshteha[ret->reshte[i]-11]<<" - ";

}
//================================================================
void bst::showlistall(treenode *cur)
{
	if (cur)
	{
		ob.showlistall(cur->left);

		if (i>42)
		{
		getch();
		window(1,3,80,25);
		clrscr();
		window(1,1,80,25);
		i=3;
		}
		gotoxy(1,i++);
		cout<<"Code ozviat:";
		cout<<cur->id;
		gotoxy(1,i++);
		cout<<"Naam:";
		cout<<cur->name1;
		gotoxy(1,i++);
		cout<<"Famil:";
		cout<<cur->name2;
		gotoxy(1,i++);
		cout<<"Tarikhe ozviat";
		cout<<cur->begdate.date<<"/"<<cur->begdate.month<<"/"<<cur->begdate.year<<"\n";
		gotoxy(1,i++);
		cout<<"Modddate etebar:";
		cout<<cur->sumdate<<"\n";
		gotoxy(1,i++);
		cout<<"Reshtehaye sabte naami:";
		for (int j=0;j<cur->cnt;j++)
			cout<<reshteha[cur->reshte[j]-11]<<" ";
		gotoxy(1,i++);
		cout<<"อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ";

		ob.showlistall(cur->right);
	}
}
//==========================================================================
void bst::show2(treenode *ret)
{
if (i>42)
{
	getch();
	window(1,3,80,50);
	clrscr();
	window(1,1,80,50);
	i=3;
}
gotoxy(1,i);
cout<<"Code ozviat:";
cout<<ret->id<<"\n";
cout<<"Naam:";
cout<<ret->name1<<"\n";
cout<<"Famil:";
cout<<ret->name2<<"\n";
cout<<"Tarikhe ozviat";
cout<<ret->begdate.date<<"/"<<ret->begdate.month<<"/"<<ret->begdate.year<<"\n";
cout<<"Modddate etebar:";
cout<<ret->sumdate<<"\n";
cout<<"Reshtehaye sabte naami:";
for (int j=0;j<ret->cnt;j++)
	cout<<reshteha[ret->reshte[j]-11]<<" ";
cout<<"\n";
cout<<"อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ";
i+=7;
}
//================================================================
void bst::inorderbyfield(treenode *cur,int cod)
{
	if(cur)
	{
		ob.inorderbyfield(cur->left,cod);
		for (int j=0;j<cur->cnt;j++)
			if (cur->reshte[j]==cod)
				ob.show2(cur);

		ob.inorderbyfield(cur->right,cod);
	}
}
//===================================================================
void bst::inorderbyex(treenode *cur)
{
	if(cur)
	{
		ob.inorderbyex(cur->left);
		if (cur->sumdate==0)
			ob.show2(cur);

		ob.inorderbyex(cur->right);
	}
}
//================================================================
void bst::showlistbyfield(int cod)
{
 treenode *s;
 s=new treenode;
 s=ob.root;
 ob.inorderbyfield(s,cod);
 getch();
 return;
}
//================================================================
void bst::showlistbyex()
{
 treenode *s;
 s=new treenode;
 s=ob.root;
 ob.inorderbyex(s);
 getch();
 return;
}
//================================================================
void searchmenu()
{
	int n;
	clrscr();
	cout<<"\n1.By Name";
	cout<<"\n2.By Id";
	cout<<"\n\nEnter 1 or 2: ";
	do {
		gotoxy(1,6);
		cout<<"       ";
		gotoxy(1,6);
		cin>>n;
	} while (n<1 || n>2);
	treenode *ret;

	if (n==2)
	{
	    ret=ob.searchid();
	    if (ret)
		ob.show(ret);
	    getch();
	}
	else if (n==1)
	{
		clrscr();
		char sname[50];
		cout<<"Enter family:";
		gets(sname);
		ob.FindFamily(ob.root,sname);
		getch();
	}
}
//================================================================
void showmenu()
{
	int n;
	clrscr();
	cout<<"\n1.By Fields";
	cout<<"\n2.Expireds";
	cout<<"\n3.By Id";
	cout<<"\n\nEnter 1..3: ";
	do {
		gotoxy(1,7);
		cout<<"            ";
		gotoxy(1,7);
		cin>>n;
	}while (n<1 || n>3);
	if (n==3)
	{
		clrscr();
		if (ob.root==NULL)
		{
		    cout<<"List Is Empty";
		    getch();
		    return ;
		}
		cout<<"                              List By Id";
		gotoxy(1,2);
		cout<<"อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ";
		i=3;
		ob.showlistall(ob.root);
	}
	else if (n==1)
	{

		clrscr();
		if (ob.root==NULL)
		{
		    cout<<"List Is Empty";
		    getch();
		    return ;
		}
		cout<<"                              List By field";
		gotoxy(1,2);
		cout<<"อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ";
		gotoxy(1,3);
		int cod;
		cout<<"code reshte ra vared konid:";
		cin>>cod;
		while (cod<11 || cod>14)
		{
		gotoxy(28,3);
		cout<<"          ";
		gotoxy(28,3);
		cin>>cod;
		}
		gotoxy(34,2);
		cout<<reshteha[cod-11];
		i=5;
		ob.showlistbyfield(cod);
	}
	else if (n==2)
       {
		clrscr();
		if (ob.root==NULL)
		{

		    cout<<"List Is Empty";
		    getch();
		    return ;
		}
		cout<<"                                   Expireds";
		gotoxy(1,2);
		cout<<"อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ";
		i=3;
		ob.showlistbyex();
	   }

getch();
}
//===============================================================
void bst::tamdid()
{
	long int money;
	treenode *ret;
	ret=new treenode;
	ret=NULL;
	ret=ob.searchid();
	if (ret)
	{
		ob.show(ret);
		cout<<"\n============================================";
		cout<<"\n\n";
		cout<<"vaj'he daryafti jahate tamdide ozviat:";
		cin>>money;
		ret->sumdate+=(int)(money/500);
		cout<<"\n";
		cout<<"Moddate etebar:";
		cout<<ret->sumdate<<" Rooz";
		getch();
		return;
	}
}

void bst::edit()
{
treenode *ret;
ret=new treenode;
ret=NULL;
ret=ob.searchid();
if(!ret)
	return;
gotoxy(10,3);cout<<"Code ozviat: "<<ret->id;
gotoxy(10,4);cout<<"Naam: "<<ret->name1;
gotoxy(10,5);cout<<"Famil: "<<ret->name2;
gotoxy(10,6);cout<<"Tarikhe ozviat: "<<ret->begdate.date<<"/"<<ret->begdate.month<<"/"<<ret->begdate.year;
gotoxy(10,7);cout<<"Modddate etebar: "<<ret->sumdate;
gotoxy(10,8);cout<<"Reshtehaye sabte naami: ";
for (int i=0;i<ret->cnt;i++)
	cout<<reshteha[ret->reshte[i]-11]<<"  ";
gotoxy(16,10);cout<<"Press Esc to exit";
i=3;
char ch=10;
gotoxy(8,i);
cout<<"ฏ";//175
while(ch!=27)
{
	if (!(ch=getch()))
		ch=getch();
	gotoxy(8,i);
	cout<<" ";
	if (ch==80)
		i++;
	else if (ch==72)
		i--;
	if (i>8)
		i=3;
	if (i<3)
		i=8;
	gotoxy(8,i);
	cout<<"ฏ";
	if (ch==13){
	switch(i){
		case 3:gotoxy(22,i);
		       cout<<"                              ";
		       gotoxy(22,i);
		       cin>>ret->id;
		       break;
		case 4:gotoxy(15,i);
		       cout<<"                      ";
		       gotoxy(15,i);
		       gets(ret->name1);
		       break;
		case 5:gotoxy(16,i);
		       cout<<"                       ";
		       gotoxy(16,i);
		       gets(ret->name2);
		       break;
		case 6:gotoxy(25,i);
		       cout<<"                     ";
		       gotoxy(25,i);
		       cout<<"day:";
		       cin>>ret->begdate.date;
		       while (ret->begdate.date<1 || ret->begdate.date>31)
		       {
			  gotoxy(29,i);
			  cout<<"       ";
			  gotoxy(29,i);
			  cin>>ret->begdate.date;
		       }
		       gotoxy(32,i);
		       cout<<"month:";
		       cin>>ret->begdate.month;
		       while (ret->begdate.month<1 || ret->begdate.month>12)
		       {
			  gotoxy(38,i);
			  cout<<"       ";
			  gotoxy(38,i);
			  cin>>ret->begdate.month;
		       }
		       gotoxy(41,i);
		       cout<<"year:";
		       cin>>ret->begdate.year;
		       while (ret->begdate.year<1980 || ret->begdate.year>2008)
		       {
			  gotoxy(46,i);
			  cout<<"       ";
			  gotoxy(46,i);
			  cin>>ret->begdate.year;
		       }
		       break;
		case 7:gotoxy(26,i);
		       cout<<"            ";
		       gotoxy(26,i);
		       cin>>ret->sumdate;
		       break;
		case 8:gotoxy(33,i);
		       cout<<"                                            ";
		       gotoxy(34,i);
		       cout<<"Tedad reshte:";
		       cin>>ret->cnt;
		       while (ret->cnt>4 || ret->cnt<0)
		       {
			  gotoxy(47,i);
			  cout<<"        ";
			  gotoxy(47,i);
			  cin>>ret->cnt;
		       }
			gotoxy(49,i);
			cout<<"Code reshteha:";
			int j=0;
			while (j<ret->cnt)
			{
			gotoxy(63+3*j,i);
			cout<<"      ";
			gotoxy(63+3*j,i);
			cin>>ret->reshte[j];
			if(ret->reshte[j]>10 && ret->reshte[j]<15)
				j++;
			}
			break;
		       }
		       gotoxy(9,i);
		}
	}
return;
}
//==================================================================
void bst::FindFamily(treenode *cur,char s[])
{
      if (cur)
      {
		ob.FindFamily(cur->left,s);
		if (strcmp(cur->name2,s)==0)
			show(cur);
		ob.FindFamily(cur->right,s);
      }
}

void menu()
{
	int n;
	clrscr();
	cout<<"\n1.Registration";
	cout<<"\n2.Extension Of Membership";
	cout<<"\n3.Delete A Member";
	cout<<"\n4.Edit A Member Info";
	cout<<"\n5.Search A Member";
	cout<<"\n6.List of Members";
	cout<<"\n7.Save Members Info";
	cout<<"\n8.Exit";
	cout<<"\n\nEnter 1..8: ";

	do {
		gotoxy(1,13);
		cout<<"          ";
		gotoxy(1,13);
		cin>>n;
	} while (n<1 || n>8);

	if (n==1)
	{
		ob.regist();
		menu();
	}
	else if (n==2)
	{
		ob.tamdid();
		menu();
	}
	else if (n==3)
	{
		ob.Delete();
		menu();
	}
	else if (n==4)
	{
		ob.edit();
		menu();
	}
	else if (n==5)
	{
		searchmenu();
		menu();
	}
	else if (n==6)
	{
		showmenu();
		menu();
	}
	else if (n==7)
	{
		clrscr();
		save.open("c:\\Members",ios::binary);
		if (save)
		{
			ob.Save(ob.root);
			cout<<"saved";
			getch();
		}
		menu();
	}
	else if (n==8)
		exit(0);
}


void main()
{
textcolor(15);
ob.Load();
menu();
}