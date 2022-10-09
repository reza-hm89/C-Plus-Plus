//#include <stdio.h>
#include <iostream.h>
#include <conio.h>
int main()
{
  int num1, num2, flag = 1;
  char op;
  while(flag){
     clrscr();
     cout << "Enter num1, operator , num2:";
     cin >> num1 >> op >> num2;
     switch(op){
	      case '+' :
	         cout << "\n sum = " << (num1 + num2);
	         break;
	      case '-' :
	         cout << "\n minus = " << (num1 - num2);
	         break;
	      case '/' :
	      case '\\' :
	         cout << "\n division = " << (float)num1 / num2;
	         break;
	      case '*' :
	         cout << "\n multiply = " << (num1 * num2);
	         break;
	      default:
	         cout << "\n operator is illegal. press a key to end.";
	         flag = 0;
     }//end of switch
     getch();
   }//end of while
  return 0;
}
