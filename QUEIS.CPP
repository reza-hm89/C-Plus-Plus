#include<iostream.h>
#include<conio.h>
int main()
{
	long int i,n,qst,corect,sum,id;
	clrscr();
	cout<<"Enter Number Of Students:";
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cout<<"\nEnter Your ID:";
		cin>>id;
		cout<<"\nEnter Javabhay Sahih be so'alat(0-20):";
		cin>>corect;
		if ((corect<0) || (corect>20))
		{
			cout<<"\njavab ha hkarej az mahdode bod!!!";
			cout<<"\nEnter Javabhay Sahih be so'alat(0-20):";
			cin>>corect;
		}
		cout<<"\nEnter tedad javabhaye dade shode be so'alat(0-20):";
		cin>>qst;
		if ((qst<0) || (qst>20))
		{
			cout<<"\njavab ha hkarej az mahdode bod!!!";
			cout<<"\nEnter tedad javabhaye dade shode be so'alat(0-20):";
			cin>>qst;
		}
		clrscr();
		cout<<"\nJavabhay Sahih : "<<corect<<endl;
		cout<<"\nJavabhay Ghalat: "<<qst-corect<<endl;
		sum=(corect*3)-(qst-corect);
		cout<<"\nNomre Daneshjoo :"<<sum<<endl;

	}
	getch();
	return 0;
}
