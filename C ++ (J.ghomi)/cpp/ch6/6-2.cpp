#include <conio.h>
#include <iostream.h>

class circle{
	int radius;
     public:
	void get_radius();
	void print();
};
//**************
void  circle::get_radius()
  {
     cout << "Enter radius:";
     cin >> radius;
  }
//******************
void circle::print()
{
   float s;
   s = radius * radius * 3.14;
   cout << "Area = " << s;
}
//***************
int main()
{
    clrscr();
    circle cVar;
    cVar.get_radius();
    cVar.print();
    getch();
    return 0;
}


