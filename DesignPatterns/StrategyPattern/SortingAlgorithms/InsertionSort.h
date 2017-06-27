
#ifndef INSERTIONSORT_H_
#define INSERTIONSORT_H_

#include "../../macros.h"
#include "../Sort.h"

// Insertion sort strategy
class InsertionSort: public BaseSort {
public:
	~InsertionSort() {
		DTOR("~InsertionSort()\n");
	}
	void sort() {
		std::cout << "Sort using insertion sort.\n";
	}
};

#endif // INSERTIONSORT_H_