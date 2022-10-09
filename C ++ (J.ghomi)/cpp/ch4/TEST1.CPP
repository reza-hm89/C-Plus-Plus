#include <iostream.h>
#include <conio.h>
int eventf(char s[], char ch, char n);
int main()
{
    char s[21], ch ;
    int n, p ;
    clrscr();
    cout << "enter string:" ;
    cin.get(s, 20) ;
    cin.get(); /* for read end of line char */
    cout << "enter the character:";
    ch = cin.get();
    cout << "enter the event:";
    cin >> n;
    p = eventf(s, ch, n);
    if(p == -1)
	 cout << n << "th event not found:";
    else
	 cout << n << "th event is in position:" << p;
    getch();
    return 0;
}
//*******************************
int eventf(char s[], char ch, char n)
{
    int i, count = 0;
    for(i = 0 ; s[i]; i++) {
	if (s[i] == ch)
	    count ++ ;
	if(count == n)
	    return (i + 1) ;
	}
	return -1 ;
}
