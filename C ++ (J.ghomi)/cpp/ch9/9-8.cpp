#include <fstream.h>
#include <iostream.h>
#include <conio.h>
int main()
{
   clrscr();
   ifstream in("test");
      if(!in) {
      cout << "File cnnot open.";
      getch();
      return 1;
   }
   /* ignore up to 10 char or first space found.*/
   in.ignore(10, ' ');
   char c;
   while(in) {
       in.get(c);
       if (in)
	    cout << c;
   }
   in.close();
   getch();
   return 0;
}

