#include<iostream.h>
#include<conio.h>
#include<fstream.h>

struct stacknode
{
	char item;
	stacknode *next;
};

class Stack
{
	stacknode *top;
	public:
		Stack() { top=NULL; };
		char ShowTop()
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
		char Pop();
		void Push(char ch);

};
void Stack::Push(char ch)
{
	stacknode *p;
	p=new stacknode();
	p->item=ch;
	p->next=top;
	top=p;
}
char Stack::Pop()
{
	char x;
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
//=========================================
//        Public Variable

char infix[100],postfix[100];
char save[100];
//=========================================
void SaveToFile()
{
	char ch;
	int i=0,true;
	ofstream f;
	do
	{
	true=i=ch=0;
	save[0]=0;
	textattr(WHITE);
	gotoxy(24,9);
	cprintf("                                             ");
	gotoxy(24,9);
	do
	{
		gotoxy(24,9);

	} while(!kbhit());
	gotoxy(25,15);
	textbackground(1);
	textcolor(BLUE);
	cprintf("                            ");
	textbackground(0);
	textcolor(WHITE);
	gotoxy(24,9);
	while (i<60 && ch!=13)
	{
		ch=getche();
		save[i++]=ch;
	}
	save[i-1]=0;
	f.open(save);
	if (!f)
	{
		true=1;
		gotoxy(25,15);
		textbackground(BLUE);
		textcolor(RED+128);
		cprintf("Can not save to this address");
	}
	f<<postfix;
	} while (true);
}
//=========================================
void ShowPostfix()
{
	gotoxy(17,6);
	cprintf("%s",postfix);
}
//=========================================
void ConvertToPostfix()
{
	Stack s;
	int value1,value2,i,j,cnt=0;
	char ch;
	for (i=0;infix[i];i++)
	{
		if (infix[i]>='a' && infix[i]<='z')
			postfix[cnt++]=infix[i];
		else if (infix[i]=='(')
			s.Push(infix[i]);
		else if (infix[i]==')')
		{
			while (s.ShowTop()!='(')
				postfix[cnt++]=s.Pop();
			ch=s.Pop();//for pop '('
		}
		else
		{       value1=0;
			ch=0;
			if (!s.IsEmpty())
				ch=s.ShowTop();
			switch (ch)
			{
				case '+':  value1=1;
				break;
				case '-':  value1=1;
				break;
				case '*':  value1=2;
				break;
				case '/':  value1=2;
				break;
				case '^':  value1=3;
				break;
			}
			switch (infix[i])
			{
				case '+':  value2=1;
				break;
				case '-':  value2=1;
				break;
				case '*':  value2=2;
				break;
				case '/':  value2=2;
				break;
				case '^':  value2=3;
				break;
			}
			if (value2>value1)
				s.Push(infix[i]);
			else if (value2<=value1)
			{
				while (value2<=value1 && !s.IsEmpty())
				{
					postfix[cnt++]=s.Pop();
					ch=0;
					if (!s.IsEmpty())
						ch=s.ShowTop();
					switch (ch)
					{
					case '+':  value1=1;
					break;
					case '-':  value1=1;
					break;
					case '*':  value1=2;
					break;
					case '/':  value1=2;
					break;
					case '^':  value1=3;
					break;
					}
				}
				s.Push(infix[i]);
			}
		}

	}
	while (!s.IsEmpty())
		postfix[cnt++]=s.Pop();
	postfix[cnt]=0;
}
//=========================================
void InputInfix()
{
	char ch;
	int i=0;
	textattr(15);
	gotoxy(17,3);
	do
	{
		gotoxy(17,3);
		cprintf(" ");

	} while(!kbhit());
	gotoxy(17,3);
	while (i<60 && ch!=13)
	{
		ch=getche();
		infix[i++]=ch;
	}
	infix[i-1]=0;
	for (i=0;infix[i];i++)
	{
		if (infix[i]>='A' && infix[i]<='Z')
			infix[i]+=32;
	}
}
//=========================================
void Help()
{
	gotoxy(3,11);
	textcolor(RED);
	cprintf("Notice: Please write a correct form of infix sentence");
	textcolor(GREEN);
	gotoxy(3,20);
	cprintf("HELP: Please Write a infix sentence in Infix Textbox and Write ");
	gotoxy(9,21);
	cprintf("the address in Textbox to save postfix sentence");
	gotoxy(3,22);
	textcolor(LIGHTRED);
	cprintf("Example: c:\\postfix.txt");
}
//=========================================
void Menu()
{
	textmode(C80);
	textbackground(1);
	textcolor(WHITE);
	clrscr();
	int i;
	for (i=1;i<80;i++)
	{
		gotoxy(i,1);
		cprintf("л");
		gotoxy(i,25);
		cprintf("л");
	}
	for (i=1;i<25;i++)
	{
		gotoxy(1,i);
		cprintf("л");
		gotoxy(80,i);
		cprintf("л");
	}
	gotoxy(5,3);
	cprintf("Infix:");
	gotoxy(5,6);
	cprintf("Postfix:");
	gotoxy(5,9);
	cprintf("Adress for Save:");
	textcolor(0);
	gotoxy(16,3);
	cprintf("ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	gotoxy(16,6);
	cprintf("ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
	gotoxy(23,9);
	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллл");
}
//=========================================
void main()
{
	Menu();
	Help();
	InputInfix();
	ConvertToPostfix();
	ShowPostfix();
	SaveToFile();
	getch();
}