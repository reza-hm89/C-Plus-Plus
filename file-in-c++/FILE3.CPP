#include<iostream.h>
#include<conio.h>
#include<fstream.h>
 void main()
 {
	clrscr();
	char name[20];
	ofstream fp("e:\\test.dat",ios::binary);
	while(1)
	{
		cin>>name;
		if (!name[0]) break;
		fp<<name<<' ';
	}
	fp.close();
	cout<<"Output:\n";
	ifstream fp1("e:\\test.dat",ios::binary);
	fp1>>name;
	while (!fp1.eof())
	{
		cout<<name<<endl;
		fp1>>name;
	}
	fp1.close();
	getch();

 }