#include <iostream.h>
#include <conio.h>
int main()
{
  int done = 1;
  char ch;
  clrscr();
  while(done){
    cout << "\nEnter a character:";
    cin >> ch;
    if(ch == '&'){
       done = 0;
       continue;
    }// end of if
    cout << "You typed char " << ch ;
    cout << ", next char is:" << (ch + 1) ;
  }// end of while
  getch();
  return 0;
}