#include <iostream.h>
#include <conio.h>
class base {
    public:
     virtual void vFunc() {
	  cout << "This is a base's vFunc().\n";
     }
};
//*********
class derived1 : public base {
   public:
     void vfunc() {
	     cout << "This is a derived1's vFunc().\n";
     }
};
//********************
class derived2 : public base {
   public:
      void vfunc() {
	      cout << "This is a derived2's vFunc().\n";
      }
};
//**use a base class reference parameter*******
void f(base &r) {
      r.vFunc();
}
//********************
int main()
{
  clrscr();
  base b;
  derived1 d1;
  derived2 d2;
  f(b);     //pass a base object to f()
  f(d1);    //pass a derived1 object to f()
  f(d2);     //pass a derived2 object to f()
  getch();
  return 0;
}
