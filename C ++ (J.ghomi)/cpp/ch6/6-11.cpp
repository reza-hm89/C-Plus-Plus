#include <iostream.h>
#include <conio.h>
const int idle = 0;
const int inuse = 1;
class myClass2;   //forward declarion
class myClass1 {
    int status; //idle if off INUSE if on screen
  public:
    void set_status(int state);
    friend int idleFunction(myClass1 a, myClass2 b);
};
//*******************
class myClass2 {
    int status;  //idle if off inuse if on screen
  public:
    void set_status(int state);
    friend int idleFunction(myClass1 a, myClass2 b);
};
//****************
void myClass1::set_status(int state)
{
  status = state;
}
//*****************
void myClass2::set_status(int state)
{
  status = state;
}
//*****************
int idleFunction(myClass1 a, myClass2 b)
{
   if(a.status || b.status)
       return 0;
   else
       return 1;
}
//*******************
int main()
{
  myClass1 x;
  myClass2 y;
  clrscr();
  x.set_status(idle);
  y.set_status(idle);
  if(idleFunction(x, y))
     cout << "Screen can be used.\n";
  else
     cout << "In use.\n";
  x.set_status(inuse);
  if(idleFunction(x, y))
     cout << "Screen can be used.\n";
  else
     cout << "In use.\n";
  getch();
  return 0;
}





