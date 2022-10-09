#include <iostream.h>
#include <conio.h>
int main()
{
    int first[10], second[10] ;
    int *p ;
    p = first ;
    for(int t = 0 ; t < 20; t ++)
      *p++ = t ;
}

