#include <iostream.h>
#include <conio.h>
class myClass {
    int a, b;
  public:
    //automatic inline
    void init(int i, int j) {a = i; b = j;}
    void show() { cout << "a=" << a << " , b=" << b;}
    void init1(int i, int j);
};
inline void myClass::init1(int i, int j)
{
   a = i;
   b = j;
}
//***************
int main()
{
  myClass x;
  clrscr();
  x.init(10, 20);
  cout << "\nInitialization in init function:";
  x.show();
  x.init1(30, 40);
  cout << "\nInitialization in init1 function:";
  x.show();
  getch();
  return 0;
}
