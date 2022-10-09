#include <iostream.h>
#include <conio.h>
class counter {
    public:
       static int count;
       counter() { count ++;}
       ~counter() { count --;}
};
int counter::count;
void f();
int main()
{
  counter ob1;
  clrscr();
  cout << "Obgects in existence: " << counter::count <<endl;
  counter ob2;
  cout << "Obgects in existence: " << counter::count <<endl;
  f();
  cout << "Obgects in existence: " << counter::count <<endl;
  getch();
  return 0;
}
//****************
void f()
{
  counter temp;
  cout << "In f() obgects in existence: " << counter::count <<endl;
  // temp is destroyed when f() returns
}
