#include<iostream.h>
#include<conio.h>
#include<stdio.h>

int strchr(char *s,char ch)
{
   int i;
   for(i=0;s[i];i++)
      if(s[i]==ch)
	 return i;
  return -1;
}
int charcount(char *s,char ch)
{
   int i,cnt=0;
   for(i=0;s[i];i++)
      if(s[i]==ch)
	 cnt++;

   return cnt;
}
void lower2upper(char *s)
{
   int i;
   for(i=0;s[i];i++)
      if(s[i]>='a' && s[i]<='z')
	  s[i]-=32;
}
void LetterExchange(char *s,char ch1,char ch2)
{
   int i;
   for(i=0;s[i];i++)
      if(s[i]==ch1)
	  s[i]=ch2;
}
void strExchange(char *s1,char *s2)
{
   int i;
   char temp;
   for(i=0;s1[i];i++)
   {
       temp=s1[i];
       s1[i]=s2[i];
       s2[i]=temp;
   }
}
void strcpy(char *s1,char *s2)
{
   int i;
   for(i=0;s2[i];i++)
      s1[i]=s2[i];
   s1[i]=0;
}
int strlen(char *s)
{
   int i;
   for(i=0;s[i];i++);
   return i;
}
void strcat(char *s1,char *s2)
{
   int i,j;
   for(i=0;s1[i];i++);
   for(j=0;s2[j];j++,i++)
      s1[i]=s2[j];
   s1[i]=0;
}
int strcmp(char *s1,char *s2)
{
   int i;
   for(i=0;s1[i] && s2[i] && s1[i]==s2[i];i++);
   if(s1[i]>s2[i])
     return 1;
   else if(s1[i]<s2[i])
     return -1;
   else
     return 0;
}
void main()
{
    clrscr();
    char s1[100]="Ali",s2[100]="Reza",ch1='a',ch2='b';
    cout<<strchr(s1,ch1)<<"\n\n";
    cout<<charcount(s1,ch1)<<"\n\n";
    lower2upper(s1);
    cout<<"S1 : "<<s1<<"\n\n";
    LetterExchange(s1,ch1,ch2);
    cout<<"S1 : "<<s1<<"\n\n";
    strExchange(s1,s2);
    cout<<"S1 : "<<s1<<"\n\nS2 : "<<s2<<"\n\n";
    strcpy(s1,s2);
    cout<<"S1 : "<<s1<<"\n\n";
    strcat(s1,s2);
    cout<<"S1 : "<<s1<<"\n\n";
    cout<<strcmp(s1,s2)<<"\n\n";
    getch();
}
