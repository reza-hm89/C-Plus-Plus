#include <iostream.h>
#include <conio.h>
class base {
  public:
     int i;
};
//****************
//derived1 inherits base************
class derived1: public base {
  public:
    int j;
};
//*****************
//derived2 inherits base
class derived2 : public base {
  public:
     int k;
};
//derived3 inherits oth derived and derived
//this meeas that there are two copies of base
//in derived3
class derived3 : public derived1, public derived2 {
    public:
       int sum;
};
//**************
int main()
{
  clrscr();
  derived3 ob;
  ob.derived1::i = 100;  //use derived1's i
  ob.derived2::i = 200;
  ob.j = 20;
  ob.k = 30;
  ob.sum = ob.derived1::i + ob.j + ob.k;
  cout << "ob.derived1 = " << ob.derived1::i << " \n";
  cout << "ob.derived2 = " << ob.derived2::i << " \n";
  cout << "ob.j = " << ob.j << ", ob.k =  " << ob.k << "\n";
  cout << "ob.sum =" << ob.sum;
  getch();
  return 0;
}





