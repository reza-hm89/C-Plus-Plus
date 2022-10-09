#include <iostream.h>
#include <conio.h>
int main()
{
  int charCount = 0, wordCount = 0;
  char ch;
  clrscr();
  cout << "\nEnter a statement(and press EMTER):";
  while((ch = getche()) != '\r'){
    charCount ++;
    if(ch == ' ')
	wordCount ++;
  }//end of while
  cout << "\nChar count=" << charCount << " , Word count=" << wordCount + 1;
  getch();
  return 0;
}


