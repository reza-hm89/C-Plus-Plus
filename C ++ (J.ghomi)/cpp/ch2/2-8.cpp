#include <iostream.h>
#include <conio.h>
int main()
{
    int x, sum = 0, n = 0;
    char ans = 'y';
    clrscr();
    while(ans == 'y'){
       cout << "Enter a number:";
       cin >> x;
       sum += x*x;
       n ++;
       cout << "Do you want to continue?(y/n):";
       cin >> ans;
    }//end of while
    cout << "You entered " << n << " numbers." << endl;
    cout << " Sum of square is:" << sum;
    getch();
    return 0;
}

