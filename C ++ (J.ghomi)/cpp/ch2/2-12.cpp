#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
  int magic, guess;
  char ans = 'y';
  magic = rand();
  do {
      clrscr();
      cout << "\n Guess the the magic number:";
      cin >> guess;
      if(guess == magic) {
     	  cout << "\n***** right *****";
	     cout << "\n %d is the magic number." << magic;
	     getch();
	     ans = 'n'; //exit from while
      } // end of if
      else {
	      cout << "***** wrong ******";
	      if(guess > magic)
	          cout << "\n your guess is too high.";
	      else
	          cout << "\n your guess is too low.";
	      cout << "\n Do you want to continue?(y/n):";
	      cin >> ans;
      }// end of else
  } while(ans == 'y');
  return 0;
}
