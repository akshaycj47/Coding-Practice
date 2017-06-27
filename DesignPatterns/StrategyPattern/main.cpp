
// Implement strategy pattern with different types of sorting algorithm

#include <iostream>

#include "../macros.h"
#include "Sort.h"
#include "SortingAlgorithms/SelectionSort.h"
#include "SortingAlgorithms/InsertionSort.h"
#include "SortingAlgorithms/BubbleSort.h"
#include "SortingAlgorithms/MergeSort.h"
#include "SortingAlgorithms/QuickSort.h"
#include "SortingAlgorithms/HeapSort.h"

void clientCode(BaseSort* algo) {
	std::cout << "Client code...\n";
	algo->sort();
}

int main() {

	std::cout << "Strategy Pattern: Implement different sorting algorithms using strategy pattern" << std::endl;

	// Enumerate different sorting strategies
	Algos criteria[] = {Selection, Insertion, Bubble, Merge, Quick, Heap};

	for(size_t i = 0; i < COUNT(criteria); i++) {
		
		// Creat an object of base sorting algorithm
		BaseSort* algo = 0;

		switch(criteria[i]) {
		case Selection:
			algo = new SelectionSort;
			break;
		case Insertion:
			algo = new InsertionSort;
			break;
		case Bubble:
			algo = new BubbleSort;
			break;
		case Merge:
			algo = new MergeSort;
			break;
		case Quick:
			algo = new QuickSort;
			break;
		case Heap:
			algo = new HeapSort;
			break;
		default:
			algo = new BaseSort;
			break;
		}

		clientCode(algo);
	}

	return 0;
}