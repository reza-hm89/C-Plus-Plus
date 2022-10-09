#include<iostream.h>
#include<conio.h>
#include<fstream.h>
 void main()
 {
	clrscr();
	char name[20];
	float avg;
	ofstream fp("e:\\test.dat",ios::binary);
	while(1)
	{
		cin>>name>>avg;
		if (!name[0]) break;
		fp<<name<<' '<<avg<<' ';
	}
	fp.close();
	cout<<"Output:\n";
	ifstream fp1("e:\\test.dat",ios::binary);
	float i=0,sum=0;
	while (!fp1.eof())
	{
		fp1>>name;
		cout<<name<<endl;
		fp1>>avg;
		sum+=avg;
		i++;
	}
	cout<<sum/i;
	fp1.close();
	getch();

 }