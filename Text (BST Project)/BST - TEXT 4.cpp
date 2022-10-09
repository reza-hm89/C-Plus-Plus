#include<conio.h>
#include<iostream.h>
#include<fstream.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int i;
struct treenode
{
	char str[100];
	int cnt;
	treenode *left,*right;
};
class bst{

	public:
	   treenode *root;
	   ifstream load;

	       bst();
	       void loadtree();
	       treenode * search(char s[]);
	       void add(char s[]);
	       void del();
	       void show(treenode *cur);
	       void add2(char str[],int cnt);
	       void inorder(treenode *cur);

}tree,tree2;
bst::bst()
{
	root=NULL;
}
////////////////////////////////////////////
void bst::loadtree()
{
	char s[100],ch;
	int i=0;
	load.open("text.txt",ios::beg);
	while(!load.eof())
	{
		s[0]='\0';
		i=0;
		while(1)
		{
			load.read((char *)&ch,sizeof(char));
			if ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
				s[i++]=ch;
			else
			{
			s[i]='\0';
			break;
			}
		}
		if (s[0]!='\0')
		{
			int sw=0;
			treenode *h=tree.root;
			while (h!=NULL)
			{
				if (strcmp(h->str,s)>0)
					h=h->left;
				else if (strcmp(h->str,s)<0)
					h=h->right;
				else
				{
					(h->cnt)++;
					sw=1;
					break;
				}
			}
			if (sw==1)
				continue;
			treenode *cur;
			cur=new treenode;
			strcpy(cur->str,s);
			cur->left=NULL;
			cur->right=NULL;
			cur->cnt=0;
			treenode *p,*q;
			p=tree.root;
			q=NULL;
			while (p)
			{
				q=p;
				if (strcmp(p->str,cur->str)<0)
					p=p->right;
				else
					p=p->left;
			}
			 p=new treenode;
			 p=cur;
			 p->left=p->right=NULL;
			 if (!tree.root)
				tree.root=p;
			 if (strcmp(q->str,cur->str)<0)
				q->right=p;
			 else
				q->left=p;
		 }
	 }
}
////////////////////////////////////////////////////
treenode* bst::search(char s[])
{
treenode *h=root;
while (h!=NULL)
{
	if (strcmp(h->str,s)>0)
		h=h->left;
	else if (strcmp(h->str,s)<0)
		h=h->right;
	else
	{
		return h;
	}
}
return NULL;
}
/////////////////////////////////////////////////////////////////
void bst::add(char s[])
{
treenode *h=root;
while (h!=NULL)
{
	if (strcmp(h->str,s)>0)
		h=h->left;
	else if (strcmp(h->str,s)<0)
		h=h->right;
	else
	{
		(h->cnt)++;
		return;
	}
}
treenode *cur;
cur=new treenode;
strcpy(cur->str,s);
cur->left=NULL;
cur->right=NULL;
cur->cnt=0;
treenode *p,*q;
p=tree.root;
q=NULL;
while (p)
{
	q=p;
	if (strcmp(p->str,cur->str)<0)
		p=p->right;
	else
		p=p->left;
}
p=new treenode;
p=cur;
p->left=p->right=NULL;
if (!tree.root)
	tree.root=p;
if (strcmp(q->str,cur->str)<0)
	q->right=p;
else
	q->left=p;
}
//////////////////////////////////////////////////////////////////
void bst::del()
{
char s[100];
int found=0;
clrscr();
treenode *cur,*q;
cout<<"kalame ra vared konid: ";
gets(s);
cur=root;
if(!cur)
{
	cprintf("List Khali ast");
	getch();
	return;
}
while(cur)
{
	if(strcmp(cur->str,s)==0)
	{
		found = 1;
		break;
	}
	else
	{
		q=cur;
		if(strcmp(cur->str,s)<0)
			cur=cur->right;
		else
			cur=cur->left;
	}
}
if(!found)
{
	gotoxy(1,3);
	cout<<"peida nashod!";
	getch();
	return;
}
gotoxy(1,3);
cprintf("Hazf shod");
getch();
//agar cur barg bashad
if( cur->left == NULL && cur->right == NULL)
{
	if(q->left == cur)
		q->left = NULL;
	else
		q->right = NULL;
	delete cur;
	return;
}
//////////
if((cur->left == NULL && cur->right != NULL)|| (cur->left != NULL && cur->right == NULL))
{
	//1 farzande rast dashte bashad
	if(cur->left == NULL && cur->right != NULL)
	{
		if(q->left == cur)
		{
			q->left = cur->right;
			delete cur;
		}
		else
		{
			q->right = cur->right;
			delete cur;
		}
	}
	else // 1 farzande chap dashte bashad
	{
		if(q->left == cur)
		{
			q->left = cur->left;
			delete cur;
		}
		else
		{
			q->right = cur->left;
			delete cur;
		}
	}
	return;
}
////////////////
//2 farzand dashte bashad (ba koochektarine samte rast avaz mishavad
if (cur->left != NULL && cur->right != NULL)
{
	treenode *CurR;
	CurR=cur->right;
	if((CurR->left==NULL) && (CurR->right == NULL))
	{
		cur=CurR;
		delete CurR;
		cur->right=NULL;
	}
	else // agar samte rasti farzand dashte bashad
	{
	//agar in samte rasti farzande chap dashte bashad
	// peida kardane koochektarine samte chap
	if((cur->right)->left != NULL)
	{
		treenode *hlp1;       //lcurr=hlp1
		treenode *hlp2;     //lcurrp=hlp2
		hlp2=cur->right;
		hlp1=(cur->right)->left;
		while(hlp1->left!=NULL)
		{
			hlp2=hlp1;
			hlp1=hlp1->left;
		}
		strcpy(cur->str,hlp1->str);
		cur->cnt=hlp1->cnt;
		delete hlp1;
		hlp2->left = NULL;
	}
	else
	{
		treenode *temp;
		temp=cur->right;
		strcpy(cur->str,temp->str);
		cur->cnt=temp->cnt;
		cur->right=temp->right;
		delete temp;
	}
	}//else
	return;
}
}
/////////////////////////////////////////////////
void bst::show(treenode *cur)
{
	if (cur)
	{
		show(cur->right);

		if (i>47)
		{
		gotoxy(30,49);
		cout<<"Press Enter For Next Page";
		char ch;
		ch=getch();
		while (ch!=13)
			ch=getch();
		clrscr();
		i=2;
		}
		gotoxy(10,i);
		puts(cur->str);
		gotoxy(30,i++);
		cout<<cur->cnt;
		gotoxy(1,i++);

		show(cur->left);
	}
}
/////////////////////////////////////////
void bst::add2(char str[],int cnt)
{
treenode *p,*q,*cur;
p=tree2.root;
q=NULL;
cur=new treenode;
cur->left=cur->right=NULL;
strcpy(cur->str,str);
cur->cnt=cnt;
while (p)
{
	q=p;
	if (p->cnt < cur->cnt)
		p=p->right;
	else
		p=p->left;
}
p=new treenode;
p=cur;
p->left=p->right=NULL;
if (!tree2.root)
	tree2.root=p;
if (q->cnt < cur->cnt)
	q->right=p;
else
	q->left=p;
}
///////////////////////////////////////////
void bst::inorder(treenode *cur)
{
       if (cur)
       {
       inorder(cur->left);
       tree2.add2(cur->str,cur->cnt);
       inorder(cur->right);
       }
}
/////////////////////////////////////////////////////////////////
void menu()
{
clrscr();
gotoxy(20,5);
cout<<"jootojooye yek kalame va chape tedad tekrare aan";
gotoxy(20,7);
cout<<"darj yek kalame jadid";
gotoxy(20,9);
cout<<"hazf yek kalame be tore kolli";
gotoxy(20,11);
cout<<"chape tamame kalamat be tartibe horoof";
gotoxy(20,13);
cout<<"chape tamame kalamat be tartibe tedad tekrar";
gotoxy(20,15);
cout<<"Exit";
int y=5;
gotoxy(18,y);
cout<<"*";
char ch;
char str[100];
while (1)
{
	ch=getch();
	if (!ch)
		ch=getch();
	if (ch==72 || ch==80)
	{
		gotoxy(18,y);
		cout<<" ";
	}
	if (ch==80)
		y+=2;
	else if (ch==72)
		y-=2;
	if (y>15)
		y=5;
	if (y<5)
		y=15;
	if (ch==72 || ch==80)
	{
		gotoxy(18,y);
		cout<<"*";
	}

	if (ch==13 && y==15)
		exit(0);
	if(ch==13 && y==5)
	{

		clrscr();
		cout<<"kalame morede nazar ra vared konid:";
		gets(str);
		treenode *ret=tree.search(str);
		if (ret==NULL)
		{
			cout<<"ERROR!!peida nashod";
			getch();
			menu();
		}
		else
		{
			cout<<"peida shod";
			cout<<"\n=====================================================================";
			cout<<"\n\nkalame:";
			puts(ret->str);
			cout<<"\ntedad tekrar:";
			cout<<ret->cnt;
			getch();
			menu();
		}
	}
	else if (ch==13 && y==7)
	{
		clrscr();
		cout<<"kalame morede nazar ra vared konid:";
		gets(str);
		tree.add(str);
		cout<<"\nsabt shod";
		getch();
		menu();
	}
	else if (ch==13 && y==9)
	{
		clrscr();
		tree.del();
		menu();

	}
	else if (ch==13 && y==11)
	{
		clrscr();
		cout<<"อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ";
		i=2;
		tree.show(tree.root);
		getch();
		menu();
	}
	else if (ch==13 && y==13)
	{
		clrscr();
		tree2.root=NULL;
		tree.inorder(tree.root);
		cout<<"อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ";
		i=2;
		tree2.show(tree2.root);
		getch();
		menu();
	}

}
}
void main()
{

tree.loadtree();
menu();
}