#include <iostream.h>
#include <conio.h>
class dayOfYear {
      public:
	  friend int equal(dayOfYear date1, dayOfYear date2);
	  dayOfYear(int the_month, int the_day);
	  dayOfYear();
	  void input();
	  void output();
	  int  get_month();
	  int  get_day();
      private:
	  int month;
	  int day;
};
//****************
void dayOfYear::output()
{
  cout << "Month=" << month << ", Day=" << day << endl;
}
//******************
void dayOfYear::input()
{
  cout << "Enter the month as a number:";
  cin >> month;
  cout << "Enter the day as a number:";
  cin >> day;
}
//*******************
dayOfYear::dayOfYear(int the_month, int the_day)
{
  month = the_month;
  day = the_day;
}
//*******************
dayOfYear::dayOfYear()
{
  month = 1;
  day = 1;
}
//*****************
int main()
{
   dayOfYear today, birthDay(1, 15);
   clrscr();
   cout << "Enter today's date:\n";
   today.input();
   cout << "Today's date is :";
   today.output();
   cout << "Ali's birth date is :";
   birthDay.output();
   if(equal(today, birthDay))
       cout << "Happy birthday ali!";
   else
       cout << "Happy unbirthday ali!";
   getch();
   return 0;
}
//******************
int  equal(dayOfYear date1, dayOfYear date2)
{
  return(date1.month == date2.month && date1.day == date2.day);
}


