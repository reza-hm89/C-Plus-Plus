#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
int main()
{
    clrscr();
    cout << hex << 100 << endl;
    cout << setfill('?') << setw(10) << 2343.0;
    getch();
    return 0;
}
