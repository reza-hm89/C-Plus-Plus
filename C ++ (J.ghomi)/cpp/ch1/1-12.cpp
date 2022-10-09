#define PI 3.14
#include <iostream.h>
#include <conio.h>
int main()
{
   int r;
   float area, p;
   cout << "Enter the radius : ";
   cin >> r;
   area = PI * r * r;
   p = 2 * PI * r;
   cout << "area = " << area << " perime = " << p;
   getch();
   return 0;
}
