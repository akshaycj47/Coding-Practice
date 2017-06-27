
#ifndef SELECTIONSORT_H_
#define SELECTIONSORT_H_

#include "../../macros.h"
#include "../Sort.h"

// Insertion sort strategy
class SelectionSort: public BaseSort {
public:
	~SelectionSort() {
		DTOR("~SelectionSort()\n");
	}
	void sort() {
		std::cout << "Sort using selection sort.\n";
	}
};

#endif // SELECTIONSORT_H_