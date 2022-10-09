#include <iostream.h>
#include <string.h>
#include <conio.h>
const int in = 1;
const int checked_out = 0;
class book {
   char author[40];
   char title[40];
   int status;
 public:
   book(char *n, char *t, int s); // parameterized costructer
   int get_status() {return status;}
   void set_status(int s) { status = s;}
   void show();
};
//***********
book::book(char *n, char *t, int s)
{
  strcpy(author, n);
  strcpy(title, t);
  status = s;
}
//************
void book::show()
{
  cout << title << " by " << author << " is ";
  if (status == in)
      cout << "in.\n";
  else
      cout << "out.\n";
}
//****************
int main()
{
  book b1("Ghomi", "pascal", in);
  book b2("Ghomi", "java", checked_out);
  clrscr();
  b1.show();
  b2.show();
  getch();
  return 0;
}



