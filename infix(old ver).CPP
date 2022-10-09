#include<conio.h>
#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
const max=100;
class stack {
	private:
		int top;
		char starray[max];
	public:
		stack() { top=-1; };
		void push(char x);
		char pop();
		char showtop();
		int  empty();
	};
////////////////////////////////////////
char stack::showtop() {
	if (!empty())
	return starray[top];
	return NULL;
	}
////////////////////////////////////////
int stack::empty() {
	if (top==-1)
		return 1;
	else	return 0;
	}
////////////////////////////////////////
char stack::pop() {
		return	starray[top--];
	}
////////////////////////////////////////
void stack::push(char x) {
	starray[++top]=x;
	}
////////////////////////////////////////
int convert();
int operand(char,int&,int&);
int variable(char,int&,int&);
int opert(char,char);
void func();
///////////////////////////////////////
char infix[max],postfix[max][max],f[max];
/////////////////////////////////////
void main()
{
	int i=0,j,n;
	clrscr();
	cout<<"Enter your string:\n";
	gets(infix);
       //	func(); //mohasebe motaghayer exmple:f(x)=1+1  'x'
	n=convert();//n:tedad satrhaye reshte 2bodi
	for (i=0;i<=n;i++) {
		for (j=0;postfix[i][j];j++)
		cout<<postfix[i][j];
		cout<<" ";
		}
	cout<<endl<<f;
	getch();
	getch();
}
/////////////////////////////////////
void func()
{
	int i=0,j,k=0;
	char var[20];
	while (infix[i]!='=') {
		f[i]=infix[i];
		i++;
	}
	i++;
	for (j=0;infix[i];j++,i++)
		infix[j]=infix[i];
	infix[j]='\0';
	for (i=0;i<strlen(f);i++)
		if (f[i]=='(') {
		j=i+1;
		while (f[j]!=')')
			var[k++]=f[j++];
		break;
		}
	var[k]='\0';
	cout<<var;
	getch();
}
/////////////////////////////////////
int convert()
{
	int i=0,j=-1,k=0,sum;
	stack s;
	char symbol,topsymbol;
	while (infix[i])
	{
		symbol=infix[i];
		if (operand(symbol,i,j));
		else if (variable(symbol,i,j));
		else if (symbol=='(')
			s.push(symbol);
		else if (symbol==')')
		{
			topsymbol=s.pop();
			while(topsymbol!='(')
			{
				postfix[++j][0]=topsymbol;
				topsymbol=s.pop();
			}//end of while
		}//end of else if
		else {
			if (s.empty())
				s.push(symbol);
			else {
			topsymbol=s.showtop();
			if (opert(topsymbol,symbol))
				s.push(symbol);
			else {
			do   {
				if(!opert(topsymbol,symbol))
				postfix[++j][0]=s.pop();
				topsymbol=s.showtop();
			}
			while (!s.empty() && topsymbol!='(');
			s.push(symbol);
			}
			}
		     }
	i++;
	}//end of while
	while (!s.empty())
	{
		topsymbol=s.pop();
		postfix[++j][k]=topsymbol;
	}
	return j;
}
///////////////////////////////////
int opert(char op1,char op2)
{
	char op[6]={'(','+','-','*','/','^'};

	int iop [6]={0,1,1,2,2,3};
	int i,p1,p2;
	for (i=0;op[i];i++)
		if (op1==op[i]) {
			p1=i;
			break;  }
	for (i=0;op[i];i++)
		if (op2==op[i]) {
			p2=i;
			break;	}
	if (iop[p1]<iop[p2])
		return 1;
	return 0;
}
//////////////////////////////////
int variable(char symbol,int &i,int &j)
{
	int k=0,num;
	char temp[20];
	j++;
	if ((symbol>='a' && symbol<='z') || (symbol>='A' && symbol<='Z'))
	{	while ((infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z'))
		{	temp[k++]=infix[i];
			i++;
		}
		i--;
	temp[k]='\0';
	cout<<"\nEnter your variable "<<temp<<":";
	cin>>num;
	ltoa(num,temp,5);
	strcpy(postfix[j],temp);
	return 1;
	}
	return 0;
}
//////////////////////////////////
int operand(char symbol,int &i,int &j)
{
	int k=0;
	j++;
	if (symbol>='0' && symbol<='9')  {
		while (infix[i]>='0' && infix[i]<='9' || infix[i]=='.') {
			postfix[j][k++]=infix[i];
			i++; }
		i--;
		return 1;
	}
	return 0;
}