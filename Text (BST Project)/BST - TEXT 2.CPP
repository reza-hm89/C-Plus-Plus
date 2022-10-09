#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<fstream.h>
#include<stdlib.h>

int x,y;
//------------------------------------------------
struct treenode
{
	char word[50];
	int cnt;
	treenode *right,*left;
};
//------------------------------------------------
class BinerySearchTree
{
	treenode *Root;
	public:
		BinerySearchTree() { Root=NULL; };
		treenode* GetRoot() { return Root; };
		void SetRoot() { Root=NULL; };
		treenode* Search(treenode*);
		int SearchNewWord(treenode*);
		void InOrder(treenode*);
		void InOrder2(treenode*);
		void ReadFromFile();
		void Add(treenode*);
		void Add2(int,char[]);
		void PrintWord();
		void SortingCount();
		char* GetWord();
		void Delete();
		void Insert();
		void Border();
		void Menu();
};
BinerySearchTree b;
//------------------------------------------------
void BinerySearchTree::ReadFromFile()
{
	clrscr();
	char str[1000],temp[20];
	int i=0,j;
	ifstream f;
	treenode *newnode;
	f.open("text.txt");
	if (!f)
	{
		gotoxy(32,12);
		textcolor(RED+128);
		cprintf("Can not open file");
		getch();
		return;
	}
	while(!f.eof())
		f.get(str[i++]);
	str[i]=0;
	for (i=0;str[i];i++)
		if (str[i]>='A' && str[i]<='Z')
			str[i]+=32;
	for (i=0,j=0;str[i];i++)
	{
		if (str[i]>='a' && str[i]<='z')
			temp[j++]=str[i];
		else
		{
			temp[j]='\0';
			if (j)
			{
				newnode=new treenode();
				strcpy(newnode->word,temp);
				newnode->cnt=1;
				newnode->right=newnode->left=NULL;
				if (!SearchNewWord(newnode))
					Add(newnode);
			}
			j=0;
		}
	}
	textcolor(RED);
	cprintf("Tree has been created");
	getch();
}
//------------------------------------------------
void BinerySearchTree::Add(treenode * currentnode)
{
	treenode *p,*q;
	p=Root;
	q=NULL;
	while (p)
	{
		q=p;
		if (strcmp(p->word,currentnode->word)<0)
			p=p->right;
		else
			p=p->left;
	}
	p=new treenode();
	p=currentnode;
	p->left=p->right=NULL;
	if (!Root)
		Root=p;
	if (strcmp(q->word,currentnode->word)<0)
		q->right=p;
	else
		q->left=p;
}
//------------------------------------------------
void BinerySearchTree::Add2(int cnt,char s[])
{
	treenode *p,*q;
	p=Root;
	q=NULL;
	while (p)
	{
		q=p;
		if (p->cnt>cnt)
			p=p->right;
		else
			p=p->left;
	}
	p=new treenode();
	p->cnt=cnt;
	strcpy(p->word,s);
	p->left=p->right=NULL;
	if (!Root)
		Root=p;
	if (q->cnt>cnt)
		q->right=p;
	else
		q->left=p;
}
//------------------------------------------------
void BinerySearchTree::Delete()
{
	clrscr();
	int sw=0;
	char CurWord[50];
	treenode *p,*q;
	p=Root;
	strcpy(CurWord,GetWord());
	while(p)
	{
		if(strcmp(p->word,CurWord)==0)
		{
			sw=1;
			break;
		}
		else
		{
			q=p;
			if (strcmp(p->word,CurWord)<0)
				p=p->right;
			else
			p=p->left;
		}
	}
	if(!sw)
	{
		textcolor(LIGHTRED);
		cprintf("This word not found");
		getch();
		return;
	}
	textcolor(WHITE);
	cprintf("Deleted from Tree...");
	getch();
	if( !p->left && !p->right)
	{
		if(q->left==p)
			q->left=NULL;
		else
			q->right=NULL;
		delete p;
		return;
	}

	if((!p->left && p->right!=NULL)|| (p->left!=NULL && !p->right))
	{
		if(!p->left && p->right!=NULL)
		{
			if(q->left==p)
			{
				q->left=p->right;
				delete p;
			}
			else
			{
				q->right=p->right;
				delete p;
			}
		}
		else
		{
			if(q->left==p)
			{
				q->left=p->left;
				delete p;
			}
			else
			{
				q->right=p->left;
				delete p;
			}
		}
		return;
	}
	if (p->left != NULL && p->right != NULL)
	{
		treenode *tempR;
		tempR=p->right;
		if((!tempR->left) && (!tempR->right))
		{
			p=tempR;
			delete tempR;
			p->right=NULL;
		}
		else
		{
			// peida kardane koochektarine samte chap
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
				strcpy(p->word,hlp1->word);
				p->cnt=hlp1->cnt;
				delete hlp1;
				hlp2->left = NULL;
			}
			else
			{
				treenode *temp;
				temp=p->right;
				strcpy(p->word,temp->word);
				p->cnt=temp->cnt;
				p->right=temp->right;
				delete temp;
			}
		}
		return;
	}
}
//------------------------------------------------
treenode* BinerySearchTree::Search(treenode * currentnode)
{
	treenode *p=Root;
	while (p)
	{
		if (strcmp(p->word,currentnode->word)==0)
			return p;
		else if (strcmp(p->word,currentnode->word)<0)
			p=p->right;
		else
			p=p->left;
	}
	return NULL;
}
//------------------------------------------------
int BinerySearchTree::SearchNewWord(treenode * currentnode)
{
	treenode *p=Root;
	while (p)
	{
		if (strcmp(p->word,currentnode->word)==0)
		{
			p->cnt++;
			return 1;
		}
		else if (strcmp(p->word,currentnode->word)<0)
			p=p->right;
		else
			p=p->left;
	}
	return 0;
}
//------------------------------------------------
void BinerySearchTree::InOrder(treenode * currentnode)
{
	if (currentnode)
	{
		textcolor(15);
		InOrder(currentnode->left);
		if (y>24)
		{
			y=2;
			x=41;
		}
		{
			gotoxy(::x,++::y);
			cprintf("%s",currentnode->word);
			gotoxy(::x+25,::y);
			cprintf("%d",currentnode->cnt);
		}
		InOrder(currentnode->right);
	}
}
//------------------------------------------------
void BinerySearchTree::InOrder2(treenode * current)
{
	if (current)
	{
		InOrder2(current->left);
		b.Add2(current->cnt,current->word);
		InOrder2(current->right);
	}
}
//------------------------------------------------
void BinerySearchTree::SortingCount()
{
	b.SetRoot();
	Border();
	InOrder2(GetRoot());
	b.InOrder(b.GetRoot());
}
//------------------------------------------------
char* BinerySearchTree::GetWord()
{
	char s[50];
	textcolor(WHITE);
	cprintf("Enter your Word: ");
	gets(s);
	return s;
}
//------------------------------------------------
void BinerySearchTree::PrintWord()
{
	clrscr();
	treenode *p;
	p=new treenode();
	strcpy(p->word,GetWord());
	textcolor(WHITE);
	if (Search(p))
	{
		p=Search(p);
		cout<<endl;
		cprintf("Wrod= %s",p->word);
		cout<<endl;
		cprintf("Count= %d",p->cnt);
	}
	getch();
}
//------------------------------------------------
void BinerySearchTree::Insert()
{
	clrscr();
	treenode *p;
	p=new treenode();
	strcpy(p->word,GetWord());
	p->cnt=1;
	textcolor(WHITE);
	if (SearchNewWord(p))
	{
		p=Search(p);
		cout<<endl;
		cprintf("Word is exist");
		cout<<endl;
		cprintf("Word= %s",p->word);
		cout<<endl;
		cprintf("Count= %d",p->cnt);
	}
	else
	{
		cprintf("Word is not exist...Added to Tree");
		Add(p);
	}
	getch();
}
//------------------------------------------------
void BinerySearchTree::Border()
{
	clrscr();
	::x=1; ::y=2;
	int i;
	gotoxy(1,1);
	cprintf("Words                  Count");
	gotoxy(41,1);
	cprintf("Words                  Count");
	gotoxy(1,2);
	for (i=1;i<=80;i++)
		cprintf("-");

	for (i=1;i<=25;i++)
	{
		gotoxy(39,i);
		cprintf("|");
	}
}
//------------------------------------------------
void BinerySearchTree::Menu()
{
	char ch;
	int y=2;
	textmode(C80);
	textbackground(BLUE);
	textcolor(WHITE);
	clrscr();
	gotoxy(10,2);
	cprintf("1.Read from file");
	gotoxy(10,4);
	cprintf("2.Search and Print");
	gotoxy(10,6);
	cprintf("3.Insert New Word to Tree");
	gotoxy(10,8);
	cprintf("4.Delete Word from Tree");
	gotoxy(10,10);
	cprintf("5.Print all Words with sorted");
	gotoxy(10,12);
	cprintf("6.Print all Words with number repeated for Max to Min");
	gotoxy(10,14);
	cprintf("7.Exit Program");
	textcolor(LIGHTRED);
	gotoxy(5,2);
	cprintf("-->");
	while (ch!=27)
	{
		ch=getch();
		textcolor(LIGHTRED);
		gotoxy(5,y);
		cprintf("   ");
		if (ch==72)
		{
			y-=2;
			if (y<2)
				y=14;
		}
		else if (ch==80)
		{
			y+=2;
			if (y>14)
				y=2;
		}
		else if (ch==13)
		{
			switch (y)
			{
				case 2:
					if (!Root)
					{
					ReadFromFile();
					Menu();
					}
					break;
				case 4:
					PrintWord();
					Menu();
					break;
				case 6:
					Insert();
					Menu();
					break;
				case 8:
					Delete();
					Menu();
					break;
				case 10:
					Border();
					InOrder(Root);
					getch();
					Menu();
					break;
				case 12:
					SortingCount();
					getch();
					Menu();
					break;
				case 14:
					exit(0);
			}
		}
		gotoxy(5,y);
		cprintf("-->");
	}
}
//-----------------------------------------------------
void main()
{
	BinerySearchTree bst;
	bst.Menu();
}