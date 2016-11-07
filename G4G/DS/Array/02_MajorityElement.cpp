#include <unordered_map>
#include <cassert>

/**
 * Function which finds the majority element in an array. A majority element
 * is an element in an array that occurs more than n / 2 times
 * @params {array} arr - Given array
 * @params {int} n - Size of the array
 * @return {int} Majority element in an array
 */
int majorityElement(int* arr, int n) {

	std::unordered_map<int, int> m;
	for (int i = 0; i < n; i++) {
		if (m.find(arr[i]) == m.end()) {
			m[arr[i]] = 1;
		}
		else {
			m[arr[i]] += 1;
		}
	}

	std::unordered_map<int, int>::iterator it;
	for (it = m.begin(); it != m.end(); it++) {
		if (it->second > n / 2) {
			return it->first;
		}
	}
	return -1;
}

/**
 * Starting point of the program
 */
int main() {

	int arr[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(majorityElement(arr, n) == 4);

	int arr2[] = {3, 3, 4, 2, 4, 4, 2, 4};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(majorityElement(arr2, n2) == -1);
}