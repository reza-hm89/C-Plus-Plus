#include<iostream.h>
#include<conio.h>
#include<fstream.h>
struct	student {
	char name[20];
	float avg;
	int id;
	}std;
void main()
{
	clrscr();
	ofstream fp("e:\\test.dat",ios::binary);
	while(1)
	{
		cin>>std.name;
		if (!std.name[0]) break;
		cin>>std.avg>>std.id;
		fp.write((char *)&std,sizeof(struct student));
	}
	fp.close();
	cout<<"\nOutput:\n";
	ifstream fp1("e:\\test.dat",ios::binary);
	while (!fp1.eof())
	{
		fp1.read((char *)&std,sizeof(struct student));
		cout<<std.name<<' '<<std.id;
	}
	fp1.close();
	getch();

 }