#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <iomanip.h>
class employee {
  public:
     employee (const char[] , const char []);
     const char *getFirstName() const;
     const char *getLastName() const;
     //pure virtual function makes employee abstract base class
     virtual double earnings() const = 0; //pure virtual
     virtual void print() const;           //virtual
  private:
     char firstName[20];
     char lastName[20];
};
//***********************
employee::employee(const char first[], const char last[])
{
   strcpy(firstName, first);
   strcpy(lastName, last);
}
//****************
void employee::print() const
{
   cout << firstName << "   " << lastName ;
}
//**************************
class boss : public employee {
  public:
    boss(const char [], const char [], double = 0.0);
    void setWeeklySalary(double);
    virtual double  earnings() const;
    virtual void print() const;
  private:
     double weeklySalary;
};
//****************
boss::boss(const char first[], const char last[], double s)
	   : employee(first, last) //call base-class constructor
{
   setWeeklySalary(s);
}
//***************
//set the boss's salary
void boss::setWeeklySalary(double s)
{
   weeklySalary = s > 0 ? s : 0 ;
}
//**********************
double boss::earnings() const
{
   return weeklySalary;
}
//*****************
void boss::print() const
{
   cout <<"\nboss: ";
   employee::print();
}
//******************
class commissionWorker : public employee {
   public:
      commissionWorker(const char [],const char [],double=0.0,double=0.0,int=0);
      void setSalary(double);
      void setCommission(double);
      void setQuantity(int);
      virtual double earnings() const;
      virtual void print() const;
   private:
      double salary;
      double commission;
      int quantity;
};
//*****************
commissionWorker:: commissionWorker(const char first[],
	const char last[] , double s, double c, int q)
	: employee(first, last) //call base-class constructor
{
     setSalary(s);
     setCommission(c);
     setQuantity(q);
}
//***************
void commissionWorker::setSalary(double s)
{
  salary = s > 0 ? s : 0;
}
//***************
void commissionWorker::setCommission(double c)
{
  commission = c > 0 ? c : 0;
}
//*****************
void commissionWorker::setQuantity(int q)
{
  quantity = q > 0 ? q : 0;
}
//*****************
double commissionWorker::earnings() const
{
  return salary + commission * quantity;
}
//*******************
void commissionWorker::print() const
{
  cout << "\ncommission worker : ";
  employee::print();
}
//*****************
class pieceWorker : public employee {
   public:
      pieceWorker(const char [], const char [], double = 0.0, int = 0);
      void setWage(double);
      void setQuantity(int);
      virtual double earnings() const;
      virtual void print() const;
   private:
      double wagePerPiece;
      int quantity;
};
//******************8
pieceWorker::pieceWorker(const char first[], const char last[],
	     double w, int q)
	     :employee(first, last) //call base-constructor
{
    setWage(w);
    setQuantity(q);
}
//*************
void pieceWorker::setWage(double w)
{
   wagePerPiece = w > 0 ? w : 0;
}
//******************
void pieceWorker::setQuantity(int q)
{
   quantity = q > 0 ? q : 0;
}
//**********************
double pieceWorker::earnings() const
{
   return quantity * wagePerPiece;
}
//*******************
void pieceWorker::print() const
{
    cout << "\npiece worker:";
    employee::print();
}
//****************
class hourlyWorker: public employee {
  public:
     hourlyWorker(const char [], const char [], double = 0.0, double = 0.0);
     void setWage(double);
     void setHours(double);
     virtual double earnings() const;
     virtual void print() const;
  private:
     double wage;
     double hours;
};
//****************
hourlyWorker::hourlyWorker(const char first[], const char last[],
	      double w, double h) : employee(first, last)
{
   setWage(w);
   setHours(h);
}
//*****************
void hourlyWorker::setWage(double w)
{
   wage = w > 0 ? w : 0;
}
//***************
void hourlyWorker::setHours(double h)
{
   hours = h >= 0 && h < 168 ? h : 0;
}
//*****************
double hourlyWorker::earnings() const
{
   if(hours <= 40) //no overtime
       return wage * hours;
   else
       return 40 * wage + (hours - 40) * wage * 1.5;
}
//*****************
void hourlyWorker::print() const
{
   cout << "\nhourly worker: ";
   employee::print();
}
//*****************
void vPointer(const employee *);
void vReference(const employee &);
int main()
{
    clrscr();
    cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(2);
    boss b(" Bahram", " alizadeh", 800);
    b.print();                                        //static binding
    cout << " earned "<< b.earnings() << " Tomans " ; //static binding

    vPointer(&b);        //uses dynamic binding
    vReference(b);       //uses dynamic binding
    cout << endl;

    commissionWorker c(" Ali", " ahmadi", 200, 3, 150);
    c.print();                                        //static binding
    cout << " earned " << c.earnings() << " Tomans" ; //static binding
    vPointer(&c);         //uses dynamic binding
    vReference(c);        //uses dynamic binding
    cout << endl;

    pieceWorker p(" Ahmad", " razavi", 2.5, 200);
    p.print();
    cout << " earned  " << p.earnings() << " Tomans";
    vPointer(&p);           //uses dynamic binding
    vReference(p);          //uses dynamic binding
    cout << endl;
    hourlyWorker h(" Mohsen", " alizadeh", 13.75, 40);
    h.print();
    cout << " earned " << h.earnings() << " Tomans" ;
    vPointer(&h);           //uses dynamic binding
    vReference(h);          //uses dynamic binding
    cout << endl;
    getch();
    return 0;
}
//*******************8
void vPointer(const employee *baseptr)
{
   baseptr -> print();
   cout << " earned  " << baseptr -> earnings() << " Tomans";
}
//*****************
void vReference(const employee &baseref)
{
 baseref.print();
 cout << " earned  " << baseref.earnings() << " Tomans" ;
}



