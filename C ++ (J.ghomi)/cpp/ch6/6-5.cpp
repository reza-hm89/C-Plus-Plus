#include <iostream.h>
#include <conio.h>
class time {
  public:
     time();                       //constructor
     void setTime(int, int, int);  //set hour, minute, second
     void printMilitary();         //print military time format
     void printStandard();         //print standard time format
  private:
     int hour;     //0 - 23
     int minute;   //0 - 59
     int second;   //0 - 59
};
//********************
//member function for time class
//time constructor initializes each data member to zero.
//ensure all time objects start in a consistent state.
time::time() { hour = minute = second = 0;}
void time::setTime(int h, int m, int s)
{
  hour   = (h >= 0 && h < 24) ? h : 0;
  minute = (m >= 0 && m < 60) ? m : 0;
  second = (s >= 0 && s < 60) ? s : 0;
}
//print time in military format
void time::printMilitary()
{
  cout << (hour   < 10 ? "0" : "") << hour << ":"
       << (minute < 10 ? "0" : "") << minute;
}
//***********************
void time::printStandard()
{
  cout << (( hour == 0 || hour == 12) ? 12 : hour % 12)
       << ":" << (minute < 10 ? "0" : "") << minute
       << ":" << (second < 10 ? "0" : "") << second
       << (hour < 12 ? " AM" : " PM");
}
//**************
int main()
{
   time t;
   clrscr();
   cout << "The initial military time is ";
   t.printMilitary();
   cout << "\nThe initial standard time is ";
   t.printStandard();
   t.setTime(13, 27, 6);
   cout << endl;
   cout << "Military time after setTime is ";
   t.printMilitary();
   cout << endl;
   cout << "Standard time after setTime is ";
   t.printStandard();
   t.setTime(99, 99, 99); //attempt invalid seetings
   cout << "\n\nAfter attempting invalid settings:\n"
	<< "Military time:";
   t.printMilitary();
   cout << "\nStandard time:";
   t.printStandard();
   cout << endl;
   getch();
   return 0;
}


