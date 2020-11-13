#include <iostream>
using namespace std;


void CountingSort(int input_array[], int s, int r) {
	

	int outputArray[s]; 
	int countArray[r];
//	cout<<"cleaning buffer........"<<endl;
//	cout<<"|||||||-----||||||---|||||"<<endl;
//	cout<<"|||||||-----||||||---|||||"<<endl;
//	cout<<"|||||||-----||||||---|||||"<<endl;
//	cout<<"|||||||-----||||||---|||||"<<endl;
//	cout<<"|||||||-----||||||---|||||"<<endl;
//	cout<<"buffer cleaned......."<<endl;
	//intialize all elements in the count array to zero
	for (int i=0; i<r; i++){
		countArray[i] = 0;
	}
	for (int i = 0; i<s; i++){
		outputArray[i] = 0;
	}
	//increment counting array accoring to occurences of unique numbers
	for (int i = 0; i<s; i++){
		++countArray[input_array[i]];
	}
	//perform sequential sums on array
	for (int i = 1; i<r; i++){
		countArray[i] = countArray[i] + countArray[i-1];
	}
	//reverse count array and assign to right index in outputarray
	for (int i = 0; i<s; i++){
		outputArray[--countArray[input_array[i]]] = input_array[i];
	}
	for (int i = 0; i<s; i++){
		input_array[i] = outputArray[i];
	}
}

int main () {

	int size;
	int range;

	cout<<"Enter size of array: "<<endl;
	cin >> size;
	int arrayy[size];
	cout<<"Enter range of values: "<<endl;
	cin >> range;
	int rangex = range - 1;
	cout<<"Enter "<<size<<" integers in any order in range of 0 - "<<rangex<<" : "<<endl;
	
	for (int i = 0; i<size; i++){
		cin >> arrayy[i];
	}

	cout<<"Before sorting"<<endl;
	for (int i = 0; i < size; i++) {
		cout<<arrayy[i]<<"\t";
	}
	cout<<endl;

	CountingSort(arrayy,size,range);
//	cout<<"error 1"<<endl;
	cout<<"After sorting"<<endl;
	for (int i = 0; i<size; i++){
		cout<<arrayy[i]<<"\t";
	}
	cout<<endl;
	return 0;
}
