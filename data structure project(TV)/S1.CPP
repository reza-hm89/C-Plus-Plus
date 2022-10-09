#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
struct TV
{
	int code;//1
	char name[30];//2
	char crt_date[30];//3
	char dis_date[30];//4
	char frst_rpt[30];//5
	int repeat;//6
	char crt_name[30];//7
	int shabaka;//8
	char pro_type[30];//9
}tv[100];

int count =0;

void add()
{
	cout<<"input code:";
	cin>>tv[count].code;//1
	cout<<"input name:";
	gets(tv[count].name);//2
	cout<<"input tarikhe sakht:";
	gets(tv[count].crt_date);//3
	cout<<"input tedad tekrar:";
	cin>>tv[count].repeat;//6
	cout<<"input name mas'ole sazande:";
	gets(tv[count].crt_name);//7
	cout<<"input shabake morede namayesh:";
	cin>>tv[count].shabaka;//8
	cout<<"input no'e barname:";
	gets(tv[count].pro_type);//9
	count++;
}

void search()
{
	int a;
	cout<<"\ninsert your search: ";
	cin >>a;
	for(int i=0;i<count;i++)
		if(tv[i].code==a)
			break;
if(i<count)
	{
	cout<<"\ncode barname:";
	cout<<tv[i].code;
	cout<<"\nname barname:";
	cout<<tv[i].name;
	cout<<"\ntarikhe sakht:";
	cout<<tv[i].crt_date;
	cout<<"\ntarikhe namayesh:";
	cout<<tv[i].dis_date;
	cout<<"\ntarikhe avalin tekrar:";
	cout<<tv[i].frst_rpt;
	cout<<"\ntedade tekrar:";
	cout<<tv[i].repeat;
	cout<<"\nname mas'ole sazande:";
	cout<<tv[i].crt_name;
	cout<<"\nshabake morede namayesh:";
	cout<<tv[i].shabaka;
	cout<<"no'e barname:";
	cout<<tv[i].pro_type;
	}
	else
		cout<<"\n\n****NOT FOUND****\n\n";
getch();
}

void del()
{
	int a;
	cout<<"\ninsert your delete: ";
	cin >>a;
	for(int i=0;i<count;i++)
		if(tv[i].code==a)
			break;
	if(i<count)
		for(;i<count-1;i++)
			tv[i]=tv[i+1];
	else
		cout<<"\n\n****NOT FOUND****\n\n";
}

void edit()
{
	int a;
	cout<<"\ninsert your edit: ";
	cin >>a;
	for(int i=0;i<count;i++)
		if(tv[i].code==a)
			break;
	if(i<count)
		{
		cout<<"input name:";
		gets(tv[i].name);//2
		cout<<"input tarikhe sakht:";
		gets(tv[i].crt_date);//3
		cout<<"input tedad tekrar:";
		cin>>tv[i].repeat;//6
		cout<<"input name mas'ole sazande:";
		gets(tv[i].crt_name);//7
		cout<<"input shabake morede namayesh:";
		cin>>tv[i].shabaka;//8
		cout<<"input no'e barname:";
		gets(tv[i].pro_type);//9
		}
	else
		cout<<"\n\n****NOT FOUND****\n\n";
}

void print7()
{
	TV tmp;
	for(int i=0;i<count-1;i++)
		for(int j=i+1;j<count;j++)
			if(tv[i].code>tv[j].code)
				{
				tmp=tv[i];
				tv[i]=tv[j];
				tv[j]=tmp;
				}
	for(i=0;i<count;i++)
		{
		cout<<"code barname:";
		cout<<tv[i].code;
		cout<<"\t\tname barname:";
		cout<<tv[i].name;
		cout<<"\t\ttarikhe sakht:";
		cout<<tv[i].crt_date;
		cout<<"\t\ttarikhe namayesh:";
		cout<<tv[i].dis_date;
		cout<<"\t\ttarikhe avalin tekrar:";
		cout<<tv[i].frst_rpt;
		cout<<"\t\ttedade tekrar:";
		cout<<tv[i].repeat;
		cout<<"\t\tname mas'ole sazande:";
		cout<<tv[i].crt_name;
		cout<<"\t\tshabake morede namayesh:";
		cout<<tv[i].shabaka;
		cout<<"\t\tno'e barname:";
		cout<<tv[i].pro_type<<endl;
		getch();
		}
}

void print8()
{


	cout<<"insert your search of namayesh:";
	char tmp[30];
	gets(tmp);
	int q=0;
	for(int i=0;i<count;i++)
		if(strcmp(tv[i].dis_date,tmp)==0)
		{
		q++;
		cout<<"\t\tcode barname:";
		cout<<tv[i].code;
		cout<<"\t\tname barname:";
		cout<<tv[i].name;
		cout<<"\t\ttarikhe sakht:";
		cout<<tv[i].crt_date;
		cout<<"\t\ttarikhe namayesh:";
		cout<<tv[i].dis_date;
		cout<<"\t\ttarikhe avalin tekrar:";
		cout<<tv[i].frst_rpt;
		cout<<"\t\ttedade tekrar:";
		cout<<tv[i].repeat;
		cout<<"\t\tname mas'ole sazande:";
		cout<<tv[i].crt_name;
		cout<<"\t\tshabake morede namayesh:";
		cout<<tv[i].shabaka;
		cout<<"\t\tno'e barname:";
		cout<<tv[i].pro_type<<endl;
		getch();
		}
	if(q==0)
		cout<<"\n\n****NOT FOUND****\n\n";
getch();
}

void print9()
{
	cout<<"insert your search of shabake:";
	int tmp;
	cin>>tmp;
	int q=0;
	for(int i=0;i<count;i++)
		if(tv[i].shabaka==tmp)
			{
			q=1;
			cout<<"code barname:";
			cout<<tv[i].code;
			cout<<"\t\tname barname:";
			cout<<tv[i].name;
			cout<<"\t\ttarikhe sakht:";
			cout<<tv[i].crt_date;
			cout<<"\t\ttarikhe namayesh:";
			cout<<tv[i].dis_date;
			cout<<"\t\ttarikhe avalin tekrar:";
			cout<<tv[i].frst_rpt;
			cout<<"\t\ttedade tekrar:";
			cout<<tv[i].repeat;
			cout<<"\t\tname mas'ole sazande:";
			cout<<tv[i].crt_name;
			cout<<"\t\tno'e barname:";
			cout<<tv[i].pro_type<<endl;
			getch();
			}
	if(q==0)
		cout<<"\n\n****NOT FOUND****\n\n";
getch();
}

void printA()
{
	cout<<"insert your search of sazande:";
	int q=0;
	char tmp[30];
	gets(tmp);
	for(int i=0;i<count;i++)
		if(tv[i].crt_name==tmp)
			{
			q=1;
			cout<<"code barname:";
			cout<<tv[i].code;
			cout<<"\t\tname barname:";
			cout<<tv[i].name;
			cout<<"\t\ttarikhe sakht:";
			cout<<tv[i].crt_date;
			cout<<"\t\ttarikhe namayesh:";
			cout<<tv[i].dis_date;
			cout<<"\t\ttarikhe avalin tekrar:";
			cout<<tv[i].frst_rpt;
			cout<<"\t\ttedade tekrar:";
			cout<<tv[i].repeat;
			cout<<"\t\tshabake morede namayesh:";
			cout<<tv[i].shabaka;
			cout<<"\t\tno'e barname:";
			cout<<tv[i].pro_type<<endl;
			getch();
			}
	if(q==0)
		cout<<"\n\n****NOT FOUND****\n\n";
getch();
}

void add_date()
{
	int a;
	cout<<"\ninsert your search: ";
	cin >>a;
	for(int i=0;i<count;i++)
		if(tv[i].code==a)
			break;
if(i<count)
	{
	if(strcmp(tv[i].dis_date,NULL)==0)
	{
	cout<<"\ninsert the date : ";
	gets(tv[i].dis_date);
	}
	else
	{
	cout<<"\nghablan sabt shode\n";
	}
	}
else
	{
	cout<<"\n\n****NOT FOUND****\n\n";
	}
	getch();


}

void add_date_r()
{
	int a;
	cout<<"\ninsert your search: ";
	cin >>a;
	for(int i=0;i<count;i++)
		if(tv[i].code==a)
			break;
if(i<count)
	{
	if(strcmp(tv[i].frst_rpt,NULL)==0)
	{
	cout<<"\ninsert the date : ";
	gets(tv[i].frst_rpt);
	}
	else
	{
	cout<<"\nghablan sabt shode\n";
	}
	}
else
	{
	cout<<"\n\n****NOT FOUND****\n\n";
	}
	getch();


}

void show_r()
{
	int a;
	cout<<"\ninsert your repeat: ";
	cin >>a;
	TV tmp;
	for(int i=0;i<count-1;i++)
		for(int j=i+1;j<count;j++)
			if(tv[i].code>tv[j].code)
				{
				tmp=tv[i];
				tv[i]=tv[j];
				tv[j]=tmp;
				}
	for(i=0;i<count;i++)
		{
	   if(tv[i].repeat>=a)
	   {
		cout<<"code barname:";
		cout<<tv[i].code;
		cout<<"\t\tname barname:";
		cout<<tv[i].name;
		cout<<"\t\ttarikhe sakht:";
		cout<<tv[i].crt_date;
		cout<<"\t\ttarikhe namayesh:";
		cout<<tv[i].dis_date;
		cout<<"\t\ttarikhe avalin tekrar:";
		cout<<tv[i].frst_rpt;
		cout<<"\t\ttedade tekrar:";
		cout<<tv[i].repeat;
		cout<<"\t\tname mas'ole sazande:";
		cout<<tv[i].crt_name;
		cout<<"\t\tshabake morede namayesh:";
		cout<<tv[i].shabaka;
		cout<<"\t\tno'e barname:";
		cout<<tv[i].pro_type<<endl;
		getch();
	   }
		}
}



void main()
{

FILE *L;
L=fopen("input.txt","r");
fscanf(L,"%d ",&count);
for(int i=0;i<count;i++)
{
	fscanf(L,"%d ",&tv[i].code);
	fscanf(L,"%s ",&tv[i].name);
	fscanf(L,"%s ",&tv[i].crt_date);
	fscanf(L,"%s ",&tv[i].dis_date);
	fscanf(L,"%s ",&tv[i].frst_rpt);
	fscanf(L,"%d ",&tv[i].repeat);
	fscanf(L,"%s ",&tv[i].crt_name);
	fscanf(L,"%d ",&tv[i].shabaka);
	fscanf(L,"%s\n",&tv[i].pro_type);
}
fclose(L);
char ch;
do{
	clrscr();
	cout<<"1 _ Add\n";
	cout<<"2 _ Delete\n";
	cout<<"3 _ Edit\n";
	cout<<"4 _ Search\n";
	cout<<"5 _ Add Date\n";
	cout<<"6 _ Add Date Repeat\n";
	cout<<"7 _ Show\n";
	cout<<"8 _ Show In Date\n";
	cout<<"9 _ Show chanell\n";
	cout<<"A _ Show compani\n";
	cout<<"B _ Show Repeat 'n'\n";
	cout<<"Esc _ EXIT\n\n";
	ch=getch();
	switch(ch)
	{
		case('1'):
			add();
			break;

		case('2'):
			del();
			break;

		case('3'):
			edit();
			break;

		case('4'):
			search();
			break;

		case('5'):
			add_date();
			break;

		case('6'):
			add_date_r();
			break;

		case('7'):
			print7();
			break;

		case('8'):
			print8();
			break;

		case('9'):
			print9();
			break;

		case('a'):
			printA();
			break;

		case('b'):
			show_r();
			break;
	}
}while(ch!=27);
FILE *S;
S=fopen("input.txt","w");
fprintf(S,"%d ",count);
for( i=0;i<count;i++)
{
	fprintf(S,"%d ",tv[i].code);
	fprintf(S,"%s ",tv[i].name);
	fprintf(S,"%s ",tv[i].crt_date);
	fprintf(S,"%s ",tv[i].dis_date);
	fprintf(S,"%s ",tv[i].frst_rpt);
	fprintf(S,"%d ",tv[i].repeat);
	fprintf(S,"%s ",tv[i].crt_name);
	fprintf(S,"%d ",tv[i].shabaka);
	fprintf(S,"%s\n",tv[i].pro_type);
}
fclose(S);
}