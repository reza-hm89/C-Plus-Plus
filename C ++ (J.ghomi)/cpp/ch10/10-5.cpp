#include <iostream.h>
#include <conio.h>
class base {
   protected:
      int i, j; //private to base, but accible by derived
   public:
      void set(int a, int b) {i = a; j = b;}
      void show() { cout << "i = " << i << ", j =  " << j << "\n";}
};
//now all elements of base are private in derived1.
class derived1 : private base {
     int k;
  public:
     //this is legal because i and j are private to derived1
     void setK() { k = i * j;}
     void showK() { cout << "k = " << k << "\n"; }
};
//access to i, j, set(), and show() not inherited.
class derived2 : public derived1 {
     int m;
  public:
     //illegal becaus i, j are private to derived1
     void setM() { m = i - j;}  //error
     void showM() { cout << "m = " << m << "\n"; }
};
//******************
int main()
{
  clrscr();
  derived1 ob1;
  derived2 ob2;
  ob1.set(2, 3);  //error, can't use set, because set() is private
  ob1.show();     //error can't use show
  ob2.set(3, 4);  //error, can't use set()
  ob2.show();     //error, can't use show()
  getch();
  return 0;
}
