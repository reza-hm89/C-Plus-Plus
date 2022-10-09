#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<stdio.h>
void main()
{
	clrscr();
	int n;
	float an,bn,x,Fx;
	cout<<"Enter your Domain [,]:";
	cin>>an>>bn;
	cout<<"your domain is: ["<<an<<","<<bn<<"]\n";
	cout<<"Enter n: ";
	cin>>n;
	cout<<"n= "<<n<<"\n";
	cout<<"\nF(x)=x^3+4x^2-10";
	cout<<"\n\nn             an            bn             xn              F(x)";
	cout<<"\n---------------------------------------------------------------------------\n\n";

	for (int i=0;i<n;i++)
	{
		x=(an+bn)/2;
		Fx=pow(x,3)+4*pow(x,2)-10;
		gotoxy(1,i+10);    cout<<i+1;
		gotoxy(15,i+10);   cout<<an;
		gotoxy(30,i+10);   cout<<bn;
		gotoxy(45,i+10);   cout<<x;
		gotoxy(60,i+10);   printf("%f",Fx);
		if (Fx>0)
			bn=x;
		if (Fx<0)
			an=x;
		cout<<endl;
	}
	printf("\n\nFinal F(x)= %f",Fx);
	getch();
}