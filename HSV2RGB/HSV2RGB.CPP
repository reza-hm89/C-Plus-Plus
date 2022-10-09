#include<conio.h>
#include<iostream.h>
#include<stdio.h>
#include<math.h>
void hsv2rgb(int[10][10][10],int[10][10][10],int[10][10][10]);
/////////////////////////////////////////////
float r[200],g[200],b[200];
/////////////////////////////////////////////
void main()
{
	clrscr();
	int h[10][10][10],s[10][10][10],v[10][10][10];
	hsv2rgb(h,s,v);
	getch();
}
void hsv2rgb(int h[10][10][10],int s[10][10][10],int v[10][10][10])
{
	int threeD,siz,sizh;
	int i,j,cntr=0,p1;
	float h1[110],s1[110],v1[110],k[110],f[110];
	float t[110],n[110],p[110],e[110];
	float max[3];
	float r_out[10][10][10],g_out[10][10][10],b_out[10][10][10];
	sizh=sizeof(h);
	threeD = sizh;
	if (threeD) {
		for (i=0;i<10;i++)
		{	for (j=0;j<10;j++)
			{
				h[i][j][0]=h[i][j][0];
				s[i][j][0]=h[i][j][1];
				v[i][j][0];h[i][j][2];
			}
		}
	for (i=0;i<10;i++)
		for (j=0;j<10;j++)
			h1[cntr++]=h[i][j][0];
	for (i=0;i<10;i++)
		for (j=0;j<10;j++)
			s1[cntr++]=s[i][j][0];
	for (i=0;i<10;i++)
		for (j=0;j<10;j++)
			v1[cntr++]=v[i][j][0];
	}  // if threeD
	for (i=0;i<cntr;i++)
		h1[i]=6*h1[i];
	for (i=0;i<cntr;i++)
		k[i]=floor(h1[i]-6);
	for (i=0;i<cntr;i++)
		f[i]=h1[i]-k[i];
	for (i=0;i<cntr;i++)
		t[i]=1-s1[i];
	for (i=0;i<cntr;i++)
		n[i]=1-s1[i]*f[i];
	for (i=0;i<cntr;i++)
		p[i]=1-(s1[i]*(1-f[i]));

	for (i=0;i<cntr;i++) {
		h1[i]=1;
		e[i]=h1[i];
	}
	/////////////////////////// for R='Red'
	for (i=0;i<cntr;i++)
		k[i]=0;
	for (i=0;i<cntr;i++)
		r[i]=k[i]*e[i];
	for (i=0;i<cntr;i++)
		k[i]=1;
	for (i=0;i<cntr;i++)
		r[i]+=k[i]*n[i];
	for (i=0;i<cntr;i++)
		k[i]=2;
	for (i=0;i<cntr;i++)
		r[i]+=k[i]*t[i];
	for (i=0;i<cntr;i++)
		k[i]=3;
	for (i=0;i<cntr;i++)
		r[i]+=k[i]*t[i];
	for (i=0;i<cntr;i++)
		k[i]=4;
	for (i=0;i<cntr;i++)
		r[i]+=k[i]*p[i];
	for (i=0;i<cntr;i++)
		k[i]=5;
	for (i=0;i<cntr;i++)
		r[i]+=k[i]*e[i];
	///////////////////////////// end of for RED
	//////////////////////////// For g='Green'
	for (i=0;i<cntr;i++)
		k[i]=0;
	for (i=0;i<cntr;i++)
		g[i]=k[i]*p[i];
	for (i=0;i<cntr;i++)
		k[i]=1;
	for (i=0;i<cntr;i++)
		g[i]+=k[i]*e[i];
	for (i=0;i<cntr;i++)
		k[i]=2;
	for (i=0;i<cntr;i++)
		g[i]+=k[i]*e[i];
	for (i=0;i<cntr;i++)
		k[i]=3;
	for (i=0;i<cntr;i++)
		g[i]+=k[i]*n[i];
	for (i=0;i<cntr;i++)
		k[i]=4;
	for (i=0;i<cntr;i++)
		g[i]+=k[i]*t[i];
	for (i=0;i<cntr;i++)
		k[i]=5;
	for (i=0;i<cntr;i++)
		g[i]+=k[i]*t[i];
	///////////////////////////////// end of green
	//////////////////////////////// for b='BLUE'
	for (i=0;i<cntr;i++)
		k[i]=0;
	for (i=0;i<cntr;i++)
		b[i]=k[i]*t[i];
	for (i=0;i<cntr;i++)
		k[i]=1;
	for (i=0;i<cntr;i++)
		b[i]+=k[i]*t[i];
	for (i=0;i<cntr;i++)
		k[i]=2;
	for (i=0;i<cntr;i++)
		b[i]+=k[i]*p[i];
	for (i=0;i<cntr;i++)
		k[i]=3;
	for (i=0;i<cntr;i++)
		b[i]+=k[i]*1;
	for (i=0;i<cntr;i++)
		k[i]=4;
	for (i=0;i<cntr;i++)
		b[i]+=k[i]*1;
	for (i=0;i<cntr;i++)
		k[i]=5;
	for (i=0;i<cntr;i++)
		b[i]+=k[i]*n[i];
	////////////////////////////// end of BLUE
	max[0]=r[0];
	for (i=1;i<cntr;i++)
		if (r[i]>max[0])
			max[0]=r[i];
	max[1]=g[0];
	for (i=1;i<cntr;i++)
		if (g[i]>max[1])
			max[1]=g[i];
	max[2]=b[0];
	for (i=1;i<cntr;i++)
		if (b[i]>max[2])
			max[2]=b[i];
	// find maximum of r,g,b
	int mx=max[0];
	for (i=1;i<3;i++)
		if (max[i]>mx)
			mx=max[i];
	// maximum of rgb/v
	for (i=0;i<cntr;i++)
		f[i]=v1[i]/mx;
	///////////////////////////////////
	///////////////////////////////////
	//Output: convert to 3d array of R,G,B
	int z=0;
	for (i=0;i<10;i++) {
		for (j=0;j<10;j++)
			for (p1=0;p1<10;p1++) {
				r_out[i][j][p1]=f[z]*r[z];
				z++;
			}
		}
	z=0;
	for (i=0;i<10;i++) {
		for (j=0;j<10;j++)
			for (p1=0;p1<10;p1++) {
				g_out[i][j][p1]=f[z]*g[z];
				z++;
			}
		}
	z=0;
	for (i=0;i<10;i++) {
		for (j=0;j<10;j++)
			for (p1=0;p1<10;p1++) {
				b_out[i][j][p1]=f[z]*b[z];
				z++;
			}
		}
	// end of convert
}