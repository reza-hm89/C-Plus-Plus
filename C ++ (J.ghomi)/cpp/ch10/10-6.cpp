#include <iostream.h>
#include <conio.h>
class base {
   public:
      base()  { cout << "Constructing base \n"; }
      ~base() { cout << "Destructing base \n";  }
};
//***************
class derived : public base {
   public:
      derived()  { cout << "Costructing derived\n"; }
      ~derived() { cout << "Destructing derived\n"; }
};
//**************
int main()
{
   clrscr();
   derived ob;
   getch();
   return 0;
}

