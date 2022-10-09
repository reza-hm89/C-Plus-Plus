#include <iostream.h>
#include <conio.h>
const int idle = 0;
const int inuse = 1;
class myClass2;   //forward declarion
class myClass1 {
    int status; //idle if off inuse if on screen
  public:
    void set_status(int state);
    int idleFunction(myClass2 b);
};
//*******************
class myClass2 {
    int status;  //IDLE if off INUSE if on screen
  public:
    void set_status(int state);
    friend int myClass1::idleFunction(myClass2 b);
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
//***idle is member of myClass1, but friend of myClass2***
int myClass1::idleFunction(myClass2 b)
{
   if(status || b.status)
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
  if(x.idleFunction(y))
     cout << "Screen can be used.\n";
  else
     cout << "In use.\n";
  x.set_status(inuse);
  if(x.idleFunction(y))
     cout << "Screen can be used.\n";
  else
     cout << "In use.\n";
  getch();
  return 0;
}

