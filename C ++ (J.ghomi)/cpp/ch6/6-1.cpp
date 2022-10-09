#include <iostream.h>
#include <conio.h>
class pieceOfFabric {
      public:
	     void   readSqMeters();
	     float  toSqYards();
	     void   displayFabric();
      private:
	     float sqMeters;
} ;
//***********
void   pieceOfFabric::readSqMeters()
{
     cout << "Enter size in square meters:";
     cin >> sqMeters;
}
//***********
float  pieceOfFabric::toSqYards()
{
     return  1.196 * sqMeters;
}
//***************
void  pieceOfFabric::displayFabric()
{
     cout << sqMeters << " square meters is " << toSqYards() << " square yards.";
}
//*********
int main()
{
  clrscr();
  pieceOfFabric fabric;
  fabric.readSqMeters();
  fabric.displayFabric();
  getch();
  return 0;
}

