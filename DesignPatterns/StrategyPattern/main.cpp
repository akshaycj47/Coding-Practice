
// Implement strategy pattern with different types of sorting algorithm

#include <iostream>

#include "../macros.h"
#include "Sort.h"

int main() {

	std::cout << "Strategy Pattern: Implement different sorting algorithms using strategy pattern" << std::endl;

	// Enumerate different sorting strategies
	Algos criteria[] = {InsertionSort};

	for(size_t i = 0; i < COUNT(criteria); i++) {

		std::cout << "Sorting using: " << criteria[i] << std::endl;
	}

	return 0;
}