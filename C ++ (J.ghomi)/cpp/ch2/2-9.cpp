#include <iostream.h>
#include <conio.h>
int main()
{
    int num, digit ;
    clrscr();
    while(1){
       cout << "\nEnter a number:";
       cin >> num;
       cout << "Inverse = ";
       do{
      	  digit = num % 10;
	        cout << digit;
	        num /= 10;
       } while(num != 0);
    }//end of while(1)
   // return 0;
}

