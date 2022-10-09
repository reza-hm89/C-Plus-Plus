#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

struct StackNode
{
	int item;
	StackNode *next;
};
//======================================
class Stack
{
	public:
		StackNode *top;
		Stack() { top=NULL; };
		void push(int x);
		int pop();
		int  IsEmpty();
		void ShowList();
};
//======================================
int Stack::IsEmpty()
{
	if (top==NULL)
		return 1;
	return 0;
}
//======================================
int Stack::pop()
{
	int x;
	StackNode *p;
	if (IsEmpty())
		return 0;
	x=top->item;
	p=top;
	top=top->next;
	delete p;
	return x;
}
//=======================================
void Stack::push(int x)
{
	StackNode *p;
	p=new StackNode;
	p->item=x;
	p->next=top;
	top=p;
}
//=======================================
void Stack::ShowList()
{
	clrscr();
	StackNode *p;
	p=new StackNode;
	p=top;
	if (!p)
	{
		cout<<"List is empty...";
		getch();
		return;
	}
	while (p)
	{
		cout<<p->item<<"\t";
		p=p->next;
	}
	getch();
}
//======================================
int Menu();
void Select();
//======================================
void main()
{
	Select();
	getch();
}
//=======================================
int Menu()
{
	int n;
	clrscr();
	cout<<"1.Add In List";
	cout<<"\n2.Delete From List";
	cout<<"\n3.Show List";
	cout<<"\n4.Exit";
	cout<<"\n\nEnter 1-4: ";
	do {
		gotoxy(15,6);
		cin>>n;
	}while (n>4);
	return n;
}
//=======================================
void Select()
{
	Stack s;
	int n,num;
	char ans='y';
	while (1)
	{
	n=Menu();
	switch (n)
	{
		case 1:
			do {
			clrscr();
			cout<<"Enter a Number: ";
			cin>>num;
			s.push(num);
			cout<<"\nDo You Want To Continue (y/n): ";
			cin>>ans;
			} while (ans=='y');
			break;
		case 2:
			if (s.pop())
				cout<<"\nNode is delete...";
			else
				cout<<"\nList is emty...";
			getch();
			break;
		case 3:
			s.ShowList();
			break;
		case 4:
			exit(0);
			break;
	}
	}//end of while (1)
}