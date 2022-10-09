#include <iostream.h>
#include <conio.h>
#include <string.h>
void check(char *a, char *b, int (*cmp)(const char *, const char *));
int main()
{
    char s1[80], s2[80] ;
    int (*p)(const char *, const char *);
    clrscr();
    p = strcmp;
    cout << " Enter first string :" ;
    cin >> s1 ;
    cout << " Enter second string :";
    cin >> s2 ;
    check(s1, s2, p);
    getch();
    return 0;
}
//*********************
void check(char *a, char *b, int (*cmp)(const char *, const char *))
{
   if(!(cmp)(a, b))
       cout << " Strings are equal.";
   else
       cout << " Strings are not equal.";
}



