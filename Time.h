#ifndef Time_H_
#define Time_H_
#include "std_lib_facilities_4.h"
#include <iostream> 
using namespace std;

void Time()
{
	int n=0;
	int algorithm =0;
	int Sorted_Comp,Reversed_Comp,Random_Comp = 0;
	double sorted, reverse, rando =0;
	cout<<"How many numbers would you like to sort/time?"<<endl;
	cin>>n;
	cout<<"What sorting algorithm do you want to use?  (1=Bubble Sort, 2=Selection Sort, 3=Insertion Sort, 4=Heap Sort, 5=Merge Sort, 6=(deterministic) Quick Sort, 7=(randomized) Quick Sort, 8=Radix Sort"<<endl;
    cin>>algorithm;
	ofstream input;
//------------------------------------------------------------------------------------------------------------------------------	
	cout << "\n===Sorted Sequence===" << endl;
	input.open("numbers.txt");
	input<<algorithm<<endl<<n;
    for (int i = 0; i < n; i++)
    {
	 input<<endl<<i;
    }
	input.close();
    //time sort function
    clock_t start = clock();
    Sort Sorted_Sort;
    clock_t end = clock();
     sorted = (double)(end - start)/CLOCKS_PER_SEC;
    //results
    Sorted_Comp = Sorted_Sort.getnumComp();
    cout << "Number of comp: " << Sorted_Comp << "\nSorting time: " <<
    sorted << " sec" << endl;
	
//------------------------------------------------------------------------------------------------------------------------------   
    cout << "\n===Reverse Sorted Sequence===" << endl;
	input.open("numbers.txt");
	input<<algorithm<<endl<<n;
    for (int i = n; i > 0; i--)
    {
		input<<endl<<i;
    }
    input.close();
    //time sort function
    clock_t start1 = clock();
    Sort Reversed_Sort;
    clock_t end1 = clock();
     reverse = (double)(end1 - start1)/CLOCKS_PER_SEC;
    //results
    Reversed_Comp = Reversed_Sort.getnumComp();
    cout << "Number of comp: " << Reversed_Comp << "\nSorting time: " <<
    reverse << " sec" << endl;
//-----------------------------------------------------------------------------------------------------------------------------   
    cout << "\n===Random Sequence===" << endl;
	input.open("numbers.txt");
	input<<algorithm<<endl<<n;
	int random=0;
    for (int i = 0; i < n; i++)
    {
		random = rand() % 1000;
		input<<endl<<random;
    }
    input.close();
    //time sort function
    clock_t start2 = clock();
    Sort Random_Sort;
    clock_t end2 = clock();
     rando = (double)(end2 - start2)/CLOCKS_PER_SEC;
    //results
    Random_Comp = Random_Sort.getnumComp();
    cout << "Number of comp: " << Random_Comp << "\nSorting time: " <<
    rand << " sec" << endl;
//------------------------------------------------------------------------------------------------------------------------------
    cout << "\n===Averages===" << endl;
	//average number of comparisons and sorting time
    double avgTime = (sorted + reverse + rando)/3;
    double avgComp = (Sorted_Comp + Reversed_Comp + Random_Comp)/3;
    cout << "Average number of comp: " << avgComp <<
    "\nAverage sorting time: " << avgTime << " sec" << endl;
}

#endif //Time_H_