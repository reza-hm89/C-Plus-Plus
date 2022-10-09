#include <iostream.h>
#include <conio.h>
int main()
{
  int grade;
  clrscr();
  cout << "\nEnter a grade:" ;
  cin >> grade;
  while(grade){
    if (grade >= 17 && grade <= 20)
       cout << "grade = " <<  grade << " score=" << 'A';
    else if (grade >= 15 && grade < 17)
       cout << "grade = " <<  grade << " score=" << 'B';
    else if (grade >= 12 && grade < 15)
       cout << "grade = " <<  grade << " score=" << 'C';
    else if (grade < 12)
       cout << "grade = " <<  grade << " score=" << 'D';
    cout << "\nEnter a grade:" ;
    cin >> grade;
  }//end of while
  return 0;
}
