#include<graphics.h>
#include<conio.h>
#include<iostream.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>

int a[10][10]={{12,13,14,15,16,14,13,12},{11,11,11,11,11,11,11,11},
{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},{21,21,21,21,21,21,21,21},{22,23,24,25,26,24,23,22}
,{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};

int b[8][8];
int c[10][10];

void vazir_move(int,int);
void king_move(int,int);
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
void rook_kish(int,int);
void asb_kish(int,int);
void fill_kish(int,int);
void vazir_kish(int,int);
void move();
void draw();
void kish1();
void kish(int,int);
void out_insert(int,int,int,int,int,int,int);
void insert_move(int,int);
void insert(int,int,int,int,int);
void clear(int,int,int,int,int);
void board();
void menu();
void load();
/////////////////////////////////////////////////////////////////////
void main()
{      // int driver=DETECT,mode;
	int i,j,k,z;
	clrscr();
       //	initgraph(&driver,&mode,"c:\\tc\\bgi");
      //	setbkcolor(0);
	menu();
	board();
	draw();
	move();

	closegraph();
}
/////////////////////////////////////////////////////////////////////
void board()	// Board of Chess//
{       int s,i,j,n=50,m=50,x=8,z=7,k;
	char ch;
	int driver=DETECT,mode;
	clrscr();
	initgraph(&driver,&mode,"c:\\tc\\bgi");
	setbkcolor(0);
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
	settextstyle(7,0,1);
	outtextxy(72,22,"A");outtextxy(122,22,"B");outtextxy(172,22,"C");
	outtextxy(222,22,"D");outtextxy(272,22,"E");outtextxy(322,22,"F");
	outtextxy(372,22,"G");outtextxy(422,22,"H");
	settextstyle(4,0,1);
	outtextxy(20,64,"1");outtextxy(20,114,"2");outtextxy(20,164,"3");
	outtextxy(20,214,"4");outtextxy(20,264,"5");outtextxy(20,314,"6");
	outtextxy(20,364,"7");outtextxy(20,414,"8");
	// kadre 1//
	setcolor(7);
	rectangle(489,15,595,65);
	rectangle(488,14,596,66);
	setcolor(8);
	rectangle(487,13,597,67);
	rectangle(486,12,598,68);
	for (i=490;i<595;i++)
		for (j=16;j<65;j++)
			putpixel(i,j,7);
	setcolor(8);
	settextstyle(0,0,1);
	setusercharsize(1, 1, 1, 1);
	outtextxy(491,22,"Current Match");
	setcolor(15);
	outtextxy(520,38,"white");
	// end kadre 1//
	// kadre 2//
	outtextxy(475,72,"White       Black");
	setcolor(8);
	rectangle(457,82,633,461);
	rectangle(458,83,632,460);
	for (i=459;i<=631;i++)
		for (j=84;j<=459;j++)
			putpixel(i,j,7);
	// end kadre 2//
	//End Board of Chess//
}
//////////////////////////////////////////////////////////////////////
void move()
{	// Move /////////////
	int player1=1,player2=2,color,f,g,q,w,e,r,t,temp;
	int enter=0,p=7,o=8,c=12,y,x,i,j,k,z,s;
	int row,col=0;
	int rang,r2=553,h1=45,h2=45,r1=424;
	setcolor(c);
	rectangle(50,50,100,100);
	i=j=0;
	x=50;
	y=100;
	k=50;
	z=100;
	setcolor(12);
	outtextxy(5,2,"** Press ESC to Exit the game **");
	s=getch();
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

		i--;
		if (i<0)	i=7;

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

		i++;
		if (i>7)	i=0;

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
		j++;
		if (j>7)	j=0;

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
		j--;
		if (j<0)	j=7;

	}
	else if (s==13 && a[i][j]!=0 && a[i][j]/10==player1 && c==12)
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
	}
	else if (s==13 && c==58)
	{
		c=12;
		enter=0;
		setcolor(c);
		insert_move(f,g);
		if (b[i][j]==1)
		{
			if (a[f][g]/10==1) color=15;
			else if(a[f][g]/10==2) color=0;
		/////out insert//////////////////////////////
		if (a[f][g]/10==2 && a[i][j]/10==1)
		{       rang=15;

			out_insert(r1,r2,h1,h2,i,j,rang);
			if (h1>=374)
			{	h1=-2;
				r1=465;
			}
			h1+=47;
		}
		else if (a[f][g]/10==1 && a[i][j]/10==2)
		{	rang=0;
			out_insert(r1,r2,h1,h2,i,j,rang);
			if (h2>=374)
			{	h2=-2;
				r2=510;
			}
			h2+=47;
		}
		////////out_insert////////////////////////////////////
		clear(q,w,e,r,t);
		clear(k,x,z,y,p);
		insert(k,x,f,g,color);
		a[i][j]=a[f][g];
		a[f][g]=0;
		kish1();
		if (player1==1)
		{       setfillstyle(1,7);
			bar(495,37,588,64);
			setcolor(15);
			outtextxy(520,37,"white");
		}
		else
		{       setfillstyle(1,7);
			bar(495,37,588,64);
			setcolor(0);
			outtextxy(520,37,"black");
		}
		}
		else if (b[i][j]==0)
		{
			setcolor(t);
			rectangle(q+1,w+1,e-1,r-1);
			temp=player1;
			player1=player2;
			player2=temp;
			setcolor(12);
			outtextxy(492,55,"Invalid move!");
			cout<<"\a";
			delay(500);
			setfillstyle(1,7);
			bar(492,55,596,64);
		}
		setcolor(12);
		rectangle(k,x,z,y);
	}
	}
	for (i=0,k=479;i<=239,k>=239;i++,k--)
		for (j=0,z=639;j<=639,z>=0;j++,z--)
		{	putpixel(j,i,0);
			putpixel(z,k,0);
		}
	load();
	delay(100);
	menu();
}	//End of Move /////////////
///////////////////////////////////////////////////////////////////////
void out_insert(int r1,int r2,int h1,int h2,int i,int j,int color)
{
	if (color==15)
	{
	if (a[i][j]==11)
		sarbaz(r1,h1,color);
	else if (a[i][j]==12)
		rook(r1,h1,color);
	else if (a[i][j]==13)
		asb(r1,h1,color);
	else if (a[i][j]==14)
		fill(r1,h1,color);
	else if (a[i][j]==15)
		king(r1,h1,color);
	else if (a[i][j]==16)
		vazir(r1,h1,color);
	}

	else if (color==0)
	{
	if (a[i][j]==21)
		sarbaz(r2,h2,color);
	else if (a[i][j]==22)
		rook(r2,h2,color);
	else if (a[i][j]==23)
		asb(r2,h2,color);
	else if (a[i][j]==24)
		fill(r2,h2,color);
	else if (a[i][j]==25)
		king(r2,h2,color);
	else if (a[i][j]==26)
		vazir(r2,h2,color);

	}
}
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
		sarbaz(k-30,x-37,color);
	else if (a[f][g]==21)
		sarbaz(k-30,x-37,color);
	else if (a[f][g]==12)
		rook(k-30,x-37,color);
	else if (a[f][g]==22)
		rook(k-30,x-37,color);
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
	else if (a[f][g]==15 || a[f][g]==25)
		king_move(f,g);
	else if (a[f][g]==16 || a[f][g]==26)
		vazir_move(f,g);
}
////////////////////////////////////////////////////////////////////////
void kish1()
{       int f,g,i,j;
	for (i=0;i<=9;i++)
		for (j=0;j<=9;j++)
			c[i][j]=0;
	for (i=0;i<=7;i++)
		for (j=0;j<=7;j++)
			if (a[i][j]==15)
			{       f=i;
				g=j;
				c[f][g]=a[i][j];
			}

	for (i=f+1;i<=7;i++)
	{	if (a[i][g]/10!=c[f][g]/10)
		 {	c[i][g]=a[i][g];
			kish(i,g);
		 }
		if (a[i][g]!=0)
			break;

	}
	for (i=f-1;i>=0;i--)
	{
		if (a[i][g]/10!=c[f][g]/10)
		{	c[i][g]=a[i][g];
			kish(i,g);
		}
		if (a[i][g]!=0)
			break;
	}
	for (i=g+1;i<=7;i++)
	{
		if(a[f][i]/10!=c[f][g]/10)
		{	c[f][i]=a[f][i];
			kish(f,i);
		}
		if (a[f][i]!=0)
			break;
	}
	for (i=g-1;i>=0;i--)
	{	if(a[f][i]/10!=c[f][g]/10)
		{	c[f][i]=a[f][i];
			kish(f,i);
		}
		if (a[f][i]!=0)
			break;
	}
	for (i=f+1,j=g+1;i<=7,j<=7;i++,j++)
	{	if (a[i][j]/10!=c[f][g]/10)
		{	c[i][j]=a[i][j];
			kish(i,j);
		}
		if (a[i][j]!=0)
			break;
	}
	for (i=f+1,j=g-1;i<=7,j>=0;i++,j--)
	{	if (a[i][j]/10!=c[f][g]/10)
		{	c[i][j]=a[i][j];
			kish(i,j);
		}
		if (a[i][j]!=0)
			break;
	}
	for (i=f-1,j=g-1;i>=0,j>=0;i--,j--)
	{	if (a[i][j]/10!=c[f][g]/10)
		{	c[i][j]=a[i][j];
			kish(i,j);
		}
		if (a[i][j]!=0)
			break;
	}
	for (i=f-1,j=g+1;i>=0,j<=7;i--,j++)
	{	if (a[i][j]/10!=c[f][g]/10)
		{	c[i][j]=a[i][j];
			kish(i,j);
		}
		if (a[i][j]!=0)
			break;
	}
	i=f+2; j=g+1;
	if ((i>=0 && i<=7) || (j>=0 && j<=7))
		if  (a[i][j]/10!=c[f][g]/10)
		{	c[i][j]=a[i][j];
			kish(i,j);
		}
	i=f+2; j=g-1;
	if ((i>=0 && i<=7) || (j>=0 && j<=7))
		if  (a[i][j]/10!=c[f][g]/10)
		{	c[i][j]=a[i][j];
			kish(i,j);
		}
	i=f-2; j=g+1;
	if((i>=0 && i<=7) || (j>=0 && j<=7))
		if  (a[i][j]/10!=c[f][g]/10)
		{	c[i][j]=a[i][j];
			kish(i,j);
		}
	i=f-2; j=g-1;
	if ((i>=0 && i<=7) || (j>=0 && j<=7))
		if  (a[i][j]/10!=c[f][g]/10)
		{	c[i][j]=a[i][j];
			kish(i,j);
		}
	i=f+1; j=g+2;
	if ((i>=0 && i<=7) || (j>=0 && j<=7))
		if  (a[i][j]/10!=c[f][g]/10)
		{	c[i][j]=a[i][j];
			kish(i,j);
		}
	i=f-1; j=g+2;
	if ((i>=0 && i<=7) || (j>=0 && j<=7))
		if  (a[i][j]/10!=c[f][g]/10)
		{	c[i][j]=a[i][j];
			kish(i,j);
		}
	i=f+1; j=g-2;
	if ((i>=0 && i<=7) || (j>=0 && j<=7))
		if  (a[i][j]/10!=c[f][g]/10)
		{	c[i][j]=a[i][j];
			kish(i,j);
		}
	i=f-1; j=g-2;
	if ((i>=0 && i<=7) || (j>=0 && j<=7))
		if  (a[i][j]/10!=c[f][g]/10)
		{	c[i][j]=a[i][j];
			kish(i,j);
		}
/////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
	for (i=0;i<=7;i++)
		for (j=0;j<=7;j++)
			if (a[i][j]==25)
			{       f=i;
				g=j;
				c[f][g]=a[i][j];
			}

	for (i=f+1;i<=7;i++)
	{	if (a[i][g]/10!=c[f][g]/10)
		 {	c[i][g]=a[i][g];
			kish(i,g);
		 }
		if (a[i][g]!=0)
			break;

	}
	for (i=f-1;i>=0;i--)
	{
		if (a[i][g]/10!=c[f][g]/10)
		{	c[i][g]=a[i][g];
			kish(i,g);
		}
		if (a[i][g]!=0)
			break;
	}
	for (i=g+1;i<=7;i++)
	{
		if(a[f][i]/10!=c[f][g]/10)
		{	c[f][i]=a[f][i];
			kish(f,i);
		}
		if (a[f][i]!=0)
			break;
	}
	for (i=g-1;i>=0;i--)
	{	if(a[f][i]/10!=c[f][g]/10)
		{	c[f][i]=a[f][i];
			kish(f,i);
		}
		if (a[f][i]!=0)
			break;
	}
	for (i=f+1,j=g+1;i<=7,j<=7;i++,j++)
	{	if (a[i][j]/10!=c[f][g]/10)
		{	c[i][j]=a[i][j];
			kish(i,j);
		}
		if (a[i][j]!=0)
			break;
	}
	for (i=f+1,j=g-1;i<=7,j>=0;i++,j--)
	{	if (a[i][j]/10!=c[f][g]/10)
		{	c[i][j]=a[i][j];
			kish(i,j);

		}
		if (a[i][j]!=0)
			break;
	}
	for (i=f-1,j=g-1;i>=0,j>=0;i--,j--)
	{	if (a[i][j]/10!=c[f][g]/10)
		{	c[i][j]=a[i][j];
			kish(i,j);
		}
		if (a[i][j]!=0)
			break;
	}
	for (i=f-1,j=g+1;i>=0,j<=7;i--,j++)
	{	if (a[i][j]/10!=c[f][g]/10)
		{	c[i][j]=a[i][j];
			kish(i,j);
		}
		if (a[i][j]!=0)
			break;
	}
	i=f+2; j=g+1;
	if ((i>=0 && i<=7) || (j>=0 && j<=7))
		if  (a[i][j]/10!=c[f][g]/10)
		{	c[i][j]=a[i][j];
			kish(i,j);
		}
	i=f+2; j=g-1;
	if ((i>=0 && i<=7) || (j>=0 && j<=7))
		if  (a[i][j]/10!=c[f][g]/10)
		{	c[i][j]=a[i][j];
			kish(i,j);
		}
	i=f-2; j=g+1;
	if((i>=0 && i<=7) || (j>=0 && j<=7))
		if  (a[i][j]/10!=c[f][g]/10)
		{	c[i][j]=a[i][j];
			kish(i,j);
		}
	i=f-2; j=g-1;
	if ((i>=0 && i<=7) || (j>=0 && j<=7))
		if  (a[i][j]/10!=c[f][g]/10)
		{	c[i][j]=a[i][j];
			kish(i,j);
		}
	i=f+1; j=g+2;
	if ((i>=0 && i<=7) || (j>=0 && j<=7))
		if  (a[i][j]/10!=c[f][g]/10)
		{	c[i][j]=a[i][j];
			kish(i,j);
		}
	i=f-1; j=g+2;
	if ((i>=0 && i<=7) || (j>=0 && j<=7))
		if  (a[i][j]/10!=c[f][g]/10)
		{	c[i][j]=a[i][j];
			kish(i,j);
		}
	i=f+1; j=g-2;
	if ((i>=0 && i<=7) || (j>=0 && j<=7))
		if  (a[i][j]/10!=c[f][g]/10)
		{	c[i][j]=a[i][j];
			kish(i,j);
		}
	i=f-1; j=g-2;
	if ((i>=0 && i<=7) || (j>=0 && j<=7))
		if  (a[i][j]/10!=c[f][g]/10)
		{	c[i][j]=a[i][j];
			kish(i,j);
		}
}
///////////////////////////////////////////////////////////////////////
void kish(int f,int g)
{       int i,j;
	if (c[f][g]==11)
	{
		if (a[f+1][g+1]==25 || a[f+1][g-1]==25)
		      { setcolor(12);
			outtextxy(518,55,"!KISH!");
			delay(500);
			cout<<"\a";
		      }
	}
	else if (c[f][g]==21)
	{
		if (a[f-1][g+1]==15 || a[f-1][g-1]==15)
		      { setcolor(12);
			outtextxy(518,55,"!KISH!");
			delay(500);
			cout<<"\a";
		      }
	}
	else if (c[f][g]==12 || c[f][g]==22)
		rook_kish(f,g);
	else if (c[f][g]==13 || c[f][g]==23)
		asb_kish(f,g);
	else if (c[f][g]==14 || c[f][g]==24)
		fill_kish(f,g);
	else if (c[f][g]==16 || c[f][g]==26)
		vazir_kish(f,g);
}
////////////////////////////////////////////////////////////////////////
void rook_kish(int f,int g)
{       int i,cntr=0;
	cntr=0;
	for (i=f+1;i<=7;i++)
	{	if (a[i][g]/10!=a[f][g]/10 && a[i][g]%10==5)
			cntr=1;
		if (a[i][g]!=0)
			break;

	}
	for (i=f-1;i>=0;i--)
	{
		if (a[i][g]/10!=a[f][g]/10 && a[i][g]%10==5)
			cntr=1;
		if (a[i][g]!=0)
			break;
	}
	for (i=g+1;i<=7;i++)
	{
		if(a[f][i]/10!=a[f][g]/10 && a[f][i]%10==5)
			cntr=1;
		if (a[f][i]!=0)
			break;
	}
	for (i=g-1;i>=0;i--)
	{	if(a[f][i]/10!=a[f][g]/10 && a[f][i]%10==5)
			cntr=1;
		if (a[f][i]!=0)
			break;
	}
	if (cntr==1)
	{
		setcolor(12);
		outtextxy(518,55,"!KISH!");
		delay(500);
		cout<<"\a";
	}
}
////////////////////////////////////////////////////////////////////////
void vazir_kish(int f,int g)
{       int i,j,cntr=0;
	cntr=0;
	for (i=f+1;i<=7;i++)
	{	if (a[i][g]/10!=a[f][g]/10 && a[i][g]%10==5)
			cntr=1;
		if (a[i][g]!=0)
			break;

	}
	for (i=f-1;i>=0;i--)
	{
		if (a[i][g]/10!=a[f][g]/10 && a[i][g]%10==5)
			cntr=1;
		if (a[i][g]!=0)
			break;
	}
	for (i=g+1;i<=7;i++)
	{
		if(a[f][i]/10!=a[f][g]/10 && a[f][i]%10==5)
			cntr=1;
		if (a[f][i]!=0)
			break;
	}
	for (i=g-1;i>=0;i--)
	{	if(a[f][i]/10!=a[f][g]/10 && a[f][i]%10==5)
			cntr=1;
		if (a[f][i]!=0)
			break;
	}
	for (i=f+1,j=g+1;i<=7,j<=7;i++,j++)
	{	if (a[i][j]/10!=a[f][g]/10 && a[i][j]%10==5)
			cntr=1;
		if (a[i][j]!=0)
			break;
	}
	for (i=f+1,j=g-1;i<=7,j>=0;i++,j--)
	{	if (a[i][j]/10!=a[f][g]/10 && a[i][j]%10==5)
			cntr=1;
		if (a[i][j]!=0)
			break;
	}
	for (i=f-1,j=g-1;i>=0,j>=0;i--,j--)
	{	if (a[i][j]/10!=a[f][g]/10 && a[i][j]%10==5)
			cntr=1;
		if (a[i][j]!=0)
			break;
	}
	for (i=f-1,j=g+1;i>=0,j<=7;i--,j++)
	{	if (a[i][j]/10!=a[f][g]/10 && a[i][j]%10==5)
			cntr=1;
		if (a[i][j]!=0)
			break;
	}
	if (cntr==1)
	{
		setcolor(12);
		outtextxy(518,55,"!KISH!");
		delay(500);
		cout<<"\a";
	}
}
////////////////////////////////////////////////////////////////////////
void fill_kish(int f,int g)
{       int i,j,cntr=0;
	cntr=0;
	for (i=f+1,j=g+1;i<=7,j<=7;i++,j++)
	{	if (a[i][j]/10!=a[f][g]/10 && a[i][j]%10==5)
			cntr=1;
		if (a[i][j]!=0)
			break;
	}
	for (i=f+1,j=g-1;i<=7,j>=0;i++,j--)
	{	if (a[i][j]/10!=a[f][g]/10 && a[i][j]%10==5)
			cntr=1;
		if (a[i][j]!=0)
			break;
	}
	for (i=f-1,j=g-1;i>=0,j>=0;i--,j--)
	{	if (a[i][j]/10!=a[f][g]/10 && a[i][j]%10==5)
			cntr=1;
		if (a[i][j]!=0)
			break;
	}
	for (i=f-1,j=g+1;i>=0,j<=7;i--,j++)
	{	if (a[i][j]/10!=a[f][g]/10 && a[i][j]%10==5)
			cntr=1;
		if (a[i][j]!=0)
			break;
	}
	if (cntr==1)
	{
		setcolor(12);
		outtextxy(518,55,"!KISH!");
		delay(500);
		cout<<"\a";
	}
}
////////////////////////////////////////////////////////////////////////
void asb_kish(int f,int g)
{       int i,j,cntr=0;
	cntr=0;

	   i=f+2; j=g+1;
	   if ((i>=0 && i<=7) || (j>=0 && j<=7))
		if  (a[i][j]/10!=a[f][g]/10 && a[i][j]%10==5)
			cntr=1;
	   i=f+2; j=g-1;
	   if ((i>=0 && i<=7) || (j>=0 && j<=7))
		if  (a[i][j]/10!=a[f][g]/10 && a[i][j]%10==5)
			cntr=1;
	   i=f-2; j=g+1;
	   if((i>=0 && i<=7) || (j>=0 && j<=7))
		if  (a[i][j]/10!=a[f][g]/10 && a[i][j]%10==5)
			cntr=1;
	   i=f-2; j=g-1;
	   if ((i>=0 && i<=7) || (j>=0 && j<=7))
		if  (a[i][j]/10!=a[f][g]/10 && a[i][j]%10==5)
			cntr=1;
	   i=f+1; j=g+2;
	   if ((i>=0 && i<=7) || (j>=0 && j<=7))
		if  (a[i][j]/10!=a[f][g]/10 && a[i][j]%10==5)
			cntr=1;
	   i=f-1; j=g+2;
	   if ((i>=0 && i<=7) || (j>=0 && j<=7))
		if  (a[i][j]/10!=a[f][g]/10 && a[i][j]%10==5)
			cntr=1;
	   i=f+1; j=g-2;
	   if ((i>=0 && i<=7) || (j>=0 && j<=7))
		if  (a[i][j]/10!=a[f][g]/10 && a[i][j]%10==5)
			cntr=1;
	   i=f-1; j=g-2;
	   if ((i>=0 && i<=7) || (j>=0 && j<=7))
		if  (a[i][j]/10!=a[f][g]/10 && a[i][j]%10==5)
			cntr=1;
	if (cntr==1)
	{
		setcolor(12);
		outtextxy(518,55,"!KISH!");
		delay(500);
		cout<<"\a";
	}
}
////////////////////////////////////////////////////////////////////////
void vazir_move(int f,int g)
{       int q,w,i,j,m=0,cntr=1;
	for (int row=0;row<=7;row++)
		for (int col=0;col<=7;col++)
			b[row][col]=0;
	for (i=f+1;i<=7;i++)
	{	if (a[i][g]==0 && m==0 && a[i][g]%10!=5)
			b[i][g]=1;
		else if (a[i][g]/10==a[f][g]/10 || a[i][g]!=0)
			{	m=1;
			 if (cntr==1)
			 {	q=i;
				w=g;
			 }
			 cntr=2;
			}
		if (a[q][w]/10!=a[f][g]/10 && a[q][w]%10!=5)
			b[q][w]=1;
	}
	m=0; cntr=1;
	for (i=f-1;i>=0;i--)
	{	if (a[i][g]==0 && m==0 && a[i][g]%10!=5)
			b[i][g]=1;
		else if (a[i][g]/10==a[f][g]/10 || a[i][g]!=0)
			{	m=1;
			 if (cntr==1)
			 {	q=i;
				w=g;
			 }
			 cntr=2;
			}
		if (a[q][w]/10!=a[f][g]/10 && a[q][w]%10!=5)
			b[q][w]=1;
	}
	m=0; cntr=1;
	for (i=g+1;i<=7;i++)
	{	if (a[f][i]==0 && m==0 && a[f][i]%10!=5)
			b[f][i]=1;
		else if (a[f][i]/10==a[f][g]/10 || a[f][i]!=0)
			{	m=1;
			 if (cntr==1)
			 {	q=f;
				w=i;
			 }
			 cntr=2;
			}
		if (a[q][w]/10!=a[f][g]/10 && a[q][w]%10!=5)
			b[q][w]=1;
	}
	m=0; cntr=1;
	for (i=g-1;i>=0;i--)
	{	if (a[f][i]==0 && m==0 && a[f][i]%10!=5)
			b[f][i]=1;
		else if (a[f][i]/10==a[f][g]/10 || a[f][i]!=0)
			{	m=1;
			 if (cntr==1)
			 {	q=f;
				w=i;
			 }
			 cntr=2;
			}
		if (a[q][w]/10!=a[f][g]/10 && a[q][w]%10!=5)
			b[q][w]=1;
	}
	m=0; cntr=1;
	for (i=f+1,j=g+1;i<=7,j<=7;i++,j++)
	{	if (a[i][j]==0 && m==0 && a[i][j]%10!=5)
			b[i][j]=1;
		else if (a[i][j]/10==a[f][g]/10 || a[i][j]!=0)
			{	m=1;
			 if (cntr==1)
			 {	q=i;
				w=j;
			 }
			 cntr=2;
			}
		if (a[q][w]/10!=a[f][g]/10 && a[q][w]%10!=5)
			b[q][w]=1;
	}
	m=0; cntr=1;
	for (i=f+1,j=g-1;i<=7,j>=0;i++,j--)
	{	if (a[i][j]==0 && m==0 && a[i][j]%10!=5)
			b[i][j]=1;
		else if (a[i][j]/10==a[f][g]/10 || a[i][j]!=0)
			{	m=1;
			 if (cntr==1)
			 {	q=i;
				w=j;
			 }
			 cntr=2;
			}
		if (a[q][w]/10!=a[f][g]/10 && a[q][w]%10!=5)
			b[q][w]=1;
	}
	m=0; cntr=1;
	for (i=f-1,j=g-1;i>=0,j>=0;i--,j--)
	{	if (a[i][j]==0 && m==0 && a[i][j]%10!=5)
			b[i][j]=1;
		else if (a[i][j]/10==a[f][g]/10 || a[i][j]!=0)
			{	m=1;
			 if (cntr==1)
			 {	q=i;
				w=j;
			 }
			 cntr=2;
			}
		if (a[q][w]/10!=a[f][g]/10 && a[q][w]%10!=5)
			b[q][w]=1;
	}
	m=0; cntr=1;
	for (i=f-1,j=g+1;i>=0,j<=7;i--,j++)
	{	if (a[i][j]==0 && m==0 && a[i][j]%10!=5)
			b[i][j]=1;
		else if (a[i][j]/10==a[f][g]/10 || a[i][j]!=0)
			{	m=1;
			 if (cntr==1)
			 {	q=i;
				w=j;
			 }
			 cntr=2;
			}
		if (a[q][w]/10!=a[f][g]/10 && a[q][w]%10!=5)
			b[q][w]=1;
	}
}
///////////////////////////////////////////////////////////////////////
void king_move(int f,int g)
{       int i,j;
	for (int row=0;row<=7;row++)
		for (int col=0;col<=7;col++)
			b[row][col]=0;
	i=f;
	j=g;
	if ((a[i+1][j+1]==0) || (a[i+1][j+1]/10!=a[f][g]/10) && a[i+1][j+1]%10!=5)
	{	if((i<=7 || i>=0) || (j<=7 || j>=0))
			b[i+1][j+1]=1;
		if(a[i+2][j+2]/10!=a[f][g]/10 && a[i+2][j+2]%10==5)
			b[i+1][j+1]=0;
	}
	i=f;
	j=g;
	if ((a[i+1][j]==0) || (a[i+1][j]/10!=a[f][g]/10) && a[i+1][j]%10!=5)
	{	if((i<=7 || i>=0) || (j<=7 || j>=0))
			b[i+1][j]=1;
		if(a[i+2][j]/10!=a[f][g]/10 && a[i+2][j]%10==5)
			b[i+1][j]=0;
	}
	i=f;
	j=g;
	if ((a[i][j+1]==0) || (a[i][j+1]/10!=a[f][g]/10) && a[i][j+1]%10!=5)
	{	if((i<=7 || i>=0) || (j<=7 || j>=0))
			b[i][j+1]=1;
		if(a[i][j+2]/10!=a[f][g]/10 && a[i][j+2]%10==5)
			b[i][j+1]=0;
	}
	i=f;
	j=g;
	if ((a[i-1][j-1]==0) || (a[i-1][j-1]/10!=a[f][g]/10) && a[i-1][j-1]%10!=5)
	{	if((i<=7 || i>=0) || (j<=7 || j>=0))
			b[i-1][j-1]=1;
		if(a[i-2][j-2]/10!=a[f][g]/10 && a[i-2][j-2]%10==5)
			b[i-1][j-1]=0;
	}
	i=f;
	j=g;
	if ((a[i-1][j]==0) || (a[i-1][j]/10!=a[f][g]/10) && a[i-1][j]%10!=5)
	{	if((i<=7 || i>=0) || (j<=7 || j>=0))
			b[i-1][j]=1;
		if(a[i-2][j]/10!=a[f][g]/10 && a[i-2][j]%10==5)
			b[i-1][j]=0;
	}
	i=f;
	j=g;
	if ((a[i][j-1]==0) || (a[i][j-1]/10!=a[f][g]/10) && a[i][j-1]%10!=5)
	{	if((i<=7 || i>=0) || (j<=7 || j>=0))
			b[i][j-1]=1;
		if(a[i][j-2]/10!=a[f][g]/10 && a[i][j-2]%10==5)
			b[i][j-1]=0;
	}
	i=f;
	j=g;
	if ((a[i+1][j-1]==0) || (a[i+1][j-1]/10!=a[f][g]/10) && a[i+1][j-1]%10!=5)
	{	if((i<=7 || i>=0) || (j<=7 || j>=0))
			b[i+1][j-1]=1;
		if(a[i+2][j-2]/10!=a[f][g]/10 && a[i+2][j-2]%10==5)
			b[i+1][j-1]=0;
	}
	i=f;
	j=g;
	if ((a[i-1][j+1]==0) || (a[i-1][j+1]/10!=a[f][g]/10) && a[i-1][j+1]%10!=5)
	{	if((i<=7 || i>=0) || (j<=7 || j>=0))
			b[i-1][j+1]=1;
		if(a[i-2][j+2]/10!=a[f][g]/10 && a[i-2][j+2]%10==5)
			b[i-1][j+1]=0;
	}
}
////////////////////////////////////////////////////////////////////////
void fill_move(int f,int g)
{       int q,w,i,j,m=0,cntr=1;
	for (int row=0;row<=7;row++)
		for (int col=0;col<=7;col++)
			b[row][col]=0;
	for (i=f+1,j=g+1;i<=7,j<=7;i++,j++)
	{	if (a[i][j]==0 && m==0 && a[i][j]%10!=5)
			b[i][j]=1;
		else if (a[i][j]/10==a[f][g]/10 || a[i][j]!=0)
			{	m=1;
			 if (cntr==1)
			 {	q=i;
				w=j;
			 }
			 cntr=2;
			}
		if (a[q][w]/10!=a[f][g]/10 && a[q][w]%10!=5)
			b[q][w]=1;
	}
	m=0; cntr=1;
	for (i=f+1,j=g-1;i<=7,j>=0;i++,j--)
	{	if (a[i][j]==0 && m==0 && a[i][j]%10!=5)
			b[i][j]=1;
		else if (a[i][j]/10==a[f][g]/10 || a[i][j]!=0)
			{	m=1;
			 if (cntr==1)
			 {	q=i;
				w=j;
			 }
			 cntr=2;
			}
		if (a[q][w]/10!=a[f][g]/10 && a[q][w]%10!=5)
			b[q][w]=1;
	}
	m=0; cntr=1;
	for (i=f-1,j=g-1;i>=0,j>=0;i--,j--)
	{	if (a[i][j]==0 && m==0 && a[i][j]%10!=5)
			b[i][j]=1;
		else if (a[i][j]/10==a[f][g]/10 || a[i][j]!=0)
			{	m=1;
			 if (cntr==1)
			 {	q=i;
				w=j;
			 }
			 cntr=2;
			}
		if (a[q][w]/10!=a[f][g]/10 && a[q][w]%10!=5)
			b[q][w]=1;
	}
	m=0; cntr=1;
	for (i=f-1,j=g+1;i>=0,j<=7;i--,j++)
	{	if (a[i][j]==0 && m==0 && a[i][j]%10!=5)
			b[i][j]=1;
		else if (a[i][j]/10==a[f][g]/10 || a[i][j]!=0)
			{	m=1;
			 if (cntr==1)
			 {	q=i;
				w=j;
			 }
			 cntr=2;
			}
		if (a[q][w]/10!=a[f][g]/10 && a[q][w]%10!=5)
			b[q][w]=1;
	}
}
////////////////////////////////////////////////////////////////////////
void rook_move(int f,int g)
{       int i,j,m=0,w,q,cntr=1;
	for (int row=0;row<=7;row++)
		for (int col=0;col<=7;col++)
			b[row][col]=0;
	for (i=f+1;i<=7;i++)
	{	if (a[i][g]==0 && m==0 && a[i][g]%10!=5)
			b[i][g]=1;
		else if (a[i][g]/10==a[f][g]/10 || a[i][g]!=0)
			{	m=1;
			 if (cntr==1)
			 {	q=i;
				w=g;
			 }
			 cntr=2;
			}
		if (a[q][w]/10!=a[f][g]/10 && a[q][w]%10!=5)
			b[q][w]=1;

	}
	m=0;
	cntr=1;
	for (i=f-1;i>=0;i--)
	{	if(a[i][g]==0 && m==0 && a[i][g]%10!=5)
			b[i][g]=1;
		else if (a[i][g]/10==a[f][g]/10 || a[i][g]!=0)
			{	m=1;
			 if (cntr==1)
			 {	q=i;
				w=g;
			 }
			 cntr=2;
			}
		if (a[q][w]/10!=a[f][g]/10 && a[q][w]%10!=5)
			b[q][w]=1;
	}
	m=0;
	cntr=1;
	for (i=g+1;i<=7;i++)
	{
		if(a[f][i]==0  && m==0 && a[f][i]%10!=5)
			b[f][i]=1;
		else if (a[f][i]/10==a[f][g]/10 || a[f][i]!=0)
			{	m=1;
			 if (cntr==1)
			 {	q=f;
				w=i;
			 }
			 cntr=2;
			}
		if (a[q][w]/10!=a[f][g]/10 && a[q][w]%10!=5)
			b[q][w]=1;
	}
	m=0;
	cntr=1;
	for (i=g-1;i>=0;i--)
	{	if(a[f][i]==0 && m==0 && a[f][i]%10!=5)
			b[f][i]=1;
		else if (a[f][i]/10==a[f][g]/10 || a[f][i]!=0)
			{	m=1;
			 if (cntr==1)
			 {	q=f;
				w=i;
			 }
			 cntr=2;
			}
		if (a[q][w]/10!=a[f][g]/10 && a[q][w]%10!=5)
			b[q][w]=1;
	}
}
////////////////////////////////////////////////////////////////////////
void asb_move(int f,int g)
{       int i,j;
	for (int row=0;row<=7;row++)
		for (int col=0;col<=7;col++)
			b[row][col]=0;
	   i=f+2; j=g+1;
	   if ((i>=0 && i<=7) || (j>=0 && j<=7))
		if  (a[i][j]/10!=a[f][g]/10 && a[i][j]%10!=5)
			b[i][j]=1;
	   i=f+2; j=g-1;
	   if ((i>=0 && i<=7) || (j>=0 && j<=7))
		if  (a[i][j]/10!=a[f][g]/10 && a[i][j]%10!=5)
			b[i][j]=1;
	   i=f-2; j=g+1;
	   if((i>=0 && i<=7) || (j>=0 && j<=7))
		if  (a[i][j]/10!=a[f][g]/10 && a[i][j]%10!=5)
			b[i][j]=1;
	   i=f-2; j=g-1;
	   if ((i>=0 && i<=7) || (j>=0 && j<=7))
		if  (a[i][j]/10!=a[f][g]/10 && a[i][j]%10!=5)
			b[i][j]=1;
	   i=f+1; j=g+2;
	   if ((i>=0 && i<=7) || (j>=0 && j<=7))
		if  (a[i][j]/10!=a[f][g]/10 && a[i][j]%10!=5)
			b[i][j]=1;
	   i=f-1; j=g+2;
	   if ((i>=0 && i<=7) || (j>=0 && j<=7))
		if  (a[i][j]/10!=a[f][g]/10 && a[i][j]%10!=5)
			b[i][j]=1;
	   i=f+1; j=g-2;
	   if ((i>=0 && i<=7) || (j>=0 && j<=7))
		if  (a[i][j]/10!=a[f][g]/10 && a[i][j]%10!=5)
			b[i][j]=1;
	   i=f-1; j=g-2;
	   if ((i>=0 && i<=7) || (j>=0 && j<=7))
		if  (a[i][j]/10!=a[f][g]/10 && a[i][j]%10!=5)
			b[i][j]=1;

}
////////////////////////////////////////////////////////////////////////
void sarbaz_move(int f,int g)
{       int i,j,m=0;
	for (int row=0;row<=7;row++)
		for (int col=0;col<=7;col++)
			b[row][col]=0;
	if (a[f][g]==11)
	{
		if(f==1)
			if (a[f+1][g]==0 && a[f+2][g]==0)
			{	b[f+1][g]=1;
				b[f+2][g]=1;
			}
		if (a[f+1][g]==0 )
			b[f+1][g]=1;
		if (a[f+1][g+1]/10==2 && a[f+1][g+1]%10!=5)
			b[f+1][g+1]=1;
		if (a[f+1][g-1]/10==2 && a[f+1][g-1]%10!=5)
			b[f+1][g-1]=1;

		for (i=0;i<=7;i++)
			for (j=0;j<=7;j++)
				if(a[i][j]==16)
					m=1;
		if (a[f][g]==a[7][g] && m==0)
			a[f][g]=16;
		m=0;
		for (i=0;i<=7;i++)
			for (j=0;j<=7;j++)
				if(a[i][j]==14)
					m=1;
		if (a[f][g]==a[7][g] && m==0)
			a[f][g]=14;
		m=0;
		for (i=0;i<=7;i++)
			for (j=0;j<=7;j++)
				if(a[i][j]==13)
					m=1;
		if (a[f][g]==a[7][g] && m==0)
			a[f][g]=13;
		m=0;
		for (i=0;i<=7;i++)
			for (j=0;j<=7;j++)
				if(a[i][j]==12)
					m=1;
		if (a[f][g]==a[7][g] && m==0)
			a[f][g]=12;
		m=0;
	}
	else if (a[f][g]==21)
	{
		if(f==6)
			if (a[f-1][g]==0 && a[f-2][g]==0)
			{
				b[f-1][g]=1;
				b[f-2][g]=1;
			}
		if (a[f-1][g]==0)
			b[f-1][g]=1;
		if (a[f-1][g-1]/10==1 && a[f-1][g-1]%10!=5)
			b[f-1][g-1]=1;
		if (a[f-1][g+1]/10==1 && a[f-1][g+1]%10!=5)
			b[f-1][g+1]=1;
		for (i=0;i<=7;i++)
			for (j=0;j<=7;j++)
				if(a[i][j]==26)
					m=1;
		if (a[f][g]==a[f][0] && m==0)
			a[f][g]=26;
		m=0;
		for (i=0;i<=7;i++)
			for (j=0;j<=7;j++)
				if(a[i][j]==24)
					m=1;
		if (a[f][g]==a[0][g] && m==0)
			a[f][g]=24;
		m=0;
		for (i=0;i<=7;i++)
			for (j=0;j<=7;j++)
				if(a[i][j]==23)
					m=1;
		if (a[f][g]==a[0][g] && m==0)
			a[f][g]=23;
		m=0;
		for (i=0;i<=7;i++)
			for (j=0;j<=7;j++)
				if(a[i][j]==22)
					m=1;
		if (a[f][g]==a[0][g] && m==0)
			a[f][g]=22;
		m=0;
	}
}
///////////////////////////////////////////////////////////////////////
void sarbaz(int x,int y,int c)
{
	setcolor(c);
	setfillstyle(1,c);
	fillellipse(x+55,y+52,9,9);
	int a[22]={45+x,60+y,65+x,60+y,60+x,65+y,60+x,78+y,73+x,82+y,
	73+x,84+y,37+x,84+y,37+x,82+y,50+x,78+y,50+x,65+y,45+x,60+y};
	drawpoly(11,a);
	fillpoly(11,a);
}

////////////////////////////////////////////////////////////////////////
void rook(int x,int y,int c)
{
	setcolor(c);
	setfillstyle(1,c);
	int rokh[26]={38+x,47+y,45+x,47+y,45+x,52+y,50+x,52+y,50+x
	,47+y,60+x,47+y,60+x,52+y,65+x,52+y,65+x,47+y,72+x,47+y
	,72+x,57+y,38+x,57+y,38+x,47+y};
	drawpoly(13,rokh);
	fillpoly(13,rokh);
	int rook[18]={50+x,57+y,60+x,57+y,60+x,78+y,73+x,82+y,73+x,84+y
	,37+x,84+y,37+x,82+y,50+x,78+y,50+x,57+y};
	drawpoly(9,rook);
	fillpoly(9,rook);
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
void draw()
{       int c=15,i,x=19,y=63;
	for (i=x;i<x+(50*8);i+=50)
		sarbaz(i,y,c);
	c=0; y=313;
	for (i=x;i<x+(50*8);i+=50)
		sarbaz(i,y,c);
	c=15; x=19; y=13;	rook(x,y,c);
	c=15; x=369;y=13;      	rook(x,y,c);
	c=0; x=19; y=364; 	rook(x,y,c);
	c=0; x=369; y=364;	rook(x,y,c);
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
/////////////////////////////////////////////////////////////////////
void menu()
{       int s,x=10,i,j,k,z,index=0,l=15,y=59;
	clrscr();
	restorecrtmode();
	textmode(C4350);
	for (i=38,j=39,z=7,k=7;i<75,j>10,k<30,z<30;i++,j--,k++,z++)
	{
		gotoxy(i,7);
		textcolor(11);
		cprintf("¯");
		delay(20);
		gotoxy(j,7);
		textcolor(11);
		cprintf("®");
		delay(20);
		gotoxy(i,30);
		textcolor(11);
		cprintf("¯");
		delay(20);
		gotoxy(j,30);
		textcolor(11);
		cprintf("®");
		delay(20);
		gotoxy(54,k);
		textcolor(3);
		cprintf("õ");
		delay(20);
		gotoxy(23,z);
		textcolor(3);
		cprintf("ô");
	}
	textcolor(15);
	for (i=1;i<=80;i++)
	{       gotoxy(i,1);
		cprintf("*");
		delay(5);
	}
	for (i=2;i<=49;i++)
	{       gotoxy(80,i);
		cprintf("*");
		delay(5);
	}
	for (i=80;i>=1;i--)
	{       gotoxy(i,49);
		cprintf("*");
		delay(5);
	}
	for (i=49;i>=1;i--)
	{       gotoxy(1,i);
		cprintf("*");
		delay(5);
	}
	gotoxy(32,10);
	textcolor(15);
	cprintf("1.   New Game");
	delay(300);
	gotoxy(32,13);
	cprintf("2.   Load Game");
	delay(300);
	gotoxy(32,16);
	cprintf("3.   Credits ");
	delay(300);
	gotoxy(32,19);
	cprintf("4.   Exit");
	//Chess/////////////////
		gotoxy(65,5);
		textcolor(12);
		cprintf("ßßßßßß");
		delay(30);
		delay(30);
		for (i=5;i<=9;i++)
		{	gotoxy(65,i);
			cprintf("Û");
			delay(30);
		}
		gotoxy(65,9);
		cprintf("ßßßßßß");
		delay(30);
		textcolor(4);
		for (i=12;i<=18;i++)
		{	gotoxy(65,i);
			cprintf("Û");
			delay(30);
			gotoxy(70,i);
			cprintf("Û");
			delay(30);
		}
		gotoxy(66,15);
		cprintf("ßßßß");
		delay(30);
		textcolor(12);
		gotoxy(65,21);
		cprintf("ßßßßßß");
		delay(30);
		for (i=21;i<=26;i++)
		{	gotoxy(65,i);
			cprintf("Û");
			delay(30);
		}
		gotoxy(66,24);
		cprintf("ßßßßß");
		delay(30);
		gotoxy(65,27);
		cprintf("ßßßßßß");
		delay(30);
		textcolor(4);
		gotoxy(65,30);
		cprintf("ß");
		delay(30);
		gotoxy(66,29);
		cprintf("ßßßß");
		delay(30);
		gotoxy(70,30);
		cprintf("ß");
		delay(30);
		for (i=30;i<33;i++)
		{       gotoxy(65,i);
			cprintf("Û");
			delay(30);
		}
		gotoxy(66,32);
		cprintf("ÜÜÜÜÜ");
		delay(30);
		for (i=33;i<35;i++)
		{       gotoxy(70,i);
			cprintf("Û");
			delay(30);
		}
		gotoxy(65,35);
		cprintf("ß");
		delay(30);
		gotoxy(66,36);
		cprintf("ßßßß");
		delay(30);
		gotoxy(70,35);
		cprintf("ß");
		delay(30);
		textcolor(12);
		gotoxy(65,39);
		cprintf("ß");
		delay(30);
		gotoxy(66,38);
		cprintf("ßßßß");
		delay(30);
		gotoxy(70,39);
		cprintf("ß");
		delay(30);
		for (i=39;i<42;i++)
		{       gotoxy(65,i);
			cprintf("Û");
			delay(30);
		}
		gotoxy(66,41);
		cprintf("ÜÜÜÜÜ");
		delay(30);
		for (i=42;i<44;i++)
		{       gotoxy(70,i);
			cprintf("Û");
			delay(30);
		}
		gotoxy(65,44);
		cprintf("ß");
		delay(30);
		gotoxy(66,45);
		cprintf("ßßßß");
		delay(30);
		gotoxy(70,44);
		cprintf("ß");
		delay(30);
	//chess******************
	//***Mohrehaye shatranj***
	for(i=3;i<=11;i++)
	      for(j=5;j<=42;j++)
		{	gotoxy(i,j);
			cout<<"²";
			delay(3);
		}
	gotoxy(3,6);
	textcolor(131);
	cprintf("ÜÜÜÜÜÜÜ");
	gotoxy(3,6);
	cprintf("º");
	gotoxy(6,6);
	cprintf("º");
	gotoxy(9,6);
	cprintf("º");
	gotoxy(3,5);
	cprintf("º");
	gotoxy(6,5);
	cprintf("º");
	gotoxy(9,5);
	cprintf("º");
	for(i=5;i<=7;i++)
		for(j=7;j<=15;j++)
			{	gotoxy(i,j);
				cprintf("Û");
			}
	gotoxy(3,15);
	cprintf("ÛÛÛÛÛÛÛ");
	//End of rokh/////////
	//begin of king//
	textcolor(131);
	gotoxy(4,29);
	cprintf("ÜÜÜÜÜ");
	gotoxy(6,28);
	cprintf("Û");
	gotoxy(6,29);
	cprintf("Û");
	gotoxy(6,30);
	cprintf("Û");
	gotoxy(6,31);
	cprintf("Û");
	gotoxy(6,31);
	cprintf("Û");
	gotoxy(4,32);
	cprintf("ÛÛÛÛÛ");
	gotoxy(5,33);
	cprintf("ÛÛÛ");
	gotoxy(6,34);
	cprintf("Û");
	for (i=35;i<=40;i++)
	{       gotoxy(6,i);
		cprintf("Û");
	}
	gotoxy(4,42);
	cprintf("ÛÛÛÛÛ");
	gotoxy(5,41);
	cprintf("ÛÛÛ");

	//**************
	//Clear*********
	gotoxy(4,5);
	cout<<"  ";
	delay(5);
	gotoxy(7,5);
	cout<<"  ";
	delay(5);
	gotoxy(10,5);
	cout<<"  ";
	delay(5);
	gotoxy(10,6);
	cout<<"  ";
	delay(5);
	gotoxy(3,7);
	cout<<"  ";
	delay(5);
	gotoxy(8,7);
	cout<<"      ";
	delay(5);
	gotoxy(10,7);
	cout<<"  ";
	delay(5);
	gotoxy(3,8);
	cout<<"  ";
	delay(5);
	gotoxy(8,8);
	cout<<"      ";
	delay(5);
	gotoxy(10,8);
	cout<<"  ";
	delay(5);
	gotoxy(3,9);
	cout<<"  ";
	delay(5);
	gotoxy(8,9);
	cout<<"      ";
	delay(5);
	gotoxy(10,9);
	cout<<"  ";
	delay(5);
	gotoxy(3,10);
	cout<<"  ";
	delay(5);
	gotoxy(8,10);
	cout<<"      ";
	delay(5);
	gotoxy(10,10);
	cout<<"  ";
	delay(5);
	gotoxy(3,11);
	cout<<"  ";
	delay(5);
	gotoxy(8,11);
	cout<<"      ";
	delay(5);
	gotoxy(10,11);
	cout<<"  ";
	delay(5);
	gotoxy(10,12);
	cout<<"  ";
	delay(5);
	gotoxy(3,12);
	cout<<"  ";
	delay(5);
	gotoxy(8,12);
	cout<<"  ";
	delay(5);
	gotoxy(10,12);
	cout<<"  ";
	delay(5);
	gotoxy(3,13);
	cout<<"  ";
	delay(5);
	gotoxy(8,13);
	cout<<"  ";
	delay(5);
	gotoxy(10,13);
	cout<<"  ";
	delay(5);
	gotoxy(3,14);
	cout<<"  ";
	delay(5);
	gotoxy(8,14);
	cout<<"  ";
	delay(5);
	gotoxy(10,14);
	cout<<"  ";
	delay(5);
	gotoxy(10,15);
	cout<<"  ";
	delay(5);
	for (i=3;i<=11;i++)
		for (j=16;j<=27;j++)
		{	gotoxy(i,j);
			cout<<" ";
			delay(5);
		}
	gotoxy(3,28);
	cout<<" ";
	delay(5);
	gotoxy(4,28);
	cout<<"  ";
	delay(5);
	gotoxy(7,28);
	cout<<"  ";
	delay(5);
	gotoxy(9,28);
	cout<<" ";
	delay(5);
	gotoxy(10,28);
	cout<<"  ";
	delay(5);
	gotoxy(3,29);
	cout<<" ";
	delay(5);
	gotoxy(9,29);
	cout<<" ";
	delay(5);
	gotoxy(10,29);
	cout<<"   ";
	delay(5);
	gotoxy(3,30);
	cout<<" ";
	delay(5);
	gotoxy(4,30);
	cout<<"  ";
	delay(5);
	gotoxy(7,30);
	cout<<"   ";
	delay(5);
	gotoxy(10,30);
	cout<<"  ";
	delay(5);
	gotoxy(3,31);
	cout<<" ";
	delay(5);
	gotoxy(4,31);
	cout<<"  ";
	delay(5);
	gotoxy(7,31);
	cout<<"   ";
	delay(5);
	gotoxy(9,31);
	gotoxy(10,31);
	cout<<"  ";
	delay(5);
	cout<<" ";
	gotoxy(3,32);
	cout<<" ";
	delay(5);
	gotoxy(9,32);
	cout<<" ";
	delay(5);
	gotoxy(10,32);
	cout<<"  ";
	delay(5);
	gotoxy(3,33);
	cout<<"  ";
	delay(5);
	gotoxy(8,33);
	cout<<" ";
	delay(5);
	gotoxy(9,33);
	cout<<" ";
	delay(5);
	gotoxy(10,33);
	cout<<"  ";
	delay(5);
	gotoxy(3,34);
	cout<<" ";
	delay(5);
	gotoxy(4,34);
	cout<<" ";
	delay(5);
	gotoxy(5,34);
	cout<<" ";
	delay(5);
	gotoxy(7,34);
	cout<<" ";
	delay(5);
	gotoxy(8,34);
	cout<<" ";
	delay(5);
	gotoxy(9,34);
	cout<<" ";
	delay(5);
	gotoxy(10,34);
	cout<<"  ";
	delay(5);
	gotoxy(3,35);
	cout<<" ";
	delay(5);
	gotoxy(4,35);
	cout<<" ";
	delay(5);
	gotoxy(5,35);
	cout<<" ";
	delay(5);
	gotoxy(7,35);
	cout<<" ";
	delay(5);
	gotoxy(8,35);
	cout<<" ";
	delay(5);
	gotoxy(9,35);
	cout<<" ";
	delay(5);
	gotoxy(10,35);
	cout<<"  ";
	delay(5);
	gotoxy(3,36);
	cout<<" ";
	delay(5);
	gotoxy(4,36);
	cout<<" ";
	delay(5);
	gotoxy(5,36);
	cout<<" ";
	delay(5);
	gotoxy(7,36);
	cout<<" ";
	delay(5);
	gotoxy(8,36);
	cout<<" ";
	delay(5);
	gotoxy(9,36);
	cout<<" ";
	delay(5);
	gotoxy(10,36);
	cout<<"  ";
	delay(5);
	gotoxy(3,37);
	cout<<" ";
	delay(5);
	gotoxy(4,37);
	cout<<" ";
	delay(5);
	gotoxy(5,37);
	cout<<" ";
	delay(5);
	gotoxy(7,37);
	cout<<" ";
	delay(5);
	gotoxy(8,37);
	cout<<" ";
	delay(5);
	gotoxy(9,37);
	cout<<" ";
	delay(5);
	gotoxy(10,37);
	cout<<"  ";
	delay(5);
	gotoxy(3,38);
	cout<<" ";
	delay(5);
	gotoxy(4,38);
	cout<<" ";
	delay(5);
	gotoxy(5,38);
	cout<<" ";
	delay(5);
	gotoxy(7,38);
	cout<<" ";
	delay(5);
	gotoxy(8,38);
	cout<<" ";
	delay(5);
	gotoxy(9,38);
	cout<<" ";
	delay(5);
	gotoxy(10,38);
	cout<<"  ";
	delay(5);
	gotoxy(3,39);
	cout<<" ";
	delay(5);
	gotoxy(4,39);
	cout<<" ";
	delay(5);
	gotoxy(5,39);
	cout<<" ";
	delay(5);
	gotoxy(7,39);
	cout<<" ";
	delay(5);
	gotoxy(8,39);
	cout<<" ";
	delay(5);
	gotoxy(9,39);
	cout<<" ";
	delay(5);
	gotoxy(10,39);
	cout<<"  ";
	delay(5);
	gotoxy(3,40);
	cout<<" ";
	delay(5);
	gotoxy(4,40);
	cout<<" ";
	delay(5);
	gotoxy(5,40);
	cout<<" ";
	delay(5);
	gotoxy(7,40);
	cout<<" ";
	delay(5);
	gotoxy(8,40);
	cout<<" ";
	delay(5);
	gotoxy(9,40);
	cout<<" ";
	delay(5);
	gotoxy(10,40);
	cout<<"  ";
	delay(5);
	gotoxy(8,41);
	cout<<"    ";
	delay(5);
	gotoxy(3,41);
	cout<<"  ";
	delay(5);
	gotoxy(9,42);
	cout<<"     ";
	delay(5);
	gotoxy(3,42);
	cout<<" ";
	delay(5);
	//End of clear/////////////
	gotoxy(28,10);
	printf("%c",16);
	gotoxy(80,49);
	s=getch();
	while (s!=27)
	{
		gotoxy(32,10);
		textcolor(15);
		cprintf("1.   New Game");
		gotoxy(32,13);
		textcolor(15);
		cprintf("2.   Load Game");
		gotoxy(32,16);
		textcolor(15);
		cprintf("3.   Credits");
		if (s==80)
		{       if(index==1)
			{	for (i=29;i<49;i++)
				{
					for (j=35;j<49;j++)
					{
						gotoxy(i,j);
						cout<<"  ";
					}
				}
			}
			index=0;
			gotoxy(35,25);
			cout<<"         ";
			gotoxy(28,x);
			cout<<" ";
			x+=3;
			if(x>19)
			{	gotoxy(28,10);
				x=10;
			}
			gotoxy(28,x);
			printf("%c",16);
			gotoxy(80,49);
		}
		if (s==72)
		{
			if(index==1)
			{	for (i=29;i<49;i++)
				{
					for (j=35;j<49;j++)
					{
						gotoxy(i,j);
						cout<<"  ";
					}
				}
			}
			index=0;
			gotoxy(35,25);
			cout<<"         ";
			gotoxy(28,x);
			cout<<" ";
			x-=3;
			if (x<10)
			{	gotoxy(28,10);
				x=19;
			}
			cout<<" ";
			gotoxy(28,x);
			printf("%c",16);
			gotoxy(80,49);
		}
		if ( s==13 && x==10 )
		{
			index=2;
			gotoxy(32,10);
			textcolor(10);
			cprintf("\a1.   New Game");
			gotoxy(35,25);
			textcolor(14);
			cprintf("N");
			delay(50);
			gotoxy(36,25);
			cprintf("e");
			delay(50);
			gotoxy(37,25);
			cprintf("w ");
			delay(50);
			gotoxy(39,25);
			cprintf("G");
			delay(50);
			gotoxy(40,25);
			cprintf("a");
			delay(50);
			gotoxy(41,25);
			cprintf("m");
			delay(50);
			gotoxy(42,25);
			cprintf("e");
			delay(500);
		//////////////////////////////////
		load();
		board();                         //
		draw();                       //
		move();                          //
		getch();                         //
		/////////////////////////////////
		}
		if ( s==13 && x==13 )
		{
			gotoxy(32,13);
			textcolor(10);
			cprintf("\a2.   Load Game");
			gotoxy(35,25);
			textcolor(14);
			cprintf("L");
			delay(50);
			gotoxy(36,25);
			cprintf("o");
			delay(50);
			gotoxy(37,25);
			cprintf("a");
			delay(50);
			gotoxy(38,25);
			cprintf("d ");
			delay(50);
			gotoxy(40,25);
			cprintf("G");
			delay(50);
			gotoxy(41,25);
			cprintf("a");
			delay(50);
			gotoxy(42,25);
			cprintf("m");
			delay(50);
			gotoxy(43,25);
			cprintf("e");
			delay(50);
		}
		if (s==13 && x==16 )
		{
			cout<<"";
			gotoxy(32,16);
			textcolor(10);
			cprintf("\a3.   Credits");
			for (i=32,j=35;i<50,j<49;i++,j++)
			{       index=1;
				gotoxy(31,35);
				textcolor(13);
				cprintf("É");
				gotoxy(i,35);
				cprintf("Í");
				delay(20);
				gotoxy(i,48);
				cprintf("Í");
				delay(20);
				gotoxy(46,35);
				cprintf("»");
				gotoxy(31,j);
				cprintf("º");
				delay(20);
				gotoxy(31,48);
				cprintf("È");
				gotoxy(46,j);
				cprintf("º");
				delay(20);
			}
			gotoxy(46,48);
			cout<<"¼";
			gotoxy(39,41);
			cprintf("3");
			delay(350);
			gotoxy(39,41);
			cprintf("2");
			delay(350);
			gotoxy(39,41);
			cprintf("1");
			delay(350);
			gotoxy(39,41);
			cprintf(" ");
			delay(50);
			textcolor(15);
			gotoxy(34,38);
			textcolor(15);
				delay(350);
				cout<<"A";
				delay(25);
				cout<<"n";
				delay(25);
				cout<<"o";
				delay(25);
				cout<<"u";
				delay(25);
				cout<<"s";
				delay(25);
				cout<<"h";
				delay(25);
				cout<<"e";
				delay(25);
			gotoxy(36,40);
				cout<<"M";
				delay(25);
				cout<<"a";
				delay(25);
				cout<<"n";
				delay(25);
				cout<<"s";
				delay(25);
				cout<<"o";
				delay(25);
				cout<<"u";
				delay(25);
				cout<<"r";
				delay(25);
				cout<<"i";
				delay(25);
			gotoxy(36,42);
				textcolor(18);
				cprintf("  * * *");
			gotoxy(34,44);
				delay(25);
				cout<<"R";
				delay(25);
				cout<<"e";
				delay(25);
				cout<<"z";
				delay(25);
				cout<<"a";
				delay(25);
			gotoxy(36,46);
				cout<<"H";
				delay(25);
				cout<<"o";
				delay(25);
				cout<<"s";
				delay(25);
				cout<<"e";
				delay(25);
				cout<<"i";
				delay(25);
				cout<<"n";
				delay(25);
				cout<<"i";
				delay(25);
		}
		if (s==13 && x==19)
		{       cout<<"\a";
			exit(0);
		}
		s=getch();
	}
}
////////////////////////////////////////////////////////////////////
void load()
{
	int d=DETECT,m=0,c=LIGHTBLUE,p=RED,i,j,k,t;
	initgraph(&d,&m,"c:\\tc\\bgi");
	delay(1000);
	setbkcolor(0);
	settextstyle(5,0,8);
	setfillstyle(1,0);
	rectangle(250,270,352,290);
	setcolor(8);
	rectangle(249,269,353,291);
	for (i=0,k=251;i<=101,k<=351;i++,k++)
	{       setcolor(c);
		outtextxy(150,120,"Loading...");
		setfillstyle(3,0);
		textcolor(8);
		for (j=271;j<=289;j++)
		{	putpixel(k,j,7);
			delay(2);

		}
		gotoxy(37,20);
		printf("%d%",i);
	}
	delay(1000);
}
