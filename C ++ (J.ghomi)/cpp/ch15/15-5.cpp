#include <iostream.h>
#include <conio.h>
int main()
{
    clrscr();
    cout.precision(4);
    cout.width(10);
    cout << 10.12345 << "\n";
    cout.fill('*');
    cout.width(10);
    cout << 10.12345 << "\n";
    cout.width(10);
    cout << "hi!" << "\n";
    cout.width(10);
    cout.setf(ios::left); // left justify
    cout << 10.12345;
    getch();
    return 0;
}
