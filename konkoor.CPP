#include<iostream.h>
#include<conio.h>
int main()
{
clrscr();
char ans='y';
int i,id,code,age,sex,n;
int taj=0,riz=0,ens=0,agem=0,j=0,agef=0,k=0,min=100,max=0;
cout<<"Enter Numbers of Students:";
cin>>n;
for(i=1;i<=n;i++)
   {
    cout<<"Student "<<i<<":\n";
    cout<<"Enter ID :";
    cin>>id;
    cout<<"\nEnter code Diplom (Tajrobi:1  riyazi:2   Ensani:3) :";
    cin>>code;
    cout<<"Enter Age :";
    cin>>age;
    cout<<"Enter Sex (male:1  Famale:2) :";
    cin>>sex;
    if(code==1)
      taj+=1;
    else if (code==2)
      riz+=1;
    else
      ens+=1;
    if(sex==1)
     {
      agem+=age;
      j+=1;
     }
    else
     {
      agef+=age;
      k+=1;
     }
    if(age>max)
      max=age;
    if(age<min)
      min=age;
   clrscr();
   }
gotoxy(1,1);
cout<<"Numbers of students:";
gotoxy(1,20);
cout<<"Riyazi";
gotoxy(1,25);
cout<<"Tajrobi";
gotoxy(1,30);
cout<<"Ensani";
gotoxy(2,20);
cout<<riz;
gotoxy(2,25);
cout<<taj;
gotoxy(2,30);
cout<<ens;
gotoxy(3,1);
cout<<"Average Age of students:";
gotoxy(3,20);
cout<<"Male";
gotoxy(3,25);
cout<<"Famale";
gotoxy(5,20);
cout<< (int)agem/j;
gotoxy(5,25);
cout<< (int)agef/k;
gotoxy(7,1);
cout<<"Youngest Student: "<<min<<endl;
cout<<"Oldest Student:   ";

getch();
return 0;
}