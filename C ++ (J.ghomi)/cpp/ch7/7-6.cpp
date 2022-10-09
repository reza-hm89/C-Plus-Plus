#include <iostream.h>
#include <conio.h>
class static_type {
    static int i;
 public:
    static void init(int x) { i = x; }
    void show() { cout << "i = " << i;}
};

int static_type::i;  //define i
int main()
{
  clrscr();
  //init static data before object creation
  static_type::init(100);
  static_type x;
  x.show(); //display 100
  getch();
  return 0;
}


