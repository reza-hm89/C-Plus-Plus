#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

struct treenode
{
	char str[30];
	int cnt;
	treenode *right,*left;
};
treenode b[100];//baraye chap tree besoorate morateb bar asase field cnt
int max;

class BST
{
	public:
		treenode *root;
		BST() { root=NULL; };
		void Add(treenode *cur);
		void Delete();
		void Inorder(treenode *cur);
		int Search(int,treenode*);
		void Insert();
		void Sort();
}bst;

void BST::Add(treenode *cur)
{
	treenode *p,*q;
	p=root;
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
	if (!root)
		root=p;
	if (strcmp(q->str,cur->str)<0)
		q->right=p;
	else
		q->left=p;
}
//---------------------------------------
void BST::Delete()
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
		if(strcmp(p->str,s)==0)
		{
			found = 1;
			break;
		}
		else
		{
			q=p;
			if (strcmp(p->str,s)<0)
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
			strcpy(p->str,hlp1->str);
			p->cnt=hlp1->cnt;
			delete hlp1;
			hlp2->left = NULL;
		}
		else
		{
			treenode *temp;
			temp=p->right;
			strcpy(p->str,temp->str);
			p->cnt=temp->cnt;
			p->right=temp->right;
			delete temp;
		}
		}//else
		return;
	}
}
int ypos;
//---------------------------------------
void BST::Inorder(treenode *cur)
{
	if (cur)
	{
		 Inorder(cur->left);
		 strcpy(b[max].str,cur->str);
		 b[max++].cnt=cur->cnt;
		 gotoxy(10,ypos);
		 cout<<cur->str;
		 gotoxy(30,ypos++);
		 cout<<cur->cnt;
		 Inorder(cur->right);
	}
}
void BST::Insert()
{
	clrscr();
	char s[30];
	treenode *p=root,*cur;
	cur=new treenode();
	cout<<"Enter a Word: ";
	gets(s);
	strcpy(cur->str,s);
	cur->cnt=1;

	while (p)
	{
		if (strcmp(p->str,cur->str)==0)
		{
			p->cnt++;
			cout<<"\nFounded...";
			cout<<"\nWord: "<<p->str;
			cout<<"\nRepeat: "<<p->cnt;
			getch();
			return;
		}
		else if (strcmp(p->str,cur->str)<0)
			p=p->right;
		else
			p=p->left;
	}
	cout<<"\nNot Found...";
	Add(cur);
	cout<<"\nAdded to List...";
	getch();
}
//---------------------------------------
int BST::Search (int sw,treenode * cur)
{       //sw baraye zamani ke agar 1 bashad bayad be tedad
	//tekraresh ezafe kone,age 0 bashe niyazi nis be tedad tekraresh add kone
	treenode *p=root;
	while (p)
	{
		if (strcmp(p->str,cur->str)==0)
		{
			if (sw)
				p->cnt++;
			cur->cnt=p->cnt;
			return 1;
		}
		else if (strcmp(p->str,cur->str)<0)
			p=p->right;
		else
			p=p->left;
	}
	return 0;
}
//==================================
void BST::Sort()
{
	treenode temp;
	int i,j;
	for (i=0;i<max;i++)
		for (j=i+1;j<max;j++)
			if (b[i].cnt<b[j].cnt)
			{
				temp=b[i];
				b[i]=b[j];
				b[j]=temp;
			}
	for (i=0;i<max;i++)
	{
		gotoxy(10,i+5);
		cout<<b[i].str;
		gotoxy(30,i+5);
		cout<<b[i].cnt;
	}
}

void Menu();

void main()
{
	int i=0,j,k;
	char ch,str[30],*s;
	treenode *p;
	ifstream f;
	f.open("text.txt");
	if (!f)
	{
		cout<<"Can not open file...";
		return;
	}
	while (!f.eof())
	{
		f.read((char*)&ch,sizeof(char));
		s[i++]=ch;
	}
	s[i]='\0';
	for (j=0;j<i;j++)
		if (s[j]>='A' && s[j]<='Z')
			s[j]+=32;
	f.close();
	for (i=0,j=0;s[i];i++)
	{
		if  (s[i]>='a' && s[i]<='z')
			str[j++]=s[i];
		else
		{
			str[j]=0;
			if (str[0])
			{
				p=new treenode;
				strcpy(p->str,str);
				p->cnt=1;
				if (!bst.Search(1,p))
					bst.Add(p);
			}
			j=0;
		}
	}
	Menu();
}
//==================================
void Menu()
{
	int n,y=10;
	char ch;
	treenode *p;
while (1)
{
	clrscr();
	gotoxy(20,10);
	cout<<"1. Search a Word";
	gotoxy(20,12);
	cout<<"2. Insert Word";
	gotoxy(20,14);
	cout<<"3. Delete Word";
	gotoxy(20,16);
	cout<<"4. Prints all Sorted Words";
	gotoxy(20,18);
	cout<<"5. Prints all Words with numbers of repeated";
	gotoxy(20,20);
	cout<<"6. Exit Program";
	gotoxy(15,10);
	cout<<"**>>";
	y=10;
	ch=0;
	while(ch!=27)
	{

		ch=getch();
		gotoxy(15,y);
		cout<<"    ";
		if (ch==72)
			y-=2;
		else if (ch==80)
			y+=2;
		if (y>20)
			y=10;
		if (y<10)
			y=20;
		if (ch==13)
		{
		clrscr();
		switch (y)
		{
			case 10:
				p=new treenode;
				cout<<"Enter word: ";
				gets(p->str);
				if (bst.Search(0,p))
				{
				cout<<"found...\n";
				cout<<p->str;
				cout<<"\n"<<p->cnt;
				}
				else
					cout<<"not found";
				getch();
				break;
			case 12:
				bst.Insert();
				break;
			case 14:
				bst.Delete();
				break;
			case 16:
				ypos=5;
				max=0;
				bst.Inorder(bst.root);
				getch();
				break;
			case 18:

				bst.Sort();
				max=0;
				getch();
				break;
			case 20:
				exit(0);
				break;
		}

		ch=27;
		}
		gotoxy(15,y);
		cout<<"**>>";

	}
	}
}