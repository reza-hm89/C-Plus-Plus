#include<conio.h>
#include<iostream.h>
void main()
{
	int h,d,m,mp,hp;
	clrscr();
	cout<<"Enter hour & Min & Time:";
	cin>>h>>m>>d;
	hp=(h+(m+d)/60)%24;
	mp=(m+d)%60;
	cout<<hp<<"\t"<<mp;
	getch();
}