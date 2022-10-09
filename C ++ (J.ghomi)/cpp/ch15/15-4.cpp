#include <iostream.h>
#include <conio.h>

int main()
{
   int i = 1000;
   double d = 0.0947628;
   cout << "The value of the flags variable is: "
        << cout.flags()
        <<"\nprint int and double in original format:\n"
        << i << '\t' << d << "\n\n";
   long originalFormat =
        cout.flags(ios::oct | ios::scientific);
        cout << "The value of the flags variable is: "
             << cout.flags()
             << "\nprint int and double in a new format\n"
             << "specified using the flags member function:\n"
             << i << '\t' << d << "\n\n";
        cout.flags(originalFormat );
        cout << "The value of the flags variable is: "
             << cout.flags()
             << "\nprint values in original format again:\n"
             << i << '\t' << d << endl;
        getch();
        return 0;
}