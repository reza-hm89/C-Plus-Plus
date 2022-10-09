#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
////////////////////////////////////////////////////
class Person {
	protected:
		char firstname[20];
		char lastname[20];
		char age[3];
		char tel[10];
		char username[20];
		char password[20];
	public:
		void setusername(char* temp){ strcpy(username,temp); }
		void setfirstname(char* temp){ strcpy(firstname,temp); }
		void setlastname(char* temp){ strcpy(lastname,temp); }
		void setage(char* temp){ strcpy(age,temp); }
		void settel(char* temp){ strcpy(tel,temp); }
		void setpassword(char* temp){ strcpy(password,temp); }
		char* retusername(){ return username; }
		char* retfirstname(){ return firstname; }
		char* retlastname(){ return lastname; }
		char* retage(){ return age; }
		char* rettel(){ return tel; }
		char* retpassword(){ return password; }
	};
///////////////////////////////////////////////////////////////
class User:public Person {
	int kind;
	int status;
	public:
		void setkind(int temp){ kind=temp; }
		void setstatus(int temp){ status=temp; }
		int retkind() { return kind; }
		int  retstatus(){ return status; }
		void showinfo();
		void editinfo(char*,int);
	};
void User::showinfo()
{
	gotoxy(20,2);
	cout<<retfirstname();
	gotoxy(20,4);
	cout<<retlastname();
	gotoxy(20,6);
	cout<<retage();
	gotoxy(20,8);
	cout<<rettel();
}
void User::editinfo(char* t,int y)
{
	if (y==2)
		setfirstname(t);
	else if (y==4)
		setlastname(t);
	else if (y==6)
		setage(t);
	else if (y==8)
		settel(t);
}
///////////////////////////////////////////////////////////////
class Admin:public Person {
	int kind;
	public:
		void setkind(int temp){ kind=temp; }
	};
///////////////////////////////////////////////////////////////
void MainMenu();
void UserMenu();
void AdminMenu();
void Movement(int,int,int,int);
void Sign_in();
void Sign_up();
int  CheckUser();
int  CheckAdmin();
void Edit_Profile();
void Delete_Profile();
void AddUser();
void EditUser();
void DeleteUser();
void VerifyUser();
void ListUser();
void SortUser();
void SearchUser();
void ChangePass();
void Number();
void SaveUserFile();
void ReadUserFile();
void ReadAdminFile();
void ConvertUser();
void ConvertAdmin();
///////////////////////////////////////////////////////////////
int page=1;
int NumOfUser,NumOfAdmin;
char user[20],pass[20];
char userfile[100][100];
char adminfile[100][100];
User ob1[100];
Admin ob2[100];
///////////////////////////////////////////////////////////////

void main()
{
	ReadUserFile();
	ConvertUser();
	ReadAdminFile();
	ConvertAdmin();
	MainMenu();
}
///////////////////////////////////////////////////////////////
void MainMenu()
{
	int i,j,MaxCol=50,MaxRow=20;
	page=1;
	textmode(C80);
	textbackground(RED);
	clrscr();
	textcolor(YELLOW);
	gotoxy(20,2);
	cprintf("Main Menu");
	textcolor(WHITE);
	for (i=1;i<=MaxCol;i++)
	{
		gotoxy(i,1);
		cprintf("Í");
		gotoxy(i,MaxRow);
		cprintf("Í");
	}
	for (j=1;j<=MaxRow;j++)
	{
		gotoxy(1,j);
		cprintf("º");
		gotoxy(MaxCol,j);
		cprintf("º");
	}
	gotoxy(1,1);
	cprintf("É");
	gotoxy(MaxCol,1);
	cprintf("»");
	gotoxy(1,MaxRow);
	cprintf("È");
	gotoxy(MaxCol,MaxRow);
	cprintf("¼");
	gotoxy(10,6);
	cprintf("1.Sign In");
	gotoxy(10,10);
	cprintf("2.Sign Up");
	gotoxy(10,14);
	cprintf("3.Exit");
	Movement(6,14,7,4);
}
////////////////////////////////////////////////////
void AdminMenu()
{
	int i,j,MaxCol=50,MaxRow=24;
	page=2;
	textmode(C80);
	textbackground(BLUE);
	clrscr();
	textcolor(YELLOW);
	gotoxy(35,2);
	cprintf("Admin Menu");
	textcolor(WHITE);
	for (i=1;i<=MaxCol;i++)
	{
		gotoxy(i,1);
		cprintf("Í");
		gotoxy(i,MaxRow);
		cprintf("Í");
	}
	for (j=1;j<=MaxRow;j++)
	{
		gotoxy(1,j);
		cprintf("º");
		gotoxy(MaxCol,j);
		cprintf("º");
	}
	gotoxy(1,1);
	cprintf("É");
	gotoxy(MaxCol,1);
	cprintf("»");
	gotoxy(1,MaxRow);
	cprintf("È");
	gotoxy(MaxCol,MaxRow);
	cprintf("¼");
	gotoxy(10,2);
	cprintf("1.Add User");
	gotoxy(10,4);
	cprintf("2.Edit User");
	gotoxy(10,6);
	cprintf("3.Delete User");
	gotoxy(10,8);
	cprintf("4.Verify User");
	gotoxy(10,10);
	cprintf("5.List User");
	gotoxy(10,12);
	cprintf("6.Sort Users (By Username)");
	gotoxy(10,14);
	cprintf("7.Search User (By Username)");
	gotoxy(10,16);
	cprintf("8.Change Password");
	gotoxy(10,18);
	cprintf("9.Save");
	gotoxy(10,20);
	cprintf("10.Number of User");
	gotoxy(10,22);
	cprintf("11.Logout");
	Movement(2,22,7,2);
}
////////////////////////////////////////////////////
void UserMenu()
{
	int i,j,MaxCol=50,MaxRow=24;
	page=3;
	textmode(C80);
	textbackground(GREEN);
	clrscr();
	textcolor(YELLOW);
	gotoxy(20,2);
	cprintf("User Menu");
	textcolor(15);
	for (i=1;i<=MaxCol;i++)
	{
		gotoxy(i,1);
		cprintf("Í");
		gotoxy(i,MaxRow);
		cprintf("Í");
	}
	for (j=1;j<=MaxRow;j++)
	{
		gotoxy(1,j);
		cprintf("º");
		gotoxy(MaxCol,j);
		cprintf("º");
	}
	gotoxy(1,1);
	cprintf("É");
	gotoxy(MaxCol,1);
	cprintf("»");
	gotoxy(1,MaxRow);
	cprintf("È");
	gotoxy(MaxCol,MaxRow);
	cprintf("¼");
	gotoxy(10,6);
	cprintf("1.Edit Profile");
	gotoxy(10,10);
	cprintf("2.Delete Profile");
	gotoxy(10,14);
	cprintf("3.Save");
	gotoxy(10,18);
	cprintf("4.Logout");
	Movement(6,18,7,4);
}
////////////////////////////////////////////////////
void Movement(int low,int high,int col,int row)
{
	char ch;
	int x=col,y=low;
	gotoxy(x,y);
	cprintf("->");
	while (1) {
		textcolor(WHITE);
		ch=getch();
		gotoxy(x,y);
		cprintf("  ");
		if (ch==72)
		{
			y-=row;
			if (y<low)
				y=high;
		}
		else if (ch==80)
		{
			y+=row;
			if (y>high)
				y=low;
		}
		else if (page==1)
		{
			if (ch==13 && y==low)
			{
				Sign_in();
				if (CheckUser())
				{
					UserMenu();
				}
				if (CheckAdmin())
				{
					AdminMenu();
				}
			}
			else if (ch==13 && y==low+row)
			{
				Sign_up();
			}
			else if (ch==13 && y==high)
			{
				exit(0);
			}
		}//page1
		else if (page==2)
		{
			if (ch==13 && y==row)
			{
				AddUser();
				AdminMenu();
			}
			else if (ch==13 && y==row*2)
			{
				EditUser();
				AdminMenu();
			}
			else if (ch==13 && y==row*3)
			{
				DeleteUser();
				AdminMenu();
			}
			else if (ch==13 && y==row*4)
			{
				VerifyUser();
				AdminMenu();
			}
			else if (ch==13 && y==row*5)
			{
				ListUser();
				AdminMenu();
			}
			else if (ch==13 && y==row*6)
			{
				SortUser();
				AdminMenu();
			}
			else if (ch==13 && y==row*7)
			{
				SearchUser();
				AdminMenu();
			}
			else if (ch==13 && y==row*8)
			{
				ChangePass();
				AdminMenu();
			}
			else if (ch==13 && y==row*9)
			{
				SaveUserFile();
				AdminMenu();
			}
			else if (ch==13 && y==row*10)
			{
				Number();
				AdminMenu();
			}
			else if (ch==13 && y==high)
			{
				MainMenu();
			}
		}//page2
		else if (page==3)
		{
			if (ch==13 && y==low)
			{
				Edit_Profile();
				UserMenu();
			}
			else if (ch==13 && y==low+row)
			{
				Delete_Profile();
				MainMenu();
			}
			else if (ch==13 && y==high-row)
			{
				SaveUserFile();
				UserMenu();
			}
			else if (ch==13 && y==high)
			{
				MainMenu();
			}
		}
		textcolor(WHITE);
		gotoxy(x,y);
		cprintf("->");
	}
}
////////////////////////////////////////////////////
void Sign_in()
{
	int i,j;
	char ch;
	textcolor(WHITE);
	gotoxy(20,4);
	cprintf("ßßßßß");
	gotoxy(20,9);
	cprintf("ßßßßß");
	for (i=4;i<=8;i++)
	{
		gotoxy(20,i);
		cprintf("Û");
	}
	gotoxy(22,5);
	cprintf("UserName ");
	textbackground(BLACK);
	cprintf("         ");
	gotoxy(22,7);
	textbackground(RED);
	cprintf("Password ");
	textbackground(BLACK);
	cprintf("         ");
	gotoxy(32,5);
	gets(user);
	gotoxy(32,7);
	i=0;
	textcolor(WHITE);
	while (ch!=13) {
		ch=getch();
		pass[i++]=ch;
		cprintf("*");
	}
	pass[i-1]='\0';
	textbackground(RED);
	for (i=3;i<=10;i++)
		for (j=20;j<=40;j++)
		{
			textcolor(RED);
			gotoxy(j,i);
			cprintf(" ");
		}
}
////////////////////////////////////////////////////
void Sign_up()
{
	int i,y=0;
	char* t;
	textbackground(LIGHTCYAN);
	textcolor(WHITE);
	clrscr();
	gotoxy(2,2);
	cprintf("First name");
	gotoxy(2,4);
	cprintf("last name");
	gotoxy(2,6);
	cprintf("Age");
	gotoxy(2,8);
	cprintf("Telephone");
	gotoxy(2,10);
	cprintf("Username");
	gotoxy(2,12);
	cprintf("Password");
	for (i=1;i<=6;i++)
	{
		gotoxy(15,y+=2);
		textbackground(BLACK);
		cprintf("                          ");
	}
	textcolor(15);
	gotoxy(15,2);
	gets(t);
	ob1[NumOfUser].setfirstname(t);
	gotoxy(15,4);
	gets(t);
	ob1[NumOfUser].setlastname(t);
	gotoxy(15,6);
	gets(t);
	ob1[NumOfUser].setage(t);
	gotoxy(15,8);
	gets(t);
	ob1[NumOfUser].settel(t);
	gotoxy(15,10);
	gets(t);
	ob1[NumOfUser].setusername(t);
	gotoxy(15,12);
	gets(t);
	ob1[NumOfUser].setpassword(t);
	ob1[NumOfUser].setstatus(0);
	NumOfUser++;
	MainMenu();
}
////////////////////////////////////////////////////
int CheckUser()
{
	for (int i=0;i<NumOfUser;i++)
	{
		if (!strcmp(user,ob1[i].retusername()))
		{
			if (!strcmp(pass,ob1[i].retpassword()))
				if (ob1[i].retstatus()==1)
					return 1;
		}
	}
	return 0;
}
////////////////////////////////////////////////////
int CheckAdmin()
{
	for (int i=0;i<NumOfAdmin;i++)
	{
		if (!strcmp(user,ob2[i].retusername()))
			if (!strcmp(pass,ob2[i].retpassword()))
				return 1;
	}
	return 0;
}
////////////////////////////////////////////////////
void Edit_Profile()
{
	clrscr();
	int y=2;
	char ch='a';
	char* t;
	gotoxy(30,1);
	cprintf("EDIT  PROFILE");
	gotoxy(7,2);
	cprintf("First name:");
	gotoxy(7,4);
	cprintf("last name:");
	gotoxy(7,6);
	cprintf("Age:");
	gotoxy(7,8);
	cprintf("Telephone:");
	for (int i=0;i<NumOfUser;i++)
	{
		if (!strcmp(user,ob1[i].retusername()))
			if (!strcmp(pass,ob1[i].retpassword()))
				{
					ob1[i].showinfo();
					break;
				}
	}
	gotoxy(4,2);
	cprintf("->");
	while (ch!=27)
	{
		ch=getch();
		gotoxy(4,y);
		cprintf("  ");
		if (ch==72)
		{
			y-=2;
			if (y<2)
				y=8;
		}
		else if (ch==80)
		{
			y+=2;
			if (y>8)
				y=2;
		}
		else if (ch==13)
		{
			gotoxy(20,y);
			cprintf("                             ");
			gotoxy(20,y);
			gets(t);
			ob1[i].editinfo(t,y);
			gotoxy(20,y);
			cprintf("%s",t);
		}
		gotoxy(4,y);
		cprintf("->");
	}
	getch();
}
////////////////////////////////////////////////////
void Delete_Profile()
{
	clrscr();
	textcolor(129);
	gotoxy(30,11);
	cprintf("Profile is Dleleted...");
	for (int i=0;i<NumOfUser;i++)
	{
		if (!strcmp(user,ob1[i].retusername()))
			if (!strcmp(pass,ob1[i].retpassword()))
				{
					for (int j=i;j<NumOfUser-1;j++)
						ob1[j]=ob1[j+1];
				}
	}
	getch();
}
////////////////////////////////////////////////////
void SaveUserFile()
{
	int i,x;
	char* t;
	char t1[20];
	t=NULL;
	clrscr();
	ofstream f;
	f.open("user3.txt",ios::out);
	if (!f){
		gotoxy(30,12);
		cprintf("Can not Save the File...");
		return;
		}
	gotoxy(30,12);
	cprintf("...File Saved...");
	for (i=0;i<NumOfUser;i++)
	{
		t="0|";
		f.write(t,strlen(t));
		if (ob1[i].retstatus())
			t="1|";
		else	t="0|";
		f.write(t,strlen(t));
		t=ob1[i].retusername();
		strcpy(t1,t);
		strcat(t1,"|");
		f.write(t1,strlen(t1));
		t=ob1[i].retpassword();
		strcpy(t1,t);
		strcat(t1,"|");
		f.write(t1,strlen(t1));
		t=ob1[i].retfirstname();
		strcpy(t1,t);
		strcat(t1,"|");
		f.write(t1,strlen(t1));
		t=ob1[i].retlastname();
		strcpy(t1,t);
		strcat(t1,"|");
		f.write(t1,strlen(t1));
		t=ob1[i].retage();
		strcpy(t1,t);
		strcat(t1,"|");
		f.write(t1,strlen(t1));
		t=ob1[i].rettel();
		strcpy(t1,t);
		strcat(t1,"|");
		f.write(t1,strlen(t1));
		f.put('\n');
		t=NULL;
	}
	f.close();
	getch();
}
////////////////////////////////////////////////////
void AddUser()
{
	int i,y=0;
	char* t;
	textbackground(LIGHTCYAN);
	textcolor(WHITE);
	clrscr();
	gotoxy(2,2);
	cprintf("First name");
	gotoxy(2,4);
	cprintf("last name");
	gotoxy(2,6);
	cprintf("Age");
	gotoxy(2,8);
	cprintf("Telephone");
	gotoxy(2,10);
	cprintf("Username");
	gotoxy(2,12);
	cprintf("Password");
	for (i=1;i<=6;i++)
	{
		gotoxy(15,y+=2);
		textbackground(BLACK);
		cprintf("                          ");
	}
	textcolor(15);
	gotoxy(15,2);
	gets(t);
	ob1[NumOfUser].setfirstname(t);
	gotoxy(15,4);
	gets(t);
	ob1[NumOfUser].setlastname(t);
	gotoxy(15,6);
	gets(t);
	ob1[NumOfUser].setage(t);
	gotoxy(15,8);
	gets(t);
	ob1[NumOfUser].settel(t);
	gotoxy(15,10);
	gets(t);
	ob1[NumOfUser].setusername(t);
	gotoxy(15,12);
	gets(t);
	ob1[NumOfUser].setpassword(t);
	ob1[NumOfUser].setstatus(1);
	NumOfUser++;
	AdminMenu();
}
////////////////////////////////////////////////////
void EditUser()
{
	clrscr();
	int y=2,x,sw=0;
	char ch='a';
	char t[20];
	char u[20];
	cprintf("Enter UserName of User: ");
	gets(u);
	clrscr();
	for (int i=0;i<NumOfUser;i++)
	{
		if (!strcmp(u,ob1[i].retusername()))
			{
				ob1[i].showinfo();
				gotoxy(20,10);
				cprintf("%d",ob1[i].retstatus());
				sw=1;
				break;
			}

	}
	if (sw==0)
	{
		gotoxy(30,12);
		cprintf("Not Found");
		getch();
		return;
	}
	gotoxy(30,1);
	cprintf("EDIT  User");
	gotoxy(7,2);
	cprintf("First name:");
	gotoxy(7,4);
	cprintf("last name:");
	gotoxy(7,6);
	cprintf("Age:");
	gotoxy(7,8);
	cprintf("Telephone:");
	gotoxy(7,10);
	cprintf("Status:");
	gotoxy(4,2);
	cprintf("->");
	while (ch!=27)
	{
		ch=getch();
		gotoxy(4,y);
		cprintf("  ");
		if (ch==72)
		{
			y-=2;
			if (y<2)
				y=10;
		}
		else if (ch==80)
		{
			y+=2;
			if (y>10)
				y=2;
		}
		else if (ch==13 && y!=10)
		{
			gotoxy(20,y);
			cprintf("                             ");
			gotoxy(20,y);
			gets(t);
			ob1[i].editinfo(t,y);
			gotoxy(20,y);
			cprintf("%s",t);
		}
		else if (ch==13 && y==10)
		{
			gotoxy(20,y);
			cprintf("                             ");
			gotoxy(20,y);
			gets(t);
			gotoxy(20,y);
			cprintf("%s",t);
			x=atoi(t);
			ob1[i].setstatus(x);
		}
		gotoxy(4,y);
		cprintf("->");
	}
	getch();
}
////////////////////////////////////////////////////
void DeleteUser()
{
	char u[20],sw=0;
	clrscr();
	textcolor(WHITE);
	cprintf("Enter UserName of User: ");
	gets(u);
	clrscr();
	for (int i=0;i<NumOfUser;i++)
	{
		if (!strcmp(u,ob1[i].retusername()))
			{
				sw=1;
				break;
			}
	}
	if (sw==0)
	{
		gotoxy(30,12);
		cprintf("Not Found");
		getch();
		return;
	}
	clrscr();
	textcolor(WHITE+128);
	gotoxy(30,11);
	cprintf("Profile is Dleleted...");
	for (i=0;i<NumOfUser;i++)
	{
		if (!strcmp(u,ob1[i].retusername()))
		{
			for (int j=i;j<NumOfUser-1;j++)
				ob1[j]=ob1[j+1];
			break;
		}
	}
	NumOfUser--;
	getch();
}
////////////////////////////////////////////////////
void VerifyUser()
{
	char u[20],ch='y';
	int sw;
	while (ch=='y')
	{
		clrscr();
		textcolor(WHITE);
		gotoxy(1,1);
		cprintf("Enter UserName of User: ");
		gets(u);
		clrscr();
		sw=0;
		for (int i=0;i<NumOfUser;i++)
		{
			if ((!strcmp(u,ob1[i].retusername())) && (ob1[i].retstatus()==0))
				{
					gotoxy(1,1);
					cprintf("FirstName: ");
					cprintf("%s",ob1[i].retfirstname());
					gotoxy(1,2);
					cprintf("lastName: ");
					cprintf("%s",ob1[i].retlastname());
					gotoxy(1,3);
					cprintf("UserName: ");
					cprintf("%s",ob1[i].retusername());
					gotoxy(1,4);
					cprintf("Status: 1");
					ob1[i].setstatus(1);
					sw=1;
				}
		}
		if (sw==0)
		{
			gotoxy(1,2);
			cprintf("Not Found");
		}
		gotoxy(1,5);
		cprintf("Do you want to continue:(y/n)? ");
		cin>>ch;
	}//while
	getch();
}
////////////////////////////////////////////////////
void ListUser()
{
	int y=3,i;
	clrscr();
	gotoxy(1,1);
	cprintf("Username");
	gotoxy(15,1);
	cprintf("Firstname");
	gotoxy(30,1);
	cprintf("Lastname");
	gotoxy(45,1);
	cprintf("Age");
	gotoxy(60,1);
	cprintf("Telephone");
	gotoxy(1,2);
	for (i=1;i<80;i++)
		cprintf("-");
	for (i=0;i<=NumOfUser;i++)
	{
		if (ob1[i].retstatus())
		{
			y++;
			gotoxy(1,y);
			cprintf(ob1[i].retusername());
			gotoxy(15,y);
			cprintf(ob1[i].retfirstname());
			gotoxy(30,y);
			cprintf(ob1[i].retlastname());
			gotoxy(45,y);
			cprintf(ob1[i].retage());
			gotoxy(60,y);
			cprintf(ob1[i].rettel());
		}
	}
	getch();
}
/////////////////////////////////////////////////////
void SortUser()
{
	int i,j;
	User temp;
	clrscr();
	for (i=0;i<NumOfUser-1;i++)
	{
		for (j=0;j<NumOfUser-i;j++)
			if (strcmp(ob1[j].retusername(),ob1[j+1].retusername())>0)
			{
				temp=ob1[j];
				ob1[j]=ob1[j+1];
				ob1[j+1]=temp;
			}
	}
	ListUser();
}
////////////////////////////////////////////////////
void SearchUser()
{
	int sw=0;
	char u[20];
	clrscr();
	cprintf("Enter UserName of User: ");
	gets(u);
	clrscr();
	for (int i=0;i<NumOfUser;i++)
	{
		if (!strcmp(u,ob1[i].retusername()))
			{
				sw=1;
				break;
			}
	}
	if (sw==0)
	{
		gotoxy(30,12);
		cprintf("Not Found");
		getch();
		return;
	}
	gotoxy(1,2);
	cprintf("First name:");
	gotoxy(1,4);
	cprintf("last name:");
	gotoxy(1,6);
	cprintf("Age:");
	gotoxy(1,8);
	cprintf("Telephone:");
	gotoxy(1,10);
	cprintf("Status:");
	gotoxy(20,10);
	ob1[i].retstatus();
	ob1[i].showinfo();
	getch();
}
////////////////////////////////////////////////////
void ChangePass()
{
	int sw=0;
	char u[20],t[20];
	clrscr();
	cprintf("Enter UserName of User: ");
	gets(u);
	clrscr();
	for (int i=0;i<NumOfUser;i++)
	{
		if (!strcmp(u,ob1[i].retusername()))
			{
				ob1[i].showinfo();
				sw=1;
				break;
			}
	}
	if (sw==0)
	{
		gotoxy(30,12);
		cprintf("Not Found");
		getch();
		return;
	}
	gotoxy(1,2);
	cprintf("First name:");
	gotoxy(1,4);
	cprintf("last name:");
	gotoxy(1,6);
	cprintf("Age:");
	gotoxy(1,8);
	cprintf("Telephone:");
	gotoxy(1,10);
	cprintf("Password:");
	gotoxy(20,10);
	ob1[i].retpassword();
	ob1[i].showinfo();
	getch();
	gotoxy(20,10);
	gets(t);
	ob1[i].setpassword(t);
	gotoxy(20,10);
	ob1[i].retpassword();
}
////////////////////////////////////////////////////
void Number()
{
	clrscr();
	textcolor(WHITE);
	cprintf("Number of Users: ");
	textcolor(GREEN);
	cprintf("%d",NumOfUser);
	textcolor(WHITE);
	gotoxy(1,3);
	cprintf("Number of Admin: ");
	textcolor(GREEN);
	cprintf("%d",NumOfAdmin);
	getch();
}
////////////////////////////////////////////////////
void ConvertUser()
{
	int i,j,t,x;
	char* temp;
	for (i=0;i<NumOfUser;i++)
	{
		t=0;j=0;
		while (userfile[i][j]!='|')
			temp[t++]=userfile[i][j++];
		temp[t]='\0';
		x=atoi(temp);
		ob1[i].setkind(x);
		t=0;j++;
		while (userfile[i][j]!='|')
			temp[t++]=userfile[i][j++];
		temp[t]='\0';
		x=atoi(temp);
		ob1[i].setstatus(x);
		t=0;j++;
		while (userfile[i][j]!='|')
			temp[t++]=userfile[i][j++];
		temp[t]='\0';
		ob1[i].setusername(temp);
		t=0;j++;
		while (userfile[i][j]!='|')
			temp[t++]=userfile[i][j++];
		temp[t]='\0';
		ob1[i].setpassword(temp);
		t=0;j++;
		while (userfile[i][j]!='|')
			temp[t++]=userfile[i][j++];
		temp[t]='\0';
		ob1[i].setfirstname(temp);
		t=0;j++;
		while (userfile[i][j]!='|')
			temp[t++]=userfile[i][j++];
		temp[t]='\0';
		ob1[i].setlastname(temp);
		t=0;j++;
		while (userfile[i][j]!='|')
			temp[t++]=userfile[i][j++];
		temp[t]='\0';
		ob1[i].setage(temp);
		t=0;j++;
		while (userfile[i][j]!='|')
			temp[t++]=userfile[i][j++];
		temp[t]='\0';
		ob1[i].settel(temp);
	}
}
////////////////////////////////////////////////////
void ConvertAdmin()
{
	int i,j,t,x;
	char* temp;
	for (i=0;i<NumOfAdmin;i++)
	{
		t=0;j=0;
		while (adminfile[i][j]!='|')
			temp[t++]=adminfile[i][j++];
		temp[t]='\0';
		x=atoi(temp);
		ob2[i].setkind(x);
		t=0;j++;
		while (adminfile[i][j]!='|')
			temp[t++]=adminfile[i][j++];
		temp[t]='\0';
		ob2[i].setusername(temp);
		t=0;j++;
		while (adminfile[i][j]!='|')
			temp[t++]=adminfile[i][j++];
		temp[t]='\0';
		ob2[i].setpassword(temp);
		t=0;j++;
		while (adminfile[i][j]!='|')
			temp[t++]=adminfile[i][j++];
		temp[t]='\0';
		ob2[i].setfirstname(temp);
		t=0;j++;
		while (adminfile[i][j]!='|')
			temp[t++]=adminfile[i][j++];
		temp[t]='\0';
		ob2[i].setlastname(temp);
		t=0;j++;
		while (adminfile[i][j]!='|')
			temp[t++]=adminfile[i][j++];
		temp[t]='\0';
		ob2[i].setage(temp);
		t=0;j++;
		while (adminfile[i][j]!='|')
			temp[t++]=adminfile[i][j++];
		temp[t]='\0';
		ob2[i].settel(temp);
	}
}
////////////////////////////////////////////////////
void ReadUserFile()
{
	char u[255];
	ifstream f;
	f.open("userdata.txt",ios::in);
	if (!f) {
		gotoxy(1,1);
		cout<<"File not found!";
		return;
	}
	while (!f.eof())
	{
		f.getline(u,'|');
		strcpy(userfile[NumOfUser],u);
		NumOfUser++;
	}
	userfile[NumOfUser+1][0]='\0';
	f.close();
}
////////////////////////////////////////////////////
void ReadAdminFile()
{
	char u[255];
	ifstream f1;
	f1.open("admin.txt",ios::in);
	if (!f1) {
		gotoxy(1,1);
		cout<<"File not found!";
		return;
	}
	while (!f1.eof())
	{
		f1.getline(u,'|');
		strcpy(adminfile[NumOfAdmin],u);
		NumOfAdmin++;
	}
	adminfile[NumOfAdmin+1][0]='\0';
	f1.close();
}
////////////////////////////////////////////////////