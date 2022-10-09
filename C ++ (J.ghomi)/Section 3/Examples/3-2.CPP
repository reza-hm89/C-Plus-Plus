#include<iostream.h>
#include<conio.h>
void max(int,int,int);
void main()
{
	int a,b,c;
	clrscr();
	cout<<"Enter a,b,c: ";
	cin>>a>>b>>c;
	max(a,b,c);
	getch();
}
void max(int x,int y,int z)
{
	int max;
	max=(x>y) ? x:y;
	max=(z>max) ? z:max;
	cout<<"Max is "<<max;
}