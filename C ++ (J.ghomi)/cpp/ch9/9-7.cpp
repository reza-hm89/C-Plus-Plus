#include <fstream.h>
#include <iostream.h>
#include <conio.h>
int main( int argc, char *argv[])
{
  if (argc < 2 ) {
     cout << "Usage : program <filename>\n";
     getch();
     return 1;
  }
  ifstream in(argv[1]);
  if(!in) {
     cout << "File cnnot open.";
     getch();
     return 1;
  }
  char str[255];
  in.getline(str, 255);  //delimiter default to '\n'
  while(!in.eof()) {
       cout << str << endl;
       in.getline(str, 255);  //delimiter default to '\n'
  }
  in.close();
  getch();
  return 0;
}



