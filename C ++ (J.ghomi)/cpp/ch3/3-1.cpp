#include <iostream.h>
#include <conio.h>
void convert(void);
int main()
    {
     convert() ;
     getch();
     return 0;
    }
//**************************
void convert(void)
{
  int hours, minutes, second;
  long int time ;
  clrscr();
  cout << "enter time to be convert:hour, minutes, second:" ;
  cin >> hours >> minutes >> second ;
  time = (long int) (60 * hours + minutes) * 60 + second ;
  cout << "time is " << time << " seconds." ;
}


