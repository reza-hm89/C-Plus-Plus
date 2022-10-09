#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <assert.h>
#include <iomanip.h>
class employee {
   public:
      employee(const char *, const char *);
      void print() const;
      ~employee() ;
   private:
      char *firstName;
      char *lastName;
};
//****************
class hourlyWorker : public employee {
   public:
      hourlyWorker(const char *, const char *, double, double);
      double getPay() const;
      void print() const;    //override base-class print
   private:
      double wage;
      double hours;
};
//***************
employee::employee(const char *first, const char *last)
{
  firstName = new char[strlen(first) + 1];
  assert(firstName != 0);
  strcpy(firstName, first);
  lastName = new char[strlen(last) + 1];
  assert(lastName != 0);
  strcpy(lastName, last);
}
//***********
void employee::print() const
{
   cout << "First name is " << firstName << ", Last name is " << lastName ;
   cout << endl;
}
//****************
employee::~employee()
{
   delete[] firstName;
   delete[] lastName;
}
//***************
hourlyWorker::hourlyWorker (const char *first, const char *last,
			   double initHours, double initWage)
			   : employee(first, last)
{
   hours = initHours;
   wage = initWage;
}
//**************
double hourlyWorker::getPay() const
{
  return wage *hours;
}
//**************
void hourlyWorker::print() const
{
    cout << "hourlyWorker::print() is executing\n\n";
    employee::print();  //call base-class print function
    cout << "is an hourly worker with pay of rials :"
	 << setiosflags(ios::fixed | ios::showpoint)
	 << setprecision(2) << getPay() << endl;
}
//****************
int main()
{
   clrscr();
   hourlyWorker h("Ali" , "Ahmadi", 4000, 100);
   h.print();
   getch();
   return 0;
}

