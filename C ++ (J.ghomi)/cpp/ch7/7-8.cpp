#include <iostream.h>
#include <conio.h>
class student {
      int   stno;
      char  name[21];
      float ave;
   public:
      student();
      void  input();
      void  print();
      float getAve();
};
//***************
student enter();
student::student()
{
   ave = 0;
}
//*********************
void student::input()
{
  cout << "Enter name , stno, ave :";
  cin >> name >> stno >> ave;
}
//********************
float student::getAve()
{
  return ave;
}
//********************
void student::print()
{
  cout << "\nName is : " << name ;
  cout << ", stno is : " << stno;
  cout << ", average is : " << ave;
}
//**********************
int main()
{
  int n, i;
  student st1, st2, st;
  clrscr();
  cout << "Enter number of stubents:";
  cin >> n;
  for (i = 0; i < n; i++) {
     st = enter();
     if(st.getAve() > st1.getAve()) {
	      st2 = st1;
	      st1 = st;
     }
     else if (st.getAve() > st2.getAve())
         st2 = st;
  }
  cout << "Second student is :";
  st2.print();
  getch();
  return 0;
}
//******************
student enter()
{
  student st;
  st.input();
  return st;
}



