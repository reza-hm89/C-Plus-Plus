#include<graphics.h>
#include<conio.h>
#include<iostream.h>
#include<stdio.h>
#include<dos.h>

int a[8][8]={{12,11,0,0,0,0,21,22},{13,11,0,0,0,0,21,23}
,{14,11,0,0,0,0,21,24},{15,11,0,0,0,0,21,25},{16,11,0,0,0,0,21,26},
{14,11,0,0,0,0,21,24},{13,11,0,0,0,0,21,23},{12,11,0,0,0,0,21,22}};

int b[8][8]={{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};

void fill_move(int,int);
void asb_move(int,int);
void rook_move(int,int);
void sarbaz_move(int,int);
void sarbaz(int,int,int);
void rook(int,int,int);
void fill(int,int,int);
void asb(int,int,int);
void vazir(int,int,int);
void king(int,int,int);
void move();
void draw(int x,int y);
void insert_move(int,int);
void insert(int,int,int,int,int);
void clear(int k,int x,int z,int y,int p);
void board();
/////////////////////////////////////////////////////////////////////
void main()
{       int driver=DETECT,mode;
	int x=15,y=59;
	clrscr();
	initgraph(&driver,&mode,"c:\\tc\\bgi");
	setbkcolor(0);
	board();
	draw(x,y);
	move();
	getch();
	closegraph();
}
/////////////////////////////////////////////////////////////////////
void board()	// Board of Chess//
{       int s,i,j,n=50,m=50,x=8,z=7,k;
	char ch;

	while (m<450)
	{       n=50;
		x=z+x;
		z=x-z;
		x=x-z;
		while (n<450)
	{
		for (i=n;i<=n+50;i++)
		{
			for(j=m;j<=m+50;j++)
				putpixel(i,j,x);
		}
		x=z+x;
		z=x-z;
		x=x-z;
		n+=50;
	}
		m+=50;
	}
	setcolor(7);
	rectangle(50,50,450,450);
	setcolor(8);
	rectangle(49,49,451,451);
	setcolor(7);
	rectangle(48,48,452,452);
	settextstyle(4,0,1);
	outtextxy(72,22,"1");outtextxy(122,22,"2");outtextxy(172,22,"3");
	outtextxy(222,22,"4");outtextxy(272,22,"5");outtextxy(322,22,"6");
	outtextxy(372,22,"7");outtextxy(422,22,"8");
	settextstyle(7,0,1);
	outtextxy(20,64,"A");outtextxy(20,114,"B");outtextxy(20,164,"C");
	outtextxy(20,214,"D");outtextxy(20,264,"E");outtextxy(20,314,"F");
	outtextxy(20,364,"G");outtextxy(20,414,"H");
	// kadre 1//
	setcolor(4);
	rectangle(499,15,605,71);
	rectangle(498,14,606,72);
	setcolor(12);
	rectangle(497,13,607,73);
	rectangle(496,12,608,74);
	for (i=500;i<605;i++)
		for (j=16;j<71;j++)
			putpixel(i,j,7);
	setcolor(8);
	settextstyle(0,0,1);
	setusercharsize(1, 1, 1, 1);
	outtextxy(501,24,"Current Match");
	setcolor(15);
	outtextxy(530,40,"white");
	// end kadre 1//
	// kadre 2//
	outtextxy(475,85,"Player White");
	setcolor(12);
	rectangle(470,95,625,278);
	rectangle(471,96,624,277);
	setcolor(4);
	rectangle(472,97,623,276);
	rectangle(473,98,622,275);
	for (i=474;i<=621;i++)
		for (j=99;j<=274;j++)
			putpixel(i,j,7);
	// end kadre 2//
	//kadre 3//
	setcolor(15);
	outtextxy(475,286,"Player Black");
	setcolor(12);
	rectangle(470,297,625,478);
	rectangle(471,298,624,477);
	setcolor(4);
	rectangle(472,299,623,476);
	rectangle(473,300,622,475);
	for (i=474;i<=621;i++)
		for (j=301;j<=474;j++)
			putpixel(i,j,7);
	//end kadre 3//
	//End Board of Chess//
}
//////////////////////////////////////////////////////////////////////
void move()
{	// Move /////////////
	int player1=1,player2=2,color,f,g,q,w,e,r,t,temp;
	int enter=0,p=7,o=8,c=12,y,x,i,j,k,z,s;
	int row,col;
	setcolor(c);
	rectangle(50,50,100,100);
	s=getch();
	i=j=0;
	x=50;
	y=100;
	k=50;
	z=100;
	while(s!=27)
	{
	s=getch();
	if (s==72)
	{
		if (enter==1)
		{       setcolor(12);
			rectangle(q+1,w+1,e-1,r-1);
		}
		temp=p;
		p=o;
		o=temp;
		setcolor(7);
		rectangle(k,x,z,y);
		x-=50;
		y-=50;
		if (y<=50 || x<50)
		{
			y=450;
			x=400;
		}
		setcolor(c);
		rectangle(k,x,z,y);

		j--;
		if (j<0)	j=7;

	}
	else if (s==80)
	{
		if (enter==1)
		{       setcolor(12);
			rectangle(q+1,w+1,e-1,r-1);
		}
		temp=p;
		p=o;
		o=temp;
		setcolor(7);
		rectangle(k,x,z,y);
		x+=50;
		y+=50;
		if (y>450 || x>400)
		{
			y=100;
			x=50;
		}
		setcolor(c);
		rectangle(k,x,z,y);

		j++;
		if (j>7)	j=0;

	}
	else if (s==77)
	{
		if (enter==1)
		{       setcolor(12);
			rectangle(q+1,w+1,e-1,r-1);
		}

		temp=p;
		p=o;
		o=temp;
		setcolor(7);
		rectangle(k,x,z,y);
		k+=50;
		z+=50;
		if (z>450 || k>400)
		{
			k=50;
			z=100;
		}
		setcolor(c);
		rectangle(k,x,z,y);
		i++;
		if (i>7)	i=0;

	}
	else if (s==75)
	{
		if (enter==1)
		{       setcolor(12);
			rectangle(q+1,w+1,e-1,r-1);
		}
		temp=p;
		p=o;
		o=temp;
		setcolor(7);
		rectangle(k,x,z,y);
		k-=50;
		z-=50;
		if (z<100 || k<50)
		{
			k=400;
			z=450;
		}
		setcolor(c);
		rectangle(k,x,z,y);
		i--;
		if (i<0)	i=7;

	}
	else if (s==13 && (a[i][j]!=0 && a[i][j]/10==player1) && c==12)
	{
		for (row=0;row<=7;row++)
			for (col=0;col<=7;col++)
				b[row][col]=0;
		enter=1;
		f=i; g=j;
		temp=player1;
		player1=player2;
		player2=temp;
		setcolor(58);
		rectangle(k,x,z,y);
		c=58;
		q=k; w=x; e=z; r=y; t=p;
		insert_move(f,g);
	}
	else if (s==13 && c==58)
	{
		c=12;
		enter=0;
		setcolor(c);
		if (b[i][j]!=0)
		{
				clear(q,w,e,r,t);
				if (a[f][g]/10==1) color=15;
				else if(a[f][g]/10==2) color=0;
				clear(k,x,z,y,p);
				insert(k,x,f,g,color);
				a[i][j]=a[f][g];
				a[f][g]=0;
		if (player1==1)
		{       setfillstyle(1,7);
			bar(505,39,598,67);
			setcolor(15);
			outtextxy(530,40,"white");
		}
		else
		{       setfillstyle(1,7);
			bar(505,39,598,67);
			setcolor(0);
			outtextxy(530,40,"black");
		}
		}
		else
		{
			for (row=0;row<=7;row++)
				for (col=0;col<=7;col++)
					b[row][col]=0;
			setcolor(t);
			rectangle(q+1,w+1,e-1,r-1);
			temp=player1;
			player1=player2;
			player2=temp;
			setcolor(12);
			outtextxy(502,57,"Invalid move!");
			cout<<"\a";
			delay(1000);
			setfillstyle(1,7);
			bar(503,55,604,67);
		}
		setcolor(12);
		rectangle(k,x,z,y);
	}
	}
}	//End of Move /////////////
///////////////////////////////////////////////////////////////////////
void clear(int k,int x,int z,int y,int t )
{       int i,j;
	for (i=k+1;i<z;i++)
		for (j=x+1;j<y;j++)
			putpixel(i,j,t);
}
///////////////////////////////////////////////////////////////////////
void insert(int k,int x,int f,int g,int color)
{
	if (a[f][g]==11)
		sarbaz(k-35,x-41,color);
	else if (a[f][g]==21)
		sarbaz(k-35,x-41,color);
	else if (a[f][g]==12)
		rook(k-37,x-37,color);
	else if (a[f][g]==22)
		rook(k-37,x-37,color);
	else if (a[f][g]==13)
		asb(k-30,x-37,color);
	else if (a[f][g]==23)
		asb(k-30,x-37,color);
	else if (a[f][g]==14)
		fill(k-30,x-37,color);
	else if (a[f][g]==24)
		fill(k-30,x-37,color);
	else if (a[f][g]==15)
		king(k-30,x-37,color);
	else if (a[f][g]==25)
		king(k-30,x-37,color);
	else if (a[f][g]==16)
		vazir(k-30,x-37,color);
	else if (a[f][g]==26)
		vazir(k-30,x-37,color);

}
////////////////////////////////////////////////////////////////////////
void insert_move(int f,int g)
{
	if (a[f][g]==11 || a[f][g]==21)
		sarbaz_move(f,g);
	else if (a[f][g]==12 || a[f][g]==22)
		rook_move(f,g);
	else if (a[f][g]==13 || a[f][g]==23)
		asb_move(f,g);
	else if (a[f][g]==14 || a[f][g]==24)
		fill_move(f,g);
      /*	else if (a[f][g]==15)
		king(k-30,x-37,color);
	else if (a[f][g]==25)
		king(k-30,x-37,color);
	else if (a[f][g]==16)
		vazir(k-30,x-37,color);
	else if (a[f][g]==26)
		vazir(k-30,x-37,color); */

}
////////////////////////////////////////////////////////////////////////
void fill_move(int f,int g)
{       int i,j;
	for (i=f+1,j=g+1;i<=7,g<=7;i++,j++)
		if (a[i][j]/10!=a[f][g]/10)
			b[i][j]=1;
	for (i=f+1,j=g-1;i<=7,g>=0;i++,j--)
		if (a[i][j]/10!=a[f][g]/10)
			b[i][j]=1;
	for (i=f-1,j=g-1;i>=0,g>=0;i--,j--)
		if (a[i][j]/10!=a[f][g]/10)
			b[i][j]=1;
	for (i=f-1,j=g+1;i>=0,g<=7;i--,j++)
		if (a[i][j]/10!=a[f][g]/10)
			b[i][j]=1;
}
////////////////////////////////////////////////////////////////////////
void rook_move(int f,int g)
{       int i,j,m=0,w,q,cntr=1;
	for (i=f+1;i<=7;i++)
	{	if (a[i][g]==0 && m==0)
			b[i][g]=1;
		else if (a[i][g]/10==a[f][g]/10 || a[i][g]!=0)
			{	m=1;
			 if (cntr==1)
			 {	q=i;
				w=g;
			 }
			 cntr++;
			}
		if (a[q][w]/10!=a[f][g]/10)
			b[q][w]=1;
	}
	m=0;
	cntr=1;
	for (i=f-1;i>=0;i--)
	{	if(a[i][g]==0 && m==0)
			b[i][g]=1;
		else if (a[i][g]/10==a[f][g]/10 || a[i][g]!=0)
			{	m=1;
			 if (cntr==1)
			 {	q=i;
				w=g;
			 }
			 cntr++;
			}
		if (a[q][w]/10!=a[f][g]/10)
			b[q][w]=1;
	}
	m=0;
	cntr=1;
	for (i=g+1;i<=7;i++)
	{
		if(a[f][i]==0  && m==0)
			b[f][i]=1;
		else if (a[f][i]/10==a[f][g]/10 || a[f][i]!=0)
			{	m=1;
			 if (cntr==1)
			 {	q=f;
				w=i;
			 }
			 cntr++;
			}
		if (a[q][w]/10!=a[f][g]/10)
			b[q][w]=1;
	}
	m=0;
	cntr=1;
	for (i=g-1;i>=0;i--)
	{	if(a[f][i]==0 && m==0)
			b[f][i]=1;
		else if (a[f][i]/10==a[f][g]/10 || a[f][i]!=0)
			{	m=1;
			 if (cntr==1)
			 {	q=f;
				w=i;
			 }
			 cntr++;
			}
		if (a[q][w]/10!=a[f][g]/10)
			b[q][w]=1;
	}
}
////////////////////////////////////////////////////////////////////////
void asb_move(int f,int g)
{       int i,j;
	   i=f+2; j=g+1;
	   if (i>=0 || i<=7 || j>=0 || j<=7)
		if  (a[i][j]/10!=a[f][g]/10)
			b[i][j]=1;
	   j=g-1;
	   if (i>=0 || i<=7 || j>=0 || j<=7)
		if  (a[i][j]/10!=a[f][g]/10)
			b[i][j]=1;
	   i=f-2; j=g+1;
	   if (i>=0 || i<=7 || j>=0 || j<=7)
		if  (a[i][j]/10!=a[f][g]/10)
			b[i][j]=1;
	   j=g-1;
	   if (i>=0 || i<=7 || j>=0 || j<=7)
		if  (a[i][j]/10!=a[f][g]/10)
			b[i][j]=1;
	   i=f+1; j=g+2;
	   if (i>=0 || i<=7 || j>=0 || j<=7)
		if  (a[i][j]/10!=a[f][g]/10)
			b[i][j]=1;
	   i=f-1;
	   if (i>=0 || i<=7 || j>=0 || j<=7)
		if  (a[i][j]/10!=a[f][g]/10)
			b[i][j]=1;
	   i=f+1; j=g-2;
	   if (i>=0 || i<=7 || j>=0 || j<=7)
		if  (a[i][j]/10!=a[f][g]/10)
			b[i][j]=1;
	   i=f-1;
	   if (i>=0 || i<=7 || j>=0 || j<=7)
		if  (a[i][j]/10!=a[f][g]/10)
			b[i][j]=1;

}
////////////////////////////////////////////////////////////////////////
void sarbaz_move(int f,int g)
{
	if (a[f][g]==11)
	{
		if(g==1)
			if (a[f][g+1]==0 && a[f][g+2]==0)
			{	b[f][g+1]=1;
				b[f][g+2]=1;
			}
		if (a[f][g+1]==0)
			b[f][g+1]=1;
		if (a[f+1][g+1]/10==2)
			b[f+1][g+1]=1;
		if (a[f-1][g+1]/10==2)
			b[f-1][g+1]=1;
	}
	else if (a[f][g]==21)
	{
		if(g==6)
			if (a[f][g-1]==0 && a[f][g-2]==0)
			{
				b[f][g-1]=1;
				b[f][g-2]=1;
			}
		if (a[f][g-1]==0)
			b[f][g-1]=1;
		if (a[f-1][g-1]/10==1)
			b[f-1][g-1]=1;
		if (a[f+1][g-1]/10==1)
			b[f+1][g-1]=1;
	}
}
///////////////////////////////////////////////////////////////////////
void sarbaz(int x,int y,int c)
{
	setcolor(c);
	setfillstyle(1,c);
	fillellipse(x+60,y+56,9,9);
	int a[22]={x+50,y+65,x+70,y+65,x+65,y+70,x+65,y+81,x+77,y+86,
	x+77,y+88,x+43,y+88,x+43,y+86,x+55,y+81,x+55,y+70,x+50,y+65};
	drawpoly(11,a);
	fillpoly(11,a);
}

////////////////////////////////////////////////////////////////////////
void rook(int x,int y,int c)
{
	setcolor(c);
	setfillstyle(1,c);
	int rook[42]={45+x,45+y,50+x,45+y,50+x,50+y,60+x,50+y,60+x,45+y
	,65+x,45+y,65+x,50+y,75+x,50+y,
	75+x,45+y,80+x,45+y,80+x,57+y,68+x,57+y,
	68+x,79+y,80+x,81+y,80+x,84+y
	,45+x,84+y,45+x,81+y,57+x,79+y
	,57+x,57+y,45+x,57+y,45+x,45+y};
	drawpoly(21,rook);
	fillpoly(21,rook);
}
///////////////////////////////////////////////////////////////////////
void fill(int x,int y,int c)
{
	setcolor(c);
	setfillstyle(1,c);
	fillellipse(55+x,42+y,3,3);
	fillellipse(55+x,53+y,6,8);
	line(46+x,60+y,64+x,60+y);
	line(46+x,62+y,64+x,62+y);
	int fill[18]={50+x,60+y,60+x,60+y,62+x,78+y,73+x,82+y,73+x,84+y
	,37+x,84+y,37+x,82+y,48+x,78+y,50+x,60+y};
	drawpoly(9,fill);
	fillpoly(9,fill);
}
//////////////////////////////////////////////////////////////////////
void asb(int x,int y,int c)
{       int i,j;
	j=46;
	while (j<=62)
	{	for(i=48;i<=61;i++)
		putpixel(i+x,j+y,c);
		j++;
	}
	j=47;
	while (j<=60)
	{	for(i=60;i<=64;i++)
		putpixel(i+x,j+y,c);
		j++;
	}
	j=44;
	while (j<=48)
	{	for(i=47;i<=62;i++)
		putpixel(i+x,j+y,c);
		j++;
	}
	for(i=46;i<=60;i++)
		putpixel(i+x,43+y,c);
	for(i=45;i<=59;i++)
		putpixel(i+x,42+y,c);
	for(i=44;i<=58;i++)
		putpixel(i+x,41+y,c);
	for(i=43;i<=57;i++)
		putpixel(i+x,40+y,c);
	for(i=48;i<=61;i++)
		putpixel(i+x,63+y,c);
	for(i=49;i<=61;i++)
		putpixel(i+x,64+y,c);
	for(i=49;i<=60;i++)
		putpixel(i+x,65+y,c);
	for(i=45;i<=61;i++)
		putpixel(47+x,i+y,c);
	for(i=44;i<=61;i++)
		putpixel(46+x,i+y,c);
	for(i=44;i<=62;i++)
		putpixel(45+x,i+y,c);
	for(i=50;i<=62;i++)
		putpixel(43+x,i+y,c);
	for(i=50;i<=62;i++)
		putpixel(44+x,i+y,c);
	for(i=53;i<=62;i++)
		putpixel(42+x,i+y,c);
	putpixel(38+x,59+y,c);
	putpixel(39+x,59+y,c);
	putpixel(40+x,59+y,c);
	putpixel(41+x,59+y,c);
	putpixel(38+x,58+y,c);
	putpixel(39+x,58+y,c);
	putpixel(40+x,58+y,c);
	putpixel(41+x,58+y,c);
	putpixel(41+x,57+y,c);
	putpixel(38+x,60+y,c);
	putpixel(39+x,60+y,c);
	putpixel(40+x,60+y,c);
	putpixel(41+x,60+y,c);
	putpixel(41+x,62+y,c);
	putpixel(40+x,62+y,c);
	putpixel(39+x,63+y,c);
	putpixel(41+x,61+y,c);
	//////////////////
	setcolor(c);
	moveto(48+x,46+y);
	lineto(44+x,42+y);
       /*	setfillstyle(1,8);
	fillellipse(49+x,51+y,3,3);     */
	arc(50+x,54+y,0,130,15);
	arc(51+x,56+y,95,170,10);
	line(64+x,55+y,61+x,66+y);
	moveto(41+x,56+y);
	lineto(37+x,59+y);
	lineto(37+x,61+y);
	lineto(40+x,61+y);
	lineto(37+x,64+y);
	lineto(48+x,62+y);
	lineto(51+x,66+y);
	line(46+x,66+y,64+x,66+y);
	line(46+x,68+y,64+x,68+y);
	int asb[18]={50+x,66+y,60+x,66+y,62+x,78+y,73+x,82+y,73+x,84+y
	,37+x,84+y,37+x,82+y,48+x,78+y,50+x,66+y};
	setfillstyle(1,c);
	drawpoly(9,asb);
	fillpoly(9,asb);
}
//////////////////////////////////////////////////////////////////////
void vazir(int x,int y,int c)
{
	setcolor(c);
	setfillstyle(1,c);
	fillellipse(55+x,44+y,2,2);
	int V[10]={51+x,46+y,59+x,46+y,61+x,50+y,49+x,50+y,51+x,46+y};
	drawpoly(5,V);
	fillpoly(5,V);
	line(46+x,51+y,64+x,51+y);
	pieslice(55+x,52+y,180,360,9);
	line(46+x,60+y,64+x,60+y);
	line(46+x,62+y,64+x,62+y);
	int vazir[18]={50+x,58+y,60+x,58+y,62+x,78+y,73+x,82+y,73+x,84+y
	,37+x,84+y,37+x,82+y,48+x,78+y,50+x,58+y};
	drawpoly(9,vazir);
	fillpoly(9,vazir);
}
////////////////////////////////////////////////////////////////////////
void king(int x,int y,int c)
{
	setcolor(c);
	setfillstyle(1,c);
	int V[16]={46+x,39+y,50+x,43+y,55+x,39+y,60+x,43+y,
	64+x,39+y,64+x,48+y,46+x,48+y,46+x,39+y};
	drawpoly(8,V);
	fillpoly(8,V);
	line(46+x,49+y,64+x,49+y);
	pieslice(55+x,50+y,180,360,9);
	line(45+x,58+y,65+x,58+y);
	line(45+x,60+y,65+x,60+y);
	int vazir[18]={50+x,58+y,60+x,58+y,62+x,78+y,73+x,82+y,73+x,84+y
	,37+x,84+y,37+x,82+y,48+x,78+y,50+x,58+y};
	drawpoly(9,vazir);
	fillpoly(9,vazir);
}
////////////////////////////////////////////////////////////////////////
void draw(int x,int y)
{       int c=15,i;
	for (i=x;i<x+(50*8);i+=50)
		sarbaz(i,y,c);
	c=0; y=309;
	for (i=x;i<x+(50*8);i+=50)
		sarbaz(i,y,c);
	c=15; y=x=13; 		rook(x,y,c);
	x=363;        		rook(x,y,c);
	c=0; x=13; y=363; 	rook(x,y,c);
	x=363;			rook(x,y,c);
	x=119; y=13; c=15;	fill(x,y,c);
	x=269;			fill(x,y,c);
	x=119; y=364; c=0;	fill(x,y,c);
	x=269;			fill(x,y,c);
	x=170; y=13; c=15;	king(x,y,c);
	x=170; y=364; c=0;	king(x,y,c);
	x=219; y=13; c=15;	vazir(x,y,c);
	x=219; y=364; c=0;	vazir(x,y,c);
	x=70; y=13;  c=15;	asb(x,y,c);
	x=319; y=13;  c=15;	asb(x,y,c);
	x=70; y=364;  c=0;	asb(x,y,c);
	x=319; y=364;  c=0;	asb(x,y,c);
}

