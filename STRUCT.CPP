#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
struct grade
	{
		int u[100],n[100];
	};
struct student
	{
		char name[20];
		long int id,sex,age;
		struct grade nomre;
	};
struct student st[100];
int ave[100],n,n1;
void average();
void average_boy();
void average_age();
void search();
void print();
void data();
void menu();
void main()
{
	menu();
	getch();
}

////////////////////////////////////////////////////////
void data()
{       int i,j,sum=0;
	clrscr();
	cout<<"Enter your data:";
	cout<<"\nEnter number of student:";
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cout<<"\nstudent "<<i;
		cout<<"\nname: ";
		cin>>st[i].name;
		cout<<"\nID: ";
		cin>>st[i].id;
		cout<<"\nSex:(1:male  0:famale) ";
		cin>>st[i].sex;
		cout<<"\nAge: ";
		cin>>st[i].age;
		cout<<"Enter number of dars: ";
		cin>>n1;
		for (j=1;j<=n1;j++)
		{
		cout<<"\ngrade & uint: ";
		cin>>st[i].nomre.n[j]>>st[i].nomre.u[j];
		sum+=(st[i].nomre.n[j])*(st[i].nomre.u[j]);
		}
		ave[i]=sum/n1;
		clrscr();
	}
	menu();
}
/////////////////////////////////////////////////////////////
void print()
{       int i,j;
	clrscr();
	for (i=1;i<=n;i++)
	{
		cout<<"\n\nstudent "<<i;
		cout<<"\n\nName: "<<st[i].name;
		cout<<"\nID "<<st[i].id;
		cout<<"\nSex: "<<st[i].sex;
		cout<<"\nAge: "<<st[i].age;
		for (j=1;j<=n1;j++)
		{	cout<<"\ngrade: "<<st[i].nomre.n[j];
			cout<<"\nuint: "<<st[i].nomre.u[j];
		}
	}
	getch();
	menu();
}
/////////////////////////////////////////////////////////////
void average()
{       int i;
	clrscr();
	for (i=1;i<=n;i++)
		if (ave[i]>16)
			cout<<st[i].name;
	getch();
	menu();
}
//////////////////////////////////////////////////////////////
void average_boy()
{       int i;
	clrscr();
	for (i=1;i<=n;i++)
		if (ave[i]>16 && st[i].sex==1)
			cout<<st[i].name;
	getch();
	menu();
}
/////////////////////////////////////////////////////////////
void search()
{       long int i,id;
	clrscr();
	cout<<"Enter your ID for serach:";
	cin>>id;
	for (i=1;i<=n;i++)
		if (id==st[i].id)
			cout<<"Name is this id: "<<st[i].name;
	getch();
	menu();
}
/////////////////////////////////////////////////////////////
void average_age()
{       int i,sum=0,age;
	clrscr();
	for (i=1;i<=n;i++)
		sum+=st[i].age;
	age=sum/n;
	cout<<"Average age of students is "<<age;
	getch();
	menu();
}
/////////////////////////////////////////////////////////////
void menu()
{       int s;
	clrscr();
	cout<<"1. Enter Your Data";
	cout<<"\n\n2. List of all students";
	cout<<"\n\n3. List of students with average > 16";
	cout<<"\n\n4. List of boys with Iaverage > 16";
	cout<<"\n\n5. Search student with ID";
	cout<<"\n\n6. Average of students with average";
	cout<<"\n\n7. Exit";
	cout<<"\n\nEnter Your Number:(1-7)";
	cin>>s;
		switch (s)
		{
		case 1: data();
		break;
		case 2: print();
		break;
		case 3: average();
		break;
		case 4: average_boy();
		break;
		case 5: search();
		break;
		case 6: average_age();
		break;
		default: exit(0);
		}
	 getch();
}
