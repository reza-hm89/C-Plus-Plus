#include<iostream.h>
#include<conio.h>
int main()
{
long int num,j,k,i,r,a[10];
clrscr();
cout<<"Enter Your Number:\n";
cin>>num;
k=num;
for(j=0;j<=9;j++)
a[j]=0;


   for (i=0;num!=0;i++)
	  {

		r=num%10;
		a[r]+=1;
		num/=10;
	  }

clrscr();
cout<<"Number is: "<<k<<endl;
for(i=0;i<=9;i++)
   cout<<"a["<<i<<"]:"<<a[i]<<endl;
getch();
return 0;
}

