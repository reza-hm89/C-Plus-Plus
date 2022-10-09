#include<iostream.h>
#include<conio.h>
#include<string.h>
struct dars {
	int id;
	char name[20];
	dars *nextdars;
	};
struct student {
	int id;
	char name[20];
	student *next;
	dars	*startdars;
	};
class listnode {
	student *start;
       //	dars	*startdars;
	public:
		listnode() { start=NULL; }//startdars=NULL;}
		void add_student();
		void add_dars();
		void show_st();
		void show_dars();
	};
////////////////////////////////////////
void listnode::add_student()
{
	int id,td;
	char name[20];
	student *cur,*prev;
	student *newnode;
	newnode=new student;
	cout<<"Enter your id: ";
	cin>>id;
	newnode->id=id;
	cout<<"Enter your name: ";
	cin>>name;
	strcpy(newnode->name,name);
	cout<<"Enter number of dars: ";
	cin>>td;
	for (int i=0;i<td;i++)
		add_dars();
	if(!start)
	{
		start=newnode;
		start->next=NULL;
		return;
	}
	prev=NULL;
	cur=start;
	while (cur) {
		prev=cur;
		cur=cur->next;
	}
	if (!prev) {
		newnode->next=start;
		start=newnode;
	}
	else {
		prev->next=newnode;
		newnode->next=cur;
	}

}
//////////////////////////////////////////
void listnode::add_dars()
{
	int id;
	char name[20];
	startdars=NULL;
	dars *cur,*prev;
	dars *newnode;
	newnode=new dars;
	cout<<"Enter book id: ";
	cin>>id;
	newnode->id=id;
	cout<<"Enter name dars: ";
	cin>>name;
	strcpy(newnode->name,name);
	if(!startdars)
	{
		startdars=newnode;
		startdars->nextdars=NULL;
		return;
	}
	prev=NULL;
	cur=startdars;
	while (cur) {
		prev=cur;
		cur=cur->nextdars;
	}
	if (!prev) {
		newnode->nextdars=startdars;
		startdars=newnode;
	}
	else {
		prev->nextdars=newnode;
		newnode->nextdars=cur;
	}

}

/////////////////////////////////////////
void listnode::show_st()
{
	while (start) {
		cout<<start->id<<"  "<<start->name<<"\n";
		while (startdars)
		cout<<"  "<<startdars->id<<"  "<<startdars->name;
		start=start->next;
	}
}
////////////////////////////////////////
void main()
{
	clrscr();
	listnode list;
	int n,i;
	cout<<"Enter Number of student: ";
	cin>>n;
	for (i=0;i<n;i++) {
		list.add_student();
	}
	list.show_st();
	getch();
}