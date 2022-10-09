#include <iostream.h>
#include <conio.h>
class testClass {
   int id;
 public:
   int i;
   testClass(int i);
   ~testClass();
   void neg(testClass &ob) {ob.i = -ob.i ;} // no temporary created
};
//*************
testClass::testClass(int num)
{
  cout << "Constructing " << num << "\n";
  id = num;
}
//***************
testClass::~testClass()
{
  cout << "Destructing " << id << "\n";
}
//*******************
int main()
{
  testClass ob(1);
  ob.i = 10;
  clrscr();
  ob.neg(ob);
  cout << "i = " << ob.i << "\n";
  getch();
  return 0;
}

