#include<iostream.h>
#include<conio.h>
template <class T>
T maximum(T p1, T p2,T p3)
{
	T max;
	max=p1>p2 ? p1:p2;
	max= max>p3 ? max:p3;
	return max;
}
void main()
{
	char c1,c2,c3;
	clrscr();
	cout<<"\nEnter three characters:";
	cin>>c1>>c2>>c3;
	cout<<"The maximum char value is: "<<maximum(c1,c2,c3);
	int int1,int2,int3;
	cout<<"\nEnter three integers:";
	cin>>int1>>int2>>int3;
	cout<<"The maximum integer value is: "<<maximum(int1,int2,int3);
	double d1,d2,d3;
	cout<<"\nEnter three doubles: ";
	cin>>d1>>d2>>d3;
	cout<<"The maximum double value is: "<<maximum(d1,d2,d3);
	getch();
}



