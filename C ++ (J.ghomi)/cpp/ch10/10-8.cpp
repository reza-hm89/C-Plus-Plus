#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
class point {
     friend ostream &operator<<(ostream &, const point &);
  public:
     point(int = 0, int = 0);   //default constructor
     void setPoint(int, int);  //set coordinates
     int getx() const { return x;}  //get x coordinate
     int gety() const {return y;}   //get y coordinate
  protected:                        //accessible by derived class
     int x, y;
};
//***************
point::point(int a, int b) { setPoint (a, b); }
void point::setPoint(int a, int b)
{
   x = a;
   y = b;
}
//outpot point with overloaded <<
ostream &operator<<(ostream &output, const point &p)
{
  output << '[' << p.x << ", " << p.y << ']';
  return output;
}
//*************
class circle : public point { //circle inherits from point
      friend ostream &operator<<( ostream &, const circle &);
   public:
      circle(double r = 0.0, int x = 0, int y = 0);
      void setRadius(double);   //set radius
      double getRadius() const; //return radius
      double area() const;      //calculate area
   protected:
      double radius;
};
//*******************
//constructor for circle calls constructor for point
//with a member initializer then initializes radius.
circle::circle(double r, int a, int b) : point(a, b) //call base class constructor
{
  setRadius(r);
}
//****set radius of circle ****
void circle::setRadius(double r)
{
   radius = (r >= 0 ? r : 0);
}
//****get radius of circle
double circle::getRadius() const
{
   return radius;
}
//calculate area of circle
double circle::area() const
{
   return 3.14159 * radius * radius;
}
//**output a circle in the form:
//center = [x, y]; radius = #.##
ostream &operator<<( ostream &output, const circle &c)
{
   output << "Center = " << static_cast < point >( c )
   << "; Radius = "
   << setiosflags(ios::fixed | ios::showpoint)
   << setprecision(2) << c.radius;
   return output;
}
//***************
int main()
{
  clrscr();
  point *pointPtr = 0, p(30, 50);
  circle *circlePtr = 0, c(2.7, 120, 89);
  cout << "point p: " << p << "\ncircle c: " << c << endl;
  //treat a circle as a point(see only the base class part)
  pointPtr = &c; //assign address of circle to poitptr
  cout << "\ncircle c (via *pointPtr): "
       << *pointPtr << '\n';
  //treat a circle as a circle(with some casting)
  pointPtr = &c;
  //cast base-class pointer to derived-class pointer
  circlePtr = static_cast<circle *>(pointPtr);
  cout << "\ncircle c(via *circleptr) :\n" << *circlePtr
       << "\nArea of c(via circlePtr): "
       << circlePtr -> area() << endl;
  //DANGEROUS: treat a point as a circle
  pointPtr = &p;
  //cast base-class pointer to derived-class pointer
  circlePtr = static_cast<circle *>(pointPtr);
  cout  << "\npoint p(via *circlePtr) :\n" << *circlePtr
	<< "\nArea of object circleptr points to : "
	<< circlePtr -> area() << endl;
  getch();
  return 0;
}
