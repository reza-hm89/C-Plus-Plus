#include <iostream.h>
#include <conio.h>
#define SIZE 3
class sample{
     int x;
  public:
     sample() { x = 0; }
     sample(int y) { x = y; }
     int getx() { return x; }
};
//******************
int main()
{
   clrscr();
   sample ob[SIZE] = {5, 10, 15};
   sample *p;
   int i;
   p = ob; //get start of array
   for (i = 0; i < SIZE; i ++) {
       cout << "  ob[" << i << "]=" << p -> getx();
       p ++;
   }
   getch();
   return 0;
}

