#include<stdio.h>
#include<conio.h>
#include<iostream.h>
int num[5];
char word[5];
void bubble();
void straight_Flush();
void Four_of_a_King();
void Full_House();
void Straight();
void Flush();
void Semi_House();
int main()
{  clrscr();
   int i,j;
   printf("Enter 5 number of cards: ");
   for(i=0;i<5;i++)
      scanf("%d",&num[i]);
   printf("\nEnter 5 word of cards: ");
   for(i=0;i<5;i++)
	cin>>word[i];
   bubble();
   straight_Flush();
   Four_of_a_King();
   Full_House();
   Flush();
   Straight();
   Semi_House();
   getch();
   return 0;
}
//*********************************************
//*********************************************
void bubble()
{  int i,j,item;
   for(i=5;i>0;i--)
      for(j=0;j<i;j++)
	 if(num[j]>num[j+1])
	 {   item=num[j];
	     num[j]=num[j+1];
	     num[j+1]=item;
	 }
}
//*********************************************
//*********************************************
void straight_Flush()
{   int i,flag1=0,flag2=0;
    for(i=1;i<5;i++)
    {   if(word[0]!=word[i])
	   flag1=1;
    }
    for(i=0;i<4;i++)
    {   if(num[i+1]-num[i]!=1)
	   flag2=1;
    }
    if(flag1==0&&flag2==0)
	printf("************Straight Flush************");
}
//*********************************************
//*********************************************
void Four_of_a_King()
{   int i,j,count=1;
    for(j=0;j<5;j++)
    {
	count=1;
       for(i=1;i<5;i++)
       {   if(num[j]==num[i])
	   count++;
       }
       if(count==4)
       break;
    }
    if(count==4)
       printf("**************Four_of_a_King************");
}
//*********************************************
//*********************************************
void Full_House()
{   int i,count1=1,count2=1;
    for(i=1;i<5;i++)
    {   if(num[0]==num[i])
	count1++;
    }
    for(i=3;i>=0;i--)
    {   if(num[i]==num[4])
	count2++;
    }
    if((count1==2&&count2==3)||(count1==3&&count2==2))
	printf("****************Full_House***************");
}
//**********************************************
//**********************************************
void Flush()
{   int i,count=0,flag=0;
    for(i=1;i<5;i++)
       if(word[0]!=word[i])
	   count=1;
    if (count==0)
	if(num[1]-num[0]>1)
	   flag=1;
    if(flag==1)
	printf("*******************Flush*****************");
}
//**********************************************
//**********************************************
void Straight()
{   int i,flag1=0,flag2=0;
    if(word[0]!=word[1])
	flag1=1;
    for(i=0;i<4;i++)
    {   if(num[i+1]-num[i]!=1)
	   flag2=1;
    }
    if(flag1==1&&flag2==0)
	printf("***************Straight****************");
}
//**********************************************
//**********************************************
void Semi_House()
{   int i,j,count=1;
    for(j=0;j<5;j++)
    {
	count=1;
       for(i=1;i<5;i++)
       {   if(num[j]==num[i])
	   count++;
       }
       if(count==3)
       break;
    }
    if(count==3)
       printf("*****************Semi_Flush***************");
}