#include <iostream.h>
#include <conio.h>
enum weekDays {SAT, SUN, MON, TUE, WED, THU,FRI};
typedef enum weekDays weekDay;
class employee {
    int   hours;
    float r1;
    float r2;
    float base;
    float rate;
    float wages;
   public:
    employee();
    void proc();
    weekDay tomorrow(weekDay);
}; //end of class
//*******************
employee::employee()
{
  r1 = 1.2f;  //1.2 convert to float
  r2 = 2.0f;  //2.0 convert to float
  wages = 0.0;
}
//*******************
void employee::proc() {
   weekDays day;
   cout << "Enter the basic hourly rate:";
   cin >> base;
   cout << "Enter the hours worked "
        <<  "for saturday through friday.\n";
   day = FRI;
   do {
      day = tomorrow(day);
      cin >> hours;
      switch(day) {
         case SAT:
            case SUN:
            case MON:
            case TUE:
            case WED:
               rate = base; break;
            case THU:
               rate = r1 * base; break;
            case FRI:
               rate = r2 * base; break;
   }
   wages += rate * hours;
   } while (day != FRI);
   cout << "\nTotal wages for the week is : " << wages;
}
//********************
weekDays employee::tomorrow(weekDays d)
{
   weekDays nextd;
   switch(d) {
      case SUN : nextd = MON; break;
      case MON : nextd = TUE; break;
      case TUE : nextd = WED; break;
      case WED : nextd = THU; break;
      case THU : nextd = FRI; break;
      case FRI : nextd = SAT; break;
      case SAT : nextd = SUN; break;
   }
   return(nextd);
}
//*********************
int main()
{
   employee emp;
   emp.proc();
   getch();
   return 0;
}
