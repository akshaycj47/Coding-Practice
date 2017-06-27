
// Implement strategy pattern with different types of sorting algorithm

#include <iostream>

#include "../macros.h"
#include "Sort.h"
#include "SortingAlgorithms/InsertionSort.h"

void clientCode(BaseSort* algo) {
	std::cout << "Client code...\n";
	algo->sort();
}

int main() {

	std::cout << "Strategy Pattern: Implement different sorting algorithms using strategy pattern" << std::endl;

	// Enumerate different sorting strategies
	Algos criteria[] = {Selection, Insertion};

	for(size_t i = 0; i < COUNT(criteria); i++) {
		
		// Creat an object of base sorting algorithm
		BaseSort* algo = 0;

		switch(criteria[i]) {
		case Insertion:
			algo = new InsertionSort;
			break;
		default:
			algo = new BaseSort;
			break;
		}

		clientCode(algo);
	}

	return 0;
}