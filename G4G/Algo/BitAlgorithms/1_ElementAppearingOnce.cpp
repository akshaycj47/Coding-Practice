#include <unordered_map>
#include <cassert>

/**
* Function that returns element appearing only once in array, where
* all the other elements occur 3 times
* In this function, we use unordered map to work as a counter
* @params {array} arr - Array of integers where every element occurs thrice
* apart from one element which occurs once
* @params {int} n - Number of elements in array
* @return {int} Element that only occurs once in the array
*/
int elementAppearingOnceMap(int* arr, int n) {

	// Start filling out the map using number as key,
	// and count as value
	std::unordered_map<int, int> m;
	for (int i = 0; i < n; i++) {
		if (m.find(arr[i]) == m.end()) {
			m[arr[i]] = 1;
		}
		else {
			m[arr[i]] += 1;
 		}
	}

	// Start iterating the map and return the element
	// that only occurs once
	std::unordered_map<int, int>::iterator it;
	for (it = m.begin(); it != m.end(); it++) {
		if (it->second == 1) {
			return it->first;
		}
	}

	// Return -1 if no element occurs just once
	return -1;
}

/**
* Starting point of the program
*/
int main() {

	int arr[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(elementAppearingOnceMap(arr, n) == 2);

	int arr2[] = {12, 1, 12, 3, 2, 2, 12, 1, 1, 2, 3, 3};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(elementAppearingOnceMap(arr2, n2) == -1);
}