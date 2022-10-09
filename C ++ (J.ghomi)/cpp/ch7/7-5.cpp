#include <iostream.h>
#include <conio.h>
class testClass {
    static int resource;
  public:
    static int get_resource();
    void free_resource() { resource = 0;}
};
//***************
int testClass::resource; // define resource
int testClass::get_resource()
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
  testClass ob1, ob2;
  clrscr();
  //get_resource() is static so may be called independent of any object.
  if(testClass::get_resource())
      cout << "Objet ob1 has resource\n";
  if(!testClass::get_resource())
      cout << "Object ob2 denied resource\n";
  ob1.free_resource();   //let someone else use it
  if(ob2.get_resource()) //can still call using object syntax
      cout << "Object ob2 can now use resource\n";
  getch();
  return 0;
}


