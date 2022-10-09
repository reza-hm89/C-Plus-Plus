#include<iostream.h>
#include<conio.h>
void asb_move(int f,int g)
{       int i,j;
	   i=f+2; j=g+1;
	   if (i>=0 || i<=7 || j>=0 || j<=7)
		if  (a[i][j]/10!=a[f][g]/10)
			b[i][j]=1;
	   j=g-1;
	   if (i>=0 || i<=7 || j>=0 || j<=7)
		if  (a[i][j]/10!=a[f][g]/10)
			b[i][j]=1;
	   i=f-2; j=g+1;
	   if (i>=0 || i<=7 || j>=0 || j<=7)
		if  (a[i][j]/10!=a[f][g]/10)
			b[i][j]=1;
	   j=g-1;
	   if (i>=0 || i<=7 || j>=0 || j<=7)
		if  (a[i][j]/10!=a[f][g]/10)
			b[i][j]=1;
	   i=f+1; j=g+2;
	   if (i>=0 || i<=7 || j>=0 || j<=7)
		if  (a[i][j]/10!=a[f][g]/10)
			b[i][j]=1;
	   i=f-1;
	   if (i>=0 || i<=7 || j>=0 || j<=7)
		if  (a[i][j]/10!=a[f][g]/10)
			b[i][j]=1;
	   i=f+1; j=g-2;
	   if (i>=0 || i<=7 || j>=0 || j<=7)
		if  (a[i][j]/10!=a[f][g]/10)
			b[i][j]=1;
	   i=f-1;
	   if (i>=0 || i<=7 || j>=0 || j<=7)
		if  (a[i][j]/10!=a[f][g]/10)
			b[i][j]=1;

}