#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
template <class type1, class type2> class  myClass
{
   type1 i;
   type2 j;
 public:
   myClass(type1 a, type2 b)
   {
     i = a;
     j = b;
   }
   void show() {
     cout << i << "   " << j << "\n";
   }
} ;
//**************
int main()
{
  clrscr();
  myClass<int, double> ob1(10, 0.23);
  myClass<char, char *> ob2('x', "Templates add power.");
  ob1.show();  //show int, double
  ob2.show();  //show char, char *
  getch();
  return 0;
}

