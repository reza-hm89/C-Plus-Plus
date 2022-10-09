# include<conio.h>
# include<iostream.h>
# include<stdio.h>
# include<stdlib.h>
void main()
{
int i,j,k,temp,mat[10][10];
clrscr();
for(i=0;i<10;i++)
	for(j=0;j<10;j++)
		{
		cout<<"Mat [ "<<i<<" , "<<j<<" ] = ";
		cin>>mat[i][j];
		}//For
for(j=0;j<10;j++)
	for(i=0;i<10;i++)
		for(k=i+1;k<10;k++)
			if(mat[k][j]<mat[i][j])
				{
				temp=mat[k][j];
				mat[k][j]=mat[i][j];
				mat[i][j]=temp;
				}//If
cout<<"\n";
for(i=0;i<10;i++)
	{
	for(j=0;j<10;j++)
		cout<<mat[i][j]<<"     ";
	cout<<"\n";
	}//For
getch();
}//Main