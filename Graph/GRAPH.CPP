#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
int a1[100];
int m_hj[20][20];
int m_vbt[20][20];
char m_yal[20][2];
void draw();
void draw()
{
	cleardevice();
	int n;
	int a[2][20];
	int i=0,j,index,s1;
	char c[17]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q'};
	a[0][0]=250; a[0][1]=195; a[0][2]=225; a[0][3]=285;
	a[1][0]=250; a[1][1]=210; a[1][2]=130; a[1][3]=70;
	a[0][4]=340; a[0][5]=395; a[0][6]=450; a[0][7]=500;
	a[1][4]=50;  a[1][5]=48; a[1][6]=60; a[1][7]=90;
	a[0][8]=530; a[0][9]=550; a[0][10]=555;a[0][11]=540;
	a[1][8]=130; a[1][9]=180; a[1][10]=230;a[1][11]=288;
	a[0][12]=500;a[0][13]=440;a[0][14]=365;a[0][15]=305;
	a[1][12]=350;a[1][13]=390;a[1][14]=405;a[1][15]=390;
	a[0][16]=250;a[0][17]=210;
	a[1][16]=350;a[1][17]=300;
	setbkcolor(15);
	setcolor(8);
	outtextxy(10,10,"Enter number of Vertex:");
	rectangle(200,13,230,33);
	do {
	gotoxy(27,2);
	cin>>n;
	} while (n>17);
	randomize();
	i=0;
	while (i<n)
	{
		index=0;
		s1=random(18);
		for (j=0;j<n;j++)
			if (s1==a1[j])
				index=1;
		if (index==0)
		{
			a1[i]=s1;
			i++;
		}
	}
	char s={'a'};
	char *p;
	settextstyle(6,0,1);
	p=&s;
	for (i=0;i<n;i++)
	{
		s='a'+i;
		c[i]=s;
		outtextxy(a[0][a1[i]],a[1][a1[i]],"Û");
		outtextxy(a[0][a1[i]]-8,a[1][a1[i]]-15,p);
		(*p)++;
	}
	settextstyle(2,0,5);
	gotoxy(10,10);
	outtextxy(10,20,"Enter your Edge: ");
	char ch,ch1,ans='y';
	int k=0,index1=0,index2,cntr=0;
	char yal[100];
	while (ans=='y')
	{
	setfillstyle(1,15);
	bar (1,35,235,115);
	rectangle(27,47,44,65);
	rectangle(75,47,93,65);
	outtextxy(7,50,"->");
	index=0;
	do {
	gotoxy(5,4);
	ch=getch();
	cout<<ch;
	for (i=0;i<n;i++)
		if (ch==c[i])
			index=1;
	} while (index!=1);
	setfillstyle(1,15);
	bar(5,50,20,63);
	outtextxy(55,50,"->");
	index=0;
	do {
	gotoxy(11,4);
	ch1=getch();
	cout<<ch1;
	for (i=0;i<n;i++)
		if (ch1==c[i])
			index=1;
	} while (index!=1);
	yal[k]=ch;
	yal[k+1]=ch1;
	yal[k+2]=' ';
	k+=3;
	cntr++;
	for (i=0;i<n;i++)
	{
		index2=0;
		if (ch==c[i])
			index=i;
		if (ch1==c[i])
			index1=i;
		if (ch1==ch)
			index2=1;
	}
	line(a[0][a1[index]]+8,a[1][a1[index]]+15,a[0][a1[index1]]+8,a[1][a1[index1]]+15);
	if (index2==1)
		circle(a[0][a1[index]]+5,a[1][a1[index]]+15,10);
	outtextxy(10,70,"Do you want to continue(y/n)?");
	rectangle(40,95,60,115);
	gotoxy(7,7);
	ans=getch();
	cout<<ans;
	getch();
	}
	delay(1000);
	for (i=0;i<640;i++)
		for (j=0;j<480;j++)
			putpixel(i,j,15);
	restorecrtmode();
	clrscr();
	i=0;
	int index3,index4;
	int x,y;
	gotoxy(1,1);
	cout<<"Matrix hamjavari";
	while (i<k)
	{
		index3=index4=0;
		for (j=0;j<n;j++)
		{
			if (c[j]==yal[i])
			{
				index=j;
				index3=1;
			}
		}
		for (j=0;j<n;j++)
		{
			if (c[j]==yal[i+1])
			{
				index1=j;
				index4=1;
			}
		}
		i+=3;
		if (index3==1 && index4==1)
			m_hj[index][index1]=1;
	}
	gotoxy(1,3);
	x=1; y=3;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			cout<<m_hj[i][j];
			gotoxy(x+=3,y);
		}
		gotoxy(x=1,y+=2);
	}
	gotoxy(25,1);
	cout<<"Matrix yalha";
	j=0;
	y=3;
	for (i=0;i<k;i+=3)
	{
		m_yal[j][0]=yal[i];
		m_yal[j][1]=yal[i+1];
		j++;
	}
	gotoxy(30,3);
	for (i=0;i<n;i++)
	{
		cout<<(char)m_yal[i][0]<<(char)m_yal[i][1];
		gotoxy(30,y+=2);
	}
	gotoxy(50,1);
	cout<<"Matrix vabastegi";
	j=0;
	x=50; y=3;
	for (i=0;i<=k;i++)
	{
		if (yal[i]==' ')
			j++;
		else if (yal[i]==c[0] && yal[i+1]!=c[0])
			index=i+1;
		m_vbt[i][j]=1;
	}
	gotoxy(50,3);
	for (i=0;i<n;i++)
	{
		for (j=0;j<cntr;j++)
		{
			cout<<m_vbt[i][j];
			gotoxy(x+=3,y);
		}
		gotoxy(x=50,y+=2);
	}
	for (i=0;i<k;i++)
	{
		index=0;
		for (j=0;j<n;j++)
			if (c[j]==yal[i])
				index=1;
		if (index==0)
		{
			outtextxy(10,200,"Graph Hamband nist");
			break;
		}
	}
	if (index)
		outtextxy(10,200,"Graph Hamband ast");


}
void main()
{
	int d=0,m=0;
	initgraph(&d,&m,"c:\\tc\\bgi");
	draw();
	getch();
}