#include <iostream.h>
#include <conio.h>
#include <string.h>
istream &getPass(istream &stream)
{
  cout << '\a';   //sound bell
  cout << "Enter password: ";
  return stream;
}
//************
int main()
{
  char pw[21];
  clrscr();
  do {
     cin >> getPass >> pw;
  } while(strcmp(pw, "password"));
  cout << "Logon complete.\n";
  getch();
  return 0;
}

