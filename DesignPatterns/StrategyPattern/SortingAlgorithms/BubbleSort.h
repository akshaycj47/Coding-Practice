
#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "../../macros.h"
#include "../Sort.h"

// Insertion sort strategy
class BubbleSort: public BaseSort {
public:
	~BubbleSort() {
		DTOR("~BubbleSort()\n");
	}
	void sort() {
		std::cout << "Sort using bubble sort.\n";
	}
};

#endif // BUBBLESORT_H