#include<iostream.h>
#include<conio.h>
#include<string.h>
int main()
{       char s[100],s1[100];
	int i,n,a,x=0,k=1,j=0,sum1=0,sum2=0;
	clrscr();
	cout<<"Enter your Statement :\n\n";
	cin.get(s,100);
	n=strlen(s);
	for (i=0;i<n;i++)
	{
		if (s[i]==' ')
			k++;
	}
	while (n!=0)
	{
		for (i=x;s[i]!=' ';i++)
		{
			s1[i]=s[i];
			x++;
		}
		a=strlen(s1);
		if (a==1)
			sum1++;
		if (a==2)
			sum2++;
		n--;
		a=0;
	}
	cout<<"\nTedad kalamat: "<<k;
	cout<<"\n"<<s1;
	cout<<"\nTeadad Kalamate 1 harfi: "<<sum1;
	cout<<"\nTeadad Kalamate 2 harfi: "<<sum2;
	getch();
	return 0;
}
