#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<math.h>
void main()
{
	char str[100],s;
	float a=0,c;
	int i,b,k=1,j;
	clrscr();
	cout<<"Enter Your String:";
	cin.get(str,100);
	for (i=0;str[i]!='.';i++)
	{

		s=str[i];
		a=(s-48)+(a*10);

	}
	for (j=i;str[j]!='\0';j++)
	{    	s=str[j];
		b=(s-48)+(b*10);
		k*=10;
	}
	b=floor(a);
	c=(int)b/k;
	cout<<"\n\nYour Number is: "<<a<<"."<<c;
	getch();
	getch();
}