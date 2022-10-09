#include <iostream.h>
#include <conio.h>
int main()
{
  int i, j, stno, s2, n, m, un, c1 = 0, c2 = 0;
  float s1, ave, grade;
  clrscr();
  cout << "Enter number of student:";
  cin >> n;
  for(i = 0; i < n; i++){
     cout << "\nEnter stno and # of course:";
     cin >> stno >> m;
     s1 = 0;
     s2 = 0;
     for(j = 0; j < m; j++){
	 cout << "\nEnter grade and unit # " <<  j + 1 << ":";
	 cin >> grade >> un;
	 s1 += grade * un;
	 s2 += un;
     }//end of for j
     ave = s1 / s2 ;
     if(ave >= 17){
	  cout << "stno = " << stno << ", ave="<< ave << ", <exelent>";
	  c1 ++;
     }
     else if (ave < 12){
	  cout << "stno = " << stno << ", ave=" << ave << ", <probation>";
	  c2 ++;
     }
     cout << "\npress a key to continue...";
     getch();
  }//end of for i
  cout << "\nexelent=" << c1 << " probation=" << c2;
  getch();
  return 0;
}







