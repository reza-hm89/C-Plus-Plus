#include <iostream.h>
#include <conio.h>
class number {
   protected:
     int val;
   public:
     void setVal(int i) { val = i; }
     //show is a pure virtual function
     virtual void show () = 0;
};
//***********
class hextype : public number {
    public:
       void show() {
	  cout << "hex = " << hex << val << endl;
       }
};
//*****************
class dectype : public number {
   public:
      void show() {
	 cout << "val = " << val << endl;
      }
};
//****************
class octtype : public number {
   public:
     void show() {
	cout << "oct = " << oct << val << endl;
     }
};
//**************
int main()
{
  dectype d;
  hextype h;
  octtype o;
  clrscr();
  d.setVal(20);
  d.show(); //display 20 - decimal
  h.setVal(20);
  h.show(); //display 14 - hexadecimal
  o.setVal(20);
  o.show(); //display 24 - octal
  getch();
  return 0;
}

