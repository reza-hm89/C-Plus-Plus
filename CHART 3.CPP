#include<iostream.h>
#include<conio.h>
void main ()
{
	clrscr();
	int i,n,code;
	for (i=10;i<=70;i++)
	{
		gotoxy(i,40);
		cout<<"-";
	}
	gotoxy(1,1);
	cout<<"Enter N: ";
	cin>>n;
	int k=8;
	for (i=1;i<=n;i++)
	{
		gotoxy(1,2);
		cout<<"            ";
		gotoxy(1,2);
		cout<<"Enter Code: ";
		cin>>code;
		k+=4;
		for (int j=40;j>40-code;j--)
		{
			gotoxy(k,j);
			cout<<"|";
		}
	}
	getch();
	return ;
}