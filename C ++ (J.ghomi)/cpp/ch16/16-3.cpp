#include <iostream>
#include <ctype>
#include <list>
#include <conio>
using namespace std;
int main() {
  list<int> lst;
  int i;
  clrscr();
  cout << "Size = " << lst.size() << endl;
  for(i = 0; i < 10; i ++)
      lst.push_back(i);
  cout << "New size = " << lst.size() << endl;
  cout << "Contents :";
  list <int>::iterator p = lst.begin();
  while(p != lst.end()) {
     cout << *p << "  ";
     p ++;
  }
  cout << endl;
  //change contents of list
  p = lst.begin();
  while(p != lst.end()) {
     *p = *p + 10;
      p ++;
  }
  cout << "Modified contents in backward:\n";
  p = lst.end();
  while(p != lst.begin()) {
     p --;
     cout << *p << "  ";
  }
  //add element at front
  for(i = 100; i < 105; i ++)
     lst.push_front(i);
  //sort the list
  cout << "\nAfter add front, new size = " << lst.size() << endl;
  lst.sort();
  cout << "\nSorted data are:\n";
  p = lst.begin();
  while(p != lst.end()) {
     cout << *p << "  ";
     p ++;
  }
  getch();
  return 0;
}
