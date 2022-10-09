#include <iostream.h>
#include <conio.h>
class base {
   protected:
      int i, j; //private to base, but accible by derived
   public:
      void set(int a, int b) {i = a; j = b;}
      void show() { cout << "i = " << i << ", j =  " << j << "\n";}
};
//i, j inherited as protected.
class derived1 : public base {
     int k;
  public:
     //derived may access base's i and j
     void setK() { k = i * j;}
     void showK() { cout << "k = " << k << "\n"; }
};
//*i, j inherited indirectly throgh derived1***
class derived2 : public derived1 {
     int m;
  public:
     //derived2 may access base's i and j
     void setM() { m = i - j;}
     void showM() { cout << "m = " << m << "\n"; }
};
//******************
int main()
{
  clrscr();
  derived1 ob1;
  derived2 ob2;
  ob1.set(2, 3);  //ok, known to derived
  ob1.show();
  ob1.setK();
  ob1.showK();
  ob2.set(3, 4);
  ob2.show();
  ob2.setK();
  ob2.setM();
  ob2.showK();
  ob2.showM();
  getch();
  return 0;
}
