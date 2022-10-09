#include <iostream.h>
#include <conio.h>
class myClass {
    int i;
  public:
    myClass(int n);
    ~myClass();
    void set_i(int n) { i = n;}
    int get_i() { return i; }
};
//***************
myClass::myClass(int n)
{
  i = n;
  cout << "Constructing " << i << endl;
}
//**************8
myClass::~myClass()
{
  cout << "Destroying " << i << endl;
}
//****************
void f(myClass ob);

int main()
{
  myClass ob1(1);
  clrscr();
  f(ob1);
  cout << "This is i in main :" << ob1.get_i() << endl;
  getch();
  return 0;
}
//**************
void f(myClass ob)
{
  ob.set_i(2);
  cout << "This is local i :" << ob.get_i() << endl;
}

