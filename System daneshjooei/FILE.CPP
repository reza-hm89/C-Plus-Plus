#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<dos.h>
int menu(void);
void input_st(void);
void selection(void);
void input_lesson(void);
void display_all_st(void);
void display_all_lesson(void);
void delete_unit(void);
void delete_lesson(void);
int search_student(int code,long int *place);
int search_lesson(int code,long int *place);
void show_vahed(int code,int *sum);

struct lesson
{
int code;
char name[20];
int unit;
int del;
};

struct e_vahed
{
int code_st;
int code_l;
int del;
};

struct student
{
int code;
char name[10],family[20],address[80],branch[10];
float ave;
};
//------------------------------------------------------------------
void main()
{
FILE *lfp,*sfp,*efp;
int code_st;
long int place;
int sum;
student st;
sfp=fopen("student.dat","r+b");

while(1)
     {
     switch(menu())
	   {
	   case 1: input_st();break;
	   case 2: input_lesson();break;
	   case 3:
		  clrscr();
		  printf(" input student code to Search:");scanf("%d",&code_st);
		  if(search_student(code_st,&place))
		  {
		     fseek(sfp,place,SEEK_SET);
		     fread(&st,sizeof(st),1,sfp);
		     printf("\n%4d %9s %12s %8s %5.2f %12s",st.code,st.name,st.family,st.branch,st.ave,st.address);
		   }else { printf("\n Not Found Student... ");getch();}
		   show_vahed(code_st,&sum);
		   getch();
		   break;
	   case 4:  display_all_st();break;
	   case 5: display_all_lesson();break;
	   case 6: selection();break;
	   case 7: delete_unit();break;
	   case 8: delete_lesson(); break;
	   default :exit(1);
	   }

     }//while
}
//----------------------------------------------------------------------
int menu(void)
{
int k;
clrscr();
printf("\n\n\n");
printf("\n 1)Insert Student                         ");
printf("\n 2)Insert Lesson                          ");
printf("\n 3)Search Student                         ");
printf("\n 4)Display All Student                    ");
printf("\n 5)Display All Lesson                     ");
printf("\n 6)Entekhab Vahed                         ");
printf("\n 7)Delete Unit of student                 ");
printf("\n 8)Delete Lesson                          ");
printf("\n 9)Exit                                  ");
printf("\n ---------------------------------      ");
printf("\n Favorite Item:");
scanf("%d",&k); return k;
}
//----------------------------------------------------------------------
void input_st(void)
{
FILE *sfp;
student st;
long int place;
char string[80],yes;
clrscr();
sfp=fopen("student.dat","a+b");
if(sfp==NULL) { printf("\n can not open file ");getch(); return;};
top:
printf("id_student:"); scanf("%d",&st.code);
if( search_student(st.code,&place)) { printf("\n this code is Invalid ... ");getch();clrscr();goto top;};
printf("\n name:");scanf("%s",&st.name);
printf("\n family:");scanf("%s",&st.family);
printf("\n reshte:");scanf("%s",&st.branch);
printf("\n addresss:"); scanf("%s",&st.address);
printf("\n average="); scanf("%f",&st.ave);
printf("\n ---------------------");
printf("\n Add this Student(y/n);"); yes=getch();
if(yes=='y' || yes=='Y') fwrite(&st,sizeof(st),1,sfp);
fclose(sfp);
return;
}
//----------------------------------------------------------------------
void input_lesson(void)
{
FILE *lfp;
lesson l;
long int place;
char string[80],yes;
clrscr();
lfp=fopen("lesson.dat","a+b");
if(lfp==NULL) { printf("\n can not open file ");getch(); return;};
label1:
printf("Code_Lesson:"); scanf("%d",&l.code);
if( search_lesson(l.code,&place)) { printf("\n this code is Exist ... ");getch();clrscr();goto label1;};
printf("\n Title Lesson:");scanf("%s",&l.name);
printf("\n Unit =");scanf("%d",&l.unit);
l.del=0;
printf("\n ---------------------");
printf("\n Insert Lesson(y/n);"); yes=getch();
if(yes=='y' || yes=='Y') fwrite(&l,sizeof(l),1,lfp);
fclose(lfp);
return;
}
//----------------------------------------------------------------------
void display_all_st(void)
{
FILE *sfp;
student st;
char string[80],yes;
int row=5;
clrscr();
sfp=fopen("student.dat","r+b");
if(sfp==NULL) { printf("\n can not open file ");getch(); return;};
printf("\n \n");
while(!feof(sfp))
{
fread(&st,sizeof(st),1,sfp);
if(feof(sfp)) break;
gotoxy(5,row);printf("%d",st.code);
gotoxy(12,row);printf("%s",st.name);
gotoxy(22,row);printf("%s",st.family);
gotoxy(37,row);printf("%s",st.branch);
gotoxy(50,row);printf("%4.2f",st.ave);
gotoxy(57,row);printf("%s",st.address);
++row;
}
printf("\n\n\n --------------------------------------------------------------------\n");
getch();
fclose(sfp);
}
//----------------------------------------------------------------------
void display_all_lesson(void)
{
FILE *lfp;
lesson l;
char string[80],yes;
int row=5;
clrscr();
lfp=fopen("lesson.dat","r+b");
if(lfp==NULL) { printf("\n can not open file ");getch(); return;};
printf("\nAll Lesson\n");
while(!feof(lfp))
{
fread(&l,sizeof(l),1,lfp);
if(feof(lfp)) break;
if(l.del==1) continue;
gotoxy(5,row);printf("%d",l.code);
gotoxy(12,row);printf("%s",l.name);
gotoxy(22,row);printf("%d",l.unit);
if(l.del==1){ gotoxy(47,row);printf(" Deleted ");}
++row;
}
printf("\n\n\n--------------------------------------------\n");
getch();
fclose(lfp);
}
//----------------------------------------------------------------------
int search_student(int code,long int *place)
{
FILE *sfp;
student st;
long int p;
char string[80],yes;
clrscr();
sfp=fopen("student.dat","r+b");
if(sfp==NULL) { printf("\n can not open file ");getch(); return 0;};
while(!feof(sfp))
{
p=ftell(sfp);
fread(&st,sizeof(st),1,sfp);
if (code==st.code) { *place=p; fclose(sfp);return 1;}
}
fclose(sfp);
return 0;
}
//----------------------------------------------------------------------
int search_lesson(int code,long int *place)
{
FILE *lfp;
lesson l;
long int p;
char string[80],yes;
//clrscr();
lfp=fopen("lesson.dat","r+b");
if(lfp==NULL) { printf("\n can not open file ");getch(); return 0;};
while(!feof(lfp))
{
p=ftell(lfp);
fread(&l,sizeof(l),1,lfp);
if (code==l.code) { *place=p; fclose(lfp);return 1;}
}
fclose(lfp);
return 0;
}
//----------------------------------------------------------------------
void show_vahed(int code)
{
FILE *efp,*lfp;
e_vahed ev;
lesson l;
long int place;
efp=fopen("e_vahed.dat","r+b");
lfp=fopen("lesson.dat","r+b");
if(efp==NULL) { printf("\n can not open file ");getch(); return;}
printf("\n\n");
while(!feof(efp))
       {
	fread(&ev,sizeof(ev),1,efp);
	if(feof(efp)) break;
	if(ev.code_st!=code || ev.del==1) continue;
	fseek(lfp,0,SEEK_SET);
	while(!feof(lfp))
	     {
	       fread(&l,sizeof(l),1,lfp);
	       if(feof(lfp)) break;
	       if(l.code==ev.code_l) printf("\n %5d    %20s    %4d ",l.code,l.name,l.unit);
	     }//while
	 }
printf("\n----------------------------------------------------------------\n");
fclose(efp);
fclose(lfp);

}
//----------------------------------------------------------------------
void selection(void)
{
FILE *lfp,*sfp,*efp;
int code_st;
int code_l;
int sum;
char yes;
long int position;
student st;
lesson l;
e_vahed ev;
label1:
clrscr();
printf("code student:"); scanf("%d",&code_st); if(code_st==0) return;
sfp=fopen("student.dat","r+b");
lfp=fopen("lesson.dat","r+b");
efp=fopen("e_vahed.dat","a+b");
if(search_student(code_st,&position))
{
fseek(sfp,position,SEEK_SET);
fread(&st,sizeof(st),1,sfp);
printf("\n%4d %9s %12s %8s %5.2f %12s",st.code,st.name,st.family,st.branch,st.ave,st.address);
}else { printf("\n Not Found Student... ");getch(); goto label1;}

printf("\n------------------------------------------------------------------------------");
show_vahed(code_st,&sum);
label2:
printf("\n");
printf("code Lesson:"); scanf("%d",&code_l); if(code_l==0) { fcloseall(); return; }

if(search_lesson(code_l,&position))
{
fseek(lfp,position,SEEK_SET);
fread(&l,sizeof(l),1,lfp);
printf("\n %5d %20s %5d",l.code,l.name,l.unit);
}else { printf("\n Not Found Lesson ... ");getch(); goto label2;}
fseek(efp,0,SEEK_SET);
while(!feof(efp))
{
fread(&ev,sizeof(ev),1,efp);
if(ev.code_st==code_st && ev.code_l==code_l && ev.del==0)
  { printf(" \n this vahed befor selected by you !!!"); getch(); goto label2; }
}

if( ( (st.ave>=12) && ((sum+l.unit)<=20) ) || ( (st.ave<12) && ((sum+l.unit)<=14)) )
 {
printf("\n -----------------------------------------------");
printf("\n Insert  lesson (y/n);"); yes=getch();
if(yes=='y' || yes=='Y') {
 ev.code_st=code_st;  ev.code_l=code_l; ev.del=0;
 fwrite(&ev,sizeof(ev),1,efp);
 }
} else { printf(" \n Sory !!! you are not valid"); getch(); goto label2;}
fclose(efp);
clrscr();
show_vahed(code_st,&sum);
efp=fopen("e_vahed.dat","a+b");
goto label2;
fclose(efp);
fclose(sfp);
show_vahed(code_st,&sum);

}
//----------------------------------------------------------------------
void delete_unit(void)
{
FILE *lfp,*sfp,*efp;
int code_st;
int code_l;
char yes;
long int place;
student st;
lesson l;
e_vahed ev;
label1:
clrscr();
printf("code student:"); scanf("%d",&code_st); if(code_st==0) return;
sfp=fopen("student.dat","r+b");
efp=fopen("e_vahed.dat","r+b");
if(search_student(code_st,&place))
{
fseek(sfp,place,SEEK_SET);
fread(&st,sizeof(st),1,sfp);
printf("\n%4d %9s %12s %8s %5.2f %12s",st.code,st.name,st.family,st.branch,st.ave,st.address);
}else { printf("\n Not Found Student... ");getch(); goto label1;}

printf("\n-------------------------------------------------------------");
show_vahed(code_st);
label2:
printf("\n");
printf("code Lesson:"); scanf("%d",&code_l); if(code_l==0) { fcloseall(); return; }
fseek(efp,0,SEEK_SET);
while(!feof(efp))
{
 place=ftell(efp);
 fread(&ev,sizeof(ev),1,efp);
 if(ev.code_st==code_st && ev.code_l==code_l &&  ev.del==0)
     {
      fseek(efp,place,SEEK_SET);
      ev.del=1;
      fwrite(&ev,sizeof(ev),1,efp);
      fclose(efp);
      show_vahed(code_st);
      efp=fopen("e_vahed.dat","r+b");
      break;
     }
 }
if(feof(efp)) printf("\n lesson code Not Found");
goto label2;

}
//----------------------------------------------------------------------
void delete_lesson(void)
{
FILE *lfp;
lesson l;
long int p;
int code;
clrscr();
lfp=fopen("lesson.dat","r+b");
if(lfp==NULL) { printf("\n can not open file ");getch(); return; };
printf("\n  please Input Lesson code for Delete:") ;scanf("%d",&code);
while(!feof(lfp))
{
p=ftell(lfp);
fread(&l,sizeof(l),1,lfp);
if (code==l.code) {
		     printf("\n %d   %s   %d ",l.code,l.name,l.unit);
		     printf("\n Are you Sure(y/n)");
		     if(getch()=='y') {
					fseek(lfp,p,SEEK_SET);
					l.del=1;
					fwrite(&l,sizeof(l),1,lfp);
					fclose(lfp);
					printf("\n Lesson Deleted"); getch(); break;
				       }
			else {fclose(lfp); break;}

		     }//if
}//while
fclose(lfp);

}
//----------------------------------------------------------------------
void show_vahed(int code,int *sum)
{
FILE *efp,*lfp;
e_vahed ev;
lesson l;
long int position;
*sum=0;
efp=fopen("e_vahed.dat","r+b");
lfp=fopen("lesson.dat","r+b");
if(efp==NULL) { printf("\n can not open file ");getch(); return;}
printf("\n\n");
while(!feof(efp))
       {
	fread(&ev,sizeof(ev),1,efp);
	if(feof(efp)) break;
	if(ev.code_st!=code || ev.del==1) continue;
	fseek(lfp,0,SEEK_SET);
	while(!feof(lfp))
	     {
	       fread(&l,sizeof(l),1,lfp);
	       if(feof(lfp)) break;
	       if(l.code==ev.code_l)
		  {
		  printf("\n %5d    %20s    %4d ",l.code,l.name,l.unit);
		  *sum=*sum+l.unit;
		  }
	     }//while
	 }
printf("\n===============================================================================\n");
fclose(efp);
fclose(lfp);

printf(" Sum Vahed=%d",*sum);
}
