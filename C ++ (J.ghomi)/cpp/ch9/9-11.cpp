#include <iostream.h>
#include <fstream.h>
#include <conio.h>
#include <string.h>
class phoneBook {
    char name[21];
    char code[4];
    char num[7];
  public:
    phoneBook() { }
    phoneBook(char *n, char *c, char *nm)
    {
       strcpy(name, n);
       strcpy(code, c);
       strcpy(num, nm);
    }
    friend ostream &operator<<(ostream &stream, phoneBook ob);
    friend istream &operator>>(istream &stream, phoneBook &ob);
};
//*************
ostream &operator<<(ostream &stream, phoneBook ob)
{
   stream << ob.name << "  ";
   stream << "(" << ob.code << ")" << ob.num << '\n';
   return stream;
}
//*****************
istream &operator>>(istream &stream, phoneBook &ob)
{
   cout << "Enter name:";
   stream >> ob.name;
   cout << "Enter area code:";
   stream >> ob.code;
   cout << "Enter number:";
   stream >> ob.num;
   cout << endl;
   return stream;
}
//***********
int main()
{
   phoneBook ob;
   char ch;
   fstream pb("phone.dat", ios::in | ios::out | ios::app);
   if(!pb) {
      cout << "Cannot open phone.dat file:";
      cin.get();
      return 1;
   }
   for(;;) {
      do {
	        clrscr();
	        cout << "1. Enter numbers\n";
	        cout << "2. Display numbers\n";
	        cout << "3. Quit\n";
	        cout << "Enter a choice(1-3) :";
	        cin >> ch;
      } while (ch < '1' || ch > '3');
      switch(ch) {
	         case '1' :
	              cin >> ob;
	              cout << "Entry is :";
	              cout << ob;   //show on screen
	              pb << ob;     //write to disk;
	              getch();
	              break;
        	   case '2' :
	              char c;
	              pb.seekg(0, ios::beg);
	              while(!pb.eof()) {
	                  pb.get(c);
	                  if(!pb.eof())
		                   cout << c;
	              }
	              pb.clear();   //reset eof
	              cout << endl;
	              getch();
	              break;
	         case '3':
      	        pb.close();
	              return 0;
      } //end of switch
   } //end of for
}


