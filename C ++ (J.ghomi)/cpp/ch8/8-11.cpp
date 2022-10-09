#include <iostream.h>
#include <conio.h>
class myClass {
   public:
     int x;
     myClass *operator ->() { return this; }
};
//***********
int main()
{
  clrscr();
  myClass ob ;
  ob -> x = 10; // same as ob.x
  cout << "ob.x=" << ob.x << ", ob-> x =" << ob -> x;
  getch();
  return 0;
}
