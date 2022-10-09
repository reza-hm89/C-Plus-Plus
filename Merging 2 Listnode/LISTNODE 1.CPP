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
void Merge();
void Sort(listnode*);
void Read1(int);
void Read2(int);
void Show(listnode*);
//===============================================
listnode *list1=NULL,*list2=NULL,*list3=NULL;
//===============================================
void Read1(int x)
{
	int n,i;
	listnode *p,*cur;
	p=list1;
	while (p->next!=NULL)
		p=p->next;
	if (list1==NULL)
	{
		p=new listnode();
		p->data=x;
		p->next=NULL;
		list1=p;
	}
	else
	{
		cur=new listnode();
		cur->data=x;
		cur->next=NULL;
		p->next=cur;
	}

}
//===============================================
void Read2(int x)
{
	int n,i;
	listnode *p,*cur;
	p=list2;

	while (p->next!=NULL)
		p=p->next;
	if (list2==NULL)
	{
		p=new listnode();
		p->data=x;
		p->next=NULL;
		list2=p;
	}
	else
	{
		cur=new listnode();
		cur->data=x;
		cur->next=NULL;
		p->next=cur;
	}

}

//===============================================
void Sort(listnode *list)
{
	listnode *p,*q;
	int temp;
	for (p=list;p!=NULL;p=p->next)
		for (q=p->next;q!=NULL;q=q->next)
			if (p->data>q->data)
				{
					temp=p->data;
					p->data=q->data;
					q->data=temp;
				}
}
//===============================================
void Show(listnode *list)
{
	clrscr();
	listnode *p;
	p=list;
	while (p!=NULL)
	{
		cout<<p->data<<"\n";
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
	clrscr();
	cout<<"\n\n1.Insert List 1";
	cout<<"\n\n2.Insert List 2";
	cout<<"\n\n3.Show Sorting List 1";
	cout<<"\n\n4.Show Sorting List 2";
	cout<<"\n\n5.Merge the List 1 & List 2";
	cout<<"\n\n6.Exit Program";
	cout<<"\n\nEnter Number Between (1..6): ";
	do {
		gotoxy(30,15);
		cout<<"         ";
		gotoxy(30,15);
		cin>>n;
	} while (n<1 || n>6);

	switch (n)
	{
		case 1:
			clrscr();
			cout<<"Enter Numbers of elements: ";
			cin>>m;
			list1=NULL;
			for (i=0;i<m;i++)
			{
				cout<<"\nEnter Number "<<i+1<<": ";
				cin>>x;
				Read1(x);
			}
			break;
		case 2:
			clrscr();
			cout<<"Enter Numbers of elements: ";
			cin>>m;
			list2=NULL;
			for (i=0;i<m;i++)
			{
				cout<<"\nEnter Number "<<i+1<<": ";
				cin>>x;
				Read2(x);
			}
			break;
		case 3: Sort(list1);
			Show(list1);
			break;
		case 4: Sort(list2);
			Show(list2);
			break;
		case 5: list3=NULL;
			Merge();
			break;
		case 6: exit(0);
	}
	Menu();
}
//===============================================
void Merge()
{
	clrscr();
	int sw;
	listnode *p1,*p2,*p3,*prev,*newnode;
	p1=list1;
	p2=list2;
	p3=list3;
	//2ta if braye sakhtane gere avale list3 ast
	if (p1->data > p2->data)
	{
		p3=new listnode;
		p3=p2;
		list3=p3;
		p2=p2->next;
	}
	if (p1->data < p2->data)
	{
		p3=new listnode;
		p3=p1;
		list3=p3;
		p1=p1->next;
	}
	//in halghe va3 sakhte list3 ast betori ke har gere meghdare
	//kamtari dashte bashad be list3 ezafe mishavad
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
	//in 2 halghe va3 ineke age ye list gerehash be list 3 
	//ezafe nashode bashe hamash ezafe mishe
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
	p3=list3;
	while (p3!=NULL)
	{
		cout<<p3->data<<"\t";
		p3=p3->next;
	}
	getch();
}