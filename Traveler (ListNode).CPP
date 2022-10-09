#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
//===============================================
struct	listnode
{
	int data;
	char name[20],family[20];
	listnode *next;
};
//===============================================
void Menu();
void Delete(listnode*);
void Output(listnode*);
void Insert_List1(listnode*);
void Insert_List2(listnode*);
//===============================================
listnode *start1,*start2;
//===============================================
void Insert_List1(listnode *newnode)
{
	listnode *prev,*cur;
	if (start1==NULL)
	{
		start1=newnode;
		start1->next=NULL;
		return;
	}
	prev=NULL;
	cur=start1;
	while (cur && cur->data < newnode->data)
	{
		prev=cur;
		cur=cur->next;
	}
	if (prev==NULL)
	{
		newnode->next=start1;
		start1=newnode;
	}
	else
	{
		prev->next=newnode;
		newnode->next=cur;
	}
	return;
}
//===============================================
void Insert_List2(listnode *newnode)
{
	listnode *prev,*cur;
	if (start2==NULL)
	{
		start2=newnode;
		start2->next=NULL;
		return;
	}
	prev=NULL;
	cur=start2;
	while (cur && cur->data < newnode->data)
	{
		prev=cur;
		cur=cur->next;
	}
	if (prev==NULL)
	{
		newnode->next=start2;
		start2=newnode;
	}
	else
	{
		prev->next=newnode;
		newnode->next=cur;
	}
	return;
}
//===============================================
void Delnode(listnode *delnode)
{
	listnode *cur=start1 , *prev=NULL ,*node;

	while (cur && cur->data!=delnode->data)
	{
		prev=cur;
		cur=cur->next;
	}
	if( !cur )
	{
		cout<<"List is empty !";
		getch() ;
		return ;
	}
	if (!prev)
		start1=start1->next;
	else
		prev->next=cur->next;

	node=new listnode;
	node->data=cur->data;
	strcpy(node->name,cur->name);
	strcpy(node->family,cur->family);

	Insert_List2(node);

	delete cur;
	cout<<"Deleted...";
	getch();
}
//===============================================
void Output(listnode *start)
{
	clrscr();
	listnode *p;
	p=start;
	while (p!=NULL)
	{
		cout<<p->data<<"\t"<<p->name<<"\t"<<p->family<<"\n";
		p=p->next;
	}
	getch();
}
//===============================================
void main()
{
	Menu();
}
//===============================================
void Menu()
{
	int n,m,i,x;
	char name[20],family[20];
	listnode *node,*start3;
	clrscr();
	cout<<"\n1.Insert Data";
	cout<<"\n\n2.Delete Data";
	cout<<"\n\n3.Show List 1";
	cout<<"\n\n4.Show List 2";
	cout<<"\n\n5.Exit Program";
	cout<<"\n\nEnter Number Between (1..5): ";
	do {
		gotoxy(30,12);
		cout<<"         ";
		gotoxy(30,12);
		cin>>n;
	} while (n<1 || n>5);

	switch (n)
	{
		case 1:
			clrscr();
			cout<<"Enter Numbers of List1: ";
			cin>>m;
			start1=NULL;
			for (i=0;i<m;i++)
			{
				cout<<"\nEnter Number "<<i+1<<": ";
				cin>>x;
				cout<<"\nEnter Name "<<i+1<<": ";
				cin>>name;
				cout<<"\nEnter Family "<<i+1<<": ";
				cin>>family;
				node=new listnode;
				node->data=x;
				strcpy(node->name,name);
				strcpy(node->family,family);
				node->next=NULL;
				Insert_List1(node);
			}
			break;
		case 2:
				clrscr();
				cout<<"\nEnter Number : ";
				cin>>x;
				node=new listnode;
				node->data=x;
				Delnode(node);
			break;
		case 3:
			Output(start1);
			break;
		case 4:
			Output(start2);
			break;
		case 5: exit(0);
	}
	Menu();
}