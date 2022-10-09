# include<conio.h>
# include<iostream.h>
# include<stdio.h>
# include<stdlib.h>
void main()
{
int i,j,min,max,p_row,p_col,mat[10][12];
clrscr();
for(i=0;i<10;i++)
	for(j=0;j<12;j++)
		{
		cout<<"Mat [ "<<i<<" , "<<j<<" ] = ";
		cin>>mat[i][j];
		}//For
for(i=0;i<10;i++)
	{
	min=mat[i][0];
	p_col=0;
	for(j=1;j<12;j++)
		if(mat[i][j]<min)
			{
			min=mat[i][j];
			p_col=j;
			}//If
	max=mat[0][p_col];
	p_row=0;
	for(j=1;j<10;j++)
		if(mat[j][p_col]>max)
			{
			max=mat[j][p_col];
			p_row=j;
			}//If
	if(min==max)
		cout<<"\n"<<min<<"     Row = "<<p_row<<"     Col = "<<p_col;
	}//For
getch();
}//Main