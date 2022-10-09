#include<conio.h>
#include <stdio.h>

long double zarayeb[30][30],hamani[30][30],natije[30],javab[30];
int input();
void makus(int);
void output(int);
void haselzarb(int);

void main()
{int majhul;
majhul=input();
makus(majhul);
haselzarb(majhul);
output(majhul);
getch();
}
//**************************************************************
int input()
{
int m,n,majhul;
clrscr();
for(m=0;m<30;m++)
for(n=0;n<30;n++)
if(m==n)
hamani[m][n]=1;
else
hamani[m][n]=0;
printf("enter a number 1..30 : ");
scanf("%d",&majhul);
printf("\n\nvared kon matris zarayeb : ");
for(m=0;m<majhul;m++)
{
printf("\n");
for(n=0;n<majhul;n++)
{
printf("%d,%d : ",m+1,n+1);
scanf("%Lf",&zarayeb[m][n]);
}
}
printf("\nvared kon matris natije : \n");
for(m=0;m<majhul;m++)
{
printf("%d : ",m+1);
scanf("%Lf",&natije[m]);
}
return majhul;
}
//**************************************************************
void makus(int majhul)
{
int m,n,t;
long double temp1,temp2;
for(m=0;m<majhul;m++)
{
if (zarayeb[m][m]==0)
{
for(t=m+1;t<majhul && zarayeb[t][m]==0;t++);

for(n=0;n<majhul;n++)
{
temp1=zarayeb[t][n];
temp2=hamani[t][n];
zarayeb[t][n]=zarayeb[m][n];
hamani[t][n]=hamani[m][n];
zarayeb[m][n]=temp1;
hamani[m][n]=temp2;
}}
for(t=0;t<majhul;t++)
if(t!=m)
{temp2=(zarayeb[t][m]/zarayeb[m][m])*(-1);
for(n=0;n<majhul;n++)
{
hamani[t][n]=hamani[t][n]+hamani[m][n]*temp2;
zarayeb[t][n]=zarayeb[t][n]+zarayeb[m][n]*temp2;
}}
temp1=zarayeb[m][m];
for(n=0;n<majhul;n++)
{
hamani[m][n]=hamani[m][n]/temp1;
zarayeb[m][n]=zarayeb[m][n]/temp1;
}}}
//**************************************************************
void haselzarb(int majhul)
{
long double sum;
int m,n;
for(m=0;m<majhul;m++)
{sum=0;
for(n=0;n<majhul;n++)
sum=sum+hamani[m][n]*natije[n];
javab[m]=sum;
}}
//**************************************************************
void output(int majhul)
{int m;
printf("\njavab : \n");
for(m=0;m<majhul;m++)
{
printf("%.3Lf",javab[m]);
printf("    ");
}}