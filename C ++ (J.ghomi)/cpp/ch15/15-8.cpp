#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
int main()
{
    clrscr();
    bool b;
    b = true;
    cout << b << "  " << boolalpha << b << endl;
    cout << "Enter a boolean value:";
    cin >> boolalpha >> b;
    cout << "Here is what you entered: " << b;
    getch();
    return 0;
}
