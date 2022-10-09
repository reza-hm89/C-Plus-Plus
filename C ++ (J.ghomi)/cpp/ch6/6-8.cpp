#include <iostream.h>
#include <conio.h>
class time {
  public:
     time(int = 0, int = 0, int = 0);                       //constructor
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
time::time(int hr, int min, int sec)
{
  setTime(hr, min, sec);
}
//*********************
//set a new time value using military time. perform validity
//check on the data values. set invalid values to zero.
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
   clrscr();
   time t1,             //all arguments defaulted
	t2(2),          //minute and second defaulted
	t3(21, 34),     //second defaulted
	t4(12, 25, 42), //all values specified
	t5(27, 74, 99); //all bad values specified
   cout << "Constructed with:\n"
	<< "All arguments defaulted: \n  ";
   t1.printMilitary();
   cout << "\n  ";
   t1.printStandard();
   cout << "\nHour specified, minute and second defaulted:" << "\n  ";
   t2.printMilitary();
   cout << "\n  ";
   t2.printStandard();
   cout << "\nHour and minute specified, second defaulted:" << "\n  ";
   t3.printMilitary();
   cout << "\n  ";
   t3.printStandard();
   cout << "\nHour, minute and second specified:" << "\n  ";
   t4.printMilitary();
   cout << "\n  ";
   t4.printStandard();
   cout << "\nAll invalid values specified:" << "\n  ";
   t5.printMilitary();
   cout << "\n  ";
   t5.printStandard();
   getch();
   return 0;
}


