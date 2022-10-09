/*########################################
  #  Programmer : Vivek Patel            #   
  #  Release at Site : cpp.blogfa.com    #
  #  mail :  cpp.blogfa@gmail.com        #
  ########################################*/

#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <graphics.h>

//Menu Global Item
#define pixTOrc(x) (8*(x-1))  //convert pixel into row and col format
#define INC 5  //Increment Distance Between Menu Items
#define ROW 15 //Row Value for Menu Item
#define COL 8 //Column Value for Menu Item
#define MAXITEM 5 //Total menu items

// To display the Inventory Main menu options
typedef char option[15];
option mainMenu[]= {
  "NEW",
  "OPEN",
  "SAVE",
  "ABOUT ME",
  "CLOSE"
};


// Function to displays all the menu prompt messages from the pointer array of option a[]
void normalvideo(int x,int y,char *str)
{
    x=pixTOrc(x);
    y=pixTOrc(y);
    outtextxy(x,y,str);
}

// Function to move the cursor on the menu prompt with a reverse video color
void reversevideo(int x,int y,char *str)
{
x=pixTOrc(x);
y=pixTOrc(y);
setcolor(YELLOW);  //Selected Item
sound(400);
delay(100);
nosound();
outtextxy(x,y,str);
setcolor(WHITE); //Unselected Item
sound(500);
delay(100);
nosound();
}


//Keep Track of which arrow key is pressed
char menu()
{
settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
setcolor(WHITE);  //Initial Menu Item Color
int i,done;
for(i = 1; i < MAXITEM; i++)
  normalvideo(COL, (i*INC)+ROW, mainMenu[i]);

reversevideo(COL,ROW, mainMenu[0]);
i = done = 0;
do
{
/**Status Bar Logic**/
//Message will be displayed as status bar guide-line
setfillstyle(SOLID_FILL,BLUE);
settextstyle(SMALL_FONT,HORIZ_DIR,5);
bar(pixTOrc(2),pixTOrc(52.5),pixTOrc(75),pixTOrc(55));
setcolor(LIGHTCYAN);
switch(i){
case 0 : outtextxy(pixTOrc(5),pixTOrc(52.75),"New --> Create New file");
break;
case 1 : outtextxy(pixTOrc(5),pixTOrc(52.75),"Open --> Open Existing file");
break;
case 2 : outtextxy(pixTOrc(5),pixTOrc(52.75),"Save --> Save file");
break;
case 3 : outtextxy(pixTOrc(5),pixTOrc(52.75),"About Me --> Programmer : Vivek Patel");
break;
case 4 : outtextxy(pixTOrc(5),pixTOrc(52.75),"Close the Program --> BYE C U");
break;
}
/**status Bar ends**/

//Restore Orignal Color and Font Setting
setcolor(WHITE);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);

int key = getch();
switch (key)
{

case 00:
key = getch();
switch (key)
{
case 72:
normalvideo(COL, (i*INC)+ROW, mainMenu[i]);
i--;
if (i == -1)
i = MAXITEM-1;
reversevideo(COL,(i*INC)+ROW,mainMenu[i]);
break;
case 80:
normalvideo(COL, (i*INC)+ROW, mainMenu[i]);
i++;
if (i == MAXITEM)
i = 0;
reversevideo(COL, (i*INC)+ROW, mainMenu[i]);
break;
}
break;
case 13:
done = 1;
}
}
while (!done);
return(i+49);
}


//Advertise Screen will displayed to utilize empty screen area
//It can be utilize for some effective...work
void advertise(){
setcolor(BLUE);
outtextxy(pixTOrc(30),pixTOrc(20),"URL  : cpp.blogfa.com");
outtextxy(pixTOrc(30),pixTOrc(26),"Mail : cpp.myblog@gmail.com");
setcolor(YELLOW);
}


/* The function is used to display the main menu*/
//Actual code for all the menu utility resides in this
//Function...
void control_menu()
{
     char choice;
do
{
choice = menu();
switch (choice)
{
   case '1':    //New
setcolor(BLUE);
outtextxy(pixTOrc(40),pixTOrc(15),"New");
advertise();
getch();
setfillstyle(SOLID_FILL,LIGHTGRAY);
bar(pixTOrc(28),pixTOrc(14),pixTOrc(75),pixTOrc(50));
advertise();
break;

   case '2':    //Open
setcolor(BLUE);
outtextxy(pixTOrc(40),pixTOrc(15),"Open");
advertise();
getch();
setfillstyle(SOLID_FILL,LIGHTGRAY);
bar(pixTOrc(28),pixTOrc(14),pixTOrc(75),pixTOrc(50));
advertise();
break;

   case '3':    //Save
setcolor(BLUE);
outtextxy(pixTOrc(40),pixTOrc(15),"Save");
advertise();
getch();
setfillstyle(SOLID_FILL,LIGHTGRAY);
bar(pixTOrc(28),pixTOrc(14),pixTOrc(75),pixTOrc(50));
advertise();
break;

   case '4':    //Modify the status of item in inventory
setcolor(BLUE);
outtextxy(pixTOrc(40),pixTOrc(15),"About Me");
advertise();
getch();
setfillstyle(SOLID_FILL,LIGHTGRAY);
bar(pixTOrc(28),pixTOrc(14),pixTOrc(75),pixTOrc(50));
advertise();
break;

   case '5':    //Close the program
setcolor(BLUE);
outtextxy(pixTOrc(40),pixTOrc(15),"CLOSE");
advertise();
delay(1000);
setfillstyle(SOLID_FILL,LIGHTGRAY);
bar(pixTOrc(28),pixTOrc(14),pixTOrc(75),pixTOrc(50));
advertise();
goto out;
   }
  } while (choice != MAXITEM);
out:
}



void main()
{
int i,j;

int gd=DETECT,gm=0;
initgraph(&gd,&gm,"c:\\tc\\bgi\\");

///code as space holder\\\\\
setfillstyle(SOLID_FILL,LIGHTGRAY);
bar(0,0,640,480);

setcolor(DARKGRAY);
rectangle(0,0,639,480);
rectangle(1,1,638,479);
setcolor(BLACK);
rectangle(2,1,637,478);
rectangle(3,1,636,477);

settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
setcolor(BLUE);
outtextxy(pixTOrc(8),pixTOrc(2),"  MENU  -->>  (Simple Style) ");

setfillstyle(HATCH_FILL,DARKGRAY);
for(i=15,j=70;i<40||j>40;i++,j--){
bar(pixTOrc(8),pixTOrc(7),pixTOrc(i),pixTOrc(7.5));
delay(10);
bar(pixTOrc(j),pixTOrc(7),pixTOrc(70),pixTOrc(7.5));
delay(20);
}

bar(pixTOrc(7),pixTOrc(14),pixTOrc(25),pixTOrc(50));

///code as space holder\\\\\

//Calling Menu
control_menu();

closegraph();
}
