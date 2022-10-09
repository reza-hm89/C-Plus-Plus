#include <iostream.h>
#include <conio.h>
class store {
      int a;
    public:
      store(int j) { a = j;}
      int getA() { return a;}
} ;
//***********
int main()
{
  store ob = 99; //pass 99 to j
  clrscr();
  cout << "j = " << ob.getA(); // outputs 99
  getch();
  return 0;
}


