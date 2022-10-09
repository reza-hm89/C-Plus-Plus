# include<iostream.h>
# include<conio.h>
int bsearch(int list[],int size,int item)
{
int loc,found=0,first=0,last=size-1;
while(first<=last&&!found)
	{
   loc=(first+last)/2;
   if(item<list[loc])
	last=loc-1;
   else
	if(item>list[loc])
	first=loc+1;
      else
	found=1;
   }//Whlie
return found;
}//Bsearch
void main()
{
int list[20],item,size;
clrscr();
cout<<"Please Enter Size Of Your List : " ;
cin>>size;
for(int i=0;i<size;i++)
	{
	cout<<"\nlist["<<i<<"]=";
	cin>>list[i];
	}//For
cout<<"\nPlease Enter Item To Search : ";
cin>>item;
if(bsearch(list,size,item))
	cout<<"\nItem Exist ";
else
	cout<<"\nItem Not Exist ";
getch();
}//Main

