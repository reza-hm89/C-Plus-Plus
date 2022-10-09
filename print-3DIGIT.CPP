#include<iostream.h>
#include<conio.h>
int main()
{
clrscr();
int i;
for(i=100;i<1000;i++)
   {
    if(i/100==i%10)
       cout<<i<<"   ";
    if(i%50==0)
       cout<<"    "<<"\n";
   }
getch();
return 0;
}