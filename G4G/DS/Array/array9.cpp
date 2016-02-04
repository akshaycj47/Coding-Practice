// Find equilibrium index of an array (find a better solution than current one)
// http://www.geeksforgeeks.org/equilibrium-index-of-an-array/

#include <iostream>
using namespace std;

void printEquilibriumIndex(int* arr, int n) {
	// Create a resultant array for sum of all elements to the left or to the right
	int* result1 = new int[n];
	int* result2 = new int[n];

	// Left swipe
	result1[0] = 0;
	for(int i = 1; i < n; i++) {
		result1[i] = result1[i - 1] + arr[i - 1];
	}

	// Right swipe
	result2[n - 1] = 0;
	for(int i = n - 2; i >= 0; i--) {
		result2[i] = result2[i + 1] + arr[i + 1];
	}

	// The positions with sum of result 0 will be equilibrium index / indices
	for(int i = 0; i < n; i++) {
		if(result1[i] == result2[i]) {
			cout << "Equilibrium index: " << i << endl;
		}
	}
}

int main() {
	int arr[] = {-7, 1, 5, 2, -4, 3, 0};
	int n = sizeof(arr) / sizeof(arr[0]);
	printEquilibriumIndex(arr, n);
}