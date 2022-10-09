#include <iostream.h>
#include <conio.h>
void upper(char []);
int main()
{
  char s[21];
  clrscr();
  cout << "Enter a string:";
  cin.get(s, 20);
  upper(s);
  cout << "Result is:" << s;
  getch();
  return 0;
}
//***********************
void upper(char s[])
{
  int i;
  for(i = 0; s[i]; i++)
      if(s[i] >= 'a' && s[i] <= 'z')
	 s[i] -= 32;
}
