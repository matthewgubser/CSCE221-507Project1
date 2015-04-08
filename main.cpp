#include "Sort.h"
#include "Time.h"
#include "std_lib_facilities_4.h"
#include <iostream> 
using namespace std;


int main()
{
    try
    {
	Sort();// Both do same thing
	Sort name;// Both simply sort list do nothing more
	cout<<"Display sorted list: "<<endl;
	name.display();//displays sorted list name
	name.getnumComp();//returns value of comps for name
	cout<<"Number of Comps on Name: "<<name.getnumComp();//prints value of comps for name
    }
    catch(exception& e)
    {
   	 cerr << "Exception: " << e.what() << '\n';
   	 return 1;
    }
    catch (...)
    {
   	 cerr << "Unknown exception" << '\n';
   	 return 2;
    }
    return 0;
}
