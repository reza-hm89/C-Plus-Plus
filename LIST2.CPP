#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
//===============================================
struct	listnode
{
	int data;
	listnode *next;
};
//===============================================
void Menu();
void Output(listnode*);
void Insert_List1(listnode*);
void Insert_List2(listnode*);
listnode* Merge(listnode*,listnode*);
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
void Output(listnode *start)
{
	clrscr();
	listnode *p;
	p=start;
	while (p!=NULL)
	{
		cout<<p->data<<"\t";
		p=p->next;
	}
	getch();
}
//===============================================
listnode* Merge(listnode *start1,listnode *start2)
{
	listnode *p1,*p2,*p3,*start3,*newnode;
	p1=start1;
	p2=start2;
	p3=start3;
	if (p1->data > p2->data)
	{
		p3=new listnode;
		p3=p2;
		start3=p3;
		p2=p2->next;
	}
	if (p1->data < p2->data)
	{
		p3=new listnode;
		p3=p1;
		start3=p3;
		p1=p1->next;
	}
	while (p1!=NULL && p2!=NULL)
	{
		if (p1->data<p2->data)
		{
			newnode=new listnode;
			newnode=p1;
			p3->next=newnode;
			p1=p1->next;
		}
		else if (p1->data>p2->data)
		{
			newnode=new listnode;
			newnode=p2;
			p3->next=newnode;
			p2=p2->next;
		}
		else if (p1->data == p2->data)
		{
			newnode=new listnode;
			newnode=p1;
			p3->next=newnode;
			p1=p1->next;
			p2=p2->next;
		}
		p3=p3->next;
	}
	while (p1!=NULL)
	{
		newnode=new listnode;
		newnode=p1;
		p3->next=newnode;
		p3=p3->next;
		p1=p1->next;
	}
	while (p2!=NULL)
	{
		newnode=new listnode;
		newnode=p2;
		p3->next=newnode;
		p3=p3->next;
		p2=p2->next;
	}
	clrscr();
	cout<<"List1 and List2 was Merged...";
	getch();
	return start3;
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
	listnode *node,*start3;
	clrscr();
	cout<<"\n\n1.Insert List 1";
	cout<<"\n\n2.Insert List 2";
	cout<<"\n\n3.Merge the List 1 & List 2";
	cout<<"\n\n4.Show List 1";
	cout<<"\n\n5.Show List 2";
	cout<<"\n\n6.Show Merge List";
	cout<<"\n\n7.Exit Program";
	cout<<"\n\nEnter Number Between (1..7): ";
	do {
		gotoxy(30,17);
		cout<<"         ";
		gotoxy(30,17);
		cin>>n;
	} while (n<1 || n>7);

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
				node=new listnode;
				node->data=x;
				node->next=NULL;
				Insert_List1(node);
			}
			break;
		case 2:
			clrscr();
			cout<<"Enter Numbers of List2: ";
			cin>>m;
			start2=NULL;
			for (i=0;i<m;i++)
			{
				cout<<"\nEnter Number "<<i+1<<": ";
				cin>>x;
				node=new listnode;
				node->data=x;
				node->next=NULL;
				Insert_List2(node);
			}
			break;
		case 3:
			start3=Merge(start1,start2);
			break;
		case 4:
			Output(start1);
			break;
		case 5:
			Output(start2);
			break;
		case 6: Output(start3);
			break;
		case 7: exit(0);
	}
	Menu();
}
//===============================================
