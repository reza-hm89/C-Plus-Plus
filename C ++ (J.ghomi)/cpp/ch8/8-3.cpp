#include <iostream.h>
#include <conio.h>
class date {
    friend ostream &operator<<(ostream &, const date &);
  public:
    date(int m = 1, int d = 1, int y = 1370); //constructor
    void setDate(int, int, int); //set the date
    date &operator++();          //preincrement operator
    date operator++(int);        //postincrement operator
    const date &operator+=(int); //add days, modify object
    int endOfMonth(int);         //is this end of month?
  private:
    int month;
    int day;
    int year;
    static const int days[];     //array of days per month
    void helpIncrement();        //utility function
};
//****************************
//initialize static member at file scope
//one class-wide copy
const int date::days[] = { 0, 31, 31, 31, 31, 31, 31,
			   30, 30, 30, 30, 30, 29 };
//date constructor
//date::date(int m, int d, int y)
date::date(int d, int m, int y)
{
  setDate(d, m, y);
}
//****set the date***********
//void date::setdate(int mm, int dd, int yy)
void date::setDate(int dd, int mm, int yy)
{
  month = (mm >= 1 && mm <= 12) ? mm : 1;
  year = (yy >= 1370 && yy <= 1400) ? yy : 1370;
       day = (dd >= 1 && dd <= days[month]) ? dd : 1;
}
//** preincrement operator overloaded as a member funtion.
date &date::operator++()
{
   helpIncrement();
   return *this; //reference return to create an lvalue
}
//*****post increment operator overloaded as a member function.
//note that the dummy integer parameter does not have
//a parameter name
date date::operator++(int)
{
  date temp = *this;
  helpIncrement();
  //return non-incremented, save, temporary object
  return temp; //value return, not a reference return
}
//add a specific number of days to a date
const date &date::operator+=(int ad)
{
  for(int i = 0; i < ad; i ++)
      helpIncrement();
  return *this;        //enables cascading
}
//*****determine if the day is the end of the month
int date::endOfMonth(int d)
{
      return d == days[month];
}
//function to help increment the date
void date::helpIncrement()
{
  if(endOfMonth(day) && month == 12) { // end year
     day = 1;
     month = 1;
     ++year;
  }
  else if(endOfMonth(day)) {    //end month
     day = 1;
     ++month;
  }
  else       //not end of month or year; increment day
     ++day;
}
//*overload output operator **********
ostream &operator<<(ostream &output, const date &d)
{
   static char *monthName[13] = { "", "Farvardine",
     "Ordibehesht", "Khordad", "Tir", "Mordad", "Shahrivar",
     "Mehr", "Aban", "Azar", "Day",
     "Bahnman", "Esphand" };
   output << monthName[d.month] << ' '
	  << d.day << ", " << d.year;
   return output; //enables cascading
}
//*******************
int main()
{
  clrscr();
  date d1, d2(29 , 4, 1375), d3(0, 99, 8045);
  cout << "d1 is " << d1
       << "\nd2 is " << d2
       << "\nd3 is " << d3 << "\n\n";
  cout << "d2 += 7 is " << (d2 += 7) << "\n\n";
  d3.setDate(28, 2, 1372);
  cout << "d3 is " << d3;
  cout << "\n++d3 is " << ++d3 << "\n\n";
  date d4(18,6, 1370);
  cout << "Testing the preIncrement operator:\n"
       << "d4 is "  << d4 <<"\n";
  cout << "++d4 is " << ++d4 << "\n";
  cout << "d4 is " << d4 << "\n\n";
  cout << "Testing the postIncrement operator:\n"
       << "d4 is " << d4 << '\n';
  cout << "d4++ is " << d4++ << '\n';
  cout << "d4 is " << d4 << endl;
  getch();
  return 0;
}









