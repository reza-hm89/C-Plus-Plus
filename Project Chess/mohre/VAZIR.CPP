#include<graphics.h>
#include<conio.h>
#include<iostream.h>
void vazir_move(int f,int g)
{       int q,w,i,j,m=0,cntr=1;
	for (i=f+1;i<=7;i++)
	{	if (a[i][g]==0 && m==0)
			b[i][g]=1;
		else if (a[i][g]/10==a[f][g]/10 || a[i][g]!=0)
			{	m=1;
			 if (cntr==1)
			 {	q=i;
				w=g;
			 }
			 cntr=2;
			}
		if (a[q][w]/10!=a[f][g]/10)
			b[q][w]=1;
	}
	m=0; cntr=1;
	for (i=f-1;i>=0;i--)
	{	if (a[i][g]==0 && m==0)
			b[i][g]=1;
		else if (a[i][g]/10==a[f][g]/10 || a[i][g]!=0)
			{	m=1;
			 if (cntr==1)
			 {	q=i;
				w=g;
			 }
			 cntr=2;
			}
		if (a[q][w]/10!=a[f][g]/10)
			b[q][w]=1;
	}
	m=0; cntr=1;
	for (i=g+1;i<=7;i++)
	{	if (a[f][i]==0 && m==0)
			b[f][i]=1;
		else if (a[f][i]/10==a[f][g]/10 || a[f][i]!=0)
			{	m=1;
			 if (cntr==1)
			 {	q=f;
				w=i;
			 }
			 cntr=2;
			}
		if (a[q][w]/10!=a[f][g]/10)
			b[q][w]=1;
	}
	m=0; cntr=1;
	for (i=g-1;i>=0;i--)
	{	if (a[f][i]==0 && m==0)
			b[f][i]=1;
		else if (a[f][i]/10==a[f][g]/10 || a[f][i]!=0)
			{	m=1;
			 if (cntr==1)
			 {	q=f;
				w=i;
			 }
			 cntr=2;
			}
		if (a[q][w]/10!=a[f][g]/10)
			b[q][w]=1;
	}
	m=0; cntr=1;
	for (i=f+1,j=g+1;i<=7,j<=7;i++,j++)
	{	if (a[i][j]==0 && m==0)
			b[i][j]=1;
		else if (a[i][j]/10==a[f][g]/10 || a[i][j]!=0)
			{	m=1;
			 if (cntr==1)
			 {	q=i;
				w=j;
			 }
			 cntr=2;
			}
		if (a[q][w]/10!=a[f][g]/10)
			b[q][w]=1;
	}
	m=0; cntr=1;
	for (i=f+1,j=g-1;i<=7,j>=0;i++,j--)
	{	if (a[i][j]==0 && m==0)
			b[i][j]=1;
		else if (a[i][j]/10==a[f][g]/10 || a[i][j]!=0)
			{	m=1;
			 if (cntr==1)
			 {	q=i;
				w=j;
			 }
			 cntr=2;
			}
		if (a[q][w]/10!=a[f][g]/10)
			b[q][w]=1;
	}
	m=0; cntr=1;
	for (i=f-1,j=g-1;i>=0,j>=0;i--,j--)
	{	if (a[i][j]==0 && m==0)
			b[i][j]=1;
		else if (a[i][j]/10==a[f][g]/10 || a[i][j]!=0)
			{	m=1;
			 if (cntr==1)
			 {	q=i;
				w=j;
			 }
			 cntr=2;
			}
		if (a[q][w]/10!=a[f][g]/10)
			b[q][w]=1;
	}
	m=0; cntr=1;
	for (i=f-1,j=g+1;i>=0,j<=7;i--,j++)
	{	if (a[i][j]==0 && m==0)
			b[i][j]=1;
		else if (a[i][j]/10==a[f][g]/10 || a[i][j]!=0)
			{	m=1;
			 if (cntr==1)
			 {	q=i;
				w=j;
			 }
			 cntr=2;
			}
		if (a[q][w]/10!=a[f][g]/10)
			b[q][w]=1;
	}
}