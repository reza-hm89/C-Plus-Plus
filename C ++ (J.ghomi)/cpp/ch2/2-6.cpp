#include <iostream.h>
#include <conio.h>
#define NUM 6
int main()
{
  int count;
  float sum, x;
  clrscr();
  for(sum = 0, x = 1.0, count = 1; count <= NUM; count ++, x *= 2)
  {
    sum += 1 / x;
    cout << "sum = " << sum  << "  when count = " << count << endl;
  }
  getch();
  return 0;
}
