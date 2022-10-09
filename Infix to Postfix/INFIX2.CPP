#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
struct node
{
	char ch;
	node *next;
};
class stack
{
	node *top;
	public:
		stack() { top=NULL; };
		void push(char ch);
		char pop();
		int empty();
		char GetTop() { return top->ch; };
};
void stack::push (char ch)
{
	node *p;
	p=new node();
	p->ch=ch;
	p->next=top;
	top=p;
}
char stack::pop()
{
	if (empty())
	{
		cout<<"Stack is empty";
		getch();
		return 0;
	}
	node *p;
	char ch;
	p=top;
	top=top->next;
	ch=p->ch;
	delete p;
	return ch;
}
int stack::empty()
{
	if (top==NULL)
		return 1;
	return 0;
}
//-----------------------------------
char infx[100],posfx[100];
int GetValue(char);
//-----------------------------------
void Calculate()
{
	stack s;
	int i,j=0,op1=0,op2=0;
	for (i=0;infx[i];i++)
	{
		if ((infx[i]>='A' && infx[i]<='Z') || (infx[i]>='a' && infx[i]<='z'))
			posfx[j++]=infx[i];
		else if (infx[i]=='(')
			s.push(infx[i]);
		else if (infx[i]==')')
		{
			while (s.GetTop()!='(')
			{
				posfx[j++]=s.pop();
			}
			s.pop();
		}
		else
		{
			op1=GetValue(infx[i]);
			op2=GetValue(s.GetTop());
			if (op1>op2)
				s.push(infx[i]);
			else
			{
				while (op1<=op2 && s.empty()==0)
				{
					posfx[j++]=s.pop();
					op2=GetValue(s.GetTop());
				}
				s.push(infx[i]);
			}
		}
	}
	while (s.empty()==0)
		posfx[j++]=s.pop();
	posfx[j]=0;
}
//------------------------------------
int GetValue(char ch)
{
	int val=0;
	if (ch=='+')
		val=1;
	else if (ch=='-')
		val=1;
	else if (ch=='*')
		val=2;
	else if (ch=='/')
		val=2;
	else if (ch=='^')
		val=3;
	return val;
}
//------------------------------------
void main()
{
	clrscr();
	ofstream f;
	cout<<"Enter your Infix:\n\n";
	gets(infx);
	Calculate();
	cout<<"\nPostfix is:\n\n";
	puts(posfx);
	f.open("file.txt");
	if (f==NULL)
	{
		cout<<"\n\nCan not save to file";
		getch();
		return;
	}
	cout<<"\n\n                          postfix saved to file";
	f<<posfx;
	getch();
}