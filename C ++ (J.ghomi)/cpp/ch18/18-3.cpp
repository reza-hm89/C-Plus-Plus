#include <stdio.h>
#include <conio.h>
#define PI 3.14
#define AREA(r)  r * r * PI
int main()
{
  float r, s;
  clrscr();
  printf("enter radius:");
  scanf("%f", &r);
  s = AREA(r);
  printf("area is :%6.2f", s);
  getch();
  return 0;
}
