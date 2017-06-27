
#ifndef SORT_H_
#define SORT_H_

#include "../macros.h"

// Different sorting algorithms
enum Algos {
	Selection,
	Insertion,
	Bubble,
	Merge,
	Quick,
	Heap
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

#endif // SORT_H_