#include<iostream.h>
#include<conio.h>

void Border();
void Input();
void Draw(int[],int);
//=====================================
void main()
{
	clrscr();
	Input();
	getch();
}
//=====================================
void Input()
{
	int n,code[20];
	cprintf("Enter Number of Code: ");
	do {
		gotoxy(23,1);
		cout<<"              ";
		gotoxy(23,1);
		cin>>n;
		if (n<1 || n>15)
		{
			gotoxy(1,2);
			cout<<"The Number Is Wrong!!! , Enter Between (1..15)";
		}
	} while (n<1 || n>15);
	cout<<"\nEnter Codes Between (1..44):\n";
	for (int i=0;i<n;i++)
	{
		cout<<"\nEnter Code "<<(i+1)<<" : ";
		cin>>code[i];
	}
	Border();
	Draw(code,n);
}
//=====================================
void Draw(int code[],int n)
{
	int i,j,Row=5;
	for (i=0;i<n;i++)
	{
		textcolor(BLACK+i+1);
		gotoxy(Row,48);
		cprintf("%d",code[i]);
		for (j=46;j>46-code[i];j--)
		{
			gotoxy(Row,j);
			cprintf("Û");
		}
		Row+=5;
	}
}
//=====================================
void Border()
{
	int i;
	textbackground(BLACK);
	textcolor(WHITE);
	clrscr();
	for (i=1;i<=80;i++)
	{
		gotoxy(i,1);
		cprintf("Û");
		gotoxy(i,49);
		cprintf("Û");//219
	}
	for (i=1;i<50;i++)
	{
		gotoxy(1,i);
		cprintf("Û");
		gotoxy(80,i);
		cprintf("Û");
	}
	for (i=3;i<=78;i++)
	{
		gotoxy(i,47);
		cprintf("Á");
	}
	for (i=3;i<=47;i++)
	{
		gotoxy(3,i);
		cprintf("Ã");
	}
	gotoxy(3,47);
	cprintf("À");
}