#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
ostream &sethex(ostream &stream)
{
   stream.setf(ios::showbase);
   stream.setf(ios::hex, ios::basefield);
   return stream;
}
//***************
int main()
{
    clrscr();
    cout << 256 << "  " << sethex << 256;
    getch();
    return 0;
}
