#include <iostream.h>
#include <conio.h>
class myClass {
   public:
      int who;
      myClass(int id);
      ~myClass();
} glob_ob1(1), glob_ob2(2);
//***************
myClass::myClass(int id)
{
  cout << "Initializing " << id << "\n";
  who = id;
}
//****************
myClass::~myClass()
{
  cout << "Destructing " << who << "\n";
}
//****************
int main()
{
  myClass localob1_ob1(3);
  clrscr();
  cout << "This will not be first line displayed.\n";
  myClass local_ob2(4);
  getch();
  return 0;
}

