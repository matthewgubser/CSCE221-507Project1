#ifndef SORT_H_
#define SORT_H_
#include "std_lib_facilities_4.h"
#include <iostream> 
using namespace std;

class Sort
{
    private:
	unsigned long numComp;			// number of comparisons performed in sort function
	vector<int> data;
	int type;
	int size;
	int tempa;
	int tempb;
	int tempc;
	bool Sorted;
    
    public:
    //constructor
    Sort() 
	{
		tempa=0, tempb=0, tempc=0, type=0, size=0, numComp=0;
		Sorted = false;
		string temp;
		ifstream input;
		input.open("numbers.txt");
		//find type
		getline(input, temp);
		type = stoi(temp);
		//get number of elements
		getline(input, temp);
		size = stoi(temp);
   	 
		//push remaining lines into vector
		for (int i = 0; i < size; i++)
		{
			getline(input, temp);
			data.push_back(stoi(temp));
		}
		switch (type)
		{
			 case 1:
			 BubbleSort();
			 break;
			 
			 case 2:
			 SelectionSort();
			 break;
			 
			 case 3:
			 //insertion sort
			 break;
			 
			 case 4:
			 //heap sort
			 break;
			 
			 case 5:
			 //merge sort
			 break;
			 
			 case 6:
			 //deterministic quick sort
			 break;
			 
			 case 7:
			 //randomized quick sort
			 break;
			 
			 case 8:
			 //radix sort
			 break;
			 
			 default:
			 //doesn't matter
			 break;
		}
		input.close();
    }
    
    //destructor
    ~Sort() {}
    
    //returns number of comparisons
    unsigned long getnumComp() { return numComp; }
    
    //resets counter
    void resetnumComp() { numComp = 0; }
	
	void printVector() 
	{
		if(size>=1)
		{
			cout<<data[0];
		}
		else 
		{
			cout<<"No Data";
		}
		for (int i = 0; i<size; ++i)
		{
			cout<<", "<<data[i];
		}
	}
	
    void display()
    {
   	 for (int i = 0; i <size; i++)
   	 {
   		 cout << data[i] << endl;
   	 }
    }
	
	void BubbleSort()
	{
		tempc=1;
		while (Sorted == false)// sort while vector is not sorted assuming vector is not sorted
		{
			for  (int n = 0; n<size-1; n++)// go through all numbers in vector
			{
				if (data[n] > data[n+1])//check to see if the number on the left is smaller than the one on the right
				{
					tempa = data[n+1];// smaller number goes in a
					tempb = data[n];// bigger number goes in b
					//swap positions
					data[n]=tempa;// smaller number, a, gets placed before bigger number, b
					data[n+1]=tempb; // bigger number, b, gets placed after smaller number, a
					tempc++; // indicate a swap has occurred this pass through
					numComp++;
					
				}
			}
			if (tempc == 0)// if no swaps occurred then vector is sorted
			{
				Sorted = true;// change status of vector to exit while loop
			}
			else
			{
				tempc = 0;// else reset swap counter
			}
		}
	}
	
	void SelectionSort()
	{
		for ( int i=size-1; i>0; i--)
		{
			tempa=0;
			for (int j=1; j<=i; j++)
			{
				if (data[j]>data[tempa])
				{
					tempa=j;
					numComp++;
				}
			}
			tempb=data[tempa];
			data[tempa]=data[i];
			data[i]=tempb;
		}
	}

	void HeapSort()
	{
		display();	
	}


};

#endif //SORT_H_
