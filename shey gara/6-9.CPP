#include<iostream.h>
#include<conio.h>
#include<dos.h>
class	myclass
{
	public:
		int who;
		myclass(int id);
		~myclass();
}glob_ob1(1),glob_ob2(2);
//================
myclass::myclass(int id)
{
	cout<<"initializing "<<id<<"\n";
	delay(1000);
	who=id;
}
myclass::~myclass()
{
	cout<<"Destructing "<<who<<"\n";
}
void main()
{
	myclass local_ob1(3);
	clrscr();
	cout<<"this will not be first line displayed.\n";
	myclass local_ob2(4);
	getch();
}
