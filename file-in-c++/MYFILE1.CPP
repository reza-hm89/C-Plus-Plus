#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
struct student {
	int state;
	char name[20];
	float avg;
	int id;
	}st;
void find(int);
void main()
{
	int fid;
	clrscr();
	ofstream fp("e:\\test.dat",ios::in | ios::out | ios::binary);
	while (1) {
		cin>>st.name;
		if (!st.name[0])
			break;
		cin>>st.avg;
		cin>>st.id;
		st.state=1;
		fp.seekp(sizeof(struct student)*st.id,ios::beg);
		fp.write((char *)&st,sizeof(struct student));
	}
	fp.close();
	cin.get();
	cout<<"Enter your id for search..\n";
	//fid=2;


	cin.get();
	cin>>fid;
	find(fid);
	getch();
}
void find(int fid) {
	fstream fp1("e:\\test.dat",ios::in | ios::out | ios::binary);
	fp1.seekg(sizeof(struct student)*fid,ios::beg);
	fp1.read((char *)&st,sizeof(struct student));
	cout<<st.name;
	fp1.close();
	getch();      }
