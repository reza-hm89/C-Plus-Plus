#include <iostream.h>
#include <conio.h>
class shared {
   public:
     static int a;
};
//**************
int shared ::a;  //define a
int main()
{
   //initialize a, before creating  any objects
   shared::a = 99;
   clrscr();
   cout << "This is initial value of a: " << shared::a;
   cout << endl;
   shared x;
   cout << "This is x.a :" << x.a;
   getch();
   return 0;
}




















