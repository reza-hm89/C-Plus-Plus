#include <iostream.h>
#include <conio.h>
void first_dif(char *, char *, int);
int main()
{
      char st1[40], st2[40] ;
      int compcase = 1 ;
      clrscr();
      cout << "Enter first string:" ;
      cin.get(st1, 39) ;
      cin.get(); /* for discard end of line char */
      cout << "Enter second string:";
      cin.get(st2, 39) ;
      first_dif(st1, st2, compcase) ;
      getch();
      return 0;
}
//********************
void first_dif(char *s1, char *s2, int ignore_case)
     /* if ignore_case is 1 ,ignore case
	of letter */
{
    int i ;
    char a , b ;
    for(i = 0; *s1 && *s2; s1++, s2++, i++)
      if(*s1 != *s2) {
	      if(ignore_case) {
	          a = (*s1 >= 'a' && *s1 <= 'z') ? *s1 -= 32 : *s1;
	          b = (*s2 >= 'a' && *s2 <= 'z') ? *s2 -= 32 : *s2;
	          if(a != b)
		          break ;
	   }//end of if
	   else
	      break;
      }//end of if
      if(*s1 || *s2) {
      	cout << "Strings are not equal, ";
	      cout << "The first difference occurs in : " << (i + 1);
      }
      else
      	cout << "Strings are equal ." ;
}


