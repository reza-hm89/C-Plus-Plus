#include<iostream.h>
#include<conio.h>
void main()
{
	int flag=1,a,b;
	char op;
	clrscr();
	while (flag)
	{
	clrscr();
	cout<<"Enter two Numbers: ";
	cin>>a>>b;
	cout<<"Enter Operator: ";
	cin>>op;
	cout<<"\n";
	switch (op)
	{
		case '+': cout<<a<<" + "<<b<<" = "<<a+b;
		break;
		case '-': cout<<a<<" - "<<b<<" = "<<a-b;
		break;
		case '*': cout<<a<<" * "<<b<<" = "<<a*b;
		break;
		case '\\':
		case '/': cout<<a<<" / "<<b<<" = "<<(float)a/b;
		break;
		default : cout<<"Operator is illigal";
		flag=0;
	}
	getch();
	}
	getch();
}