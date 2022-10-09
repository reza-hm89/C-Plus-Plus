#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

struct avlNode
{
	int data;
	int height;
	avlNode *LeftChild,*RightChild;
};

struct stacknode
{
	avlNode *item;
	stacknode *next;
};

class Stack
{
	stacknode *top;
	public:
		Stack() { top=NULL; };
		avlNode* ShowTop()
		{
			if  (!IsEmpty())
				return top->item;
			return 0;
		};
		int IsEmpty()
		{
			if (top==NULL)
				return 1;
			return 0;
		};
		avlNode* Pop(avlNode*);
		void Push(avlNode *ch);

};
void Stack::Push(avlNode *ch)
{
	stacknode *p;
	p=new stacknode();
	p->item=ch;
	p->next=top;
	top=p;
}
avlNode* Stack::Pop(avlNode *x)
{
	stacknode *p;
	if (IsEmpty())
	{
		cout<<"Stack is Empty";
		getch();
		return 0;
	}
	x=top->item;
	p=top;
	top=top->next;
	delete p;
	return x;
}

class avl
{
	public:
		avlNode *root;

		avl() { root =NULL; };
		void insert(avlNode *);
		avlNode* insert(avlNode *,avlNode*);
		int height(avlNode *);
		int parentCalculate(avlNode *, avlNode *);

		void Delete(avlNode *);
		avlNode* avl::LR(avlNode *);
		avlNode* avl::RL(avlNode *);
		avlNode* avl::RR(avlNode *);
		avlNode* avl::LL(avlNode *);
		void InOrder(avlNode*);
}a;
int max (int a,int b)
{
	if (a>b)
		return a;
	else
		return b;
}
void avl::insert(avlNode *newNode)
{
	root = insert(newNode,root);
}
int avl::height(avlNode *x)
{
	if(!x)
		return -1;
	else
		return max(height(x->LeftChild),height(x->RightChild))+1;
}//end height
void avl::InOrder(avlNode *cur)
{
	if (cur==NULL)
		return;
	else
	{
		InOrder(cur->LeftChild);
		cout<<cur->data<<"\t";
		InOrder(cur->RightChild);
	}
}
avlNode* avl::insert(avlNode *newNode, avlNode *current)
{
	int x = newNode->data;
	if( !current )
	{
	current = newNode;
	}//end if
	else if( x < current->data )
	{
		current->LeftChild = insert(newNode,current->LeftChild);
		if(height(current->LeftChild) - height(current->RightChild) == 2)
		{
			if( x < current->LeftChild->data )
			current = LL(current);
			else current = LR(current);
		}//end if
	}//end else if
	else if( x > current->data )
	{
		current->RightChild = insert(newNode,current->RightChild);
		if(height(current->LeftChild)- height(current->RightChild) == -2)
		{
			if(x > current->RightChild->data )
				current = RR(current);
			else current = RL(current);
		}//end if
	}//end else if
	current->height = max ( height(current->LeftChild), height(current->RightChild)) + 1;
	return current;
}//end insert
//=========== LR rotate in avl ================
avlNode *avl::LR(avlNode *a)
{
	avlNode *b = a->LeftChild;
	avlNode *c = b->RightChild;
	b->RightChild = c->LeftChild;
	a->LeftChild = c->RightChild;
	c->RightChild = a;
	c->LeftChild = b;
	a->height = max ( height(a->LeftChild) , height(a->RightChild) ) + 1 ; b->height = max ( height(b->LeftChild) , height(b->RightChild) ) + 1 ; c->height = max ( height(a) , height(b) ) + 1 ; return c;
}//end LR
//=========== RL rotate in avl ================
avlNode *avl::RL(avlNode *a)
{
	avlNode *b = a->RightChild;
	avlNode *c = b->LeftChild;
	a->RightChild = c->LeftChild;
	b->LeftChild = c->RightChild;
	c->RightChild = b;
	c->LeftChild = a;
	a->height = max ( height(a->LeftChild) , height(a->RightChild) ) + 1 ;
	b->height = max ( height(b->LeftChild) , height(b->RightChild) ) + 1 ;
	c->height = max ( height(a) , height(b) ) + 1 ;
	return c;
}//end RL
//=========== LL rotate in avl ================
avlNode *avl::LL(avlNode *a)
{
	avlNode *b = a->LeftChild;
	a->LeftChild = b->RightChild;
	b->RightChild = a;
	a->height = max ( height (a->LeftChild) , height (a->RightChild)) + 1 ;
	b->height = max ( height (a) , height(b->LeftChild) ) + 1 ;
	return b;
}//end LL
//=========== RR rotate in avl ================
avlNode *avl::RR(avlNode *a)
{
	avlNode *b = a->RightChild;
	a->RightChild = b->LeftChild;
	b->LeftChild = a;
	a->height = max ( height(a->RightChild) , height (a->LeftChild) ) + 1 ;
	b->height = max (height(a) , height(b->RightChild) ) + 1 ;
	return b ;
}//end RR

void avl::Delete(avlNode *deletedNode)
{
	Stack s;
	avlNode *check;
	int x = deletedNode->data;
	avlNode *current = root ;
	avlNode *parent = 0 ;
	while ( current )
	{
		if( x < current->data )
		{
			s.Push(current);
			parent = current;
			current = current->LeftChild ;
		}//end if
		else if ( x > current->data )
		{
			s.Push(current);
			parent = current;
			current = current->RightChild;
		}//end else if
		else break;
	}//end while
	if ( !current )
	{
		cout<<"not found";
		return;
	}//end if(!current)

	cout<<"\nDeleted...";
	if( current->LeftChild && current->RightChild )//current has 2 children
	{
		s.Push(current);
		avlNode *l = current->LeftChild,*p=current;
		while(l->RightChild)
		{
			s.Push(l);
			p=l;
			l = l->RightChild;
		}//end while
		if(p!=current)
			p->RightChild=l->LeftChild;
		else
			p->LeftChild = l->LeftChild;
		current->data=l->data;
		delete l;
	}//end if
	else if ( current->RightChild )//current has 1 child in right
	{
		if(!parent)
			root = current->RightChild;
		else
		{
			if( parent->RightChild == current )
			{
				parent->RightChild = current->RightChild;
				s.Push(parent->RightChild);
			}//end if
			else
			{
				parent->LeftChild = current->RightChild ;
				s.Push(parent->LeftChild);
			}//end else
		}//end else
		delete current ;
	}//end else if
	else if( current->LeftChild )//current has 1 child in left
	{
		if(!parent)
			root = current->LeftChild;
		else
		{
			if(parent->RightChild == current )
			{
				parent->RightChild = current->LeftChild;
				s.Push(parent->RightChild);
			}//end if
			else
			{
				parent->LeftChild = current->LeftChild;
				s.Push(parent->LeftChild);
			}//end else
		}//end else
		delete current;
	}//end else if
	else// current is a leaf
	{
		if(!parent)
		root = 0;
		else
		{
			if ( x > parent->data )
				parent->RightChild = 0 ;
			else
				parent->LeftChild = 0 ;
		}//end else
		delete current;
	}//end else ( leaf )
	while(!s.IsEmpty())
	{
		avlNode *par;
		s.Pop(check);
		int v = parentCalculate(check,par);
		if(height(check->LeftChild)-height(check->RightChild) == 2 )
		{
			if(height(check->LeftChild->RightChild ) > height(check->LeftChild->LeftChild))
			{
				if(par)
				{
					if( v == 0 )
						par->LeftChild = LR(check);
					else
						par->RightChild = LR(check);
				}//end if(par)
				else
					root = LR(check);
			}//end if
			else
			{
				if(par)
				{
					if(v == 0 )
						par->LeftChild = LL(check);
					else
						par->RightChild = LL(check);
				}//end if(par)
				else
					root = LL(check);
			}//end else
		}//end if else
		if(height(check->LeftChild)-height(check->RightChild)== -2 )
		{
			if(height(check->RightChild->RightChild) < height(check->RightChild->LeftChild))
			{
				if(par)
				{
					if( v == 0 )
						par->LeftChild = RL(check);
					else
						par->RightChild = RL(check);
				}//end if(par)
				else
					root = RL(check);
			}//end if
			else
			{
				if(par)
				{
					if( v == 0 )
						par->LeftChild = RR(check);
					else
						par->RightChild = RR(check);
				}//end if(par)
				else root = RR(check);
			}//end else
		}//end else if
	}//end while
}//end delete function

int avl::parentCalculate(avlNode *x, avlNode *parent)
{
	int right_or_left = 0;//0 :left; 1 :right parent = 0;
	avlNode *p = root;
	while(p)
	{
		if ( x->data > p->data )
		{
			parent = p ;
			p = p->RightChild;
			right_or_left = 1;
		}//end if
		else if( x->data < p->data )
		{
			parent = p ;
			p = p->LeftChild;
			right_or_left = 0;
		}//end else if
		else
			break;
	}//end while
	return right_or_left;
}//end parent function
void Menu()
{
	int n;
	clrscr();
	cout<<"\n1.Insert Number";
	cout<<"\n2.Delete Number";
	cout<<"\n3.Order";
	cout<<"\n4.Exit";
	cout<<"\n\nEnter n (1-4): ";

	do {
		gotoxy(1,8);
		cout<<"            ";
		gotoxy(1,8);
		cin>>n;
	} while (n<1 || n>4);

	switch (n)
	{
		case 1:
			int num;
			avlNode *cur=new avlNode;
			clrscr();
			cout<<"Enter Number: ";
			cin>>num;
			cur->data=num;
			cur->LeftChild=cur->RightChild=NULL;
			a.insert(cur);
			Menu();
			break;
		case 2:
			cur=new avlNode;
			clrscr();
			cout<<"Enter Number: ";
			cin>>num;
			cur->data=num;
			a.Delete(cur);
			getch();
			Menu();
			break;
		case 3:
			clrscr();
			a.InOrder(a.root);
			getch();
			Menu();
			break;
		case 4:
			exit(0);
	}
}
void main()
{
	Menu();
}