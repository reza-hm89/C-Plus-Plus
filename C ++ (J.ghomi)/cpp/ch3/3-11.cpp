#include <iostream.h>
#include <conio.h>
int areaCube(int length, int width = 25, int height = 1);
int main()
{
  int area, length = 100, width = 50, height = 2;
  clrscr();
  area = areaCube(length, width, height);
  cout << "First time area equals: " << area << endl;
  area = areaCube(length, width);
  cout << "Second time area equals: " << area << endl;
  area = areaCube(length);
  cout << "Third time area equals: " << area;
  getch();
  return 0;
}
/**************************/
int areaCube(int length, int width, int height)
{
   return (length * width * height);
}

