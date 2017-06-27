
#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include "../../macros.h"
#include "../Sort.h"

// Insertion sort strategy
class QuickSort: public BaseSort {
public:
	~QuickSort() {
		DTOR("~QuickSort()\n");
	}
	void sort() {
		std::cout << "Sort using quick sort.\n";
	}
};

#endif // QUICKSORT_H_