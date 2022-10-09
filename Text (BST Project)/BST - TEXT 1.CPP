#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

//==================================
struct treenode
{
	char string[30];
	int count;
	treenode *right,*left;
};
treenode tree[100];
int cnt;
//==================================
class BST
{
	treenode *root;
	public:
		BST() { root=NULL; };
		treenode* GetRoot()
		{
			return root;
		}
		void Add_Node(treenode *cur);
		void Delete_Node();
		void Edit();
		void InOrder(treenode *cur);
		void SearchWord();
		void InsertWord();
		void SortingCount();
		int Search(treenode *cur);
};

void BST::Add_Node(treenode *cur)
{
	treenode *p,*q;
	p=root;
	q=NULL;
	while (p)
	{
		q=p;
		if (strcmp(p->string,cur->string)<0)
			p=p->right;
		else
			p=p->left;
	}
	p=new treenode;
	p=cur;
	p->left=p->right=NULL;
	if (!root)
		root=p;
	if (strcmp(q->string,cur->string)<0)
		q->right=p;
	else
		q->left=p;
}
//---------------------------------------
void BST::Delete_Node()
{
	int found=0;
	char s[30];
	clrscr();
	treenode *p,*q;
	p=root;
	cout<<"Enter a Word: ";
	gets(s);
	if(!p)
	{
		cout<<"Not Found";
		getch();
		return;
	}
	while(p)
	{
		if(strcmp(p->string,s)==0)
		{
			found = 1;
			break;
		}
		else
		{
			q=p;
			if (strcmp(p->string,s)<0)
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
		treenode *pR;
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
			treenode *hlp1;       //lpr=hlp1
			treenode *hlp2;     //lprp=hlp2
			hlp2=p->right;
			hlp1=(p->right)->left;
			while(hlp1->left!=NULL)
			{
				hlp2=hlp1;
				hlp1=hlp1->left;
			}
			strcpy(p->string,hlp1->string);
			p->count=hlp1->count;
			delete hlp1;
			hlp2->left = NULL;
		}
		else
		{
			treenode *temp;
			temp=p->right;
			strcpy(p->string,temp->string);
			p->count=temp->count;
			p->right=temp->right;
			delete temp;
		}
		}//else
		return;
	}
}
//---------------------------------------
void BST::InOrder(treenode *cur)
{
	if (cur)
	{
		 InOrder(cur->left);
		 cout<<"\n"<<cur->string;
		 gotoxy(17,wherey());
		 strcpy(tree[cnt].string,cur->string);
		 tree[cnt++].count=cur->count;
		 cout<<cur->count;
		 InOrder(cur->right);
	}
}
//---------------------------------------
void BST::SearchWord()
{
	clrscr();
	char s[30];
	treenode *p=root,*cur;
	cur=new treenode();
	cout<<"Enter a Word: ";
	gets(s);
	strcpy(cur->string,s);
	cur->count=1;

	while (p)
	{
		if (strcmp(p->string,cur->string)==0)
		{
			cout<<"Founded...";
			cout<<"\nWord: "<<p->string;
			cout<<"\nRepeated: "<<p->count;
			getch();
			return;
		}
		else if (strcmp(p->string,cur->string)<0)
			p=p->right;
		else
			p=p->left;
	}
	cout<<"Not Found...";
	getch();
}
//---------------------------------------
void BST::InsertWord()
{
	clrscr();
	char s[30];
	treenode *p=root,*cur;
	cur=new treenode();
	cout<<"Enter a Word: ";
	gets(s);
	strcpy(cur->string,s);
	cur->count=1;

	while (p)
	{
		if (strcmp(p->string,cur->string)==0)
		{
			p->count++;
			cout<<"\nFounded...";
			cout<<"\nWord: "<<p->string;
			cout<<"\nRepeat: "<<p->count;
			getch();
			return;
		}
		else if (strcmp(p->string,cur->string)<0)
			p=p->right;
		else
			p=p->left;
	}
	cout<<"\nNot Found...";
	Add_Node(cur);
	cout<<"\nAdded to List...";
	getch();
}
//---------------------------------------
int BST::Search (treenode * cur)
{
	treenode *p=root;
	while (p)
	{
		if (strcmp(p->string,cur->string)==0)
		{
			p->count++;
			return 1;
		}
		else if (strcmp(p->string,cur->string)<0)
			p=p->right;
		else
			p=p->left;
	}
	return 0;
}
//==================================
void InOrder2(treenode *cur)
{
	if (cur)
	{
		 InOrder2(cur->left);
		 strcpy(tree[cnt].string,cur->string);
		 tree[cnt++].count=cur->count;
		 InOrder2(cur->right);
	}
}
//==================================
void BST::SortingCount()
{       int i,j;
	clrscr();
	treenode temp;
	cnt=0;
	InOrder2(GetRoot());
	for (i=0;i<cnt;i++)
		for (j=i+1;j<cnt;j++)
			if (tree[i].count<tree[j].count)
			{
				temp=tree[i];
				tree[i]=tree[j];
				tree[j]=temp;
			}
	cout<<"Word            Count";
	cout<<"\n---------------------";

	for (i=0;i<cnt;i++)
	{
		cout<<"\n"<<tree[i].string;
		gotoxy(17,wherey());
		cout<<tree[i].count;
	}
	getch();
}
//==================================
//            Define Functions
void Get_String();
void Initial_Tree();
void InOrder2(treenode*);
void Menu();
//==================================
//            Define public Variables
char str[100][30];
int StrCnt;
BST b;
//==================================
void main()
{
	char *p;
	textbackground(0);
	clrscr();
	textcolor(WHITE);
	Get_String();
	Initial_Tree();
	Menu();
	getch();
}
//==================================
void Menu()
{
	int n;
	clrscr();
	cout<<"\n1. Search a Word";
	cout<<"\n\n2. Insert Word";
	cout<<"\n\n3. Delete Word";
	cout<<"\n\n4. Prints all Sorted Words";
	cout<<"\n\n5. Prints all Words with numbers of repeated";
	cout<<"\n\n6. Exit Program";
	cout<<"\n\n\nEnter Number (1...6):  ";
	do {
		gotoxy(25,15);
		cout<<"           ";
		gotoxy(25,15);
		cin>>n;
	} while (n<1 || n>6);
	switch (n)
	{
		case 1:
			b.SearchWord();
			Menu();
		break;
		case 2:
			b.InsertWord();
			Menu();
		break;
		case 3:
			b.Delete_Node();
			Menu();
		break;
		case 4:
			clrscr();
			cout<<"Words          Count";
			cout<<"\n--------------------";
			b.InOrder(b.GetRoot());
			getch();
			Menu();
		break;
		case 5:
			b.SortingCount();
			Menu();
		break;
		case 6:
			exit(0);
	}
}
//==================================
void Get_String()
{
	int i=0,j=0,k=0,n;
	char ch,s[1000];
	ifstream f;
	f.open("text.txt");
	if (!f)
	{
		cout<<"Can not open file...";
		return;
	}
	while (!f.eof())
	{
		f.get(ch);
		s[i++]=ch;
	}
	s[i]=0;
	for (j=0;j<i;j++)
		if (s[j]>='A' && s[j]<='Z')
			s[j]+=32;
	f.close();
	j=0;
	n=i;
	for (i=0;i<n;i++)
	{
		if ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))
			str[j][k++]=s[i];
		else if ((s[i+1]>='A' && s[i+1]<='Z') || (s[i+1]>='a' && s[i+1]<='z')|| s[i+1]==0)
		{
			str[j++][k]=0;
			k=0;
		}
	}
	StrCnt=j;
}
//==================================
void Initial_Tree()
{
	treenode *temp;
	for (int i=0;i<StrCnt;i++)
	{
		temp=new treenode();
		strcpy(temp->string,str[i]);
		temp->count=1;
		temp->right=temp->left=NULL;
		if (!b.Search(temp))
			b.Add_Node(temp);
	}
}