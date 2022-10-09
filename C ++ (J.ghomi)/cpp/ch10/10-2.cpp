#include <iostream.h>
#include <conio.h>
class base {
      int i, j;
   public:
      void set(int a, int b) {i = a; j = b;}
      void show() { cout << "i = " << i << ", j =  " << j << "\n";}
};
//*public elements of base are private in derived
class derived : private base {
     int k;
  public:
     derived(int x) { k = x;}
     void showK() { cout << "k = " << k << "\n"; }
};
//***************
int main()
{
  clrscr();
  derived ob(3);
  ob.set(1, 2);  //can not access memeber of base
  ob.show();     //can not access member of base
  ob.showK();    //uses member of derived class
  getch();
  return 0;
}
