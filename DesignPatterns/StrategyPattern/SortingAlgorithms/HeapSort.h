
#ifndef HEAPSORT_H_
#define HEAPSORT_H_

#include "../../macros.h"
#include "../Sort.h"

// Insertion sort strategy
class HeapSort: public BaseSort {
public:
	~HeapSort() {
		DTOR("~HeapSort()\n");
	}
	void sort() {
		std::cout << "Sort using heap sort.\n";
	}
};

#endif // HEAPSORT_H_