#include <conio.h>
#include <iostream.h>
void ascii_to_int(int *, char *);
int main()
{
   int number ;
   char s[10] ;
   clrscr();
   cout << "\nEnter numeric string:";
   cin >> s ;
   ascii_to_int(&number, s) ;
   cout << "Numeric value is:" << number ;
   getch();
   return 0;
}
//**************************
void ascii_to_int(int *value, char *str)
{
  int sign = 1 ;
  *value = 0 ;
  while(*str == ' ') str++ ;
  if(*str== '-' || *str == '+')
  	     sign = (*str ++ == '-') ? -1 : 1;
  while(*str)
  	   if((*str >= '0') && (*str <= '9'))
	       *value = (*value * 10) + (*str ++ -48) ;
	   else {
	      cout << "Watning :the <" << *str << "> is invalid character.\n";
	      break ;
	}
     *value *= sign ;
}

