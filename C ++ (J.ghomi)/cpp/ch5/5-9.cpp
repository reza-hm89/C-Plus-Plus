#include <iostream.h>
#include <conio.h>
#include <string.h>
int main()
{
    int i;
    const int k = 5;
    char name[21];
    char *list[k]=
		 {"ali",
		  "ahmad",
		  "alireza",
		  "jalal",
		  "mohammad"
		 } ;
    clrscr();
    cout << "Enter a name for search:" ;
    cin >> name;
    for(i = 0; i <k; i++)
      if(!strcmp(list[i], name))
	    break ;
    if(i == k)
      cout << "Name <" << name << "> not exist." ;
     else
      cout << "Name <" << name << "> exist.";
    getch();
    return 0;
}

