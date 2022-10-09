#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<windows.h>
#include<math.h>

using namespace std;

class Array
{
	public:
		int *a,n,r;
		char str[100];

		void ConvertTo10();
		int* Sum(int*,int*,int,int);
		int* Sub(int*,int*,int,int);
		int Compare(int*,int*,int,int);
		void SetToZero(int *,int);
		friend int Compare1(int,int);
		Array operator+(Array);
		Array operator++();
		Array operator++(int);
		Array operator-(Array);
		Array operator--();
		Array operator--(int);
		Array operator*(Array);
		Array operator/(Array);
		Array operator+=(Array);
		Array operator-=(Array);
		Array operator*=(Array);
		Array operator/=(Array);
		Array operator=(Array);
		friend istream &operator>>(istream&,Array&);
		friend ostream &operator<<(ostream&,Array);
		int operator >=(Array);
		int operator <=(Array);
		int operator ==(Array);
		int operator !=(Array);
		int operator !=(int);
};

void Array::ConvertTo10()
{
	int *t,*temp,i,j,k,p=-1,m;
	long int num,tnum;
	
	char s[5];
	a=new int [1];
	n=1;
	SetToZero(a,n);
	a[0]=0;
	for (i=strlen(str);i>=0;i--)
	{
		j=i-1;
		k=0;
		while (str[j]!=' '&& j>=0)
		{
			s[k++]=str[j--];
			i--;
		}
		s[k]=0;
		num=0;
		for (j=k-1;j>=0;j--)
			num=num*10+(s[j]-48);
		p++;
		num=num*((long int)pow((long double)r,p));
		tnum=num;
		j=0;
		while (tnum)
		{
			j++;
			tnum/=10;
		}
		m=j+1;
		t=new int [m];
		SetToZero(t,m);
		temp=new int [m];
		SetToZero(temp,m);
		for (j=0;j<n;j++)
			temp[j]=a[j];
		a=new int [m];
		n=m;

		SetToZero(a,n);
		for (j=0;j<n;j++)
			a[j]=temp[j];
		j=0;
		while (num)
		{
			t[j++]=(int)num%10;
			num/=10;
		}
		
		(*this).a=Sum(a,t,n,m);
		while (num)
		{
			(*this)++;
			num--;
		}
	}
}
void Array::SetToZero(int *ob,int m)
{
	for (int i=0;i<m;i++)
		ob[i]=0;
}
Array Array::operator+(Array op1)
{
	Array result;
	if (n>=op1.n)
		result.n=n+1;
	else
		result.n=op1.n+1;
	result.a=new int[result.n];
	SetToZero(result.a,result.n);
	result.a=Sum(a,op1.a,n,op1.n);
	return result;
}
Array Array::operator++()
{

	int i=0,x=0;
	for (i=0;i<n;i++)
		if (a[i]!=9)
			x=1;
	if (x==0)
	{
		int *p;
		p=new int [n+1];
		SetToZero(p,n+1);
		for (i=0;i<n;i++)
			p[i]=a[i];
		a=new int [n+1];
		SetToZero(a,n+1);
		n++;
		for (i=0;i<n;i++)
			a[i]=p[i];
	}

	if (a[0]!=9)
		a[0]++;
	else
	{
		i=0;
		while (a[i]>=9 && i<n)
		{
			a[i]=0;
			a[i+1]++;
			if (a[i+1]==9)
				break;
			i++;
			
		}
	}
	return *this;
}
Array Array::operator++(int x)
{
	x=0;
	int i=x;
	for (i=0;i<n;i++)
		if (a[i]!=9)
			x=1;
	if (x==0)//agar hamash 9 bud
	{
		int *p;
		p=new int [n+1];
		SetToZero(p,n+1);
		for (i=0;i<n;i++)
			p[i]=a[i];
		a=new int [n+1];
		SetToZero(a,n+1);
		n++;
		for (i=0;i<n;i++)
			a[i]=p[i];
	}

	if (a[0]!=9)
		a[0]++;
	else
	{
		i=0;
		while (a[i]>=9 && i<n)
		{
			a[i]=0;
			a[i+1]++;
			i++;
			if (a[i]==9)
				break;
		}
	}
	return *this;
}
Array Array::operator-(Array op1)
{
	Array result;
	if (n>=op1.n)
		result.n=n;
	else
		result.n=op1.n;
	result.a=new int[result.n];
	SetToZero(result.a,result.n);
	result.a=Sub(a,op1.a,n,op1.n);
	return result;
}
Array Array::operator--()
{
	int i,j;
	if (a[0]!=0)
			a[0]--;
	else
	{
		i=0;
		if (a[i]<1)
		{
			while (a[i]==0)
			{
				for (j=i+1;a[j]==0 && j<n;j++);
				a[j]--;
				a[j-1]+=10;
			}
		}
		a[i]=a[i]-1;
	}
	return *this;
}
Array Array::operator--(int x)
{
	int i,j;
	if (a[0]!=0)
			a[0]--;
	else
	{
		i=0;
		if (a[i]<1)
		{
			while (a[i]==0)
			{
				for (j=i+1;a[j]==0 && j<n;j++);
				a[j]--;
				a[j-1]+=10;
			}
		}
		a[i]=a[i]-1;
	}
	return *this;
}

Array Array::operator*(Array ob)
{
	int *t,i;
	Array temp=ob,result;
	result.a=new int [n+ob.n];
	result.n=n+ob.n;
	SetToZero(result.a,result.n);
	while (temp!=0)
	{
		result=result+(*this);
		t=new int [result.n];
		SetToZero(t,result.n);
		for (i=0;i<result.n;i++)
			t[i]=result.a[i];
		i--;
		while (t[i]==0)
		{
			i--;
		}
		result.a=new int [i+1];
		result.n=i+1;
		SetToZero(result.a,result.n);
		for (i=0;i<result.n;i++)
			result.a[i]=t[i];
		temp--;
	}
	return result;
}
Array Array::operator/(Array ob)
{
	Array result,temp;
	temp.a=new int [(*this).n];
	temp.n=(*this).n;
	SetToZero(temp.a,temp.n);
	for (int i=0;i<(*this).n;i++)
		temp.a[i]=(*this).a[i];
	result.a=new int [(*this).n];
	result.n=(*this).n;
	SetToZero(result.a,result.n);
	while (temp>=ob)
	{
		temp.a=Sub(temp.a,ob.a,temp.n,ob.n);
		result++;
	}
	return result;
}
Array Array::operator+=(Array ob1)
{
	int max;
	if (ob1.n>n)
		max=ob1.n;
	else 	max=n;

	int *p,i;
	p=new int [max+1];
	SetToZero(p,max+1);
	for (i=0;i<n;i++)
		p[i]=a[i];
	a=new int [max+1];
	n=max+1;
	for (i=0;i<n;i++)
		a[i]=p[i];

	(*this).a=Sum(a,ob1.a,n,ob1.n);
	return *this;
}
Array Array::operator-=(Array ob1)
{
	int max;
	if (ob1.n>n)
		max=ob1.n;
	else 	max=n;

	int *p,i;
	p=new int [max];
	SetToZero(p,max);
	for (i=0;i<n;i++)
		p[i]=a[i];
	a=new int [max];
	n=max;
	for (i=0;i<n;i++)
		a[i]=p[i];

	(*this).a=Sub(a,ob1.a,n,ob1.n);
	return *this;
}
Array Array::operator *=(Array ob)
{
	*this=(*this)*ob;
	return *this;
}
Array Array::operator /=(Array ob)
{
	Array temp;
	temp.a=new int [(*this).n];
	temp.n=(*this).n;
	SetToZero(temp.a,temp.n);
	for (int i=0;i<(*this).n;i++)
		temp.a[i]=(*this).a[i];
	*this=temp/ob;
	return *this;
}
Array Array::operator=(Array ob1)
{
	a=new int [ob1.n];
	n=ob1.n;
	SetToZero(a,n);
	for (int i=0;i<ob1.n;i++)
		a[i]=ob1.a[i];
	return *this;
}
istream &operator>>(istream &input,Array &ob1)
{
	char ch=0;
	int i=0;
	cout<<"\n";
	while (ch!=13)
	{
		ch=getche();
		ob1.str[i++]=ch;
	}
	ob1.str[i-1]='\0';
	cout<<"\n";
	return input;
}
ostream &operator<<(ostream &output,Array ob1)
{
	for (int i=ob1.n-1;i>=0;i--)
		cout<<ob1.a[i];
	return output;
}
int Array::operator>=(Array ob)
{
	int i,*t;
	if (n>=ob.n)
	{
		t=new int [n];
		SetToZero(t,n);
		for (i=0;i<ob.n;i++)
			t[i]=ob.a[i];
		for (i=n-1;i>=0;i--)
		{
			if (a[i]>t[i])
				return 1;
			else if (a[i]<t[i])
				return 0;
		}
	}	
	else
	{
		t=new int [ob.n];
		SetToZero(t,ob.n);
		for (i=0;i<n;i++)
			t[i]=a[i];
		for (i=ob.n-1;i>=0;i--)
		{
			if (ob.a[i]<t[i])
				return 1;
			else if (ob.a[i]>t[i])
				return 0;
		}
	}
	int sw=1;
	for (i=n-1;i>=0;i--)
		if (a[i]!=t[i])
			sw=0;
	if (sw==1)
		return 1;
	return 0;
}
int Array::operator<=(Array ob)
{
	int i,*t;
	if (n>=ob.n)
	{
		t=new int [n];
		SetToZero(t,n);
		for (i=0;i<ob.n;i++)
			t[i]=ob.a[i];
		for (i=n-1;i>=0;i--)
		{
			if (a[i]<t[i])
				return 1;
			else if (a[i]>t[i])
				return 0;
		}
	}	
	else
	{
		t=new int [ob.n];
		SetToZero(t,ob.n);
		for (i=0;i<n;i++)
			t[i]=a[i];
		for (i=ob.n-1;i>=0;i--)
		{
			if (ob.a[i]>t[i])
				return 1;
			else if (ob.a[i]<t[i])
				return 0;
		}
	}
	int sw=1;
	for (i=n-1;i>=0;i--)
		if (a[i]!=t[i])
			sw=0;
	if (sw==1)
		return 1;
	return 0;
}
int Array::operator==(Array ob)
{
	int sw=0;
	if (n==ob.n)
	{
		for (int i=n-1;i>=0;i--)
		{
			if (a[i]!=ob.a[i])
				sw=1;
		}
		if (sw==0)
			return 1;
	}
	return 0;
}
int Array::operator!=(Array ob)
{
	int sw=0;
	if (n==ob.n)
	{
		for (int i=n-1;i>=0;i--)
		{
			if (a[i]!=ob.a[i])
				sw=1;
		}
		if (sw==0)
			return 0;
	}
	return 1;
}
int Array::operator!=(int x)
{
	int sw=0;x=0;
	for (int i=0;i<n;i++)
		if (a[i]!=x)
			sw=1;
	return sw;
}
int* Array::Sum(int *a,int *b,int n,int m)
{
	int *c,*t,i,j,temp,max,k=0;
	if (n>=m)
	{
		c=new int [n+1];
		t=new int [n];
		SetToZero(c,n+1);
		SetToZero(t,n+1);
		for (i=0;i<m;i++)
			t[i]=b[i];
		b=new int [n];
		SetToZero(b,n+1);
		for (i=0;i<n;i++)
			b[i]=t[i];
		max=n;
	}
	else
	{
		c=new int [m+1];
		t=new int [m];
		SetToZero(c,m+1);
		SetToZero(t,m+1);
		for (i=0;i<n;i++)
			t[i]=a[i];
		a=new int [m];
		SetToZero(a,m+1);
		for (i=0;i<m;i++)
			a[i]=t[i];
		max=m;
	}
	for (i=0;i<max;i++)
	{
		temp=a[i]+b[i];
		if (temp>=10)
		{
			c[k]=temp-10;
			a[i+1]++;
			if (i+1==max)
				c[k+1]++;
		}
		else
		{
			c[k]=temp;
		}
		k++;
	}
	return c;
}
int* Array::Sub(int *a,int *b,int n,int m)
{
	int *c,*t,max,i,j,k=0;
	
	if (n>=m)
	{
		c=new int [n];
		t=new int [n];
		SetToZero(c,n+1);
		SetToZero(t,n+1);
		for (i=0;i<m;i++)
			t[i]=b[i];
		b=new int [n];
		SetToZero(b,n+1);
		for (i=0;i<n;i++)
			b[i]=t[i];
		max=n;
	}
	else
	{
		c=new int [m];
		t=new int [m];
		SetToZero(c,m+1);
		SetToZero(t,m+1);
		for (i=0;i<n;i++)
			t[i]=a[i];
		a=new int [m];
		SetToZero(a,m+1);
		for (i=0;i<m;i++)
			a[i]=t[i];
		max=m;
	}
	if (Compare(a,b,n,m)>=0)
	{
		for (i=0;i<max;i++)
		{
			if (a[i]<b[i])
			{
				while (a[i]<b[i])
				{
					for (j=i+1;a[j]==0 && j<max;j++);
					a[j]--;
					a[j-1]+=10;
				}
			}
			if (a[i]>=b[i])
				c[k++]=a[i]-b[i];
		}
	}
	else
	{
		for (i=0;i<max;i++)
		{
			if (b[i]<a[i])
			{
				while (b[i]<a[i])
				{
					for (j=i+1;b[j]==0 && j<max;j++);
					b[j]--;
					b[j-1]+=10;
				}
			}
			if (b[i]>=a[i])
				c[k++]=b[i]-a[i];
		}
		for (j=k-1;c[j]==0&& j>=0;j--);
		c[j]=-c[j];
	}
	return c;
}
int Array::Compare(int *a,int *b,int n,int m)
{
	if (n>m)
		return 1;
	else if (n<m)
		return -1;
	else if (n==m)
	{
		for (int i=n-1;i>=0;i--)
		{
			if (a[i]>b[i])
				return 1;
			else if (a[i]<b[i])
				return -1;
	     }
		return 0;
	}
	return 0;
}
void gotoxy(int x, int y)
{
	static HANDLE hStdout = NULL;
	COORD coord;
	coord.X = x;
	coord.Y = y;

	if(!hStdout)
		hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hStdout,coord);
}
int cnt [2001];
void Input()
{
	Array n1,n2,n3,n4,n5,n6;
	char ch;
	system("cls");
	cout<<"\t\tYou must insert whitespace between each number!";
	cout<<"\n\t\tYo must enter radix between 2 - 2000";
	cout<<"\n\nEnter n1: ";
	cin>>n1;
	cout<<"\nEnter r1: ";
	cin>>n1.r;
	n1.ConvertTo10();
	cout<<"\nEnter n2: ";
	cin>>n2;
	cout<<"\nEnter r2: ";
	cin>>n2.r;
	n2.ConvertTo10();
	cout<<"\nn1: "<<n1;
	cout<<"\nn2: "<<n2;
	cout<<"\n\nn1/n2: ";
	n6=n1/n2;
	cout<<n6;
	cout<<"\nn1+n2: ";
	n3=n1+n2;
	cout<<n3;
	cout<<"\nn1-n2: ";
	n4=n1-n2;
	cout<<n4;
	cout<<"\nn1*n2: ";
	n5=n1*n2;
	cout<<n5;
	
	/*n1++;
	cout<<"\nn1++ : "<<n1;
	n2++;
	cout<<"\nn2++ : "<<n2;
	n1--;
	cout<<"\nn1-- : "<<n1;
	n2--;
	cout<<"\nn2-- : "<<n2;*/

	cnt[n1.r]++;
	cnt[n2.r]++;
	getch();
}
void Show()
{
	system("cls");
	cout<<"Radix    Quantity\n\n";
	for (int i=0;i<2001;i++)
	{
		if (cnt[i])
		{
			cout<<"\n"<<i<<"\t"<<cnt[i];
		}
	}
	getch();
}
void Menu()
{
	int n;
	system("cls");
	cout<<"\n1.Enter number and radix";
	cout<<"\n2.Show quantity of radix";
	cout<<"\n3.Exit";
	cout<<"\n\nEnter Number (1-3): ";
	do
	{
		gotoxy(0,7);
		cout<<"                      ";
		gotoxy(0,7);
		cin>>n;
	}while (n<1 || n>3);
	while (1)
	{
		if (n==1)
		{
			Input();
			Menu();
		}
		else if (n==2)
		{
			Show();
			Menu();
		}
		else if (n==3)
			exit(0);
	}
}
void main()
{
	Menu();
	/*Array n,m,t;
	cin>>n;
	cin>>n.r;
	cin>>m;
	cin>>m.r;
	n.ConvertTo10();
	m.ConvertTo10();
	cout<<n<<"\t"<<m;
	t=n/m;
	cout<<"\n"<<t;*/
	getch();
}
int Compare1(int a,int b)
{
	if (a>b)
		return a;
	else
		return b;
}
