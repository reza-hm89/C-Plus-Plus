#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
ostream &bell(ostream &output) { return output << '\a'; }
ostream &ret (ostream &output) { return output << '\r'; }
ostream &tab(ostream &output) { return output << '\t'; }
ostream &endline(ostream &output)
{
   return output << '\n' << flush;
}
//*****************
int main()
{
   clrscr();
   cout << "Testing the tab manipulator:"  << endline
	<< 'a' << tab << 'b' << tab << 'c' << endline
	<<  "Testing the ret and bel manipulators:"
	<< endline << ".............";
   cout << bell;
   cout << ret << "-----" << endline;
   getch();
   return 0;
}


