#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <iomanip.h>
class shape {
  public:
      virtual double area() const { return 0; }
      virtual double volume() const { return 0;}
      //pure virtual functios overridden in derived class
      virtual void printShpName() const = 0;
      virtual void print() const = 0;
};
//*****************
class point : public shape {
   public:
      point (int = 0, int = 0);
      void setPoint(int, int);
      int getx() const  { return x; }
      int gety() const  { return y; }
      virtual void printShpName() const { cout << "point : "; }
      virtual void print() const;
   private:
      int x, y;  //coordinate of point
};
//***************
point::point(int a, int b) { setPoint(a, b); }
void point::setPoint(int a, int b)
{
   x = a;
   y = b;
}
//***************
void point::print() const
{
   cout << '[' << x << ", " << y << ']';
}
//********************
class circle : public point {
   public:
      circle(double r = 0, int x = 0, int y = 0);
      void setRadius(double);
      double getRadius() const;
      virtual double area() const;
      virtual void printShpName() const { cout << "circle: "; }
      virtual void print() const;
   private:
      double radius;
};
//*****************
circle::circle(double r, int a, int b) : point(a, b)
{
   setRadius(r);
}
//****************
void circle::setRadius(double r) { radius = r > 0 ? r: 0;}
double circle::getRadius() const { return radius; }
double circle::area() const
{
   return 3.14159 * radius * radius;
}
//************
void circle::print() const
{
   point::print();
   cout << "; radius = " << radius;
}
//**************
class cylinder : public circle {
    public:
       cylinder(double h = 0, double r= 0, int x = 0, int y = 0);
       void setHeight(double);
       double getHeight() const;
       virtual double area() const;
       virtual double volume() const;
       virtual void printShpName() const { cout << "cylinder : ";}
       virtual void print() const;
    public:
       double height;
};
//******************************
cylinder::cylinder(double h, double r, int x, int y) : circle(r, x, y)
{
    setHeight(h);
}
//****************
void cylinder::setHeight(double h)
{
  height = h > 0 ? h : 0;
}
//**************
double cylinder::area() const
{
   return 2 * circle::area() + 2 * 3.14159 *getRadius() * height;
}
//***********
double cylinder::volume() const
{
    return circle::area() * height;
}
//************
void cylinder::print() const
{
   circle::print();
   cout << " ; height = " << height;
}
//***************
void vPointer(const shape *);
void vRef(const shape &);
int main()
{
    int i;
    clrscr();
    cout << setiosflags(ios::fixed | ios::showpoint)
	 << setprecision(2);
    point p(7, 11);
    circle c(3.5, 22, 8);
    cylinder cy(10, 3.5, 10, 10);

    p.printShpName();    //static binding
    p.print();
    cout << endl;

    c.printShpName();    //static binding
    c.print();
    cout << endl;

    cy.printShpName();    //static binding
    cy.print();
    cout << endl;

    shape *arrayShp[3];
    arrayShp[0] = &p;
    arrayShp[1] = &c;
    arrayShp[2] = &cy;

    cout << "virtual function calls mode off "
	 << "base class pointer\n ";
    for(i = 0; i < 3; i++)
	vPointer(arrayShp[i]);

    cout << "virtual function calls mode off "
	 << "base class pointer\n ";
    for(i = 0; i < 3; i++)
  	vRef(*arrayShp[i]);
    getch();
    return 0;
}
//*****************
void vPointer(const shape *basePtr)
{
   basePtr -> printShpName();
   basePtr -> print();
   cout << "\narea = " << basePtr -> area()
	<<  "\nvolume = " << basePtr -> volume() << "\n\n";
}
//*************
void vRef(const shape &baseRef)
{
   baseRef.printShpName();
   baseRef.print();
   cout << "\narea = " << baseRef.area()
	<< "\nvolume = " << baseRef.volume() << "\n\n";
}

