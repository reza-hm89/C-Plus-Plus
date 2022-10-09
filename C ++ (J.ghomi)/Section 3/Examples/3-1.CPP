#include<iostream.h>
#include<conio.h>
void time(void);
void main()
{
	clrscr();
	time();
	getch();
}
void time()
{
	int h,m,s;
	long int time;
	cout<<"Enter your time (hours:minutes:seconds): ";
	cin>>h>>m>>s;
	time=(long int)(h*60+m)*60+s;
	cout<<"Time is "<<time<<" seconds";
}