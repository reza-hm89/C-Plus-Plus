#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
class integer_matris
{
private:
   int a[10][10];
   int row;
   int col;
   int i;
   int j;
   int k;
public:
   integer_matris();
   void getrc(int,int);
   void input();
   void output();
   integer_matris operator+(integer_matris);
   integer_matris operator-(integer_matris);
   integer_matris operator*(integer_matris);
};
//******************************************************************************
integer_matris::integer_matris()
{
for(i=0;i<10;i++)
	for(j=0;j<10;j++)
		{
	 a[i][j]=0;
	 }//For
}//Costructor
//------------------------------------------------------------------------------
void integer_matris::getrc(int r,int c)
{
row=r;
col=c;
}//Getrc
//------------------------------------------------------------------------------
void integer_matris::input()
{
for(i=0;i<row;i++)
	for(j=0;j<col;j++)
		{
	 cout<<"Integer_Matrix["<<i+1<<"]["<<j+1<<"]=";
	 cin>>a[i][j];
	 }//For
for(int i=0;i<80;i++)
	cout<<"-";
}//Input
//------------------------------------------------------------------------------
void integer_matris::output()
{
for(i=0;i<row;i++)
	for(j=0;j<col;j++)
		{
		gotoxy((j+1)*5,(i+1)*3);
	    cout<<this->a[i][j];
		}//For
}//Output
//------------------------------------------------------------------------------
integer_matris integer_matris::operator+(integer_matris integer_matris2)
{
integer_matris result;
result.getrc(row,col);
for(i=0;i<row;i++)
	for(j=0;j<col;j++)
		result.a[i][j]=this->a[i][j]+integer_matris2.a[i][j];
return result;
}//operator+
//------------------------------------------------------------------------------
integer_matris integer_matris::operator-(integer_matris integer_matris2)
{
integer_matris result;
result.getrc(row,col);
for(i=0;i<row;i++)
	for(j=0;j<col;j++)
		result.a[i][j]=this->a[i][j]-integer_matris2.a[i][j];
return result;
}//operator-
//------------------------------------------------------------------------------
integer_matris integer_matris::operator*(integer_matris integer_matris2)
{
integer_matris result;
result.getrc(row,integer_matris2.col);
for(i=0;i<10;i++)
	for(j=0;j<10;j++)
		result.a[i][j]=0;
for(i=0;i<row;i++)
	for(j=0;j<integer_matris2.col;j++)
		for(k=0;k<col;k++)
			result.a[i][j]+=this->a[i][k]*integer_matris2.a[k][j];
return result;
}//operator*
//******************************************************************************
void main()
{
int f1=1,f2=1,m1r,m2r,m3r,m1c,m2c,m3c;
integer_matris integer_matris1,integer_matris2,integer_matris3;
char ch;
//------------------------------------------------------------------------------
clrscr();
cout<<"First Row:";
cin>>m1r;
cout<<"First Col:";
cin>>m1c;
cout<<"Second Row:";
cin>>m2r;
cout<<"Second Col:";
cin>>m2c;
//------------------------------------------------------------------------------
if((m1r==m2r)&&(m1c==m2c)&&(m1r==m2c))
	{
	f1=1;
   f2=1;
   }//If
else
	if((m1r==m2r)&&(m1c==m2c))
		f1=0;
	else
		if(m1c==m2r)
			f2=0;
      else
	{
	 clrscr();
	 cout<<"Your Sizes For Integer_Matrixes Are Not Correct";
	 gotoxy(80,25);
	 getch();
	 exit(0);
	 }//Else
//------------------------------------------------------------------------------
integer_matris1.getrc(m1r,m1c);
integer_matris2.getrc(m2r,m2c);
//------------------------------------------------------------------------------
if(f1==1&&f2==1)
	integer_matris3.getrc(m1r,m1c);
else
	if(f1==1&&f2==0)
      integer_matris3.getrc(m1r,m2c);
   else
	if(f1==0&&f2==1)
	integer_matris3.getrc(m1r,m1c);
//------------------------------------------------------------------------------
integer_matris1.input();
integer_matris2.input();
//------------------------------------------------------------------------------
while((ch=getch())!=27)
	{
	switch(ch)
		{
		case '+':
		clrscr();
		if(f2==0)
			{
			cout<<"You Can Not Use It At This Time";
			gotoxy(80,25);
			}//If
		else
			{
			cout<<"Integer_Matrix1 + Integer_Matrix2\n";
			cout<<'\n';
			integer_matris3=integer_matris1+integer_matris2;
			integer_matris3.output();
	       gotoxy(80,25);
			}//Esle
		break;
      case '-':
		clrscr();
		if(f2==0)
				{
			cout<<"You Can Not Use It At This Time";
			gotoxy(80,25);
			}//If
		else
			{
			cout<<"Integer_Matrix1 - Integer_Matrix2\n";
			cout<<'\n';
			integer_matris3=integer_matris1-integer_matris2;
			integer_matris3.output();
	       gotoxy(80,25);
			}//Esle
		break;
		case '*':
		clrscr();
		if(f1==0)
			{
					cout<<"You Can Not Use It At This Time";
			gotoxy(80,25);
			}//If
		else
			{
			cout<<"Integer_Matrix1 * Integer_Matrisx\n";
			cout<<'\n';
			integer_matris3=integer_matris1*integer_matris2;
			integer_matris3.output();
	       gotoxy(80,25);
			}//Else
		break;
      }//Switch
   }//Whlie
//******************************************************************************
}//Main



