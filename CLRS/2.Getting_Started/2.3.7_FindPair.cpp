// In a set S, find a pair whose sum adds to a given value
// CLRS page 39

#include <iostream>
#include <cassert>
#include <map>
#include <utility>
using namespace std;

/**
 * Function which finds a pair whose sum adds to a given value
 * @params {array} arr - The array in which we have to find the pair
 * @params {int} n - Size of the array
 * @params {int} val - The sum of the pair should be equal to this value
 */
pair<int, int> findPair(int* arr, int n, int val) {

	map<int, bool> m;
	for (int i = 0; i < n; i++) {
		if (m.find(val - arr[i]) != m.end()) {
			return make_pair(val - arr[i], arr[i]);
		}
		else {
			m[arr[i]] = 0;
		}
	}
	return make_pair(-1, -1);	
}

/**
 * Starting point of the program
 */
int main() {

	int arr[] = {5, 2, 4, 6, 1, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(findPair(arr, n, 10) == make_pair(4, 6));

	int arr2[] = {3, 42, 61, 62, 23, 842, 11};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(findPair(arr2, n2, 72) == make_pair(61, 11));
	assert(findPair(arr2, n2, 109) == make_pair(-1, -1));
}