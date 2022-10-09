#include <iostream.h>
#include <conio.h>
int main()
{
     int mat1[2][3], mat2[3][4], mat3[2][4]={0} ;
     int i,j,k ;
     clrscr();
     //read mat1
     for(i = 0 ; i < 2 ; i++)
       for(j = 0 ; j < 3; j++) {
  	        cout << "Enter mat1[" << i << "][" << j << "]:";
	        cin >> mat1[i][j] ;
     }
     //read mat2
     for(i = 0 ; i < 3 ; i++)
       for(j = 0 ; j < 4; j++) {
	        cout << "Enter mat2[" << i << "][" << j << "]: ";
	        cin >> mat2[i][j];
       }
     //multiply mat1 by mat2
     for(i = 0 ; i < 2 ; i++)
	     for(j = 0 ; j < 4 ;j++) {
	         mat3[i][j]=0 ;
	         for(k=0 ;k<3 ; k++)
	             mat3[i][j] = mat3[i][j]+mat1[i][k]*mat2[k][j];
        }
     cout << "\nThe produc of mat1 & mat2 is : \n\n" ;
     for(i = 0 ;i < 2 ;i++) {
       for(j = 0 ; j < 4 ;j++)
	       cout <<  mat3[i][j] << " ";
       cout << endl ;
     }
     getch();
     return 0;
}


