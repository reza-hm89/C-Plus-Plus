#include<conio.h>
#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
const max=100;
int inc=-1;
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
int error();
void func();
///////////////////////////////////////
char infix[max],postfix[max][max],f[max],v[20][20];
/////////////////////////////////////
void main()
{
	int i=0,j,n;
	clrscr();
	do {
	gotoxy(1,2);
	cout<<"                                                    ";
	gotoxy(1,3);
	cout<<"                                                    ";
	gotoxy(1,1);
	cout<<"Enter your string:\n";
	gets(infix);
	} while (!error());
     //  func(); //mohasebe motaghayer exmple:f(x)=1+1  'x'
	n=convert();//n:tedad satrhaye reshte 2bodi
	for (i=0;i<=n;i++) {
		for (j=0;postfix[i][j];j++)
			cout<<postfix[i][j];
		cout<<" ";
		}
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
//////////////////////////////////////////////////////

int oneop(char symbol,int &i,int  &ers)
{
	char t[10][10]={"sin(","cos(","tan(","cot(","arctan(","log10(",
	"log2(","abs(","exp(","[("};
	char temp[10];
	char t2[10];
	char h[100][10];
	int k=0;
	switch (symbol) {
	case 's':
	case 'c':
	case 't':
	case 'a':
	case 'l':
	case '[':
	case 'e':
		while (infix[i]!='(') {
			temp[k++]=infix[i];
			i++;
		}
		temp[k]='(';
		temp[k+1]='\0';
		for(int i1=0;i1<10;i1++)
		if(!strcmp(t[i1],temp))
		      ers =i1;
		for(i1=0;i1<10;i1++)
		if(!strcmp(t[i1],temp))  {
		    i--;
			return 1;
		}//end of if
	}//end of switch
	return 0;
}
/////////////////////////////////////////////////////
int error()
{
	char temp[46]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d',
	'e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u'
	,'v','w','x','y','z','+','-','*','/','^','[',']','(',')','.'};
	char op2[6]={'/','*','+','-','^'};
	char ch[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n'
	,'o','p','q','r','s','t','u','v','w','x','y','z'};
	char num[10]={'0','1','2','3','4','5','6','7','8','9'};
	char tavabe[10][10]={"sin","cos","tan","cot","arctan","log10",
	"log2","abs","exp","["};
	int sw=0,i,j;
	for (i=0;i<strlen(infix);i++)
	{
		sw=0;
		for (j=0;j<46;j++)
			if (infix[i]==temp[j])
				sw=1;
		if (!sw)  {
			cout<<"ERROR!";
			getch();
			return 0;
		}
	}
	if (infix[0]=='*' || infix[0]=='/' || infix[0]=='+')
	{
		cout<<"ERROR!";
		getch();
		return 0;
	}
	for (i=0;i<strlen(infix);i++)
	{
		for (j=0;j<6;j++)
			if (infix[i]==op2[j])
			{
				sw=0;
				for (int k=0;k<6;k++)
				if (infix[i+1]==op2[k] || infix[i-1]==op2[k])
					sw=1;
				if (sw) {
					cout<<"ERROR!";
					getch();
					return 0;
				}
			}
	}
	for (i=0;i<strlen(infix);i++)
	{
		for (j=0;j<26;j++)
			if (infix[i]==ch[j])
			{
				sw=0;
				for (int k=0;k<10;k++)
				if (infix[i+1]==num[k] || infix[i-1]==num[k])
					sw=1;
				if (sw) {
					cout<<"ERROR!";
					getch();
					return 0;
				}
			}
	}
	for (i=0;i<strlen(infix);i++)
	{
		if (infix[i]>='a' && infix[i]<='z')
		{
			while(
		for (j=0;j<10;j++)
			if (strcmp
	return 1;
}
/////////////////////////////////////////////////////
int convert()
{
	int i=0,j=-1,k=0,sum;
	int ers;
	stack s;
	char symbol,topsymbol;
	while (infix[i])
	{
		symbol=infix[i];
		if(variable(symbol,i,j));
		else if(oneop(symbol,i,ers))
		{
		switch(ers)
		{
		    case 0:
		    s.push('s');
		    break;
		    case 1:
		    s.push('c');
		    break;
		    case 2:
		    s.push('t');
		    break;
		    case 3:
		    s.push('k');
		    break;
		    case 4:
		    s.push('a');
		    break;
		    case 5:
		    s.push('l');
		    break;
		    case 6:
		    s.push('0');
		    break;
		    case 7:
		    s.push('b');
		    break;
		    case 8:
		    s.push('e');
		    break;
		    case 9:
		    s.push('[');
		    break;
		  }// s.push(symbol);
		}
		else if (operand(symbol,i,j));
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
		else if (symbol!=']'){
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
	char op[16]={'(','+','-','*','/','^',
	's','c','t','k','a','l','o','b','e','['};
	int iop [16]={0,1,1,2,2,3,4,4,4,4,4,4,4,4,4,4};
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
	char t[9][10]={"sin","cos","tan","cot","arctan","log10","log2"
	,"abs","exp"};
	int k=0,sw=0,z=i,p=i,i1;
	static int num;
	char temp[20];
	strcpy(temp,'\0');
	j++;
	if ((symbol>='a') && (symbol<='z') || (symbol>='A') && (symbol<='Z'))
	{
		while ((infix[p]>='a') && (infix[p]<='z') || (infix[p]>='A') && (infix[p]<='Z'))
		{
			temp[k++]=infix[p];
		       p++;
		}
		p--;
	if (infix[p+1]!='(')
		sw=1;
	if(z!=0)
	if (infix[z-1]!=')')
		sw=1;
	temp[k]='\0';
	for(i1=0;i1<10;i1++)
	if((!strcmp(t[i1],temp)) && (temp[0]!='\0'))
		sw=0;
	for (i1=0;i1<=inc;i1++)
		if (!strcmp(v[i1],temp))
			sw=2;
	}
       if(sw==1)
       {
	strcpy(v[++inc],temp);
	cout<<"\nEnter your variable "<<temp<<":";
	cin>>num;
	itoa(num,temp,10);
	strcpy(postfix[j++],temp);
	i=p;
	return 1;
	}
	if (sw==2) {
	itoa(num,temp,10);
	strcpy(postfix[j++],temp);
	i=p;
	return 1;
	}
	j--;
	return 0;
}
//////////////////////////////////
int operand(char symbol,int &i,int &j)
{
	int k=0;
	j++;
	if (symbol>='0' && symbol<='9')  {
		while (infix[i]>='0' && infix[i]<='9' || infix[i]=='.')
		{
			postfix[j][k++]=infix[i];
			i++;
		}
		i--;
		return 1;
	}
	j--;
	return 0;
}