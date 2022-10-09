#include<conio.h>
#include<iostream.h>
class	employee
{
	public:
		void read();
		void calculate();
		void show();
	private:
		char name[20];
		int h,mon,s;
};
void employee::read()
{
	cout<<"Enter name,hour,dastmozd: ";
	cin>>name;
	cin>>h>>mon;
}
void  employee::calculate()
{
	s=h*mon;
}
void employee::show()
{
	cout<<"name: "<<name<<endl;
	cout<<"salary: "<<s;
}
void main()
{
	clrscr();
	employee emp;
	emp.read();
	emp.calculate();
	emp.show();
	getch();
}

