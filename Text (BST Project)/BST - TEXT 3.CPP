#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
struct treenode
{
	char s[30];
	int c;
	treenode *right,*left;
};
int x1,y1;
///////////////////////////////////////////////////////
class BST
{
	treenode *root;
	public:
		BST() { root=NULL; };
		treenode* GetRoot() {return root;}
		void Add(treenode *cur);
		void Delete(treenode*);
		void InOrder(treenode *cur);
		int Search1(treenode*);
		int Search2(treenode*);
		void Insert(treenode*);
		treenode* InputData();
		void Sort(treenode*);
}bst;
void BST::Add(treenode *cur)
{
	treenode *p,*q;
	p=root;
	q=NULL;
	while (p)
	{
		q=p;
		if (strcmp(p->s,cur->s)<0)
			p=p->right;
		else
			p=p->left;
	}
	p=new treenode;
	p=cur;
	p->left=p->right=NULL;
	if (!root)
		root=p;
	if (strcmp(q->s,cur->s)<0)
		q->right=p;
	else
		q->left=p;
}
int BST::Search1(treenode *cur)
{
	treenode *p=root;
	while (p)
	{
		if (strcmp(p->s,cur->s)==0)
		{
			gotoxy(10,37);
			cprintf("%s",p->s);
			gotoxy(10,39);
			cprintf("%d",p->c);
			return 1;
		}
		else if (strcmp(p->s,cur->s)<0)
			p=p->right;
		else
			p=p->left;
	}
	return 0;
}
int BST::Search2(treenode *cur)
{
	treenode *p=root;
	while (p)
	{
		if (strcmp(p->s,cur->s)==0)
		{
			p->c++;
			return 1;
		}
		else if (strcmp(p->s,cur->s)<0)
			p=p->right;
		else
			p=p->left;
	}
	return 0;
}

void BST::Insert(treenode *cur)
{
	textcolor(RED);
	if (Search2(cur))
	{
		gotoxy(8,42);
		cprintf("this Word exist");
		textcolor(BLACK);
		gotoxy(10,37);
		cprintf("%s",cur->s);
		gotoxy(10,39);
		cprintf("%d",cur->c);
	}
	else
	{
		textcolor(RED);
		gotoxy(5,42);
		cprintf("not found..Add to Tree");
		Add(cur);
	}
}
void BST::Delete(treenode *cur)
{
	int found=0;
	char s[30];
	strcpy(s,cur->s);
	treenode *p,*q;
	p=root;
	while(p)
	{
		if(strcmp(p->s,s)==0)
		{
			found = 1;
			break;
		}
		else
		{
			q=p;
			if (strcmp(p->s,s)<0)
				p=p->right;
			else
			p=p->left;
		}
	}
	textcolor(RED);
	if(!found)
	{
		gotoxy(11,42);
		cprintf("not found");
		getch();
		return;
	}
	gotoxy(11,42);
	cprintf("Delete");
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
		treenode *r;
		r=p->right;
		if((r->left==NULL) && (r->right == NULL))
		{
			p=r;
			delete r;
			p->right=NULL;
		}
		else
		{
		if(r->left != NULL)
		{
			treenode *tmp1;
			treenode *tmp2;
			tmp2=p->right;
			tmp1=tmp2->left;
			while(tmp1->left!=NULL)
			{
				tmp2=tmp1;
				tmp1=tmp1->left;
			}
			strcpy(p->s,tmp1->s);
			p->c=tmp1->c;
			delete tmp1;
			tmp2->left = NULL;
		}
		else
		{
			treenode *temp;
			temp=p->right;
			strcpy(p->s,temp->s);
			p->c=temp->c;
			p->right=temp->right;
			delete temp;
		}
		}
		return;
	}
}
void BST::InOrder(treenode *cur)
{
	treenode *p=cur;
	if (p)
	{
		InOrder(p->left);
		gotoxy(x1,y1);
		cprintf("%s",p->s);
		gotoxy(x1+20,y1++);
		cprintf("%d",p->c);
		InOrder(p->right);
	}
}
treenode t[50];
int z;
void BST::Sort(treenode *cur)
{
	if (cur)
	{
		Sort(cur->left);
		strcpy(t[z].s,cur->s);
		t[z++].c=cur->c;
		Sort(cur->right);
	}
}
treenode* BST::InputData()
{
	treenode* p=new treenode();
	gotoxy(10,37);
	gets(p->s);
	p->c=1;
	return p;
}
///////////////////////////////////////////////////////
char str[100][50];
int cnt;
///////////////////////////////////////////////////////
void GetFile()
{
	 ifstream f;
	 char *s;
	 int i=0,j,k;
	 f.open("text.txt");
	 if (!f)
	 {
		textcolor(RED);
		gotoxy(48,10);
		cprintf("Can not open file");
		getch();
		exit(0);
	 }
	 while (!f.eof())
	 {
		f>>s;
		strcpy(str[i++],s);
		s=NULL;
	 }
	 f.close();
	 str[i][0]=0;
	 cnt=i;
	 for (i=0;i<cnt;i++)
	 {
		k=0;
		for (j=0;str[i][j];j++)
		if ((str[i][j]>='a' && str[i][j]<='z') || (str[i][j]>='A' && str[i][j]<='Z'))
		{
			str[i][k++]=str[i][j];
		}
		str[i][k]=0;
	 }
	 for (i=0;i<cnt;i++)
		for (j=0;str[i][j];j++)
		{
			if (str[i][j]>='A' && str[i][j]<='Z')
				str[i][j]+=32;
		}
}
void SetToTree()
{
	treenode *p;
	char *t;
	int i;
	for (i=0;i<cnt;i++)
	{
		strcpy(t,str[i]);
		if (t[0])
		{
			p=new treenode();
			strcpy(p->s,t);
			p->c=1;
			if (!bst.Search2(p))
				bst.Add(p);
		}
	}
}
void Menu()
{
	textbackground(WHITE);
	textcolor(BLACK);
	clrscr();
	int i,j,y=3;
	char ch;
	for (i=1;i<=30;i++)
	{
		gotoxy(i,1);
		cprintf("อ");
		gotoxy(i,30);
		cprintf("อ");
	}
	for (i=1;i<=30;i++)
	{
		gotoxy(1,i);
		cprintf("บ");
		gotoxy(30,i);
		cprintf("บ");
	}
	gotoxy(1,1);  cprintf("ษ");
	gotoxy(30,1);  cprintf("ป");
	gotoxy(1,30); cprintf("ศ");
	gotoxy(30,30); cprintf("ผ");

	//--------------option
	gotoxy(7,6);
	cprintf("2.Insert");
	gotoxy(7,9);
	cprintf("3.Delete");
	gotoxy(7,12);
	cprintf("4.Print");
	gotoxy(7,15);
	cprintf("5.Sorting");
	gotoxy(7,18);
	cprintf("6.Exit");

	textcolor(RED);
	gotoxy(7,3);
	cprintf("1.Search");

	textcolor(BLACK);
	for (i=1;i<=30;i++)
	{
		gotoxy(i,35);
		cprintf("อ");
		gotoxy(i,45);
		cprintf("อ");
	}
	for (i=35;i<=45;i++)
	{
		gotoxy(1,i);
		cprintf("บ");
		gotoxy(30,i);
		cprintf("บ");
	}
	gotoxy(1,35);  cprintf("ษ");
	gotoxy(30,35);  cprintf("ป");
	gotoxy(1,45); cprintf("ศ");
	gotoxy(30,45); cprintf("ผ");
	gotoxy(11,33);
	cprintf("TEXTBOX");
	gotoxy(3,37);
	cprintf("String: ");
	gotoxy(3,39);
	cprintf("Repeat: ");
	gotoxy(52,2);
	cprintf("Tree Nodes");
	gotoxy(35,3);
	cprintf("ออออออออออออออออออออออออออออออออออออออออออ");
	SetToTree();
	while (ch!=27)
	{
		gotoxy(80,50);
		ch=getch();
		textcolor(BLACK);
		gotoxy(7,3);
		cprintf("1.Search");
		gotoxy(7,6);
		cprintf("2.Insert");
		gotoxy(7,9);
		cprintf("3.Delete");
		gotoxy(7,12);
		cprintf("4.Print");
		gotoxy(7,15);
		cprintf("5.Sorting");
		gotoxy(7,18);
		cprintf("6.Exit");

		if (ch==72)
		{
			y-=3;
			if (y<3)
				y=18;
		}
		else if (ch==80)
		{
			y+=3;
			if (y>18)
				y=3;
		}
		else if (ch==13)
		{
			for (i=10;i<30;i++)
				for (j=37;j<45;j++)
				{
					gotoxy(i,j);
					cprintf(" ");
				}
				gotoxy(5,42);
				cprintf("                         ");
			switch(y)
			{
				case 3:
					if(bst.Search1(bst.InputData()))
					{
						textcolor(RED);
						gotoxy(11,42);
						cprintf("Found");
					}
					else
					{
						textcolor(RED);
						gotoxy(11,42);
						cprintf("not found");
					}
					break;
				case 6:
					bst.Insert(bst.InputData());
					break;
				case 9:
					bst.Delete(bst.InputData());
					break;
				case 12:
					x1=45; y1=5;
					for (i=40;i<80;i++)
						for (j=5;j<50;j++)
						{
							gotoxy(i,j);
							cprintf(" ");
						}
					bst.InOrder(bst.GetRoot());
					break;
				case 15:
					z=0;
					bst.Sort(bst.GetRoot());
					treenode temp;
					for (i=0;i<z;i++)
						for (j=i+1;j<z;j++)
							if (t[i].c<t[j].c)
							{
								temp=t[i];
								t[i]=t[j];
								t[j]=temp;
							}
						x1=45; y1=5;
						for (i=40;i<80;i++)
						for (j=5;j<50;j++)
						{
							gotoxy(i,j);
							cprintf(" ");
						}
						for (i=0;i<z;i++)
						{
							gotoxy(x1,y1);
							cprintf("%s",t[i].s);
							gotoxy(x1+20,y1++);
							cprintf("%d",t[i].c);
						}
					break;
				case 18:
					exit(0);
			}
		}
		textcolor(RED);
		switch (y)
		{
			case 3:
				gotoxy(7,3);
				cprintf("1.Search");
			break;
			case 6:
				gotoxy(7,6);
				cprintf("2.Insert");
			break;
			case 9:
				gotoxy(7,9);
				cprintf("3.Delete");
			break;
			case 12:
				gotoxy(7,12);
				cprintf("4.Print");
			break;
			case 15:
				gotoxy(7,15);
				cprintf("5.Sorting");
			break;
			case 18:
				gotoxy(7,18);
				cprintf("6.Exit");
			break;
		}
	}

}
void main()
{
	GetFile();
	Menu();
}