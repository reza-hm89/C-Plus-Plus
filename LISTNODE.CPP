#include<iostream.h>
#include<conio.h>
#include<string.h>

struct	listnode {
	char name[20];
	int data;
	listnode *next;
	};
class	linklist {
	listnode *start;
	public:
		linklist() { start=NULL; }
		~linklist();
		void create();
		void show();
	};
/////////////////////////////////////////
void linklist::create()
{
	char nam[20];
	int n;
	listnode *prev,*cur;
	listnode *newnode;
	newnode=new listnode;
	cout<<"Enter your id: ";
	cin>>n;
	newnode->data=n;
	cout<<"Enter your name: ";
	cin>>nam;
	strcpy(newnode->name,nam);
	if (!start)
	{
		start=newnode;
		start->next=NULL;
		return;
	}
	prev=NULL;
	cur=start;
	while (cur && cur->data<newnode->data)
	{
		prev=cur;
		cur=cur->next;
	}
	if (!prev)
	{
		newnode->next=start;
		start=newnode;
	}
	else {
		prev->next=newnode;
		newnode->next=cur;
	}

}
/////////////////////////////////////////
void linklist::show()
{
	while (start) {
		cout<<start->data<<"\t"<<start->name<<"\n";
		start=start->next;
		}
}
//////////////////////////////////////////
linklist::~linklist()
{
	listnode *cur;
	while (start)
	{
		cur=start;
		start=start->next;
		delete cur;
	}
}
/////////////////////////////////////////
void main()
{
	linklist list;
	clrscr();
	for (int i=0;i<2;i++)
		list.create();
	list.show();
	//~linklist();
	getch();
}