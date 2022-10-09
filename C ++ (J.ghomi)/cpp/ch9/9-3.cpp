#include <fstream.h>
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
int main(int argc, char *argv[])
{
   char ch;
   int pc, po, bc, bo ;
   pc = po = bc = bo = 0;
   clrscr();
   if(argc < 2) {
     cout << "usage : program  filename.";
     getch();
     exit(0);
   }
   ifstream  fp(argv[1]);
   if(!fp) {
       cout << "Cannot open file.";
       getch();
       exit(0);
   }
   fp.get(ch);
   while(!fp.eof()) {
       switch(ch) {
	 case ')':
	    pc ++; break;
	 case '(':
	    po ++; break;
	 case '}':
	    bc ++; break;
	 case '{' :
	    bo ++;
       }
       fp.get(ch);
   }
   fp.close();
   cout << "pc = " << pc << ", po = " << po
        << ", bc = " << bc << ", bo = " << bo;
   getch();
   return 0;
}
