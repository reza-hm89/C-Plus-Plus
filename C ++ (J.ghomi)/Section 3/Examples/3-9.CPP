#include<iostream.h>
#include<conio.h>
inline int max(int a,int b)
{
	return a>b ? a:b;
}
void main()
{
	clrscr();
	cout<<"Max of 10,20 is: "<<max(10,20)<<endl;
	cout<<"Max of 99,88 is: "<<max(99,88);
	getch();
}