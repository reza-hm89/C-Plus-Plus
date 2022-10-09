#include <iostream.h>
#include <conio.h>
int main()
{
   int x, y, m;
   float ave;
   cout << "Enter three number : ";
   cin >> x >> y >> m;
   ave = (float) (x + y + m) / 3;
   cout << "ave = " << ave;
   getch();
   return 0;
}
