# include<iostream.h>
# include<conio.h>
# include<string.h>
# include<stdio.h>
void main()
{
char s1[100],s2[100],s3[100];
int i,j,k,find=0,l;
clrscr();
cout<<"Enter S1 : ";
gets(s1);
cout<<"\nEnter S2 : ";
gets(s2);
cout<<"\nEnter S3 : ";
gets(s3);
for(i=0;i<=strlen(s1)-strlen(s2);i++)
	if(s1[i]==s2[0])
		{
		for(j=1,k=i+1,find=1;s2[j]&&find;j++,k++)
			if(s1[k]!=s2[j])
				find=0;
		if(find)
			{
			if(strlen(s3)>strlen(s2))
				for(l=strlen(s1);l>=i+strlen(s2)-1;l--)
					s1[l+strlen(s3)-strlen(s2)]=s1[l];
			if(strlen(s3)<strlen(s2))
				for(l=i;l<=strlen(s1)-(strlen(s2)-strlen(s3));l++)
					s1[l]=s1[l+strlen(s2)-strlen(s3)];
			for(k=i,l=0;s3[l];k++,l++)
				s1[k]=s3[l];
			}//If
		}//If
if(find)
	{
	cout<<"\nResult : ";
	for(l=0;s1[l];l++)
		cout<<s1[l];
	}//If
else
	cout<<"\nResult: Not Found";
getch();
}//Main