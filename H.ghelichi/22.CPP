#include<stdio.h>
#include<conio.h>
int main()
{
	int i=1,n,a[10];
	clrscr();
	do {
	printf("Enter a 4 digit number: ");
	scanf("%d",&n);}
	while (n<1000 && n>10000);
	while (n!=0)
	{
		a[i]=n%10;
		i++;
		n/=10;
	}
		if (a[4]==1)
			printf("yeksad hezaro");
		else if (a[4]==2)
			printf("do hezaro");
		else if (a[4]==3)
			printf("seh hezaro");
		else if (a[4]==4)
			printf("chahar hezaro");
		else if (a[4]==5)
			printf("panj hezaro");
		else if (a[4]==6)
			printf("chesh hezaro");
		else if (a[4]==7)
			printf("haft hezaro");
		else if (a[4]==8)
			printf("hasht hezaro");
		else if (a[4]==9)
			printf("noh hezaro");
		if (a[3]==1)
			printf(" yeksado");
		else if (a[3]==2)
			printf(" devisto");
		else if (a[3]==3)
			printf(" sisado");
		else if (a[3]==4)
			printf(" chaharsado");
		else if (a[3]==5)
			printf(" pansado");
		else if (a[3]==6)
			printf(" cheshsado");
		else if (a[3]==7)
			printf(" haftsado");
		else if (a[3]==8)
			printf(" hashtsado");
		else if (a[3]==9)
			printf(" nohsado");
		if (a[2]==1)
		{
		if (a[1]==1)
			printf(" yazdah");
		else if (a[1]==2)
			printf("davazdah");
		else if (a[1]==3)
			printf(" sizdah");
		else if (a[1]==4)
			printf(" chahardah");
		else if (a[1]==5)
			printf("panzdah");
		else if (a[1]==6)
			printf("chanzdah");
		else if (a[1]==7)
			printf("hefdah");
		else if (a[1]==8)
			printf("hejdah");
		else if (a[1]==9)
			printf("noozdah");
		}
		else if (a[2]==2)
			printf(" bisto");
		else if (a[2]==3)
			printf(" si'o");
		else if (a[2]==4)
			printf(" chehelo");
		else if (a[2]==5)
			printf(" panjaho");
		else if (a[2]==6)
			printf(" chasto");
		else if (a[2]==7)
			printf(" haftado");
		else if (a[2]==8)
			printf(" hashtado");
		else if (a[2]==9)
			printf(" navado");
		if (a[1]==1)
			printf(" yek");
		else if (a[1]==2)
			printf(" do");
		else if (a[1]==3)
			printf(" seh");
		else if (a[1]==4)
			printf(" chahar");
		else if (a[1]==5)
			printf(" panj");
		else if (a[1]==6)
			printf(" chesh");
		else if (a[1]==7)
			printf(" haft");
		else if (a[1]==8)
			printf(" hasht");
		else if (a[1]==9)
			printf(" noh");
	getch();
	return 0;
}
