#include <iostream.h>
#include <conio.h>
int square(int);
float square(float);
int main()
{
 int x = 10;
 float y = 5.5;
 clrscr();
 cout << square(x) << endl;
 cout << square(y) << endl;
 getch();
 return 0;
}
/******************/
float square(float f)
{
  cout << " In float function : " ;
  return f * f;
}
/**********************/
int square(int i)
{
  cout << " In int function : ";
  return i * i;
}
