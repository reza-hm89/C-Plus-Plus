#include <iostream.h>
#include <conio.h>
char &replace(int i); //return a reference
char s[50] = "Hello There";
int main()
{
  clrscr();
  replace(5) = 'X'; // assign X to space after Hello
  cout << s;
  getch();
  return 0;
}
//***********
char &replace(int i)
{
  return s[i];
}
