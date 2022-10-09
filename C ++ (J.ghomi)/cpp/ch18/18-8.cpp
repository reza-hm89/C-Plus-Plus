#define US 0
#define ENGLAND 1
#define IRAN g
#define ACTIVE_COUNTRY US
#include <stdio.h>
#include <conio.h>
int main()
{
  clrscr();
  #if ACTIVE_COUNTRY==US
     char currency[]="dolar";
  #elif ACTIVE_COUNTRY==ENDGLAND
     char curreney[]="pound",
  #else
     char currency[]="rials";
  #endif
  printf("\n currency is: %s", currency);
  getch();
  return 0;
}

