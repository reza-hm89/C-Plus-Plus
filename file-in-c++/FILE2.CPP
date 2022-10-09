#include<iostream.h>
#include<conio.h>
#include<fstream.h>
 void main()
 {
	clrscr();
	char ch;
	ofstream fp("e:\\test.dat",ios::binary);
	ch=getch();
	while(ch!='\r')
	{
		fp.put(ch);
		ch=getche();
	}
	fp.close();
	cout<<"Output:\n";
	ifstream fp1("e:\\test.dat",ios::binary);
	fp1.get(ch);
	while (!fp1.eof())
	{
		cout<<ch;
		fp1.get(ch);
	}
	fp1.close();
	getch();

 }