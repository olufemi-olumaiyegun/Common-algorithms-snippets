#include<iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <string>
#include <chrono>
#include <algorithm>

using namespace std;

//FUNCTION TO GET MAX OF VALUES
int getMax(int arr[], int n)
{
   int mx = arr[0];
   for (int i = 1; i < n; i++)
       if (arr[i] > mx)
           mx = arr[i];
   return mx;
}

//COUNTING SORT FUNCTION 	
void countSort(int arr[], int n, int exp, int base)
{
   int output[n]; // output array
   int i;
   int count[base];
  for(int i = 0; i < base; i++){
    count[i] = 0;
  }

   // Store count of occurrences in count[]
   for (i = 0; i < n; i++)
       count[ (arr[i]/exp)%base ]++;

   // Change count[i] so that count[i] now contains actual
   // position of this digit in output[]
   for (i = 1; i < base; i++)
       count[i] += count[i - 1];

   // Build the output array
   for (i = n - 1; i >= 0; i--)
   {
       output[count[ (arr[i]/exp)%base ] - 1] = arr[i];
       count[ (arr[i]/exp)%base ]--;
   }

   // Copy the output array to arr[], so that arr[] now
   // contains sorted numbers according to current digit
   for (i = 0; i < n; i++)
       arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], int n, int base)
{
   // Find the maximum number to know number of digits
   int m = getMax(arr, n);

   // Do counting sort for every digit. Note that instead
   // of passing digit number, exp is passed. exp is 10^i
   // where i is current digit number
   for (int exp = 1; m/exp > 0; exp *= base)
       countSort(arr, n, exp,base);
}

// A utility function to print an array
void print(int arr[], int n)
{
   for (int i = 0; i < n; i++)
       cout << arr[i] << " ";
}

// Driver program to test above functions
int main(int argc, char*argv[])
{
	//check if command line has only one argument for base
	if (argc!=2){
		cout<<"Error! Restart program and Enter correct number of arguments";
		exit(0);
	}
	cout<<"Name: Olufemi Olumaiyegun; CSCE3110.001; ASSIGNMENT 5; 1STUDENT ID - 1256640"<<endl;
	cout<<"please ignore debug warnings, code runs regardless"<<endl;
	cout<<endl;
	cout<<endl;
  //different array data structures for the different sizes
   int arr1[10];
   int arr2[100];
   int arr3[1000];
   int arr4[10000];
   
  stringstream convert(argv[1]) ;
    int base;
    if(!(convert >> base)) //convert commandline input into integer
        base = 10; //default base



   srand(time(0)); //seeded random integer







cout<<"----------------Array of size 10 with base "<< base<<"---"<<endl;
for(int i = 0; i<10; i++){
  //populate arrays
     for (int i = 0; i<10; i++){
       arr1[i] = rand() % 10000;
     }
     cout<<endl;
     cout<<endl;
     cout<<"-------------Unsorted Array-----------------------------------------"<<endl;
   int n = sizeof(arr1)/sizeof(arr1[0]);
   cout<<"[";
   print(arr1,n); //print unsorted array
   cout<<"]"<<endl;

auto start = std::chrono::high_resolution_clock::now(); //start clock to check time it takes to sort array

   radixsort(arr1, n, base);
auto stop = std::chrono::high_resolution_clock::now(); //end clock

auto duration = duration_cast<std::chrono::nanoseconds>(stop - start); //calculate duration 
cout<<"***********RUN "<<i+1<<"**************"<<endl;

cout<<"-------------Sorted Array-----------------------------------------"<<endl;

cout<<"Time taken by run "<<i+1<<" is: "<<duration.count() <<" nanoseconds"<<endl; //display duration
     cout<<"[";
 
   print(arr1, n);
      cout<<"]"<<endl;

   cout<<endl;

 }
 cout<<endl;
 cout<<endl;
 cout<<endl;
 cout<<"----------------Array of size 100 with base "<< base<<"---"<<endl;
 for(int i = 0; i<10; i++){
   for (int i = 0; i<100; i++){
     arr2[i] = rand() % 10000;
   }
    int n = sizeof(arr2)/sizeof(arr2[0]);
    auto start = std::chrono::high_resolution_clock::now();

       radixsort(arr2, n, base);
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = duration_cast<std::chrono::nanoseconds>(stop - start);

    cout<<"***********RUN "<<i+1<<"**************"<<endl;
    cout<<"Time taken by run "<<i+1<<" is: "<<duration.count() <<" nanoseconds"<<endl;


  }
  cout<<"----------------Array of size 1000 with base "<< base<<"---"<<endl;
  for(int i = 0; i<10; i++){
    for (int i = 0; i<1000; i++){
      arr3[i] = rand() % 10000;
    }
     int n = sizeof(arr3)/sizeof(arr3[0]);
     auto start = std::chrono::high_resolution_clock::now();

        radixsort(arr3, n, base);
     auto stop = std::chrono::high_resolution_clock::now();

     auto duration = duration_cast<std::chrono::nanoseconds>(stop - start);
     cout<<"***********RUN "<<i+1<<"**************"<<endl;
     cout<<"Time taken by run "<<i+1<<" is: "<<duration.count() <<" nanoseconds"<<endl;

   }
   cout<<"----------------Array of size 10000 with base "<< base<<"---"<<endl;
   for(int i = 0; i<10; i++){
     for (int i = 0; i<10000; i++){
       arr4[i] = rand() % 10000;
     }
      int n = sizeof(arr4)/sizeof(arr4[0]);
      auto start = std::chrono::high_resolution_clock::now();

         radixsort(arr4, n, base);
      auto stop = std::chrono::high_resolution_clock::now();

      auto duration = duration_cast<std::chrono::nanoseconds>(stop - start);
      cout<<"***********RUN "<<i+1<<"**************"<<endl;
      cout<<"Time taken by run "<<i+1<<" is: "<<duration.count() <<" nanoseconds"<<endl;


    }
return 0;


}
