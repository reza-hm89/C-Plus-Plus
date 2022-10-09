#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>

class stack
{
	int top;
	int a[100],n;
	public:
		stack() { top=-1; };
		void push(char ch);
		char pop();
		int empty();
		char GetTop() { return a[top]; };
};
void stack::push (char ch)
{
	a[++top]=ch;
}
char stack::pop()
{
	if (empty())
	{
		cout<<"Stack is empty";
		getch();
		return 0;
	}
	return a[top--];
}
int stack::empty()
{
	if (top==-1)
		return 1;
	return 0;
}
//-----------------------------------
char infx[100],posfx[100],prefx[100];
int GetValue(char);
//-----------------------------------
void Postfix()
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
//-----------------------------------
void Prefix()
{
	stack s1,s2;
	int i,j=0,op1=0,op2=0;
	for (i=strlen(infx)-1;i>=0;i--)
	{
		if ((infx[i]>='A' && infx[i]<='Z') || (infx[i]>='a' && infx[i]<='z'))
			s2.push(infx[i]);
		else if (infx[i]==')')
			s1.push(infx[i]);
		else if (infx[i]=='(')
		{
			while (s1.GetTop()!=')')
			{
				s2.push(s1.pop());
			}
			s1.pop();
		}
		else
		{
			op1=GetValue(infx[i]);
			op2=GetValue(s1.GetTop());
			if (op1>=op2)
				s1.push(infx[i]);
			else
			{
				while (op1<op2 && s1.empty()==0)
				{
					s2.push(s1.pop());
					op2=GetValue(s1.GetTop());
				}
				s1.push(infx[i]);
			}
		}
	}
	while (s1.empty()==0)
		s2.push(s1.pop());
	j=0;
	while (s2.empty()==0)
		prefx[j++]=s2.pop();
	prefx[j]=0;
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
//-----------------------------------
int CalculatePostfix()
{
	stack s;
	int i,n,x1,x2;
	for (i=0;i<strlen(posfx);i++)
	{
		if ((posfx[i]>='A' && posfx[i]<='Z') || (posfx[i]>='a' && posfx[i]<='z'))
		{
			cout<<"\nEnter "<<posfx[i]<<" : ";
			cin>>n;
			s.push(n);
		}
		else
		{
			x1=s.pop();
			x2=s.pop();
			if (posfx[i]=='+')
			{
				s.push(x1+x2);
			}
			if (posfx[i]=='-')
			{
				s.push(x1-x2);
			}
			if (posfx[i]=='*')
			{
				s.push(x1*x2);
			}
			if (posfx[i]=='/')
			{
				s.push(x1/x2);
			}
			if (posfx[i]=='^')
			{
				s.push(x1^x2);
			}
		}
	}
	return s.pop();
}
//-----------------------------------
int CalculatePrefix()
{
	stack s;
	int i,n,x1,x2;
	for (i=strlen(posfx)-1;i>=0;i--)
	{
		if ((prefx[i]>='A' && prefx[i]<='Z') || (prefx[i]>='a' && prefx[i]<='z'))
		{
			cout<<"\nEnter "<<prefx[i]<<" : ";
			cin>>n;
			s.push(n);
		}
		else
		{
			x1=s.pop();
			x2=s.pop();
			if (prefx[i]=='+')
			{
				s.push(x1+x2);
			}
			if (prefx[i]=='-')
			{
				s.push(x1-x2);
			}
			if (prefx[i]=='*')
			{
				s.push(x1*x2);
			}
			if (prefx[i]=='/')
			{
				s.push(x1/x2);
			}
			if (prefx[i]=='^')
			{
				s.push(x1^x2);
			}
		}
	}
	return s.pop();
}
//------------------------------------
void main()
{
	int result;
	clrscr();
	cout<<"Enter your Infix:\n";
	gets(infx);
	Postfix();
	Prefix();
	cout<<"\nPostfix is:\n";
	puts(posfx);
	cout<<"\nPrefix is:\n";
	puts(prefx);
	result=CalculatePostfix();
	cout<<"\nPostfix result: "<<result<<"\n";
	result=CalculatePrefix();
	cout<<"\nPrefix result: "<<result;
	getch();
}