#include<iostream.h>
#include<conio.h>
int main()
{
clrscr();
char ans='y';
int  i=1,num,s=0;
long int sum=0;
while(ans=='y')
    {
     cout<<"Enter Your Number:";
     cin>>num;
     sum+=(num*num);
     s+=i;
     cout<<"Do You Want to cantinue?(y/n)";
     cin>>ans;
     if (ans=='y');

    }

    cout<<"Squre is:"<<sum<<endl;
    cout<<"Numbers of digits is:"<<s;

getch();
return 0;
}

