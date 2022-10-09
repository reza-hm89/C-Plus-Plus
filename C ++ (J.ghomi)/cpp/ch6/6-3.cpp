#include <iostream.h>
#include <conio.h>
class employee {
   int hour;
   int hp;
   char name[21];
   long int salary;
public:
   void input();
   void calculate();
   void print();
};
//*********************
void employee::input()
{
   cout << "Enter name, hours, hourpay:";
   cin >> name >> hour >> hp;
}
//*********************
void employee::calculate()
{
   salary = (long)hour * hp;
}
//***********************
void employee::print()
{
   cout << "Name is:" << name << endl;
   cout << "Hour is:" << hour << endl;
   cout << "Hourpay is:" << hp << endl;
   cout << "Salary is:" << salary;
}
//************************
int main()
{
   clrscr();
   employee em;
   em.input();
   em.calculate();
   em.print();
   getch();
   return 0;
}

