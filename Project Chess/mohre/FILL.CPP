#include<iostream.h>
#include<conio.h>
#include<dos.h>
void main ()
{
	for (i=f+1,j=g+1;i<=7,g<=7;i++,j++)
		if (a[i][j]==0)
			b[i][j]=1;
	for (i=f+1,j=g-1;i<=7,g>=0;i++,j--)
		if (a[i][j]==0)
			b[i][j]=1;
	for (i=f-1,j=g-1;i>=0,g>=0;i--,j--)
		if (a[i][j]==0)
			b[i][j]=1;
	for (i=f-1,j=g+1;i>=0,g<=7;i--,j++)
		if (a[i][j]==0)
			b[i][j]=1;
	getch();
	return ;
}