#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
//****************************
void menu();
int sw(int);
int play();
int option();
int help();
int highscore();
int choose();
int main()
{
	int choice;
	char ans;
	do {
	clrscr();
	menu();
	choose();
	choice=choose();
	choice=sw(choice);
	}while(choice!=5);
	   //getch();
	  return 0;
}
//***********************************
int play()
{
   ////////////////////////////////////////////////////
	clrscr();
	char ch,name[20],arr[6][20];
	textcolor(9); {
	gotoxy(30,16);
	cprintf("ENTER YOUR NAME:");
	cin.get(arr[6],19);
	cin.get();}
   /////////////////////////////////////////////////////////
	int i=0,j=0,a=50,b=21,m,c[15][10],n,d[15][2],p1,p2,p3,p4=0,p5,ii1,jj1;
	int i3,j3,z3,count,fuze,i4,j4,z4,i5,xprim[8],yprim[8],dd[10][10];
	clrscr();
	textcolor(3);
	gotoxy(10,20);

	for(j=1;j<=b;j+=2) {

	   for(i=0;i<a;i++) {
		   gotoxy(10+i,j);
		      cprintf("_");}

	}
	b--;
	for(i=0;i<=a;i+=5) {
	   for(j=1;j<=b;j++) {
		   gotoxy(10+i,j+1);
		      cprintf("³");}
  //////////////////////////////////////////////////////////
		gotoxy(59,24);
		cout<<"NAME:";
		gotoxy(64,24);
		cprintf(arr[6]);
	}
//*************************************
	for(ii1=1;ii1<+10;ii1++)
	   for(jj1=1;jj1<=10;jj1++)
	      dd[ii1][jj1]=0;
	textcolor(4);
	randomize();
	for(m=1;m<=15;m++)
	for(n=1;n<=2;n++)
	c[m][n]=random(10)+1;
	p3=2;
	for(p1=1;p1<=15;p1++){
	   for(p2=p3;p2<=15;p2++){
	   if(c[p1][1]==c[p2][1]&&c[p1][2]==c[p2][2])
	   p4++;}
	   p3++;}
	   p5=15-p4;
	for(m=1;m<=15;m++)
	for(n=1;n<2;n++){
	d[m][1]=7+5*c[m][n];
	d[m][2]=22-2*c[m][n+1];}
	for(m=1;m<=15;m++)
	{
	gotoxy(d[m][1],d[m][2]);
       //	cprintf("B");
	dd[(d[m][1]-7)/5][(22-d[m][2])/2]=1;
	}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	char ch1;
	int x=12,y=20,l,x1,y1,find=0,i1,j1,find1=0,m2,find2=1,counter=0;
	gotoxy(x,y);
	//cout<<"*";
	while(find1==0&&find2!=0) {
	while(ch1!=13){
		//ch1=getch();
		//if(ch1==0) {
		ch1=getch();
		gotoxy(x,y);
		cout<<' ';
		switch(ch1) {
			case 104:
			if(counter<2) {
			   gotoxy(d[counter+1][1]+1,d[counter+1][2]);
				  cout<<"B";
				 counter++;}
			break;
			case 72:
			if(y>2)
			y-=2;
			break;
			case 80:
			if(y<20)
			y+=2;
			break;
			case 75:
			if(x>12)
			x-=5;
			break;
			case 77:
			if(x<57)
			x+=5;
			break;
		}//end of switch
		gotoxy(x,y);
//		cout<<x;
		//cout<<"*";
		//}//end of if


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
	}
	 //cout<<x;
	 //cout<<y;
		//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
		for(l=1;l<=15;l++){
		if(d[l][1]==x&&d[l][2]==y)
		find=1;}
		if(find==1){
		find1=1;

			for(m2=1;m2<=15;m2++) {
			   textcolor(4);
			   gotoxy(d[m2][1],d[m2][2]);
			   cprintf("B");}
		gotoxy(30,24);
		cout<<"GAME OVER";}
		else{
		textcolor(6);
		gotoxy(x+1,y);
		dd[(x-7)/5][(22-y)/2]=1;
		cprintf("1");}
	       //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^



		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	       i5=0;
	       for(i3=x-5;i3<=x+5;i3+=5)
		  for(j3=y-2;j3<=y+2;j3+=2)
		     for(z3=1;z3<=15;z3++)
			if(d[z3][1]==i3&&d[z3][2]==j3){
			  xprim[i5]=i3;
			  yprim[i5]=j3;
			 // cout<<xprim[i5];
			  //cout<<yprim[i5];
			  i5++;
			  }
	 ///++++++++++++++++++++++++++++++++++++++++++++++++++++
	       count=i5;
	       for(i4=x-5;i4<=x+6;i4+=10)
		  for(j4=y-2;j4<=y+3;j4+=4){
		     fuze=1;
		     if(i4==x-5&&j4==y-2){
		     fuze=0;
		     for(z4=0;z4<=count;z4++){
			if(i4==xprim[z4]&&j4==yprim[z4])
			  fuze++;
			if(i4+5==xprim[z4]&&j4==yprim[z4])
			  fuze++;
			if(i4+10==xprim[z4]&&j4==yprim[z4])
			  fuze++;
			if(i4==xprim[z4]&&j4+2==yprim[z4])
			  fuze++;
			if(i4==xprim[z4]&&j4+4==yprim[z4])
			  fuze++;
			  }
			  }
		     if(i4==x-5&&j4==y+2){
		     fuze=0;
		     for(z4=0;z4<=count;z4++){
			if(i4==xprim[z4]&&j4==yprim[z4])
			  fuze++;
			if(i4+5==xprim[z4]&&j4==yprim[z4])
			  fuze++;
			if(i4+10==xprim[z4]&&j4==yprim[z4])
			  fuze++;
			if(i4==xprim[z4]&&j4-2==yprim[z4])
			  fuze++;
			if(i4==xprim[z4]&&j4-4==yprim[z4])
			  fuze++;
			  }
			  }
		     if(i4==x+5&&j4==y-2){
		     fuze=0;
		     for(z4=0;z4<=count;z4++){
			if(i4==xprim[z4]&&j4==yprim[z4])
			  fuze++;
			if(i4-5==xprim[z4]&&j4==yprim[z4])
			  fuze++;
			if(i4-10==xprim[z4]&&j4==yprim[z4])
			  fuze++;
			if(i4==xprim[z4]&&j4+2==yprim[z4])
			  fuze++;
			if(i4==xprim[z4]&&j4+4==yprim[z4])
			  fuze++;
			  }
			  }
		     if(i4==x+5&&j4==y+2){
		     fuze=0;
		     for(z4=0;z4<=count;z4++){
			if(i4==xprim[z4]&&j4==yprim[z4])
			  fuze++;
			if(i4-5==xprim[z4]&&j4==yprim[z4])
			  fuze++;
			if(i4-10==xprim[z4]&&j4==yprim[z4])
			  fuze++;
			if(i4==xprim[z4]&&j4-2==yprim[z4])
			  fuze++;
			if(i4==xprim[z4]&&j4-4==yprim[z4])
			  fuze++;
			  }
			  }
			if(fuze==0&&i4>=12&&i4<=57&&j4<=20&&j4>=2){
			  gotoxy(i4+1,j4);
			  cout<<"1";
			  dd[(i4-7)/5][(22-j4)/2]=1;}
			  }
	      //++++++++++++++++++++++++++++++++++++++++++++

		 for(i4=x-5;i4<=x+6;i4+=5)
		  for(j4=y-2;j4<=y+3;j4+=2){
		    fuze=1;
		    if(i4==x-5&&j4==y){
		   fuze=0;
		     for(z4=0;z4<=count;z4++){
			if(i4==xprim[z4]&&j4==yprim[z4])
			  fuze++;
			if(i4==xprim[z4]&&j4-2==yprim[z4])
			  fuze++;
			if(i4==xprim[z4]&&j4+2==yprim[z4])
			  fuze++;}
				 }
		     if(i4==x+5&&j4==y){
		   fuze=0;
		     for(z4=0;z4<=count;z4++){
			if(i4==xprim[z4]&&j4==yprim[z4])
			  fuze++;
			if(i4==xprim[z4]&&j4-2==yprim[z4])
			  fuze++;
			if(i4==xprim[z4]&&j4+2==yprim[z4])
			  fuze++;}
				 }
			if(i4==x&&j4==y-2){
			   fuze=0;
			   for(z4=0;z4<=count;z4++){
				if(i4==xprim[z4]&&j4==yprim[z4])
				  fuze++;
				if(i4-5==xprim[z4]&&j4==yprim[z4])
				  fuze++;
				if(i4+5==xprim[z4]&&j4==yprim[z4])
				  fuze++;}
					 }
			if(i4==x&&j4==y+2){
			   fuze=0;
			   for(z4=0;z4<=count;z4++){
				if(i4==xprim[z4]&&j4==yprim[z4])
				  fuze++;
				if(i4-5==xprim[z4]&&j4==yprim[z4])
				  fuze++;
				if(i4+5==xprim[z4]&&j4==yprim[z4])
				  fuze++;}
					 }
			if(fuze==0&&i4>=12&&i4<=57&&j4<=20&&j4>=2){
			  gotoxy(i4+1,j4);
			  cout<<"1";
			  dd[(i4-7)/5][(22-j4)/2]=1;}
			  }

	       //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	       //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	gotoxy(x,y);
	ch1=14;
	find2=0;
	for(ii1=1;ii1<=10;ii1++)
	  for(jj1=1;jj1<=10;jj1++)
	    if(dd[ii1][jj1]==0)
	    find2++;
	    if(find2==0){
	    gotoxy(30,25);
	    cout<<"CONGRATULATION!YOU WON";}
	}
	getch();

	return 0;
}
//*************************************
void menu()
{
gotoxy(30,5);
textcolor(2);
cprintf("PLAY GAME");
gotoxy(30,8);
textcolor(2);
cprintf("OPTION");
gotoxy(30,11);
textcolor(2);
cprintf("HELP");
gotoxy(30,14);
textcolor(2);
cprintf("HIGH SCORE");
gotoxy(30,17);
textcolor(2);
cprintf("EXIT");
}
//*******************************
int option()
{
int ch2,x=40,y=12;
textcolor(4);
clrscr();
gotoxy(30,8);
cprintf("DIFFICULTY\n");
gotoxy(30,10);
cprintf("SOUNDS\n");
gotoxy(30,12);
cprintf("TIME");
	while(ch2!=13){
		//ch1=getch();
		//if(ch1==0) {
		ch2=getch();
		gotoxy(x,y);
		cout<<' ';
		switch(ch2) {
			case 72:
			if(y>9)
			y-=2;
			break;
			case 80:
			if(y<11)
			y+=2;
			break;
		}//end of switch
	}//end of while
///////////////////////////////



/////////////////////////////////////////
//getch();
return 0;
}
//********************************
int highscore()
{
int i,j,arr[6][20];
clrscr();
textcolor(14);
gotoxy(30,8);
cout<<"NAME \t\tBEST SCORE";
cout<<endl;
gotoxy(30,9);
cprintf("\-----------------------------");
for(i=8;i<22;i++) {
gotoxy(44,i);
cprintf("³");}
   i=8;
   for(j=1;j<=6;j++){
gotoxy(30,i+=2);
cout<<j<<"-";}

getch();
return 0;
}
//********************************
int help()
{
cout<<"ABOUT THIS GAME";
}
//********************************
int sw(int f)
{
	char ans;
	switch(f)
	{
		case 1:
		play();
		break;
		case 2:
		option();
		break;
		case 3:
		help();
		break;
		case 4:
		highscore();
		break;
		case 5:
		clrscr();
		gotoxy(10,15);
		textcolor(14);
		cprintf("DO YOU WANT TO EXIT?");
		cprintf("\(yes or no)");
		cin>>ans;
		if(ans=='y')
		  return 5;
		  return 0;
		}//end of switch

 }
 //*************************************************
 int choose()
 {
	char ch;
	int x=40,y=17,t=5,z;
	gotoxy(x,y);
	while(ch!=13) {
		ch=getch();
		if(ch==0) {
		ch=getch();
		gotoxy(x,y);
		cout<<' ';
		switch(ch) {
			case 72:
			if(y>5){
			y-=3;
			t--;}
			break;
			case 80:
			if(y<17){
			y+=3;
			t++;}
			break;
			}//end of switch
		gotoxy(x,y);
		z=t;
		}//end of if
	}   return z;
 }







