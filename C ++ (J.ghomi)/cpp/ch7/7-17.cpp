#include <iostream.h>
#include <conio.h>
class student{
     int   stno;
     char  name[21];
     float ave;
  public:
     void input();
     void output();
};
//****************
void student::input()
{
   cout << " Enter name, stno, ave :";
   cin >> name >> stno >> ave;
}
//********************
void student::output()
{
   cout << " Information is :";
   cout  << name << "  "<< stno << "  " << ave;
}
//************
int main()
{
   student *st;
   clrscr();
   st = new student;
   st -> input();
   st -> output();
   getch();
   return 0;
}
