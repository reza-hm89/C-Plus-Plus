#include<conio.h>
#include<iostream.h>
class	area
{
	public:
		void read();
		void show();
	private:
		float r;
};
void area::read()
{
	cout<<"Enter r: ";
	cin>>r;
}
void area::show()
{
	float s;
	s=r*r*3.14;
	cout<<"Area: "<<s;
}
void main()
{
	clrscr();
	area ar;
	ar.read();
	ar.show();
	getch();
}

