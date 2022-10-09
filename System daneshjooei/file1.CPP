  #include<fstream.h>
  #include<iostream.h>
  #include<stdlib.h>
  #include<conio.h>
  #include<stdio.h>
  #include<string.h>
  #define C1  cout<<"number      "<<"name         "<<"family       "
  #define C2	   <<"reshteh     "<<"year      "<<"term      "
  #define C3	   <<"avg    "<<endl;
  #define G1 gotoxy(1,row);cout<<meh.number;gotoxy(13,row);cout<<meh.name;
  #define G2 gotoxy(26,row);cout<<meh.family;gotoxy(39,row);cout<<meh.reshteh;
  #define G3 gotoxy(51,row);cout<<meh.year;gotoxy(61,row);cout<<meh.term;
  #define G4 gotoxy(71,row);cout<<meh.avg;
  #define C4 cout<<"zip_les     "<<"group_les      "<<"name_les     "
  #define C5     <<"number_les   "<<"day_exam     "<<"hours_exam    " <<endl;
  #define G5 gotoxy(1,row);cout<<meh.zip_lesson;gotoxy(14,row);cout<<meh.group_lesson;
  #define G6 gotoxy(29,row);cout<<meh.name_lesson;gotoxy(41,row);cout<<meh.number_lesson;
  #define G7 gotoxy(54,row);cout<<meh.d_exam;gotoxy(67,row);cout<<meh.h_exam;

  void student  (void);
  void class_d  (void);
  void enter_1  (void);
  void enter_2  (void);
  void show_1   (void);
  void show_2   (void);
  void search_1 (void);
  void search_2 (void);
  void search_3 (void);
  void delet_1  (void);
  void delet_2  (void);
  void max_1    (void);

  struct mehdi{
		 char
			  name[21] , family[21] , reshteh[21],
				group_lesson[10] , name_lesson[10] ;
		 int
			  year , term , number , state , zip_lesson,
			  number_lesson , d_exam , h_exam ;
		 float
			  avg;
		 }meh;

  int main()
	 {
	 clrscr();
	  char p ;
	  for(;;){
				  cout<<"\n\n\n\n\n\n\n          ";
				  cout<<"\t\t1 file danesh joo\n  ";
				  cout<<"\t\t\t2 file dars \n\n";
				  cout<<"\t\t\t entekhab khod ra vared konid";
				  cin>>p;
		switch(p) {
					  case'1': student();  break;
					  case'2': class_d();  break;
					 }
				}
	 }

//*****************************************************
		void class_d()
	  {
		clrscr();
		char q ;
		for(;;){
					cout<<"\n\n\n\n\n\n\n       ";
					cout<<"\t\t                add_d (e \n";
					cout<<"\t\t                  del_d (d \n";
					cout<<"\t\t                 show_d (s \n";
					cout<<"\t\t                search_d (r \n";
					cout<<"\t\t insert date and show_d (h \n";
					cout<<"\t\t           Exit (x \n\n";
					cout<<"\t\t      insert your select";
					cin>>q;
		 switch(q){
					  case'e':enter_2 ();  break;
					  case'd':delet_2 ();  break;
					  case's':show_2  ();  break;
					  case'r':search_2();  break;
					  case'h':search_3();  break;
					  case'x':exit(0)   ;
					 }
				 }
	 }

//*****************************************************
	void student()
	  {
		clrscr();
		char q ;
		for(;;){
					cout<<"\n\n\n\n\n\n\n       ";
					cout<<"\t\t     add_st (e    \n";
					cout<<"\t\t       del_st (d    \n";
					cout<<"\t\t      show_st (s    \n";
					cout<<"\t\t     search_st (r    \n";
					cout<<"\t\t     first (m    \n";
					cout<<"\t\t    Exit (x  \n\n";
					cout<<"\t\t please insert your select" ;
					cin>>q;
		 switch(q){
					  case'e':enter_1 ();  break;
					  case'd':delet_1 ();  break;
					  case's':show_1  ();  break;
					  case'r':search_1();  break;
					  case'm':max_1 ()  ;  break;
					  case'x':exit(0)   ;
					 }
				 }
	 }

//**************************************************************
  void enter_1()
	 {
	  int num,row=3;
	  clrscr();
	  ofstream fp("ataei.dat",ios::out|ios::in |ios::binary |ios::app) ;
			 if(!fp){
						 cout<<"\n\n\t  can not open file  ";
						 exit(0);
					 }
	  C1  C2  C3;
	  gotoxy(1,row);
	  cin>>num;
	  fstream fp1("ataei.dat",ios::out|ios::in|ios::binary);
		  while(fp1.read((char*)&meh,sizeof(struct mehdi)))
			  {
				if(meh.number==num)
					{
					  cout<<"\n\n\n\n\n\n\n\n\n";
					  cout<<"\t\t\t  ************************\n";
					  cout<<"\t\t\t  * Erorr in number_st  *\n";
					  cout<<"\t\t\t  ************************\n";
					  getch();
					  exit(0);
					  }

				  }
	  meh.number=num;
	  gotoxy(13,row);
	  cin>>meh.name;
	  gotoxy(26,row);
	  cin>>meh.family;
	  gotoxy(39,row);
	  cin>>meh.reshteh;
	  gotoxy(51,row);
	  cin>>meh.year;
	  gotoxy(61,row);
	  cin>>meh.term;
	  gotoxy(71,row);
	  cin>>meh.avg;
	  meh.state=1;
	  fp.write((char *)&meh,sizeof(struct mehdi));
	  fp.close();
	  clrscr();
	  getch();
	}
//***************************************************
  void delet_1()
  {
	  clrscr();
	  int numstr,s=0;
	  cout<<"\n\n\n\n\n\n\n\n";
	  cout<<"\t\t insert number_st for del";
	  cin>>numstr;
	  fstream fp("ataei.dat",ios::out|ios::in|ios::binary);
		while(fp.read((char *)&meh,sizeof(struct mehdi)))
		  {
			if(numstr==meh.number)
			  {
				  meh.state=0;
				  fp.seekg(sizeof(struct mehdi)* s,ios::beg);
				  fp.write((char *)&meh,sizeof(struct mehdi));
				  }
				  s++;
			  }
	  clrscr();
	  getch();
	}
//***************************************************
  void search_1()
		{
		 clrscr();
		 int i,row=3;
		 cout<<"\n\n\n\n\n\n\n\n\n";
		 cout<<"\t\tinsert number_st for search  ";
		 cin>>i;
		 clrscr();
		 fstream fp("ataei.dat",ios::out|ios::in|ios::binary);
		 while(fp.read((char *)&meh,sizeof(struct mehdi))){
		  if(i==meh.number){
		 C1  C2  C3;
		 G1; G2; G3; G4;
		 break;
		}
		}
	  if(i!=meh.number){
	  cout<<"\n\n\n\n\n\n\n\n ";
	  cout<<"\t\tcan not show this number_st ";
	  }
	  getch();
	  clrscr();
	}
//***************************************************
  void show_1()
  {
		int row=3;
		clrscr();
		ifstream fp("ataei.dat",ios::in|ios::binary);
			if(!fp){
						cout<<"\t can not open file\n";
						getch();
						exit(0);
					 }
		C1  C2  C3;
		while(fp.read((char *)&meh,sizeof(struct mehdi))){
			 if(meh.state==1){G1; G2; G3; G4; row++;}
		}
		fp.close();
		getch();
		clrscr();
	}

//***************************************************************************
  void max_1()
	{
	 int row=3;
	 clrscr();
	 mehdi meh1;
	 meh1.avg=0;
	 fstream fp("ataei.dat",ios::out | ios::in | ios::binary);
	 while(fp.read((char*)&meh,sizeof(struct mehdi)))
		 if(meh.state==1)
			 if(meh.avg>meh1.avg)
				 meh1=meh;
			  C1  C2  C3;
			  G1; G2; G3; G4;
			  getch();
			  clrscr();
	}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
  void enter_2()
	{
	  int i,row=3;
		char j[10];
		clrscr();
		ofstream fp("sherafati.dat",ios::out|ios::in |ios::binary |ios::app) ;
			 if(!fp){
						 cout<<"\n\n\t can not open file  \n";
						 exit(0);
					 }
	  C4  C5;
	  gotoxy(1,row);
	  cin>>i;
	  fstream fp1("sherafati.dat",ios::out|ios::in|ios::binary);
		  while(fp1.read((char*)&meh,sizeof(struct mehdi)))
			  {
				if(meh.zip_lesson==i)
					{
					  cout<<"\n\n\n\n\n\n\n\n\n";
					  cout<<"\t\t\t  *****************\n";
					  cout<<"\t\t\t  * Erorr in dars *\n";
					  cout<<"\t\t\t  *****************\n";
					  getch();
					  exit(0);
					  }
				  }
	  meh.zip_lesson=i;
	  gotoxy(14,row);
	  cin>>j[10];
	  fstream fp2("sherafati.dat",ios::out|ios::in|ios::binary);
		  while(fp2.read((char*)&meh,sizeof(struct mehdi)))
			  {
				if(strcmp(j,meh.group_lesson))
					{
					  cout<<"\n\n\n\n\n\n\n\n\n";
					  cout<<"\t\t\t  *******************\n";
					  cout<<"\t\t\t  * erorr in group dars *\n";
					  cout<<"\t\t\t  *******************\n";
					  getch();
					  exit(0);
					  }
				  }
	  strcpy( meh.group_lesson,j);
	  gotoxy(29,row);
	  cin>>meh.name_lesson;
	  gotoxy(41,row);
	  cin>>meh.number_lesson;
	  gotoxy(54,row);
	  cin>>meh.d_exam;
	  gotoxy(67,row);
	  cin>>meh.h_exam;
	  meh.state=1;
	  fp.write((char *)&meh,sizeof(struct mehdi));
	  fp.close();
	  clrscr();
	  getch();
	}
//************************************************************
  void show_2()
	{
	  int row=3;
		clrscr();
		ifstream fp("sherafati.dat",ios::in|ios::binary);
			if(!fp){
						cout<<"\t can not open file\n";
						getch();
						exit(0);
					 }
			 C4  C5;
		while(fp.read((char *)&meh,sizeof(struct mehdi))){
			 if(meh.state==1){G5; G6; G7; row++;}
			}
		fp.close();
		getch();
		clrscr();
	}
//************************************************************
  void search_2()
	{
	  clrscr();
	  int i,row=3;
		 char j[10];
		 cout<<"\n\n\n\n\n\n\n\n\n";
		 cout<<"\t enter number_d for search";
		 cin>>i;
		 cout<<"\t enter group_d for search";
		 gets(j);
		  clrscr();
		  fstream fp("sherafati.dat",ios::out|ios::in|ios::binary);
			 while(fp.read((char *)&meh,sizeof(struct mehdi))){
				if(i==meh.zip_lesson && !strcmp(j,meh.group_lesson)){
			 C4  C5;
			 G5; G6; G7;
		 break;
		 }
		 }
		 if(i!=meh.zip_lesson ||strcmp(j,meh.group_lesson)){
	  cout<<"\n\n\n\n\n\n\n\n ";
	  cout<<"\t\t the number is not in group ";}
	  getch();
	  clrscr();
	}
//***********************************************************
  void delet_2()
	{
	  clrscr();
	  int numstr,s=0;
	  cout<<"\n\n\n\n\n\n\n\n";
	  cout<<"\t enter code_d for del";
	  cin>>numstr;
	  fstream fp("sherafati.dat",ios::out|ios::in|ios::binary);
		while(fp.read((char *)&meh,sizeof(struct mehdi)))
			{
			 if(numstr==meh.zip_lesson)
				{
				  meh.state=0;
				  fp.seekg(sizeof(struct mehdi)* s,ios::beg);
				  fp.write((char *)&meh,sizeof(struct mehdi));
				 }
				  s++;
			  }
		 clrscr();
		 getch();
	  }

//********************************************************************
void search_3()
	{
	  clrscr();
	  int i,row=3;
		 cout<<"\n\n\n\n\n\n\n\n\n";
		 cout<<"\t enter date your test";
		 cin>>i;
		 clrscr();
		 ifstream fp("sherafati.dat",ios::out|ios::in|ios::binary);
			 cout<<"\t\tname_les            "<<"hours_exam";
           while(fp.read((char *)&meh,sizeof(struct mehdi))){
				if(i==meh.d_exam ){
				  gotoxy(17,row);
				  cout<<meh.name_lesson ;
				  gotoxy(37,row);
				  cout<<meh.h_exam ;
				  row++;
				 }
			 }
	  fp.close();
	  getch();
	  clrscr();
	}
			  //////////////////////////////////////////////////////
					////////////////////////////////////////////
		   ///////////////////////////////////

