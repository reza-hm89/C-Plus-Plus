#include <iostream.h>
#include <conio.h>
class ar {
     int x;
     int y;
   public:
     ar (int i, int j) {x = i; y = j;}
     int  getX() { return x; }
     int  getY() { return y; }
};
//*****************
#define SIZE 5
int main()
{
  int i;
  ar ob[SIZE] = {
       ar(2, 4), ar( 6, 8), ar(10, 12), ar(14, 16), ar(18, 20)};
  int s = 0;
  clrscr();
  for(i = 0; i < SIZE; i ++) {
     s += ob[i].getX() + ob[i].getY();
  }
  cout << "Sum of " << SIZE << " elements is:" << s;
  getch();
  return 0;
}

