#include <iostream.h>
#include <conio.h>
class base {
  public:
     int i;
};
//****************
//derived1 inherits base as virtual*******
class derived1: virtual public base {
  public:
    int j;
};
//*****************
//derived2 inherits base as virtual
class derived2 : virtual public base {
  public:
     int k;
};
//derived3 inherits both derived1 and derived2
//this time, there is only one  copy of base class
class derived3 : public derived1, public derived2 {
    public:
       int sum;
};
//**************
int main()
{
  clrscr();
  derived3 ob;
  ob.i = 100;
  ob.j = 20;
  ob.k = 30;
  ob.sum = ob.i + ob.j + ob.k;
  cout << "ob.i = " << ob.i << " \n";
  cout << "ob.j = " << ob.j << ", ob.k =  " << ob.k << "\n";
  cout << "ob.sum =" << ob.sum;
  getch();
  return 0;
}





