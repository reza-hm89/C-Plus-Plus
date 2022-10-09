#include<iostream.h>
#include<conio.h>
#include<fstream.h>
 void main()
 {
	clrscr();
	char ch;
	ofstream fp("e:\\test.dat");
	ch=getch();
	while(ch!='z')
	{
		fp.put(ch);
		ch=getch();
	}
	fp.close();
	cout<<"Output:\n";
	ifstream fp1("e:\\test.dat");
	fp1.get(ch);
	while (!fp1.eof())
	{
		cout<<ch;
		fp1.get(ch);
	}
	fp1.close();
	getch();

 }