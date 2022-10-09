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
     void vFunc() {
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
//***************
int main()
{
  clrscr();
  base *p, b;
  derived1 d1;
  derived2 d2;
  //point to base
  p = &b;
  p -> vFunc();  //access base's vfunc()
  //point to derived1
  p = &d1;
  p -> vFunc(); //access derived1's vfunc()
  //point to derived2
  p = &d2;
  p -> vFunc(); //access derived2's vfunc()
  getch();
  return 0;
}
