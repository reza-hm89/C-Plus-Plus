#include<iostream.h>
#include<conio.h>
void main()
{
	int i=0,j=1;
	char ch;
	clrscr();
	cout<<"Enter your statement(Press ENTER to end):\n";
	while((ch=getche())!='\r')
	{
		i++;
		if (ch==' ')
			j++;
	}
	cout<<"\nNumbers of ccharacters: "<<i;
	cout<<"\nNumbers of words: "<<j;
	getch();
}