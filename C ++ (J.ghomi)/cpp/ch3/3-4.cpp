#include <iostream.h>
#include <conio.h>
int prime(int);
int main()
{
  int num;
  char ans;
  clrscr();
  while(1) {
     cout << "\n Enter a number:" ;
     cin >> num;
     if(prime(num))
      	cout << "\n Number " <<  num << " is prime.";
     else
	      cout << "\n Number " << num << " is  not prime.";
     cout << "\n Do you want to continue?(y/n):";
     cin >> ans;
     if(ans != 'y')
	    break;
  }// end of while
  return 0;
}
//********************
int prime(int num)
{
  int i, temp = 1;
  for(i = 2; (i <= num / 2)  && temp ; i++)
      if(num % i == 0)
	        temp = 0;
  return temp;
}




