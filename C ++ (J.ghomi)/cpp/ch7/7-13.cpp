#include <iostream.h>
#include <conio.h>
class  sample {
    public:
      int x;
      sample(int y) { x = y; }
};
//*****************
int main()
{
  sample ob = 10;
  int *p;
  clrscr();
  p = &ob.x; // get address of x
  cout << " x = " << *p;
  getch();
  return 0;
}
