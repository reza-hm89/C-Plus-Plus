#include <iostream.h>
#include <conio.h>
class myClass {
    static int resource;
  public:
    int get_resource();
    void free_resource() { resource = 0;}
};
//***************
int myClass::resource; // define resource
int myClass::get_resource()
{
  if(resource)
     return 0; //resource already int use
  else {
     resource = 1;
     return  1; //resource allocated to this object
  }
}
//*************
int main()
{
  myClass ob1, ob2;
  clrscr();
  if(ob1.get_resource())
      cout << "Objet ob1 has resource\n";
  if(!ob2.get_resource())
      cout << "Object ob2 denied resource\n";
  ob1.free_resource();   //let someone else use it
  if(ob2.get_resource())
      cout << "Object ob2 can now use resource\n";
  getch();
  return 0;
}


