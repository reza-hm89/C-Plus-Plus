#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
bool div3(int i)
{
   if ( i % 3 == 0)
	    return true;
   return false;
}
//*********
int main()
{
   vector<int> vec, v2(15);
   int i;
   for (i =1; i < 10; i ++)
	     vec.push_back(i);
   cout << "Contents :\n";
   for(i = 0; i < vec.size(); i++)
	     cout << vec[i] <<  " ";
   cout << endl;
   i = count_if(vec.begin(), vec.end(), div3);
   cout << i << " Numbers are dividsible by 3.\n";
   i = count(vec.begin(), vec.end(), 3);
   cout << i << " Number of 3 is exist.\n";
   for( i = 0; i < 5 ; i ++)
	   vec.push_back(i);
   cout << "New contents :\n";
   for(i = 0; i < vec.size(); i++)
	     cout << vec[i] <<  " ";
   cout << endl;  
   remove_copy(vec.begin(), vec.end(), v2.begin(), 3);
   cout << "Contents after remove 3(in v2) \n";
   for(i = 0; i < v2.size(); i++)
	     cout << v2[i] <<  " ";
   cout << endl;  
   
   replace_copy(vec.begin(), vec.end(), v2.begin(), 4, 14);

   cout << "Contents after replace 4 with 14(in v2) \n";
   for(i = 0; i < v2.size(); i++)
	     cout << v2[i] <<  " ";
   cout << endl;  


   return 0;
}
   