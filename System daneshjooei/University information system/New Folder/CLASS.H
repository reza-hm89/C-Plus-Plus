#ifndef	CLASS2.H
#define  CLASS2.H

#if !defined FSTREAM_H
#define FSTREAM_H
#include<fstream.h>
#endif

#if !defined STDIO_H
#define 	STDIO_H
#include<stdio.h>
#endif

ofstream fout;
ofstream f1;
ofstream f2;
class student
{
	public:
	char name[40];
	char gender[6];
	char age[10];
	char dep[10];
	char id[20];
	char sem_n[10];
	public:
	void get()
	{
	  fout.open("st.doc",ios::app);
	  cout<<"Enter name ";gets(name);
	  fout<<name<<"\n";
	  cout<<"Enter gender "; cin>>gender;
	  fout<<gender<<"\n";
	  cout<<"Enter age "; cin>>age;
	  fout<<age<<"\n";
	  cout<<"Enter depertment "; cin>>dep;
	  fout<<dep<<"\n";
	  cout<<"Enter id no ";gets(id);
	  fout<<id<<"\n";
	  cout<<"Enter semister no ";cin>>sem_n;
	  fout<<sem_n<<"\n";
	  fout.close();
	}
	void display()
	{
	  cout<<"\n"<<" Name : "<<name<<"  Gender : "<<gender
	  <<"  age : "<<age<<"  depertment : "<<dep<<"\n"<<
	  "id "<<id<<"\n"<<"semister no "<<sem_n<<"\n";
	}
};
// 							TEACHER CLASS
class teacher
{
	public:
	char name[40];
	char gender[10];
	char age[10];
	char dep[10];
	char salary[10];
	char des[40];
	char tele[30];
	public:
	void get()
	{
		f1.open("tea.doc",ios::app);
		cout<<"Enter name ";gets(name);
		f1<<name<<"\n";
		cout<<"Enter gender "; cin>>gender;
		f1<<gender<<"\n";
		cout<<"Enter age "; cin>>age;
		f1<<age<<"\n";
		cout<<"Enter depertment "; cin>>dep;
		f1<<dep<<"\n";
		cout<<"Enter salary ";
		cin>>salary;
		f1<<salary<<"\n";
		cout<<"Enter designation ";
		gets(des);
		f1<<des<<"\n";
		cout<<"Enter telephone number ";
		gets(tele);
		f1<<tele<<"\n";
		f1.close();
	}
	void display()
	{
		cout<<"\n"<<" Name : "<<name<<"  Gender : "<<gender
	  <<"  age : "<<age<<"  depertment : "<<dep<<"\n"<<
		" Salary : "<<salary<<" Designation : "<<des<<
		" Telephone no : "<<tele<<"\n";
	}
};
//								EMPLOYE CLASS
class employe
{
	public:
	char name[40],gender[10],age[10],work_y[10];
	char title[15];
	char salary[10];
	virtual void get(char *fn)
	{
		f2.open(fn,ios::app);
		cout<<"Enter name";gets(name);
		f2<<name<<"\n";
		cout<<"Your gender";cin>>gender;
		f2<<gender<<"\n";
		cout<<"your age";cin>>age;
		f2<<age<<"\n";
		cout<<"Working time";gets(work_y);
		f2<<work_y<<"\n";
		cout<<"Enter title ";
		cin>>title;
		f2<<title<<"\n";
		cout<<"Enter salary ";
		cin>>salary;
		f2<<salary<<"\n";
		//f2<<name<<"\n"<<gender<<"\n"<<age<<"\n"<<work_y<<"\n"<<title<<"\n"<<title<<"\n">>salary>>"\n";
		f2.close();
	}
	void display()
	{
		cout<<"\nName "<<name<<" gender "<<gender<<" age "<<age<<"\n"
		<<"Working time "<<work_y;
		cout<<"  Title  "<<title<<" Salary : "<<salary<<"\n";
	}

};
//									 ACCOUNT EMPLOYE CLASS
class account:public employe
{
public:
void get()
  {
	employe::get("Acc.doc");
  }
};
//									 LIBRARY EMPLOYE CLASS
class library:public employe
{
public:
void get()
  {
	employe::get("Lib.doc");
  }

};
//									 SECURITY EMPLOYE CLASS
class security:public employe
{
	public:
	void get()
	{
		employe::get("sec.doc");
	}
};
#endif