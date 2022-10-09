#include <iostream>
#include<conio.h>

using namespace std;

void main()
{
	int a[3][3]={1,2,3,4,5,6,7,8,9},temp;
	for(int i=0;i<3;i++)
		for (int j=0;j<3;j++)
		{
			if (i<j)
			{
				temp=a[i][j];
				a[i][j]=a[j][i];
				a[j][i]=temp;

			}
		}
		for(int i=0;i<3;i++)
		for (int j=0;j<3;j++)
		cout<<a[i][j]<<" ";
		getch();
}