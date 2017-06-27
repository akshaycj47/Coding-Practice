
#include "../macros.h"

// Different sorting algorithms
enum Algos {
	SelectionSort,
	InsertionSort,
	BubbleSort,
	MergeSort,
	QuickSort,
	HeapSort
};

// Abstract class for all sorting algorithms
class BaseSort {
public:
	virtual ~BaseSort() {
		DTOR("~BaseSort()\n");
	}
	virtual void sort() {
		std::cout << "Sort using base sort.\n";
	} 
};