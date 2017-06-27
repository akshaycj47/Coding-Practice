
#ifndef MERGESORT_H_
#define MERGESORT_H_

#include "../../macros.h"
#include "../Sort.h"

// Insertion sort strategy
class MergeSort: public BaseSort {
public:
	~MergeSort() {
		DTOR("~MergeSort()\n");
	}
	void sort() {
		std::cout << "Sort using merge sort.\n";
	}
};

#endif // MERGESORT_H_