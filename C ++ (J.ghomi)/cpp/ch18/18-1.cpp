#include <stdio.h>
#include <conio.h>
#define PROGRAM main()
#define FLOAT   float
#define WHILE while(
#define DO    )
#define BEGIN {
#define END   }
#define FORMATOUT "the sum is: %6.2f\n"
#define FORMATIN "%f"
#define MESSAGE  printf("enter numbers(negative to end):");
PROGRAM
 BEGIN
  FLOAT data, sum=0.0;
  clrscr();
  MESSAGE
  scanf(FORMATIN, &data);
  WHILE data >= 0.0 DO
  BEGIN
    sum += data;
    scanf(FORMATIN, &data);
  END
  printf(FORMATOUT, sum);
  getch();
  return 0;
END


