#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

/*struct student
{ char name[50];
char family[50];
long int id;
}st[50],ears;
*/
struct dars
{
  char darsname[50];
  int cod;
  int vahed;
}d1[10];

class student {
	char name[50];
	char family[50];
	long id;
	dars d[20];
	public :
	int tdars;
	student () {tdars=0;}
	int Ret_id();
	char* Ret_family();
	void Input();
	void Input_Dars();
	void Edit();
	void Edit_Dars(int i,int cod1);
	void Show(int r);
	void Show2(int e,int s,int x);
	void Show_Dars(int j,int e,int s,int x);

}st[20];
//--------------------------------------------------------------------------
int student :: Ret_id()
	{
		return id;
	}
char* student :: Ret_family()
	{
		return family;
	}
void student :: Input()
	{
		cout<<"name:";
		gets(name);
		cout<<"family:";
		gets(family);
		cout<<"id:";
		cin>>id;
	}
	void student :: Input_Dars()
	{
		cout<<"darsname:";
		gets(d[tdars].darsname);
		cout<<"cod:";
		cin>>d[tdars].cod;
		cout<<"vahed:";
		cin>>d[tdars++].vahed;
	}
	void student :: Edit()
	{
		gotoxy(2,10);
		cin>>name;
		gotoxy(10,10);
		cin>>family;
		gotoxy(23,10);
		cin>>id;
	}
	void student :: Edit_Dars(int i,int cod1)
	{
		if(d[i].cod==cod1)
		{
			gotoxy(2,10);
			cin>>d[i].darsname;
			gotoxy(10,10);
			cin>>d[i].cod;
			gotoxy(23,10);
			cin>>d[i].vahed;
		}
	}
	void student :: Show(int r)
	{
		gotoxy(2,r);
		cout<<name;
		gotoxy(10,r);
		cout<<family;
		gotoxy(23,r);
		cout<<id;
	}
	void student :: Show2(int e,int s,int x)
	{
	gotoxy(21,e);
	puts(name);
	gotoxy(23,s);
	puts(family);
	gotoxy(21,x);
	cout<<id;
	}
	void student :: Show_Dars(int j,int e,int s,int x)
	{
		gotoxy(21,e);
		puts(d[j].darsname);
		gotoxy(23,s);
		cout<<d[j].cod;
		gotoxy(25,x);
		cout<<d[j].vahed;
	}
//--------------------------------------------------------------------------
struct entekhab
{
   long int shom;
   long int dar;
}ent[100];
//--------------------------------------------------------------------------
FILE *fp,*fd,*fe;
int k=0,t=0,q=0;
//-----------------------------------------------------------------------------------
/*void save()
{
    register int i;
    FILE *fp;
    fp=fopen("st.txt","w+b");
    if(!fp){
  // -setcursortype(-NOCURS
    cout<<"\n cannot open file pres key...";
    getch();
    return;
   }
   for(i=0;i<k && st[i].name[0]!='\0';i++)
     fwrite(&st[i],sizeof(st),1,fp);
   fclose(fp);
}
//----------------------------------------------------------------------------
void load()
{
register int i;
FILE *fp;
clrscr();
fp=fopen("st.txt","rb");
if(!fp){
cout<<"\n cannot ope file press key...";
getch();
return;
}
for(i=0;i<k;i++){
fread(&st[i],sizeof(struct student),1,fp);
if(feof(fp)){
clrscr();
cout<<"data loaded press a key...";
getch();
return;
}
}
fclose(fp);
}*/
//--------------------------------------------------------------------------------
void entkh()
{
int i;
char ch;

clrscr();
for(i=0;ch!='n';i++)
{
cout<<"shomareye daneshju?";
cin>>ent[i].shom;
cout<<"code dars?";
cin>>ent[i].dar;
cout<<"cauntinue?(y/n)";
ch=getch();

q++;

}


fe=fopen("khab.txt","a+b");
for(i=0;i<q;i++)
 fwrite(&ent[i],sizeof(struct entekhab),1,fe);
fclose(fe);






}
//--------------------------------------------------------------------------------
void nake()
{

int i;
long int co;
clrscr();
fe=fopen("khab.txt","rb");
for(i=0;!feof(fe);i++)
 fread(&ent[i],sizeof(struct entekhab),1,fe);
fclose(fe);
cout<<"code kelas?";
cin>>co;
for(i=0;i<q;i++)
{
if(co==ent[i].dar) cout<<ent[i].shom;

}

getch();
}
//--------------------------------------------------------------------------------
void adddaneshjo()
{
clrscr();
fp=fopen("dan.txt","w+b");
 int i,j;
 char ans;
  for(i=0;ans!='n'&&i<50;i++)
  {
	st[i].Input();

 k++;
puts("do you want cauntinue?(y/n)");
ans=getch();
}
j=i;
for(j=0;j<i;j++)
 fwrite(&st[j],sizeof(struct student),1,fp);
 //fflush(fp);
 fclose(fp);
// save();
}
//--------------------------------------------------------------------------------
void adddars()
{
 t=0;
 clrscr();
 int i;
 char ans;
  for(i=0;ans!='n'&&i<50;i++)
  {
	st[i].Input_Dars();

 t++;
puts("do you want cauntinue?()y/n");
ans=getch();
}
remove("dar.txt");
fd=fopen("dar.txt","a+b");
for(i=0;i<t;i++)
 fwrite(&st[i],sizeof(struct dars),1,fd);
fclose(fd);
}
//----------------------------------------------------------------------------------
void hazfdaneshjo()
{
  clrscr();
  int i,j;
  long int id1;
  cout<<"id1=";
  cin>>id1;
  for(i=0;i<=k;i++)
   if(st[i].Ret_id()==id1)
   {
       k--;
       for(j=i;j<=k;j++)
	 st[j]=st[j+1];
      i--;
    getch();
   }
}
//----------------------------------------------------------------------------------
void hazfdars()
{
    int i,j;
  fp=fopen("dar.txt","a+b");
for(i=0;d1[i].darsname[0];i++)
 fread(&d1[i],sizeof(struct dars),1,fd);
fclose(fd);

  clrscr();

  long int cod1;
  cout<<"cod1=";
  cin>>cod1;
  for(i=0;i<=t;i++)
   if(d1[i].cod==cod1)
   {
       t--;
       for(j=i;j<=t;j++)
	 d1[j]=d1[j+1];
      i--;
   }
   getch();
}
//----------------------------------------------------------------------------------
void viraishdaneshjo()
{

long int id1;
int i;
clrscr();


  fp=fopen("dan.txt","a+b");
  for(i=0;!feof(fp);i++)
     fread(&st[i],sizeof(struct student),1,fp);


gotoxy(2,6);
cout<<"name";
gotoxy(10,6);
cout<<"family";
gotoxy(23,6);
cout<<"id";
gotoxy(2,8);
for (i=1;i<=65;i++)
cout<<"-";
gotoxy(2,2);
cout<<"please enter id for viraish:";
cin>>id1;

for(i=0;i<k;i++)
{
if(st[i].Ret_id()==id1)
{
	st[i].Edit();
}

}
fclose(fp);
rewind(fp);
fp=fopen("dan.txt","a+b");
for(int j=0;j<k;j++)
 fwrite(&st[j],sizeof(struct student),1,fp);
fclose(fp);
getch();

}

//-----------------------------------------------------------------------------
void viraishdars()
{
long int cod1;
int i,j;

  fd=fopen("dar.txt","a+b");
   for(j=0;!feof(fd);j++)
     fread(&d1[j],sizeof(struct dars),1,fd);


clrscr();
gotoxy(2,6);
cout<<"name";
gotoxy(10,6);
cout<<"cod";
gotoxy(23,6);
cout<<"vahed";
gotoxy(2,8);
for (i=1;i<=65;i++)
cout<<"-";
gotoxy(2,2);
cout<<"please enter cod for viraish :";


cin>>cod1;
for(i=0;i<st[i].tdars;i++)
{
	st[i].Edit_Dars(i,cod1);
}

fclose(fd);
rewind(fd);
  fd=fopen("dar.txt","a+b");
   for(j=0;j<t;j++)
     fwrite(&d1[j],sizeof(struct dars),1,fd);


getch();

}
//-----------------------------------------------------------------------------------
void moratab()
{
int v,i,j,s,r,h;

  fp=fopen("dan.txt","a+b");
  for(i=0;!feof(fp);i++)
     fread(&st[i],sizeof(struct student),1,fp);


student temp;

clrscr();
gotoxy(1,2);
cout<<"enter 1 bar asase id, 2 bar asase family:";
cin>>v;
if(v==2)
{
for(i=0;i<k;i++)
for(j=i+1;j<k;j++)
if(strcmp(st[i].Ret_family(),st[j].Ret_family())>0)
{
temp=st[i];
st[i]=st[j];
st[j]=temp;
}
gotoxy(2,6);
cout<<"name";
gotoxy(10,6);
cout<<"family";
gotoxy(23,6);
cout<<"id";
gotoxy(2,8);
for(h=1;h<=65;h++)
cout<<"-";

r=10;
for(i=0;i<k;i++)
{
	st[i].Show(r);
	r++;
}
}
if(v==1)
{
for(i=0;i<k;i++)
for(j=i;j<k;j++)
if(st[i].Ret_id()>st[j].Ret_id())
{
temp=st[i];
st[i]=st[j];
st[j]=temp;
}
gotoxy(2,6);
cout<<"name";
gotoxy(10,6);
cout<<"family";
gotoxy(23,6);
cout<<"id";
gotoxy(2,8);
for (i=1;i<=65;i++)
cout<<"-";
int y=10;
for(i=0;i<k;i++)
{
	st[i].Show(y);
y++;
}
}


fclose(fp);
rewind(fp);
remove("dan.txt");
fp=fopen("dan.txt","a+b");
for(j=0;j<k;j++)
 fwrite(&st[j],sizeof(struct student),1,fp);
fclose(fp);


getch();
}
//---------------------------------------------------------------------------------------------------------------------------------------
void serch()
{
int x,i;

  fp=fopen("dan.txt","a+b");
  for(i=0;!feof(fp);i++)
     fread(&st[i],sizeof(struct student),1,fp);



long int id3;
char family2[20];
clrscr();
 gotoxy(1,1);
cout<<"enter 1 bar asase family,2 bar asase id:";
cin>>x;

gotoxy(2,6);
cout<<"name";
gotoxy(10,6);
cout<<"family";
gotoxy(23,6);
cout<<"id";
gotoxy(2,8);
for(i=1;i<=65;i++)
cout<<"-";
if(x==1)
{
int q=10;
gotoxy(1,4);
cout<<"family:";
gets(family2);
for(i=0;i<=k;i++)
if(!strcmp(st[i].Ret_family(),family2))
{
	st[i].Show(q);
}
  q++;
}
if(x==2)
{
     gotoxy(1,2);
     cout<<"id:";
     cin>>id3;
     int m=10;
     for(i=0;i<k;i++)
     if(st[i].Ret_id()==id3)
     {
	st[i].Show(m);
	m++;
}
m+=4;
}
getch();
}
//---------------------------------------------------------------------------------------------------
void showdaneshjo()
{
  clrscr();
    int i,e=10,s=20,x=30,j;
  fp=fopen("dan.txt","rb");
  for(i=0;!feof(fp);i++)
     fread(&st[i],sizeof(struct student),1,fp);
    gotoxy(15,10);
    cout<<"name:";
    gotoxy(15,20);
   cout<<"famili:";
  gotoxy(15,30);
  cout<<"id:";
  for(j=0;j<i-1;j++)
  {
    st[j].Show2(e,s,x);
  e++;s++;x++;
   }
   getch();
}
//------------------------------------------------------------------------------
 void showdars()
{
  clrscr();
  int j,e=10,s=20,x=30;
  fd=fopen("dar.txt","rb");
   for(j=0;!feof(fd);j++)
     fread(&d1[j],sizeof(struct dars),1,fd);
    gotoxy(15,10);
    cout<<"name:";
    gotoxy(15,20);
    cout<<"cod:";
    gotoxy(15,30);
    cout<<"vahed";
  for(j=0;d1[j].darsname[0];j++)
  {
    st[j].Show_Dars(j,e,s,x);
   e++;s++;x++;
   }
   getch();
}
//---------------------------------------------------------------------------------
void meno()
{
   gotoxy(20,4);
   cout<<"q for adddanehjo";
   gotoxy(20,8);
   cout<<"w for adddars";
   gotoxy(20,12);
   cout<<"e for hazf daneshjo";
   gotoxy(20,16);
   cout<<"r for hazf dars";
   gotoxy(20,20);
   cout<<"t for viraish daneshjo";
   gotoxy(20,24);
   cout<<"y for viraish dars";
   gotoxy(20,28);
   cout<<"u for show daneshjo";
   gotoxy(20,32);
   cout<<"i for show dars";
   gotoxy(20,36);
   cout<<"o for moratab";
   gotoxy(20,40);
   cout<<"p for serch";
   gotoxy(20,44);
   cout<<"a for entekhab vahed";
   gotoxy(20,46);
   cout<<"b for namayesh kelas";
   gotoxy(20,48);
   cout<<"m=";

//   getch();

}
//--------------------------------------------------------------------------------
int main()
{
     char m;
     do{
	clrscr();
	meno();
	m=getch();
	switch(m)
	{
	    case 'q':
		  adddaneshjo();
		  break;
	    case 'w':
		  adddars();
		  break;
	    case 'e':
		  hazfdaneshjo();
		  break;
	    case 'r':
		  hazfdars();
		  break;
	    case 't':
		  viraishdaneshjo();
		  break;
	    case 'y':
		  viraishdars();
		  break;
	    case 'u':
		  showdaneshjo();
		  break;
	    case 'i':
		  showdars();
		  break;
	    case 'o':
		  moratab();
		  break;
	    case 'p':
		  serch();
		  break;
	    case 'a':
		  entkh();
		  break;
	    case 'b':
		  nake();
		  break;
	 }
	} while(m!=27);
      //	getch();
	return 0;
}
