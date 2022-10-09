#include<iostream.h>
#include<conio.h>
void king_move(int f,int g)
{       int i,j;
	i=f;
	j=g;
	if ((a[++i][++j]==0) || (a[i][j]/10!=a[f][g]/10))
		if((i<=7 || i>=0) || (j<=7 || j>=0))
			b[i][j]=1;
	i=f;
	j=g;
	if ((a[++i][j]==0) || (a[i][j]/10!=a[f][g]/10))
		if((i<=7 || i>=0) || (j<=7 || j>=0))
			b[i][j]=1;
	i=f;
	j=g;
	if ((a[i][++j]==0) || (a[i][j]/10!=a[f][g]/10))
		if((i<=7 || i>=0) || (j<=7 || j>=0))
			b[i][j]=1;
	i=f;
	j=g;
	if ((a[--i][--j]==0) || (a[i][j]/10!=a[f][g]/10))
		if((i<=7 || i>=0) || (j<=7 || j>=0))
			b[i][j]=1;
	i=f;
	j=g;
	if ((a[--i][j]==0) || (a[i][j]/10!=a[f][g]/10))
		if((i<=7 || i>=0) || (j<=7 || j>=0))
			b[i][j]=1;
	i=f;
	j=g;
	if ((a[i][--j]==0) || (a[i][j]/10!=a[f][g]/10))
		if((i<=7 || i>=0) || (j<=7 || j>=0))
			b[i][j]=1;
	i=f;
	j=g;
	if ((a[++i][--j]==0) || (a[i][j]/10!=a[f][g]/10))
		if((i<=7 || i>=0) || (j<=7 || j>=0))
			b[i][j]=1;
	i=f;
	j=g;
	if ((a[--i][++j]==0) || (a[i][j]/10!=a[f][g]/10))
		if((i<=7 || i>=0) || (j<=7 || j>=0))
			b[i][j]=1;
}