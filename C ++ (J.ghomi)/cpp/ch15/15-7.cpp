#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
int main()
{
    clrscr();
    cout << setiosflags(ios::showpos);
    cout << setiosflags(ios::showbase);
    cout << 123 << "  " << hex << 123;
    getch();
    return 0;
}
