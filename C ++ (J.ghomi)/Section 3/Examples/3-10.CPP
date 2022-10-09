#include<iostream.h>
#include<conio.h>
int square(int);
float square(float);
void main()
{
	int x=10;
	float y=5.5;
	clrscr();
	cout<<square(x)<<endl;
	cout<<square(y)<<endl;
	getch();
}
float square(float f)
{
	cout<<"In float Function: ";
	return f*f;
}
int square(int i)
{
	cout<<"In int Function: ";
	return i*i;
}
