#include <iostream.h>
#include <conio.h>
int main()
{
  int i2, i5, i10, i20, i50, count = 0;
  unsigned long int sum;
  clrscr();
  for(i2 = 0; i2 <= 50; i2 ++)
    for(i5 = 0; i5 <= 20; i5 ++)
      for(i10 = 0; i10 <= 10; i10 ++)
      	for(i20 = 0; i20 <= 5; i20 ++)
	        for(i50 = 0; i50 <= 2; i50 ++){
	        sum=i2*2 + i5*5 + i10 *10 +i20*20 + i50*50;
	         if(sum==100){
		          cout<< "\n 2Rials = " << i2 << " 5Rials = " << i5;
		          cout << " 10Rials = " << i10 << " ,20Rials = " << i20;
		          cout << " 50Rials = " << i50;
		          count ++;
	     }// end of if
	     else
	       sum = 0;
	   }//end of for
  cout << "\n number of correct times : " << count;
  getch();
  return 0;
}