#include <stdio.h>
#include <conio.h>
#define NUMLINE  5
#define BLANK   ' '
#define ASTRISK '*'
#define NEWLINE '\n'
int main()
{
  int l, le, s ;
  l = 1;
  clrscr();
  while (l <= NUMLINE) {
      le = 1 ;
      while (le++ <= NUMLINE - l)
	 printf("%c", BLANK);
      s = 1;
      while(s++ <= 2 * l - 1)
	  printf("%c", ASTRISK);
      printf("%c", NEWLINE);
      l ++;
  }
  getch();
  return 0;
}
