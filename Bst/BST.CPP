#include<iostream.h>
#include<conio.h>

struct treenode
{
	int CompNum;
	char CompName[30];
	treenode *left,*right;
};
//-------------------------------------------------
const maxsize=20;
//-------------------------------------------------
class Queue
{
	int front,rear;
	treenode* q[maxsize];
	public:
		Queue() { front=rear=-1; };
		void Insert (treenode *cur)
		{
			if (rear >= maxsize)
				return;
			q[++rear] = cur;
		}
		treenode* Delete()
		{
			if (isEmpty())
				return NULL;
			return q[++front];
		}
		int isEmpty()
		{
			if (front == rear)
				return 1;
			return 0;
		}
};
//------------------------------------------------
class BST
{
	treenode *root;
	public:
		BST() { root=NULL; };
		treenode* GetRoot()
		{
			return root;
		}
		treenode* InputData();
		void Add_Node(treenode *cur);
		void Delete_Node(int NodeNum);
		void Edit();
		void InOrder(treenode *cur);
		void PreOrder(treenode *cur);
		void PostOrder(treenode *cur);
		void LevelOrder(treenode *cur);
};

treenode* BST::InputData()
{
	treenode *newnode=new treenode();
	clrscr();
	cout<<"Enter Component numbre: ";
	cin>>newnode->CompNum;
	cout<<"Enter Component name: ";
	cin>>newnode->CompName;
	newnode->right=newnode->left=NULL;
	getch();
	return newnode;
}
void BST::Add_Node(treenode *cur)
{
	treenode *p,*q;
	p=root;
	q=NULL;
	while (p)
	{
		q=p;
		if (p->CompNum<cur->CompNum)
			p=p->right;
		else
			p=p->left;
	}
	p=new treenode;
	p=cur;
	p->left=p->right=NULL;
	if (!root)
		root=p;
	if (q->CompNum<cur->CompNum)
		q->right=p;
	else
		q->left=p;
}
//---------------------------------------
void BST::Edit()
{
	treenode *p=root,*cur=new treenode();
	cout<<"Enter Component number for edit: ";
	cin>>cur->CompNum;
	while (p)
	{
		if (p->CompNum==cur->CompNum)
		{
			cout<<"\nOld Name: "<<p->CompName;
			cout<<"\n\n\nEnter New Component name: ";
			cin>>p->CompName;
		}
		else if (p->CompNum<cur->CompNum)
			p=p->right;
		else
			p=p->left;
	}

}
//---------------------------------------
void BST::Delete_Node(int NodeNum)
{
	int found=0;
	clrscr();
	treenode *p,*parent;
	p=root;
	if(!p)
		return;
	while(p)
	{
		if(p->CompNum == NodeNum)
		{
			found = 1;
			break;
		}
		else
		{
			parent = p;
			if(p->CompNum<NodeNum)
				p = p->right;
			else p = p->left;
		}
	}
	if(!found)
	{
		textcolor(RED);
		gotoxy(30,3);
		cprintf("Node not found!");
		getch();
		return;
	}
	textcolor(RED);
	gotoxy(30,3);
	cprintf("Node Deleted...");
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
//---------------------------------------
void BST::InOrder(treenode *cur)
{
	if (cur)
	{
		 InOrder(cur->left);
		 cout<<cur->CompNum<<"  "<<cur->CompName<<"       ";
		 InOrder(cur->right);
	}
}
//---------------------------------------
void BST::PreOrder(treenode *cur)
{
	if (cur)
	{
		 cout<<cur->CompNum<<"  "<<cur->CompName<<"       ";
		 PreOrder(cur->left);
		 PreOrder(cur->right);
	}
}
//---------------------------------------
void BST::PostOrder(treenode *cur)
{
	if (cur)
	{
		 PostOrder(cur->left);
		 PostOrder(cur->right);
		 cout<<cur->CompNum<<"  "<<cur->CompName<<"       ";
	}
}
//---------------------------------------
void BST::LevelOrder (treenode * cur)
{
	treenode * temp;
	Queue q;
	q.Insert (cur);
	while ( ! q.isEmpty () )
	{
		temp = q.Delete ();
		if (temp -> left)
			q.Insert (temp->left);
		if (temp -> right)
			q.Insert (temp->right);
		cout<<temp->CompNum<<"  "<<temp->CompName<<"       ";
	}
}
//---------------------------------------

void Menu();

BST Btree;
//---------------------------------------
void main()
{
	Menu();
}
//---------------------------------------
void Menu()
{
	int n,num;
	treenode *cur;
	clrscr();
	cout<<"\n1.Insert Node";
	cout<<"\n2.Delete Node";
	cout<<"\n3.Edit Node";
	cout<<"\n4.Pre Order";
	cout<<"\n5.In Order";
	cout<<"\n6.Post Order";
	cout<<"\n7.Level Order";
	cout<<"\n8.Exit";
	cout<<"\n\nEnter Number (1-8): ";

	do {
		gotoxy(25,11);
		cout<<"          ";
		gotoxy(25,11);
		cin>>n;
		switch(n)
		{
			case 1:
				cur=Btree.InputData();
				Btree.Add_Node(cur);
				cout<<"\nAdded to tree";
				getch();
				Menu();
				break;
			case 2:
				clrscr();
				cout<<"Enter Number Node for Delete:";
				cin>>num;
				Btree.Delete_Node(num);
				Menu();
				break;
			case 3:
				clrscr();
				Btree.Edit();
				getch();
				Menu();
				break;
			case 4:
				clrscr();
				Btree.PreOrder(Btree.GetRoot());
				getch();
				Menu();
				break;
			case 5:
				clrscr();
				Btree.InOrder(Btree.GetRoot());
				getch();
				Menu();
				break;
			case 6:
				clrscr();
				Btree.PostOrder(Btree.GetRoot());
				getch();
				Menu();
				break;
			case 7:
				clrscr();
				Btree.LevelOrder(Btree.GetRoot());
				getch();
				Menu();
				break;
			case 8:
				return;
		}
	} while(n<1 || n>8);
}