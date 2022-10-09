#include <iostream.h>
#include <conio.h>
class base {
   protected:
      int i, j; //private to base, but accible by derived
   public:
      void set(int a, int b) {i = a; j = b;}
      void show() { cout << "i = " << i << ", j =  " << j << "\n";}
};
//*public elements of base are private in derived
class derived : public base {
     int k;
  public:
     //derived may access base's i and j
     void setK() { k = i * j;}
     void showK() { cout << "k = " << k << "\n"; }
};
//***************
int main()
{
  clrscr();
  derived ob;
  ob.set(2, 3);  //ok, known to derived
  ob.show();     //ok, known to derived
  ob.setK();
  ob.showK();
  getch();
  return 0;
}
