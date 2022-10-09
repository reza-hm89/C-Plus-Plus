#include <iostream.h>
#include <conio.h>
void int_to_ascii(int , char *);
int main()
{
    int number ;
    char s[10] ;
    clrscr();
    cout << "enter a number :";
    cin >> number ;
    int_to_ascii(number, s) ;
    cout << "the string value is:" << s;
    getch();
    return 0;
}
//**********************************
void int_to_ascii(int value, char *str)
{
    int saveVal= value ;
    char temp, *saveStr = str ;
    if(value < 0)
	value *= -1 ;
    do{
  	    *str ++ = (value % 10) + 48 ;
	    value = value / 10 ;
    } while(value > 0);
    if (saveVal < 0)
       *str++ = '-' ;
    *str -- = '\0' ;
    while(saveStr < str) {
      temp = *str ;
      *str -- =* saveStr ;
      *saveStr ++ = temp ;
    }
}




