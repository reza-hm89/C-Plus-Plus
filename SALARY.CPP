#include<iostream.h>
#include<conio.h>
int main()
{
clrscr();
long int i,id,s,sum,news;
const int n=10;
for (i=1;i<=n;i++)
    {
     cout<<"Enter ID & Salary "<<i<<":\n";
     cin>>id>>s;
     if       (s<=190000)
	sum=s+((s*4)/100);
     else if  ((s>190000) && (s<=250000))
	sum=s+((s*5.5)/100);
     else if  (s>250000)
	sum=s+((s*7)/100);
      news=sum-s;
      cout<<"New Salary is: "<<sum<<endl;
      cout<<"Added Salary : "<<news<<endl;

    }
getch();
return 0;
}