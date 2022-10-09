#include <iostream.h>
#include <conio.h>
void separate(char exp[], char oper[], int opnd[]);
int main()
{
   char expr[21], oper[21];
   int opnd[21];
   clrscr();
   cout << "Enter expression:";
   cin.get(expr, 20);
   separate(expr, oper, opnd);
   getch();
   return 0;
}
//***************
void separate(char expr[], char oper[], int opnd[])
{
  int i, j = 0 , k = 0;
  for(i = 0; expr[i]; i ++)
     if(expr[i] >= '0' && expr[i] <= '9')
	      opnd[j ++] = expr[i] - 48;
     else
	      oper[k ++] = expr[i];
   oper[k] = '\0';
   cout << "Operators are:" << oper << endl;
   cout << "Operands are:" ;
   for(i = 0; i < j; i ++)
     cout << opnd[i] << " ";
}

